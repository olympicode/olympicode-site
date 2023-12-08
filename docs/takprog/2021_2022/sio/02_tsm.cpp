#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
#define pii pair<int, int>
#define fi first
#define se second
#define MAXN 300010
#define MAXL 20
#define INF 1000000001
using namespace std;
vector<pii> adj[MAXN], e;
vector<int> v[MAXN];
vector<pair<int, pii> > ec, add;
priority_queue<pii> pq;
int dsu[MAXN], anc[MAXN][MAXL], minn[MAXN][MAXL], in[MAXN], out[MAXN], timer;

int root(int x) {
  while(x != dsu[x]) {
    dsu[x] = dsu[dsu[x]];
    x = dsu[x];
  }
  return x;
}
bool connect(int x, int y) {
  int rtX = root(x), rtY = root(y);
  if(rtX == rtY) return false;
  dsu[rtX] = rtY;
  return true;
}

void dfs(int node, int prev, int nodeIdx) {
  in[node] = ++timer;
  anc[node][0] = prev;
  minn[node][0] = nodeIdx;
  for(auto x : adj[node]) {
    if(x.fi != prev) {
      dfs(x.fi, node, x.se);
    }
  }
  out[node] = ++timer;
}
int W(int idx) {
  return ec[idx].fi;
}

bool inSubtree(int x, int y) { ///da li je x u y
  return in[y] <= in[x] && out[x] <= out[y];
}
int find_min(int x, int y) {
  int minIdx = 0;
  int _x = x, _y = y;
  for(int l = MAXL-1; l >= 0; l--) {
    if(!inSubtree(y, anc[_x][l])) {
      if(W(minn[_x][l]) < W(minIdx)) minIdx = minn[_x][l];
      _x = anc[_x][l];
    }
    if(!inSubtree(x, anc[_y][l])) {
      if(W(minn[_y][l]) < W(minIdx)) minIdx = minn[_y][l];
      _y = anc[_y][l];
    }
  }
  if(!inSubtree(y, _x)) {
    if(W(minn[_x][0]) < W(minIdx)) minIdx = minn[_x][0];
  }
  if(!inSubtree(x, _y)) {
    if(W(minn[_y][0]) < W(minIdx)) minIdx = minn[_y][0];
  }
  return minIdx;
}

vector<int> NadjiPoredak(int N, int M, int* X, int* Y, int* w) {
  ec.push_back({INF, {1, 1}});
  for(int i = 1; i <= M; i++) {
    e.push_back({w[i], i});
    ec.push_back({w[i], {X[i], Y[i]}});
  }
  for(int i = 1; i <= N; i++) dsu[i] = i;
  sort(e.begin(), e.end());
  for(auto edge : e) {
    int w = edge.fi, x = ec[edge.se].se.fi, y = ec[edge.se].se.se;
    if(connect(x, y)) {
      adj[x].push_back({y, edge.se});
      adj[y].push_back({x, edge.se});
      pq.push({w, edge.se});
    } else {
      add.push_back({edge.se, {x, y}});
    }
  }
  dfs(1, 1, 0);
  for(int l = 1; l < MAXL; l++) {
    for(int i = 1; i <= N; i++) {
      anc[i][l] = anc[anc[i][l-1]][l-1];

      minn[i][l] = minn[i][l-1];
      if(W(minn[i][l]) > W(minn[anc[i][l-1]][l-1])) {
        minn[i][l] = minn[anc[i][l-1]][l-1];
      }
    }
  }

  for(auto edge : add) {
    v[find_min(edge.se.fi, edge.se.se)].push_back(edge.fi);
  }
  vector<int> sol;
  while(!pq.empty()) {
    pii vrh = pq.top(); pq.pop();
    sol.push_back(vrh.fi);
    if(vrh.se != 0) {
      for(auto x : v[vrh.se]) {
        pq.push({W(x), 0});
      }
    }
  }
  return sol;
}
/*
4 5
1 2 50
2 3 10
2 4 20
3 4 30
1 4 40

5 5
2 5 12
2 4 3
1 2 50
1 4 11
3 4 36
*/
