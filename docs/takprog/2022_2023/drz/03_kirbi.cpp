#include <bits/stdc++.h>

using namespace std;

// Postoji mnogo nacina da se implementira lis
vector<int> lis(vector<int>& a) {
	int n = a.size();
    vector<int> d(n+1, 2e9);
	
	vector<int> sol;
	for (int i = 0; i < n; i++) {
		int ind = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[ind] != 2e9){
			sol.push_back(ind+1);
			d[ind] = a[i];
		} else {
			d[ind] = a[i];
			sol.push_back(lower_bound(d.begin(), d.end(), 2e9) - d.begin());
		}
	}

	return sol;
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);

	int t;
	cin >> t;

	for (int e = 0; e < t; ++e){
		int n, m, p;
		cin >> n >> m >> p;

		vector<pair<int, int>> a;
		for (int i = 0; i < p; ++i){
			int x, y;
			cin >> x >> y;

			a.push_back({x, y});
		}

		sort(a.begin(), a.end());

		vector<int> col;
		for (int i = 0; i < p; ++i){
			col.push_back(a[i].second);
		}

		vector<int> pref = lis(col);

		vector<int> rev;
		for (int i = 0; i < p; ++i){
			rev.push_back(-1 * a[p-1-i].second);
		}

		vector<int> suf = lis(rev);
		reverse(suf.begin(), suf.end());

		vector<int> candidates;
		vector<int> cnt(p+1,0);

		int max_lis = *max_element(pref.begin(), pref.end());

		for (int i = 0; i < p; ++i){
			if (pref[i] + suf[i] - 1 == max_lis){
				candidates.push_back(i);
				cnt[pref[i]]++;
			}
		}

		int sol = 0;
		for (int c : candidates){
			if (cnt[pref[c]] == 1){
				++sol;
			}
		}

		cout << sol << '\n';
	}

}
