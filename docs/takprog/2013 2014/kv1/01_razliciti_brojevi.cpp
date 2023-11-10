/*
    Marko Bakovic
    Razliciti brojevi O(Q + N)
*/

#include <cstdio>

const int maxn = 1e6 + 5;

int n, q, niz[ maxn ], broj_razlicitih[ maxn ], leva_granica, desna_granica;

int main()
{
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) scanf( "%d", &niz[ i ] );
    broj_razlicitih[ 0 ] = 1;
    for ( int i = 1; i < n; i++ )
    {
        if ( niz[ i ] != niz[ i - 1 ] ) broj_razlicitih[ i ] = broj_razlicitih[ i - 1 ] + 1;
        else broj_razlicitih[ i ] = broj_razlicitih[ i - 1 ];
    }
    scanf( "%d", &q );
    for ( int i = 0; i < q; i++ )
    {
        scanf( "%d %d", &leva_granica, &desna_granica );
        int resenje = broj_razlicitih[ desna_granica ];
        if ( leva_granica )
        {
            resenje -= broj_razlicitih[ leva_granica - 1 ];
            if ( niz[ leva_granica ] == niz[ leva_granica - 1 ] ) resenje++;
        }
        printf( "%d\n", resenje );
    }
    return 0;
}
