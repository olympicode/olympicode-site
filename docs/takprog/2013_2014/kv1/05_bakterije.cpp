/*
    Marko Bakovic
    Bakterije
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1e3 + 5;

struct node
{
    int x, y, time, type;
} event[ maxn ];

int n, dist[ maxn ][ maxn ], time_sol, all_size, dead[ maxn ];
pair < int, int > all[ maxn * maxn ];
vector < int > adj[ maxn ];

int get_dist( node A, node B )
{
    int temp = abs( A.x - B.x ) + abs( A.y - B.y );
    int diff = max( A.time, B.time ) - min( A.time, B.time );
    return max( A.time, B.time ) + max( 0, ( temp - diff + 1 ) / 2 );
}

bool cmp( pair < int, int > A, pair < int, int > B )
{
    if ( dist[ A.first ][ A.second ] != dist[ B.first ][ B.second ] ) return dist[ A.first ][ A.second ] < dist[ B.first ][ B.second ];
    return ( event[ A.first ].type == event[ A.second ].type );
}

void kill( int curr, int time )
{
    dead[ curr ] = time;
    for ( vector < int > :: iterator it = adj[ curr ].begin(); it != adj[ curr ].end(); it++ )
        if ( dead[ *it ] == -1 ) kill( *it, time );
}

bool one_dead( int A, int B )
{
    if ( dead[ A ] != -1 && dead[ A ] < dist[ A ][ B ] ) return true;
    if ( dead[ B ] != -1 && dead[ B ] < dist[ A ][ B ] ) return true;
    return false;
}

int main()
{
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) scanf( "%d %d %d %d", &event[ i ].x, &event[ i ].y, &event[ i ].time, &event[ i ].type );
    for ( int i = 0; i < n; i++ )
        for ( int j = i + 1; j < n; j++ )
        {
            all[ all_size++ ] = make_pair( i, j );
            dist[ i ][ j ] = get_dist( event[ i ], event[ j ] );
        }
    sort( all, all + all_size, cmp );
    memset( dead, -1, sizeof( dead ) );
    for ( int i = 0; i < all_size; i++ )
    {
        if ( one_dead( all[ i ].first, all[ i ].second ) ) continue;
        if ( event[ all[ i ].first ].type != event[ all[ i ].second ].type )
        {
            kill( all[ i ].first, dist[ all[ i ].first ][ all[ i ].second ] );
            kill( all[ i ].second, dist[ all[ i ].first ][ all[ i ].second ] );
            time_sol = dist[ all[ i ].first ][ all[ i ].second ];
        }
        else
        {
            adj[ all[ i ].first ].push_back( all[ i ].second );
            adj[ all[ i ].second ].push_back( all[ i ].first );
        }
     }
     printf( "%d\n", time_sol );
     int alive = -1;
     for ( int i = 0; i < n; i++ )
        if ( dead[ i ] == -1 )
        {
            alive = event[ i ].type;
            break;
        }
    if ( alive == -1 ) printf( "0\n" );
    else printf( "1\n%d\n", alive );
    return 0;
}
