#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (abs(a+d-b-c) + 1) / 2;
	return 0;
}
