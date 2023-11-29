# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

# define MAXN 30030

# define BEO 0
# define SIV 1
# define CRN 2

int n, m, no;

vector<int> susedi[MAXN];

int mark[MAXN];
int tord[MAXN];
int s[MAXN], x[MAXN];

citaj() {
  int i, j, k, zn;
  scanf("%d%d", &n, &m);
  for (k = 0; k <= n; k++)
  	susedi[k].clear();
  for (k = 1; k <= m; k++) {
  	scanf("%d%d%d", &i, &j, &zn);
  	if (zn > 0)
  	  susedi[i-1].push_back(j);
  	else
  	  susedi[j].push_back(i-1);
  }
}

int topordr(int c1) {
  int k, c2;
  mark[c1] = SIV;
  for (k = 0; k < susedi[c1].size(); k++) {
  	c2 = susedi[c1][k];
  	if (mark[c2] == CRN) continue;
  	if (mark[c2] == SIV) return 1;
  	if (topordr(c2) != 0) return 1;
  }
  tord[no--] = c1;
  mark[c1] = CRN;
  return 0;
}

int topord() {
  int k;
  for (k = 0; k <= n; k++) mark[k] = BEO;
  no = n;
  for (k = 0; k <= n; k++) 
    if (mark[k] == BEO)
      if (topordr(k)) return 1;
  return 0;
}

resi() {
  int i, j, k;
  k = 0; 
  while (tord[k] != 0) k++;
  s[0] = 0;
  for (i = k-1, j = -1; i >= 0; i--, j--) 
    s[tord[i]] = j;	
  for (i = k+1, j = 1; i <= n; i++, j++) 
    s[tord[i]] = j;	
  for (k = 1; k <= n; k++) 
    x[k] = s[k] - s[k-1];
}

main() {
  int s, t;
  scanf("%d", &t);
  for (s = 1; s <= t; s++) {
  	citaj();
  	if (topord() != 0)  
    	printf("-1\n");
  	else {
  		resi();
    	printf("1\n");
  		for (int k = 1; k < n; k++)
  	  		printf("%d ", x[k]);
  	  	printf("%d\n", x[n]);
    }    
  }
  return 0;
}
