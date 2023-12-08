#include<bits/stdc++.h>
#define maxn 200005
#define maxv 100000
using namespace std;
long long a[maxn];
int n,k;
long long pref[maxn];
long long suf[maxn];
int cnt[4*maxn];
int pref_cnt[4*maxn];
long long sum[4*maxn];
inline void clear_seg(int id,int l,int r) {
    sum[id]=0;
    cnt[id]=0;
    pref_cnt[id]=0;
    if(l==r) return;
    int m=(l+r)/2;
    clear_seg(id*2+1,l,m);
    clear_seg(id*2+2,m+1,r);
}
inline void update(int id,int l,int r,int pos,int c,int p,int s) {
    cnt[id]+=c;
    pref_cnt[id]+=p;
    sum[id]+=s;
    if(l==r) return;
    int m=(l+r)/2;
    if(pos<=m) update(id*2+1,l,m,pos,c,p,s);
    else update(id*2+2,m+1,r,pos,c,p,s);
}
inline pair<long long,pair<int,int>> pick(int id,int l,int r,int k,int ps,int ss) {
    if(k==0) return {0,{0,0}};
    if(k>=cnt[id] && ps>pref_cnt[id] && ss>cnt[id]-pref_cnt[id]) return {sum[id],{pref_cnt[id],cnt[id]}};
    if(l==r) {
        if(k>=cnt[id]) {
            if(ps==pref_cnt[id]) return {1ll*(l-maxv)*(cnt[id]-1),{pref_cnt[id]-1,cnt[id]-1}};
            else return {1ll*(l-maxv)*(cnt[id]-1),{pref_cnt[id],cnt[id]-1}};
        }
        else {
            return  {1ll*(l-maxv)*k,{k,k}};
        }
    }
    int m=(l+r)/2;
    pair<long long,pair<int,int> > p2=pick(id*2+2,m+1,r,k,ps,ss);
    pair<long long,pair<int,int> > p1=pick(id*2+1,l,m,k-p2.second.second,ps-p2.second.first,ss-p2.second.second+p2.second.first);
    return {p1.first+p2.first,{p1.second.first+p2.second.first,p1.second.second+p2.second.second}};
}
long long solve() {
    for(int i=1;i<=n;i++) {
        pref[i]=pref[i-1]+a[i];
    }
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+a[i];
    }
    long long ans=-1e18;
    clear_seg(0,0,maxn);
    update(0,0,maxn,-a[1]+maxv,1,1,-a[1]);
    for(int i=2;i<=n;i++) {
        update(0,0,maxn,a[i]+maxv,1,0,a[i]);
    }
    for(int i=1;i<=n-1;i++) {
        pair<long long,pair<int,int > > p=pick(0,0,maxn,n-k,i,n-i);
        ans=max(ans,pref[i]-suf[i+1]+p.first);
        update(0,0,maxn,a[i+1]+maxv,-1,0,-a[i+1]);
        update(0,0,maxn,-a[i+1]+maxv,1,1,-a[i+1]);
    }
    return ans;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    long long ans=solve();
    for(int i=1;i<=n;i++) {
        a[i]=-a[i];
    }
    ans=max(ans,solve());
    printf("%lld",ans);
    return 0;
}
