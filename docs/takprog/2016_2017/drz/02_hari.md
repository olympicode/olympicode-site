---
hide:
  - toc
---

# B2 - Hari

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 400ms | 64MB |
	
	Hogvorts, škola magije i čarobnjaštva, priprema se za uskršnji raspust kada svi učenici idu kući na zasluženi odmor. Kako je magija zabranjena u svetu običnih ljudi, čarobnjaci ne nose svoje čarobne štapove, već ih ostavljaju Hagridu na čuvanje. Čarobni štapovi se čuvaju u posebnim magičnim kutijama. Hagrid je vrlo senilan, pa je zaboravio gde je ostavio magične kutije, te mora da napravi nove.
	
	Da se štapovi ne bi pomešali, pa da nakon raspusta čarobnjaci ne mogu da nađu svoj štap, postoji posebna procedura. Najpre svi čarobnjaci, njih $N$, ostave svoje štapove na dugačkom stolu, a onda ih Hagrid redom pakuje u kutije. Hagrid mora da ih pakuje redom, tj svaka kutija treba sadržati **samo uzastopne štapove**.
	
	Mora se voditi računa i o stabilnosti kutija. U svakoj kutiji mora biti **isti broj štapova**. Takođe, štapovi imaju starost, izraženu u godinama. Ukoliko se u jednoj kutiji nađe više od $K$ čarobnih štapova iste starosti, može doći do velike magične eksplozije.
	
	Hagrida zanima na koliko načina može da upakuje štapove u kutije, a da ispoštuje sva pravila.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se dva prirodna broja, $N$ - broj čarobnjaka i $K$ - najveći dozvoljeni broj štapova iste starosti koji se mogu naći u jednoj kutiji.
	U sledećem redu nalazi se N celih brojeva, $A_1, A_2, ..., A_N$ koji predstavljaju starosti štapova.
	
	## Opis izlaza
	Na standardni izlaz potrebno je ispisati jedan broj, koji predstavlja broj načina na koji Hagrid može podeliti štapove u kutije.
	
	## Primer 1
	### Ulaz
	```
	6 1
	1 5 3 3 7 4 
	```
	
	### Izlaz
	```
	2
	```
	
	## Primer 2
	### Ulaz
	```
	12 2
	1 2 3 4 2 3 4 2 1 2 3 4
	```
	
	### Izlaz
	```
	5
	```
	
	## Objašnjenje primera
	U prvom primeru K je 1, što znači da svi štapovi u jednoj kutiji moraju imati različitu starost. Moguće je staviti svaki štap u posebnu kutiju, ili prva tri u jednu kutiju, a sledeća tri u drugu. Ako se stavljaju po dva, druga kutija će sadržati štapove starosti 3 i 3, što nije stabilno.
	U drugom primeru validne su podele na po 1, 2, 3, 4 i 6 štapova po kutiji.
	
	## Ograničenja i podzadaci
	* $1 \leq K \leq 200000$
	* $1 \leq A_i \leq 10^9$
	
	Postoje 4 podzadatka, u kojima dodatno važi:
	
	* Podzadatak 1 [16 poena]: $1 \leq N \leq 100$.
	* Podzadatak 2 [24 poena]: $1 \leq N \leq 20000$.
	* Podzadatak 3 [29 poena]: $1 \leq N \leq 200000$ i $1 \leq A_i \leq 10^6$.
	* Podzadatak 4 [31 poena]: $1 \leq N \leq 200000$.
	
	## Napomena
	Dozvoljeno je staviti i sve štapove u jednu kutiju, ukoliko su ispunjni sva pravila.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Dejković | Ivan Dejković | Uroš Vukićević | Ivan Stošić |
	
	## Prvi podzadatak:  
	Kako su ograničenja mala, zadatak se može rešiti direktnom implementacijom teksta zadatka, odnosno grubom silom.
	  
	## Drugi podzadatak:  
	U ovom podzadatku prolaze sporije implementacije glavnog rešenja, koje inače ne bi prošle. Na primer, korišćenje struktura *std::set* ili *std::map* je neefikasno, ali donosi određen broj poena.
	  
	## Treći podzadatak:  
	Pošto kutije moraju sadržati isti broj štapova, kandidati za broj štapova u svakoj od kutija su samo delioci broja $N$. Delioce broja $N$ možemo naći u $O(\sqrt{N})$ . Takođe, za $N\le200000$ najveći broj delilaca biće $160$ . Ova činjenica se može potvrditi lokalno generisanim kodom.
	
	Sada možemo napraviti niz vektora $pos$; $pos_{x}$ predstavlja sve pozicije broja $x$ u nizu, poređane od manje ka većoj. Nakon toga za fiksirani delilac $d$ možemo proveriti da li je ta veličina kutije validna. To radimo tako što za svaki štap $x$ proverimo da li se on u svakoj kutiji pojavio ne više od $K$ puta. Za bilo koju poziciju $i$, najlevlji štap koji će sadržati kutija koja sadrži i $i$-ti štap biće najveći sadržalac $d$ koji je manji ili jednak od $i$. Zbog ove činjenice možemo samo jednom proći kroz sve pozicije štapa $x$ i proveriti da li se on u svakoj kutiji pojavio ne više od $K$ puta. 
	
	Vremenska složenost je $O(T \cdot (maxA_i+N))$, a memorijska složenost je $O(maxA_i+N)$.  $T$ predstavlja broj delilaca broja $N$, koji iznosi najviše $160$.
	  
	## Glavno rešenje:  
	Pošto nam je za bilo koja dva štapa važno samo da li su isti, niz možemo kompresovati(u složenosti $O(N\log N)$) tako da sve vrednosti budu manje od ili jednake $N$. Nakon što smo to uradili, rešenje se svodi na rešenje iz prethodnog podzadatka. 
	
	Vremenska složenost je $O(N\log N + T\cdot N)$, a memorijska složenost je $O(N)$.
	
	``` cpp title="02_hari.cpp" linenums="1"
	//carobni stapovi
	#include <bits/stdc++.h>
	
	using namespace std;
	
	struct Stap {
	    int tip;
	    int pozicija;
	
	    bool operator < (const Stap &s) const {
	        if (tip != s.tip) {
	            return tip < s.tip;
	        }
	        return pozicija < s.pozicija;
	    }
	};
	
	int n, k, br_delilaca, delilac[12345], k_ti[200000];
	Stap stap[200000];
	
	void nadji_delioce(int n) {
	    br_delilaca = 0;
	    for (int i = 1; i <= n; i++) {
	        if (n % i == 0) {
	            delilac[br_delilaca++] = i;
	        }
	    }
	}
	
	bool proveri_grupu(int pocetak, int kraj) {
	    for (int i = pocetak; i < kraj; i++) {
	        if (k_ti[i] == -1) {
	            continue;
	        }
	        if (k_ti[i] < kraj) {
	            return false;
	        }
	    }
	
	    return true;
	}
	
	int main() {
	    scanf("%d %d", &n, &k);
	    for (int i = 0; i < n; i++) {
	        scanf("%d", &stap[i].tip);
	        stap[i].pozicija = i;
	    }
	
	    nadji_delioce(n);
	
	    sort(stap, stap + n);
	
	    for (int i = 0; i < n; i++) {
	        if (i + k >= n || stap[i].tip != stap[i + k].tip) {
	            k_ti[stap[i].pozicija] = -1;
	        }
	        else {
	            k_ti[stap[i].pozicija] = stap[i + k].pozicija;
	        }
	    }
	
	    int br_nacina = 0;
	
	    for (int d = 0; d < br_delilaca; d++) {
	        int br_grupa = n / delilac[d];
	        bool balans = true;
	
	        for (int g = 0; g < br_grupa; g++) {
	            int pocetak = g * delilac[d];
	            int kraj = (g+1) * delilac[d];
	            if (!proveri_grupu(pocetak, kraj)) {
	                balans = false;
	                break;
	            }
	        }
	
	        if (balans) {
	            br_nacina++;
	        }
	    }
	
	    printf("%d\n", br_nacina);
	
	    return 0;
	}

	```
