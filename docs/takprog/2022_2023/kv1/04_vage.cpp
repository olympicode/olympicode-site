#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MAXN 200010
using namespace std;
int N, M, l[MAXN], r[MAXN], rez[MAXN];
vector<pair<int, pair<int, int> > > delta; // {granica, {tip, indeks}}
vector<pair<int, int> > q; // {x, indeks}
int bit[MAXN];
void update(int idx, int val) {
  while(idx < MAXN) {
    bit[idx] += val;
    idx += idx&-idx;
  }
}
int query(int idx) {
  int rez = 0;
  while(idx > 0) {
    rez += bit[idx];
    idx -= idx&-idx;
  }
  return rez;
}
int main() {
  //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  scanf("%d%d", &N, &M); //cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    int d, u; scanf("%d%d", &d, &u); //cin >> d >> u;
    delta.push_back({d, {+1, i}});
    delta.push_back({u+1, {-1, i}});
  }
  for(int i = 1; i <= M; i++) {
    int x; scanf("%d%d%d", &l[i], &r[i], &x); //cin >> l[i] >> r[i] >> x;
    q.push_back({x, i});
  }
  sort(delta.begin(), delta.end());
  sort(q.begin(), q.end());
  int idx = 0;
  for(int i = 0; i < M; i++) {
    while(idx < delta.size() && delta[idx].first <= q[i].first) {
      update(delta[idx].second.second, delta[idx].second.first);
      idx++;
    }
    rez[q[i].second] = query(r[q[i].second]) - query(l[q[i].second]-1);
  }
  for(int i = 1; i <= M; i++) {
    printf("%d\n", rez[i]);
    //cout << rez[i] << endl;
  }
  return 0;
}
