#include <iostream>
using namespace std;

int f(int b) {
	return b*(b-1)*(b-2)/6;
}

int k, l, e, x[2005], y[2005];

int main() {
	cin >> k;
	while (k > 0) {
		int b = 0;
		while (f(b+1) <= k)
			b++;
		k -= f(b);
		for (int i=0; i<b; i++)
			x[e] = l*l*500000+i, y[e++] = l;
		l++;
	}
	cout << e << '\n';
	for (int i=0; i<e; i++)
		cout << x[i] << ' ' << y[i] << '\n';
}