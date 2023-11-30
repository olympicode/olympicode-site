#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int n;
long long b[maxn];
long long a[maxn];
int main () {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        scanf("%lld",&b[i]);
    }
    a[1]=b[1];
    a[n]=b[n-1];
    for(int i=2;i<n;i++) {
        a[i]=b[i-1]*b[i]/__gcd(b[i-1],b[i]);
    }
    for(int i=1;i<n;i++) {
        if(__gcd(a[i],a[i+1])!=b[i]) {
            printf("-1");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) printf("%lld ",a[i]);
    return 0;
}
