#include <bits/stdc++.h>
#define maxn 2000050
using namespace std;
int n;
int q;
long long a[maxn];
long long c[maxn];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%lld",&c[i]);
    }
    scanf("%d",&q);
    while(q--) {
        int i;
        long long x;
        scanf("%d %lld",&i,&x);
        a[i]+=x;
    }
    for(int i=1;i<=n;i++) {
        if(a[i]>c[i]) {
            a[i+1]+=(a[i]-c[i]);
            a[i]=c[i];
        }
        printf("%lld ",a[i]);
    }
    return 0;
}
