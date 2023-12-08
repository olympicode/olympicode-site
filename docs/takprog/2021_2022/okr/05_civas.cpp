#include <bits/stdc++.h>
using namespace std;
int a[200007],b[200007],n,q,cnt;
bool bad[200007];
void check(int x)
{
    if(x>=n/2) {check(x-n/2); return;}
    if(bad[x]) cnt--;
    if(b[x]==b[x+n/2]) bad[x]=false;
    else bad[x]=true;
    if(bad[x]) cnt++;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) b[i]=a[i]^a[(i+1)%n];
    for(int i=0;i<n;i++) check(i);
    if(cnt==0) printf("%d\n",n/2);
    else printf("%d\n",n);
    while(q--)
    {
        int p,v;
        scanf("%d%d",&p,&v);
        p--;
        a[p]=v;
        b[(p+n-1)%n]=a[(p+n-1)%n]^a[p];
        b[p]=a[p]^a[(p+1)%n];
        check(p); check((p+n-1)%n);
        if(cnt==0) printf("%d\n",n/2);
        else printf("%d\n",n);
    }
}
