#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,q;
int col[4*maxn];
int c[maxn];
int par[maxn];
int lb[maxn];
int rb[maxn];
vector<int> a[maxn];
int ord[maxn];
int pos[maxn];
int seg[4*maxn];
int laz[4*maxn];
int cv=1;
void dfs(int u,int p) {
    pos[u]=cv;
    ord[cv]=u;
    lb[u]=rb[u]=cv;
    cv++;
    for(int v:a[u]) {
        if(v!=p) {
            par[v]=u;
            dfs(v,u);
            lb[u]=min(lb[u],lb[v]);
            rb[u]=max(rb[u],rb[v]);
        }
    }
}
void propagate_color(int id,int l,int r) {
    if(col[id]!=0 && l!=r) {
        col[id*2+1]=col[id*2+2]=col[id];
        col[id]=0;
    }
}
int get_color(int id,int l,int r,int x) {
    propagate_color(id,l,r);
    if(l==r) return col[id];
    int m=(l+r)/2;
    if(x<=m) return get_color(id*2+1,l,m,x);
    else return get_color(id*2+2,m+1,r,x);
}
void set_color(int id,int l,int r,int x,int y,int v) {
    propagate_color(id,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y) {
        col[id]=v;
        propagate_color(id,l,r);
        return;
    }
    int m=(l+r)/2;
    set_color(id*2+1,l,m,x,y,v);
    set_color(id*2+2,m+1,r,x,y,v);
}
void propagate_val(int id,int l,int r) {
    if(laz[id]==-1) return;
    if(l!=r) {
        laz[id*2+1]=laz[id*2+2]=laz[id];
    }
    seg[id]=laz[id]*(r-l+1);
    laz[id]=-1;
}
void set_val(int id,int l,int r,int x,int y,int v) {
    propagate_val(id,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y) {
        laz[id]=v;
        propagate_val(id,l,r);
        return;
    }
    int m=(l+r)/2;
    set_val(id*2+1,l,m,x,y,v);
    set_val(id*2+2,m+1,r,x,y,v);
    seg[id]=seg[id*2+1]+seg[id*2+2];
}
void init_seg(int id,int l,int r) {
    laz[id]=-1;
    if(l==r) {
        col[id]=c[ord[l]];
        if(ord[l]!=1) {
            //cout<<l<<" "<<ord[l]<<" "<<c[par[ord[l]]]<<" "<<c[ord[l]]<<endl;
            if(c[par[ord[l]]]!=c[ord[l]]) seg[id]=1;
        }
        return;
    }
    int m=(l+r)/2;
    init_seg(id*2+1,l,m);
    init_seg(id*2+2,m+1,r);
    seg[id]=seg[id*2+1]+seg[id*2+2];
}
int main() {
    scanf("%d %d",&n,&q);
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int u=1;u<=n;u++) {
        scanf("%d",&c[u]);
    }
    dfs(1,-1);
    init_seg(0,1,n);
    while(q--) {
        int u,c;
        scanf("%d %d",&u,&c);
        set_color(0,1,n,lb[u],rb[u],c);
        set_val(0,1,n,lb[u],rb[u],0);
        if(u!=1) {
            int v=par[u];
            if(get_color(0,1,n,pos[u])!=get_color(0,1,n,pos[v])) {
                set_val(0,1,n,pos[u],pos[u],1);
            }
        }
        printf("%d\n",seg[0]+1);
    }
    return 0;
}
