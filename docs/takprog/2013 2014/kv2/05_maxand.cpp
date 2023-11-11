#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 1000005;

int n, k;
int a[MAX_N];
bool mark[MAX_N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; ++i) mark[i] = true;
	for (int i = 29; i >= 0; --i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (mark[j] && ((a[j] >> i) & 1) == 1)
				++cnt;
		}

		if (cnt >= k) {
			for (int j = 0; j < n; ++j)
				if (mark[j] && ((a[j] >> i) & 1) == 0)
					mark[j] = false;
		}
	}

	for (int i = 0; i < n && k > 0; ++i)
		if (mark[i]) {
            printf("%d ", a[i]);
			--k;
		}
    printf("\n");
	return 0;
}
