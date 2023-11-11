/*
 Author: Petar 'PetarV' Velickovic
 Task: Carina
*/

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

lld n, c, l, X;

inline lld max1(lld a, lld b)
{
    if (a > b) return a;
    return b;
}

inline lld min1(lld a, lld b)
{
    if (a < b) return a;
    return b;
}

inline lld moj_ceil(lld A, lld B)
{
    lld ret = A/B;
    if (B * ret != A) ret++;
    return ret;
}

inline lld solve_bruteforce()
{
    for (lld i=0;i<l;i++)
    {
        n -= moj_ceil(n, c);
    }
    return n;
}

inline lld calc_new_n(lld x)
{
    lld V = moj_ceil(n, c);
    lld rem = n % c;
    lld ret;
    
    if (rem == 0 || rem >= x) ret = n - V*x;
    else ret = n - (V-1)*x - rem;
    
    return max1(0, ret);
}

inline lld binsearch(lld initPos)
{
    lld i = initPos + 1, j = l;
    lld V = moj_ceil(n, c);
    
    while (i < j)
    {
        lld mid = (i+j) >> 1;
        lld newN = calc_new_n(mid - initPos);
        if (moj_ceil(newN, c) == V) i = mid+1;
        else j = mid;
    }
    
    return i;
}

inline lld solve()
{
    lld ii = 0;
    while (ii < l && moj_ceil(n, c) > 1)
    {
        lld next_ii = binsearch(ii);
        lld x = next_ii - ii;
        
        lld V = moj_ceil(n, c);
        lld rem = n % c;
        
        if (rem == 0 || rem >= x) n -= V*x;
        else n -= (V-1)*x + rem;
        
        ii = next_ii;
    }
    return max1(0LL, n - (l - ii));
}

inline void debug()
{
    srand(time(NULL));
    for (int i=1;i<=20000;i++)
    {
        n = rand() % 100000 + 1;
        c = rand() % 100000 + 1;
        l = rand() % 100000 + 1;
        X = rand() % 100000 + 1;
        
        lld X1 = moj_ceil(n, c);
        if (X1 > (X+1)) n = c*(X+1);
        
        lld storN = n, storC = c, storL = l;
        lld bf = solve_bruteforce();
        n = storN, c = storC, l = storL;
        lld tt = solve();
        if (i % 1000 == 0) printf("Done %d\n", i);
        assert(bf == tt);
    }
}

int main()
{
    scanf("%lld%lld%lld%lld", &n, &c, &l, &X);
    lld X1 = moj_ceil(n, c);
    if (X1 > (X+1)) n = c*(X+1);
    printf("%lld\n", solve());
    return 0;
}