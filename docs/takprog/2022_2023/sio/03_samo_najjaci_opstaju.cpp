#include <bits/stdc++.h>
#define MAXN 500007
#define MAXL 20
#define MOD 1000000007
using namespace std;
int a[MAXN],lg[MAXN],rg[MAXN],l[MAXN],r[MAXN],in[MAXN],out[MAXN],p[MAXL][MAXN],t;
long long dp[MAXN],mul[2][MAXL][MAXN],pls[2][MAXL][MAXN];
void dfs(int s)
{
    in[s]=t++;
    if(l[s]) dfs(l[s]);
    if(r[s]) dfs(r[s]);
    if(l[s] || r[s]) dp[s]=(dp[l[s]]*dp[r[s]]+1)%MOD;
    else dp[s]=2;
    out[s]=t++;
}
bool insub(int u,int v) {return in[u]>=in[v] && out[u]<=out[v];}
int LCA(int u,int v)
{
    if(insub(v,u)) return u;
    if(insub(u,v)) return v;
    for(int j=MAXL-1;j>=0;j--) if(!insub(v,p[j][u])) u=p[j][u];
    return p[0][u];
}
void Init(int N, int* A)
{
    a[0]=N+2;
    a[N+1]=N+1;
    stack<int> st; st.push(0);
    for(int i=1;i<=N;i++) a[i]=A[i];
    for(int i=1;i<=N;i++)
    {
        while(a[st.top()]<a[i]) st.pop();
        lg[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(N+1);
    for(int i=N;i>=1;i--)
    {
        while(a[st.top()]<a[i]) st.pop();
        rg[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=N;i++) l[i]=r[i]=0;
    for(int i=1;i<=N;i++)
    {
        if(a[lg[i]]<a[rg[i]])
        {
            p[0][i]=lg[i];
            r[lg[i]]=i;
        }
        else
        {
            p[0][i]=rg[i];
            l[rg[i]]=i;
        }
    }
    dp[0]=1;
    dfs(N+1);
    p[0][N+1]=N+1;
    for(int i=1;i<=N;i++)
    {
        if(A[i]==N) continue;
        if(a[lg[i]]<a[rg[i]])
        {
            mul[0][0][i]=1;
            pls[0][0][i]=0;
            mul[1][0][i]=dp[l[p[0][i]]];
            pls[1][0][i]=1;
        }
        else
        {
            mul[0][0][i]=dp[r[p[0][i]]];
            pls[0][0][i]=1;
            mul[1][0][i]=1;
            pls[1][0][i]=0;
        }
    }
    for(int j=1;j<MAXL;j++) for(int i=1;i<=N+1;i++)
    {
        p[j][i]=p[j-1][p[j-1][i]];
        for(int k=0;k<2;k++)
        {
            mul[k][j][i]=(mul[k][j-1][i]*mul[k][j-1][p[j-1][i]])%MOD;
            pls[k][j][i]=(mul[k][j-1][p[j-1][i]]*pls[k][j-1][i]+pls[k][j-1][p[j-1][i]])%MOD;
        }
    }
}
int Query(int L,int R)
{
    int w=LCA(L,R);
    long long pl=0,ml=dp[r[L]]+1,pd=0,md=dp[l[R]]+1;
    if(L==w) ml=1;
    else
    {
        for(int j=MAXL-1;j>=0;j--) if(!insub(w,p[j][L]))
        {
            ml=(ml*mul[0][j][L])%MOD;
            pl=(pl*mul[0][j][L]+pls[0][j][L])%MOD;
            L=p[j][L];
        }
    }
    if(R==w) md=1;
    else
    {
        for(int j=MAXL-1;j>=0;j--) if(!insub(w,p[j][R]))
        {
            md=(md*mul[1][j][R])%MOD;
            pd=(pd*mul[1][j][R]+pls[1][j][R])%MOD;
            R=p[j][R];
        }
    }
    return ((ml+pl)*(md+pd)+1)%MOD;
}
