#include<bits/stdc++.h>

using namespace std;

const int maxi=5000001;

long long a[maxi];
long long s[maxi];

int main()
{

    for (int i=1; i<maxi; i++)
        for (int j=i; j<maxi; j+=i)
            s[j]+=i;

    int t,x;

    cin>>t;

    while(t--)
    {
        cin>>x;

        long long ans=2;
        for (int i=2; i<=x; i++)
            if (1.0*s[i]/i <1.0*s[ans]/ans) ans=i;

        cout<<ans<<"\n";
    }

    return 0;
}
