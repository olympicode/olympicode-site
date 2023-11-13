#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool res[50];

void solve(long long x, int cur, int n) {
	if (x == 0) return;
	x = x - 1;
	int t = n - 1;
	while ((1LL << t) <= x) {
		x -= (1LL << t);
		t = t - 1;
		cur++;
	}
	res[cur] = true;
	solve(x, cur + 1, t);
}

int main() {
	int n;
	long long m;
	cin >> n >> m;

	memset(res, false, sizeof(res));
	solve(m - 1, 1, n);

	for (int i = 1; i <= n; ++i)
		if (res[i])
			printf("%d ", i);
	printf("\n");

	return 0;
}