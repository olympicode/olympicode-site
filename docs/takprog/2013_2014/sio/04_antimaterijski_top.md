---
hide:
  - toc
---

# 4 - Antimaterijski top

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Profesor Đurić, sada već malo nagluv, je na Tavanu pronašao svoj antimaterijski top iz mladih dana. Oduvavši prašinu, prisetio se eksperimenta koji je nekada izvodio sa njim.
	
	U poljima matrice sa $N$ redova i $M$ kolona nalazili su se pozitroni, elektroni i gravitoni. Svako polje sadržalo je tačno jednu od čestica. Namena antimaterijskog topa bila je da promeni sve elemente u jednom redu njihovim odgovarajućim antičesticama. Pozitron je antičestica elektrona, i ubrnuto, dok je graviton antičestica sam sebi. Cilj eksperimenta bio je da primenom antimaterijskog topa na neke vrste dobijemo unapred određeni broj pozitrona u svakoj koloni. Sada se profesor Đirić pita na koliko načina je to moglo da se uradi.
	
	Izračunajte traženi broj umesto profesora i time mu pomozite da što pre siđe sa Tavana.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju:
	
	* `BrojNacina(N, M, matrica, vektor)`
	
	gde je $N$ - broj redova u matrici, $M$ - broj kolona u matrici, $matrica$ – matrica karaktera dimenzija $N\times M$ gde se na polju $(i,j)$ matrice može nalaziti jedan od sledeća tri karaktera `p`, `e`, `g` koji redom označavaju da se na polju $(i,j)$ nalazi pozitron, elektron ili graviton, $vektor$ – niz dužine $M$ gde $i$-ti broj označava da se nakon upotrebe antimaterijskog topa u koloni $i$ treba nalaziti $vektor[i]$ pozitrona.
	
	## Primer 1
	Neka je $N = 5$, $M = 3$, a matrica neka je data sledećom tabelom:
	
	```
	gee
	epg
	ppg
	gpp
	ege
	```
	
	$vector = \{1, 2, 2\}$
	
	Traženi broj pozitrona po kolona se može dobiti na $3$ načina:
	
	1. Ako primenimo antimaterijski top na vrste $3$ i $5$;
	2. Ako primenimo antimaterijski top na vrste $1$, $2$ i $3$;
	3. Ako primenimo antimaterijski top na vrste $1$, $3$, $4$ i $5$.
	
	## Primer 2
	Neka je $N = 2$, $M = 2$, a matrica data sledećom tabelom:
	```
	pe
	pp
	```
	
	$vector = \{1,1\}$
	
	Traženi broj pozitrona po kolona se ne može dobiti.
	
	## Ograničenja
	
	* $1 \leq N, M \leq 30$.
	* Svaki element matrice će biti iz skupa {`p`, `e`, `g`}.
	
	Podzadaci:
	
	* PODZADATAK $1$ [$11$ POENA]: $1\leq N, M\leq 15$.
	* PODZADATAK $2$ [$15$ POENA]: $M = 1$.
	* PODZADATAK $3$ [$19$ POENA]: Dovoljno je odgovoriti da li postoji barem jedan način da se dobije zadati raspored pozitrona po kolonama. Poeni se dobijaju u slučaju da je broj načina $0$ i vaš program je ispisao $0$, ili ukoliko je broj načina veći od $0$, a vaš program je ispisao
	prirodan broj manji od $10^18$.
	* PODZADATAK $4$ [$55$ POENA] : Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom `top.c`, `top.cpp` ili `top.pas`, koji implementira gore pomenuty funkcijy. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaše funkcije/procedure moraju biti sledećeg oblika:
	```
	C/C++:
	long long BrojNacina(int N, int M, char **mapa, int *vektor);
	Pascal:
	function BrojNacina(N: integer; M: integer; mapa: array of array of char; vector: array of integer)
	```
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (`top.c`, `top.cpp`, `top.pas`) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (`grader.c`, `grader.cpp`, `grader.pas`) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$, $M$ razdvojene razmakom;
	* U narednih $N$ redova po $M$ odgovarajućih karaktera;
	* U poslednjoj liniji $M$ celih brojeva koji predstavljaju promenljivu $vektor$;
	
	zatim pozivaju vašu funkciju `BrojNacina` iz odgovarajućeg fajla (`top.c`, `top.cpp`, `top.pas`) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Savić | Demjan Grubić | Aleksandar Višnjić | Marko Savić |
	
	## Prvi podzadatak
	Generišimo svih $2^N$ vektora koji predstavljaju krajnje zbirove po kolonama nakon korišćenja antimaterijskog topa. Potrebno je za svaki proveriti da li se podudara sa traženim vektorom. Složenost je $O(2^N \cdot M)$.
	
	## Drugi podzadatak
	Potrebno je proveriti na koliko načina možemo izabrati podskup našeg skupa tako da je njegov zbir jednak traženom broju. Pošto je $n\leq 30$, to radimo tehnikom *meet in the middle*: Podelimo naš skup na dve jednake polovine, generižemo svih $2^{\frac{N}{2}}$ mogućnosti za oba skupa, i preko sortiranja i dva pokazivača odredimo koliko ima zbirova dva broja iz oba skupa koji su jednaki datom broju. Složenost je $O(2^{\frac{N}{2}} \cdot N)$.
	
	## Glavno rešenje
	Opet koristimo *meet in the middle*, ali ovaj put mapiramo vektore. Deljenjem matrice na gornji i donji deo koji su približno jednaki možemo generisati sve moguće vektore. Zatim je potrebno proveriti za dva skupa na koliko načina možemo izabrati po jedan vektor iz svakog tako da njihov zbir bude jednak traženom vektoru. To radimo tako što za prvi skup mapiramo sve vektore (map<vector< int>, int>, brojimo koliko ima svakog od vektora) a za svaki vektor iz drugog skupa proveravamo koliko ima vektora iz prvog koji su jednaki razlici traženog vektora i vektora iz drugog skupa. Složenost je $O(2^{\frac{N}{2}}\cdot N \cdot M)$.
	
	
	
	``` cpp title="04_antimaterijski_top.cpp" linenums="1"
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

	```
