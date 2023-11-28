/*
 Author: Petar 'PetarV' Velickovic
 Task: Tiho Brdo
*/

#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_N 1000005

using namespace std;
typedef long long lld;

int n;

struct node
{
    int par; int w_par;
    vector<int> adj;
};
node tree[MAX_N];

lld dp[MAX_N];

inline void compute_dp()
{
    queue<int> bfs_q;
    for (int i=1;i<=n;i++)
    {
        if (tree[i].adj.empty()) bfs_q.push(i);
    }
    
    while (!bfs_q.empty())
    {
        int xt = bfs_q.front();
        bfs_q.pop();
        
        if (tree[xt].par == -1) continue;
        
        dp[xt] = tree[xt].w_par;
        if (!tree[xt].adj.empty())
        {
            lld s_1 = 0;
            for (int i=0;i<tree[xt].adj.size();i++)
            {
                s_1 += dp[tree[xt].adj[i]];
            }
            dp[xt] = min(dp[xt], s_1);
        }
        
        bfs_q.push(tree[xt].par);
    }
}

void extract_seq(int x, vector<int> &ret)
{
    if (tree[x].adj.size() == 0)
    {
        ret.push_back(tree[x].w_par);
        return;
    }
    
    lld opt_2 = 0;
    for (int i=0;i<tree[x].adj.size();i++)
    {
        opt_2 += dp[tree[x].adj[i]];
    }
    
    if (tree[x].w_par < opt_2)
    {
        ret.push_back(tree[x].w_par);
        return;
    }
    
    for (int i=0;i<tree[x].adj.size();i++)
    {
        extract_seq(tree[x].adj[i], ret);
    }
}

inline pair<lld, vector<int> > solve()
{
    compute_dp();
    
    lld ret = 0;
    vector<int> seq;
    
    for (int i=0;i<tree[1].adj.size();i++)
    {
        ret += dp[tree[1].adj[i]];
        extract_seq(tree[1].adj[i], seq);
    }
    
    return {ret, seq};
}

int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
    {
        int len;
        scanf("%d", &len);
        tree[i].adj.resize(len);
        for (int j=0;j<len;j++)
        {
            scanf("%d", &tree[i].adj[j]);
            tree[tree[i].adj[j]].par = i;
        }
        for (int j=0;j<len;j++)
        {
            scanf("%d", &tree[tree[i].adj[j]].w_par);
        }
    }
    
    tree[1].par = tree[1].w_par = -1;
    
    auto ret = solve();
    printf("%lld\n", ret.first);
    for (int j=0;j<ret.second.size();j++)
    {
        printf("%d ", ret.second[j]);
    }
    printf("\n");
    
    return 0;
}