#include <cstdlib>
#include <cstdio>

const int MAX_N = 20;
const int MAX_SUM = 2000000001;

int n, k, sol;
long long counter = 0LL, counter2 = 0LL;
int a[MAX_N], b[MAX_N], sum[MAX_N], part[MAX_N];

void check()
{
	for (int i = 0; i < k; i++) sum[i] = 0;
	int minSum = MAX_SUM, maxSum = 0;

	for (int i = 0; i < n; i++)
	{
		sum[ b[i] ] = sum[ b[i] ] + a[i];
	}

	for (int i = 0; i < k; i++)
	{
		minSum = (sum[i] < minSum ? sum[i] : minSum);
		maxSum = (sum[i] > maxSum ? sum[i] : maxSum);
	}

	if (maxSum - minSum < sol)
	{
		sol = maxSum - minSum;
		for (int i = 0; i < n; i++)
		{
			part[i] = b[i];
		}
	}
}

void F(int currSet, int currNum, int currMinIndex)
{
	if (currNum >= n)
	{
		return;
	}
	if (currSet == k)
	{
		check();
		//counter++;
		return;
	}

	b[currMinIndex] = currSet;
	for (int mask = 0; mask < (1 << (n - currNum - 1)); mask++)
	{
		counter2++;

		int ind = -1;
		int newMinInd = -1;
		int numOfElems = 1;
		for (int i = currMinIndex + 1; i < n; i++)
		{
			if (b[i] == 0)
			{
				ind++;
				if ((mask & (1 << ind)) != 0) 
				{
					b[i] = currSet;
					numOfElems++;
				}
				else if (newMinInd == -1) newMinInd = i;
			}
		}
		F(currSet + 1, currNum + numOfElems, newMinInd);
		for (int i = currMinIndex + 1; i < n; i++)
		{
			if (b[i] == currSet) b[i] = 0;
		}
	}
	b[currMinIndex] = 0;
}

int main() 
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sol = MAX_SUM;
	for (int i = 0; i <= n; i++)
		b[i] = 0;

	F(1, 0, 0);
	printf("%d\n", sol);

	for (int i = 0; i < n; i++)
		printf("%d ", part[i] + 1);
	printf("\n");

	/*counter = 0LL;
	counter2 = 0LL;
	F(1, 0, 0);
	printf("%lld\n", counter);
	printf("%lld\n", counter2);*/
	return 0;
}