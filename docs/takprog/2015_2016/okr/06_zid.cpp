#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Selo {
    int x, y, w;
};

vector<Selo> sela[1000002];
int C; // cena kilometra zida

void ucitaj(){
    int N;
    cin >> N >> C;
    while (N--){
        Selo novo;
        cin >> novo.x >> novo.y >> novo.w;
        sela[novo.w].push_back(novo);
    }
}

int aps(int x){
    return x > 0 ? x : -x;
}

int resi(){
    int xmax = 0, ymax = 0, obim = 0, resenje = 1e9;

    for (int d=1000000; d>=0; d--){
        for (unsigned i=0; i<sela[d+1].size(); i++){
            xmax = max(xmax, aps(sela[d+1][i].x));
            ymax = max(ymax, aps(sela[d+1][i].y));
            obim = 4*(xmax+ymax);
        }
        resenje = min(resenje, C*obim + d);
    }
    return resenje;
}

int main(){
    ios_base::sync_with_stdio(0);
    ucitaj();
    cout << resi() << endl;
    return 0;
}

