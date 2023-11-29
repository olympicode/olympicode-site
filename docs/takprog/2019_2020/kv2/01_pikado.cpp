#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 16;

int n, k, cnt[MAXN * 2];
vector<int> sol;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        string inFileName = argv[1];
        string outFileName = inFileName.substr(0, inFileName.length() - 2) + "out";
        freopen(inFileName.c_str(), "r", stdin);
        freopen(outFileName.c_str(), "w", stdout);
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x + MAXN]++;
    }
    for (int i = 0; i < 2 * MAXN; i++) {
        if (cnt[i] >= k) {
            sol.push_back(i - MAXN);
        }
    }
    cout << sol.size() << endl;
    for (auto x : sol) {
        cout << x << " ";
    }
    return 0;
}
