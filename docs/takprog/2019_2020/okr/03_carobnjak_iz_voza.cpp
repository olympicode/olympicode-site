#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000555
#define MAXSM 1000555

int n;
long long e;
int s[MAXN],m[MAXN],cnt[MAXSM];

int main() {

    scanf("%d%lld", &n, &e);

    for(int i=0; i<n; i++) {
        scanf("%d", &s[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &m[i]);
    }

    for(int i=0; i<n; i++) {
        cnt[m[i]]++;
        while(s[i] > 0) {
            cnt[s[i]]++;
            s[i] /= 2;
        }
    }

    int res = 0;
    for(int i=MAXSM-1; i>=1; i--) {
        while(e > 0 && cnt[i] > 0) {
            e -= i;
            cnt[i]--;
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}