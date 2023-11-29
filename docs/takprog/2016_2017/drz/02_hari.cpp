//carobni stapovi
#include <bits/stdc++.h>

using namespace std;

struct Stap {
    int tip;
    int pozicija;

    bool operator < (const Stap &s) const {
        if (tip != s.tip) {
            return tip < s.tip;
        }
        return pozicija < s.pozicija;
    }
};

int n, k, br_delilaca, delilac[12345], k_ti[200000];
Stap stap[200000];

void nadji_delioce(int n) {
    br_delilaca = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            delilac[br_delilaca++] = i;
        }
    }
}

bool proveri_grupu(int pocetak, int kraj) {
    for (int i = pocetak; i < kraj; i++) {
        if (k_ti[i] == -1) {
            continue;
        }
        if (k_ti[i] < kraj) {
            return false;
        }
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stap[i].tip);
        stap[i].pozicija = i;
    }

    nadji_delioce(n);

    sort(stap, stap + n);

    for (int i = 0; i < n; i++) {
        if (i + k >= n || stap[i].tip != stap[i + k].tip) {
            k_ti[stap[i].pozicija] = -1;
        }
        else {
            k_ti[stap[i].pozicija] = stap[i + k].pozicija;
        }
    }

    int br_nacina = 0;

    for (int d = 0; d < br_delilaca; d++) {
        int br_grupa = n / delilac[d];
        bool balans = true;

        for (int g = 0; g < br_grupa; g++) {
            int pocetak = g * delilac[d];
            int kraj = (g+1) * delilac[d];
            if (!proveri_grupu(pocetak, kraj)) {
                balans = false;
                break;
            }
        }

        if (balans) {
            br_nacina++;
        }
    }

    printf("%d\n", br_nacina);

    return 0;
}
