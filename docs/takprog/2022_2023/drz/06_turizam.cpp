#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5];
set <int> nule[20];

int calc(int l, int p, int r){
    return r - l + min(p - l, r - p);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        for(int j=0; j<20; j++){
            if(!((1 << j) & a[i])) nule[j].insert(i);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int x, y;
            cin >> x >> y;
            for(int j=0; j<20; j++){
                bool pre = ((1 << j) & a[x]);
                bool posle = ((1 << j) & y);
                if(pre && !posle) nule[j].insert(x);
                if(!pre && posle) nule[j].erase(x);
            }
            a[x] = y;
        }
        else{
            int id;
            cin >> id;
            vector <pair <int, int>> vec;
            int res = 2*n;
            bool bad = 0;
            for(int j=0; j<20; j++){
                if(!((1 << j) & a[id])) continue;
                if(!nule[j].size()){
                    bad = 1;
                    break;
                }
                auto x = nule[j].upper_bound(id);
                if(x == nule[j].begin()){
                    vec.push_back({0, *x});
                    continue;
                }
                auto p = x;
                p--;
                if(x == nule[j].end()){
                    vec.push_back({*p, n + 1});
                }
                else{
                    assert(*p <= id);
                    vec.push_back({*p, *x});
                }
            }
            if(bad){
                cout << "-1\n";
                continue;
            }
            int mxd = id;
            sort(vec.begin(), vec.end());
            for(auto c : vec){
                if(c.first >= 1 && mxd <= n) res = min(res, calc(c.first, id, mxd));
                mxd = max(mxd, c.second);
            }
            if(mxd <= n){
                res = min(res, calc(id, id, mxd));
            }
            cout << res << "\n";
        }
    }
    return 0;
}
