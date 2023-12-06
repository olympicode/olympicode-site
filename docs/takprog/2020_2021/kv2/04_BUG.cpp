#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long mod=1000000007;
inline long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
int lp[maxn];
long long seg[4*maxn];
inline void set_seg(int id,int l,int r) {
    seg[id]=1;
    if(l==r) return;
    int m=(l+r)/2;
    set_seg(id*2+1,l,m);
    set_seg(id*2+2,m+1,r);
}
int pos[maxn];
inline void update_seg(int id,int l,int r,int p) {
    if(l==r) {
        seg[id]=step(p,pos[p]);
        return;
    }
    int m=(l+r)/2;
    if(p<=m) update_seg(id*2+1,l,m,p);
    else update_seg(id*2+2,m+1,r,p);
    seg[id]=(1ll*seg[id*2+1]*seg[id*2+2]);
    if(seg[id]>=mod) seg[id]%=mod;
}
long long a[maxn];
long long val[maxn];
int n,k;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    set_seg(0,0,maxn-1);
    for(int i=2;i<maxn;i++) {
        if(!lp[i]) {
            lp[i]=i;
            for(long long j=1ll*i*i;j<maxn;j+=i) {
                if(!lp[j] || lp[j]>i) lp[j]=i;
            }
        }
    }
    int nf=0;
    val[0]=1;
    for(int i=1;i<n;i++) {
        int x=k+i;
        int y=i;
        while(x>1) {
            int p=lp[x];
            int c=0;
            while(lp[x]==p) {
                c++;
                x=x/lp[x];
            }
            pos[p]+=c;
            update_seg(0,0,maxn-1,p);
        }
        while(y>1) {
            int p=lp[y];
            int c=0;
            while(lp[y]==p) {
                c++;
                y=y/lp[y];
            }
            pos[p]-=c;
            update_seg(0,0,maxn-1,p);
        }
        val[i]=seg[0];
    }
    long long ans=0;
    for(int i=0;i<n;i++) {
        ans=(ans+((((a[i]*val[i])%mod)*val[n-1-i])%mod))%mod;
    }
    printf("%lld",ans);
    return 0;
}
