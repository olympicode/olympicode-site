#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<pair<int, bool>>> gr;

int main(){
    cin >> n >> m;
    gr.clear();
    gr.resize(n);
    for(int i = 0; i < m; ++i){
        int x, y, t;
        cin >> x >> y >> t;
        --x;
        --y;
        gr[x].push_back({y,t});
        gr[y].push_back({x,t});
    }
    int u, v;
    cin >> u >> v;
    --u,--v;
    deque<pair<int, int> > dq;
    dq.push_back({u,0});
    vector<int> was(n,-1);

    was[u] = 0;
    vector<int> par(n);
    while(!dq.empty()){
        auto x = dq.front();
        dq.pop_front();
        int x1 = x.first;
        for(auto i : gr[x1]){
            if(i.second == x.second and (was[i.first]==-1 or was[i.first] > was[x1])){
                dq.push_front({i.first, x.second});
                was[i.first] = was[x1];
                par[i.first] = x1;
            } else if(i.second != x.second and (was[i.first]==-1 or was[i.first] > (was[x1]+1))){
                dq.push_back({i.first, i.second});
                was[i.first] = was[x1]+1;
                par[i.first] = x1;
            }
        }
    }
    cout << was[v] << "\n";
}
