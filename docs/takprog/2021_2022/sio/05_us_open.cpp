#include <bits/stdc++.h>
#define MAXN (1<<20)+7
using namespace std;
int a[MAXN],b[MAXN],dp[MAXN],aux[MAXN];
void rek(int l,int r)
{
    if(l==r) {dp[l]=0; return;}
    int s=(l+r)/2;
    rek(l,s); rek(s+1,r);
    int t1=l,t2=r;
    int mx=0,pmax=-500;
    for(int i=s+1;i<=r;i++) mx=max(mx,dp[i]);
    for(int i=s;i>=l;i--)
    {
        while(t2!=s && a[t2]>=a[i]) pmax=max(pmax,dp[t2--]);
        aux[i]=dp[i]+max(pmax+1,mx);
    }
    mx=0; pmax=-500;
    for(int i=l;i<=s;i++) mx=max(mx,dp[i]);
    for(int i=s+1;i<=r;i++)
    {
        while(t1!=s+1 && a[i]>=a[t1]) pmax=max(pmax,dp[t1++]);
        aux[i]=dp[i]+max(pmax+1,mx);
    }
    t1=l; t2=s+1;
    while(t1<=s || t2<=r)
    {
        if(t1==s+1) {b[t1+t2-s-1]=a[t2]; dp[t1+t2-s-1]=aux[t2]; t2++; continue;}
        if(t2==r+1) {b[t1+t2-s-1]=a[t1]; dp[t1+t2-s-1]=aux[t1]; t1++; continue;}
        if(a[t1]<a[t2]) {b[t1+t2-s-1]=a[t1]; dp[t1+t2-s-1]=aux[t1]; t1++; continue;}
        b[t1+t2-s-1]=a[t2]; dp[t1+t2-s-1]=aux[t2]; t2++;
    }
    for(int i=l;i<=r;i++) a[i]=b[i];
}
int Interesantnost(int N,int *A)
{
    int n=1<<N;
    for(int i=1;i<=n;i++) a[i]=A[i];
    rek(1,n);
    int res=0;
    for(int i=0;i<n;i++) res=max(res,dp[i]);
    return res;
}
