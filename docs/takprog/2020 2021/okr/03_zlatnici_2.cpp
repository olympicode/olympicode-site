#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long a[MAXN],pr[MAXN],su[MAXN];
long long formula(long long x,long long k)
{
	return x*k+(k*(k-1))/2;
}
int binarna(int l,int r,long long x)
{
	if(l==r) return l;
	int s=(l+r+1)/2;
	if(a[s]-s<x) return binarna(s,r,x);
	return binarna(l,s-1,x);
}
int main()
{	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	pr[0]=a[0];
	for(int i=1;i<n;i++) pr[i]=pr[i-1]+a[i];
	su[n]=0;
	for(int i=n-1;i>=0;i--) su[i]=su[i+1]+a[i];
	scanf("%d",&q);
	while(q--)
	{
		long long x;
		scanf("%lld",&x);
		if(a[0]>=x) {printf("%lld\n", pr[n-1]-formula(x,n)); continue;}
		int t=binarna(0,n-1,x);
		printf("%lld\n",(formula(x,t+1)-pr[t])+(su[t+1]-formula(x+t+1,n-t-1)));
	}
}
