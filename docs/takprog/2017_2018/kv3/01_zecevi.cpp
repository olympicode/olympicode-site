#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3], t;
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	int d1 = a[1] - a[0];
	int d2 = a[2] - a[1];
	if (d1 == d2) {
		t = a[2] + d2;
	} else if (d1 == 2*d2) {
		t = a[1] - d2;
	} else if (d2 == 2*d1) {
		t = a[1] + d1;
	} else {
		t = -1;
	}
	cout << t << '\n';
}