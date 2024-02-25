---
hide:
  - toc
---

# A3 - Linijopolis

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 4000ms | 128MB |
	
	
	Velelepni Linijopolis su urbanisti zamislili tako da ima dokazano najbolju organizaciju: linijsku. Grad se sastoji od jedne jedine ulice, pored koje se nalaze blokovi jednakih veličina numerisani redom (počev od nultog). Za prevoz stanovnika Linijopolisa predviđen je javni prevoz u vidu $M$ ultra-brzih autobusa koje pokreću bitovi (vozovi će biti uvedeni tek u fazi 3C projekta Linijopolis), koji se drže jedne stalne trase od $N$ stanica (u različitim terminima u toku dana). Da bi prešao rastojanje između dva susedna bloka, svaki autobus potroši tačno jedan bit svog goriva. Nažalost, ovi autobusi na početku prvog dana rada GSP Linijopolis imaju ograničen broj bitova u rezervoaru: $i$-ti autobus ($1 \leq i \leq m$) na početku dana ima na raspolaganju $A_i$ bitova.
	
	Po trenutnom planu, u Linijopolisu će u okviru svake od $N$ stanica biti i pumpa bitova. Stanica sa rednim brojem $j$ ($1 \leq j \leq N$) se nalazi u okviru bloka $X_j$ i sadrži pumpu koja na raspolaganju ima ukupno $B_j$ bitova. Trasa nije nužno koncipirana tako da autobusi uvek idu u istom smeru (stanice mogu da imaju "cik-cak" raspored). Autobusi jedino mogu da dodaju bitove dok se putnici ukrcavaju ili iskrcavaju na trenutnoj stanici, i ne mogu da menjaju trasu ili se privremeno zaustave na stanici koja nije sledeća u nizu.
	
	Ispostavlja se da je teško, a možda i nemoguće iskoristiti svih $M$ autobusa u svrhu javnog prevoza. Zato će se iskoristiti neki podskup navedenih autobusa, pri čemu će za svaki biti unapred određeno koliko bitova treba da preuzme sa koje pumpe, da bi neki drugi autobusi imali priliku da dodaju bitove u svoje rezervoare. Bitovi su nedeljivi: svaki autobus može da preuzme isključivo celobrojan broj bitova.
	
	Pomozite idejnim tvorcima Linijopolisa da njihova ideja zaživi tako što ćete odrediti **najveći broj autobusa** koji u toku dana mogu da **u potpunosti završe svoj put** kroz svih $N$ stanica.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza dati su celi brojevi $M$ i $N$, koji redom predstavljaju broj autobusa i broj stanica.
	
	U drugog redu je dato $M$ celih brojeva $A_i$, koji predstavljaju početne količine bitova kojima raspolaže svaki od autobusa.
	
	U trećem redu je dato $N$ celih brojeva $X_j$, koji predstavljaju redne brojeve blokova u kojima se stanice redom nalaze.
	
	U četvrtom redu je dato $N$ celih brojeva $B_j$, koji predstavljaju kapacitete pumpi na stanicama.
	
	## Opis izlaza
	
	U prvom i jedinom redu standardnog izlaza treba ispisati najveći broj autobusa koji mogu da pređu put od prve do $N$-te stanice.
	
	## Primer 1
	
	### Ulaz
	
	```
	3 4
	3 0 2
	1 3 7 8
	2 5 3 6
	```
	
	### Izlaz
	
	```
	2
	```
	
	### Objašnjenje
	
	Prvi i treći autobus mogu da obiđu sve stanice u datom redosledu, ukoliko prate naredni postupak:
	* Prvi autobus počinje sa 3 bita i preuzima jedan bit sa prve stanice, nakon čega ima ukupno 4 bita. Po dolasku do druge stanice preostaju 2 bita, potom preuzima dva bita i ukupno ima na raspolaganju 4 bita. Ta 4 bita su dovoljna da autobus stigne do treće stanice bez preostalih bitova, nakon čega preuzima jedan bit sa treće stanice koji je dovoljan da bi stigao do poslednje četvrte stanice.
	* Treći autobus počinje sa dva bita i preuzima jedan bit sa prve stanice, nakon čega ima ukupno 3 bita. Potom stiže do druge stanice sa preostalim jednim bitom i uzima tri bita sa ove stanice, nakon čega ima četiri bita koja su dovoljna za dolazak do treće stanice. Pri dolasku u treću stanicu nema nijedan preostali bit, potom preuzima jedan bit sa ove stanice koji je dovoljan da se trasa završi.
	
	Drugi autobus može da pređe celu trasu korišćenjem, ali tada na stanicama nema dovoljno preostalih bitova da bi ijedan drugi autobus takođe mogao da obiđe sve stanice.
	
	## Primer 2
	
	### Ulaz
	
	```
	5 3
	50 50 50 50 150
	200 150 175
	25 25 200
	```
	
	### Izlaz
	
	```
	3
	```
	
	### Objašnjenje
	
	Dva autobusa sa početnim brojem bitova 50 i jedan autobus sa početnim brojem bitova 150 mogu da obiđu sve stanice. Pri tom jedan od autobusa sa početnim brojem bitova 50 dodaje svih 25 bitova sa prve stanice, a drugi dodaje svih 25 bitova sa druge stanice.
	
	Primetimo da stanice idu "cik-cak": $200$, $150$, $175$.
	
	## Ograničenja
	
	- $1 \leq M, N \leq 10^6$.
	- $0 \leq A_i \leq 10^9$ za sve $i=1, \dots, M$.
	- $0 \leq X_i, B_i \leq 10^9$ za sve $i=1, \dots, N$.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	- U test primerima vrednim 20 poena: $M \leq 10$, $N \leq 100$;
	- U test primerima vrednim 20 poena: $M,N \leq 10^4$;
	- U test primerima vrednim 30 poena: $M,N \leq 10^5$;
	- U test primerima vrednim 30 poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksandar Višnjić | Andrej Ivašković | Aleksandar Višnjić | Marko Šišović |
	
	## Rešenje kada $M\leq 10, N\leq 100$
	Za svaki podskup autobusa proveravamo da li mogu preći celu trasu. Kada se odlučimo za neki takav, puštamo autobuse po principu "jedan po jedan". Svakom je cilj da korišćenjem što manje dodatnih bitova stigne do kraja. Ukoliko mu je to potrebno, bitove će uzimati u najkasnijem mogućem trenutku. Ako je moguće ispuniti cilj, on neće uzurpirati ostale autobuse. Vremenska složenost je $O(2^M \cdot M\cdot N)$.
	
	## Rešenje kada $N,M\leq 10^4$
	Nadovezujemo se na prethodni podzadatak. Umesto razmatranja svakog podskupa, možemo uočiti to da autobusi sa većom početnom količinom bitova imaju veću šansu da stignu do kraja i štede više bitova. Zato ih sortiramo po tom parametru i puštamo ih redom od najvećeg ka najmanjem. Primetimo da ne znamo unapred veličinu grupe autobusa, već je odrećujemo naknadno nakon neuspešne trase (ili nakon što svi autobusi stignu do kraja). Najveća grupa će upravo biti poslednja "trenutna" grupa koju je opisani algoritam našao. Vremenska složenost je $O(M\log M + M\cdot N)$.
	
	## Rešenje kada $N,M\leq 10^5$
	Optimalno je odrediti nekoliko autobusa sa najvećom početnom količinom bitova. Stoga vršimo binarnu pretragu po vrednosti rešenja. Pretpostavimo da smo se odlučili za grupu od $K$ autobusa. Njih paralelno puštamo da putuju zajedno kroz svaku stanicu. Kada doću do stanice upotrebljavaju sve dostupne bitove. Prioritet ima autobus koji je "najprazniji". Promene je moguće simulirati preko **min heap** (priority queue) strukture. 
	
	U njoj pamtimo količine bitova, kao i broj autobusa koji imaju istu. Ukoliko imamo dovoljno bitova na raspolaganju, desiće se da "spojimo" dve najniže vrednosti, čime se veličina strukture smanjuje za jedan. Prilikom jedne ovakve operacije, smanjivanje se može desiti proizvoljan broj puta, ali dodavanje se dešava najviše dvaput (prilikom deljenja nedovoljnog broja bitova sa ostatkom). Kako u strukturu ne možemo oduzeti više nego što smo dodali, složenost provere je $O((N+M)\log M$.
	
	Zbog upotrebe binarne pretrage, ukupna vremenska složenost je $O((N+M)\log^2M)$.
	
	## Glavno rešenje
	Umesto *min heap* strukture koristimo **stack**. Provera postaje linearna, a ukupna složenost je $O((N+M)\log M$.
	
	``` cpp title="06_linijopolis.cpp" linenums="1"
	#include <algorithm>
	#include <cstdio>
	#include <cstdlib>
	#include <stack>
	
	using namespace std;
	
	#define MAXN 1000000
	#define MAXM 1000000
	
	// indeksirano od nule
	int M, N;
	int A[MAXM];
	int X[MAXN], B[MAXN];
	
	struct autobus {
	    int broj;
	    long long bitovi;
	} buff[MAXM];
	
	void ulaz() {
	    scanf("%d %d", &M, &N);
	    for (int i = 0; i < M; i++) {
	        scanf("%d", &A[i]);
	    }
	    for (int i = 0; i < N; i++) {
	        scanf("%d", &X[i]);
	    }
	    for (int i = 0; i < N; i++) {
	        scanf("%d", &B[i]);
	    }
	}
	
	bool isprobaj_resenje(int broj) {
	    if (broj == 0) {
	        return true;
	    }
	    stack<autobus> busevi;
	    for (int i = 0; i < broj; i++) {
	        autobus bus;
	        bus.bitovi = A[M - i - 1];
	        bus.broj = 1;
	        busevi.push(bus);
	    }
	    long long udaljenost = 0;
	    for (int i = 0; i < N - 1; i++) {
	        int preostalo = B[i];
	        while (preostalo > 0) {
	            bool spojDva = false;
	            bool barDva = (busevi.size() > 1);
	            autobus najmanji = busevi.top();
	            busevi.pop();
	            if (barDva) {
	                autobus drugi = busevi.top();
	                long long razlika = drugi.bitovi - najmanji.bitovi;
	                spojDva = (razlika * najmanji.broj <= preostalo);
	            }
	            if (spojDva) {
	                autobus drugi = busevi.top();
	                busevi.pop();
	                long long razlika = drugi.bitovi - najmanji.bitovi;
	                preostalo -= razlika * najmanji.broj;
	                drugi.broj += najmanji.broj;
	                busevi.push(drugi);
	            } else {
	                int broj_dodatnih = preostalo % najmanji.broj;
	                int uvecanje = preostalo / najmanji.broj;
	                preostalo = 0;
	                najmanji.bitovi += uvecanje;
	                najmanji.broj -= broj_dodatnih;
	                busevi.push(najmanji);
	                if (broj_dodatnih > 0) {
	                    autobus novi;
	                    novi.broj = broj_dodatnih;
	                    novi.bitovi = najmanji.bitovi + 1;
	                    busevi.push(novi);
	                }
	            }
	        }
	        long long najmanje = busevi.top().bitovi;
	        udaljenost += abs(X[i + 1] - X[i]);
	        if (najmanje < udaljenost) {
	            return false;
	        }
	    }
	    return true;
	}
	
	void resi() {
	    sort(A, A + M);
	    int levo = 0, desno = M;
	    while (levo < desno) {
	        int pokusaj = (levo + desno + 1) / 2;
	        if (isprobaj_resenje(pokusaj)) {
	            levo = pokusaj;
	        } else {
	            desno = pokusaj - 1;
	        }
	    }
	    printf("%d\n", levo);
	}
	
	int main() {
	    ulaz();
	    resi();
	    return 0;
	}
	```
