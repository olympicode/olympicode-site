#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	int t;
	cin >> t;

	for (int e = 0; e < t; ++e){

		int n;
		cin >> n;

		vector<ll> a(n);
		for (auto& i : a)
			cin >> i;

		sort(a.begin(), a.end());

		ll sol = 0;
		for (int i = 0; i < n; ++i)
			sol += (i + 2) * 1ll * a[i];

		sol -= a[n-1];

		cout << sol << '\n';
	}
}
