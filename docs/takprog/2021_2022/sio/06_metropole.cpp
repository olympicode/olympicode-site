#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
vector<int> g[3*MAXN], ind[MAXN],c[2],ge[MAXN];
int p[MAXN], a[MAXN], d[MAXN], u[MAXN], v[MAXN], b[MAXN];
bool vi[MAXN], uc[MAXN], ve[MAXN];
void dfs(int s,int f,int du)
{
    d[s]=du;
    p[s]=f;
    b[s]=du&1;
    vi[s]=true;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f)
    {
        int v=g[s][i];
        if(vi[v])
        {
            if(d[v]>d[s]) continue;
            uc[ind[s][i]]=true;
            uc[a[s]]=true;
            ge[ind[s][i]].push_back(a[s]);
            ge[a[s]].push_back(ind[s][i]);
            uc[a[p[s]]]=true;
            ge[a[s]].push_back(a[p[s]]);
            ge[a[p[s]]].push_back(a[s]);
            uc[a[p[p[s]]]]=true;
            ge[a[p[s]]].push_back(a[p[p[s]]]);
            ge[a[p[p[s]]]].push_back(a[p[s]]);
        }
        else {a[v]=ind[s][i]; dfs(v,s,du+1);}
    }
}
void dfsd(int s,int f,int du)
{
    d[s]=du;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfsd(g[s][i],s,du+1);
}
void dfsblok(int s)
{
    ve[s]=true;
    if(!vi[u[s]]) {c[b[u[s]]].push_back(u[s]); vi[u[s]]=true;}
    if(!vi[v[s]]) {c[b[v[s]]].push_back(v[s]); vi[v[s]]=true;}
    for(int i=0;i<ge[s].size();i++) if(!ve[ge[s][i]]) dfsblok(ge[s][i]);
}
int NajduziPut(int N, int M, int* U, int* V)
{
    for(int i=1;i<=M;i++) {u[i]=U[i]; v[i]=V[i];}
    for(int i=1;i<=M;i++) g[U[i]].push_back(V[i]);
    for(int i=1;i<=M;i++) ind[U[i]].push_back(i);
    for(int i=1;i<=M;i++) g[V[i]].push_back(U[i]);
    for(int i=1;i<=M;i++) ind[V[i]].push_back(i);
    dfs(1,1,0);
    for(int i=1;i<=N;i++) g[i].clear();
    for(int i=1;i<=M;i++)
    {
        if(!uc[i])
        {
            g[U[i]].push_back(V[i]);
            g[V[i]].push_back(U[i]);
        }
    }
    fill(vi+1,vi+N+1,false);
    for(int i=1;i<=M;i++) if(!ve[i] && uc[i])
    {
        dfsblok(i);
        if(c[0].size()>c[1].size()) swap(c[0],c[1]);
        if(c[1].size()==2)
        {
            N++;
            g[N].push_back(c[0][0]); g[N].push_back(c[0][1]);
            g[c[0][0]].push_back(N); g[c[0][1]].push_back(N);
            N++;
            g[N].push_back(c[1][0]); g[N].push_back(c[1][1]);
            g[c[1][0]].push_back(N); g[c[1][1]].push_back(N);
            g[N-1].push_back(N); g[N].push_back(N-1);
        }
        else
        {
            N++;
            g[N].push_back(c[0][0]); g[N].push_back(c[0][1]);
            g[c[0][0]].push_back(N); g[c[0][1]].push_back(N);
            int x = N;
            for(int i=0;i<c[1].size();i++)
            {
                N++;
                g[c[1][i]].push_back(N);
                g[N].push_back(x);
                g[N].push_back(c[1][i]);
                g[x].push_back(N);
            }
        }
        for(int i=0;i<2;i++) for(int j=0;j<c[i].size();j++) vi[c[i][j]]=false;
        c[0].clear(); c[1].clear();
    }
    dfsd(1,1,0);
    int mx=0,mxi;
    for(int i=1;i<=N;i++) if(d[i]>mx) {mx=d[i]; mxi=i;}
    dfsd(mxi,mxi,0);
    for(int i=1;i<=N;i++) if(d[i]>mx) mx=d[i];
    return mx;
}
