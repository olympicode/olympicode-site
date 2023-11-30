#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int a[MAXN][MAXN];
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {if(a[i][j]>1000 || a[i][j]<=0) printf("%d %d %d\n",i,j,a[i][j]); assert(a[i][j]>0 && a[i][j]<1001);}
	int mx1=-2000000000,mx2=-2000000000;
	for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) mx1=max(mx1,a[i][j]-2*i-2*j);
	for(int i=x;i<=n;i++) for(int j=y;j<=m;j++) mx2=max(mx2,a[i][j]+2*i+2*j);
	printf("%d",mx1+mx2+4);
}
