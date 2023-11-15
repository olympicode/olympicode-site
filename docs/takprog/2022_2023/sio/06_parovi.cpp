#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pb push_back
#define si(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int N = 200000;

struct DSU{
    int n;
    int par[N+5], sz[N+5];
    void init(int _n){
        n = _n;
        for(int i=1; i<=n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int root(int x){
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    void unite(int u, int v){
        u = root(u), v = root(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = par[u];
    }
} dsu;

int n, m;

vector <int> gc[N+5];
vector <int> gn[N+5];
pair <int, int> e[N+5];

int shares[N+5];
bool has_edge[N+5];
int ima_c[N+5], ima_n[N+5];
bool bitan[N+5];

ll solve(int l, int r){
    vector <int> nodes, comps;
    for(int i=l; i<=r; i++){
        int u = e[i].fi, v = e[i].se;
        int u1 = dsu.root(u), v1 = dsu.root(v);
        if(u1 == v1) continue;
        nodes.pb(u);
        nodes.pb(v);
        comps.pb(u1);
        comps.pb(v1);
        gc[u].pb(v1);
        gc[v].pb(u1);
        gn[u1].pb(v);
        gn[v1].pb(u);
    }
    sort(all(nodes));
    sort(all(comps));
    nodes.erase(unique(all(nodes)), nodes.end());
    comps.erase(unique(all(comps)), comps.end());
    for(auto u : nodes){
        bitan[u] = 1;
        sort(all(gc[u]));
        gc[u].erase(unique(all(gc[u])), gc[u].end());
    }
    for(auto cm : comps){
        sort(all(gn[cm]));
        gn[cm].erase(unique(all(gn[cm])), gn[cm].end());
    }
    ll res = 0;
    for(int i=0; i<si(nodes); i++){
        int u = nodes[i];
        for(auto cm : gc[u]){
            ima_c[cm] = 1;
            for(auto c : gn[cm]) shares[c]++;
        }
        for(auto c : gn[dsu.root(u)]){
            ima_n[c] = 1;
        }
        res += 1LL*(n - si(nodes))*si(gc[u]);
        for(int j=l; j<=r; j++){
            if(e[j].fi == u && bitan[e[j].se]) has_edge[e[j].se] = 1;
            if(e[j].se == u && bitan[e[j].fi]) has_edge[e[j].fi] = 1;
        }
        for(int j=i+1; j<si(nodes); j++){
            int v = nodes[j];
            res += si(gc[u]) + si(gc[v]) - shares[v];
            if(has_edge[v] || dsu.root(u) == dsu.root(v)){
                continue;
            }
            res -= ima_n[v] + ima_c[dsu.root(v)];
            if(ima_n[v] || ima_c[dsu.root(v)] || shares[v]) res++;
        }
        for(auto c : nodes){
            shares[c] = 0;
            has_edge[c] = 0;
            ima_n[c] = 0;
        }
        for(auto c : comps){
            ima_c[c] = 0;
        }
    }
    for(auto c : nodes){
        bitan[c] = 0;
        gc[c].clear();
    }
    for(auto c : comps) gn[c].clear();
    for(int i=l; i<=r; i++){
        dsu.unite(e[i].fi, e[i].se);
    }
    return res;
}

long long Resi(int _n, int _m, int _k, int *U, int *V){
    int k;
    n = _n, m = _m, k = _k;
    for(int i=1; i<=m; i++){
        e[i].fi = U[i], e[i].se = V[i];
    }
    dsu.init(n);
    ll res = 0;
    for(int i=1; i<=m; i+=k){
        res += solve(i, min(m, i + k - 1));
    }
    return res;
}