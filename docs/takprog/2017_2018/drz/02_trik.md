---
hide:
  - toc
---

# B2 - Trik

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Umesto da uči za test iz programiranja, mali Aleksa je čitav dan vežbao trikove sa karticama. Sada mu nije preostalo ništa drugo nego da oduševi svog profesora Dragana jednim trikom, i nada se da će dobiti bolju ocenu zbog toga.
	
	On poseduje **za svaki broj od $1$ do $N$ po dve kartice** na kojoj je ispisan taj broj, i $K$ džoker kartica na kojima je ispisano slovo $J$.
	
	Trik se sastoji u tome da će Aleksa promešati i rasporediti kartice tako da se između svake dve kartice koje imaju isti **broj** na sebi, nalazi **tačno toliko kartica koliki je taj broj**. Npr, između dve kartice sa brojem 3 treba da se nalaze tačno 3 kartice.
	
	Ovakav raspored je teško napraviti bez znanja programiranja, i zato vas mali Aleksa moli za pomoć. Za dato $N$ i $K$ ispišite raspored kartica kojim će Aleksa oduševiti profesora.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalaze se dva prirodana broja $N$ i $K$, koja redom označavaju do kog broja Aleksa poseduje kartice, i broj džoker kartica.
	
	## Opis izlaza
	U prvom redu standardnog izlaza ispisati tačno $2 \cdot N + K$ oznaka kartica koje predstavljaju raspored tim redom. Oznaka kartice sa brojem je taj broj, dok je oznaka džoker kartice slovo "J". Ukoliko postoji više rešenja, možete ispisati bilo koje.
	
	## Primeri
	### Ulaz 1
	```
	3 4
	```
	
	### Izlaz 1
	```
	1 J 1 2 J 3 2 J J 3
	```
	
	### Ulaz 2
	```
	7 5
	```
	
	### Izlaz 2
	```
	3 7 4 6 3 5 J 4 J 7 6 5 J J 2 J 1 2 1
	```
	
	## Objašnjenje primera
	U prvom primeru imamo 3 para kartica sa brojevima 1 do 3, i 4 džokera. Jedan mogući izlaz je: 1 J 1 2 J 3 2 J J 3 zbog toga što se između dve kartice sa brojem 1 nalazi tačno jedna kartica (J), između dve kartice sa brojem 2 se nalaze tačno dve kartice (J 3), između dve kartice sa brojem 3 se nalaze tačno tri kartice (2 J J).
	
	## Ograničenja i podzadaci
	
	* $2 \leq N, K \leq 222222$.
	
	Postoji pet podzadatka:
	
	* Podzadatak $1$ [$3$ poena]: $N, K \leq 4$.
	* Podzadatak $2$ [$5$ poena]: $N \leq 8, K = 128$.
	* Podzadatak $3$ [$32$ poena]: $N, K \leq 64$.
	* Podzadatak $4$ [$22$ poena]: $K = 22$.
	* Podzadatak $5$ [$38$ poena]: $K = 2$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Vladimir Milovanović | Dušan Zdravković | Vladimir Milovanović | Ivan Stošić |
	
	Najpre, lako se dokazuje da u opštem slučaju za proizvoljno $N$, nije moguće sklopiti odgovarajući niz bez džokera. Naime, kako kartice označene neparnim brojevima, $1, 3, 5,\ldots$, moraju sadržati neparan broj kartica između njih, ove kartice se uvek pojavljuju na mestima u nizu, odnosno indeksima, sa istom parnošću. Sa druge strane, kartice označene parnim brojevima, $2, 4, 6,\ldots$, sadrže paran broj kartica između njih, pa se stoga pojavljuju na pozicijama suprotne parnosti. U nizu koji sadrži samo $2N$ kartica, postoji tačno $N$ parnih i tačno $N$ neparnih indeksa, od kojih bi, bez smanjenja opštosti uz pretpostavku da je $N$ parno, po $N/2$ parnih i neparnih pozicija bilo zauzeto karticama sa parnim brojevima na sebi, to jest, $2, 4, 6,\ldots$, pa bi nakon njihovog raspoređivanja u nizu preostalo $N/2$ parnih i $N/2$ neparnih indeksa bez mogućnosti da se kartice označene neparnim brojevima, $1, 3, 5,\ldots$, rasporede na odgovarajući način.
	
	Iako je opisani niz nemoguće sastaviti bez džokera, za proizvoljno $N$ potreban je i dovoljan samo jedan džoker da se ispune uslovi opisani postavkom zadatka. Nije teško uočiti da se sve kartice označene neparnim i parnim brojevima mogu ugnezditi jedna u drugu na sledeći način za neparno $N$:
	
	* $N, N-2, N-4,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-4, N-2, N$
	* $N-1, N-3, N-5,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-5, N-3, N-1$
	
	odnosno na identičan način i za parno $N$:
	
	* $N-1, N-3, N-5,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-5, N-3, N-1$
	* $N, N-2, N-4,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-4, N-2, N$
	
	te se njihovim spajanjem dobija rešenje koje sadrži ukupno tri džokera (jednog u podnizu kartica označenih neparnim i dva u podnizu kartica označenih parnim brojevima).
	
	U svakom slučaju, sada između nesusednih džokera tako spojenih podnizova ima tačno $N$, to jest $N+1$ kartica, među kojima su i po jedna kartica označena brojevima $N-1$ i $N$, bez obzira na to da li je $N$ parno ili neparno i koji je od ugnežđenih podnizova prvi, a koji drugi, odnosno:
	
	* $N-1, N-3, N-5,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-5, N-3, N-1, N, N-2, N-4,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-4, N-2, N$
	* $N, N-2, N-4,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-4, N-2, N, N-1, N-3, N-5,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-5, N-3, N-1$
	
	Ukoliko sada, (u prvom slučaju) izvadimo kartice označene brojem $N-1$ dobićemo tačno $N-1$ karticu između dva bliža nesusedna džokera:
	
	* $N-3, N-5,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-5, N-3, N, N-2, N-4,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-4, N-2, N$
	* $N, N-2, N-4,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-4, N-2, N, N-3, N-5,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-5, N-3$
	
	pa zamenom odgovarajućih džokera karticama označenim sa $N-1$ dobijamo traženi niz, to jest:
	
	* $N-3, N-5,\ldots, 7, 5, 3, 1, N-1, 1, 3, 5, 7,\ldots, N-5, N-3, N, N-2, N-4,\ldots, 6, 4, 2, N-1, J, 2, 4, 6,\ldots, N-4, N-2, N$
	* $N, N-2, N-4,\ldots, 7, 5, 3, 1, N-1, 1, 3, 5, 7,\ldots, N-4, N-2, N, N-3, N-5,\ldots, 6, 4, 2, N-1, J, 2, 4, 6,\ldots, N-5, N-3$
	
	za parno i neparno $N$, respektivno.
	
	Slično tome, bilo je (u drugom slučaju) moguće izvaditi i kartice označene brojem $N$, pa bi između druga dva nesusedna džokera bilo $N$ kartica:
	
	* $N-1, N-3, N-5,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-5, N-3, N-1, N-2, N-4,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-4, N-2$
	* $N-2, N-4,\ldots, 7, 5, 3, 1, J, 1, 3, 5, 7,\ldots, N-4, N-2, N-1, N-3, N-5,\ldots, 6, 4, 2, J, J, 2, 4, 6,\ldots, N-5, N-3, N-1$
	
	čijom bismo zamenom karticama označenim brojem $N$ na još jedan mogući način dobili traženi niz, zapravo:
	
	* $N-1, N-3, N-5,\ldots, 7, 5, 3, 1, N, 1, 3, 5, 7,\ldots, N-5, N-3, N-1, N-2, N-4,\ldots, 6, 4, 2, J, N, 2, 4, 6,\ldots, N-4, N-2$
	* $N-2, N-4,\ldots, 7, 5, 3, 1, N, 1, 3, 5, 7,\ldots, N-4, N-2, N-1, N-3, N-5,\ldots, 6, 4, 2, J, N, 2, 4, 6,\ldots, N-5, N-3, N-1$
	
	takođe za parno i neparno $N$, respektivno.
	
	Prethodnim se dokazuje da je u opštem slučaju koristeći samo jednu džoker karticu moguće konstruisati traženi niz za proizvoljno $N$, pa je i složenost ovog algoritma linearna po $N$, odnosno $\mathcal{O}(N)$. Trivijalnim dodavanjem preostalih $K-1$ džokera bilo na početak ili na kraj ovako formiranog niza, zadatak je rešen u ukupnoj složenosti $\mathcal{O}(N+K)$.
	
	``` cpp title="02_trik.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	
	int main() {
	
	    int n,j,t,p,i;
	
	    scanf("%d%d", &n, &j);
	
	    t = n;
	    if (n%2 == 0) t--;
	    for(i=t-2; i>=1; i-=2) printf("%d ", i);
	    printf("%d ", t);
	    for(i=1; i<t; i+=2) printf("%d ", i);
	
	    p = n;
	    if (n%2 == 1) p--;
	    for(i=p; i>=2; i-=2) printf("%d ", i);
	
	    if (n%2 == 1) printf("J %d ", t);
	    else printf("%d J ", t);
	
	    for(i=2; i<=p; i+=2) printf("%d ", i);
	
	    for(i=2; i<=j; i++) printf("J ");
	
	    printf("\n");
	    return 0;
	}

	```
