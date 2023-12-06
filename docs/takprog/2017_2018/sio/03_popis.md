---
hide:
  - toc
---

# 3 - Popis

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 512MB |
	
	Ena radi u poznatom supermarketu koji je dobio ime po jednoj komutativnoj binarnoj operaciji na skupu realnih brojeva. Nedavno je supermarket obijen pa je potrebno izvršiti popis robe. Supermarket se može predstaviti kao matrica sa $N$ redova i $M$ kolona. Redovi i kolone su indeksirani od $1$. U supermarketu se prodaje $V$ vrsta robe, koje označavamo brojevima od $1$ do $V$. Ena je dobila zadatak da tokom nekih od narednih $Q$ dana popiše neku pravougaonu podmatricu. Njoj je šef dao spisak $B$ od $V$ brojeva, gde $B_i$ označava da artikal pod rednim brojem $i$ treba u podmatrici da se nađe tačno $B_i$ puta. Enin zadatak je da za neku podmatricu odredi koliko vrsta artikala postoji tako da se taj artikal nalazi u toj podmatrici tačno $B_i$ puta, odnosno, koliko različitih vrednosti $i$ postoji tako da se broj $i$ pojavljuje tačno $B_i$ puta u podmatrici. Međutim, tu nije kraj Eninim mukama! Zli duhovi s vremena na vreme vade artikle sa nekih mesta u matrici i stavljaju neke druge artikle (tokom tih dana Ena ne mora da popisuje robu). Ena ima puno obaveza pa je ovaj zadatak poverila vama.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $Resi(N, M, Q, V, A[\ldots][\ldots], B[\ldots], X1[\ldots], Y1[\ldots], X2[\ldots], Y2[\ldots], O[\ldots])$
	
	koja treba da obradi sve upite i da smesti rešenja upita u niz $O$. Matrica $A$ sadrži brojeve od $1$ do $V$ i opisuje početno stanje supermarketa. Nizovi $X1, Y1, X2, Y2$ opisuju upite. Ukoliko je $Y2[i] = -1$, tog dana je zli duh ušao u supermarket i promenio artikal na poziciji $(X1[i], Y1[i])$ u artikal sa rednim brojem $X2[i]$. U suprotnom, ako je $Y2[i] \neq -1$, tog dana Ena treba da popiše robu. **Ako postoji $T$ upita koji označavaju da se roba popisuje, odgovore na ove upite upišite u istom redosledu u niz $O$ na pozicijama od $1$ do $T$. Svi nizovi su indeksirani od 1.**
	
	## Primer 1
	Neka je $N = 3, M = 4, Q = 3, V = 4$, niz $B = [1, 2, 3, 4]$, a matrica $A$ je:
	```
	1 2 3 2
	2 3 1 3
	3 1 1 4
	```
	
	Prvog dana, Ena treba da popiše podmatricu od polja $(1,2)$ do polja $(3,4)$, odnosno, podmatricu koja se sastoji od poslednje tri kolone. Ena vidi da se artikal $1$ nalazi tri puta, artikal $2$ se nalazi dva puta, artikal $3$ se nalazi $3$ puta i artikal $4$ se nalazi jednom u ovoj podmatrici. Od svih njih artikli $2, 3$ se nalaze ispravan broj puta - artikal $2$ treba da se javi $B_2 = 2$ puta, a artikal $3$ treba $B_3 = 3$ puta, pa je odgovor $2$. Drugog dana, zli duh menja artikal u donjem desnom uglu matrice u artikal $2$, pa će sledećeg dana samo jedan artikal (sa rednim brojem $3$) da se nađe ispravan broj puta.
	
	## Ograničenja
	
	+ $N, M \leq 840$.
	+ $Q \leq 10000$.
	+ $V \leq 100000$.
	+ $1 \leq A_{i, j} \leq V$.
	+ $0 \leq B_i \leq N \cdot M$.
	+ U upitima kod kojih je $Y_2 = -1$ važi $1 \leq X_1 \leq N, 1 \leq Y_1 \leq M, 1 \leq X_2 \leq V$.
	+ U ostalim upitima važi $1 \leq X_1 \leq X_2 \leq N, 1 \leq Y_1 \leq Y_2 \leq M$.
	
	## Podzadaci
	
	+ Podzadatak $1$ [$7$ poena]: $N, M, Q, V \leq 100$.
	+ Podzadatak $2$ [$12$ poena]: $V \leq 100$, nema zlih duhova.
	+ Podzadatak $3$ [$15$ poena]: $V \leq 50$.
	+ Podzadatak $4$ [$17$ poena]: $Q \leq 400$.
	+ Podzadatak $5$ [$21$ poen]: $N, M \leq 400$.
	+ Podzadatak $6$ [$28$ poena]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `popis.cpp` ili `popis.pas`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	U zavisnosti od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	| Jezik   | Deklaracija funkcije                                                                                    | 
	| ------- | ------------------------------------------------------------------------------------------------------- |
	| C++     | `void Resi(int N, int M, int Q, int V, int** A, int* B, int* X1, int* Y1, int* X2, int* Y2, int* O);`   |
	| Pascal  | `procedure Resi(N, M, Q, V : Longint; var A : Matrica; var B, X1, Y1, X2, Y2, O : Array of Longint);`   |
	
	Za `Pascal`, `Matrica` je tip koji je definisan kao `Array[1..1000, 1..1000] of Longint`.
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova**.
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam "template" fajlovi `code.cpp` i `code.pas` koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi `grader.cpp`, `grader.pas` koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu brojeve $N, M, Q, V$,
	+ U narednih $N$ redova po $M$ brojeva, elemente matrice $A$,
	+ U narednom redu $V$ brojeva, elemente niza $B$,
	+ U narednih $Q$ redova 4 ili 5 brojeva:
	+ + Prvi broj je tip upita (1 - popis, 2 - zli duh)
	+ + U slučaju popisa preostala 4 broja su $X1, Y1, X2, Y2$.
	+ + U slučaju zlog duha 3 broja, $X, Y, Z$, $(X, Y)$ je pozicija u matrici a $Z$ je nova vrednost.
	
	Zatim ovaj program zove vašu funkciju i štampa brojeve $O[1], \ldots, O[T]$, svaki u posebnom redu, gde je $T$ broj "popis" upita. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dušan Zdravković | Dragan Urošević | Ivan Stošić i Aleksa Plavšić |
	
	Razmislimo prvo kako bismo rešili zadatak u slučaju da nije data matrica već niz vrednosti i da nema izmena niza, pa ćemo ovo rešenje uopštiti. Jasno je da se nameće [Mo-ov algoritam](http://codeforces.com/blog/entry/7383) kao potencijalno rešenje. Vrlo jednostavno možemo održavati za svako $i, 1 \leq i \leq V$ broj $C_i$ - koliko puta se vrednost $i$ javlja u trenutnom prozoru i takođe za koliko različitih vrednosti $i$ važi da su jednake $C_i, B_i$, neka je taj broj $Z$. U $1$-dimenzionoj varijanti vremenska složenost bi bila $O(N \sqrt{N} + Q)$.
	
	## Generalizacija u više dimenzija i izmene
	
	Posmatrajmo 5-dimenzioni prostor, gde 4 dimenzije odgovaraju pozicijama $(x_1, y_1, x_2, y_2)$ prozora dok poslednja dimenzija odgovara rednom broju upita. Posmatrajmo koliko nam elementarnih koraka treba da od tačke $(x_1, y_1, x_2, y_2, t)$ dođemo do tačke $(x_1', y_1', x_2', y_2', t')$. Kroz prostorne dimenzije se krećemo tako što povećavamo ili smanjujemo vrednosti $x_1, y_1, x_2, y_2$. Da bismo jednu od njih promenili za tačno jedan, treba nam onoliko vremena kolika je širina prozora u drugoj dimenziji (toliko vrednosti biva ubačeno tj. izbačeno). Kretanje kroz vreme je jednostavnije, ukoliko je pozicija prozora fiksna, samo posmatramo da li vrednost koja se menja u trenutku $t$ upada u prozor. Ako ne upada, samo je promenimo u matrici a ako upada dodatno ažuriramo vrednosti $C_i, Z$. Sada, izdelimo ceo ovaj prostor na blokove, koji u prostornoj dimenziji imaju širinu $\frac{D}{N}$ a u vremenskoj $D$. Unutar jednog bloka moguće je doći od bilo koje do bilo koje druge tačke u ne više od $5D$ elementarnih koraka. Od jednog bloka do susednog bloka moguće je doći u $D$ elementarnih koraka. Najzad, rasporedimo upite u blokove i rešavamo upite iz jednog bloka, pa iz nekog od susednih blokova, i tako dalje. Ukupan broj elementarnih koraka potreban da se reše svi upiti je ne veći od $DW + 5DQ$, gde je $W = \frac{N^4Q}{(\frac{D}{N})^4 D} = \frac{N^8Q}{D^5}$ broj blokova. Sada, nađimo najbolju veličinu bloka. Ovo se može uraditi prostim isprobavanjem različitih vrednosti $D$ ali se dobra procena može naći matematički. Nađimo izvod izraza $DW + 5DQ$ po $D$. On iznosi $5Q - \frac{4N^8 Q}{D^5}$. Ako ga izjednačimo sa nulom i rešimo po $D$, dobićemo vrednost koja minimizuje vreme izvršenja. Rezultat je $D \approx 0.956 N^\frac{8}{5}$, odnosno, za $N=840, D \approx 45600$. Pošto je $Q \leq 10000$ ovo znači da ne moramo da delimo u blokove po vremenskoj dimenziji, dok u prostornoj delimo na blokove širine $\approx 54$, najbliži delilac broja $840$ je $56$. Vremenska složenost rešenja je $O(Q N^\frac{8}{5})$.
	
	``` cpp title="03_popis.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	const int MAXN = 840;
	const int MAXQ = 10000;
	const int MAXV = 100000;
	
	const int PRAVOUGAONIK = 1;
	const int IZMENA = 2;
	
	const int D = 60; // velicina bloka
	const int K = 14;
	
	int n, m, q, v;
	
	int a[MAXN][MAXN];
	int a_orig[MAXN][MAXN];
	
	int b[MAXV];
	
	struct upit {
		int t, x1, y1, x2, y2, val, old;
	};
	
	// Mo prerequisites
	
	int mo;
	
	inline void add(int vr) {
		if (!b[vr]) {
			mo--;
		}
		b[vr]--;
		if (!b[vr]) {
			mo++;
		}
	}
	
	inline void rem(int vr) {
		if (!b[vr]) {
			mo--;
		}
		b[vr]++;
		if (!b[vr]) {
			mo++;
		}
	}
	
	// Mo tracker
	
	int xl=0, xr=-1, yl=0, yr=-1, t=-1;
	
	upit u[MAXQ];
	
	void adjust_t(int tt) {
		while (t < tt) {
			// vidi sta se desava u t+1
			t++;
			if (u[t].t == PRAVOUGAONIK)
				continue;
	
			if (xl <= u[t].x1 && u[t].x1 <= xr &&
				yl <= u[t].y1 && u[t].y1 <= yr)
			{
				rem(u[t].old);
				add(u[t].val);
			}
	
			a[u[t].x1][u[t].y1] = u[t].val;
		}
	
		while (t > tt) {
	
			if (u[t].t == PRAVOUGAONIK) {
				t--;
				continue;
			}
	
			if (xl <= u[t].x1 && u[t].x1 <= xr &&
				yl <= u[t].y1 && u[t].y1 <= yr)
			{
				add(u[t].old);
				rem(u[t].val);
			}
	
			a[u[t].x1][u[t].y1] = u[t].old;
			t--;
		}
	}
	
	void adjust_x(int lt, int rt) {
		while (xl > lt) {
			xl--;
			for (int j=yl; j<=yr; j++) {
				add(a[xl][j]);
			}
		}
		while (xr < rt) {
			xr++;
			for (int j=yl; j<=yr; j++) {
				add(a[xr][j]);
			}
		}
		while (xl < lt) {
			for (int j=yl; j<=yr; j++) {
				rem(a[xl][j]);
			}
			xl++;
		}
		while (xr > rt) {
			for (int j=yl; j<=yr; j++) {
				rem(a[xr][j]);
			}
			xr--;
		}
	}
	
	void adjust_y(int lt, int rt) {
		while (yl > lt) {
			yl--;
			for (int j=xl; j<=xr; j++) {
				add(a[j][yl]);
			}
		}
		while (yr < rt) {
			yr++;
			for (int j=xl; j<=xr; j++) {
				add(a[j][yr]);
			}
		}
		while (yl < lt) {
			for (int j=xl; j<=xr; j++) {
				rem(a[j][yl]);
			}
			yl++;
		}
		while (yr > rt) {
			for (int j=xl; j<=xr; j++) {
				rem(a[j][yr]);
			}
			yr--;
		}
	}
	
	int seqn(int i) {
		int sz[5] = {K*K*K*K, K*K*K, K*K, K, 1};
		int h[5] = {0, K, K, K, K};
		int a[5] = {
			i / (MAXN * D),
			u[i].x1 / D,
			u[i].y1 / D,
			u[i].x2 / D,
			u[i].y2 / D
		};
	
		int x = 0;
		for (int i=0; i<5; i++) {
			if (a[i] % 2) {
				for (int j=i+1; j<5; j++) {
					a[j] = h[j] - 1 - a[j];
				}
			}
			x += a[i] * sz[i];
		}
	
		return x;
	}
	
	bool cmprbupit(int i, int j) {
		return seqn(i) < seqn(j);
	}
	
	void Resi(int n, int m, int q, int v, int** a, int* b,
		int* x1, int* y1, int* x2, int* y2, int* o)
	{
		// ucitavanje
		::n = n;
		::m = m;
		::q = q;
		::v = v;
	
		for (int i=1; i<=v; i++) {
			mo += !b[i];
			::b[i-1] = b[i];
		}
	
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				::a[i-1][j-1] = a_orig[i-1][j-1] = a[i][j] - 1;
	
		for (int i=1; i<=q; i++) {
			if (y2[i] != -1) {
				u[i-1] = {PRAVOUGAONIK, x1[i]-1, y1[i]-1, x2[i]-1, y2[i]-1,      -1, -1};
			} else {
				u[i-1] = {      IZMENA, x1[i]-1, y1[i]-1,      -1,      -1, x2[i]-1, -1};
			}
		}
	
		// vidi za svaku izmenu koja vrednost je bila pre izmene
		for (int i=0; i<q; i++) {
			if (u[i].t == IZMENA) {
				u[i].old = ::a[u[i].x1][u[i].y1];
				::a[u[i].x1][u[i].y1] = u[i].val;
			}
		}
	
		// vrati na vreme 0
		memcpy(::a, a_orig, sizeof(::a));
	
		// sortiraj i resi
		vector<int> qs;
		for (int i=0; i<q; i++)
			if (u[i].t == PRAVOUGAONIK)
				qs.push_back(i);
	
		sort(qs.begin(), qs.end(), cmprbupit);
	
		for (int i : qs) {
			adjust_x(u[i].x1, u[i].x2);
			adjust_y(u[i].y1, u[i].y2);
			adjust_t(i);
			u[i].val = mo;
		}
	
		int outv = 0;
		for (int i=0; i<q; i++) {
			if (u[i].t == PRAVOUGAONIK) {
				o[++outv] = u[i].val;
			}
		}
	}
	```
