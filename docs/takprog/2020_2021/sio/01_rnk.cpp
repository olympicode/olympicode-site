#include "code.h"
#include <cstdio>

int delta(char a, char b, int k) {
    return Skener(1, k, a) - Skener(1, k, b);
}

void solve(int n, char a, int na, char b, int nb, int *L, int *R) {
    if(na + nb == n && n % 2 == 1) {
        *L = *R = -1;
    } else {
        int mindelta = na - n/2;
        int maxdelta = n/2 - nb;

        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int d = delta(a, b, mid);

            if(mindelta <= d && d <= maxdelta) {
                *L = 1; *R = mid;
                return;
            } else {
                if(d < mindelta) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        *L = 1; *R = lo;
    }
}

void Resi(int N, int *L, int *R) {
    int a, c, g, u;
    a = Skener(1, N, 'A');
    c = Skener(1, N, 'C');
    g = Skener(1, N, 'G');
    u = N - a - c - g;

    if(a + u > c + g) {
        if(a > u) {
            solve(N, 'A', a, 'U', u, L, R);
        } else {
            solve(N, 'U', u, 'A', a, L, R);
        }
    } else {
        if(c > g) {
            solve(N, 'C', c, 'G', g, L, R);
        } else {
            solve(N, 'G', g, 'C', c, L, R);
        }
    }
}
