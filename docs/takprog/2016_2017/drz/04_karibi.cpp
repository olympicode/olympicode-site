#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 2010;

char s[MAX_N][MAX_N];
int U[MAX_N][MAX_N], L[MAX_N][MAX_N], R[MAX_N][MAX_N], D[MAX_N][MAX_N];
int currSum[MAX_N];

// broj horizontalnih nacina za postavljanje koje zauzima brod na pozicijiama [i][j1]...[i][j2] brodu duzine d
int H(int i, int j1, int j2, int d)
{
	int l = j1 - L[i][j1] + 1;
	int r = j2 + R[i][j2] - d;
	if (r < l) return 0;
	int l1 = j1 - d + 1;
	int r1 = j2;
	return (std::min(r, r1) - std::max(l, l1) + 1);
}
// broj vertikalnih nacina za postavljanje koje zauzima brod na pozicijiama [i1][j]...[i2][j] brodu duzine d
int V(int j, int i1, int i2, int d)
{
	int l = i1 - U[i1][j] + 1;
	int r = i2 + D[i2][j] - d;
	if (r < l) return 0;
	int l1 = i1 - d + 1;
	int r1 = i2;
	return (std::min(r, r1) - std::max(l, l1) + 1);
}

int solve(int n, int m, int a, int b, char s[][MAX_N])
{
	for (int i = 0; i <= n + 1; i++)
	{
		s[i][0] = '1';
		s[i][m + 1] = '1';
	}
	for (int j = 0; j <= m + 1; j++)
	{
		s[0][j] = '1';
		s[n + 1][j] = '1';
	}

	// racunanje U, L, R i D matrica
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			L[i][j] = U[i][j] = 0;
			if (s[i][j] == '0')
			{
				L[i][j] = 1 + L[i][j - 1];
				U[i][j] = 1 + U[i - 1][j];
			}
		}
	}
	for (int i = n + 1; i >= 1; i--)
	{
		for (int j = m + 1; j >= 1; j--)
		{
			R[i][j] = D[i][j] = 0;
			if (s[i][j] == '0')
			{
				R[i][j] = 1 + R[i][j + 1];
				D[i][j] = 1 + D[i + 1][j];
			}
		}
	}

	// racunanje ukupnog broja nacina da se postavi b-brod bez a-broda
	int totalNumOfWays = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (L[i][j] >= b) totalNumOfWays++;
			if (U[i][j] >= b) totalNumOfWays++;
		}
	}

	int maxReduction = 0;
	// proveri sve moguce horizontalne pozicije za a-brod
	for (int i = 1; i <= n; i++)
	{
		currSum[0] = 0;
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == '0')
			{
				currSum[j] = currSum[j - 1] + V(j, i, i, b);
			}
			else
			{
				currSum[j] = 0;
			}

			if (L[i][j] >= a)
			{
				int currReduction = H(i, j - a + 1, j, b) + currSum[j] - currSum[j - a];
				if (currReduction > maxReduction)
				{
					maxReduction = currReduction;
				}
			}
		}
	}
	// proveri sve moguce vertikalne pozicije za a-brod
	for (int j = 1; j <= m; j++)
	{
		currSum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i][j] == '0')
			{
				currSum[i] = currSum[i - 1] + H(i, j, j, b);
			}
			else
			{
				currSum[i] = 0;
			}

			if (U[i][j] >= a)
			{
				int currReduction = V(j, i - a + 1, i, b) + currSum[i] - currSum[i - a];
				if (currReduction > maxReduction)
				{
					maxReduction = currReduction;
				}
			}
		}
	}

	return totalNumOfWays - maxReduction;
}

int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	}

	int sol = solve(n, m, a, b, s);
	printf("%d\n", sol);

	return 0;
}
