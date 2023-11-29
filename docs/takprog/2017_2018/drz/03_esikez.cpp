#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> a[200005];
int b[200005];
int bsel[200005];
int dp[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i=0; i<m; i++)
		cin >> b[i];

	sort(a, a+n);

	for (int i=0; i<m; i++) {
		auto p = lower_bound(a, a+n, pair<int, int>(b[i], -1));
		if (p != a+n && p->first == b[i]) {
			bsel[k++] = p->second;
		}
	}

	int h = 0;
	for (int i=0; i<k; i++) {
		auto p = lower_bound(dp+1, dp+h+1, bsel[i]);
		*p = bsel[i];
		if (p == dp+h+1)
			h++;
	}
	cout << n+m-h-h << '\n';
}