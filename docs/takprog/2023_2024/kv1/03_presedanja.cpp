#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(400005);
bool vis[400005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int n,m,s,t; cin>>n>>m>>s>>t;
    while (m--)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v+n);
        g[v].push_back(u+n);
        g[u+n].push_back(v);
        g[v+n].push_back(u);
    }
    
    queue<pair<int,int>> bfs;
    bfs.push({s,0});
    while (!bfs.empty())
    {
        int p=bfs.front().first;
        int d=bfs.front().second;
        bfs.pop();
        if (vis[p]) continue;
        vis[p]=true;
        
        if (p==t)
        {
            cout<<d/2<<"\n";
            break;
        }
        
        for (auto it : g[p]) bfs.push({it,d+1});
    }
}