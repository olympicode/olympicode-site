#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 10000;
const int MaxK = 8;
const int MaxM = 500;
const int MaxKombZaIgracaZaILoptica = 70; // binom(MaxK, MaxK/2)

int N; // broj ljudi
int K; // broj kuglica koje se izvlace
int M; // kuglice imaju brojeve {1, 2, 3, ..., M}
int Q; // broj izvlacenja

int kombIgraca[MaxN][MaxK];

int trenutnoElemenata[MaxK+1];
int sveMoguceKombinacije[MaxK+1][MaxN*MaxKombZaIgracaZaILoptica][MaxK];
int komb[MaxK];

int firstElement[2][MaxM+1];
int lastElement[2][MaxM+1];
int nextElement[2][MaxN*MaxKombZaIgracaZaILoptica];

int sortiranRaspored[MaxK+1][MaxN*MaxKombZaIgracaZaILoptica];

/*
O(N*K*logK) ili O(N*K^2)
*/
void UlazIgraci()
{
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			scanf("%d",&kombIgraca[i][j]);
		}

		// nije bitno koji sort
		// posto sortiramo K elemenata
		sort(kombIgraca[i], kombIgraca[i]+K);
	}
}

/*
O(N*K*2^K)
*/
void UbaciUNizove()
{
	memset(trenutnoElemenata, 0, sizeof(trenutnoElemenata));

	for (int i = 0; i < N; ++i) {
		int bitmaskEnd = (1 << K);
		for (int bitmask = 1; bitmask < bitmaskEnd; ++bitmask) {
			int cntBit = 0;
			for (int bit = 0; bit < K; ++bit) {
				if ((bitmask >> bit) & 1) {
					komb[cntBit++] = kombIgraca[i][bit];
				}
			}

			for (int j = 0; j < cntBit; ++j) {
				sveMoguceKombinacije[cntBit][trenutnoElemenata[cntBit]][j] = komb[j];
			}
			trenutnoElemenata[cntBit]++;
		}
	}
}

/*
O(SUM_{i=1..K} i*(binom(K, i)*N+M)) ~ O(K*N*2^K + K^2*M)
*/
void SortSveNizove()
{
	for (int brojLoptica = 1; brojLoptica <= K; ++brojLoptica) {

		int now = 0;
		int prev = 1;

		memset(firstElement, -1, sizeof(firstElement));
		memset(lastElement, -1, sizeof(lastElement));
		for (int i = 0; i < trenutnoElemenata[brojLoptica]; ++i) {
			if (lastElement[prev][1] == -1) {
				firstElement[prev][1] = lastElement[prev][1] = i;
			}
			else {
				nextElement[prev][ lastElement[prev][1] ] = i;
				lastElement[prev][1] = i;
			}

			nextElement[prev][i] = -1;
		}

		for (int trenIdx = brojLoptica-1; trenIdx >= 0; --trenIdx) {
			for (int i = 1; i <= M; ++i) {
				for (int j = firstElement[prev][i]; j != -1; j = nextElement[prev][j]) {
					int idxNiza = j;
					int vrednost = sveMoguceKombinacije[brojLoptica][idxNiza][trenIdx];

					if (lastElement[now][vrednost] == -1) {
						firstElement[now][vrednost] = lastElement[now][vrednost] = idxNiza;
					}
					else {
						nextElement[now][ lastElement[now][vrednost] ] = idxNiza;
						lastElement[now][vrednost] = idxNiza;
					}

					nextElement[now][idxNiza] = -1;
				}
			}

			memset(firstElement[prev], -1, sizeof(firstElement[prev]));
			memset(lastElement[prev], -1, sizeof(lastElement[prev]));

			now = 1 - now;
			prev = 1 - prev;
		}

		int trenElement = 0;
		for (int i = 1; i <= M; ++i) {
			for (int j = firstElement[prev][i]; j != -1; j = nextElement[prev][j]) {
				int idxNiza = j;
				sortiranRaspored[brojLoptica][trenElement++] = idxNiza;
			}
		}
	}
}

/*
O(log(binom(K, K/2) * N)) ~ O(N*logN)
*/
int BinarySearch(int vrednostTrazeneKuglice, int idxKuglice, int donjaGranica, int gornjaGranica, bool prvi, int brojKuglica)
{
	int left = donjaGranica;
	int right = gornjaGranica;

	while (right - left) {
		int mid = (left + right) / 2;
		int idxUNesortitanomNizu = sortiranRaspored[brojKuglica][mid];
		int vrednostKugliceUNizu = sveMoguceKombinacije[brojKuglica][idxUNesortitanomNizu][idxKuglice];

		if (prvi) {
			if (vrednostKugliceUNizu >= vrednostTrazeneKuglice) right = mid;
			else 												left = mid + 1;
		}
		else {
			if (vrednostKugliceUNizu > vrednostTrazeneKuglice) right = mid;
			else 											   left = mid + 1;
		}
	}

	// ako trazimo poslednji
	// onda moramo smanjiti pokazivac za 1
	if (donjaGranica != gornjaGranica) {
		int idxUNesortitanomNizu = sortiranRaspored[brojKuglica][left];
		int vrednostKugliceUNizu = sveMoguceKombinacije[brojKuglica][idxUNesortitanomNizu][idxKuglice];
		if (!prvi && (vrednostKugliceUNizu != vrednostTrazeneKuglice)) {
			left--;
		}
	}

	if (left == -1) return -1;

	int idxUNesortitanomNizu = sortiranRaspored[brojKuglica][left];
	int vrednostKugliceUNizu = sveMoguceKombinacije[brojKuglica][idxUNesortitanomNizu][idxKuglice];

	if (vrednostTrazeneKuglice != vrednostKugliceUNizu) return -1;
	return left;
}

/*
O(K*log(binom(K, K/2) * N)) ~ O(K*K*logN) (gubi se dosta na uproscavanju verovatno)
*/
int BinarySearchNiz(int brojKuglica, int *trazenNiz)
{
	int donjaGranica = 0;
	int gornjaGranica = trenutnoElemenata[brojKuglica] - 1;

	for (int trenutnoPoredimKuglicu = 0; trenutnoPoredimKuglicu < brojKuglica; ++trenutnoPoredimKuglicu) {
		int trenutnaKuglicaKojaSeTrazi = trazenNiz[trenutnoPoredimKuglicu];

		int tmp_donjaGranica  = BinarySearch(trenutnaKuglicaKojaSeTrazi, trenutnoPoredimKuglicu, donjaGranica, gornjaGranica, true, brojKuglica);
		int tmp_gornjaGranica = BinarySearch(trenutnaKuglicaKojaSeTrazi, trenutnoPoredimKuglicu, donjaGranica, gornjaGranica, false, brojKuglica);

		donjaGranica = tmp_donjaGranica;
		gornjaGranica = tmp_gornjaGranica;

		if (donjaGranica == -1) return 0;
	}

	return gornjaGranica - donjaGranica + 1;
}

/*
O(Q*K*log(binom(K, K/2) * N)) ~ O(Q*K*K*logN)
*/
void UcitajIOdradiUpite()
{
	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q) {
		for (int i = 1; i <= K; ++i) {
			scanf("%d", &komb[i-1]);

			// nije bitno kako cemo sortirati
			sort(komb, komb+i);
			int resenje = BinarySearchNiz(i, komb);

			if (i > 1) {
				printf(" ");
			}
			printf("%d", resenje);
		}
		printf("\n");
	}
}

/*
O(SUM_{i=1..K] i*(binom(K, i)*N+M)) ~ O(K*N*2^K + K^2*M)
+
O(Q*K*log(binom(K, K/2) * N)) ~ O(Q*K*K*logN)
~~~~~~~~~~~~~~
O(K*N*2^K + K^2*M + Q*K^2*logN)

ukoliko se koristi sort()
~ O(K*N*2^K*(K*logN) + Q*K^2*logN)
*/
int main()
{
	UlazIgraci();
	UbaciUNizove();
	SortSveNizove();
	UcitajIOdradiUpite();

	return 0;
}
