/*
 Author: Petar 'PetarV' Velickovic
 Task: Kripto
*/

#include <stdio.h>
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

#define MAX_N 100005

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int len;
char N[MAX_N];
lld M;

inline llu kripto()
{
    llu ret = 0LL;
    for (int i=0;i<len;i++)
    {
        ret *= (10 % M);
        ret %= M;
        ret += ((N[i] - '0') % M);
        ret %= M;
    }
    return ret;
}

int main()
{
    scanf("%s%lld", N, &M);
    len = strlen(N);
    printf("%lld\n", kripto());
    return 0;
}