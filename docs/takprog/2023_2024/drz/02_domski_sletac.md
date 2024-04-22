---
hide:
  - toc
---

# B2 - Domski sletač

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Domski Sletač se nalazi u gornjem levom uglu matrice dimenzija $N \times M$. Želja mu je da dođe do polja u donjem desnom uglu, jer se tamo nalazi njegov frižider sa mlekom. Opšte je poznato da se Domski Sletač može pomerati iz trenutnog polja u polje direktno ispod ili u polje direktno desno (ukoliko takva polja postoje, odnosno nije moguće da "izađe" iz matrice.).
	
	Bane Kasapin i Vojni Momak žele da napakoste Domskom Sletaču, pa su u nekim poljima matrice postavili izvestan broj njegovih neistomišljenika. Neistomišljenici takođe moraju da se kreću kao i Domski Sletač (mogu se pomerati iz trenutnog polja u polje direktno ispod ili u polje direktno desno). Kako je Domski Sletač neustrašiv, on na putu do svog mleka želi i da raspravi nesuglasice sa svim svojim neistomišljenicima.
	
	Kada Domski Sletač izabere svoju putanju do mleka, svi neistomišljenici će se pomeriti do sebi najbližeg polja na tom putu. Tek kada se svi neistomišljenici presele na željena polja, onda Domski Sletač kreće na svoj put. Pošto želi da mu neistomišljenici budu što odmorniji, potrebno je da Domski Sletač izabere put takav da je ukupan put koji će svi neistomišljenici preći minimalan.
	
	Vaš zadatak je da pronađete i ispišete koliko će neistomišljenici preći do opisane putanje.
	
	## Opis ulaza
	
	U prvoj liniji standardnog ulaza, nalaze se dva prirodna broja $N$ i $M$ koji predstavljaju dimenzije matrice.
	
	U narednih $N$ linija standardnog ulaza, nalazi se po $M$ nenegativnih celih brojeva. U $i$-tom od $N$ redova, $j$-ti broj označen sa $a_{ij}$ predstavlja broj neistomišljenika na polju u $i$-toj vrsti i $j$-toj koloni. 
	
	## Opis izlaza
	
	U prvoj i jedinoj liniji izlaza ispisati najmanju ukupnu distancu koju će neistomišljenici preći.
	
	## Primer 1
	
	
	### Ulaz
	
	
	```
	4 4 
	4 3 2 1
	4 3 2 1
	4 3 2 1
	4 3 2 1
	```
	
	
	
	### Izlaz
	
	
	```
	29
	```
	
	## Objašnjenje primera
	
	Optimalna putanja Domskom Sletaču je $(1,1)\rightarrow (2, 1) \rightarrow (2, 2) \rightarrow (3, 2) \rightarrow (4, 2) \rightarrow (4, 3) \rightarrow (4, 4)$. Svih $4+4+3+3+3+2+1=20$ neistomišljenika na poljima kroz koje Domski Sletač prolazi, neće morati da se pomere, pa je ukupna distanca koji oni pređu $0$. Neistomišljenici na poljima $(3, 1)$ i $(4, 1)$ će preći za jedno polje u desnu stranu, što znači da će zbirno preći $4+4 = 8$. Neistomišljenik u polju $(1,2)$ će se spustiti za jedno pole ispod i preći $3$. Zatim, neistomišljenici na poljima $(3, 3)$ i $(3, 4)$ će preći po jedno polje ispod, odnosno zbirno će preći $2 + 1 = 3$. Slično, neistomišljenici na poljima $(2, 3)$ i $(2, 4)$ će preći po $2$ polja na dole i ukupno preći $2\cdot 2 + 2\cdot1 = 6$. Na kraju, neistomišljenici na poljima $(1, 3)$ i $(1, 4 )$ spustiće se za tri polja ispod i prelaze zbirno $3\cdot 1 + 3\cdot 2 = 9$. Ukupno, svi neistomišljenici će preći $0+8+3+3+6+9 = 29$.
	
	## Primer 2
	
	
	### Ulaz
	
	
	```
	3 3 
	1 0 0
	0 7 0
	0 0 1
	```
	
	
	
	### Izlaz
	
	
	```
	0
	```
	
	## Objašnjenje primera
	
	U ovom primeru, optimalna putanja Domskom Sletaču nije jedinstvena. Jedna mogućnost je $(1,1)\rightarrow (2, 1) \rightarrow (2, 2) \rightarrow (2, 3) \rightarrow (3, 3)$. Na ovaj način, Domski Sletač prolazi kroz sve neistomišljenike. Svih $1+7+1=9$ neistomišljenika na poljima kroz koje Domski Sletač prolazi, neće morati da se pomere, pa je ukupna distanca koji oni pređu $0$.
	
	
	## Ograničenja
	
	
	* $1 \leq N \cdot M \leq 10^6$
	* $0 \leq a_{ij} \leq 10^6$
	
	Test primeri su podeljeni u četiri disjunktnih grupa:
	
	* U test primerima vrednim 20 poena: $1 \leq NM \leq 20$;
	* U test primerima vrednim 10 poena: $N = 2$;
	* U test primerima vrednim 35 poena: $N\cdot M \leq 10^4$;
	* U test primerima vrednim 35 poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Milenković | Marko Milenković | Marko Milenković | Dragan Urošević |
	
	##  $NM \leq 20$
	U ovom podzadatku je dovoljno izgenerisati sve moguće puteve (npr. bektreking algoritmom) i proveriti za svako polje koliko su neistomišljenici udaljeni od tog puta. Na kraju samo ispisujemo minimum svih zbirnih udaljenosti.
	
	## $N=2$
	U ovom podzadatku je ključno primetiti da time što posmatrana matrica ima dva reda, Domski Sletač će se samo jednom spustiti u drugi (niži) red. Neka to bude iz polja $(1, X)$ u polje $(2, X)$. Kako neistomišljenici mogu takođe da se kreću samo dole i desno, svi neistomišljenici iz prvog reda desno od polja $(1,X)$, će morati da se spuste jedno polje naniže. Sa druge strane, neistomišljenici iz drugog reda levo od polja $(2,X)$, će morati da idu na desnu stranu do polja $(2, X)$. Konačna suma za fiksirano $X$ biće $\sum_{j=X+1}^M a_{1j} + \sum_{j=1}^{X-1} \left( a_{2j}\cdot (X-j) \right)$. Množenje sa $(X-j)$ zapravo određuje koliko putanju će preći neistomišljenici iz drugog reda. Iteriraćemo po $X$, a tražene sume možemo da izračunamo pre toga kako ne bismo dobili kvadratnu složenost. Konačno, vremenska složenost ovog pristupa je $\mathcal{O}(M)$.
	
	##  $NM \leq 10^4$
	
	Primetimo da se u prošlom podzadatku svaki neistomišljenik kretao samo dole ili samo desno. Ako uopštimo zaključak dobijamo da ako fiksiramo putanju Domskog Sletača i ukoliko se neistomišljenik nalazi ispod nje, najbliže polje putanje će upravo biti ono koje je prvo gledajući samo nadesno. Slično, neistomišljenicima koji su iznad putanje je optimalno da se spuste samo dole do prvog polja putanje. Imajući u obzir da i Domski Sletač i neistomišljenici kreću samo dole i desno, može se lako pokazati da su im to najbliža polja.
	
	Uz ovaj zaključak možemo da formiramo stanje dinamičkog programiranja: $dp[i][j]$ nam predstavlja odgovor na postavku zadatka ali za podmatricu do $i$-tog reda i $j$-te kolone (kolika je minimalna distanca koju svi neistomišljenici iz ove podmatrice moraju da pređu da bi stigli do putanje Domskog Sletača koji se kreće od polja $(1,1)$ do polja $(i,j)$). Jasno, u početku je $dp[1][x] = dp[y][1] = 0$ za svako $x=1,2,\ldots,M$ i $y=1,2,\ldots,N$. U polje $(i,j)$ možemo doći s gornje strane, odnosno iz polja $(i-1,j)$, ili s leve strane odnosno iz polja $(i,j-1)$. U prvom slučaju minimalna distanca biće $dp[i-1][j] + \sum_{k=1}^{j-1} \left( a_{ik}\cdot (j-k) \right)$, jer neistomišljenici iz $i$-tog reda s leve strane od trenutnog polja baš dolaze u polje $(i,j)$. Sličnim rezonovanjem, u drugom slučaju minimalna distance biće. Na kraju, prelaz dinamičkog programiranja biće $dp[i][j-1]+\sum_{k=1}^{i-1}\left( a_{kj}\cdot (i-k)\right)$. Za $dp[i][j]$ uzimamo manju od ove dve vrednosti. Konačno rešenje je $dp[N][M]$. Ukupna vremenska složenost ovog algoritma je $\mathcal{O}(NM(N+M))$.  
	
	## Rešenje bez dodatnih ograničenja
	
	Jedino što nas sprečava da dostignemo željenu složenost $\mathcal{O}(NM)$ u prethodnom rešenju jeste sporo računanje prelaza za $dp[i][j]$. Primetimo da isto kao i u drugom podzadatku možemo da pre računanja prelaza i stanja dodatne sume. Odnosno, izračunaćemo $r[i][j]$ najmanja distanca da svi neistomišljenici iz reda $i$ a u kolonama $1,2,\ldots,j-1$ dođu do polja $(i,j)$. Slično, $c[i][j]$ najmanja distanca da svi neistomišljenici iz kolone $j$ a u redovima $1,2,\ldots,i-1$ dođu do polja $(i,j)$. Prelaze računamo po formuli $r[i][j] = r[i][j-1] + \sum_{k=1}^{j-1}a_{ij}$ (posmatramo ovo na sledeći način: kao da su do susednog polja levo svi neistomišljenici došli i onda svi zajedno prešli za jedno polje udesno se pomerili) i $c[i][j] = c[i-1][j]  + \sum_{k=1}^{i-1}a_{ij}$. Primetimo da ove dodatne sume nisu ništa nego prefiksne sume po redovima i kolonama, koje možemo takođe unapred da izračunamo i obeležimo sa $pref\_r[i][j]$ i $pref\_c[i][j]$. Sada nam prelazi izledaju ovako: $r[i][j] = r[i][j-1] + pref\_r[i][j-1]$ i $c[i][j] = c[i-1][j]  + pref\_c[i-1][j]$. Konačno, početni prelaz iz prethodnog podzadatka dobija sledeću formu $dp[i][j] = \min(dp[i-1][j] + r[i][j], dp[i][j-1] + c[i][j])$. Vremenska složenost ovog rešenja je $\mathcal{O}(NM)$.
	
	## Napomena
	
	U skoro svim podzadacima je potrebno da se koristi $64$-bitni tip podataka za računanje, jer krajnji odgovor može da bude znatno veći od $2\cdot 10^9$.
	
	``` cpp title="02_domski_sletac.cpp" linenums="1"
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
	
	
	ifstream in;
	ofstream out;
	
	const int mod = 1e9+7;
	
	signed main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(nullptr); 
		cout.tie(nullptr); 
		cerr.tie(nullptr);	
	
		int n, m;
		cin >> n >> m;
	
		vector<vector<int>> a(n, vi(m, 0)), dp = a, rows = a, cols = a;
	
		for (auto& i : a)
			for(auto& j : i)
				cin >> j;
	
		for (int i = 0; i < n; ++i){
			rows[i][0] = a[i][0];
			for (int j = 1; j < m; ++j)
				rows[i][j] = rows[i][j-1] + a[i][j];
		}
	
		for (int j = 0; j < m; ++j){
			cols[0][j] = a[0][j];
			for (int i = 1; i < n; ++i)
				cols[i][j] = cols[i-1][j] + a[i][j];
		}
	
		auto pref_cols = vector<vector<int>>(n, vi(m, 0));
		auto pref_rows = pref_cols;
		for (int i = 0; i < n; ++i)
			for (int j = 1; j < m; ++j)
				pref_rows[i][j] = pref_rows[i][j-1] + rows[i][j-1];
	
		for (int j = 0; j < m; ++j)
			for (int i = 1; i < n; ++i)
				pref_cols[i][j] = pref_cols[i-1][j] + cols[i-1][j];
	
		for (int i = 1; i < n; ++i){
			for (int j = 1; j < m; ++j){
				int levo = dp[i][j-1] + pref_cols[i][j];
				int gore = dp[i-1][j] + pref_rows[i][j];
	
				dp[i][j] = min(levo, gore);
			}
		}
	
		cout << dp[n-1][m-1] << '\n';
	}
	```
