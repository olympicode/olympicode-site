#include <bits/stdc++.h>
#define MAXN 300007
#define MAXL 20
using namespace std;
int a[2*MAXN],nxt[MAXL][MAXN],rs[MAXN],rf[MAXN],l[MAXN],r[MAXN],p[2*MAXN];
bool check(int u, int v)
{
	return (l[u]<l[v] && r[v]<r[u]) || (l[v]<l[u] && r[u]<r[v]);
}
bool left(int u,int v)
{
	if(check(u,v)) return false;
	return l[u]<l[v];
}
int dist(int u,int v)
{
	if(u==v) return 0;
	if(check(u,v)) return 1;
	int w=u,d=1;
	for(int i=MAXL-1;i>=0;i--) if(left(nxt[i][w],v)) {w=nxt[i][w]; d+=(1<<i);}
	return d+1;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=2*n;i++)
	{
		if(!l[a[i]]) l[a[i]]=i;
		else r[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {p[l[i]]=r[i]; p[r[i]]=l[i];}
	int mxr=0,nd=0;
	for(int i=1;i<=2*n;i++) if(p[i]>i)
	{
		if(p[i]<mxr) rf[a[i]]=nd;
		else {rf[a[i]]=-1; mxr=p[i]; nd=a[i];}
	}
	int mxl=0; nd=0;
	for(int i=1;i<=2*n;i++) if(p[i]<i)
	{
		if(p[i]<mxl) rs[a[i]]=nd;
		else {rs[a[i]]=-1; mxl=p[i]; nd=a[i];}
	}
	for(int i=1;i<=n;i++)
	{
		if(rs[i]==-1) nxt[0][i]=(rf[i]==-1)?i:rf[i];
		if(rf[i]==-1) nxt[0][i]=(rs[i]==-1)?i:rs[i];
	}
	for(int i=1;i<MAXL;i++) for(int j=1;j<=n;j++) nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	for(int i=1;i<=q;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		if(u==v) {printf("0\n"); continue;}
		if(check(u,v)) {printf("1\n"); continue;}
		if(left(v,u)) swap(u,v);
		int ws=u,wf=u,ds=0,df=0;
		if(rs[u]!=-1) {ws=rs[u]; ds++;}
		if(rf[u]!=-1) {wf=rf[u]; df++;}
		int w=nxt[MAXL-1][ws];
		if(left(w,v)) {printf("-1\n"); continue;}
		int res1=dist(ws,v)+ds,res2=dist(wf,v)+df;
		printf("%d\n",min(res1,res2));
	}
}
