#include <cstdlib>
#include <cstdio>

int red, blue, yellow;
int n, num;

int main()
{
	red = 0; blue = 0; yellow = 0;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		while (num > 0)
		{
			switch (num % 10)
			{
			case 1: red += 2; break;
			case 2: blue += 2; break;
			case 3: yellow += 2; break;
			case 4: red++; yellow++; break;
			case 5: yellow++; blue++; break;
			case 6: blue++; red++; break;
			}
			num /= 10;
		}
	}

	printf("%d %d %d\n", red, blue, yellow);
	return 0;
}