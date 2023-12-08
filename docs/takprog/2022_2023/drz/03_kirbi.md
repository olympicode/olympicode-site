---
hide:
  - toc
---

# B3 - Kirbi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3000ms | 64MB |
	
	Možda ste primetili kako se ovogodišnje Državno takmičenje radi u vrlo prijatnom okruženju i glavna zasluga toga je što su Prirodno-matematički fakultet i Fakultet inženjerskih nauka veoma čisti. Na tome je radilo puno ljudi, ali kako ima mnogo takmičara, morao je u pomoć da uskoči i Kirbi Usisivač.
	
	Prostor koji Kirbi treba da očisti može da se predstavi kao matrica sa $N$ redova i $M$ kolona. Tačno $P$ polja ove matrice su prljava, dok su ostala čista. Na početku čišćenja, Kirbi se nalazi u polju koje je u prvom redu i prvoj koloni. Zbog toga što je roze, on može da se kreće samo na polje direktno ispod trenutnog ili direktno desno od trenutnog.
	
	Verovatno ste to već znali, ali Kirbi je vrsan programer, i zna da odredi koliko najviše uprljanih polja da očisti krećući se kroz matricu. Ono što njega interesuje (zato što je opsednut statistikom) jeste koliko polja postoji, tako da kada bi ona bila čista, najveći broj uprljanih polja koje Kirbi može da očisti prolaskom kroz matricu se smanjio. 
	
	## Opis ulaza
	U prvoj liniji ulaza nalazi se prirodan broj $T$ - broj test primera.
	
	Svaki test primer je u sledećem formatu:
	
	U prvoj liniji test primera nalaze se tri prirodna broja $N$, $M$ i $P$ - broj redova u matrici, broj kolona u matrici i broj uprljanih polja u matrici
	
	U narednih $P$ linija se nalaze po dva prirodna broja $X_i$ i $Y_i$ koji predstavljaju koordinate $i$-tog uprljanog polja.
	
	## Opis izlaza
	U $T$ linija izlaza ispisati po jedan ceo broj koji predstavlja broj uprljanih polja koja kada bi bila čista, umanjio bi se najveći broj uprljanih polja koje Kirbi može da očisti u tom primeru.
	
	## Primer 1
	### Ulaz
	```
	1
	5 5 5
	1 1
	2 2
	3 3
	4 4
	5 5
	```
	
	### Izlaz
	```
	5
	```
	
	## Primer 2
	### Ulaz
	```
	1
	4 4 5
	1 2
	1 3
	1 4
	2 1
	3 1
	```
	
	### Izlaz
	```
	3
	```
	
	## Objašnjenje primera
	
	Prvi primer:
	
	* Inicijalno, Kirbi može da da očisti svih pet uprljanih polja, tako da uklanjanje bilo kog taj broj umanjuje na četiri. Dakle, odgovor je pet.
	
	Drugi primer:
	
	* Inicijalno, Kirbi može da da očisti najviše tri uprljanih polja. Uklanjanje nekog od uprljanih polja iz prve kolone ne utiče na najveći broj polja koje Kirbi može da očisti, jer on može da se kreće samo kroz prvi red. Sa druge strane, uklanjanje bilo kog od tri polja iz prvog reda smanjuje taj broj sa tri na dva, pa je i konačan odgovor tri.
	
	## Ograničenja
	
	- $1 \leq T \leq 10$.
	- $1 \leq N,M \leq 10^9$.
	- $1 \leq P \leq \min(N\cdot M, 2\cdot 10^5)$.
	- $1 \leq X_i \leq N$.
	- $1 \leq Y_i \leq M$.
	
	Test primeri su podeljeni u četiri disjunktnih grupa:
	
	- U test primerima vrednim 10 poena, $1 \leq N,M,P \leq 5$.
	- U test primerima vrednim 20 poena, $N = 2$ ili $M=2$.
	- U test primerima vrednim 20 poena, $1 \leq N,M,P \leq 100$.
	- U test primerima vrednim 50 poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Milenković | Marko Milenković | Marko Milenković | Dimitrije Erdeljan |
	
	## Rešenje kada $1 \leq N,M,P \leq 5$
	U ovom podzadatku koristimo to da su sve vrednosti male brojke. Možemo izbrisati svako prljavo polje i zatim isprobati sve putanje da vidimo koja sadrži najveći broj uprljanih polja i da li se to razlikuje od početnog maksimalnog broja polja koje Kirbi može da očisti. Vremenska složenost je $O(TP2^{N+M})$.
	
	## Rešenje kada $N = 2$ ili $M = 2$
	Posmatraćemo slučaj $N=2$, jer se drugi slučaj analogno rešava. Primetimo da će se Kirbi tačno jednom spustiti u drugi red. Pamtimo prefiksni niz prljvih polja za prvi red i pamtimo sufiksni niz prljavih polja za drugi red. Maksimalan broj polja koje Kirbi može da očisti je $S = \max_{1 \leq i \leq M}\{pref_i + suf_i\}$. Neka je $i_{min}$ prva kolona u kojoj izraz $pref_{i_{min}} + suf_{i_{min}}$ dostiže vrednost $S$ i neka je $i_{max}$ poslednja kolona u kojoj izraz $pref_{i_{max}} + suf_{i_{max}}$ dostiže vrednost $S$. Traženo rešenje je $pref_{i_{min}} + suf_{i_{max}}$. Vremenska složenost je $O(T(P+M))$.
	
	## Rešenje kada $1 \leq N,M,P \leq 100$
	Neka je $S$ ponovo maksimalan broj polja koje Kirbi može da očisti u startu. To možemo izračunati standardnim dinamičkim programiranjem. Stanje $dp_{i,j}$ predstavlja maksimalan broj polja koje Kirbi može da očisti krećući sa polja $(1,1)$ do polja $(i,j)$. Krenemo "redom" da obilazimo matricu po redovima, pa po kolonama (kao u ulazu) i vršimo prelaz $dp_{i,j} = \max(dp_{i-1,j}, dp_{i,j-1}) + a_{i,j}$, gde je $a_{i,j}$ binarni indikator da li je polje $(i,j)$ urljano ($1$ ako jeste, $0$ ako nije). Sada možemo da izbacujemo jedno po jedno uprljano polje i računamo iznova celu $dp$ matricu i vidimo kada je vrednost $dp_{N,M} < S$. Vremenska složenost $O(TPNM)$.
	   
	## Glavno rešenje
	Možemo primetiti da kada posmatramo redom polja koja je Kirbi očistio, njihove kolone formiraju neopadajući niz. Odnosno, ukoliko sortiramo uprljana polja po redovima, maksimalan broj polja koja Kirbi može da očisti je najduži neopadajući podniz kolona ovog niza. Dati problem je ekvivalentan nalaženju najdužeg rastućeg podniza (\emph{Longest increasing subsequence}, ili skraćeno LIS), što je poznat problem i može se rešiti/implementirati u vremenskoj složenosti $O(P\log P)$. Ono što nama treba jesu prefiksni i sufiksni LIS nizovi. Formalno, $pref_i$ predstavlja $LIS$ od početka niza do $i$-tog elementa, ali tako da on zasigurno figuriše u $LIS$-u. Slično, $suf_i$ predstavlja $LIS$ niza od $i$-tog elementa do kraja niza, tako da $i$-ti element učestvuje u $LIS$-u. Za $i$-ti element niza uprljanih polja važi da je deo nekog od putanja koje sadrže najveći broj uprljanih polja ako i samo ako je $pref_i + suf_i - 1 = S$. Sa druge strane, element niza pripada svim takvim putanjama ako i samo ako dodatno važi i da je vrednost $pref_i$ jedinstvena među svim prefiksnim $LIS$-ovima. Potrebno je samo ispisati broj takvih polja. Vremenska složenost je $O(TP\log P)$. 
	
	``` cpp title="03_kirbi.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	// Postoji mnogo nacina da se implementira lis
	vector<int> lis(vector<int>& a) {
		int n = a.size();
	    vector<int> d(n+1, 2e9);
		
		vector<int> sol;
		for (int i = 0; i < n; i++) {
			int ind = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
			if (d[ind] != 2e9){
				sol.push_back(ind+1);
				d[ind] = a[i];
			} else {
				d[ind] = a[i];
				sol.push_back(lower_bound(d.begin(), d.end(), 2e9) - d.begin());
			}
		}
	
		return sol;
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(nullptr); 
		cout.tie(nullptr); 
		cerr.tie(nullptr);
	
		int t;
		cin >> t;
	
		for (int e = 0; e < t; ++e){
			int n, m, p;
			cin >> n >> m >> p;
	
			vector<pair<int, int>> a;
			for (int i = 0; i < p; ++i){
				int x, y;
				cin >> x >> y;
	
				a.push_back({x, y});
			}
	
			sort(a.begin(), a.end());
	
			vector<int> col;
			for (int i = 0; i < p; ++i){
				col.push_back(a[i].second);
			}
	
			vector<int> pref = lis(col);
	
			vector<int> rev;
			for (int i = 0; i < p; ++i){
				rev.push_back(-1 * a[p-1-i].second);
			}
	
			vector<int> suf = lis(rev);
			reverse(suf.begin(), suf.end());
	
			vector<int> candidates;
			vector<int> cnt(p+1,0);
	
			int max_lis = *max_element(pref.begin(), pref.end());
	
			for (int i = 0; i < p; ++i){
				if (pref[i] + suf[i] - 1 == max_lis){
					candidates.push_back(i);
					cnt[pref[i]]++;
				}
			}
	
			int sol = 0;
			for (int c : candidates){
				if (cnt[pref[c]] == 1){
					++sol;
				}
			}
	
			cout << sol << '\n';
		}
	
	}

	```
