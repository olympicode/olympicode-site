#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;
///
#define INF 1000000000
#define mid (l+r)/2
int dp[MAXN], seg[4*MAXN], lazy[4*MAXN];
void init(int node, int l, int r) {
    if(l == r) {
        seg[node] = dp[l];
        lazy[node] = INF;
        return;
    }
    init(2*node, l, mid); init(2*node+1, mid+1, r);
    seg[node] = max(seg[2*node], seg[2*node+1]);
    lazy[node] = INF;
}
void propagate(int node, int l, int r) {
    if(lazy[node] != INF) {
        seg[node] = lazy[node];
        if(l != r) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = INF;
    }
}
int query(int node, int l, int r, int L, int R) {
    propagate(node, l, r);
    if(L <= l && r <= R) return seg[node];
    if(r < L || r < l || R < l || R < L) return -INF;
    return max(query(2*node, l, mid, L, R), query(2*node+1, mid+1, r, L, R));
}
void update(int node, int l, int r, int L, int R, int val) {
    propagate(node, l, r);
    if(L <= l && r <= R) {
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    if(r < L || r < l || R < l || R < L) return;
    update(2*node, l, mid, L, R, val); update(2*node+1, mid+1, r, L, R, val);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}
int Slamke(int N, int* A, int M, int* T, int* X, int* Y) {
    int idxx = -1;
    for(int i = 1; i <= N; i++) {
        if(A[i] == 1) dp[i] = 0;
        else dp[i] = -INF;
    }
    init(1, 1, N);
    for(int i = 1; i <= M; i++) {
        if(T[i] == 1) {
            int maxx = query(1, 1, N, X[i], Y[i]);
            update(1, 1, N, X[i], Y[i], maxx);
        } else {
            int maxx = query(1, 1, N, X[i], X[i]);
            update(1, 1, N, X[i], X[i], maxx+1);
        }
    }
    return query(1, 1, N, 1, N);
}
/*
int A[MAXN], T[MAXN], X[MAXN], Y[MAXN];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    int M; cin >> M;
    for(int i = 1; i <= M; i++) cin >> T[i] >> X[i] >> Y[i];
    cout << Slamke(N, A, M, T, X, Y) << endl;
    return 0;
}
*/