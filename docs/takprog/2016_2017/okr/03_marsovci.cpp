#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXH 1000000005

using namespace std;

int N, H[MAXN];
int minh = MAXH, maxh = -1;
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &H[i]);
        minh = min(minh, H[i]);
        maxh = max(maxh, H[i]);
    }
    int first_min = -1;
    int first_max = -1;
    long long sol = 0;
    for(int L = 0; L < N; L++)
    {
        if(first_min < L)
        {
            do
            {
                first_min++;
            }
            while(first_min < N && H[first_min] != minh);
        }
        if(first_max < L)
        {
            do
            {
                first_max++;
            }
            while(first_max < N && H[first_max] != maxh);
        }
        if(first_min == N || first_max == N)
        {
            break;
        }
        int R = max(first_max, first_min);
        sol += N - R;
    }
    printf("%lld\n", sol);
    return 0;
}
