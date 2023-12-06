#include <bits/stdc++.h>
#define maxN 2000005

using namespace std;

long long a[maxN],p[maxN],d[maxN],ans[maxN],n,i,j;
vector<int> adj[maxN];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=1;i<n;i++){
        cin>>p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }
    for(i=n-1;i>=0;i--){
        d[i]=a[i];
        for(j=0;j<adj[i].size();j++){
            d[i]+=d[adj[i][j]];
        }
    }
    ans[0]=d[0];
    for(i=1;i<n;i++) ans[i]=ans[p[i]]+d[i];
    if(ans[0]!=0) cout<<-1<<endl;
    else{
        for(i=0;i<n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}
