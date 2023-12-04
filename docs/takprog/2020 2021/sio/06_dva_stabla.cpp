#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=200050;
const int M=2*20*N;

int root[N],ls[M],rs[M],sum[M],tsz;
void Add(int p,int&c,int ss,int se,int qi,int x){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+x;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Add(ls[p],ls[c],ss,mid,qi,x);
	else Add(rs[p],rs[c],mid+1,se,qi,x);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}

vector<int> E[2][N];
int lid[N],rid[N],tid;
void Euler(int u,int p,int t){
	lid[u]=++tid;
	for(int v:E[t][u])if(v!=p)Euler(v,u,t);
	rid[u]=++tid;
}

void Build(int u,int p,int t){
	Add(root[p],root[u],1,tid,lid[u],1);
	Add(root[u],root[u],1,tid,rid[u],-1);
	for(int v:E[t][u])if(v!=p)Build(v,u,t);
}


const int L=20;
int par[2][N][L],dep[2][N];
void DFS(int u,int p,int t){
	par[t][u][0]=p;
	dep[t][u]=dep[t][p]+1;
	for(int i=1;i<L;i++){
		par[t][u][i]=par[t][par[t][u][i-1]][i-1];
	}
	for(int v:E[t][u])if(v!=p)DFS(v,u,t);
}
int LCA(int u,int v,int t){
	if(dep[t][u]<dep[t][v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[t][par[t][u][i]]>=dep[t][v])u=par[t][u][i];
	for(int i=L-1;~i;i--)if(par[t][u][i]!=par[t][v][i])u=par[t][u][i],v=par[t][v][i];
	return u==v?v:par[t][v][0];
}

int Get(int x,int y){
	if(x==0||y==0)return 0;
	return Get(root[x],1,tid,1,lid[y]);
}

int Get(int node,int C,int D,int lca){
	return Get(node,C)+Get(node,D)-Get(node,lca)-Get(node,par[1][lca][0]);
}

void Resi(int N, int Q, int P, int *U1, int *V1, int *U2, int *V2, int *A1, int *B1, int *C1, int *D1, int *R){
	for(int i=1;i<N;i++){
		E[0][U1[i]].pb(V1[i]);
		E[0][V1[i]].pb(U1[i]);

		E[1][U2[i]].pb(V2[i]);
		E[1][V2[i]].pb(U2[i]);
	}
	Euler(1,0,1);
	Build(1,0,0);
	DFS(1,0,0);
	DFS(1,0,1);
	int last_ans=0;
	for(int i=1;i<=Q;i++){
		int A=(A1[i]+last_ans*P-1)%N+1;
		int B=(B1[i]+last_ans*P-1)%N+1;
		int C=(C1[i]+last_ans*P-1)%N+1;
		int D=(D1[i]+last_ans*P-1)%N+1;
		int lca1=LCA(A,B,0);
		int lca2=LCA(C,D,1);
		R[i]=Get(A,C,D,lca2)+Get(B,C,D,lca2)-Get(lca1,C,D,lca2)-Get(par[0][lca1][0],C,D,lca2);
		last_ans=R[i];
	}
}
