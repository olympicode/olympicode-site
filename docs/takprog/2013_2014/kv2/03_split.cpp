/*
 Author: Petar 'PetarV' Velickovic
 Task: Split
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

int n, q;
char frst[55];
char kom[10];
int x;
char s1[55], s2[55];

struct Range
{
    int L, R;
    string S;
};
vector<Range> Rs;
int idd = 0;

int bit[MAX_N];

inline void update(int x, int val)
{
    while (x <= n)
    {
        bit[x] += val;
        x += (x & -x);
    }
}

inline int read(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

inline void split(int x, string sL, string sR)
{
    int idx = read(x);
    
    int L = Rs[idx].L;
    int R = Rs[idx].R;
    
    // Reduce [L..R] to 0
    update(L, -idx);
    if (R < n) update(R+1, idx);
    
    // Convert [L..x-1] to idL
    if (L < x)
    {
        int idL = ++idd;
        
        update(L, idL);
        update(x, -idL);
        
        Range Rl;
        
        Rl.L = L;
        Rl.R = x-1;
        Rl.S = sL;
        
        Rs.push_back(Rl);
    }
    
    // Convert [x+1..R] to idR
    if (x < R)
    {
        int idR = ++idd;
        
        if (x < n) update(x+1, idR);
        if (R < n) update(R+1, -idR);
        
        Range Rr;
        
        Rr.L = x+1;
        Rr.R = R;
        Rr.S = sR;
        
        Rs.push_back(Rr);
    }
    
    // Convert [x..x] to idx
    update(x, idx);
    if (x < n) update(x+1, -idx);
    
    Rs[idx].L = Rs[idx].R = x;
}

inline void debug()
{
    for (int i=1;i<=n;i++)
    {
        printf("%d ", read(i));
    }
    printf("\n");
}

int main()
{
    scanf("%d%d%s", &n, &q, frst);
    
    Range R;
    R.L = 1, R.R = n;
    R.S = frst;
    Rs.push_back(R);
    
    while (q--)
    {
        scanf("%s", kom);
        if (kom[0] == 'S')
        {
            scanf("%d%s%s", &x, s1, s2);
            split(x, s1, s2);
        }
        else if (kom[0] == 'Q')
        {
            scanf("%d", &x);
            printf("%s\n", Rs[read(x)].S.c_str());
        }
    }
    return 0;
}