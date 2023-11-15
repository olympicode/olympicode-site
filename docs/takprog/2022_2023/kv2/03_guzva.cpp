#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int n,m,q;
vector<vector<ll> > a,dp_top,dp_bot,pref,suf;
int main() {
    scanf("%d %d",&n,&m);
    a.resize(n+2);dp_top.resize(n+2);dp_bot.resize(n+2);pref.resize(n+2);suf.resize(n+2);
    for(int i=0;i<=n+1;i++) {
        a[i].resize(m+2);dp_top[i].resize(m+2);dp_bot[i].resize(m+2);pref[i].resize(m+2);suf[i].resize(m+2);
        for(int j=0;j<=m+1;j++) a[i][j]=dp_top[i][j]=dp_bot[i][j]=pref[i][j]=suf[i][j]=inf;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
    dp_top[1][1]=a[1][1]; dp_bot[n][m]=a[n][m];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp_top[i][j]=min(dp_top[i][j],min(dp_top[i-1][j],dp_top[i][j-1])+a[i][j]);
    for(int i=n;i>=1;i--) for(int j=m;j>=1;j--) dp_bot[i][j]=min(dp_bot[i][j],min(dp_bot[i+1][j],dp_bot[i][j+1])+a[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) pref[i][j]=min(pref[i-1][j+1],dp_top[i][j]+dp_bot[i][j]-a[i][j]);
    for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) suf[i][j]=min(suf[i+1][j-1],dp_top[i][j]+dp_bot[i][j]-a[i][j]);
    scanf("%d",&q);
    while(q--) {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%lld\n",min(pref[x-1][y+1],suf[x+1][y-1]));
    }
    return 0;
}
