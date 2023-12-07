---
hide:
  - toc
---

# 1 - RNK

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Nekako ste se našli uposleni na projektu proizvodnje najnovije RNK
	vakcine, gde radite na prototipu koji se može opisati kao niz od $N$
	kodona, odnosno karaktera koji mogu biti `A`, `C`, `G`, i `U`.
	Proizvedena vakcina će biti stabilna samo ako ne sadrži previše istih
	kodona. Konkretno, smatramo je stabilnom ako se **ni jedan kodon ne
	pojavljuje strogo više od $\frac{N}{2}$ puta**.
	
	Na raspolaganju vam je RNKpopravljač, uređaj koji treba iskoristiti
	tačno jednom i koji će **obrnuti sve kodone u datom intervalu** tako
	što `A` pretvori u `U` i obrnuto, a `C` u `G` i obrnuto. Vaš zadatak
	je da odredite da li je ovim putem moguće od prototipa dobiti stabilnu
	vakcinu (i kako).
	
	Nažalost, izgubili ste beleške, tako da ne znate kako prototip
	izgleda. Na raspolaganju vam je skener, kojim možete da ispitate
	**koliko puta se neki kodon pojavljuje u nekom intervalu prototipa**.
	Pošto ste u žurbi, skener možete koristiti ograničen broj puta.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $\text{Resi}(N, L, R)$
	
	gde je:
	
	* $N$ broj kodona u prototipu.
	* $L$ i $R$ promenljive u koje treba da upišete indekse prvog i
	  poslednjeg kodona koje ćete obrnuti RNKpopravljačem. Ukoliko nije
	  moguće dobiti stabilnu vakcinu ovim putem, upišite $L = R = -1$.
	
	Vaš program može da koristi funkciju
	
	$\text{Skener}(L, R, C)$
	
	koja će vratiti broj pojavljivanja kodona $C$ u intervalu $[L, R]$
	prototipa (uključujući i $L$-ti i $R$-ti).
	
	**Nizovi su indeksirani od 1.**
	
	## Ograničenja
	Test primeri su podeljeni u nekoliko podzadataka. U svakom podzadatku
	je dato ograničenje $Q$, koje predstavlja dozvoljen broj poziva funkcije
	$\text{Skener}$.
	
	* **[10 poena]:** $N \leq 1000$, $Q = 4000$
	* **[15 poena]:** $N \leq 10^5$, $Q = 3 \times 10^5 + 10$
	* **[15 poena]:** $N \leq 10^5$, $Q = 2 \times 10^5 + 10$
	* **[20 poena]:** $N \leq 10^5$, $Q = 1.5 \times 10^5 + 50$
	* **[40 poena]:** $N \leq 10^5$, $Q = 36$
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `rnk.cpp` koji implementira
	pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i
	dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int *L, int *R)`
	
	Vaš program mora uključivati header `code.h`, u kom je definisana
	funkcija $\text{Skener}$ sledećeg potpisa:
	
	`int Skener(int L, int R, char C)`
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete
	koristiti i menjati po potrebi. Takođe vam je obezbeđen program
	`grader.cpp` koji služi da lakše testirate kodove. ovaj program
	učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$ i $Q$.
	* U narednom redu string dužine $N$ koji predstavlja prototip (sačinjen
	  isključivo od velikih slova `A`, `C`, `T` i `U`).
	
	Zatim ovaj program poziva vašu funkciju i štampa vrednosti $L$ i $R$
	koje je funkcija popunila u jednom redu, i broj poziva funkcije
	$\text{Skener}$ u drugom. Ukoliko vaše rešenje koristi skener više od
	$Q$ puta, biće prekinuto sa statusom `RTE` (runtime error).
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Mladen Puzić | Dimitrije Erdeljan | Mladen Puzić | Tadija Šebez |
	
	## Podzadatak 1
	Koristeći $4N$ upita, možemo odrediti ceo prototip (za svaku poziciju možemo da pitamo koliko ima svakog slova na toj poziciji). Nakon toga možemo probati svaki interval za promenu, videti da li daje validnu vakcinu. Vremenska/memorijska složenost: $O(N^2)$, broj poziva funkciji: $4N$. 
	
	## Podzadatak 2
	Slično prethodnom podzadatku, možemo otkriti ceo prototip, ali ovaj put smemo koristiti najviše $3$ upita po poziciji. To nije problem, jer možemo pitati za tri kodona, ako nijedan ne važi, znamo da je u pitanju četvrti kodon.  Odredimo kodon koji se pojavljuje više od $\frac{N}{2}$ puta, recimo da se pojavljuje $x$ puta, dok se njegov komplement pojavljuje $y$ puta. Želimo da se najčešći kodon u našem intervalu pojavljuje makar $\frac{x-y}{2}$ puta više od komplementa. Ne sme da se pojavljuje ni previše puta, jer onda njegov komplement postaje element koji se pojavljuje više od $\frac{N}{2}$ puta, srećom u većini slučajeva možemo naći baš interval u kom se najčešći kodon pojavljuje **tačno** $\lceil\frac{x-y}{2}\rceil$ puta više od komplementa. Jedini slučaj u kojem to nije moguće je ukoliko je $N$ neparan broj i važi $x+y=N$, u tom slučaju koji god interval da izaberemo, postojaće element koji se pojavljuje više od $\frac{N}{2}$ puta, pa rešenje ne postoji. 
	
	Ukoliko to nije slučaj, postoji odgovarajući interval, i to odgovarajući interval koji je i prefiks. Nazovimo sa $f(i)$ razliku broja pojavljivanja   najčešćeg elementa i njegovog komplementa u prvih $i$ elemenata. Jasno je da važi $f(0) = 0$ i $f(N) = x-y$. Kako se $f(i)$ i $f(i+1)$ razlikuju za najviše $1$, možemo reći da je u nekom smislu ova funkcija *neprekidna*, tj. postoje indeksi za koje iznosi $0$ i $x-y$, postoje i indeksi gde iznosi i bilo šta između toga, uključujući i $\lceil\frac{x-y}{2}\rceil$. Samim tim, postoji prefiks koji nam odgovara, i možemo ga jednostavno naći. 
	
	Vremenska/memorijska složenost: $O(N)$, broj poziva funkciji: $3N$. 
	
	## Podzadatak 3
	Ovaj podzadatak veoma je sličan prethodnom, nećemo direktno odrediti ceo prototip, nego ćemo iskoristiti $3$ poziva funkciji da za svaki kodon odredimo koliko puta se pojavljuje, tj. da odredimo koji kodon se pojavljuje najviše puta. Kada imamo tu informaciju, možemo da izračunamo $f(i)$ sa dva poziva funkciji. Možemo da izračunamo $f(i)$ i odaberemo ono koje nam odgovara. Vremenska/memorijska složenost: $O(N)$, broj poziva funkciji: (najviše) $2N+3$. 
	
	
	## Podzadatak 4
	Nađimo koliko se koji kodon pojavljuje, odnosno koji se pojavljuje najčešće. Nađimo sva pojavljivanja njegovog komplementa u nizu koristeći do sad ukupno $N+3$ poziva funkciji. Tih pojavljivanja može biti najviše $\frac{N}{2}$. Za svaki prefiks koji se završava na jednom od ovih pojavljivanja, otkrijmo koliko se puta do njega pojavljuje najčešći kodon. Ova informacija nam, zbog *neprekidnosti* naše funkcije, pomaže da odredimo između koja dva pojavljivanja se nalazi prefiks koji tražimo. Kada nađemo tu informaciju, možemo uraditi binarnu pretragu, da nađemo tačan potreban indeks. Vremenska/memorijska složenost: $O(N)$, broj poziva funkciji: (najviše) $1.5N+\lceil logN\rceil+3$. 
	
	## Glavno rešenje
	Koristićemo binarnu pretragu da nađemo $i$ za koje važi $f(i) = \lceil\frac{x-y}{2}\rceil$. Znamo $f(0) = 0$ i $f(N) = x-y$, proveravamo $f(mid)$. Važiće da će se $\lceil\frac{x-y}{2}\rceil$ nalaziti ili između $f(l)$ i $f(mid)$ ili između $f(mid)$ i $f(r)$ (možda i na oba mesta, ali nama je dovoljno jedno). Ovo važi po *neprekidnosti* naše funkcije. Onda nastavljamo binarnu pretragu u delu koji sadrži vrednost koju tražimo.  Vremenska/memorijska složenost: $O(logN)$, broj poziva funkciji: (najviše) $2\lceil logN\rceil+3$.
	
	``` cpp title="01_rnk.cpp" linenums="1"
	#include "code.h"
	#include <cstdio>
	
	int delta(char a, char b, int k) {
	    return Skener(1, k, a) - Skener(1, k, b);
	}
	
	void solve(int n, char a, int na, char b, int nb, int *L, int *R) {
	    if(na + nb == n && n % 2 == 1) {
	        *L = *R = -1;
	    } else {
	        int mindelta = na - n/2;
	        int maxdelta = n/2 - nb;
	
	        int lo = 1, hi = n;
	        while(lo < hi) {
	            int mid = (lo + hi) / 2;
	            int d = delta(a, b, mid);
	
	            if(mindelta <= d && d <= maxdelta) {
	                *L = 1; *R = mid;
	                return;
	            } else {
	                if(d < mindelta) {
	                    lo = mid + 1;
	                } else {
	                    hi = mid - 1;
	                }
	            }
	        }
	
	        *L = 1; *R = lo;
	    }
	}
	
	void Resi(int N, int *L, int *R) {
	    int a, c, g, u;
	    a = Skener(1, N, 'A');
	    c = Skener(1, N, 'C');
	    g = Skener(1, N, 'G');
	    u = N - a - c - g;
	
	    if(a + u > c + g) {
	        if(a > u) {
	            solve(N, 'A', a, 'U', u, L, R);
	        } else {
	            solve(N, 'U', u, 'A', a, L, R);
	        }
	    } else {
	        if(c > g) {
	            solve(N, 'C', c, 'G', g, L, R);
	        } else {
	            solve(N, 'G', g, 'C', c, L, R);
	        }
	    }
	}

	```
