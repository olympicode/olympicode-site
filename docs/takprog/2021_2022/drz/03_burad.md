---
hide:
  - toc
---

# B3 - Burad

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	
	
	Nakon što se penzionisao u *Vrčinsoftu* i postao velemajstor programiranja na *Vrčinskoj Sili*, Marko je odlučio da nađe novi hobi. Pošto svi znaju da je Vrčin kišno mesto, odlučio je da skuplja kišu u svojih $N$ burića. 
	
	On ih je poređao u red s leva na desno i numerisao ih brojevima od $1$ do $N$, tako da je bure sa brojem $1$ najlevlje. Bure $i$ ima kapacitet od $a_i$ litara. 
	
	Marko zna da će narednih $M$ dana da pada kiša, ali na jako specifičan način -- $i$-tog dana kiša će padati tako da voda upada isključivo u buriće numerisane brojevima od $l_i$ do $r_i$ (uključujući i njih). Ako kiša dospeva u neko bure, u danu u njega upadne **tačno jedan litar** kiše. Ako se Marku ne svidi vremenska prognoza za taj dan, on ima mogućnost da prekrije sve buriće, kako kiša tog dana ne bi upala u njih.
	
	Marko voli da sakupi što više vode, ali još više mrzi kad mu se prelije neko bure. Pošto je okačio tastaturu o klin, zamolio je vas da izračunate -- koliko najmanje dana je potrebno da prekrije sve buriće, tako da se nijedno bure ne prelije (ne padne u njega više litara vode nego što mu je kapacitet)?
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza nalaze se pozitivni celi brojevi $N$ i $M$, gde je $N$ broj burića koje Marko poseduje, a $M$ broj kišnih dana. 
	
	U narednom redu, nalazi se $N$ nenegativnih celih brojeva, od kojih je $i$-ti broj baš $a_i$, kapacitet $i$-tog bureta.
	
	Narednih $M$ redova sadrže po dva pozitivna cela broja $l_i$ i $r_i$ koji opisuju kišne dane.
	
	## Opis izlaza
	
	U jedinom redu standardnog izlaza ispisati jedan broj - najmanji broj dana u kojim Marko mora prekriti buriće.
	
	## Ograničenja
	- $1 \leq N, M \leq 2\cdot10^5$
	- $0 \leq a_i \leq 10^9$, za svako $1 \leq i \leq N$
	- $1 \leq l_i \leq r_i \leq N$, za svako $1 \leq i \leq M$
	
	## Podzadaci
	
	1. (6 poena) $l_i = r_i$, za svako $1 \leq i \leq M$
	2. (7 poena) Ni u jedno bure neće padati kiša više od jedanput po vremenskoj prognozi
	3. (13 poena) $a_i \in \{0, 10^9\}$, za svako $1 \leq i \leq N$.
	4. (15 poena) $N, M \leq 2000$
	5. (59 poena) Bez dodatnih ograničenja.
	
	## Primeri
	
	### Primer 1
	
	### Ulaz
	
	```
	5 4
	3 1 0 0 3
	1 3
	1 2
	1 5
	4 5
	```
	
	### Izlaz
	
	```
	3
	```
	### Objašnjenje
	Potrebno je prekriti buriće svaki dan sem drugog, jer će inače kiša upasti u buriće kapaciteta $0$.
	
	### Primer 2
	
	### Ulaz
	
	```
	6 9
	4 1 2 3 1 2
	2 4
	1 3
	4 4
	1 4
	5 6
	3 4
	6 6
	3 3
	1 6
	```
	
	### Izlaz
	
	```
	4
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Mladen Puzić | Mladen Puzić | Mladen Puzić | Aleksa Plavšić |
	
	## Rešenje kada $l_i = r_i$
	Pošto će kiša svakog dana padati nad tačno jednim buretom, možemo svako bure gledati zasebno. Izbrojaćemo koliko litara je prognozirano da upadne u $i$-to bure, nazovimo taj broj $cnt_i$. Ukoliko $cnt_i > a_i$, znači da dolazi do prelivanja i moramo prekriti buriće $cnt_i - a_i$ dana. Uradimo to za svako $i$ i sumirajmo kako bismo dobili krajnje rešenje. Vremenska složenost je $O(N+M)$, a memorijska $O(N)$.
	
	## Rešenje kada u svako bure pada najviše jedan litar kiše
	Jedina mesta na kojima može doći do prelivanja jesu burad sa kapacitetom $0$, a pošto su svi intervali disjunktni, to znači da je ukupna dužina svih intervala do $N$, pa je dovoljno efikasno da za svaki dan prođemo kroz sve buriće u koje bi upala kiša i proverimo da li neki od njih ima kapacitet $0$. Vremenska složenost $O(N+M)$, a memorijska $O(N)$.
	
	## Rešenje kada $a_i \in \{0, 10^9\}$
	Jedina mesta na kojima može doći do prelivanja jesu burad sa kapacitetom $0$, u koje ne sme upasti ni litar kiše. Zato, Marko mora prekriti sve buriće na dane kada bi u makar jedno bure kapaciteta $0$ upala kiša, što je ekvivalentno sa proverom da li u intervalu nizu postoji $0$. Ovo možemo proveriti npr. binarnom pretragom nad indeksima gde se pojavljuje $0$ ili prefiksnim sumama kojim brojimo nule na prefiksu. Vremenska složenost $O(N+M)$ ili $O(N+MlogN)$, a memorijska $O(N)$.
	
	## Rešenje kada $N, M \leq 2000$
	Prvo je potrebno da odredimo koliko litara kiše je prognozirano za svako bure. To možemo jednostavno uraditi tako što za svaki dan prolazimo kroz sve buriće i uvećamo broj litara za jedan. Nazovimo taj broj litara za $i$-to bure $cnt_i$. Sada je potrebno da posmatramo isključivo buriće za koje važi $cnt_i > a_i$, odnosno one koji bi se prelili kada ništa ne bismo učinili. 
	
	Sada, idemo sleva nadesno i svaki put kada naiđemo na takvo bure, znamo da moramo da pokrijemo buriće na makar $cnt_i - a_i$ novih dana. Čuvajmo u nekom nizu sve dane za koje nismo odredili da li ćemo prekriti buriće taj dan (zvaćemo ih *neobrisani intervali*). Kad god moramo da obrišemo novi interval, obrisaćemo onaj interval koji sadrži $i$, a proseže se što je moguće dalje u desno. Ovo je optimalno, jer su tako najveće šanse da ćemo tim brisanjem smanjiti $cnt_j$ drugih *kritičnih* burića. Kada odaberemo takav interval, brišemo ga iz niza, i smanjujemo odgovarajuće elemente $cnt$ niza. Nastavljamo desno dok ne obradimo ceo niz. 
	
	Vremenska složenost je $O(NM)$, a memorijska $O(N+M)$.
	
	## Glavno rešenje
	Ideja iza ovog rešenja ista je kao za prethodno, samo je potrebno da sve uradimo efikasnije. Prvi deo, pronalaženje niza $cnt_i$, uradićemo konstrukcijom novog niza, $b$. Na početku, on će biti ispunjen nulama. Za svaki dan $i$, mi ćemo povećati $b_{l_i}$ za jedan, a smanjiti $b_{r_i+1}$ isto za jedan. Niz $cnt$ dobijamo kao niz prefiksnih suma nad nizom $b$.
	
	Drugi deo ćemo raditi slično kao u prethodnom rešenju, samo što ćemo umesto niza neobrisanih intervala, čuvaćemo skup (*std::multiset*), sortiran po desnom kraju intervala. Čuvaćemo samo one intervale koji sadrže trenutni element, dakle dodaćemo interval $j$ tek kad važi $l_j = i$, a izbaciti tek kad je obrisan ili kada $r_j = i$. Svaki put kada treba da obrišemo interval, obrisaćemo najveći u skupu. Slično se može uraditi i sa prioritetnim redom (*std::priority_queue*), sa malo dodatne analize.
	
	Vremenska složenost je $O(N+MlogN)$, a memorijska $O(N+M)$.
	
	``` cpp title="03_burad.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	int solve(int N, int M, vector<int> a, vector<pair<int, int> > days) {
	  sort(days.begin(), days.end());
	  int pref[N+2], ends[N+2];
	  fill(pref, pref+N+2, 0);
	  fill(ends, ends+N+2, 0);
	  for(auto x : days) {
	    pref[x.first]++;
	    pref[x.second+1]--;
	  }
	  for(int i = 1; i <= N; i++) {
	    pref[i] += pref[i-1];
	  }
	  priority_queue<int> pq;
	  int idx = 0, res = 0, active = 0;
	  for(int i = 1; i <= N; i++) {
	    while(idx < M && days[idx].first == i) {
	      pq.push(days[idx].second);
	      idx++;
	    }
	    while(pref[i] > a[i-1] && pref[i]-a[i-1] > active) {
	      int r = pq.top(); pq.pop();
	      ends[r]++;
	      active++;
	      res++;
	    }
	    active -= ends[i];
	  }
	  return res;
	}
	
	int main() {
	    int N, M; cin >> N >> M;
	    vector<int> a;
	    vector<pair<int, int> > days;
	    for(int i = 1; i <= N; i++) {
	        int x; cin >> x;
	        a.push_back(x);
	    }
	    for(int i = 0; i < M; i++) {
	        int x, y; cin >> x >> y;
	        days.push_back({x, y});
	    }
	    cout << solve(N, M, a, days);
	}

	```
