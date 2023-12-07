#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;
int n,m,dp[MAXN],dpl[MAXN],l[MAXN],r[MAXN],d[MAXN];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>l[i]>>r[i];
	for(int i=0;i<n;i++) d[i]=r[i]-l[i];
	fill(dpl,dpl+MAXN,1000000000);
	for(int i=1;i+d[0]<=m;i++) dpl[i]=abs(i-l[0]);
	for(int i=1;i<n;i++)
	{
		fill(dp,dp+MAXN,1000000000);
		for(int j=1;j+d[i]<=m;j++) for(int k=j;k>=max(0,j+d[i]-d[i-1]);k--) dp[j]=min(dp[j],dpl[k]+abs(j-l[i]));
		for(int j=1;j<=m;j++) dpl[j]=dp[j];
	}
	int res=100000000; for(int i=0;i<MAXN;i++) res=min(res,dp[i]);
	cout<<res;
}
