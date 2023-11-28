#include<bits/stdc++.h>
using namespace std;

#define MAXN 3555333
#define mmod 1000000007

int n;
long long bombonice[MAXN];

int bigrand() {
    return (rand() << 15) | (rand());
}

void fmod(long long &x) {
    if (x>=mmod) x%=mmod;
    if (x<0) x = ((x%mmod) + mmod) % mmod;
}

void PocetakBF(int N) {
    n = N;
    for(int i=0; i<=N; i++) bombonice[i] = 0;
}

void DodajBomboniceBF(int P, int K) {
    for(long long k = K; k>0; k--) {
        bombonice[P] += k*k;
        fmod(bombonice[P]);
        P++;
        if (P>n) P=1;
    }
}

int PrebrojiBF(int X, int T) {
    long long s = 0;
    for(int i=0; i<T; i++) {
        s += bombonice[X];
        fmod(s);
        X++;
        if (X>n) X=1;
    }
    return s;
}

long long sum[MAXN], lazy0[MAXN], lazy1[MAXN], lazy2[MAXN];
long long part_sum0[MAXN], part_sum1[MAXN], part_sum2[MAXN];

void Pocetak(int N) {
    n = N;

    part_sum0[0] = 0;
    part_sum1[0] = 0;
    part_sum2[0] = 0;
    for(long long i=1; i<=N; i++) {
        part_sum0[i] = part_sum0[i-1] + 1;   fmod(part_sum0[i]);
        part_sum1[i] = part_sum1[i-1] + i;   fmod(part_sum1[i]);
        part_sum2[i] = part_sum2[i-1] + i*i; fmod(part_sum2[i]);
    }

    int m = min(MAXN,5*N);
    for(long long i=0; i<m; i++) {
        sum[i] = 0;
        lazy0[i] = 0;
        lazy1[i] = 0;
        lazy2[i] = 0;
    }
}

long long lazypartsum(int l, int r, long long s2, long long s1, long long s0) {
    long long s = 0;
    fmod(s2); fmod(s1); fmod(s0);
    s += s2*(part_sum2[r] - part_sum2[l-1]); fmod(s);
    s += s1*(part_sum1[r] - part_sum1[l-1]); fmod(s);
    s += s0*(part_sum0[r] - part_sum0[l-1]); fmod(s);
    return s;
}

void addseg(int x, int l, int r, int L, int R, long long s2, long long s1, long long s0) {

    if (r < L) return;
    if (l > R) return;

    if (l >= L && r <= R) {

        lazy2[x] += s2; fmod(lazy2[x]);
        lazy1[x] += s1; fmod(lazy1[x]);
        lazy0[x] += s0; fmod(lazy0[x]);

        sum[x] += lazypartsum(l,r,s2,s1,s0); fmod(sum[x]);

        /*sum[x] += s2*(part_sum2[r] - part_sum2[l-1]); fmod(sum[x]);
        sum[x] += s1*(part_sum1[r] - part_sum1[l-1]); fmod(sum[x]);
        sum[x] += s0*(part_sum0[r] - part_sum0[l-1]); fmod(sum[x]);*/

        //printf("add %d %d %d (%d %d)   %lld %lld %lld    -> %lld\n", x,l,r,L,R,s2,s1,s0,sum[x]);

    } else {
        int m = (l+r)/2;
        addseg(x*2,l,m, L,R, s2,s1,s0);
        addseg(x*2+1,m+1,r, L,R, s2,s1,s0);
        sum[x] = sum[x*2] + sum[x*2+1];
        fmod(sum[x]);
        sum[x] += lazypartsum(l,r,lazy2[x],lazy1[x],lazy0[x]);
        fmod(sum[x]);
        //printf("trsum %d (%d %d) -> %lld\n", x,l,r, sum[x]);
    }
}

long long sumseg(int x, int l, int r, int L, int R, long long s2, long long s1, long long s0) {

    if (r < L) return 0;
    if (l > R) return 0;

    if (l >= L && r <= R) {

        long long res = sum[x] + lazypartsum(l,r,s2,s1,s0);
        fmod(res);

        /*res += s2*(part_sum2[r] - part_sum2[l-1]); fmod(res);
        res += s1*(part_sum1[r] - part_sum1[l-1]); fmod(res);
        res += s0*(part_sum0[r] - part_sum0[l-1]); fmod(res);*/

        return res;

    } else {

        int m = (l+r)/2;
        long long res = sumseg(x*2,l,m, L,R, s2+lazy2[x],s1+lazy1[x],s0+lazy0[x]);
        res += sumseg(x*2+1,m+1,r, L,R, s2+lazy2[x],s1+lazy1[x],s0+lazy0[x]);
        fmod(res);

        return res;
    }
}

void DodajBombonice(int P, int K) {
    if (P+K-1 > n) {
        long long R = P+K;
        addseg(1,1,n, P,n, 1, -2LL*R,R*R);

        DodajBombonice(1, K-(n-P+1));
    } else {
        long long R = P+K;
        addseg(1,1,n, P,R-1, 1,-2LL*R,R*R);
    }
}

int Prebroji(int X, int T) {
    if (X+T-1 > n) {
        long long sum = Prebroji(X, n-X+1);
        sum += Prebroji(1, T-(n-X+1));
        fmod(sum);
        return sum;
    } else {
        long long sum = sumseg(1,1,n, X,X+T-1, 0,0,0);
        return sum;
    }
}
