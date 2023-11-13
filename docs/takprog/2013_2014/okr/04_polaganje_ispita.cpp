#include<stdio.h>
#include<math.h>
#define MAX_N 5005
#define MAX_VALUE 1000005

int n, k, a [MAX_N], count [2 * MAX_VALUE];
bool marked [MAX_N];

void input()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a [i]);
}

void output()
{
	for (int i = 0; i < n; i++)
	{
		if (marked [i])
		{
			printf("%d ", a [i]);
		}
	}
	printf("\n");
}


void count_sort()
{
	for (int i = 0; i < 2 * MAX_VALUE; i++)
		count [i] = 0;
	for (int i = 0; i < n; i++)
		count [MAX_VALUE + a [i]]++;
	int index = 0;
	for (int i = 0; i < 2 * MAX_VALUE; i++)
	{
		while (count [i] > 0)
		{
			a [index] = i - MAX_VALUE;	
			index++;
			count[i]--;
		}
	}
}

void solve()
{
	count_sort();

	for (int i = 0; i < MAX_N; i++)
		marked [i] = false;

	int indexA = 0, indexB = n - 1, sign = 1;
	while (indexA + (n - 1 - indexB) < k)
	{
		if (abs(a [indexA]) > a [indexB] && a [n - 1] >= 0)
		{
			marked [indexA] = true;
			if (a [indexA] < 0)
				sign *= -1;
			indexA++;
		}
		else
		{
			marked [indexB] = true;
			indexB--;
		}
	}

	if (sign == -1)
	{
		if (indexB == n - 1)
		{
			marked [indexA - 1] = false;
			marked [indexB] = true;
		}
		else
		{
			if ((a [indexA] * a [indexA - 1]) > (a [indexB] * a [indexB + 1]))
			{
				marked [indexB + 1] = false;
				marked [indexA] = true;
			}
			else
			{
				marked [indexA - 1] = false;
				marked [indexB] = true;
			}
		}
	}
}

int main()
{
	input();
	solve();
	output();

	return 0;
}