#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
vector<pair<int,char>> E[N];
bool was[N];
int sz[N];
void DFS(int u,int p){sz[u]=1;for(auto e:E[u])if(e.first!=p&&!was[e.first])DFS(e.first,u),sz[u]+=sz[e.first];}
int Find(int u,int p,int n){for(auto e:E[u])if(e.first!=p&&!was[e.first]&&sz[e.first]*2>n)return Find(e.first,u,n);return u;}
int FindCentroid(int u){DFS(u,u);return Find(u,u,sz[u]);}
vector<pair<int,int>> push;
map<pair<int,int>,int> cnt;
ll ans=0;
void Solve(int u,int p,int S,int I,int O){
	push.pb({S-I,S-O});
	ans+=cnt[{I-S,O-S}];
	for(auto e:E[u])if(e.first!=p&&!was[e.first]){
		Solve(e.first,u,S+(e.second=='S'),I+(e.second=='I'),O+(e.second=='O'));
	}
}
void Decompose(int u){
	u=FindCentroid(u);
	was[u]=1;
	cnt.clear();
	cnt[{0,0}]++;
	for(auto e:E[u])if(!was[e.first]){
		Solve(e.first,u,e.second=='S',e.second=='I',e.second=='O');
		for(auto p:push)cnt[p]++;
		push.clear();
	}
	for(auto e:E[u])if(!was[e.first]){
		Decompose(e.first);
	}
}
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<n;i++){
		int u,v;char c;
		scanf("%i %i %c",&u,&v,&c);
		E[u].pb({v,c});
		E[v].pb({u,c});
	}
	Decompose(1);
	printf("%lld\n",ans);
	return 0;
}
