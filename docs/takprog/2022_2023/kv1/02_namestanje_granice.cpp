#include <bits/stdc++.h>
using namespace std;
const int mxN=2e5;
int a[mxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q; cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0; i<q; i++)
    {
        int x; cin >> x;
        int mn=lower_bound(a,a+n,x)-a;
        int mx=upper_bound(a,a+n,x)-a;
        int l=-1, r=1e6;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if((n+m)/2>=mn&&(n+m)/2<=mx-1+m) r=m;
            else l=m;
        }
        cout << r << "\n";
    }
}
