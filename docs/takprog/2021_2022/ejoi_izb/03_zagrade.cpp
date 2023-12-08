#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
string s;
pair<int,int> seg[4*MAXN];
int bag[4*MAXN],cnt=0;
void relax(int ind)
{
    bag[2*ind]+=bag[ind];
    bag[2*ind+1]+=bag[ind];
    seg[ind]=min(make_pair(seg[2*ind].first+bag[2*ind],seg[2*ind].second),make_pair(seg[2*ind+1].first+bag[2*ind+1],seg[2*ind+1].second));
    bag[ind]=0;
}
void upd(int val,int l,int r,int lt,int rt,int ind)
{
    if(l>rt || r<lt) return;
    if(l>=lt && r<=rt) {bag[ind]+=val; return;}
    relax(ind);
    int s=(l+r)/2;
    upd(val,l,s,lt,rt,2*ind);
    upd(val,s+1,r,lt,rt,2*ind+1);
    seg[ind]=min(make_pair(seg[2*ind].first+bag[2*ind],seg[2*ind].second),make_pair(seg[2*ind+1].first+bag[2*ind+1],seg[2*ind+1].second));
}
void make(int l,int r,int ind)
{
    if(l==r) {seg[ind].second=l; return;}
    int s=(l+r)/2;
    make(l,s,2*ind);
    make(s+1,r,2*ind+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,q;
    string s;
    cin>>n>>q;
    cin>>s;
    make(0,n,1);
    for(int i=0;i<n;i++) {upd(((s[i]=='(')?1:-1),0,n,i+1,n,1); cnt+=((s[i]=='(')?1:-1);}
    if(cnt!=0) printf("-1\n");
    else printf("%d\n",seg[1].second);
    while(q--)
    {
        int t;
        cin>>t; t--;
        upd(((s[t]=='(')?-2:2),0,n,t+1,n,1); cnt+=((s[t]=='(')?-2:2);
        s[t]^=1;
        if(cnt!=0) printf("-1\n");
        else printf("%d\n",seg[1].second);
    }
}
