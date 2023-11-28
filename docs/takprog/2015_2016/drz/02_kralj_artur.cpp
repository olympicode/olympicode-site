#include <iostream>
#include <algorithm>
using namespace std;

const long long lim = 1ll << 60ll;

inline void add(long long& x, long long y){
    x += y;
    if (x > lim) x = lim;
}

int N, M;
long long K;

int A[11][1001];
long long D[11][10001];

int main(){
    cin >> M >> N >> K;
    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
    D[0][0] = 1;
    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            int x = A[i][j];
            for (int k=x; k<=1000*i; k++){
                add(D[i][k], D[i-1][k-x]);
            }
        }
    }
    int w = 1000*M;
    while (w>=0){
        if (K <= D[M][w]){
            cout << w << endl;
            return 0;
        } else {
            K -= D[M][w];
            w--;
        }
    }
    return 0;
}
