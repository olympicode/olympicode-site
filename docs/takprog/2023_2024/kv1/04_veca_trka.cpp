#include <bits/stdc++.h>
#define MAXN 150007
using namespace std;
int bit[MAXN],N;
double a[MAXN];
long long x[MAXN],v[MAXN],K;
void upd(int x)
{
    while(x<=N)
    {
        bit[x]++;
        x+=(x&-x);
    }
}
long long sum(int x)
{
    long long sum=0;
    while(x)
    {
        sum+=bit[x];
        x-=(x&-x);
    }
    return sum;
}
bool provera(double s)
{
    vector<pair<double,int>> vec;
    for(int i=1;i<=N;i++) vec.push_back({x[i]+s*v[i],i});
    sort(vec.begin(),vec.end());
    fill(bit,bit+N+1,0);
    long long invcnt=0;
    for(int i=0;i<N;i++)
    {
        invcnt+=i-sum(vec[i].second);
        upd(vec[i].second);
    }
    return invcnt>=K;
}
int main()
{
    scanf("%d%lld",&N,&K);
    for(int i=1;i<=N;i++) scanf("%lld%lld",&x[i],&v[i]);
    double l=0,r=1000000000;
    while(r-l>5e-10)
    {
        double s=0.5*(l+r);
        if(provera(s)) r=s;
        else l=s;
    }
    printf("%.9f",0.5*(l+r));
}
