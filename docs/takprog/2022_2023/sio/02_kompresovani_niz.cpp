#include <bits/stdc++.h>
#define maxn 400005
#define maxl 31
using namespace std;
int l;
long long dp[maxn];
long long prev_bit[maxl];
long long sprs[maxn][21];
int val[maxn];
int bit[2][maxl];
int pos[2][maxl];
pair<int,int> v[2][maxl];
inline long long query(int p,int q) {
    int k=val[q-p];
    return min(sprs[q][k],sprs[p+((1<<k)-1)*l][k]);
}
long long Resi(int N, int* A, int K)
{
    l=K-1;
    int c=0;
    for(int j=1;j*l<maxn;j++) {
        if(2*(1<<c)<=j) c++;
        val[j*l]=c;
    }
    for(int j=0;j<maxl;j++) bit[0][j]=bit[1][j]=j;
    int g=0;
    for(int i=1;i<=N;i++) {
        int c=0;
        for(int j=0;j<maxl;j++) {
            if(A[i]&(1<<bit[g][j])) {
                pos[g^1][c]=i;
                bit[g^1][c]=bit[g][j];
                c++;
            }
        }
        for(int j=0;j<maxl;j++) {
            if(!(A[i]&(1<<bit[g][j]))) {
                pos[g^1][c]=pos[g][j];
                bit[g^1][c]=bit[g][j];
                c++;
            }
        }
        g^=1;
        dp[i]=A[i]+dp[i-1];
        int o=0;
        c=(i-1);
        int fst=c-l*(c/l);
        for(int j=0;j<maxl;j++) {
            if(pos[g][j]==0) break;
            if(pos[g][j]==i) {
                o|=(1<<bit[g][j]);
                continue;
            }
            if(j!=0 && pos[g][j]==pos[g][j-1]) {
                o|=(1<<bit[g][j]);
                continue;
            }
            int rm=c%l;
            int start=c-l*((c-(pos[g][j]))/l);
            dp[i]=min(dp[i],query(start,c)+o);
            o|=(1<<bit[g][j]);
            if(query(fst,start)+o>dp[i]) break;
        }
        int rm=c%l;
        dp[i]=min(dp[i],query(fst,c)+o);
        sprs[i][0]=dp[i];
        for(int j=1;i-((1<<j)-1)*l>=0;j++) {
            sprs[i][j]=min(sprs[i][j-1],sprs[i-((1<<(j-1)))*l][j-1]);
        }
    }
    return dp[N];
}
