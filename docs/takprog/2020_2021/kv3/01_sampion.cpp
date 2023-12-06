#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long X, Y, T; cin >> X >> Y >> T;
    long long rez = 0;
    if(T%X == 0) rez = (T/X)*(X+Y)-Y;
    else rez = (T/X)*(X+Y) + T%X;
    cout << rez;
    return 0;
}
