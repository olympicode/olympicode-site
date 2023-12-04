#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long x[MAXN],y[MAXN],px[MAXN],py[MAXN];
int main()
{
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++) px[i]=px[i-1]+x[i]*((i&1)?1:-1);
	for(int i=1;i<=n;i++) py[i]=py[i-1]+y[i]*((i&1)?1:-1);
	scanf("%d",&q);
	while(q--)
	{
		long long xt,yt;
		int l,r;
		scanf("%lld%lld%d%d",&xt,&yt,&l,&r);
		printf("%lld %lld\n",2*(px[r]-px[l-1])*((r&1)?1:-1)+xt*(((r-l)&1)?1:-1),2*(py[r]-py[l-1])*((r&1)?1:-1)+yt*(((r-l)&1)?1:-1));
	}
}
