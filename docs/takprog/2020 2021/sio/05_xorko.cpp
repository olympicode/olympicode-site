#include <bits/stdc++.h>
#define MAXN 150007
using namespace std;
int lc[MAXN*62],rc[MAXN*62],cnt[MAXN*62],br;
long long p[MAXN];
void ubaci(long long a,int x,int node)
{
    cnt[node]++;
    if(x==-1) return;
    if(a&(1LL<<x))
    {
        if(lc[node]==-1) lc[node]=++br;
        ubaci(a,x-1,lc[node]);
    }
    else
    {
        if(rc[node]==-1) rc[node]=++br;
        ubaci(a,x-1,rc[node]);
    }
}
long long findmax(long long a,int x,int node)
{
    cnt[node]--;
    if(x==-1) return 0;
    long long sol=0;
    if((!(a&(1LL<<x)) && lc[node]!=-1) || rc[node]==-1)
    {
        sol=findmax(a,x-1,lc[node]);
        if(!cnt[lc[node]]) lc[node]=-1;
        sol+=(1LL<<x);
    }
    else
    {
        sol=findmax(a,x-1,rc[node]);
        if(!cnt[rc[node]]) rc[node]=-1;
    }
    return sol;
}
void LexMax(int N, long long* A,long long *B)
{
    fill(lc,lc+MAXN*62,-1);
    fill(rc,rc+MAXN*62,-1);
    for(int i=1;i<=N;i++) p[i]=p[i-1]^A[i];
    for(int i=1;i<N;i++) ubaci(p[i],59,0);
    long long last=0;
    for(int i=1;i<N;i++)
    {
        long long t=findmax(last,59,0);
        B[i]=last^t;
        last=t;
    }
    B[N]=last^p[N];
}
