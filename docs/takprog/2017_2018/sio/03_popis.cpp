#include <bits/stdc++.h>
using namespace std;

const int MAXN = 840;
const int MAXQ = 10000;
const int MAXV = 100000;

const int PRAVOUGAONIK = 1;
const int IZMENA = 2;

const int D = 60; // velicina bloka
const int K = 14;

int n, m, q, v;

int a[MAXN][MAXN];
int a_orig[MAXN][MAXN];

int b[MAXV];

struct upit {
	int t, x1, y1, x2, y2, val, old;
};

// Mo prerequisites

int mo;

inline void add(int vr) {
	if (!b[vr]) {
		mo--;
	}
	b[vr]--;
	if (!b[vr]) {
		mo++;
	}
}

inline void rem(int vr) {
	if (!b[vr]) {
		mo--;
	}
	b[vr]++;
	if (!b[vr]) {
		mo++;
	}
}

// Mo tracker

int xl=0, xr=-1, yl=0, yr=-1, t=-1;

upit u[MAXQ];

void adjust_t(int tt) {
	while (t < tt) {
		// vidi sta se desava u t+1
		t++;
		if (u[t].t == PRAVOUGAONIK)
			continue;

		if (xl <= u[t].x1 && u[t].x1 <= xr &&
			yl <= u[t].y1 && u[t].y1 <= yr)
		{
			rem(u[t].old);
			add(u[t].val);
		}

		a[u[t].x1][u[t].y1] = u[t].val;
	}

	while (t > tt) {

		if (u[t].t == PRAVOUGAONIK) {
			t--;
			continue;
		}

		if (xl <= u[t].x1 && u[t].x1 <= xr &&
			yl <= u[t].y1 && u[t].y1 <= yr)
		{
			add(u[t].old);
			rem(u[t].val);
		}

		a[u[t].x1][u[t].y1] = u[t].old;
		t--;
	}
}

void adjust_x(int lt, int rt) {
	while (xl > lt) {
		xl--;
		for (int j=yl; j<=yr; j++) {
			add(a[xl][j]);
		}
	}
	while (xr < rt) {
		xr++;
		for (int j=yl; j<=yr; j++) {
			add(a[xr][j]);
		}
	}
	while (xl < lt) {
		for (int j=yl; j<=yr; j++) {
			rem(a[xl][j]);
		}
		xl++;
	}
	while (xr > rt) {
		for (int j=yl; j<=yr; j++) {
			rem(a[xr][j]);
		}
		xr--;
	}
}

void adjust_y(int lt, int rt) {
	while (yl > lt) {
		yl--;
		for (int j=xl; j<=xr; j++) {
			add(a[j][yl]);
		}
	}
	while (yr < rt) {
		yr++;
		for (int j=xl; j<=xr; j++) {
			add(a[j][yr]);
		}
	}
	while (yl < lt) {
		for (int j=xl; j<=xr; j++) {
			rem(a[j][yl]);
		}
		yl++;
	}
	while (yr > rt) {
		for (int j=xl; j<=xr; j++) {
			rem(a[j][yr]);
		}
		yr--;
	}
}

int seqn(int i) {
	int sz[5] = {K*K*K*K, K*K*K, K*K, K, 1};
	int h[5] = {0, K, K, K, K};
	int a[5] = {
		i / (MAXN * D),
		u[i].x1 / D,
		u[i].y1 / D,
		u[i].x2 / D,
		u[i].y2 / D
	};

	int x = 0;
	for (int i=0; i<5; i++) {
		if (a[i] % 2) {
			for (int j=i+1; j<5; j++) {
				a[j] = h[j] - 1 - a[j];
			}
		}
		x += a[i] * sz[i];
	}

	return x;
}

bool cmprbupit(int i, int j) {
	return seqn(i) < seqn(j);
}

void Resi(int n, int m, int q, int v, int** a, int* b,
	int* x1, int* y1, int* x2, int* y2, int* o)
{
	// ucitavanje
	::n = n;
	::m = m;
	::q = q;
	::v = v;

	for (int i=1; i<=v; i++) {
		mo += !b[i];
		::b[i-1] = b[i];
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			::a[i-1][j-1] = a_orig[i-1][j-1] = a[i][j] - 1;

	for (int i=1; i<=q; i++) {
		if (y2[i] != -1) {
			u[i-1] = {PRAVOUGAONIK, x1[i]-1, y1[i]-1, x2[i]-1, y2[i]-1,      -1, -1};
		} else {
			u[i-1] = {      IZMENA, x1[i]-1, y1[i]-1,      -1,      -1, x2[i]-1, -1};
		}
	}

	// vidi za svaku izmenu koja vrednost je bila pre izmene
	for (int i=0; i<q; i++) {
		if (u[i].t == IZMENA) {
			u[i].old = ::a[u[i].x1][u[i].y1];
			::a[u[i].x1][u[i].y1] = u[i].val;
		}
	}

	// vrati na vreme 0
	memcpy(::a, a_orig, sizeof(::a));

	// sortiraj i resi
	vector<int> qs;
	for (int i=0; i<q; i++)
		if (u[i].t == PRAVOUGAONIK)
			qs.push_back(i);

	sort(qs.begin(), qs.end(), cmprbupit);

	for (int i : qs) {
		adjust_x(u[i].x1, u[i].x2);
		adjust_y(u[i].y1, u[i].y2);
		adjust_t(i);
		u[i].val = mo;
	}

	int outv = 0;
	for (int i=0; i<q; i++) {
		if (u[i].t == PRAVOUGAONIK) {
			o[++outv] = u[i].val;
		}
	}
}