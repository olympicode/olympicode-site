#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int t;
int n,k;
vector<int> a[maxn];
int dp[maxn][maxn][3];
int gp[maxn][3];
int sz[maxn];
void dfs(int u,int pr=-1) {
    sz[u]=1;
    dp[u][0][0]=dp[u][0][1]=dp[u][0][2]=0;
    dp[u][1][0]=-1e9;
    dp[u][1][1]=0;
    dp[u][1][2]=0;
    for(auto v:a[u]) {
        if(v!=pr) {
            dfs(v,u);

            for(int i=sz[u]+1;i<=sz[u]+sz[v] && i<=k+1;i++) {
                dp[u][i][0]=dp[u][i][1]=dp[u][i][2]=0;
            }
            dp[u][sz[u]+sz[v]][0]=-1e9;
            for(int i=0;i<=sz[u]+sz[v] && i<=k+1;i++) {
                gp[i][0]=gp[i][1]=gp[i][2]=0;
            }
            gp[sz[u]+sz[v]][0]=-1e9;

            for(int i=0;i<=sz[u] && i<=k+1;i++) {
                for(int j=0;j<=sz[v] && i+j<=k+1;j++) {
                    gp[i+j][0]=max(gp[i+j][0],dp[u][i][0]+dp[v][j][2]);
                    if(i) {
                        gp[i+j][1]=max(gp[i+j][1],dp[u][i][1]+dp[v][j][2]);
                    }
                    if(j) {
                        gp[i+j][1]=max(gp[i+j][1],dp[u][i][0]+dp[v][j][1]+1);
                    }
                    if(i>0 && j>0) {
                        gp[i+j-1][2]=max(gp[i+j-1][2],dp[u][i][1]+dp[v][j][1]+1);
                    }
                    gp[i+j][2]=max(gp[i+j][2],dp[u][i][2]+dp[v][j][2]);
                }
            }

            for(int i=0;i<=sz[u]+sz[v] && i<=k+1;i++) {
                for(int j=0;j<=2;j++) {
                    dp[u][i][j]=max(dp[u][i][j],gp[i][j]);
                }
            }


            sz[u]+=sz[v];

        }
    }
    for(int i=0;i<=sz[u];i++) {
        dp[u][i][2]=max(dp[u][i][0],max(dp[u][i][1],dp[u][i][2]));
    }
    /*cout<<u<<" "<<sz[u]<<endl;
    for(int i=0;i<=sz[u];i++) {
        cout<<"dp["<<u<<"]["<<i<<"][0]="<<dp[u][i][0]<<", "<<"dp["<<u<<"]["<<i<<"][1]="<<dp[u][i][1]<<", "<<"dp["<<u<<"]["<<i<<"][2]="<<dp[u][i][2]<<", "<<endl;
    }*/
}
int main() {

    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        k=min(k+1,n);
        for(int i=0;i<n-1;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }

        dfs(1);

        int ans=0;
        for(int i=0;i<=k;i++) {
            for(int j=0;j<=2;j++) {
                ans=max(ans,dp[1][i][j]+max(i-1,0));
            }
        }

        printf("%d\n",ans);

        for(int i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}
