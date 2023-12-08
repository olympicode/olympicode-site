#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,t;
int a[maxn];
int b[maxn];
set<pair<int,int> > s;
vector<int> ad[maxn];
int bt[maxn];
void upd(int i) {
    while(i<=m) {
        bt[i]++;
        i+=(i&(-i));
    }
}
int que(int i) {
    int ret=0;
    while(i>0) {
        ret+=bt[i];
        i-=(i&(-i));
    }
    return ret;
}
int main() {
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++) {
        if(a[i]!=m) s.insert({i,a[i]});
    }
    for(int i=0;i<m;i++) {
        if(b[i]!=n) s.insert({b[i],i});
    }
    long long mn=s.size();
    for(int i=0;i<m;i++) {
        ad[b[i]].push_back(i);
    }
    long long mx=0;
    for(int i=0;i<n;i++) {
        for(auto j:ad[i]) {
            upd(m-j);
        }
        mx+=que(m-a[i]);
    }
    if(t==0) printf("%lld\n",mn);
    if(t==1) printf("%lld\n",mx);
    return 0;
}
