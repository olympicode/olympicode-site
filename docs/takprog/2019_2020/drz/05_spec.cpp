#include<bits/stdc++.h>
using namespace std;

#define MAXN 333555
#define MAXQ 333555
#define MAXA 1000333

int n,q;
long long nll;
int a[MAXN];
int resl[MAXA],resr[MAXA];

vector< vector<int> > positions[MAXA];

long long powll(long long x, long long st) {
    long long r = 1;
    for(int i=0; i<st; i++) {
        r *= x;
    }
    
    return r;
}

bool boljires(int bestK, int bestD, int tk, int td, int x, int stp) {

    if (bestK == -1 || tk > bestK+stp) {
        return true;
    }

    if (bestK == tk) {
        if (td < bestD) return true;
    }

    if (tk > bestK) {
        if (powll((long long)x, tk-bestK) * (long long)bestD > (long long)td) {
            return true;
        }
    }

    if (td < bestD) {

        if (bestK - tk > stp) return false;

        if ((long long)bestD > (long long)td * powll((long long)x, bestK-tk)) {
            return true;
        }
    }

    return false;
}

int main() {

    scanf("%d%d", &n, &q);
    nll = n;

    int last0 = -1;
    int firstNon0 = -1;
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        if (a[i] == 0) {
            last0 = i;
            continue;
        }

        if (firstNon0 == -1) firstNon0 = i;

        if (a[i] > 1) {
            if (positions[a[i]].empty() || last0 > positions[a[i]].back().back()) {
                vector<int> vec;
                vec.push_back(i);
                positions[a[i]].push_back(vec);
            } else {
                positions[a[i]].back().push_back(i);
            }
        }

    }
    if (firstNon0 == -1) firstNon0 = 0;

    for(int i=0; i<q; i++) {

        int x;
        scanf("%d", &x);

        if (resl[x] == 0) {
            
            if (positions[x].empty()) {
                resl[x] = firstNon0;
                resr[x] = firstNon0;
            } else {

                int bestK = -1;
                int bestD = -1;

                int stp = 2;
                long long t = x;
                while(t < nll) {
                    t*=x;
                    stp++;
                }

                for(int j=0; j<positions[x].size(); j++) {

                    int cnt = positions[x][j].size();
                    for(int pl = 0; pl<cnt; pl++) {
                        for(int pr = max(pl,cnt-stp+pl); pr<cnt; pr++) {

                            int posl = positions[x][j][pl];
                            int posr = positions[x][j][pr];
                            
                            int tk = pr-pl + 1;
                            int td = posr-posl + 1;

                            if (boljires(bestK,bestD,tk,td,x,stp)) {
                                bestK = tk;
                                bestD = td;

                                resl[x] = posl;
                                resr[x] = posr;
                            }
                        }
                    }

                }
            }

            resl[x]++;
            resr[x]++;
        }

        printf("%d %d\n", resl[x]-1, resr[x]-1);
    }


    return 0;
}