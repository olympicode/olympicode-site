#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORR(i,n) for(i=0;i<n;i++)
#define is_digit(c) ('0'<=(c) && (c)<='9')

#define eps 0.0000001
#define PI  3.14159265359
#define infll 199988877733322255LL

long long a[1000333],s[1000333],llevo[1000333],rlevo[1000333],res_levo[1000333];

int main() {

    freopen("input2.txt", "r", stdin);
    //freopen("output9.txt", "w", stdout);

    int n,k,i,j;
    long long x,l1,r1,l2,r2,res,min_l,max_d,min_l_ind,max_d_ind;
    bool bres;

    scanf("%d", &n);

    for(i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }

    for(i=1; i<=n; i++) {
        scanf("%lld", &x);
        a[i] -= x;
    }

    s[0] = 0;
    for(i=1; i<=n; i++) {
        s[i] = s[i-1] + a[i];
    }

    res_levo[1] = s[1] - s[0];
    if (s[1] < s[0]) {
        min_l = s[1];
        min_l_ind = 1;
    } else {
        min_l = s[0];
        min_l_ind = 0;
    }

    rlevo[1] = 1;
    llevo[1] = 1;

    for(i=2; i<=n; i++) {
        res_levo[i] = res_levo[i-1];
        rlevo[i] = rlevo[i-1];
        llevo[i] = llevo[i-1];
        if (s[i] - min_l > res_levo[i]) {
            res_levo[i] = s[i] - min_l;
            rlevo[i] = i;
            llevo[i] = min_l_ind + 1;
        }

        if (s[i] < min_l) {
            min_l = s[i];
            min_l_ind = i;
        }
    }

    max_d = s[n];
    max_d_ind = n;
    res = max_d - s[n-1] + res_levo[n-1];
    if (s[n-1] > max_d) {
        max_d = s[n-1];
        max_d_ind = n-1;
    }

    for(i=n-2; i>0; i--) {
       if (max_d - s[i] + res_levo[i] > res) {
           res = max_d - s[i] + res_levo[i];
           l1 = llevo[i];
           r1 = rlevo[i];
           l2 = i+1;
           r2 = max_d_ind;
       }
       if (s[i] > max_d) {
           max_d = s[i];
           max_d_ind = i;
       }
    }

    printf("%lld\n", res);
    printf("-> %lld %lld %lld %lld\n", l1,r1,l2,r2);
    printf("-> %lld\n", s[r1] - s[l1-1] + s[r2] - s[l2-1]);

    return 0;
}
