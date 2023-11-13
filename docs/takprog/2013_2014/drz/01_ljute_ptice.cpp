#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <cstring>
using namespace std;

#define MaxN 1000010

int n,k;
int h[MaxN];
int rk, hb;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i)
		scanf("%d",&h[i]);
	scanf("%d%d",&rk,&hb);

	long long retr = -1LL;
	long long reth = hb;
	
    if ( hb >= k )
    {
        rk--;

        long long count = hb - k + 1;

        for (int i = rk + 1; i < n; ++i)
        {
            if (k > h[i])
            {
                if (h[i] + count >= k)
                {
                    count -= k - h[i] - 1;
                }
                else
                {
                    retr = i + 1;
                    reth = h[i] + count;
                    break;
                }
            }
            else
            {
                count += h[i] - k + 1;
            }
        }

        if (retr == -1LL)
        {
            retr = n + (count + k - 2) / (k - 1);
            reth = (count-1) % (k-1) + 1;
        }

	}

	if (retr == -1LL) retr = rk;

	printf("%lld %lld\n",retr,reth);

	return 0;
}