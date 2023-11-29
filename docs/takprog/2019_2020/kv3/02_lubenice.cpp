#include<bits/stdc++.h>

using namespace std;

int k1, k2, k3;
long long l, r;

int lcm(int x, int y)
{
    return x * y / __gcd(x, y) ;
}

int main()
{
    cin>> k1 >> k2 >> k3 >> l >> r ;

    int sum = k1 * ( k2 + k3 ) + k2 * k3 ;

    if (sum > k1 * k2 * k3) return !printf("0\n") ;

    if ( sum == k1 * k2 * k3 )
    {
        long long nzs = lcm( lcm ( k1, k2 ), k3) ;
        return !printf( "%lld\n", r / nzs - ( l - 1) / nzs ) ;
    }

    long long ans = 0;
    for (long long i = l ; i<= min(l + 3000, r) ; i++)
    {
         long long val =  (i + k1 - 1)/k1 + (i + k2 - 1)/k2 + (i + k3 - 1) / k3 ;
         if (val <= i) ans++;
    }

    ans += r - min( l + 3000, r ) ;

    return !printf( "%lld\n", ans ) ;
}
