#include <cstdlib>
#include <cstdio>

const int MAX_N = 300100;

int n, m, k;
int r[MAX_N]; // r[i] - redni broj takmicara koji sedi za racunarom i

int main()
{
	scanf("%d%d%d", &n, &m, &k);

	int num_suspicious = 0; // trenutni broj sumnjivih takmicara
	
	for (int i = 1; i <= n; i++)
		r[i] = i;

	for (int i = 1; i <= m; i++)
	{
		int a, b, tmp;
		scanf("%d%d", &a, &b);

		if (abs(a - r[a]) > k) num_suspicious--;
		if (abs(b - r[b]) > k) num_suspicious--;
		if (abs(a - r[b]) > k) num_suspicious++;
		if (abs(b - r[a]) > k) num_suspicious++;

		tmp = r[a]; 
		r[a] = r[b]; 
		r[b] = tmp;

		if (num_suspicious > 0)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
} // O(n + m)