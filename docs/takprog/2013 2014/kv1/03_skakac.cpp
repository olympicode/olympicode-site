#include <cstdlib>
#include <cstdio>

const int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};

int X[100], Y[100];
int n, m, r, c, k, sol;

bool ok(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int solveK1()
{
	int sol = 0;
	for (int i = 0; i < 8; i++)
		if (ok(r + dx[i], c + dy[i])) sol++;
	return sol;
}

int solveK2()
{
	int num = 0;
	for (int i = 0; i < 8; i++)
	{
		if (ok(r + dx[i], c + dy[i]))
		{
			for (int j = 0; j < 8; j++)
			{
				if (ok(r + dx[i] + dx[j], c + dy[i] + dy[j]))
				{
					num++;
					X[num] = r + dx[i] + dx[j];
					Y[num] = c + dy[i] + dy[j];
				}
			}
		}
	}

	int sol = 0;
	for (int i = 1; i <= num; i++)
	{
		bool moveExists = false;
		for (int j = 1; j < i; j++)
		{
			if (X[i] == X[j] && Y[i] == Y[j])
				moveExists = true;
		}
		if (!moveExists) sol++;
	}

	return sol;
}

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &r, &c, &k);
		
	if (k == 1)
		printf("%d\n", solveK1());
	else
		printf("%d\n", solveK2());

	return 0;
}