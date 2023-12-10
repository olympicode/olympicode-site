#include <array>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

typedef uint16_t tezina_t;
typedef uint8_t cvor_t;
const int MAX_N = 42;
const int MAX_SZ = 252;
const int MAX_LOG = 8;

struct grana {
	cvor_t u, v;
	tezina_t w;

	grana() : u(0), v(0), w(0) {}
	grana(cvor_t u, cvor_t v, tezina_t w) : u(u), v(v), w(w) {}

	bool operator< (const grana& b) const {
		return w < b.w;
	}
};

typedef array<grana, MAX_N> mst;

struct dsu {
	array<cvor_t, MAX_N> p, s;

	dsu() {
		iota(p.begin(), p.end(), 0);
		fill(s.begin(), s.end(), 1);
	}

	cvor_t e(cvor_t x) {
		if (x == p[x])
			return x = p[x];
		return p[x] = e(p[x]);
	}

	bool spoji(cvor_t x, cvor_t y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		if (s[x] > s[y])
			swap(x, y);
		p[x] = y;
		s[y] += s[x];
		return true;
	}
};

mst spoji(const mst& a, const mst& b) {
	mst c;
	dsu d;
	int i = 0, j = 0, k = 0;
	while (a[i].u || b[j].u) {
		bool prva = (a[i].u && b[j].u && a[i].w < b[j].w) || !b[j].u;
		grana g = prva ? a[i++] : b[j++];
		if (d.spoji(g.u, g.v))
			c[k++] = g; 
	}
	return c;
}

mst tbl[MAX_SZ][MAX_SZ][MAX_LOG], prazan;

const mst& daj(int x, int y, int z) {
	if (x >= MAX_SZ || y >= MAX_SZ)
		return prazan;
	return tbl[x][y][z];
}

void Resi(
	int N, int R, int C, int Q,
	int** U, int** V, int** W,
	int* X1, int* Y1, int* X2, int* Y2,
	int* O)
{
	for (int i=1; i<=R; i++)
		for (int j=1; j<=C; j++)
			tbl[i][j][0][0] = grana(U[i][j], V[i][j], W[i][j]);
	for (int k=1; k<MAX_LOG; k++) {
		int w = 1 << (k-1);
		for (int i=1; i<=R; i++)
			for (int j=1; j<=C; j++)
				tbl[i][j][k] = spoji(
					spoji(daj(i+w, j, k-1), daj(i, j+w, k-1)),
					spoji(daj(i, j, k-1), daj(i+w, j+w, k-1)));
	}

	for (int i=1; i<=Q; i++) {
		int p = X2[i] - X1[i] + 1;
		int q = Y2[i] - Y1[i] + 1;
		int k = 0, l = 1;
		while (2*l <= min(p, q))
			l<<=1, k++;

		mst tmp;
		if (p >= q) {
			int xt = X1[i];
			while (1) {
				if (X2[i]-xt+1 > l) {
					tmp = spoji(tmp, daj(xt, Y1[i]    , k));
					tmp = spoji(tmp, daj(xt, Y2[i]-l+1, k));
					xt += l;
				} else {
					tmp = spoji(tmp, daj(X2[i]-l+1, Y1[i]    , k));
					tmp = spoji(tmp, daj(X2[i]-l+1, Y2[i]-l+1, k));
					break;
				}
			}
		} else {
			int yt = Y1[i];
			while (1) {
				if (Y2[i]-yt+1 > l) {
					tmp = spoji(tmp, daj(X1[i],     yt, k));
					tmp = spoji(tmp, daj(X2[i]-l+1, yt, k));
					yt += l;
				} else {
					tmp = spoji(tmp, daj(X1[i],     Y2[i]-l+1, k));
					tmp = spoji(tmp, daj(X2[i]-l+1, Y2[i]-l+1, k));
					break;
				}
			}
		}

		int z = 0, uw = 0;
		for (int j=0; j<MAX_N; j++)
			if (tmp[j].u)
				uw += tmp[j].w, z++;
		if (z < N-1)
			uw = -1;
		O[i] = uw;
	}
}