#include <string>
#include <iostream>
using namespace std;

typedef long long ll;

ll od_stringa(string s) {
	ll x = 0;
	for (char c : s) {
		x = 10 * x + (c - '0');
	}
	return x;
}

string veci_jednak(string s) {
	int i = 1;
	while (i < (int)s.size() && s[i] >= s[i-1]) {
		i++;
	}
	for (int j=i; j<(int)s.size(); j++) {
		s[j] = s[i-1];
	}
	return s;
}

string manji_jednak(string s) {
	int i = 1;
	while (i < (int)s.size() && s[i] >= s[i-1]) {
		i++;
	}
	while (0 < i && i < (int)s.size() && s[i] < s[i-1]) {
		s[i-1]--;
		i--;
	}
	for (int j=i+1; j<(int)s.size(); j++) {
		s[j] = '9';
	}
	return s;
}

int main() {
	ll n;
	cin >> n;
	ll l = od_stringa(manji_jednak(to_string(n)));
	ll h = od_stringa(veci_jednak(to_string(n)));

	ll dl = n-l;
	ll dh = h-n;

	if (dl < dh) {
		cout << l << '\n';
	} else if (dh < dl) {
		cout << h << '\n';
	} else if (l == h) {
		cout << l << '\n';
	} else {
		cout << l << ' ' << h << '\n';
	}
}