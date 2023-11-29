#include <iostream>
using namespace std;

typedef unsigned long long ull;

bool rek(ull a, ull b, ull x, int i) {
	ull y = b ^ x;
	ull m = (1ull << i) - 1;
	if (((x*y) ^ a) & m)
		return false;
	if (i == 32)
		return false;
	if (x*1.0*y < 5e18 && x*y == a) {
		cout << x << ' ' << y << '\n';
		return true;
	}
	if (rek(a, b, x, i+1))
		return true;
	return rek(a, b, x|(1ull<<i), i+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		ull a, b;
		cin >> a >> b;
		if (!rek(a, b, 0, 0))
			cout << "-1\n";
	}
}