#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
#define lld long long
int N, M;
lld A[MAXN], B[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i = 1; i <= N; i++) cin >> A[i];
        for(int i = 1; i <= M; i++) cin >> B[i];
        sort(A+1, A+1+N);
        lld X = A[2]-A[1];
        int rez = 1;
        for(int i = 3; i <= N; i++) X = __gcd(X, A[i]-A[i-1]);
        for(int i = 1; i <= M; i++) {
            if(abs(B[i]-A[1])%X == 0) rez = 0;
        }
        cout << rez << endl;
    }
    return 0;
}
