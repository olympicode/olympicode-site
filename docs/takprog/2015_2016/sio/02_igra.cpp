#include "igra.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

#define MaxK 110
#define MaxN 1010
#define MaxM 100010
#define INF 1000000000

int n, m, k, d;
vector<int> edge[2*MaxN];

int even[MaxK];
int odd[MaxK];
int dist[2*MaxN];

int OddNode( int id )
{
	return id;
}

int EvenNode( int id )
{
	return n + id;
}

void BFS( int start, int end, int &even, int &odd )
{
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	while (!q.empty()) q.pop();

	dist[ EvenNode( start ) ] = 0;
	q.push( EvenNode( start ) );

	while (!q.empty()) {
		int currNode = q.front();
		q.pop();

		for (int i = 0; i < edge[ currNode ].size(); ++i) {
			int adjNode = edge[ currNode ][i];
			if ( dist[ adjNode ] != -1 ) continue;

			dist[ adjNode ] = dist[ currNode ] + 1;
			q.push( adjNode );
		}
	}

	even = dist[ EvenNode( end ) ];
	odd = dist[ OddNode( end ) ];
}

int Calculate( int currDay, int wantedDay, int D )
{
	if ( currDay == -1 ) return INF;

	int ret = currDay;
	currDay %= D;

	if ( wantedDay < currDay ) {
		wantedDay += D;
	}

	if ( (wantedDay - currDay) % 2 == 0 ) {
		return ret + (wantedDay - currDay);
	}

	wantedDay += D;
	if ( (wantedDay - currDay) % 2 == 0 ) {
		return ret + (wantedDay - currDay);
	}

	return INF;
}

void Igra(int N, int M, int K, int D, int* U, int* V, int* S, int* F, int* R){
	n = N;
	m = M;
	k = K;
	d = D;

	for (int i = 0; i < m; ++i) {
		int u = U[i];
		int v = V[i];
		--u; --v;

		edge[ OddNode(u) ].push_back( EvenNode(v) );
		edge[ EvenNode(u) ].push_back( OddNode(v) );

		edge[ OddNode(v) ].push_back( EvenNode(u) );
		edge[ EvenNode(v) ].push_back( OddNode(u) );
	}

	for (int i = 0; i < k; ++i) {
		int start = S[i], end = F[i];
		--start; --end;

		BFS( start, end, even[ i ], odd[ i ] );

		// printf("%d => %d %d\n", i+1, even[i], odd[i]);
	}

	for (int day = 0; day < d; ++day) {
		int maximumEven = -1;
		int maximumOdd = -1;

		for (int i = 0; i < k; ++i) {
			int evenNumberOfMoves = Calculate( even[i], day, d );
			int oddNumberOfMoves = Calculate( odd[i], day, d );

			maximumEven = max( maximumEven, evenNumberOfMoves );
			maximumOdd = max( maximumOdd, oddNumberOfMoves );
		}

		int ret = min( maximumEven, maximumOdd );
		if ( ret == INF ) R[day] = -1;
		else R[day] = ret;
	}
}
