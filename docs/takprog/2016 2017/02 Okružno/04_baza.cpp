#include <cstdlib>
#include <cstdio>

long long n, m;

void solve()
{
	
	if (n == 1 && m == 1)
	{
		printf("1\n");
		printf("1 1\n");
		return;
	}
	if (n == 1 && m != 1)
	{
		printf("-1\n");
		return;
	}

	long long upBound = (n < m / n ? n : m / n);

	for (long long a = 1LL; a <= upBound; a++) // a = 1 hvata slucaj m = n^2
	{
		if (m - a * n > 0 && n - a > 0 && (m - a * n) % (n - a) == 0)
		{
			long long b = (m - a * n) / (n - a); // uvek vazi a <= b

			printf("%lld\n", b);
			for (long long i = 1; i <= a; i++)
			{
				printf("%lld %lld\n", i, i);
			}
			for (long long i = a + 1; i <= b; i++)
			{
				printf("%lld %lld\n", a, i);
			}
			return;
		}
	}

	printf("-1\n");
	return;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	solve();
	return 0;
}
