#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 510;
const int MAX_M = MAX_N * MAX_N;
const long long INFTY = 1000000000000000000LL;

int n, m, k, a, b;
int home[MAX_N];
int x[MAX_M], y[MAX_M], z[MAX_M];

//----------------------------------------
long long d[MAX_N][MAX_N];
long long weight[MAX_N][MAX_N];

struct minDist
{
	int ind;
	long long val;
};

bool cmp(const minDist& a, const minDist& b)
{
	return (a.val > b.val);
}

minDist s[MAX_N];
long long val[MAX_N];
int inv[MAX_N];

long long FindShortestTime(int n, int m, int k, int a, int b, int home[], int x[], int y[], int z[]) 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INFTY;
		}
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0LL;

	for (int i = 1; i <= m; i++)
	{
		d[x[i]][y[i]] = z[i];
		d[y[i]][x[i]] = z[i];
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		s[i].ind = i;
		s[i].val = INFTY;
		for (int j = 1; j <= k; j++)
		{
			s[i].val = min(s[i].val, d[i][home[j]]);
		}
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		inv[s[i].ind] = i;
		val[i] = s[i].val;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INFTY;
			weight[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u = inv[x[i]];
		int v = inv[y[i]];
		d[u][v] = z[i];
		d[v][u] = z[i];
		weight[u][v] = z[i];
		weight[v][u] = z[i];
	}

	long long sol = INFTY;

	for (int w = 1; w <= n; w++)
	{
		for (int u = 1; u < w - 1; u ++)
		{
			for (int v = u + 1; v < w; v++)
			{
				if (weight[w][u] != -1 && weight[w][v] != -1 && d[u][v] != INFTY)
				{
					sol = min(sol, val[w] * b + (weight[w][u] + weight[w][v] + d[u][v]) * a);
				}
			}
		}

		for (int u = 1; u <= n; u++)
		{
			for (int v = 1; v <= n; v++)
			{
				d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
			}
		}
	}

	return sol;
}

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &home[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}

	printf("%lld\n", FindShortestTime(n, m, k, a, b, home, x, y, z));

	return 0;
}