#include<bits/stdc++.h>
#define maxn 501
#define maxl 9
using namespace std;
int n;
int a;
int s;
int m[maxn][maxn];
long long pref[maxn][maxn];
long long b[maxn][maxn];
long long sprs[maxn][maxn][maxl][maxl];
int gdeg[maxn];
inline long long sum(int u,int d,int l,int r) {
    return pref[d][r]-pref[d][l-1]-pref[u-1][r]+pref[u-1][l-1];
}
inline long long maxsum(int u,int d,int l,int r) {
    long long ans=-1e18;
    while(u<=d) {
        int c=l;
        while(c<=r) {
            ans=max(ans,sprs[u][c][gdeg[d-u+1]][gdeg[r-c+1]]);
            c=c+(1<<gdeg[r-c+1]);
        }
        u=u+(1<<gdeg[d-u+1]);
    }
    return ans;
}
int main() {
    scanf("%d %d",&n,&a);
    s=a/4;
    int j=0;
    for(int i=1;i<=n;i++) {
        if(1<<(j+1)<=i) j++;
        gdeg[i]=j;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&m[i][j]);
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+m[i][j];
        }
    }
    for(int i=1;i+s-1<=n;i++) {
        for(int j=1;j+s-1<=n;j++) {
            b[i][j]=-1e18;
            long long tot=sum(i,i+s-1,j,j+s-1);
            for(int k=1;k<s;k++) {
                long long k1=sum(i,i+k-1,j,j+k-1);
                long long k2=sum(i,i+k-1,j+s-k,j+s-1);
                long long k3=sum(i+s-k,i+s-1,j,j+k-1);
                long long k4=sum(i+s-k,i+s-1,j+s-k,j+s-1);
                long long k5=sum(i,i+k-1,j,j+(s-k)-1);
                long long k6=sum(i,i+k-1,j+k,j+s-1);
                long long k7=sum(i+s-k,i+s-1,j,j+s-k-1);
                long long k8=sum(i+s-k,i+s-1,j+k,j+s-1);
                b[i][j]=max(b[i][j],tot-k1);
                b[i][j]=max(b[i][j],tot-k2);
                b[i][j]=max(b[i][j],tot-k3);
                b[i][j]=max(b[i][j],tot-k4);
                b[i][j]=max(b[i][j],tot-k5);
                b[i][j]=max(b[i][j],tot-k6);
                b[i][j]=max(b[i][j],tot-k7);
                b[i][j]=max(b[i][j],tot-k8);
            }
            sprs[i][j][0][0]=b[i][j];
        }
    }
    for(int k=0;k<9;k++) {
        for(int l=0;l<9;l++) {
            if(k==0 && l==0)  continue;
            if(k==0) {
                for(int i=1;i+s-1<=n;i++) {
                    for(int j=1;j+(1<<l)-1+s-1<=n;j++) {
                        sprs[i][j][k][l]=max(sprs[i][j][k][l-1],sprs[i][j+(1<<(l-1))][k][l-1]);
                    }
                }
            }
            else {
                for(int i=1;i+(1<<k)-1+s-1<=n;i++) {
                    for(int j=1;j+(1<<l)-1+s-1<=n;j++) {
                        sprs[i][j][k][l]=max(sprs[i][j][k-1][l],sprs[i+(1<<(k-1))][j][k-1][l]);
                    }
                }
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--) {
        int u,d,l,r;
        scanf("%d %d %d %d",&u,&d,&l,&r);
        printf("%lld\n",maxsum(u,d-s+1,l,r-s+1));
    }
    return 0;
}
