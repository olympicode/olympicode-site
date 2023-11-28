#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

const int MAX_N = 800010;
const int MAX_K = 3010;
const int MAX_T = 3010;

int n, k, t;
int v[MAX_N];
long long d[2][MAX_N];

long long solve(int n, int k, int t, int v[])
{
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++)
	{
		d[0][i] = max(d[0][i - 1], (long long)v[i]);
	}

	int currRow = 0;
	for (int i = 2; i <= k; i++)
	{
		currRow = 1 - currRow;
		int L = 1 + (i - 1) * t;
		int R = n - (k - i) * t;
		d[currRow][L] = d[1 - currRow][L - t] + v[L];
		for (int j = L + 1; j <= R; j++)
		{
			d[currRow][j] = max(d[currRow][j - 1], d[1 - currRow][j - t] + v[j]);
		}
	}

	return d[currRow][n];
}

int main()
{

	scanf("%d%d%d", &n, &k, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}
	n = n - (t - 1);

	printf("%lld\n", solve(n, k, t, v));

	return 0;
}