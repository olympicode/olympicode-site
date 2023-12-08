#include<bits/stdc++.h>
#define maxn 202
#define maxk 10005
using namespace std;
int n,m,k;
int s[maxn];
long long dp[maxn][maxk];
int a[maxn][maxn];
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d",&a[i][j]);
        }
        sort(a[i]+1,a[i]+(m+1));
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) dp[i][j]=dp[i-1][j];
        for(int l=0;l<=m;l++) {
            int c;
            if(l==0) c=0;
            else c=a[i][l]+1;
            for(int j=c;j<=k;j++) {
                dp[i][j]=max(dp[i][j],dp[i-1][j-c]+1ll*l*s[i]);
            }
        }
    }
    long long ans=dp[n][0];
    for(int j=1;j<=k;j++) ans=max(ans,dp[n][j]);
    printf("%lld",ans);
    return 0;
}
