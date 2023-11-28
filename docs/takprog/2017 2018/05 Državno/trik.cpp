#include<bits/stdc++.h>
using namespace std;

int main() {

    int n,j,t,p,i;

    scanf("%d%d", &n, &j);

    t = n;
    if (n%2 == 0) t--;
    for(i=t-2; i>=1; i-=2) printf("%d ", i);
    printf("%d ", t);
    for(i=1; i<t; i+=2) printf("%d ", i);

    p = n;
    if (n%2 == 1) p--;
    for(i=p; i>=2; i-=2) printf("%d ", i);

    if (n%2 == 1) printf("J %d ", t);
    else printf("%d J ", t);

    for(i=2; i<=p; i+=2) printf("%d ", i);

    for(i=2; i<=j; i++) printf("J ");

    printf("\n");
    return 0;
}
