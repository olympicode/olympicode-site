#include <iostream>
using namespace std;

const int N = 300000;

int niz[N+5];
int poslednji_dobar[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    poslednji_dobar[n] = n;
    for(int i=n-1; i>=1; i--){
        if(niz[i] > niz[i+1]) poslednji_dobar[i] = i;
        else poslednji_dobar[i] = poslednji_dobar[i+1];
    }
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int l, r;
        cin >> l >> r;
        int p = poslednji_dobar[l];
        if(p >= r - 1) cout << "DA\n";
        else if(poslednji_dobar[p+1] >= r && (p == l || niz[p-1] <= niz[p+1])) cout << "DA\n"; /// brisanje niz[p]
        else if(poslednji_dobar[p+2] >= r && niz[p] <= niz[p+2]) cout << "DA\n"; /// brisanje niz[p+1]
        else cout << "NE\n";
    }
    return 0;
}