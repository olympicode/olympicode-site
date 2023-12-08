---
hide:
  - toc
---

# 1 - Operacija nad glistom

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Jedan pre svega veliki ljubitelj životinja po imenu Okram probudio se jednog dana i imao je šta da vidi: njegov ljubimac Edgar de Glist, jedna kišna glista, bio je raskomadan na $N$ delova. Okram je bio potrešen ovim prizorom, ali je, sa obzirom da se razume u ovu vrstu životinje, znao za oni mogu da prežive i nakon što im se desi ovakva povreda, i što je najbitnije, znao je da najnovijim tehnologijama on može da vrati svog ljubimca u stanje u kom je bio pre nemilog događaja. 
	
	Okram je pripremio svoju glistu za operaciju tako što je delove njenog tela poređao u niz u pravilnom redosledu i njihove dužine zapisao u jedan niz istim redosledom (pri tome je pazio da je poslednji deo, to jest deo skroz desno, onaj sa usnom dupljom, videćemo posle da je orijentacija bitna). U ovoj nezgodnoj operaciji nad svojom glistom on mora da obrati pažnju na nekoliko stvari:
	
	 -  Dva dela gliste se mogu spojiti samo ako su oni susedni i ako za njihove dužine $a$ i $b$ važi $a \le b \le a+1$. Pri ovome je bitno obratiti pažnju i na redosled, to jest $a$ predstavlja levi a $b$ desni broj (kao što smo rekli orijentacija je bitna).
	 - Da bi prošli uslov za spajanje mogao da bude ispunjen neki delovi će morati da se "prepolove" pre ponovnog spajanja sa drugim delovima, i to isključivo na sledeći način: ako je $c$ dužina dela koji se polovi, levi deo će nakon podele biti dužine $floor(c/2)$ a desni dužine $ceil(c/2)$.
	
	Pomozite Okramu tako što ćete mu reći koliko minimalno koraka (spajanja + polovljenja) je potrebno da bi se operacija odradila, to jest da bi ponovo spojio Edgara u jedan deo, kako bi znao da proceni vreme ovog hirurškog poduhvata.
	
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	-   $Resi(N,  A[\ldots])$
	
	Funkcija $Resi$ se poziva samo jednom na početku ivršavanja programa, a njeni parametri su $N$, broj delova gliste, i $A[\ldots]$, niz dužine $N$ koji sadrži dužine delova gliste, i indeksiran je od $0$. Povratna vrednost funkcije je minimalan broj koraka koji je potreban da se operacija izvrši.
	
	## Primer 1
	### Ulaz
	```
	3
	1 2 1
	```
	
	### Izlaz
	```
	4
	```
	
	#### Objašnjenje
	Na pošetku moramo podeliti srednji deo, nakon čega imamo 4 dela dužine 1. Sada možemo spojiti prva dva, kao i poslednja dva dela, nakon čega nam ostaju 2 dela dužine 2 koje možemo potom spojiti i time završiti postupak
	
	## Primer 2
	
	### Ulaz
	```
	9
	1 1 1 1 1 1 1 1 1
	```
	
	### Izlaz
	```
	8
	```
	
	### Objašnjenje
	
	Numerišimo delove od $1$ do $9$. Spojimo sada redom delove 1 i 2, 3 i 4, 5 i 6, kao i 8 i 9. Niz sada izgleda ovako: 2 2 2 1 2. Spojimo poslednja prva dva dela i poslednja dva dela i dobijamo niz: 4 2 3, kod kog možemo spojiti poslednja dva dela odakle dobijamo niz: 4 5, koji sada možemo spojiti i završiti postupak.
	
	## Ograničenja
	
	* $N \le 10^5$
	* $S \le 10^6$, gde je $S$ ukupna dužina gliste, to jest suma brojeva u nizu
	
	## Podzadaci
	
	Test primeri su podeljeni u $5$ podzadataka:
	
	- **[10 poena]** $S \le 20$
	- **[10 poena]** Dužine svih delova, to jest svi elementi niza, su $1$ ili $2$.
	- **[20 poena]** $S \le 1000$
	- **[30 poena]** $S \le 10^5$
	- **[30 poena]** Bez dodatnih ograničenja.
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl  `operacija_nad_glistom.cpp`  koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int Resi(int N, int* A);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojevi $N$.
	-   U narednom redu $N$ brojeva: $A_i$.
	
	Zatim ovaj program zove vašu funkciju i ispisuje rezultate koje ona vrati.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Marko Šišović | Dragan Urošević | Vladimir Milenković |
	
	## Glavno rešenje
	Primetimo da su operacije razdvajanja i spajanja uzajamno inverzne
	(tj. iverzne jedna drugoj), tako da ako neka dva dela spojimo, nikad ih više nećemo razdvajati.
	U poslednjem potezu znamo da moramo da spojimo dva dela koji imaju jednake dužine, ili dva dela od kojih je levi za jedan kraći od desnog (tj. dužine delova su $\left\lfloor\frac{S}{2}\right\rfloor$ i $\left\lceil\frac{S}{2}\right\rceil$, gde je $S$ ukupna dužina gliste). Zbog toga treba da postoji indeks $k$, tako da je suma dužina prvih $k$ delova jednaka $\left\lfloor\frac{S}{2}\right\rfloor$, a suma dužina  preostalih delova iznosi $\left\lceil\frac{S}{2}\right\rceil$. Ako ne postoji takav indeks $k$, onda se određuje indeks $k$ tako da je
	
	$$
	\sum_{i=1}^{k-1} a_i< \left\lfloor\frac{S}{2}\right\rfloor
	\quad \text{i}
	\quad
	\sum_{i=1}^{k} a_i >  \left\lceil\frac{S}{2}\right\rceil.
	$$
	
	Nakon toga se deo sa indeksom $k$ deli sve dok se ne dobije niz u kome postoji indeks $l$, takav da je
	
	$$
	\sum_{i=1}^{l} a_i = \left\lfloor\frac{S}{2}\right\rfloor.
	$$
	
	To postižemo tako što svaki put delimo deo sa indeksom  $k'$
	za koji važi
	
	$$
	\sum_{i=1}^{k'-1} a_i < \left\lfloor\frac{S}{2}\right\rfloor
	\quad \text{i}
	\quad
	\sum_{i=1}^{k'} a_i > \left\lceil\frac{S}{2}\right\rceil.
	$$
	
	Kada dobijemo niz delova (koji ima $n'$ delova) za koji postoji indeks $l$ takav da je
	
	$$
	\sum_{i=1}^{l} a_i = \left\lfloor\frac{S}{2}\right\rfloor.
	$$,
	
	onda raekrzivno pozivamo funkciju koja određuje minimalni broj operacija potreban da se spoje prvih $l$ delova u jedan deo i funciju koja određuje minimalan broj operacija potreban da se spoji poslednjih $n'-l$ delova  u jedan deo. Na kraju dva tako dobijena dela ćemo spojiti u jedan deo. Ukupan broj operacija je jednak zbiru broja operacija deljenja na početku funkcije, broju operacija za spajanje leve polovine, broja operacija za spajanje desne polovine i broja 1 za spajanje dva dobijena dela (polovine).
	
	Znači, za rešavanje zadatka smo iskoristili tehniku podeli pa vladaj ($divide\ and\ conquer$). Primetimo da je složenost jednog rekurzivnog poziva (odnosno pripreme za rekrzivne pozive tokom izvršavanja tog rekurzivnog poziva) ${\mathcal O}(S)$, a da se rekurzivno poziva funkcija za nizove u kojima je suma dužina delova $\frac{S}{2}$, pa je po master teoremi složenost kompletnog funkcije ${\mathcal O}(S\log S)$.
	 
	
	
	``` cpp title="01_operacija_nad_glistom.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	int n;
	
	struct node{
	    int val = -1;
	    node* next = nullptr;
	    node(int val):val(val){};
	    node(int val, node* next):val(val),next(next){};
	};
	
	node *head, *tail;
	
	int solve(node* l_ptr, int total_sum){
	    /*for(node* i = head; i != 0; i = i->next){
	        if(l_ptr == i){
	            printf("*");
	        }
	        printf("%d ", i->val);
	    }
	    printf("-- %d\n", total_sum);*/
	    if(l_ptr->val == total_sum){
	        return 0;
	    }
	    int ans = 0;
	    node* ptr = l_ptr;
	    int cur_sum = l_ptr->val;
	    while(cur_sum != total_sum/2){
	        while(cur_sum < total_sum/2){
	            ptr = ptr->next;
	            cur_sum += ptr->val;
	        }
	        while(cur_sum > total_sum/2){
	            int a = ptr->val;
	            int la = a/2, ra = (a + 1)/2;
	            cur_sum -= ra;
	            ptr->val = la;
	            ptr->next = new node(ra, ptr->next);
	            ans++;
	        }
	    }
	    ptr = ptr->next;
	    return ans + solve(l_ptr, total_sum/2) + solve(ptr, (total_sum + 1)/2) + 1;
	}
	
	int Resi(int N, int* A){
	    n = N;
	    int total_sum = 0;
	    for(int i = 0; i < n; i++){
	        int in = A[i];
	        total_sum += in;
	        if(i == 0){
	            head = new node(in);
	            tail = head;
	        }
	        else{
	            tail->next = new node(in);
	            tail = tail->next;
	        }
	    }
	    return solve(head, total_sum);
	}

	```
