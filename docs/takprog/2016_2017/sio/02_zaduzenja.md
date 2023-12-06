---
hide:
  - toc
---

# 2 - Zaduženja

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 64MB |
	
	Članovi Komisije su vrlo zauzeti ljudi i uvek se pogodi da najviše obaveza (koje nemaju veze sa SIO-om) imaju neposredno pred SIO. Nažalost, neko mora i da smišlja zadatke i pravi test primere pa se uvek uoči SIO-a organizuje popularna *trka zaduženja*. 
	
	U komisiji ima $k$ članova i svi žive u jednom gradu koji ima $n$ raskrsnica numerisanih brojevima od $1$ do $n$ i $m$ **dvosmernih** ulica koje povezuju neke od raskrsnica. Za svakog člana komisije je poznato na kojoj raskrsnici živi i za svaku ulicu je poznata njena dužina u metrima. Svake godine se odabere *kružna staza* -- niz **od nekoliko (bar 3) različitih raskrsnica** $x_1, x_2, \ldots, x_l$ pri čemu **između svake dve uzastopne raskrnice na kružnoj stazi postoji neka ulica** (tj. postoje ulice između raskrsnica $x_1$ i $x_2$, $x_2$ i $x_3$, $\ldots$, $x_l$ i $x_1$). Ulice kružne staze se pokrivaju posebnim materijalom pogodnim za trčanje -- kada neko trči njima, on prelazi $1$ metar za $a$ sekundi dok na ostalim ulicama prelazi $1$ metar za $b$ sekundi (dakle, svi članovi komisije trče istom brzinom). Svaki član komisije mora trčati **od svoje raskrsnice do neke raskrsnice na kružnoj stazi (po izboru) a zatim optrčati tačno jedan krug kružne staze**. Ko prvi završi trku, ide svojim izmišljenim obavezama a ostali moraju da prave test primere.
	
	Ispostavlja se da članovi Komisije zbog svojih obaveza nisu imali vremena da treniraju pa im je mnogo bitnije da pobednik bude odlučen što pre (jer tada ostali mogu prekinuti tu napornu aktivnost) nego da pobede u trci. Zato planiraju da urgiraju kod gradskih vlasti da se ove godine **izabere takva kružna staza za koju važi da je vreme potrebno pobedniku da završi trku -- najmanje moguće**. Pomozite članovima Komisije da odaberu takvu kružnu stazu kako bi stigli da naprave test primere za ovaj zadatak.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se pet prirodnih brojeva $n$, $m$, $k$, $a$ i $b$ koji, redom, predstavljaju podatke iz teksta zadatka. U narednom redu nalazi se $k$ prirodnih brojeva $r_i$ -- redni brojevi raskrsnica na kojima žive članovi komisije. U narednih $m$ redova nalaze se po tri broja $x_i$, $y_i$ i $z_i$ koji označavaju  da između raskrsnice broj $x_i$ i raskrsnice broj $y_i$ postoji ulica dužine $z_i$ metara.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati jedan ceo broj - najmanji vreme (u sekundama) potrebno da pobednik završi trku pri optimalnom izboru kružne staze. **Uvek će postojati bar jedno rešenje.**
	
	## Primer 1
	### Ulaz
	```
	8 12 3 1 2
	4 2 7
	1 5 1
	7 5 6
	2 7 1
	7 3 11
	8 1 7
	2 3 20
	4 6 2
	1 6 2
	2 4 10
	8 6 8
	7 8 15
	5 8 5
	```
	
	### Izlaz
	```
	20
	```
	
	## Primer 2
	### Ulaz
	```
	3 3 1 10 5
	2
	1 2 11
	2 3 12
	3 1 13
	```
	
	### Izlaz
	```
	360
	```
	
	## Objašnjenje primera
	U prvom primeru imamo ukupno 8 raskrsnica i 3 člana Komisije koji žive na raskrsnicama 4, 2 i 7. Optimalno je odabrati kružnu stazu 5-8-6-1-5. Tada pri optimalnom trčanju, član Komisije koji živi na raskrsnici broj 4 trči do staze ulicom 4-6 dužine 2 a zatim trči stazom (ulicama 6-8, 8-5, 5-1 i 1-6) dok ne obiđe celu stazu, tj. dok se ne vrati na raskrsnicu 6. Ukupno mu je trebalo $2 \cdot b + 8 \cdot a + 5 \cdot a + 1 \cdot a + 2 \cdot a$ = 20 sekundi. Članovi komisije sa raskrsnica 2 i 7 bi, redom, završili trku posle 30 i 28 sekundi; dakle, za ovaj izbor kružne staze, član sa raskrsnice 4 je pobednik i trka se prekida posle 20 sekundi. Ne postoji izbor kružne staze tako da pobednik bude odlučen za manje od 20 sekundi.
	
	## Ograničenja i podzadaci
	* $3 \leq n \leq 500$
	* $n \leq m \leq n(n-1)/2$
	* $1 \leq k \leq n$
	* $0 \leq a, b \leq 10^6$
	* $1 \leq r_i \leq n$, $r_i \neq r_j$ za $i \neq j$
	* $1 \leq x_i, y_i \leq n$, $x_i \neq y_i$, $1 \leq z_i \leq 10^9$
	* Između svake dve raskrsnice postoji najviše jedna ulica. 
	* Moguće je doći od bilo koje raskrsnice do bilo koje druge raskrsnice koristeći date ulice.
	
	Postoji $6$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [8 poena]: $n \leq 10$.
	* Podzadatak 2 [15 poena]: $n \leq 80$.
	* Podzadatak 3 [18 poena]: $a = 0$.
	* Podzadatak 4 [20 poena]: $b = 0$.
	* Podzadatak 5 [16 poena]: $k = 1$.
	* Podzadatak 6 [23 poena]: Nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Ivan Dejković |
	
	Označimo optimalnu stazu (ciklus u grafu) sa C a njenu ukupnu dužinu sa w©. Jasno je da će tada traženo vreme biti
	
	a * w© + b * minimalno_rastojanje(neki član komisije, ciklus C)
	
	pa ovaj izraz treba minimizovati po C. Izraz se može uprostiti ako za svaki čvor unapred izračunamo A(u) - rastojanje od čvora u do njemu najbližeg člana komisije pomnoženo brojem b (nazovimo ovo “težina čvora”). Za ovo nam je dovoljan Floyd-Warshall ili puštanje Dijkstre iz svakog člana komisije (složenost je O(n^3) ili O(kmlog(n))). Dakle, potrebno je pronaći ciklus C za koji važi da je a*w© + min{A(u) | u iz C} minimalno.
	
	Problem možemo posmatrati i iz drugog ugla: za čvor u, označimo sa MinCyc(u) dužinu najkraćeg ciklusa kome je čvor u čvor minimalne težine (dakle, NE najkraći od SVIH ciklusa koji sadrže u). Tada je
	minimum po ciklusima C (a*w© + min{A(u) | u iz C}) = min po čvorovima u (MinCyc(u) + A(u))
	pa je za svaki čvor dovoljno izračunati vrednost MinCyc.
	
	Najtrivijalniji način je: za svaki čvor u, izbaciti iz grafa sve čvorove težine ne veće od u (uključujući i sam čvor u), naći sva najkraća rastojanja d[x][y] između čvorova novog grafa i staviti MinCyc(u) = minimum (w(u,x) + w(u,y) + d[x][y]) gde su x i y susedi čvora u koji su ostali u novom grafu. Složenost ovog pristupa je O(n^4) ili O(n^2 * m * log(n)).
	
	Ukoliko sortiramo čvorove opadajuće po vrednosti A(u), tada važi MinCyc(u) = najkraći od SVIH ciklusa na skupu čvorova {1, 2, …, u} koji sadrži čvor u. Sada možemo vrednosti MinCyc računati modifikovanim Floyd-Warshall algoritmom: ovaj algoritam ima osobinu da neposredno pre k-tog koraka (spoljašnja od 3 ugnježdene for petlje) ima izračunate vrednosti d[u][v] - najkraće rastojanje od u do v preko prvih k-1 čvorova. Prema tome, za trenutni čvor k važi MinCyc(k) = minimum (w(k,u) + w(k,v) + d[u][v]) po svim susedima u,v čvora k za koje je u < k, v < k i d[u][v] != INF. Ako ovaj minimum računamo na početku svake spoljašnje for petlje, složenost Floyd-Warshalla ostaje O(n^3) i imamo vrednosti svih MinCyc(u) što je dovoljno za rešenje zadatka.
	
	Podzadaci uključuju slučajeve za čije je rešavanje dovoljan pristup složenosti O(n^4) poput gore pomenutog, slučajeve gde je a = 0 (tada je rešenje min A(u) među svim čvorovima u koji pripadaju bar jednom ciklusu) i slučajeve gde je b = 0 (klasično traženje najkraćeg ciklusa u grafu). Zadatak se može uraditi i puštanjem Dijkstre iz svih čvorova sa komisijama (istovremeno) i fiksiranjem čvora koji će biti “ulaz” u kružnu stazu a zatim za njega računati najkraći ciklus koji ga sadrži i sastavljen je od čvorova “ispod njega” u Dijkstra-stablu (ovo je suštinski ista ideja kao i u gore pomenutom rešenju jer je redosled obilaska Dijsktrom rastući po vrednostima A).
	
	``` cpp title="02_zaduzenja.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	#include <vector>
	
	using namespace std;
	
	const int MAX_N = 510;
	const int MAX_M = MAX_N * MAX_N;
	const long long INFTY = 1000000000000000000LL;
	
	int n, m, k, a, b;
	int home[MAX_N];
	int x[MAX_M], y[MAX_M], z[MAX_M];
	
	//----------------------------------------
	long long d[MAX_N][MAX_N];
	long long weight[MAX_N][MAX_N];
	
	struct minDist
	{
		int ind;
		long long val;
	};
	
	bool cmp(const minDist& a, const minDist& b)
	{
		return (a.val > b.val);
	}
	
	minDist s[MAX_N];
	long long val[MAX_N];
	int inv[MAX_N];
	
	long long FindShortestTime(int n, int m, int k, int a, int b, int home[], int x[], int y[], int z[]) 
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = INFTY;
			}
		}
		for (int i = 1; i <= n; i++) d[i][i] = 0LL;
	
		for (int i = 1; i <= m; i++)
		{
			d[x[i]][y[i]] = z[i];
			d[y[i]][x[i]] = z[i];
		}
	
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	
		for (int i = 1; i <= n; i++)
		{
			s[i].ind = i;
			s[i].val = INFTY;
			for (int j = 1; j <= k; j++)
			{
				s[i].val = min(s[i].val, d[i][home[j]]);
			}
		}
		sort(s + 1, s + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			inv[s[i].ind] = i;
			val[i] = s[i].val;
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = INFTY;
				weight[i][j] = -1;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int u = inv[x[i]];
			int v = inv[y[i]];
			d[u][v] = z[i];
			d[v][u] = z[i];
			weight[u][v] = z[i];
			weight[v][u] = z[i];
		}
	
		long long sol = INFTY;
	
		for (int w = 1; w <= n; w++)
		{
			for (int u = 1; u < w - 1; u ++)
			{
				for (int v = u + 1; v < w; v++)
				{
					if (weight[w][u] != -1 && weight[w][v] != -1 && d[u][v] != INFTY)
					{
						sol = min(sol, val[w] * b + (weight[w][u] + weight[w][v] + d[u][v]) * a);
					}
				}
			}
	
			for (int u = 1; u <= n; u++)
			{
				for (int v = 1; v <= n; v++)
				{
					d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
				}
			}
		}
	
		return sol;
	}
	
	int main()
	{
		scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &home[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
		}
	
		printf("%lld\n", FindShortestTime(n, m, k, a, b, home, x, y, z));
	
		return 0;
	}
	```
