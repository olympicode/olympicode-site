#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
long long A[MAXN], zbir;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        zbir += A[i];
    }
    int Q; cin >> Q;
    long long cnt = 0, sum = 0;
    while(Q--) {
        int tip; cin >> tip;
        if(tip == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            if(x > 0) sum += (r-l+1)*x;
        } else {
            cnt++;
        }
    }
    cout << (zbir+sum)*cnt;
    return 0;
}
