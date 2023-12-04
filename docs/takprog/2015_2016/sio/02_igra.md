---
hide:
  - toc
---

# 2 - Igra

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 600ms | 256MB |
	
	Malo ko zna da su Nikola Tesla i Albert Ajnštajn bili jako dobri prijatelji. Svake nedelje je jedan od njih postavljao zagonetke drugome. Ovoga puta je došao red na Alberta da postavi zagonetku. On je zadao zagonetku u obliku igre.
	
	Da bi se igrala igra potrebna je tabla na kojoj se nalazi $N$ polja koja su numerisana brojevima od 1 do $N$ . Ta polja su povezana uz pomoć $M$ puteva, gde svaki put povezuje neka dva polja. Tabla je takva da je moguće krenuti iz bilo kog čvora i koristeći date puteve doći do bilo kog drugog čvora. Na početku igre, svaka od $K$ figurica (označene brojevima od 1 do $K$) se postavi na njeno početno polje i takođe se za svaku od tih figurica obeleži i krajnje polje, tj. polje gde ta figurica mora da se nađe na kraju igre.
	
	U jednom potezu, Tesla mora da pomeri svaku figuricu sa polja gde se ta figurica nalazi na neko susedno polje. Dva polja su susedna ukoliko među datih $M$ puteva, postoji put koji spaja ta dva polja. Na jednom polju u isto vreme može da se nalazi više figurica. Poenta igre je da se sve figurice u isto vreme nađu na njihovim krajnjim pozicijama. Primetimo da ukoliko je neka figurica pre kraja na svojoj krajnjoj poziciji, ona u sledećem potezu mora da se pomeri sa te pozicije.
	
	Dobro je poznato da su njih dvojica računali dane drugačije nego što smo navikli, njihovih nedelju dana je trajalo $D$ dana, umesto nama dobro poznatih 7.
	
	Prvi dan u njihovoj nedelji, Albert je poslao postavku igre Tesli, tj. tablu i obeležena početna i krajnja polja za svaku figuricu. Postavio mu je uslov da svaki dan mora da odigra tačno jedan potez i tražio je od njega da mu kaže za svaki dan u njihovoj nedelji koji je najmanji broj poteza (dana) koje Tesla mora da odigra kako bi sve figurice bile na svojim krajnjim pozicijama baš na taj dan u nedelji.
	
	Dobili ste postavku igre i znate da je Tesla uspešno dao odgovor za svaki dan u njihovoj nedelji. Vaš zadatak je da otkrijete koje je odgovore Tesla poslao Ajnštajnu.
	
	## Opisi funkcija
	
	Potrebno je implementirati funkciju
	
	$$
	Igra(N,M,K,D,U[...],V[...],S[...],F[...],R[...])
	$$
	
	gde je:
	
	*  $N$ – broj polja na tabli
	*  $M$ – broj puteva između polja
	*  $K$ – broj figurica na tabli
	*  $D$ – broj dana u Albertovoj i Nikolinoj nedelji
	*   $U$ i $V$ – nizovi dužine $M$, gde znamo da su polja označena brojevima $U_i$ i $V_i$ povezana putem na tabli
	* $S$ i $F$ – nizovi dužine $K$, gde $i$-ti elementi niza označavaju redni broj početnog i krajnjeg polja za $i$-tu figuricu, redom.
	
	Funkciji se takođe prosleđuje i parametar $R$ koji predstavlja niz dužine $D$, kroz koji treba da vratite vaše rešenje. Po završetku funkcije, i-ti element niza $R$ treba da ima vrednost minimalnog broja dana (poteza) tako da sve figurice budu na svojim krajnjim pozicijama na dan i u nedelji. Ukoliko za neki dan u nedelji nije moguće da se sve figurice nađu na istom mestu, rešenje za taj dan treba da bude -1.
	
	Svi nizovi su indeksirani od 0, što znači da je prvi element nizova onaj sa indeksom 0. Voditi računa da pošto su svi nizovi indeksirani od 0, $R_0$ treba da predstavlja rešenje za dan 1, $R_1$ za dan 2, itd...
	
	## Primer:
	
	Neka postoji $N=6$ polja, povezana uz pomoć $M=7$ puteva koji su opisani uz pomoć nizova $U=\{1,1,2,3,4,4,5\}$ i $V=\{2,3,4,4,5,6,6\}$. Neka postoji $K=2$ figurice gde su početne i krajnje pozicije date uz pomoć nizova $S=\{1,4\}$ i $F=\{2,5\}$, i neka nedelja traje $D=3$ dana. Na slici ispod možete videti prikaz takve table.
	
	![](https://lh7-us.googleusercontent.com/UAwpuOW9W5lZcVD05vSQf1BXL6wB1TL-hLZni_sDxHGajIAZOYB6IyRxEY7Z725QgkMj-I8M9cCEi_FBGMI5oLb20IOXyznlFgYTJjAm2BlxkbQJbgNdUwrrTOi4KXs7Me1Eg5m3G7F7up2ilRuq2g)
	
	Prva figurica počinje na polju 1 i treba da završi na polju 2, dok druga figurica počinje na polju 4 i treba da završi na polju 5.
	
	Nedelja ima 3 dana i za svaki od tih dana treba da ispišemo najmanji broj poteza da bi obe figurice bile na krajnjim pozicijima baš na taj dan u nedelji.
	
	-   Dan 1 - najmanji broj poteza je 3. Jedno moguće rešenje je da prva figurica pravi šetnju: polje 1 (dan 1) polje 3 (dan 2) polje 4 (dan 3) polje 2 (dan 1), dok druga pravi šetnju: polje 4 (dan 1) polje 6 (dan 2) polje 4 (dan 3) polje 5 (dan 1). 
	-   Dan 2 - najmanji broj poteza je 1. Jedno moguće rešenje je da prva figurica pravi šetnju: polje 1 (dan 1) polje 2 (dan 2), dok druga pravi šetnju: polje 4 (dan 1) polje 5 (dan 2). 
	-   Dan 3 - najmanji broj poteza je 5. Jedno moguće rešenje je da prva figurica pravi šetnju: polje 1 (dan 1) polje 3 (dan 2) polje 4 (dan 3) polje 3 (dan 1) polje 4 (dan 2) polje 2 (dan 3), a druga šetnju: polje 4 (dan 1) polje 6 (dan 2) polje 4 (dan 3) polje 6 (dan 1) polje 4 (dan 2) polje 5 (dan 3).
	    
	## Ograničenja
	
	-   $1≤N≤1000$
	-   $1≤M\leq 100.000$
	-   $1≤K≤100$
	-   $1≤D≤1000$
	-   $1≤U_i,V_i \leq N$, za svako $0≤i \leq M$
	-   $1≤S_i,F_i \leq N$, za svako $0≤i \leq K$
	    
	
	## Podzadaci i bodovanje
	
	-   PODZADATAK 1 [10 POENA]: Između svaka dva polja na tabli postojaće tačno jedan put (dato je stablo) i važi $K=1$.
	-   PODZADATAK 2 [15 POENA]: Između svaka dva polja na tabli postojaće tačno jedan put (dato je stablo).
	-   PODZADATAK 3 [25 POENA]: $D≤10,K≤10$ i $D$ je paran broj.
	-   PODZADATAK 4 [10 POENA]: $D≤10,K≤10$
	-   PODZADATAK 5 [40 POENA]: Nema dodatnih ograničenja
	    
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom igra.c, igra.cpp ili igra.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	C/C++
	void Igra(int N, int M, int K, int D, int* U, int* V, int* S, int* F, int* R);
	
	Pascal
	procedure Igra(N, M, K, D : longint; var U, V, S, F, R : array of longint);
	
	  
	Ukoliko radite u C/C++ -u, potrebno je na početku fajla staviti #include “igra.h” a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti Unit igra; (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	  
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam “template” fajlovi (igra.c, igra.cpp, igra.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	1.  U prvom redu brojeve $N,M,K$  i $D$.    
	2.  U sledećih $M$ redova brojeve $U_i$ i $V_i$, redom, razdvojene razmakom
	3.  U narednih $K$ redova brojeve $S_i$ i $F_i$, redom, razdvojene razmakom
	
	a zatim pozivaju vašu funkciju Igra iz odgovarajućeg fajla (igra.c, igra.cpp, igra.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Demjan Grubić | Demjan Grubić | Aleksandar Višnjić | Boris Grubić |
	
	
	## Podzadatak 1
	Stablo ima svojstvo bipartitivnosti: svaki čvor se može obojiti u crno ili belo tako da susedni čvorovi uvek imaju različitu boju. Jedan potez po uslovu zadatka uvek menja boju na kojoj se figurica nalazi. Možemo napraviti sledeću trdnju: ako je $W$ najkraći put između neka dva čvora $U$ i $V$, onda su moguće dužine svih ostalih puteva (koji mogu biti samo-presecajući) $W+2,W+4,W+6,...$
	Putevi kraći od $W$ ne postoje, a putevi čija je dužina drugačije parnosti od $W$ takođe ne postoje zbog bipartitivnosti. Svi ostali postoje jer je uvek moguće izaći iz čvora i vratiti se u njega za $2$ poteza.
	
	Najkraći putevi iz svakog čvora mogu se naći efikasno i jednostavno bilo kojim algoritmom za pretraživanje celog stabla u složenosti $O(N)$. Ostalo je samo ciklično proveriti koji dani su mogući i odrediti odgovarajuće parnosti. Vremenska složenost je $O((N+M+D)\cdot K)$, a memorijska 
	$O(N^2+K)$ ili $O(N+M+K)$.
	
	## Podzadatak 2
	Koristićemo isto rešenje kao u prethodnom podzadatku, samo je potrebno još i proveriti da li dužine najkraćih puteva imaju istu parnost. Ako je dat uslov ispunjen, onda je moguće da se sve figurice nađu na svojim krajnjim pozicijama nakon $max(W_i)$ poteza, gde je $W_i$ dužina najkraćeg puta od $U_i$ do $V_i$.
	
	## Podzadaci 3,4 i 5
	Graf više ne mora da bude bipartitivan, ali možemo napraviti novi koji će biti: svaki čvor u njemu numerišemo isto kao i u prethodnom, ali čuvamo crnu i belu verziju. Grane su iste, ali povezujemo isključivo susedne čvorove sa suprotnim bojama verzija. Novi graf će biti duplo veći po broju čvorova i grana i bipartitivan. Možemo pretpostaviti da sve figurice kreću iz belog čvora i treba da stignu u odgovarajući čvor proizvoljne boje. Bitno je da svaka figurica završi u čvoru iste boje (tj. da im dužine puteva imaju istu parnost). Ostalo je naći najkraći put od bele verzije $U_i$ do obe verzije $V_i$. (Ili odrediti da put ne postoji) Opet ćemo računati $max(W_i)$ i parnost kao u prethodnim podzadacima, ali ovog puta to moramo uraditi odvojeno za samo za crne i samo za bele krajeve figurica. 
	
	Efikasna implementacija koristi pretragu po širini da nađe najkraći put od svakog početnog polja figurica do svakog drugog čvora. Vremenska složenost je $O((N+M+D)\cdot K)$, a memorijska $O(N+M+K)$. Manje efikasne implementacije ili izostavljanje računanja određenih parnosti mogu rešiti i prethodne podzadatke. 
	
	``` cpp title="02_igra.cpp" linenums="1"
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

	```
