---
hide:
  - toc
---

# B3 - Anti-žmurke

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Članovi Tajne komisije u senci su prilično besposleni ovih dana pa u obližnjem parku igraju anti-žmurke. Anti-žmurke su potezna dečja igra u kojoj se jedan igrač krije dok ga jedan ili više igrača, koje nazivamo tragačima, traži.
	
	Park je pravougaonih dimenzija i podeljen je na jedinične kvadrate. Svako kvadratno polje predstavlja žbun u kojem se igrač može sakriti. Za svakog tragača je poznata njegova početna pozicija kao i brzina koja predstavlja koliko polja može preći u jednom potezu. Sa trenutnog polja tragač može preći samo na neko od četiri susedna polja. Dva polja su susedna ukoliko imaju zajedničku stranicu. Svi tragači u isto vreme kreću sa potragom.
	
	Red je na malog Zokija da se sakrije. On želi da bude što bolji u ovoj igri pa želi da se sakrije u žbunu na polju čija je **skrivenost** najveća moguća. **Skrivenost** nekog polja je celobrojna vrednost koja predstavlja **u koliko najmanje poteza neki od tragača može stići do tog polja krećući se najkraćim putem**. Pomozite Zokiju da pronađe polje sa najvećom skrivenošću jer su tragači već počeli sa odbrojavanjem.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se dva prirodna broja $N$, $M$ i $K$, koji predstavljaju dimenzije parka i broj tragača, tim redom. U narednih $K$ redova slede koordinate početne pozicije $X_i$ i $Y_i$ (redni broj reda i kolone) i brzina $V_i$ za svakog od tragača. Redovi su numerisani od $1$ do $N$ odozgo nadole a kolone od $1$ do $M$ sleva nadesno.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati dva broja $i$ i $j$ – redni broj reda i kolone polja na kojem se Zoki treba sakriti u skladu sa svojim zahtevom. Ukoliko postoji više rešenja ispisati bilo koje.
	
	## Primer 1
	### Ulaz
	```
	5 7 2
	1 2 3
	4 4 1
	```
	
	### Izlaz
	```
	3 7
	```
	
	## Objašnjenje primera
	```
	Slika 1  Slika 2  Slika 3
	1011122  6543456  1011122
	1111222  5432345  1111222
	1112223  4321234  1111223
	2122233  3210123  2110123
	2222333  4321234  2221233
	```
	
	Slike 1 i 2 predstavljaju koliko najmanje poteza je potrebno prvom i drugom tragaču da dođu do odgovarajućih polja u parku, tim redom. Na slici 3 vidimo **skrivenost** svakog polja. Primetimo da je najveća **skrivenost** nekog polja jednaka 3 i da ukupno takvih polja ima 4. Bilo koje od tih polja je rešenje.
	
	## Ograničenja
	* $1\leq N,M,K \leq 1.000$
	* $1\leq V_i \leq 10^9$
	* Nikoja dva tragača neće imati iste koordinate.
	
	## Napomena
	Test primeri su podeljeni u 5 disjuntknih grupa:
	
	* U test primerima vrednim 10 poena važi $K=1$.
	* U test primerima vrednim 20 poena važi $1\leq N,M\leq 100$.
	* U test primerima vrednim 20 poena važi da su brzine svih tragača jednake.
	* U test primerima vrednim 20 poena važi $1\leq V_i\leq 50$.
	* U test primerima vrednim 30 poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Dimić | Dimitrije Dimić | Aleksandar Višnjić | Nikola Milosavljević |
	
	## Prva dva podzadatka:
	Tragač $i$ čini da neko polje $(x,y)$ ima skrivenost najviše $\lceil\frac{|X_i-x|+|Y_i-y|}{V_i}\rceil$. Skrivenost polja je minimalna skrivenost od svih tragača. Ako za svako polje to odredimo preko grube sile imamo algoritam složenosti $O(N\cdot M\cdot K)$.
	
	## Treći podzadatak:
	Potrebno je brže proveriti skrivenost svakog polja. Pošto su brzine jednake, to možemo uraditi pretragom u širini sa izvorom u koordinatama svakog tragača. Izračunaćemo polje koje ima najveću udaljenost od svakog tragača i podelićemo je sa konstantnom brzinom kako bismo dobili skrivenost. Složenost je $O(N\cdot M)$.
	
	## Glavno rešenje:
	Kada brzine nisu jednake, možemo raditi binarnu pretragu po rešenju: potrebno je proveriti da li je datu skrivenost moguće postići. Tačnije, ako je skrivenost $S$ moguća, za svakog tragača $i$ znamo da pokriva sva polja na udaljenosti $S\cdot V_i$ i da nakon toga ostaje bar jedno slobodno polje (i njega je potrebno ispisati za najveću skrivenost). Ako ne ostaje slobodno polje, tražena skrivenost nije moguća.  Proveru da li ono postoji radimo pretragom u širini, ali ne preko reda nego preko niza vektora: za svaku "dubinu" pamtimo sva polja koja se nalaze na njoj. Susedna polja koja nisu posećena u sledećem koraku imaju dubinu za jednu manju od trenutne. Najmanja moguća dubina posećenog polja je $0$. Izvori imaju koordinate $(X_i,Y_i)$ i dubinu $S\cdot V_i$.
	
	``` cpp title="03_anti_zmurke.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	
	using namespace std;
	
	const int MAX_N = 2010;
	const int MAX_K = 1000100;
	
	struct seeker
	{
		int x, y, v;
	};
	
	int n, m, k;
	seeker s[MAX_K];
	int solX, solY;
	int d[MAX_N][MAX_N];
	
	bool covered(int time)
	{
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= k; i++)
		{
			int r = time * s[i].v;  // time <= n + m, s[i].v <= n + m
			if (r > n + m) r = n + m;  // r <= n + m
	
			int x = s[i].x - r;  // od vrha do sredine
			int y = s[i].y;
			for (int j = 0; j <= r; j++)
			{
				d[max(x + j, 1)][max(y - j, 1)] += 1;
				d[max(x + j, 1)][min(y + j, m) + 1] -= 1;
			}
	
			x = s[i].x + r;  // od dna do sredine
			y = s[i].y;
			for (int j = 0; j < r; j++)
			{
				d[min(x - j, n)][max(y - j, 1)] += 1;
				d[min(x - j, n)][min(y + j, m) + 1] -= 1;
			}
		}
	
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j <= m; j++)
			{
				sum = sum + d[i][j];
				if (sum == 0)
				{
					solX = i;
					solY = j;
					return false;
				}
			}
		}
	
		return true;
	}
	
	int main()
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].v);
			if (s[i].v > n + m) s[i].v = n + m;
		}
		
		int l = 0, r = n + m;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (covered(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		printf("%d %d\n", solX, solY);
		return 0;
	}

	```
