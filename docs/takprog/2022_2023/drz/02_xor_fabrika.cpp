#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int ps[MAXN][2];

int n, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '+'){
            ps[i][0] = ps[i-1][0] + 1;
            ps[i][1] = ps[i-1][1] + 1;
        }
        else if(s[i-1] == '^'){
            ps[i][0] = ps[i-1][0] + (i % 2 == 1 ? 1 : -1);
            ps[i][1] = ps[i-1][1] + (i % 2 == 0 ? 1 : -1);
        }
    }
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        int pr = (x + l + 1) % 2;
        cout << x + ps[r][pr] - ps[l-1][pr] << "\n";
    }
    return 0;
}
