#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
using namespace std;

#define MaxN 100005
#define MaxM 100005

int n, m;
long long k;
int a[MaxN];

vector<int> KbaseM;

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	--k;

	if (n == 1) {
		printf("%d", a[0]);
		for (int i = 1; i < m; ++i)
			printf(" %d", a[0]);
		printf("\n");
	}
	else {

		while (k > 0) {
			KbaseM.push_back(k % n);
			k /= n;
		}

		bool first = true;
		for (int i = 0; i < m - KbaseM.size(); ++i) {
			if (first) first = false; else printf(" ");
			printf("%d", a[0]);
		}

		for (int i = KbaseM.size() - 1; i >= 0; --i) {
			if (first) first = false; else printf(" ");
			printf("%d", a[ KbaseM[i] ]);
		}
		printf("\n");

	}
}