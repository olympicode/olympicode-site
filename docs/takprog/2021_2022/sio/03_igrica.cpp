#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=100050;

struct BIT {
	ll sum[N];
	void init() {
		for (int i = 0; i < N; ++i)
			sum[i] = 0;
	}
	BIT() { init(); }
	ll Get(int i) {
		ll ans = 0;
		for (; i > 0; i -= i & -i)
			ans += sum[i];
		return ans;
	}
	ll Get(int l, int r) {
		return Get(r) - Get(l - 1);
	}
	void Add(int i, ll x) {
		for(; i < N; i += i & -i)
			sum[i] += x;
	}
} BT1, BTi;

void Resi(int n, int *a, int q, int *t, int *l, int *r, int *s, ll *o) {
	for (int i = 1; i <= n; ++i) {
		BT1.Add(i, a[i]);
		BTi.Add(i, (ll)a[i] * i);
	}
	for (int i = 1; i <= q; ++i) {
		if (t[i] == 1) {
			o[i] = 0;
			int sq = ceil(sqrt(s[i]));
			for (int j = l[i]; j <= min(r[i], l[i] + sq); ++j)
				o[i] += (ll)a[j] * (s[i] % (j - l[i] + 1));
			int ptr = l[i] + sq + 1;
			while (ptr <= r[i]) {
				int m = ptr - l[i] + 1;
				int x = s[i] / m;
				int L = ptr, mR, R;
				if (x == 0) {
					R = r[i];
				} else {
					mR = s[i] / x;
					R = l[i] + mR - 1;
				}
				R = min(R, r[i]);

				ll sum = BT1.Get(L, R);
				ll sumi = BTi.Get(L, R);
				sumi -= sum * (l[i] - 1);

				o[i] += sum * s[i];
				o[i] -= sumi * x;
				ptr = R + 1;
			}
		} else {
			BT1.Add(l[i], r[i] - a[l[i]]);
			BTi.Add(l[i], (ll)(r[i] - a[l[i]]) * l[i]);
			a[l[i]] = r[i];
		}
	}
}
