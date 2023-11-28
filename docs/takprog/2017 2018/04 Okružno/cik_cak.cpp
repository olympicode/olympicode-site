# include <stdio.h>

# define MAXN 50050

int n;
int a[MAXN];
long long s, s1, s2, s3;

main() {
	int i, j, k;
	scanf("%d%lld", &n, &s1);
	s = (long long)n * (n-1) / 2;
	if (s1 > s) {
		printf("-1\n");
		return 0;
	}
	if (s1 < -s) {
		printf("-1\n");
		return 0;
	}
	if ((s - s1) %2 == 1) {
		printf("-1\n");
		return 0;
	}
	s2 = (s - s1) / 2;
	a[0] = 0;
	for (i = 1, j = n-1; i < n; i++, j--) 
		if (j <= s2) {
			a[i] = a[i-1] - 1;
			s2 -= j;
		} else {
			a[i] = a[i-1] + 1;
		}
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}
