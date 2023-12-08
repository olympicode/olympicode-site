#include <bits/stdc++.h>
using namespace std;
int a[1500][1500],stn[1000007],stm[1000007];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    stn[0]=stm[0]=1;
    for(int i=1;i<1000007;i++) stn[i]=(stn[i-1]*2)%n;
    for(int i=1;i<1000007;i++) stm[i]=(stm[i-1]*2)%m;
    while(q--)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k); x--; y--;
        printf("%d\n",a[(x+stn[k])%n][y]^a[(x+n-stn[k])%n][y]^a[x][(y+stm[k])%m]^a[x][(y+m-stm[k])%m]);
    }
}
