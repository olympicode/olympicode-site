#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int t;
int n;
vector<int> a[maxn];
bool vis[maxn];
const int mod=998244353;
int dfs(int u) {
    int ret=2;
    vis[u]=true;
    for(auto v:a[u]) {
        ret--;
        if(!vis[v]) ret+=dfs(v);
    }
    return ret;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int ans=1;
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                if(dfs(i)==0) {
                    ans=ans*2;
                    if(ans>=mod) ans-=mod;
                }
                else ans=0;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) {
            a[i].clear();
            vis[i]=false;
        }
    }
    return 0;
}
