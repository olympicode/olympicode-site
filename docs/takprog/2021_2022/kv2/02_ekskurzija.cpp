#include<bits/stdc++.h>

using namespace std;


const int maxN = 1000000000;
const long long maxM = 100000000000000000;
int t;
long long n, m, k;

void solve() {
	cin >> n >> m >> k;
	assert(n > 0 && n <= maxN);
	assert(m > 0 && m <= maxM);
	assert(k > 0 && k <= n);

	long long velicinaGrupe = n / k;
	long long potrebneBannice = velicinaGrupe * (velicinaGrupe + 1) / 2 * k + (velicinaGrupe + 1) * (n % k);

	if (potrebneBannice <= m) {
		cout << "Tak" << endl;
	} else {
		cout<< "Nie" << endl;
	}
}

int main() {

	cin >> t;

	assert(t >0 && t<=10);

	while(t--) {
		solve();
	}
}
