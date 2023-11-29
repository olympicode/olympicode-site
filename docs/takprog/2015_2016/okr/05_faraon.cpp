#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

const int MaxNumber = 1000000;

int T, p, q;

int sqrtMaxNumber;
int smallestDivisor[MaxNumber+5];
int dp[MaxNumber+5];

int gcd(int a, int b)
{
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	memset(smallestDivisor, -1, sizeof(smallestDivisor));
	sqrtMaxNumber = int(sqrt(MaxNumber)) + 1;

	smallestDivisor[1] = -1;
	for (int number = 2; number <= sqrtMaxNumber; ++number) {
		if (smallestDivisor[number] != -1) continue;

		smallestDivisor[number] = number;
		for (int curr = number * number; curr <= MaxNumber; curr += number) {
			if (smallestDivisor[curr] == -1) smallestDivisor[curr] = number;
		}
	}
	for (int i = sqrtMaxNumber; i <= MaxNumber; ++i) {
		if (smallestDivisor[i] == -1) smallestDivisor[i] = i;
	}

	dp[1] = 0;
	for (int number = 2; number <= MaxNumber; ++number) {
		int previousNumber = number / smallestDivisor[number];
		dp[number] = dp[previousNumber] + 1;
	}

	scanf("%d",&T);
	for (;T--;) {
		scanf("%d%d",&p,&q);
		int result = dp[p] + dp[q] - 2 * dp[gcd(p,q)];
		printf("%d\n",result);
	}

	return 0;
}