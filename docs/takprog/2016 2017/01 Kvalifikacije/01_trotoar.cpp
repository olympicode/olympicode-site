#include <cstdlib>
#include <cstdio>

int a, b, c, sol;

int main()
{
	scanf("%d%d%d", &a, &b, &c);

	sol = 1000000000;
	if (a + b + c < sol)
		sol = a + b + c;
	if (a + b * c < sol)
		sol = a + b * c;
	if (a * b + c < sol)
		sol = a * b + c;
	if (a * b * c < sol)
		sol = a * b * c;

	printf("%d\n", sol);
	return 0;
}
