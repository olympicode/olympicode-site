#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double ld;
const int maxn = 131072;

int h, w, r, q;

struct krug {
	int x, y;

	krug(int x=1e8, int y=1e8) : x(x), y(y) {}

	ld operator* (int t) const {
		if (t < x-r || t > x+r)
			return 1e50;
		return y - sqrt(ld(r+t-x)*(r-t+x));
	}
};

krug b[2*maxn];

void dodaj(krug v, int x, int xl, int xr) {
	if (v.x + r < xl || xr < v.x - r)
		return;
	if (v.x - r <= xl && xr <= v.x + r) {
		ld vl = v * xl, vr = v * xr;
		ld bl = b[x] * xl, br = b[x] * xr;
		if (vl <= bl && vr <= br) {
			b[x] = v;
			return;
		}
		if (vl >= bl && vr >= br)
			return;
		if (vl < bl)
			swap(b[x], v);
	}
	int xm = (xl+xr) >> 1;
	dodaj(v, 2*x, xl, xm);
	dodaj(v, 2*x+1, xm+1, xr);
}

ld racunaj(int p, int x, int xl, int xr) {
	ld sol = b[x] * p;
	if (xl != xr) {
		int xm = (xl+xr) >> 1;
		if (p <= xm)
			sol = min(sol, racunaj(p, 2*x, xl, xm));
		else
			sol = min(sol, racunaj(p, 2*x+1, xm+1, xr));
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(12) << fixed;
	
	cin >> w >> h >> r >> q;
	for (int i=0; i<=w; i++)
		dodaj(krug(i, h+r), 1, 0, w);
	while (q--) {
		int t;
		cin >> t;
		if (t == 2) {
			int x;
			cin >> x;
			cout << max(ld(0), racunaj(x, 1, 0, w)) << '\n';
		} else if (t == 1) {
			int x, y;
			cin >> x >> y;
			dodaj(krug(x, y), 1, 0, w);
		}
	}
}

