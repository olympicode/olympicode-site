#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
int mul(int x,int y){return (ll)x*y%mod;}

const int N=1000050;
ll dp[N];
int cnt[N],dv[N],a[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			dv[i]+=cnt[j];
		}
	}
	int ans=0;
	for(int i=N-1;i>=1;i--){
		dp[i]=(ll)dv[i]*(dv[i]-1)/2;
		for(int j=i*2;j<N;j+=i){
			dp[i]-=dp[j];
		}
		ans=add(ans,mul(dp[i]%mod,i));
	}
	ans=mul(ans,2);
	for(int i=1;i<=n-1;i++)ans=mul(ans,i);
	printf("%i\n",ans);
	return 0;
}
