#include <bits/stdc++.h>
#define MAXN 1507
using namespace std;
int a[MAXN][MAXN],cnt[2*MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    long long ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int x=0;x<30;x++)
    {
        for(int i=0;i<m+n-1;i++) cnt[i]=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]&(1<<x)) cnt[i+j]^=1;
        int br=0;
        for(int i=0;i<n+m-1;i++) if(cnt[i]==1) br++;
        ans+=(1LL<<x)*min(br,n+m-1-br);
    }
    cout<<ans;
}
