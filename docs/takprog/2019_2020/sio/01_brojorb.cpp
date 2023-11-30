#include<bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXMEM 1200555333

int N;
long long res;
long long resN[MAXN];
long long maxV = 8796093532561LL;

int brP = 16;
long long primeri[] = {-1, -1, 1748063LL, 13497742LL, 39374969LL, 375466538LL, 1809756849LL, 7676048889LL, 24323337576LL, 
35802962412LL, 146900865525LL, 287835581101LL, 681224605882LL, 1119584485997LL, 2199024540265LL, 4398047597508LL, 8796093532561LL};
int trres = 2;
long long resP[MAXN];

int startTime, endTime;

void printTime(int time)
{
    printf("time = %02d:%02d\n", time % 3600 / 60, time % 60);
}

int s[MAXN];

long long palt[MAXN];

char iskorisceni[MAXMEM];

void popLast(int p) {
    iskorisceni[palt[p]] = 0;
}

bool proveriDalImaIUbaci(int p, long long t, int l) {
    long long pt = (t<<1LL) + (l&1);

    if (!iskorisceni[pt]) {
        iskorisceni[pt] = 1;
        palt[p] = pt;
        return true;
    } else {
        return false;
    }
}

int brp[MAXN];
int plens[MAXN][MAXN];
long long plensT[MAXN][MAXN];

bool addLast(int p) {

    int sp = s[p];

    brp[p] = 1;
    plens[p][1] = 1;
    
    long long t = 2LL + sp;

    plensT[p][1] = t;

    bool bb = false;

    if (proveriDalImaIUbaci(p,t,1)) {
        return true;
    }

    if (p>0) {

        if (sp == s[p-1]) {
            plens[p][++brp[p]] = 2;
            plensT[p][brp[p]] = t;
            if (proveriDalImaIUbaci(p,t,2)) {
                return true;
            }
        }

        for(int i=1; i<=brp[p-1]; i++) {

            int l = plens[p-1][i];

            if (p - l - 1 >= 0 && sp == s[p-l-1]) {

                t = (plensT[p-1][i]<<1LL) + sp;

                plens[p][++brp[p]] = l+2;
                plensT[p][brp[p]] = t;

                if (proveriDalImaIUbaci(p,t,l+2)) {
                    return true;
                }
            }
        }
    }

    return bb;
}

void printbin(long long v) {
    if (v/2 != 0) printbin(v/2);
    printf("%lld", v % 2);
}

void idar(int p, long long v, int tp) {

    if (v >= maxV) return;

    for(int b=0; b<2; b++) {
        if (p==0 && b==0) continue;
        long long pv = (v<<1LL) + b;

        if (pv >= maxV) continue;

        s[p] = b;
        if (addLast(p)) {
            
            //trres = upper_bound(primeri, primeri+brP, pv) - primeri;
            while(pv >= primeri[tp]) tp++;
            
            res++;
            resP[tp]++;
            idar(p+1, pv, tp);
            popLast(p);  
        }
    }
}

void ispisiRes() {
    char pathin[555], pathout[555];

    long long ressum = 0;

    for(int i=2; i<=brP; i++) {
        sprintf(pathin, "testcases/%d.in", i);
        sprintf(pathout, "testcases/%d.out", i);

        FILE *fin = fopen(pathin, "w"), *fout = fopen(pathout, "w");

        ressum += resP[i];

        fprintf(fin,"%lld\n", primeri[i]);
        fprintf(fout,"%lld\n", ressum);
        fclose(fin); fclose(fout);
    }
}


int main() {

    startTime = time(0);

    res = 0;

    idar(0,0,2);

    printf("%lld\n", res);
    //printf("%lld\n", resN[N]);

    ispisiRes();

    endTime = time(0);
    printTime(endTime - startTime);

    return 0;
}
