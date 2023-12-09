---
hide:
  - toc
---

# 1 - Poslovan čovek

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1300ms | 256MB |
	
	
	Ovo je priča o Huanu, momku koji je imao stila. On je živeo negde dole, severno-južno od Brazila. Huan je mnogo voleo da radi, tako da je imao dva posla. Svakog dana on je mogao da bira na koji od poslova će otići. Ako bi izabrao prvi posao, na kraju dana zaradio bi $A$ funti (isti iznos bez obzira na to koji je dan). Ako $i$-tog dana Huan izabere drugi posao, on će tog dana zaraditi $B_i$ funti. Kada zaradi više od $C$ funti na drugom poslu, njegova plata će biti duplo veća nego planirano na drugom poslu. To znači ako Huan izabere da radi drugi posao dana $j > k$, gde je $k$ prvi dan kada je Huan ukupno zaradio više od $C$ funti na drugom poslu, onda će Huanova plata $j$-tog dana biti $2 \cdot B_j$, umesto $B_j$ funti. Pomozite Huanu i izračunajte koliko najviše novca može da zaradi u narednih $N$ dana.
	
	
	
	## Opis ulaza
	Prvi red standardnog ulaza sadrži tri cela broja $N$, $A$, $C$, broj dana koji će Huan raditi, Huanova dnevna zarada na prvom poslu i granica nakon koje će se njegova plata na drugom poslu duplirati.
	
	
	
	Drugi red standardnog ulaza sadrži niz $B$ dužine $N$, gde $B_i$ predstavlja Huanovu potencijalnu platu ako izabere da $i$-tog dana radi drugi posao. 
	
	
	
	## Opis izlaza
	U jednom redu standardnog izlaza ispisati maksimalnu zaradu u funtama koju može Huan imati nakon $N$ dana.
	
	
	
	## Ograničenja
	- $1 \leq N \leq 2\cdot 10^5$
	- $1 \leq A \leq 10^9$
	- $0 \leq C \leq 10^9$
	- $1 \leq B_i \leq 10^9$
	
	
	
	## Podzadaci
	- (11 poena): $1 \leq N \leq 20$
	- (12 poena): $C = 0$
	- (10 poena): Važi $B_i = B_j$ za svako $1\leq i, j \leq N$.
	- (18 poena): Važi $B_i \leq B_{i + 1}$, za svako $1 \leq i < N$
	- (25 poena): Sve vrednosti sa ulaza nisu veće od $2000$.
	- (24 poena): Nema dodatnih ograničenja.
	
	
	
	## Primer 1
	### Ulaz
	```
	4 5 3
	1 4 2 7
	```
	### Izlaz
	```
	28
	```
	### Objašnjenje
	Huan će birati poslove po sledećem rasporedu:
	
	
	
	1. dan - prvi posao, zarada 5 funti
	2. dan - drugi posao, zarada 4 funte, od ovog trenutka kreće da se duplira zarada na drugom poslu
	3. dan - prvi posao, zarada 5 funti
	4. dan - drugi posao, zarada 14 funti
	
	
	
	Huan će ukupno zaraditi 5 + 4 + 5 + 14 = 28 funti.
	
	
	
	## Primer 2
	### Ulaz
	```
	3 1000000000 3
	1 1 1
	```
	### Izlaz
	
	```
	3000000000
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksa Plavšić | Mladen Puzić | Pavle Martinović |
	
	## Rešenje kada $N \leq 20$
	Pošto za svaki dan postoji dve mogućnosti, otići na prvi ili drugi posao, ukupno postoji $2^N$ mogućnosti. Možemo probati svaku mogućnost, simulirati zaradu novca i odabrati optimalni odabir poslova.
	
	Vremenska složenost je $O(N\cdot 2^N)$, a memorijska $O(N)$.
	
	## Rešenje kada $C = 0$
	Pošto je od početka ispunio kvotu za dupliranu platu na drugom poslu, potrebno je $i$-tog dana otići na prvi posao ukoliko je $A \leq 2\cdot B_i$,  u suprotnom otići na drugi posao. 
	
	Vremenska i memorijska složenost je $O(N)$.
	
	## Rešenje kada $B_i = B_j$
	Pošto je plata na drugom poslu ista svakog dana, nazovimo je $B$. Fiksirajmo $k$ kao prvi dan kada je ispunjena kvota (prvi dan kad bi plata na drugom poslu bila $2\cdot B$), isprobajmo sve brojeve od $1$ do $N$, tim redom. 
	
	Kako bi dan $k$ bio prvi kad je plata duplirana, potrebno je da Huan u prvih $k-1$ dana tačno $\lceil \frac{C}{B} \rceil$ dana ode na drugi posao (ukoliko $\lceil \frac{C}{B} \rceil > k-1$, ta vrednost za $k$ nije moguća). Samim tim rezultat za fiksno $k$ je 
	
	$$
	\lceil \frac{C}{B} \rceil \cdot B + (k-1-\lceil \frac{C}{B} \rceil) \cdot A + (N-k+1) \cdot \max(A, 2\cdot B),
	$$
	
	što se može lako izračunati.
	
	Vremenska i memorijska složenost je $O(N)$.
	
	## Rešenje kada $B_i \leq B_{i+1}$
	Slično prethodnom rešenju, fiksirajmo $k$. U prvih $k-1$ dana, na drugi posao će sigurno otići kada važi $B_i \geq A$. Ukoliko sa tim danima nije ispunio kvotu, potrebno je da na drugi posao ode još nekoliko dana dok ne ispuni kvotu, uvek idući danima kada je najveće $B_i$. Pošto mu se već ne isplati, želi da što manje dana potroši na to. 
	
	Pošto je niz $B$ neopadajući, možemo primetiti da će za neko $0 \leq t_1 \leq k-1$ prvih $t_1$ dana otići na prvi posao, a danima $[t_1+1, k-1]$ otići na drugi posao. 
	
	Sem toga, postoji neko $k \leq t_2 \leq N$, takvo da se danima $[t_2, N]$ više isplati otići na drugi posao (ako $k$-tog dana ispunimo kvotu). Dakle, rezultat za fiksno $k$ je:
	
	$$
	t_1 \cdot A +\sum_{i = t_1+1}^{k-1} B_i  + (t_2-k)\cdot A + 2\cdot \sum_{i = t_2}^{N} B_i 
	$$
	
	Brojeve $t_1$ i $t_2$ možemo naći binarnom pretragom, dok rezultat možemo efikasno izračunati prefiksnom sumom nad nizom $B$. Ponovo moramo paziti da je moguće da nam fiksirana vrednost može biti $k$.
	
	Vremenska složenost je $O(NlogN)$, a memorijska $O(N)$.
	
	## Rešenje kada $N, A, C, B_i \leq 2000$
	Ovo rešenje je veoma slično prethodnom - pošto je $N$ malo, za svako $k$ možemo iznova sortirati niz $B$ na intervalima $[1, k-1]$ i $[k, N]$ i primeniti prethodno rešenje. 
	
	Vremenska složenost je $O(N^2logN)$, a memorijska $O(N)$.
	
	## Glavno rešenje
	Ponovo fiksiramo $k$ i idemo sleva nadesno, odvojeno rešavamo intervale $[1, k-1]$ i $[k, N]$. Za desni interval, jednostavno ćemo izračunati sufiksne sume $suf_i = suf_{i+1} + \max(A, 2\cdot B_j)$ koje ćemo kasnije koristiti u krajnjem rešenju.
	
	Što se tiče levog intervala, spomenuli smo da postoje oni dani kada se Huanu uvek isplati da ode na drugi posao ($B_i \geq A$) i oni kad ide na drugi posao samo kako bi ispunio kvotu. Za prvi tip, dovoljno je održavati njihovu sumu $Bsum$ kako menjamo $k$. Za drugi tip je komplikovanije, jer može da se desi da za jedno $k$ ode na drugi posao, a za sledeće $k$ istog dana ode na prvi posao. 
	
	Zato ćemo održavati min hip (*priority_queue*) sa najvećim vrednostima $B$ koji **nisu** prvog tipa (dakle, za koje važi $B_i < A$). Čuvaćemo u njemu sve vrednosti koje su nam potrebne da, zajedno sa danima prvog tipa, ispuni kvotu. Nazovimo sumu elemenata u hipu $Hsum$. Održavamo hip tako da u njemu imamo što manje elemenata, a važi $Bsum + Hsum \geq C$. Kada se $k$ premesti sa $i-1$ na $i$, ukoliko je $B_i \leq A$ onda uvećavamo $Bsum$ i potencijalno brišemo neke najmanje elemente iz hipa, ukoliko nam više nisu potrebni, smanjujući $Hsum$. Ukoliko važi $B_i < A$, onda ćemo prvo dodati $B_i$ u hip i povećati $Hsum$, a onda potencijalno obrisati najmanje elemente koji su višak (to može biti i element koji smo upravo dodali) i smanjujemo $Hsum$. 
	
	Rezultat za fiksno $k$ je onda $Hsum + Bsum + suf_i$.
	
	Vremenska složenost je $O(NlogN)$, a memorijska $O(N)$.
	
	``` cpp title="01_poslovan_covek.cpp" linenums="1"
	#include<bits/stdc++.h>
	
	using namespace std;
	
	const int maxN = 2e5 + 10;
	int N, A, C;
	int B[maxN];
	long long sufBest[maxN];
	
	int main() {
	
		cin >> N >> A >> C;
	    
	  for (int i = 1 ; i <= N; i++) {
	    cin >> B[i];
	  }
	
	  for (int i = N; i > 0; i--) {
	    sufBest[i] = sufBest[i  + 1] + max(A, 2 * B[i]);
	  }
	  
	  multiset<int> taken;
	  long long setSum = 0;
	  long long answer = 0;
	  long long totalSum = 0;
	  for (int i = 1; i <= N; i++) {
	   	totalSum+=max(A, B[i]);
	    taken.insert(B[i]);
	    setSum+=B[i];
	    while(setSum - *taken.begin() > C && *taken.begin() < A) {
	     	setSum-= *taken.begin();
	     	taken.erase(taken.begin());
	    }
	
	    if (setSum > C) {
	      int setSize = taken.size();
	      answer = max(answer, setSum + 1ll * (i - setSize) * A  + sufBest[i + 1]);
	    }
	  }
	
	  answer = max(answer, totalSum);
	
	  cout << answer << endl;
	}
	```
