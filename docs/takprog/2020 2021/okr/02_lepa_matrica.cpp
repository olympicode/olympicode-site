#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
long long a[maxn][maxn];
long long r[maxn];
long long c[maxn];
int main() {
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            r[i]=r[i]+abs(a[(i+1)%n][j]-a[i][j]);
            c[j]=c[j]+abs(a[i][(j+1)%m]-a[i][j]);
            ans=ans+abs(a[i][(j+1)%m]-a[i][j]);
            ans=ans+abs(a[(i+1)%n][j]-a[i][j]);
        }
    }
    long long mv=r[0];
    for(int i=0;i<n;i++) mv=min(mv,r[i]);
    ans-=mv;
    mv=c[0];
    for(int i=0;i<m;i++) mv=min(mv,c[i]);
    ans-=mv;
    printf("%lld",ans);
    return 0;
}
