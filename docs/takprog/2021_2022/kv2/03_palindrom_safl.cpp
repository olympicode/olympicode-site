#include<bits/stdc++.h>

using namespace std;


const int maxN = 2e5;
const int maxS = 26;
string s;
int n;
int p[maxN + 10][maxS + 1];

bool compare(int l, int r) {
	int l1 = n - r + 1;
	int r1 = n - l + 1;

	for (int i = 0; i < 26; i++) {
		if (p[r][i] - p[l - 1][i] != p[r1][i] - p[l1 - 1][i]) {
			return false;
		}
	}
	
	return true;
}

bool palindrom_shuffle(int l, int r) {
	int odd = 0;

    for (int i = 0; i < 26; i++) {
    	if (2 * p[r][i] - p[l - 1][i] - p[n - l + 1][i] < 0) {
    		return false;
    	}
    }

	return true;
}

int solve() {
	n = s.size();

	for (int i = 0; i < 26; i++) {
		p[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			p[i][j] = p[i - 1][j];
		}
		p[i][s[i - 1] - 'a']++;
	}

	int d = 1;
	while (s[d - 1] == s[n - d] && d <= n / 2) d++;

	if (d > n / 2) {
		return 1;
	}
    
    int d1 = n / 2;

    while(s[d1 - 1] == s[n - d1]) {
    	d1--;
    }


    if (compare(d, d1)) {
    	return d1 - d + 1;
    }

    for (int i = n/2 + 1; i <= n - d; i++) {
    	if (palindrom_shuffle(d, i)) {
    		return i - d + 1;
    	}
    }

    return n - 2 * d + 2;    
}

int main() {
	cin>>s;
    
    int ans = solve();
    reverse(s.begin(), s.end());
    ans = min(ans, solve());

    cout<<ans<<endl;
}