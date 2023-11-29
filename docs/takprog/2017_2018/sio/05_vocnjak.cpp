# include <stdio.h>
# include "code.h"

# define MAXN 1010
int smv[MAXN], smk[MAXN];
int npv, npk;
int a[MAXN][MAXN];



void Nadji(int i1, int j1, int i2, int j2, int vv, int *ii, int *jj) {
	int i, j;
	if (smv[i1] == 1) {
		if (smk[j2] == 1) {
			i = i1; j = j2;
			while (i <= i2) {
//				printf("cc %d %d\n", i, j);
				if (a[i][j] == 0)
					a[i][j] = DajVisinu(i, j);
				if (a[i][j] == vv) {
					*ii = i; *jj = j; return;
				}
				if (vv < a[i][j]) {
					j--;
					if (j < j1) return; // j < j1
				} else {
					if (j < j2) j++;
					if (++i > i2) return;
				}
			}						
		} else {
			i = i2; j = j2;
			while (i >= i1) {
//				printf("cc %d %d\n", i, j);
				if (a[i][j] == 0)
					a[i][j] = DajVisinu(i, j);
				if (a[i][j] == vv) {
					*ii = i; *jj = j; return;
				}
				if (vv < a[i][j]) {
					j--;	
					if (j < j1) return; // j < j1
				} else {
					if (j < j2) j++;
					if (--i < i1) return;
				}
			}						
		}
	} else {
		if (smk[j2] == 1) {
			i = i1; j = j1;
			while (i <= i2) {
//				printf("cc %d %d\n", i, j);
				if (a[i][j] == 0)
				if (a[i][j] == 0)
					a[i][j] = DajVisinu(i, j);
				if (a[i][j] == vv) {
					*ii = i; *jj = j; return;
				}
				if (vv < a[i][j]) {
					j++; 
					if (j > j2) return;
				} else {
					if (j > j1) j--;
					if (++i > i2) return;
				}
			}						
		} else {
			i = i2; j = j1;
			while (i >= i1) {
//				printf("cc %d %d\n", i, j);
				if (a[i][j] == 0)
					a[i][j] = DajVisinu(i, j);
				if (a[i][j] == vv) {
					*ii = i; *jj = j; return;
				}
				if (vv < a[i][j]) {
					j++;
					if (j > j2) return;	
				} else {
					if (j > j1) j--;
					if (--i < 1) return;
				}
			}						
		}
	}
}





void Resi2x2AA(int n, int i1, int j1, int vv, int *ii, int *jj) {
	int i, j;
	int radi[2][2] = {{1,1},{1,1}};
//	printf("Ovde %d %d %d %d\n", i1, j1, a[i1-1][j1-1], a[i1][j1]);
	if (vv > a[i1-1][j1-1]) {
		radi[0][0] = 0;
	} else {
		radi[0][1] = radi[1][0] = 0;
	}
	if (vv > a[i1][j1]) {
		radi[1][1] = 0;
	} else {
		radi[0][1] = radi[1][0] = 0;
	}
//	printf("%d\n", radi[0][1]);
	if (radi[0][0]) {
		Nadji(1, 1, i1-1, j1-1, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[0][1]) {
		Nadji(1, j1, i1-1, n, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[1][0]) {
		Nadji(i1, 1, n, j1-1, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[1][1]) {
		Nadji(i1, j1, n, n, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}	
}


void Resi2x2BB(int n, int i1, int j1, int vv, int *ii, int *jj) {
	int i, j;
	int radi[2][2] = {{1,1},{1,1}};
//	printf("Ovde %d %d %d %d\n", i1, j1, a[i1-1][j1-1], a[i1][j1]);
	if (vv < a[i1-1][j1-1]) {
		radi[0][0] = 0;
	} else {
		radi[0][1] = radi[1][0] = 0;
	}
	if (vv < a[i1][j1]) {
		radi[1][1] = 0;
	} else {
		radi[0][1] = radi[1][0] = 0;
	}
//	printf("%d\n", radi[0][1]);
	if (radi[0][0]) {
		Nadji(1, 1, i1-1, j1-1, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[0][1]) {
		Nadji(1, j1, i1-1, n, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[1][0]) {
		Nadji(i1, 1, n, j1-1, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}
	if (radi[1][1]) {
		Nadji(i1, j1, n, n, vv, ii, jj);
		if ((*ii != 0) && (*jj != 0)) return;
	}	
}




void Resi2x2(int n, int vv, int *ii, int *jj) {
	int i, j, i1, j1, i2, j2;
	i1 = 1; j1 = 1;
	*ii = *jj = 0;
	while (smv[i1] == smv[1]) i1++;
	while (smk[j1] == smk[1]) j1++;
	a[i1-1][j1-1] = DajVisinu(i1-1, j1-1);	
	a[i1-1][j1] = DajVisinu(i1-1, j1);	
	a[i1][j1-1] = DajVisinu(i1, j1-1);	
	a[i1][j1] = DajVisinu(i1, j1);	
	if (a[i1-1][j1-1] == vv) {
		*ii = i1-1; *jj = j1-1; return; 
	}
	if (a[i1-1][j1] == vv) {
		*ii = i1-1; *jj = j1; return; 
	}
	if (a[i1][j1-1] == vv) {
		*ii = i1; *jj = j1-1; return; 
	}
	if (a[i1][j1] == vv) {
		*ii = i1; *jj = j1; return; 
	}
	if ((smv[1] == 1) && (smk[1] == 1)) {
		Resi2x2AA(n, i1, j1, vv, ii, jj);
		return;	
	}
	if ((smv[1] == -1) && (smk[1] == -1)) {
		Resi2x2BB(n, i1, j1, vv, ii, jj);
		return;	
	}

}


void ResiV(int n, int vv, int *ii, int *jj) {

	int nadjen = 0;
	int i, j, i1, i2;
	i2 = 1;
	*ii = *jj = 0;
	while (i2 <= n) {
		i1 = i2;
		while ((i2 <= n) && (smv[i2] == smv[i1])) i2++;
//		printf("AA %d %d %d\n", i1, i2, vv);
		if (smk[1] == 1) {
			if (smv[i1] == -1) {
				a[i2-1][1] = DajVisinu(i2-1, 1);
				if (vv <= a[i2-1][1]) {
					nadjen = 1; break;
				}
			} else {
				a[i2-1][n] = DajVisinu(i2-1, n);
				if (vv <= a[i2-1][n]) {
					nadjen = 1; break;
				}
			}
		} else {
			if (smv[i1] == -1) {
				a[i2-1][n] = DajVisinu(i2-1, n);
				if (vv >= a[i2-1][n]) {
					nadjen = 1; break;
				}
			} else {
				a[i2-1][1] = DajVisinu(i2-1, 1);
				if (vv >= a[i2-1][1]) {
					nadjen = 1; break;
				}
			}
		}
	}
//	printf("BB %d %d\n", i2, a[i2-1][n]);
	if (!nadjen) {
		*ii = *jj = 0;
		return;
	}
	i2--;
	Nadji(i1, 1, i2, n, vv, ii, jj);


}

void ResiK(int n, int vv, int *ii, int *jj) {
	int nadjen = 0;
	int i, j, j1, j2;
	j2 = 1;
	*ii = *jj = 0;
	while (j2 <= n) {
		j1 = j2;
		while ((j2 <= n) && (smk[j2] == smk[j1])) j2++;
//		printf("AA %d %d %d\n", j1, j2, vv);
		if (smv[1] == 1) {
			if (smk[j1] == -1) {
				a[1][j2-1] = DajVisinu(1, j2-1);
				if (vv <= a[1][j2-1]) {
					nadjen = 1; break;
				}
			} else {
				a[n][j2-1] = DajVisinu(n, j2-1);
				if (vv <= a[n][j2-1]) {
					nadjen = 1; break;
				}
			}
		} else {
			if (smk[j1] == -1) {
				a[n][j2-1] = DajVisinu(n, j2-1);
				if (vv >= a[n][j2-1]) {
					nadjen = 1; break;
				}
			} else {
				a[1][j2-1] = DajVisinu(1, j2-1);
				if (vv >= a[1][j2-1]) {
					nadjen = 1; break;
				}
			}
		}
	}
//	printf("BB %d %d\n", j2, a[n][j2-1]);
	if (!nadjen) {
		*ii = *jj = 0;
		return;
	}
	j2--;
	Nadji(1, j1, n, j2, vv, ii, jj);
}


void Resi(int n, int k, int vv, int *ii, int *jj) {
	int i, j;
	a[1][1] = DajVisinu(1, 1);
	a[1][2] = DajVisinu(1, 2);
	if (a[1][1] < a[1][2]) smv[1] = 1; else smv[1] = -1;
	for (i = 2; i < n; i++) {
		a[i][i] = DajVisinu(i, i);
		a[i][i+1] = DajVisinu(i, i+1);
		if (a[i][i] < a[i][i+1]) smv[i] = 1; else smv[i] = -1;
		if (a[i-1][i] < a[i][i]) smk[i] = 1; else smk[i] = -1;
	}
	a[n][n] = DajVisinu(n, n);
	a[n][1] = DajVisinu(n, 1);
	if (a[n][1] < a[n][n])	smv[n] = 1; else smv[n] = -1;
	if (a[1][1] < a[n][1])	smk[1] = 1; else smk[1] = -1;
	if (a[n-1][n] < a[n][n]) smk[n] = 1; else smk[n] = -1;
	npv = npk = 1;
	for (i = 2; i <= n; i++) {
		if (smv[i-1] != smv[i]) npv++;
		if (smk[i-1] != smk[i]) npk++;
	}	
	  
//	printf("%d %d\n", npv, npk);

	if (npv == 1) {
		ResiK(n, vv, ii, jj);
		return;
	}
	if (npk == 1) {
		ResiV(n, vv, ii, jj);
		return;
	}
	Resi2x2(n, vv, ii, jj);
}
