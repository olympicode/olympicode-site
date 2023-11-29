#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
//    string path = argv[1];
//    freopen(path.c_str(), "r", stdin);
//    path = path.substr(0, path.length() - 2) + "out";
//    freopen(path.c_str(), "w", stdout);

    int n, x;
    cin >> n >> x;
    int mini = x, maxi = x;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        mini = min(mini, y);
        maxi = max(maxi, y);
    }
    cout << min(x - mini, maxi - x) + maxi - mini;
    return 0;
}
