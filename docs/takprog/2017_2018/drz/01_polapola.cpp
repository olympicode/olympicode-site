#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int q;
	cin >> q;
	deque<char> leva, desna;

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			char x;
			cin >> x;
			desna.push_back(x);
			if (desna.size() == leva.size() + 2) {
				leva.push_back(desna.front());
				desna.pop_front();
			}
		} else {
			if (leva.size() != desna.size()) {
				cerr << "bad\n";
				return 1;
			}
			swap(leva, desna);
		}
	}

	cout << string(leva.begin(), leva.end());
	cout << string(desna.begin(), desna.end());
	cout << '\n';
}