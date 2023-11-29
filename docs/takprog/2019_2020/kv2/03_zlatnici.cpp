#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long x[MAXN],y[MAXN];
int main()
{
	int n;
	long long res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for(int i=1;i<=n;i++) res+=abs(x[i]-i);
	for(int i=1;i<=n;i++) res+=abs(y[i]-i);
	printf("%lld",res);
}
