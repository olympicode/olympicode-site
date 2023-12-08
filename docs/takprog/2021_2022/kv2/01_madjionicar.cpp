#include <bits/stdc++.h>
#define MAXN 20007
using namespace std;
int p[MAXN];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) if(p[i]==k) printf("%d",p[(i+1)%n]);
}
