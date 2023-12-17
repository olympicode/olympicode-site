# include <stdio.h>
# include <stdlib.h>

# define MAXN 510

long long k;
int m, n;
int ip, jp;
int op[MAXN][MAXN];
int zid[4][MAXN][MAXN];
int bio[4][MAXN][MAXN];

void citaj() {
  char zn;
  int i, j;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &ip, &jp);
  scanf("%lld", &k);
  for (j = 0; j <= m+1; j++) 
    op[0][j] = op[n+1][j] = 1;
  for (i = 0; i <= n+1; i++) 
    op[i][0] = op[i][m+1] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      zn = getchar();
      if (zn == '#') op[i][j] = 1; else op[i][j] = 0;
    }
    if (i < n)
      while ((zn = getchar()) != '\n');
  }
}

void pripremi() {
  int p;
  int i, j;
  int ip, jp;
  for (j = 1; j <= m; j++) {
    i = n;
    while ((i >= 1) && op[i][j]) {
      zid[0][i][j] = -1; 
      i--;
    }
    ip = i+1;
    while (i >= 1) {
      if (op[i][j] == 0) {
        zid[0][i][j] = ip-1;
      } else {
        zid[0][i][j] = -1;
        ip = i;
      }
      i--;
    }
  } 
  for (i = 1; i <= n; i++) {
    j = m;
    while ((j >= 1) && op[i][j]) {
      zid[1][i][j] = -1;
      j--;
    }
    jp = j+1;
    while (j >= 1) {
      if (op[i][j] == 0) {
        zid[1][i][j] = jp-1;
      } else {
        zid[1][i][j] = -1;
        jp = j;
      }
      j--;
    }
  }
  for (j = 1; j <= m; j++) {
    i = 1;
    while ((i <= n) && op[i][j]) {
      zid[2][i][j] = -1; 
      i++;
    }
    ip = i-1;
    while (i <= n) {
      if (op[i][j] == 0) {
        zid[2][i][j] = ip+1;
      } else {
        zid[2][i][j] = -1;
        ip = i;
      }
      i++;
    }
  } 
  for (i = 1; i <= n; i++) {
    j = 1;
    while ((j <= m) && op[i][j]) {
      zid[3][i][j] = -1;
      j++;
    }
    jp = j-1;
    while (j <= m) {
      if (op[i][j] == 0) {
        zid[3][i][j] = jp+1;
      } else {
        zid[3][i][j] = -1;
        jp = j;
      }
      j++;
    }
  }
  for (p = 0; p < 4; p++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        bio[p][i][j] = -1;
  bio[3][ip][jp] = 0;
}

void obidji() {
  long long kt; 
  int pt, ps;
  int it, jt, is, js;      
  pt = 0; it = ip; jt = jp;
  kt = 0;
  while (kt < k) {
    kt++;
    switch (pt) {
      case 0:
        is = zid[0][it][jt];
        js = jt;
        ps = 1;
        break;
      case 1:
        is = it;
        js = zid[1][it][jt];
        ps = 2;
        break;
      case 2:
        is = zid[2][it][jt];
        js = jt;
        ps = 3;
        break;
      case 3:
        is = it;
        js = zid[3][it][jt];
        ps = 0;
        break;
    }
    it = is;
    jt = js;
    pt = ps;
//    printf("%d %d\n", it, jt);
    if (bio[pt][it][jt] >= 0) break;
    bio[pt][it][jt] = kt;
  }        
//  printf("%d\n", kt);
  if (kt == k) {
    printf("%d %d\n", it, jt);
  } else {
    long long kp;
    kp = kt - bio[pt][it][jt];
    kt = kt + (k - kt) / kp * kp;
    while (kt < k) {
      kt++;
      switch (pt) {
        case 0:
          is = zid[0][it][jt];
          js = jt;
          ps = 1;
          break;
        case 1:
          is = it;
          js = zid[1][it][jt];
          ps = 2;
          break;
        case 2:
          is = zid[2][it][jt];
          js = jt;
          ps = 3;
          break;
        case 3:
          is = it;
          js = zid[3][it][jt];
          ps = 0;
          break;
      }
      it = is;
      jt = js;
      pt = ps;
    }
    printf("%d %d\n", it, jt);
  }      
}

int main() {
  citaj();
  pripremi();
  obidji();
//  system("pause");
  return 0;
}

        
