#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
vector<int> g[MAXN];
vector<int> dp[2][MAXN];
bool op[MAXN];
int k[MAXN],co[MAXN];
bool cmp(int x,int y) {return g[x].size()<g[y].size();}
void dfs(int s,int p)
{
    if(g[s].size()==1 && s!=p) {dp[1][s][1]=true; op[s]=true; k[s]=1; return;}
	int deg=g[s].size();
	vector<int> v;
	for(int i=0;i<deg;i++) if(g[s][i]!=p) {dfs(g[s][i],s); v.push_back(g[s][i]);}
	sort(v.begin(),v.end(),cmp);
	int t=0;
	bool fas=false;
	for(int i=1;i<=deg;i++)
	{
		int a=0,b=0,c=0;
		while(t<v.size() && g[v[t]].size()<i) {if(!op[v[t]]) fas=true; t++;}
		if(fas)
		{
			for(int j=i;j<=deg;j++) dp[0][s][j]=dp[1][s][j]=false;
			break;
		}
		b=t;
		for(int j=t;j<v.size();j++)
		{
			bool gr=dp[0][v[j]][i],d=(op[v[j]] && k[v[j]]!=i);
			if(gr && d) c++;
			if(!gr && d) b++;
			if(gr && !d) a++;
		}
		if(a+b+c==v.size())
		{
			if(b+c>=i && a+c>=(int)v.size()-i) dp[0][s][i]=true;
			if(b+c>=i-1 && a+c>=(int)v.size()+1-i) dp[1][s][i]=true;
		}
	}
	for(int i=1;i<=deg;i++) if(dp[1][s][i])
	{
		if(op[s]) k[s]=-1;
		else {op[s]=true; k[s]=i;}
	}
}
void reconstruct(int s,int p,int x,int y)
{
	co[s]=x;
	vector<int> a,b,c,v;
	int deg=g[s].size();
	for(int i=0;i<deg;i++) if(g[s][i]!=p) v.push_back(g[s][i]);
	for(int j=0;j<v.size();j++)
	{
		bool gr=(x<dp[0][v[j]].size() && dp[0][v[j]][x]),d=(op[v[j]] && k[v[j]]!=x);
		if(gr && d) c.push_back(v[j]);
		if(!gr && d) b.push_back(v[j]);
		if(gr && !d) a.push_back(v[j]);
	}
	for(int i=0;i<a.size();i++) reconstruct(a[i],s,x,x);
	for(int i=0;i<b.size();i++)
	{
		int color;
		for(int j=1;j<=g[b[i]].size();j++) if(dp[1][b[i]][j] && j!=x) color=j;
		reconstruct(b[i],s,color,color-1);
		y--;
	}
	for(int i=0;i<c.size();i++)
	{
		if(!y) reconstruct(c[i],s,x,x);
		else
		{
			int color;
			for(int j=1;j<=g[c[i]].size();j++) if(dp[1][c[i]][j] && j!=x) color=j;
			reconstruct(c[i],s,color,color-1);
			y--;
		}
	 }
}
void Oboji(int N,int* U,int* V,int* C)
{
	for(int i=1;i<=N-1;i++) g[U[i]].push_back(V[i]);
	for(int i=1;i<=N-1;i++) g[V[i]].push_back(U[i]);
	for(int i=1;i<=N;i++) for(int j=0;j<g[i].size()+1;j++) dp[0][i].push_back(false);
	for(int i=1;i<=N;i++) for(int j=0;j<g[i].size()+1;j++) dp[1][i].push_back(false);
	dfs(1,1);
	for(int i=1;i<=g[1].size();i++) if(dp[0][1][i])
	{
		reconstruct(1,1,i,i);
		for(int i=1;i<=N;i++) C[i]=co[i];
		return;
	}
	for(int i=1;i<=N;i++) C[i]=-1;
}
