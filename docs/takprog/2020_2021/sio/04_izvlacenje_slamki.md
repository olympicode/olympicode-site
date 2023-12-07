---
hide:
  - toc
---

# 4 - Izvlačenje slamki

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Pavle i Aleksa se igraju sa slamkama. One su poređane u niz i njihove pozicije su numerisane brojevima od $1$ do $N$ sleva nadesno. Sve slamke su različitih celobrojnih dužina od $1$ do $N$. 
	
	Otišli su kod proroka Mikija da im kaže kako će se njihova igra odvijati. On im je rekao da će biti $M$ dešavanja za redom, i svako od njih će biti u jednom od dva tipa:
	
	$1$ $l_i$ $r_i$ - Aleksa ima priliku da promeša slamke (promeni im redosled) na pozicijama od $l_i$ do $r_i$ kako god želi;
	
	$2$ $x_i$ - Pavle izvlači slamku na poziciji $x_i$ i odmah je vrati na isto mesto.
	
	Svi znaju da, pri izvlačenju slamke, nikako ne želimo da izvučemo najkraću slamku. Pošto Pavle nema slobodu koju slamku će izvući (prorok Miki je uvek u pravu), a Aleksa ima slobodu u mešanju slamki, on želi da koristi svoje prilike za mešanje da namesti Pavlu da što više puta izvuče najkraću slamku. Odredite koliko je najviše puta moguće da on to uradi.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $Slamke(N, A[\ldots], M, T[\ldots], X[\ldots], Y[\ldots])$
	
	gde je $N$  broj koji predstavlja broj slamki,  niz $A$, dužine $N$ predstavlja dužine slamki sa leva na desno.  Broj $M$ predstavlja broj dešavanja, dok nizovi $T$, $X$ i $Y$ opisuju dešavanja hronološkim redosledom. Ukoliko važi $T[i] = 1$, znači da je $i$-to dešavanje mešanje slamki, pa $X[i]$ i $Y[i]$ predstavljaju levu i desnu granicu intervala koji se meša. Ukoliko važi $T[i] = 2$, znači da je $i$-to dešavanje izvlačenje slamke, pa $X[i]$ predstavlja indeks izvučene slamke. U tom slučaju važiće $Y[i] = 0$.  **Svi nizovi su indeksirani od 1.**
	
	## Primer
	Neka su $N=6$ i $M = 4$, i neka su nizovi $A=\{3, 1, 4, 6, 5, 2\}$, $T=\{1, 2, 1, 2\}$, $X=\{
	2, 5, 4, 5\}$ i $Y=\{4, 0, 6, 0\}$:
	Nakon prvog mešanja nije moguće namestiti najkraću slamku na poziciju $5$, ali posle drugog jeste, pa je rezultat $1$. 
	
	Neka su $N=4$ i $M = 4$, i neka su nizovi $A=\{4, 3, 2, 1\}$, $T=\{1, 2, 2, 2\}$, $X=\{
	1, 1, 1, 3\}$ i $Y=\{4, 0, 0, 0\}$:
	Posle prvog mešanja moguće je staviti slamku bilo gde, ali ne istovremeno i na poziciju $1$ i poziciju $3$. Od te dve opcije bolja je opcija $1$, jer nju izvlači dvaput, pa je rezultat $2$.
	
	## Ograničenja
	-   $1 \leq N, M \leq 3\cdot10^5$
	-   $1 \leq A_i \leq N$
	-  Svi elementi niza $A_i$ različiti. 
	- $T_i \in \{1, 2\}$
	- Ukoliko $T_i = 1$, važi $1 \leq X_i \leq Y_i \leq N$.
	- Ukoliko $T_i = 2$, važi $1 \leq X_i \leq N$, $Y_i = 0$.
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[14 poena]:** Sva dešavanja tipa $1$ se dešavaju pre svakog dešavanja tipa $2$.
	-   **[9 poena]:** $M \leq 20$ i ukoliko $T_i = 1$, važi $Y_i - X_i = 1$.
	-   **[13 poena]:** Ukoliko $T_i = 1$, važi $Y_i - X_i = 1$.
	-   **[15 poena]:** $N, M \leq 5000$.
	-   **[13 poena]:** $M \leq 10000$.
	-   **[36 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `izvlacenje_slamki.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int Slamke(int N, int* A, int M, int* T, int* X, int* Y);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu broj $N$.
	* U drugom redu $N$ brojeva, niz $A$.
	* U trećem redu broj $M$.
	* U narednih $M$ redova po tri broja u svakom redu, $T_i$ $X_i$ $Y_i$.
	
	Obratite pažnju da se broj $Y_i$ učitava i kada je u pitanju dešavanje drugog tipa. Tada je potrebno da mu vrednost bude $0$. 
	
	Zatim ovaj program poziva vašu funkciju i štampa rezultat koji je vratila vaša funkcija.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Mladen Puzić | Mladen Puzić | Mladen Puzić | Pavle Martinović |
	
	## Podzadatak 1
	Za ovaj podzadatak, potrebno je naći poziciju sa koje se najviše puta izvlači slamka, a da je moguće staviti najkraću slamku na tu poziciju. Potrebno je, dakle, samo naći interval na kojem može završiti najkraća slamka. Na početku je taj interval jednak samo njenoj početnoj poziciji, dok svakim novim mešanjem taj interval se može proširiti, ukoliko se makar i malo preklapa sa intervalom mešanja. Vremenska i memorijska složenost: $O(N+M)$.
	
	## Podzadatak 2
	Za svako mešanje, možemo fiksirati da li se menja mesto dvema slamkama na intervalu mešanja. Svaku kombinaciju simuliramo i uzmemo najbolje rešenje. Memorijska složenost: $O(N+M)$, vremenska složenost: $O(2^M\cdot M + N)$.
	
	## Podzadatak 3
	 Ovaj podzadatak ima rešenje veoma slično podzadatku $4$, ali ga je lakše zamisliti, pa je služio kao pomoć takmičarima da dođu do boljeg rešenja. Pogledati rešenje četvrtog podzadatka.
	 
	## Podzadatak 4
	Označimo sa $dp_{i, j}$ maksimalno rešenje ako se posle $j$ događaja najkraća slamka nalazi na poziciji $i$. Na početku važi $dp_{i, 0} = -\infty$ (dovoljno mali negativan broj), za svako $i$ na kojem se ne nalazi najkraća slamka, dok važi $dp_{i, 0} = 0$, za $i$ koje je početna pozicija najkraće slamke. Sada je potrebno da nađemo rekurzivnu vezu. Postojaće dva slučaja, za dva različita tipa događaja:
	
	$1$ $l$ $r$: $dp_{i, j} = max\{dp_{l, j-1}, dp_{l+1, j-1}, \ldots, dp_{r, j-1}\}$, ukoliko $i \in [l, r]$. U suprotnom $dp_{i, j} = dp_{i, j-1}$. Dakle, bilo koja pozicija na intervalu može doći sa bilo koje druge pozicije na intervalu, a optimalno je da uzmemo sa maksimalne.
	
	$2$ $x$: $dp_{x, j} = dp_{x, j-1} + 1$, a $dp_{i, j} = dp_{i, j-1}$ ukoliko $i \neq x$.  Jedino se povećava slučaj kad se baš tu nalazi najkraća slamka, ostale se ne menjaju.
	
	Memorijska složenost: $O(NM)$ (može i $O(N)$), vremenska složenost: $O(NM)$. 
	
	## Podzadatak 5
	Čuvajmo $dp_i$ za svaki događaj $i$ koji je drugog tipa. Tu čuvamo najbolje rešenje ako je Pavle u tom trenutku izvukao najkraću slamku. Kako bismo izračunali ovu vrednost potrebno je da vidimo odakle smo sve mogli da dođemo. Krećemo se unazad kroz događaje i održavamo interval odakle smo mogli da dođemo na poziciju slamke koju je Pavle izvukao u događaju $i$, slično rešenju prvog podzadatka. Svaki put kada naiđemo na događaj $j$ oblika $2$, ako je u intervalu od kojeg smo mogli da dođemo, uradimo operaciju $dp_i = max(dp_i, dp_j+1)$. Krajnje rešenje nam je maksimum celog niza $dp$. Memorijska složenost: $O(M)$, vremenska složenost: $O(M^2+N)$. 
	
	## Glavno rešenje
	Veoma slično rešenju podzadatka $4$, idemo kroz dešavanja jedno po jedno i održavamo niz $dp_i$, za do sada pređene događaje, koje je najbolje rešenje, ako se trenutno najkraća slamka nalazi na poziciji $i$. Ovaj niz možemo održavati po rekurentnim vezama iz $4$ podzadatka, koristeći segmentno stablo sa lenjom propagacijom, koje ima operacije: nađi maksimum na intervalu i postavi ceo interval na neku vrednost. Događaj jedan se pokriva operacijom postavi interval na maksimum na intervalu, dok se događaj dva pokriva operacijom postavi interval $[x, x]$ na vrednost od $dp_x+1$. Memorijska složenost: $O(N)$, vremenska složenost: $O(MlogN+N)$. 
	
	``` cpp title="04_izvlacenje_slamki.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 300010
	using namespace std;
	///
	#define INF 1000000000
	#define mid (l+r)/2
	int dp[MAXN], seg[4*MAXN], lazy[4*MAXN];
	void init(int node, int l, int r) {
	    if(l == r) {
	        seg[node] = dp[l];
	        lazy[node] = INF;
	        return;
	    }
	    init(2*node, l, mid); init(2*node+1, mid+1, r);
	    seg[node] = max(seg[2*node], seg[2*node+1]);
	    lazy[node] = INF;
	}
	void propagate(int node, int l, int r) {
	    if(lazy[node] != INF) {
	        seg[node] = lazy[node];
	        if(l != r) {
	            lazy[2*node] = lazy[node];
	            lazy[2*node+1] = lazy[node];
	        }
	        lazy[node] = INF;
	    }
	}
	int query(int node, int l, int r, int L, int R) {
	    propagate(node, l, r);
	    if(L <= l && r <= R) return seg[node];
	    if(r < L || r < l || R < l || R < L) return -INF;
	    return max(query(2*node, l, mid, L, R), query(2*node+1, mid+1, r, L, R));
	}
	void update(int node, int l, int r, int L, int R, int val) {
	    propagate(node, l, r);
	    if(L <= l && r <= R) {
	        lazy[node] = val;
	        propagate(node, l, r);
	        return;
	    }
	    if(r < L || r < l || R < l || R < L) return;
	    update(2*node, l, mid, L, R, val); update(2*node+1, mid+1, r, L, R, val);
	    seg[node] = max(seg[2*node], seg[2*node+1]);
	}
	int Slamke(int N, int* A, int M, int* T, int* X, int* Y) {
	    int idxx = -1;
	    for(int i = 1; i <= N; i++) {
	        if(A[i] == 1) dp[i] = 0;
	        else dp[i] = -INF;
	    }
	    init(1, 1, N);
	    for(int i = 1; i <= M; i++) {
	        if(T[i] == 1) {
	            int maxx = query(1, 1, N, X[i], Y[i]);
	            update(1, 1, N, X[i], Y[i], maxx);
	        } else {
	            int maxx = query(1, 1, N, X[i], X[i]);
	            update(1, 1, N, X[i], X[i], maxx+1);
	        }
	    }
	    return query(1, 1, N, 1, N);
	}
	/*
	int A[MAXN], T[MAXN], X[MAXN], Y[MAXN];
	int main() {
	    ios::sync_with_stdio(false); cin.tie(0);
	    int N; cin >> N;
	    for(int i = 1; i <= N; i++) cin >> A[i];
	    int M; cin >> M;
	    for(int i = 1; i <= M; i++) cin >> T[i] >> X[i] >> Y[i];
	    cout << Slamke(N, A, M, T, X, Y) << endl;
	    return 0;
	}
	*/
	```
