# include <stdio.h>
# include <stdlib.h>

# define MAXN 1000000
# define MAXM 1000

int c1;
int n, m;
int g[MAXN];
int a[MAXN], b[MAXN];
int brp[MAXM][10][10];
int brf[MAXM][10];
int ukc, minc, trenc;
int c2[10][10];

void citaj() {
	int i;
	scanf("%d%d", &n, &c1);
	for (i = 0; i < n; i++) 
	  scanf("%d", &g[i]);
	for (i = 0; i < n; i++) 
	  scanf("%d", &a[i]);
	for (i = 0; i < n; i++) 
	  scanf("%d", &b[i]);	
}

void odredic2() {
	int i, j;
	for (i = 0; i < 10; i++) 
	  for (j = 0; j < 10; j++) {
	  	c2[i][j] = abs(i - j);
	  	if (10 - c2[i][j] < c2[i][j])
	  	   c2[i][j] = 10 - c2[i][j];
	  }
}

void prebroj() {
	int i;
	int mt;
	for (i = 0; i < n; i++) {
		mt = g[i];
		if (mt > m) m = mt;
		brp[mt][a[i]][b[i]]++;
		brf[mt][b[i]]++;
	}
}

void resi() {
	int mt;
	int i, j;
	for (mt = 0; mt <= m; mt++) {
	    trenc = 0;
		for (i = 0; i < 10; i++)
		  for (j = 0; j < 10; j++)
		    trenc += brp[mt][i][j] * c2[i][j];
		minc = trenc;
		for (i = 0; i < 10; i++) {
			trenc = c1;
			for (j = 0; j < 10; j++)
			  trenc += brf[mt][j] * c2[i][j];
			if (trenc < minc)
			  minc = trenc;
		}
		ukc += minc;
	}
}

void pisi() {
	printf("%d\n", ukc);
}

main() {
	citaj();
	odredic2();
	prebroj();
	resi();
	pisi();
}
