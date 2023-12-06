---
hide:
  - toc
---

# 6 - Pogled

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Članovi Komisije su u periodima dokolice došli na zanimljivu ideju da na zgradama jednog mesta naprave vidikovce. Zgrade su poređane na nekoj zamišljenoj liniji. Na svakoj od njih mogu biti postavljena najviše dva uređaja za posmatranje od kojih je jedan usmeren prema početku tog niza zgrada (na levu stranu), a drugi prema kraju niza zgrada (na desnu stranu).  Međutim, postavljanje uređaja koji je okrenut prema početku se može izvesti samo ako između zgrade na koji se uređaj postavlja i početka niza ne postoji zgrada veće visine. Slično postavljanje uređaja koji je okrenut prema kraju se može izvesti samo ako između te zgrade i kraja niza ne postoji zgrada veće visine. Dozvoljeno je srušiti neke zgrade, ako se time dobija mogućnost postavljanja uređaja za posmatranje na nekim zgradama. Za svaku zgradu je poznata cena rušenja. Postavljanje svakog uređaja donosi određenu zaradu i za svaku zgradu su poznate zarada ako je postavljen uređaj koji je okrenut na levo i zarada od uređaja koji je okrenut na desno. Ukupna zarada od postavljenih uređaja je jednaka razlici zbira zarada od postavljenih uređaja i troškova rušenja zgrada koje treba srušiti. Zbog zauzetosti nekim drugim aktivnostima, oni ne mogu da odvoje vreme i da odrede koje zgrade treba srušiti i gde postaviti uređaje tako da zarada bude što veća. Pomozite im da izračunaju najveću moguću zaradu koja se može dostići postavljanjem uređaja (uz neophodna rušenja).
	
	## Opis ulaza 
	U prvom redu se nalazi jedan prirodan broj: $n$ - broj zgrada.
	U narednih $n$ redova se nalazi po $4$ broja i oni predstavljaju podatke za odgovarajuću zgradu: visina zgrade, cena rušenja zgrade, zarada ako na njoj postoji uređaj okrenut ulevo (pri čemu levo nema niti jedna zgrada veće visine, tj. sve zgrade koje su bile veće visine su srušene) i zarada ako je na zgradi postavljen uređaj koji je okrenut udesno (pri čemu su zgrade veće visine desno od te zgrade srušene). Visine zgrada su različiti brojevi, tj. ne postoje dve zgrade iste visine.
	
	## Opis izlaza
	U prvom redu izlaza ispisati maksimalnu moguću zaradu koja predstavlja razliku zbira svih zarada od uređaja raspoređenih na zgradama i zbira troškova rušenja zgrada koje su morale da budu srušene.
	
	## Primer 1
	### Ulaz
	```
	10
	1041 18 23 27
	1169 29 16 29
	1962 14 23 23
	1281 27 29 28
	1995 21 29 26
	1391 14 22 13
	1815 19 26 29
	1718 18 20 13
	1771 25 29 18
	1837 15 14 26
	```
	### Izlaz
	```
	149
	```
	
	## Objašnjenje primera
	Ako se rasporede uređaji na zgradama 1, 2, 3 i 5 (zgrade su numerisane brojevima od 1 do $n$, sleva nadesno) tako da su okrenuti levo, zbir zarada će biti $23+16+23+29 = 91$. Ako se na zgradama 5, 7, 9 rasporede uređaji tako da gledaju desno, mora se srušiti zgrada broj 10. Zbir zarada od postavljenih uređaja je $26+29+18 = 73$. Rušenje zgrade 10 košta 15. Tako je ukupna zarada $91 + 73 - 15 = 149$. 
	
	## Primer 2
	### Ulaz
	```
	8
	1771 25 14 13
	1270 21 24 16
	1018 19 23 24
	1729 26 25 16
	1817 18 26 22
	1861 26 13 18
	1541 19 20 23
	1645 25 14 17
	
	```
	### Izlaz
	```
	98
	```
	
	## Ograničenja i podzadaci
	* Ukupan broj zgrada nije veći od $100.000$ ($n\leq 100.000$).
	* Visine zgrada su celi brojevi između $1$ i $1.000.000.000$.
	* Cene rušenja zgrada su celi brojevi između $0$ i $2.000.000$.
	* Zarade od uređaja su celi brojevi između  $1$ i $20.000$.
	
	Postoje $4$ podzadatka u kojima dodatno važi:
	
	* Podzadatak 1 [$16$ poena]: $n \leq 1000$. 
	* Podzadatak 2 [$12$ poena]: cene rušenja zgrada su između $1.000.000$ i $2.000.000$, a zarade od postavljanja uređaja za posmatranje između $5$ i $10$.
	* Podzadatak 3 [$25$ poena]: cene rušenja zgrada su jednake nuli (za svaku od zgrada). 
	* Podzadatak 4 [$47$ poena]: nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Dragan Urošević | Nikola Milosavljević | Dimitrije Erdeljan i Ivan Stošić |
	
	Neka je L[i] = optimalna zarada za prvih i zgrada ukoliko postavljamo samo uređaje okrenute ulevo i poslednji postavljeni uređaj je na i-toj zgradi. Analgo se definiše R[i] za desne uređaje i nije teško zaključiti da je rešenje zadatka max {L[i] + R[i]} i da se ova dva niza računaju simetrično pa nadalje gledamo samo za L[i]. Neka su h[], v[] i c[] visine, zarade i cene rušenja, redom. Zadatak rešavamo dinamičkim programiranjem. Važi
	
	(1) L[i] = v[i] + maximum { L[j] - suma {c[k] | j < k < i, h[k] > h[i]} | j < i, h[j] < h[i] }
	
	(sa desne strane je maximum po svim zgradama j < i koje su niže od i; to je kandidat za pretposlednju zgradu, a moramo srušiti sve zgrade između j i i koje su više od h[i] dok će cena preostaih rušenja zgrada viših od h[i] a levo od j biti uračunata u L[j] jer je h[j] < h[i]). U cilju nalaženja boljeg rešenja od O(n^2), jedan od načina je da se dinamika radi po visinama a ne redom s leva udesno; to ujedno omogućava da ne moramo da proveravamo uslov h[j] < h[i] u (1). Za dato i treba nam indeks j < i za koji je vrednost
	
	L[j] - suma {c[k] | j < k < i, h[k] > h[i]} (*)
	
	maksimalna. Međutim, primetimo da (*) dostiže maksimum u indeksu j ako i smo ako izraz
	
	L[j] - suma {c[k] | j < k, h[k] > h[i]} (**)
	
	dostiže maksimum maksimum u indeksu j (ostatak sume ne zavisi od j). Ovim smo izbacili parametar i iz granica pa sada možemo prebaciti priču na segmentno stablo i računanje nekih upita.
	
	Neka su na početku svi L[i] = -INF. Posmatrajmo niz A dužine n koji je u i-tom koraku dinamike (idemo od najmanje do najveće zgrade) definisan sa (uzimamo da je h[0] = 0)
	
	(2) A[j] = L[j] - suma {c[k] | j < k, h[k] > h[i]}
	
	(dakle, na početku za sve j važi A[j] = -INF - suma {c[k] | j < k}). Kako računamo vrednosti L[i] redom po visinama zgrada, treba odraditi n koraka i u i-tom koraku:
	
	a) Odrediti L[i] kao L[i] = v[i] + max(A[1],A[2],…,A[i]) + suma { c[k] | i < k, h[k] > h[i]};
	b) Update-ovati niz A, tj. povećati A[i] za (L[i] + INF) i za sve j < i povećati A[j] za c[i].
	
	Formula iz a) je tačna jer zamenom A[i] iz (2) dobijamo (1) (do tada su izračunati svi A[j] za h[j] < h[i]). Deo “+ suma…” je tu da bismo nadoknadili razliku između (*) i (**). Kod dela b), menja se više elemenata niza A na osnovu definicije (2). Obe ove operacije možemo raditi u složenosti O(log n) - dovoljno nam je segmetno stablo nad nizom A koje podržava “vrati maximum na segmentu” i “povećaj sve elemente iz datog segmenta za dati broj” a to je max-segmento sa lazy propagation-om.
	Za upit U(i) = suma { c[k] | i < k, h[k] > h[i]} možemo koristiti (drugo) suma-segmentno stablo nad nizom c[] pri čemu u i-tom koraku vraćamo sumu na segmentu [i, n] a zatim izbacujemo element c[i] (tj. postavljamo c[i] = 0) jer dinamiku radimo po visinama i za svaki naredni upit j važi h[j] > h[i] pa vrednsot c[i] ne učestvuje u sumi. Ukupna složenost je O(n log n).
	
	Podzadaci uključuju slučajeve kada prolazi dinamičko programiranje u složenosti O(n^2) tj. direktno dinamičko iz formule (1), slučajeve gde se ne isplati rušiti zgrade (tada je rešenje jedinstveno - postaviti levi urđaj na prvu zgradu, zatim na prvu narednu koja nije zaklonjena prvom, zatim na prvu narednu koja nije zaklonjena drugom izabranom itd. do najviše zgrade i sl. za desne uređaje) kao i slučajeve gde su cena zgrada 0 što značajno pojednostavljuje formulu (1) na L[i] = v[i] + maximum { L[j] | j < i, h[j] < h[i] } pa ovo možemo rešavati slično kao LIS konstrukcijom max-segmentnog nad nizom L[i] (koje je indeksirano visinama ako računamo vrednosti L[i] od 1 do n ili je indeksirano pozicijama ako računamo vrednosti L[i] po visinama).
	
	``` cpp title="06_pogled.cpp" linenums="1"
	# include <stdio.h>
	# include <stdlib.h>
	#include<math.h> 
	//#include<algorithm>
	#include<string.h>
	
	# define MAXN 100100
	# define MAXN2 ((1<<18)+1)
	#define INF 0x1FFFFFFFFFFFFFLL
	//#define INF 10000000000LL
	
	using namespace std;
	
	int n;
	
	int ord[MAXN];
	int ht[MAXN], ct[MAXN], lc[MAXN], rc[MAXN];
	
	long long ls[MAXN], rs[MAXN];
	
	long long ctc[MAXN];
	long long smc[MAXN];
	
	
	long long tree_sum[MAXN2];
	long long lazy_sum[MAXN2];
	long long tree_max[MAXN2];
	long long lazy_max[MAXN2];
	
	long long sum(long long a, long long b) {
		return a + b;
	}
	
	long long max(long long a, long long b) {
		if (a > b) return a; else return b;
	}
	
	
	void build_tree_sum(int node, int a, int b, long long arr[]) {
	  	if(a > b) return; 						
	  	
	  	if(a == b) { 							
	    	tree_sum[node] = arr[a]; 		
			return;
		}
		
		build_tree_sum(node*2, a, (a+b)/2, arr); 	
		build_tree_sum(node*2+1, 1+(a+b)/2, b, arr); 
		
		tree_sum[node] = sum(tree_sum[node*2], tree_sum[node*2+1]); 
	}
	
	void update_tree_sum(int node, int a, int b, int i, int j, long long value) {
	  
	  	if(lazy_sum[node] != 0) { 							
	   		tree_sum[node] += (b - a + 1) * lazy_sum[node]; 
	
			if(a != b) {
				lazy_sum[node*2] += lazy_sum[node]; 		
	    		lazy_sum[node*2+1] += lazy_sum[node]; 		
			}
	
	   		lazy_sum[node] = 0; 							
	  	}
	  
		if(a > b || a > j || b < i) 						
			return;
	    
	  	if(a >= i && b <= j) { 								
	    		tree_sum[node] += (b - a + 1) * value;
	
			if(a != b) { 									
				lazy_sum[node*2] += value;					 
				lazy_sum[node*2+1] += value;				
			}
	
	    	return;
		}
	
		update_tree_sum(node*2, a, (a+b)/2, i, j, value); 		
		update_tree_sum(1+node*2, 1+(a+b)/2, b, i, j, value); 	
	
		tree_sum[node] = sum(tree_sum[node*2], tree_sum[node*2+1]); 
	}
	
	long long query_tree_sum(int node, int a, int b, int i, int j) {
		
		if(a > b || a > j || b < i) return 0; 					
	
		if(lazy_sum[node] != 0) { 								
			tree_sum[node] += (b - a + 1) * lazy_sum[node]; 	
	
			if(a != b) {
				lazy_sum[node*2] += lazy_sum[node]; 			
				lazy_sum[node*2+1] += lazy_sum[node]; 			
			}
	
			lazy_sum[node] = 0; 								
		}
	
		if(a >= i && b <= j) 
			return tree_sum[node];
	
		long long q1 = query_tree_sum(node*2, a, (a+b)/2, i, j); 		
		long long q2 = query_tree_sum(1+node*2, 1+(a+b)/2, b, i, j);	
	
		long long res = sum(q1, q2); 									
		
		return res;
	}
	
	void build_tree_max(int node, int a, int b, long long arr[]) {
	  	if(a > b) return; 					
	  	
	  	if(a == b) { 						
	    	tree_max[node] = arr[a]; 
			return;
		}
		
		build_tree_max(node*2, a, (a+b)/2, arr); 		
		build_tree_max(node*2+1, 1+(a+b)/2, b, arr); 	
		
		tree_max[node] = max(tree_max[node*2], tree_max[node*2+1]); 
	}
	
	void update_tree_max(int node, int a, int b, int i, int j, long long value) {
	  
	  	if(lazy_max[node] != 0) { 					
	   		tree_max[node] += lazy_max[node]; 		
	
			if(a != b) {
				lazy_max[node*2] += lazy_max[node]; 		
	    			lazy_max[node*2+1] += lazy_max[node]; 	
			}
	
	   		lazy_max[node] = 0; 					
	  	}
	  
		if(a > b || a > j || b < i) 				
			return;
	    
	  	if(a >= i && b <= j) { 						
	    	tree_max[node] += value;
	
			if(a != b) { 							
				lazy_max[node*2] += value;			
				lazy_max[node*2+1] += value;
			}
	
	    	return;
		}
	
		update_tree_max(node*2, a, (a+b)/2, i, j, value); 			
		update_tree_max(1+node*2, 1+(a+b)/2, b, i, j, value); 		
	
		tree_max[node] = max(tree_max[node*2], tree_max[node*2+1]); 
	}
	
	long long query_tree_max(int node, int a, int b, int i, int j) {
		
		if(a > b || a > j || b < i) return -2*INF; 		
	
		if(lazy_max[node] != 0) { 						
			tree_max[node] += lazy_max[node]; 			
	
			if(a != b) {
				lazy_max[node*2] += lazy_max[node]; 	
				lazy_max[node*2+1] += lazy_max[node]; 	
			}
	
			lazy_max[node] = 0; 						
		}
	
		if(a >= i && b <= j) 							
			return tree_max[node];
	
		long long q1 = query_tree_max(node*2, a, (a+b)/2, i, j); 		
		long long q2 = query_tree_max(1+node*2, 1+(a+b)/2, b, i, j); 	
	
		long long res = max(q1, q2); 									
		
		return res;
	}
	
	
	
	
	void read() {
		int i;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &ht[i], &ct[i], &lc[i], &rc[i]);
		}
	}
	
	int cmpht(const void *p1, const void *p2) {
		const int *pi1 = (const int *)p1;
		const int *pi2 = (const int *)p2;
		return ht[*pi1] - ht[*pi2];
	}
	
	long long solve() {
		int i, j;
		for (i = 0; i < n; i++) 
			ord[i] = i+1;
		qsort(ord, n, sizeof(int), cmpht);
		ls[n] = smc[n] = -INF;
		ctc[n] = ct[n];
		for (i = n-1; i >= 1; i--) {
			smc[i] = smc[i+1] - ct[i+1];
			ctc[i] = ct[i];
			ls[i] = -INF;
		} 
		smc[0] = smc[1] - ct[1] + INF;
		ctc[0] = 0;
		build_tree_sum(1, 0, n, ctc);
		build_tree_max(1, 0, n, smc);
		memset(lazy_max, 0, sizeof lazy_max);
		memset(lazy_sum, 0, sizeof lazy_sum);
		for (i = 0; i < n; i++) {
			j = ord[i];
			ls[j] = lc[j];
			if (j > 0) 
				ls[j] += query_tree_max(1, 0, n, 0, j-1);
			ls[j] += query_tree_sum(1, 0, n, j, n);
			update_tree_max(1, 0, n, j, j, INF+ls[j]);
			smc[j] += INF + ls[j];
			if (j > 0) {
				update_tree_max(1, 0, n, 0, j-1, ct[j]);
			}
			update_tree_sum(1, 0, n, j, j, -ct[j]);
		}
	
		rs[1] = smc[1] = -INF;
		ctc[1] = ct[1];
		for (i = 2; i <= n; i++) {
			smc[i] = smc[i-1] - ct[i-1];
			ctc[i] = ct[i];
			rs[i] = -INF;
		} 
		smc[n+1] = smc[n] - ct[n] + INF;
		ctc[n+1] = 0;
		build_tree_sum(1, 1, n+1, ctc);
		build_tree_max(1, 1, n+1, smc);
		memset(lazy_max, 0, sizeof lazy_max);
		memset(lazy_sum, 0, sizeof lazy_sum);
		for (i = 0; i < n; i++) {
			j = ord[i];
			rs[j] = rc[j];
			rs[j] += query_tree_max(1, 1, n+1, j+1, n+1);
			rs[j] += query_tree_sum(1, 1, n+1, 1, j);
			update_tree_max(1, 1, n+1, j, j, INF+rs[j]);
			update_tree_max(1, 1, n+1, j+1, n+1, ct[j]);
			update_tree_sum(1, 1, n+1, j, j, -ct[j]);
		}
	
		long long rez;
		rez = ls[1] + rs[1];
		for (i = 2; i <= n; i++) 
			if (ls[i] + rs[i] > rez)
				rez = ls[i] + rs[i];
		printf("%lld\n", rez);
		return rez;
	}
	
	main() {
		read();
		solve();
		return 0;
	}

	```
