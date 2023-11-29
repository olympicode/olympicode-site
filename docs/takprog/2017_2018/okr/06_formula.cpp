#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	vector<string> terms;
	int a[20] = {0};

	for (int i=n-k; i<n; i++) {
		a[i] = 1;
	}

	do {
		string s(k-1, '[');

		int j = 0;

		for (int i=0; i<n; i++) {
			if (a[i]) {
				if (!j) {
					j = 1;
					s += 'a' + i;
				} else {
					s += ',';
					s += 'a' + i;
					s += ']';
				}
			}
		}
		terms.push_back(s);
	} while (next_permutation(a, a+n));

	string p(terms.size() - 1, '(');

	int j = 0;

	for (string q : terms) {
		if (!j) {
			j = 1;
			p += q;
		} else {
			p += ',';
			p += q;
			p += ')';
		}
	}

	cout << p << '\n';
}