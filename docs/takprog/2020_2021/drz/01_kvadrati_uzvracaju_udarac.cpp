#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
int x,y;
map<long long,int> m;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        ans+=m[x-y];
        m[x-y]++;
    }
    printf("%lld",ans);
    return 0;
}
