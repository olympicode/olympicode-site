# include <stdio.h>

# define MAXNM 110
# define MAXK 10100
# define MOD 1000000007

int n, m;

int t[MAXNM][MAXNM];
int c[MAXNM][MAXNM];
int cz[MAXNM][MAXNM];

int F[MAXK];

long long rez;

long long prs[MAXNM][MAXNM];
long long prt[MAXNM][MAXK];

citaj() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
  	for (j = 1; j <= m; j++)
	  scanf("%d", &t[i][j]);
  for (i = 1; i <= n; i++) {
  	k = 0;
  	for (j = 1; j <= m; j++) {
  		scanf("%d", &c[i][j]);
  		if (c[i][j] == 1) {
  			k++;
			cz[i][k] = j;	
		}
	}
	k++;
	cz[i][k] = -1;
 }
  for (i = 1; i <= n * m; i++)
  	scanf("%d", &F[i]);	
}


void racunajprs() {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		prs[i][0] = 1;
		for (j = 1; j <= m; j++) 
			prs[i][j] = 0;
		for (j = 1; j <= m; j++) {
			for (k = j; k >= 1; k--) {
				prs[i][k] = (prs[i][k] + prs[i][k-1] * t[i][j]) % MOD;
			}
		}
	}
}

void racunajprt() {
	int i, j, j1, k;
	for (j1 = 1; cz[1][j1] != -1; j1++) {
		j = cz[1][j1];
		prt[1][j] = prs[1][j];
	}
	for (i = 2; i <= n; i++) {
		for (j1 = 1; cz[i][j1] != -1; j1++) {
			j = cz[i][j1];
			for (k = (i - 1) * m; k >= 0; k--) {
				prt[i][k+j] = (prt[i][k+j] + prt[i-1][k] * prs[i][j]) % MOD;
			}
		}
	}
	rez = 0;
	for (k = 1; k <= m * n; k++) {
		rez = (rez + prt[n][k] * F[k]) % MOD;
	}
}

pisi() {
	printf("%lld\n", rez);
}

main() {
	citaj();
	racunajprs();
	racunajprt();
	pisi();
	return 0;	
}
