#include <bits/stdc++.h>
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
#define NL(x) " \n"[(x)]
#define lld long long
#define pil pair<int,lld>
#define pli pair<lld,int>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mid ((l+r)/2)
#define endl '\n'
#define all(a) begin(a),end(a)
#define sz(a) int((a).size())
#define LINF 1000000000000000LL
#define INF 1000000000
#define EPS 1e-9
using namespace std;
int solve(int N, int M, vector<int> p, vector<pair<int, int> > cards) {
    int dub[N+1];
    dub[1] = 0;
    for(int i = 2; i <= N; i++) {
        dub[i] = dub[p[i-2]] + 1;
    }
    map<int, int> cnt;
    for(auto x : cards) {
        cnt[x.first + dub[x.second]]++;
    }
    int rez = 0;
    for(auto x : cnt) {
        rez += x.second - x.second%2;
    }
    return rez;
}
int main() {
    ios::sync_with_stdio(false); //cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> p;
    int cnt = 0;
    for(int i = 0; i < N-1; i++) {
        int x; cin >> x;
        p.push_back(x);
    }
    vector<pair<int, int> > cards;
    for(int i = 0; i < M; i++) {
        int t, v; cin >> t >> v;
        cards.push_back({t, v});
    }
    cout << solve(N, M, p, cards) << endl;
    return 0;
}
