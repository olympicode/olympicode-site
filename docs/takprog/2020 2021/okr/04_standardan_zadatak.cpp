#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5;
const int maxA = 1e6;

int a[maxN], cnt[maxA + 10];
int n;

int main()
{
    scanf("%d",&n);

    assert(n > 0 && n <= maxN);

    for (int i = 1; i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	assert(a[i] > 0 && a[i]<=maxA);
    	cnt[a[i]]++;
    }
   
   int ans = n;
   int bigger = 0;
   for (int i = maxA; i>0; i--) 
   if (cnt[i])
   {   
       ans = min(ans, max(bigger, n - bigger - cnt[i]));
       bigger+=cnt[i];
   }

   printf("%d\n", ans);
}