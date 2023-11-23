#include <cstdlib>
#include <cstdio>

const int MAX_N = 1000100;

int n, m;
bool row[MAX_N], col[MAX_N];
long long a, b, sol;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		row[i] = false;
		col[i] = false;
	}
	
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		row[x] = true;
		col[y] = true;
	}

	a = 0LL;
	b = 0LL;
	for (int i = 1; i <= n; i++)
	{
		if (row[i] == true) a++;
		if (col[i] == true) b++;
	}

	sol = a * n + b * n - a * b;
	printf("%lld\n", sol);
	return 0;
}
