---
hide:
  - toc
---

# A1 - Xormutacije

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	
	Stefan je od nedavno postao profesor na jednom vrlo prestižnom univerzitetu i povodom toga organizuje žurku. Ipak, organizacija mu nikad nije bila jača strana, pa je zakazao žurku u sred ispitnog roka!
	
	Na ispitu je Stefan dao svakom studentu po jedan niz $P$ dužine $N+1$ u kome se svaki od brojeva $0,1,2,\ldots,N$ pojavljuje tačno jednom. Zadatak im je da konstruišu još jedan takav niz $Q$ tako da sledeći izraz bude najveći moguć:
	
	$$
	X = (P_0 \oplus Q_0) + (P_1 \oplus Q_1) + \ldots + (P_N \oplus Q_N).
	$$
	
	Kako biste pomogli Stefanu da se što pre vrati na žurku, na koju kasni iako je organizator, potrebno je da napišete program koji će za zadat niz $P$ ispisati najveću moguću vrednost izraza $X$ i odgovarajući niz $Q$. Ukoliko postoji više odgovarajućih nizova $Q$, ispisati bilo koji. 
	
	
	## Opis ulaza
	
	
	U prvoj liniji ulaza nalazi se prirodan broj $T$ - broj test primera.
	
	Svaki test primer je u sledećem formatu:
	U prvoj liniji test primera nalazi se prirodan broj $N$.
	
	U drugoj liniji test primera se nalazi niz $P$ od $N+1$ brojeva $P_0, P_1, \ldots, P_N$.
	
	
	## Opis izlaza
	
	Za svaki od $T$ test primera ispisati po dve linije izlaza u sledećem formatu:
	
	U prvoj liniji izlaza ispisati vrednost izraza $X$.
	
	U drugoj liniji izlaza ispisati $N$ brojeva koji predstavljaju niz $Q$.
	
	
	## Primer 1
	
	
	### Ulaz
	
	
	```
	1
	5
	4 1 3 2 0 5
	```
	
	
	
	### Izlaz
	
	
	```
	30
	3 0 4 5 1 2
	```
	
	
	### Objašnjenje
	
	Vrednost izraza $X$ jednaka je $(4 \oplus 3) + (1 \oplus 0) + (3 \oplus 4) + (2 \oplus 5) + (0 \oplus 1) + (5 \oplus 2) = 7+1+7+7+1+7=30$ i može se pokazati da ni za jedan drugi niz $Q$ ne dostiže veću vrednost.
	
	
	## Primer 2
	
	
	### Ulaz
	
	
	```
	2
	3
	0 1 3 2
	2
	0 2 1
	```
	
	
	
	### Izlaz
	
	
	```
	12
	3 2 0 1
	6
	0 1 2
	```
	
	## Ograničenja
	
	
	* $1 \leq T \leq 5$
	* $1 \leq N \leq 10^5$
	* $1 \leq P_i \leq N$ i svaka od ovih vrednosti se pojavljuje tačno jednom.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	* U test primerima vrednim 10 poena: $T = 1$ i $1 \leq N \leq 9$;
	* U test primerima vrednim 30 poena: $N+1$ je stepen dvojke;
	* U test primerima vrednim 40 poena: $P_i = i$ za svako $0 \leq i \leq N$;
	* U test primerima vrednim 20 poena: Bez dodatnih ograničenja.
	
	## Napomena
	
	Operator $\oplus$ predstavlja operaciju [isključive disjunkcije](https://sr.wikipedia.org/wiki/Isključiva_disjunkcija).
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Milenković | Marko Milenković | Marko Milenković | Pavle Martinović |
	
	##  $T = 1$ i $N \leq 9$
	U ovom podzadatku je dovoljno izgenerisati sve permutacije dužine $N+1$ i izračunati za svaku od njih izraz $X$. Kako bi se izbegla nepotrebna konstanta $N$ u složenosti, izraz $X$ računamo dok generišemo sve permutacije. Ukupna složenost je onda $\mathcal{O}((N+1)!)$ ili $\mathcal{O}((N+1)! \cdot N)$ u zavisnosti od toga kako računamo izraz $X$. 
	
	## $N+1$ je stepen dvojke
	Primetimo da je moguće da uparimo brojeve $x$ i $N-x$. Oni su komplementarni u binarnom zapisu - kada na nekom mestu u binarnom zapisu broj $x$ ima jedinicu, tada je na istom tom mestu nula u broju $N-x$, i obrnuto. To znači da će $\oplus$ svakog para biti $N$, a onda i ukupna suma $N\cdot(N+1)$. Vremenska složenost ovog algoritma je $\mathcal{O}(N)$. 
	
	##  $P_i = i$ za svako $i = 0, 1, 2, \ldots, N$
	Primetimo da ukoliko imamo rešenje kada važi $P_i = i$, onda imamo i rešenje u opštem slučaju - samo je potrebno da izmapiramo koji element ide kome umesto da ih ispisujemo redom za $i=0,1,2,\ldots,N$. 
	
	## Rešenje bez dodatnih ograničenja
	Posmatrajmo najveći broj $K$ manji od $N$, za koji važi da je $K+1$ stepen dvojke. Jasno je da ukoliko uparimo $K$ i $K+1$ ne gubimo nijedan bit primenom operacije $\oplus$, jer su komplementarni brojevi u binarnom zapisu. Isto to važi i za brojeve $K-1$ i $K+2$, $K-2$ i $K+3$, i tako dalje. Nakon što uparimo broj $N$ sa njegovim parnjakom, rekurzivno rešavamo za preostale brojeve. Iz ove konstrukcije se lako može pokazati da je najveća moguća vrednost izraza $X$ upravo jednaka $N(N+1)$. U zavisnosti od implementacije mapiranja elementa ili pronalaženja broja $K$, ukupna vremenska složenost biće $\mathcal{O}(N)$ ili $\mathcal{O}(N\log N)$.
	
	``` cpp title="04_xormutacije.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	#define int ll
	typedef long long ll;
	typedef long double ld;
	typedef pair<int, int> pi;
	typedef pair<ll, ll> pl;
	typedef vector<int> vi;
	typedef vector<ll> vl;
	typedef vector<double> vd;
	typedef vector<bool> vb;
	typedef vector<char> vc;
	typedef vector<string> vs;
	typedef vector<pi> vp;
	typedef vector<pl> vpl;
	
	signed main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(nullptr); 
		cout.tie(nullptr); 
		cerr.tie(nullptr);	
	
		int t;
		cin >> t;
	
		for (int e = 0; e < t; ++e){
			int n;
			cin >> n;
	
			vi a(n+1);
			for (int i = 0; i <= n; ++i){
				cin >> a[i];
			}
	
			vi res(n+1,0);
			int sol = 0;
			while(n){
				int k = log2(n);
	
				int m = 1<<k, suprotan = m-1;
				for (int i = m; i <= n; --suprotan, ++i){
					res[i] = suprotan;
					res[suprotan] = i;
					sol += (i^suprotan) * 2;
				}
	
				n=suprotan;
			}
	
	
			cout << sol << '\n';
			for (int i = 0; i < res.size(); ++i)
				cout << res[a[i]] << ' ';
			cout << '\n';
		}
	}

	```
