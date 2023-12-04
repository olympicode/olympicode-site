#include <cstdlib>
#include <cstdio>

const long long MAX_VAL = 1000000000000000000LL;
const int MAX_DIGITS = 18;
const int MAX_K = 100000;

long long X, Y;
int k;
long long a[MAX_K + 10];

long long c[10];
int x[10];
bool found;
long long solution;

void precalc()
{
	for (int val = 1; val <= 9; val++)
	{
		long long curr = 1LL;
		c[val] = 0LL;
		int i = 1;

		while (i <= k)
		{
			curr = curr * val;
			if (curr > MAX_VAL / a[i])
			{
				c[val] = MAX_VAL + 1;
				break;
			}
			c[val] = c[val] + curr * a[i];
			if (c[val] > MAX_VAL)
			{
				c[val] = MAX_VAL + 1;
				break;
			}
			i++;
		}
	}
}

long long calc(int x[])
{
	long long ret = 0LL;
	for (int i = 1; i <= 9; i++)
	{
		if (x[i] > MAX_VAL / c[i])
			return MAX_VAL + 1;
		ret = ret + c[i] * x[i];
		if (ret > MAX_VAL)
			return MAX_VAL + 1;
	}

	return ret;
}

bool check(int x[])
{
	long long n = calc(x);
	if (n < X || n > Y)
		return false;

	int x1[10];
	for (int i = 0; i <= 9; i++)
		x1[i] = 0;

	long long n1 = n;
	while (n > 0)
	{
		x1[n % 10]++;
		n = n / 10;
	}
	for (int i = 1; i <= 9; i++)
		if (x[i] != x1[i])
			return false;

	solution = n1;
	return true;
}

void F(int n, int currDigit)
{
	if (found)
		return;

	if (n > MAX_DIGITS || currDigit == 0)
	{
		found = check(x);
		return;
	}

	x[currDigit]++;
	F(n + 1, currDigit);
	x[currDigit]--;
	F(n, currDigit - 1);
}

int main()
{
	scanf("%lld%lld%d", &X, &Y, &k);
	for (int i = 1; i <= k; i++)
		scanf("%lld", &a[i]);

	precalc();

	for (int i = 0; i <= 9; i++)
		x[i] = 0;
	found = false;
	solution = -1LL;

	F(1, 9);

	printf("%lld\n", solution);
	return 0;
}
