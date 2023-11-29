#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, n;
vector<int> tok, novitok;
vector<vector<int>> mat;

void rasporedi(vector<int> &a, bool oddrow, int l, int r, ll curr) {
    if (l == -1) {
        // sve ide desno - garantovano je da desno postoji
        a[r] += curr;
    } else if (r == n) {
        // sve ide levo - garantovano je da levo postoji
        a[l] += curr;
    } else {
        // podjednako se raspodeli
        a[l] += curr / 2;
        a[r] += curr / 2;
        if (oddrow) {
            // u neparnim redovima višak ide levo
            a[l] += (curr & 1);
        } else {
            // u parnim redovima višak ide desno
            a[r] += (curr & 1);
        }
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> h >> n;
    tok.resize(n);
    novitok.resize(n);
    mat.resize(h);
    for (int i = 0; i < h; i++) {
        mat[i].resize(n);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        tok[i] = 1;
    }
    for (int i = 0; i < h; i++) {
        int last = -1;
        int curr = 0;
        for (int j = 0; j < n; j++) {
            novitok[j] = 0;
            if (mat[i][j] == 0) {
                if (last == -1) {
                    last = j;
                }
                curr += tok[j];
            } else {
                novitok[j] += tok[j];
                if (last != -1) {
                    rasporedi(novitok, (i + 1) & 1, last - 1, j, curr);
                    last = -1;
                    curr = 0;
                }
            }
        }
        if (last != -1) {
            rasporedi(novitok, (i + 1) & 1, last - 1, n, curr);
        }
        tok = novitok;
    }
    for (int i = 0; i < n; i++) {
        cout << tok[i] << " ";
    }
    cout << endl;
    return 0;
}
