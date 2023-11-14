#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MaxN = 35;
const long long MaxSetSize = (1 << (MaxN/2));

class Vector
{
private:
	int M;
	int vector[MaxN];
	
public:
	Vector() {
	}

	Vector( int _M ) {
		M = _M;
		memset(vector, 0, sizeof(vector));
	}

	Vector( int *value, int _M ) {
		M = _M;
		for (int i = 0; i < M; ++i)
			vector[i] = value[i];
	}

	void set( int position, int value ) {
		vector[position] = value;
	}

	void add( int position, int value ) {
		vector[position] += value;
	}

	int get( int position ) const {
		return vector[position];
	}

	void copy( Vector _vector )
	{
		M = _vector.M;
		for (int i = 0; i < M; ++i)
			vector[i] = _vector.get(i);
	}

	Vector operator + ( Vector &other ) {
		Vector ret = other;
		for (int i = 0; i < M; ++i)
			ret.add( i, get(i) );
		return ret;
	}

	bool operator < (const Vector &other) const {
		for (int i = 0; i < M; ++i) {
			if ( get(i) < other.get(i) ) return true;
			if ( get(i) > other.get(i) ) return false;
		}

		return false;
	}

	bool operator == (const Vector &other) const {
		for (int i = 0; i < M; ++i)
			if ( get(i) != other.get(i) ) return false;
		return true;
	}

	int Equals(const Vector &other) const {
		for (int i = 0; i < M; ++i) {
			if ( get(i) < other.get(i) ) return -1;
			if ( get(i) > other.get(i) ) return 1;
		}

		return 0;
	}
};

int N, M;
char **mapa;
int vector[MaxN];

long long dva[MaxN];

Vector vector1[MaxSetSize];
int pvector1;
Vector vector2[MaxSetSize];
int pvector2;

void MakeSet( int start, int end, int M, char **mapa, Vector *vector, int &pvector )
{
	long long maxBitMask = dva[end - start];

	for (int bitmask = 0; bitmask < maxBitMask; ++bitmask) {
		Vector positronVektor = Vector(M);
		
		for (int row = start; row < end; ++row) {
			int index = row - start;
			bool inBitmask = (bitmask >> index) & 1;

			for (int j = 0; j < M; ++j) {
				if ( !inBitmask && mapa[row][j] == 'p' ) positronVektor.add( j, 1 );
				if ( inBitmask && mapa[row][j] == 'e' ) positronVektor.add( j, 1 );
			}
		}

		vector[ pvector++ ] = positronVektor;
	}
}

long long FindSame( Vector *vector, int pvector, int &position, int step )
{
	long long ret = 1LL;
	
	position += step;
	while ( position >= 0 && position < pvector && vector[position-step] == vector[position] ) {
		ret++;
		position += step;
	}

	return ret;
}

long long BrojNacina( int N, int M, char **mapa, int *_vector )
{
	Vector vector = Vector(_vector, M);

	long long ret = 0LL;

	dva[0] = 1LL;
	for (int i = 1; i <= N; ++i)
		dva[i] = 2LL * dva[i-1];

	MakeSet( 0, N/2, M, mapa, vector1, pvector1 );
	MakeSet( N/2, N, M, mapa, vector2, pvector2 );

	sort( vector1, vector1 + pvector1 );
	sort( vector2, vector2 + pvector2 );

	int p1 = 0;
	int p2 = pvector2 - 1;
	
	while ( p1 < pvector1 && p2 >= 0 ) {
		Vector sum = vector1[p1] + vector2[p2];
		
		int equal = sum.Equals(vector);

		if ( equal == -1 ) {
			p1++;
		}
		else if ( equal == 1 ) {
			p2--;
		}
		else {
			long long number1 = FindSame( vector1, pvector1, p1, +1 );
			long long number2 = FindSame( vector2, pvector2, p2, -1 );

			ret += number1 * number2;
		}
	}

	return ret;
}
