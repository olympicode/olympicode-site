#include <bits/stdc++.h>
#define MAXN 80007
#define MAXL 17
using namespace std;
int d[MAXN],p[MAXL][MAXN],t,in[MAXN],out[MAXN],n,per[MAXN];
vector<int> g[MAXN];
void dfs(int s,int f,int dub)
{
    d[s]=dub;
    p[0][s]=f;
    in[s]=t++;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s,dub+1);
    out[s]=t++;
}
void lcainit()
{
    dfs(1,1,0);
    for(int j=1;j<MAXL;j++) for(int i=1;i<=n;i++) p[j][i]=p[j-1][p[j-1][i]];
}
bool insub(int u,int v) {return in[u]<=in[v] && out[u]>=out[v];}
int lca(int u,int v)
{
    if(insub(u,v)) return u;
    if(insub(v,u)) return v;
    for(int i=MAXL-1;i>=0;i--) if(!insub(p[i][u],v)) u=p[i][u];
    return p[0][u];
}
int dist(int u,int v) {return d[u]+d[v]-2*d[lca(u,v)];}
pair<int,int> mojmax(pair<int,int> a, pair<int,int> b)
{
    if(dist(a.first,a.second)<dist(b.first,b.second)) return b;
    return a;
}
pair<int,int> sga(int a,int b,int c,int d)
{
    if(a==-1) return {c,d};
    if(c==-1) return {a,b};
    pair<int,int> res={a,b};
    res=mojmax(res,{a,c});
    res=mojmax(res,{a,d});
    res=mojmax(res,{b,c});
    res=mojmax(res,{b,d});
    res=mojmax(res,{c,d});
    return res;
}
pair<int,int> seg[4*MAXN];
void upd(int l,int r,int v,int w,int ind)
{
    if(l==r) {seg[ind]={v,v}; return;}
    int s=(l+r)/2;
    if(w<=s) upd(l,s,v,w,2*ind);
    else upd(s+1,r,v,w,2*ind+1);
    pair<int,int> lv=seg[2*ind],ds=seg[2*ind+1];
    seg[ind]=sga(lv.first,lv.second,ds.first,ds.second);
}
pair<int,int> mp(int l,int r,int lt,int rt,int ind)
{
    if(l>=lt && r<=rt) return seg[ind];
    if(r<lt || l>rt) return {-1,-1};
    int s=(l+r)/2;
    pair<int,int> lv=mp(l,s,lt,rt,2*ind),ds=mp(s+1,r,lt,rt,2*ind+1);
    return sga(lv.first,lv.second,ds.first,ds.second);
}
int main()
{
    int q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&per[i]);
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    lcainit();
    for(int i=1;i<=n;i++) upd(1,n,per[i],i,1);
    scanf("%d",&q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            swap(per[x],per[y]);
            upd(1,n,per[x],x,1);
            upd(1,n,per[y],y,1);
        }
        else
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            pair<int,int> p=mp(1,n,l,r,1);
            printf("%d\n",max(dist(x,p.first),dist(x,p.second)));
        }
    }
}
