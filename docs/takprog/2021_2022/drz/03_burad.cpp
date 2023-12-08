#include <bits/stdc++.h>
using namespace std;
int solve(int N, int M, vector<int> a, vector<pair<int, int> > days) {
  sort(days.begin(), days.end());
  int pref[N+2], ends[N+2];
  fill(pref, pref+N+2, 0);
  fill(ends, ends+N+2, 0);
  for(auto x : days) {
    pref[x.first]++;
    pref[x.second+1]--;
  }
  for(int i = 1; i <= N; i++) {
    pref[i] += pref[i-1];
  }
  priority_queue<int> pq;
  int idx = 0, res = 0, active = 0;
  for(int i = 1; i <= N; i++) {
    while(idx < M && days[idx].first == i) {
      pq.push(days[idx].second);
      idx++;
    }
    while(pref[i] > a[i-1] && pref[i]-a[i-1] > active) {
      int r = pq.top(); pq.pop();
      ends[r]++;
      active++;
      res++;
    }
    active -= ends[i];
  }
  return res;
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> a;
    vector<pair<int, int> > days;
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        days.push_back({x, y});
    }
    cout << solve(N, M, a, days);
}
