#include <bits/stdc++.h>

using namespace std;
#define MAXN 300010
int A[MAXN], B[MAXN];
vector<pair<int, int> > p;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for(int i = 1; i <= N; i++) p.push_back({A[i], B[i]});
    sort(p.begin(), p.end());
    sort(B+1, B+1+N);
    int maxx = 0, rez = 0, idxx = 0;
    for(auto x : p) {
        ++idxx;
        maxx = max(maxx, x.second);
        if(maxx == B[idxx]) rez++;
    }
    cout << rez;
    return 0;
}
