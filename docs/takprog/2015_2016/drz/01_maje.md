---
hide:
  - toc
---

# B1 - Maje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 400ms | 64MB |
	
	Civilizacija maja je jedna od najpoznatijih drevnih civilizacija. Ova civilizacija je, između ostalog, poznata po njihovoj, za taj period, veoma naprednoj matematici. Maje su bile opčinjene neopadajućim nizovima brojeva, tj. nizovima koji zadovoljavaju da je svaki element niza, sem prvog, veći ili jednak od prethodnog u nizu. Maje su verovale da se neke bitne osobine niza mogu otkriti tako što se niz transformiše u neopadajući niz brojeva. Međutim, pošto su verovale da se redosled elemenata u nizu ne sme menjati, maje su koristile specijalnu operaciju nad elementima niza kako bi ga transformisale.
	
	Dozvoljena operacija uzima jedan od brojeva iz niza i redom prebacuje nekoliko cifara (moguće njih 0) sa početka broja na njegov kraj. Npr. primenjujući ovu operaciju na broj 12345, moguće je dobiti jedan od brojeva (uspravnom crtom je označena grupa cifara koja se prebacuje na kraj broja):
	
	* |12345 → 12345
	* 1|2345 → 23451
	* 12|345 → 34512
	* 123|45 → 45123
	* 1234|5 → 51234
	
	Vaš zadatak je da za dati niz brojeva odredite da li je moguće da se primenjujući opisanu operaciju na svaki element niza tačno jednom, dobije neopadajući niz elemenata.
	
	
	## Opis ulaza
	U prvom redu standardnog ulaza se nalazi prirodan broj $N$ koji predstavlja dužinu niza. U drugom redu se nalazi $N$ prirodnih brojeva koji predstavljaju niz.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza vaš program treba da ispiše “DA” ukoliko je moguće transformisati dati niz u neopadajući, primenjujući opisanu operaciju na svaki element niza tačno jednom. U suprotnom, u prvom redu standardnog izlaza vaš program treba da ispiše “NE”.
	
	## Primer 1
	### Ulaz
	```
	5
	3302 142 214 115 600
	```
	
	### Izlaz
	```
	DA
	```
	
	## Primer 2
	### Ulaz
	```
	3
	24 15 33
	```
	
	### Izlaz
	```
	NE
	```
	
	## Objašnjenja primera
	U prvom test primeru, jedan od načina da se niz transformiše u neopadajući niz brojeva je da se odrade sledeće operacije nad brojevima:
	
	33|02 → 0233, 1|42 → 421, 21|4 → 421, 11|5 → 511, |600 → 600
	
	Ovim operacijama se dobija niz brojeva: 233 421 421 511 600, koji je neopadajući. 
	Niz dat u drugom test primeru nije moguće transformisati opisanom operacijom u neopadajući niz brojeva.
	
	## Ograničenja
	
	* $n ≤ 10^6$
	* svi brojevi u datom nizu su imeđu $0$ i $10^9$, uključujući i ove brojeve
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u 4 podzadatka, u kojima važe sledeća dodatna
	ograničenja:
	
	* Podzadatak 1 [10 poena]: svi brojevi u datom nizu su manji od 10
	* Podzadatak 2 [20 poena]: $n = 2$
	* Podzadatak 3 [20 poena]: svi brojevi u datom nizu su manji od 100
	* Podzadatak 4 [50 poena]: nema dodatnih ograničenja
	
	## Napomena
	Primetiti da se, primenom operacije na određeni broj, cifre 0 mogu naći na početku broja. U ovom slučaju se ne posmatraju ove nule, tj. posmatra se broj bez vodećih nula. Takođe, primetiti da u ulazu brojevi neće imati vodeće nule.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Demjan Grubić | Boris Grubić | Aleksandar Višnjić | Ivan Stošić |
	
	## Prvi podzadatak:
	Svi elementi niza su jednocifreni i samim tim se njihove vrednosti ne mogu promeniti. Potrebno je proveriti da li je dat niz već sortiran neopadajuće. Vremenska složenost: $O(N)$, memorijska složenost: $O(N)$ ili $O(1)$.
	
	## Drugi podzadatak:
	Broj mogućih vrednosti nakon transformisanja nekog broja jednak je broju njegovih cifara. (koji po uslovu zadatka ne prevazilazi $9$, tj. $log(maxA_i)$ ) Kako imamo samo dva broja, možemo da generišemo sve moguće transformacije i uporedimo ih. Vremenska složenost:  $O(log^N(maxA_i))$, memorijska složenost: $O(N)$.
	
	## Treći podzadatak:
	Za svaki element niza postoje dve moguće vrednosti (ili ga transformišemo na jedini način mogući, ili ga ne transformišemo uopšte). Za prvi element je optimalno uzeti manju od te dve opcije (on ne mora biti veći ni od čega, a biće nam lakše da ostatak niza učinimo neopadajućim). Za svaki sledeći element, sličnim razmišljanjem, uzimamo manju od dve opcije ukoliko je ona veća ili jednaka od prethodnog elementa (možda već modifikovanog). Ako nije, a ona druga opcija jeste, onda uzimamo nju. Ako za neki element nijedna od dve moguće vrednosti nije veća ili jednaka od prethodne, onda rešenje ne postoji. U suprotnom, rešenje postoji. Vremenska složenost: $O(N)$, memorijska složenost: $O(N)$ ili $O(1)$. 
	
	## Glavno rešenje:
	Slično prethodnom podzadatku, za prvi element niza uzimamo najmanju od mogućih tranformacija. Za svaki sledeći element uzimamo najmanju mogućnost koja je veća ili jednaka od prethodnog elementa. Ukoliko takva mogućnost ne postoji, ne postoji ni rešenje. Vremenska složenost: $O(Nlog(maxA_i))$, memorijska složenost: $O(N)$ ili $O(1)$.
	
	``` cpp title="01_maje.cpp" linenums="1"
	#include <iostream>
	#include <cstring>
	#include <cstdio>
	
	using namespace std;
	
	const int MAX_N = 1000005;
	
	int n;
	char a[MAX_N][10];
	
	int get_num(char str[10], int sep) {
	    int ret = 0;
	    int cnt = strlen(str);
	    for (int i = sep; i < cnt; ++i)
	        ret = ret * 10 + (str[i] - '0');
	    for (int i = 0; i < sep; ++i)
	        ret = ret * 10 + (str[i] - '0');
	    return ret;
	}
	
	int main() {
	    scanf("%d", &n);
	    for (int i = 0; i < n; ++i) {
	        scanf("%s", &a[i]);
	    }
	
	    bool ok = true;
	    int cnt = strlen(a[0]);
	    int lastNum = get_num(a[0], 0);
	    for (int i = 1; i < cnt; ++i)
	        lastNum = min(lastNum, get_num(a[0], i));
	
	    for (int i = 1; i < n; ++i) {
	        cnt = strlen(a[i]);
	        int minNum = -1;
	        for (int j = 0; j < cnt; ++j) {
	            int tmp = get_num(a[i], j);
	            if (tmp >= lastNum) {
	                if (minNum == -1 || minNum > tmp)
	                    minNum = tmp;
	            }
	        }
	        if (minNum < lastNum) {
	            ok = false;
	        }
	        lastNum = minNum;
	    }
	
	    if (ok) printf("DA\n");
	    else printf("NE\n");
	
	    return 0;
	}

	```
