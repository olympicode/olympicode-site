#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
struct edge
{
    int u, v, w;
};

int n, m;
edge edges[maxn];
vector<int> graph[maxn];
bool vis[maxn];


void clear()
{

    for(int u = 1; u <= n; u++) {

        graph[u].clear();
        vis[u] = false;

    }

}

void construct_graph(int max_w)
{

    for(int i = 1; i <= m; i++) {

        if( (max_w & edges[i].w) == edges[i].w) {

            graph[edges[i].u].push_back(edges[i].v);
            graph[edges[i].v].push_back(edges[i].u);

        }

    }

}

int dfs_tree_size(int u)
{

    vis[u] = true;
    int ret = 1;

    for(int v : graph[u]) {

        if(!vis[v]) {

            ret += dfs_tree_size(v);

        }

    }

    return ret;

}

int main()
{

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++) {

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = {u, v, w};

    }

    int ans = 0;
    int bit = (1 << 30);

    while(bit > 0) {

        clear();
        construct_graph(ans | (bit - 1) );

        if(dfs_tree_size(1) != n) {

            ans |= bit;

        }

        bit >>= 1;

    }

    printf("%d", ans);
    return 0;

}
