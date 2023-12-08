#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LIM = 1'000'000'000'000'000'000;
inline int digit_sum (ll x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main() {
	ll x, y, a, b;
	scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
	for (int sum_digits = 0; sum_digits <= 200; sum_digits++) {
		ll guess = sum_digits * a + b;
		if (guess > LIM) break;
		// cout << sum_digits << " " << guess << " " << digit_sum(guess) << endl;
		if (x <= guess && guess <= y && digit_sum(guess) == sum_digits) {
			printf("%lld\n", guess);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
