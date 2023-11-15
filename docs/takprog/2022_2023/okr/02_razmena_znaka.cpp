#include <bits/stdc++.h>
#define MAXN 30007
using namespace std;
int a[MAXN],b[MAXN];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) if(i&1) a[i]=-a[i];
        for(int i=0;i<n;i++) if(i&1) b[i]=-b[i];
        sort(a,a+n);
        sort(b,b+n);
        bool ok=true;
        for(int i=0;i<n;i++) if(a[i]!=b[i]) ok=false;
        if(ok) cout<<"DA\n";
        else cout<<"NE\n";
    }
}
