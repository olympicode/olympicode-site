#include <cstdlib>
#include <cstdio>
#include <cstring>

const int MaxN = 100100;

int n, a, digCount;
int digits[20];
long long curr, deg;
char b[MaxN];

int main()
{
	scanf("%d", &a);
	scanf("%s", b);
	n = strlen(b);
	
	curr = 0LL;
	for (int i = 0; i < n; i++)
		curr = (curr * 10 + (b[i] - '0')) % a;

	deg = 1;
	digCount = 0;
	while ((a - curr) % a >= deg)
	{
		deg = deg * 10;
		digCount++;
		curr = (curr * 10) % a;
	}

	curr = (a - curr) % a;
	for (int i = 1; i <= digCount; i++)
	{
		digits[i] = curr % 10;
		curr = curr / 10;
	}

	for (int i = 0; i < n; i++)
		printf("%c", b[i]);
	for (int i = digCount; i > 0; i--)
		printf("%d", digits[i]);
	printf("\n");
	return 0;
}