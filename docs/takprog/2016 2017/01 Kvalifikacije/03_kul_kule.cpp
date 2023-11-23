#include<stdio.h>
#include<math.h>
#include<algorithm>


using namespace std;

int n;
long long a[1000000];

long long calc(long long x)
{
    if (x%3==0) return(x/3); else
    if (x%3==1) return((x-4)/3+2); else
    return(x/3+1);
}

int main()
{
    scanf("%d",&n);

    long long res=0;
    long long maxi=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        maxi=max(maxi,a[i]);
    }

    int cnt=0;

    for (int i=0;i<n;i++)
        if (maxi-a[i]==1) cnt++;

    if (cnt==0)
    {
        for (int i=0;i<n;i++)
            res+=calc(maxi-a[i]);

        printf("%lld\n",res);
    } else
    {
        for (int i=0;i<n;i++)
            res+=calc(maxi-a[i]+2);

        printf("%lld\n",res);
    }

    return 0;
}

