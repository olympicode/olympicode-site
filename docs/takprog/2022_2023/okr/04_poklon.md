---
hide:
  - toc
---

# A1 - Poklon

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 128MB |
	
	Kao nagradu za prolaz na okružno takmičenje, komisija Vam poklanja $Q$ nizova. Svaki od nizova je dobijen tako što je od glavnog niza $A$, dužine $N$, kopiran neki uzastopni podniz. Preciznije, $i$-ti niz je određen vrednostima $l_i$ i $r_i$, što znači da on sadrži elemente ${A_{l_i}, A_{l_i+1}, ... , A_{r_i}}$, u tom redosledu.
	
	Vama se, međutim, ovaj poklon ne sviđa mnogo, jer Vi volite samo nizove koji su sortirani u neopadajućem poretku. Zato ćete malo izmeniti nizove koje ste dobili. Pošto ne želite da ispadnete nezahvalni, nećete ih mnogo menjati, pa ćete iz svakog niza izbrisati **najviše jedan** element. Takođe, pošto Vas ipak mrzi da sada menjate toliki broj nizova, dovoljno je da za svaki od njih samo odredite da li ga je uopšte moguće izmeniti da postane sortiran.
	
	Podrazumeva se da brisanje elementa iz jednog niza **ne utiče** na druge nizove.
	
	## Opis ulaza
	Prvi red standardnog ulaza sadrži ceo broj $N$, broj elemenata glavnog niza.
	
	Drugi red sadrži $N$ celih brojeva koji predstavljaju glavni niz $A_1, A_2, ..., A_N$.
	
	Treći red sadrži ceo broj $Q$, broj poklonjenih nizova.
	
	Narednih $Q$ redova sadrže po dva broja, $l_i, r_i$, koji označavaju da $i$-ti niz sadrži elemente ${A_{l_i}, A_{l_i+1}, ... , A_{r_i}}$, u tom redosledu.
	
	## Opis izlaza
	Na standardni izlaz je potrebno ispisati $Q$ linija - u $i$-toj liniji ispisati "DA" (bez navodnika) ako je $i$-ti niz moguće sortirati brisanjem najviše jednog elementa, u suprotnom ispisati "NE" (bez navodnika).
	
	## Primer 1
	### Ulaz
	```
	7
	1 7 2 7 2 2 3
	4
	1 4
	2 7
	4 6
	5 5
	```
	
	### Izlaz
	```
	DA
	NE
	DA
	DA
	```
	
	## Objašnjenje primera
	Prvi niz je $[A_1, A_2, A_3, A_4]$, tj. $[1, 7, 2, 7]$. Iz njega možemo izbrisati drugi element da bismo dobili niz $[1, 2, 7]$.
	
	Drugi niz je $[A_2, A_3, A_4, A_5, A_6, A_7]$, tj. $[7, 2, 7, 2, 2, 3]$. Može se videti da koji god element izbrišemo, niz neće biti sortiran.
	
	Treći niz je $[A_4, A_5, A_6]$, tj. $[7, 2, 2]$. Iz njega možemo izbrisati prvi element da bismo dobili niz $[2, 2]$.
	
	Četvrti niz je $[A_5]$, tj. $[2]$. On je već sortiran, pa ne moramo raditi ništa.
	
	## Ograničenja
	
	- $1 \leq N \leq 2 \cdot 10^5$.
	- $1 \leq Q \leq 10^5$.
	- $1 \leq L_i \leq R_i \leq N$ za $1 \leq i \leq Q$.
	- $1 \leq A_i \leq N$.
	
	Test primeri su podeljeni u pet disjunktnih grupa:
	
	- U testovima vrednim 15 poena: $N, Q \leq 200$.
	- U testovima vrednim 25 poena: $N, Q \leq 3000$.
	- U testovima vrednim 10 poena: $Q = 5$.
	- U testovima vrednim 20 poena: Svi elementi niza su $1$ ili $2$.
	- U testovima vrednim 30 poena: nema dodatnih ograničenja.
	
	## Napomena
	Niz $[B_1, B_2, B_3, ... , B_M]$ je sortiran u neopadajućem poretku ako i samo ako važi $B_1 \leq B_2 \leq ... \leq B_M$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Jovan Bengin | Jovan Bengin | Dragan Urošević | Igor Pavlović |
	
	## Rešenje prvog podzadatka
	U ovom slučaju, zbog ograničenja na dužinu niza $A$ (broj $N$) i broj upita $Q$, moguće je za svaki upit $(L_i, R_i)$ proveriti da li podniz postaje sortiran nakon izbacivanja elementa $A_j$ ($j= L_i, L_i+1, L_i+2, \dots R_{i-1}, R_i$). Provera da li je niz sortiran izvodi se tako što se porede parovi uzastopnih (naravno, uzimajući u obzir da je izbačen element $A_j$, pa su elementi $A_{j-1}$ i $A_{j+1}$, ako je $L_i < j < R_i$, uzastopni). Složenost ovog rešenja je $O(QN^2)$.
	
	## Rešenje drugog i trećeg podzadatka
	Rešenje ovih podzadataka dobija se "profinjenjem" rešenja za prvi zadatak. To "profinjenje" se postiže tako što se za vrednosti $j$ za koje je $A_{j-1}\leq A_j \leq A_{j+1}$ ne proverava da li je podniz dobijen izbacivanjem elementa $A_j$ sortiran (jer element $A_j$ "ne smeta", budući da je, po vrednosti, između elemenata levo i desno od njega). Tokom obrade se proverava da li je podniz koji sadrži sve elemente od pozicije  $L_i$ do pozicije $R_i$ sortiran i ako jeste onda je odgovor na upit "DA". Naravno, i u slučaju da se za neko $j$ ispostavi da je podniz dobijen nakon izbacivanja elementa $A_j$ sortiran, odgovor je "DA".
	
	## Rešenje četvrtog podzadatka
	U ovom podzadatku je moguće sa svaki indeks $i$  ($1\leq i \leq N$) odrediti:
	- indeks $j$ ($j\geq i$) prvog elementa u delu niza koga čine elementi $A_i, A_{i+1}, A_{i+2}, \dots, A_N$ koji ima vrednost  $1$; označimo tu vrednost sa $next_{i,1}$; ako takav element ne postoji onda će odgovarajući indeks imati vrednost $N+1$. 
	- indeks $j$ ($j\geq i$) prvog elementa u delu niza koga čine elementi $A_i, A_{i+1}, A_{i+2}, \dots, A_N$ koji ima vrednost  $2$; označimo tu vrednost sa $next_{i,2}$; ako takav element ne postoji onda će odgovarajući indeks imati vrednost $N+1$.
	
	Ovaj deo se može odraditi nakon učitavanja elemenata niza, a pre odgovaranja na upite.
	
	Kada odgovaramo na upit za par brojeva $(L,R)$, onda određujemo indeks $X$ prvog elementa od pozicije $L$ koji ima vrednost $2$ ($X=next_{L,2}$) i indeks $Y$ prvog elementa od pozicije $X$ koji ima vrednost $1$ ($Y=next_{X,1}$).
	Može se pokazati da će odgovor biti "DA" samo u sledećim slučajevima
	
	- ako je $Y>R$ (jer su elementi od pozicije $L$ do pozicije $X-1$ jednaki $1$, a od pozicije $X$ pa do pozicije $Y-1\geq R$ jednaki $2$; 
	- ako je $next_{Y+1,1}>R$, jer se može izbaciti jedinica sa pozicije $Y$, i tako će se dobiti blok dvojki od pozicije $X$ pa do pozicije $next_{Y+1,1}-1 \geq R$ i podniz će biti sortiran;
	- ako je $Y=X+1$ i  $next_{next_{Y,2},1}>R$, jer se na poziciji $X$ nalazi broj $2$, ali odmah nakon toga broj $1$, a nakon prve dvojke posle pozicije $Y$ sledi blok dvojki koji se završava nakon pozicije $R$; brisanjem dvojke na poziciji $X$ dobija se sortiran podniz.
	
	U svim ostalim slučajevima, odgovor je "NE".
	Matrica $next$ može biti izračunata u vremenu $\Theta(N)$, a kako je složenost odgovora na svaki upit $\Theta(1)$, to je ukupna složenost $\Theta(N+Q)$.
	
	## Glavno rešenje
	Za svaki indeks $i$ ($1\leq i \leq N$) se može odrediti najveći indeks $j$ tako da je podniz od indeksa $i$ do indeksa $j$ neopadajući:
	 $$
	 A_i \leq A_{i+1} \leq A_{i+2} \leq \dotsb \leq A_{j-1} \leq A_j.
	 $$
	 Označimo indeks $j$ koji ima gornju osobinu  sa $last_i$. Primetimo da je $last_i = N$ ili je $A_{last_i} > A_{last_i+1}$. 
	Tada će odgovor na upit za par indeksa $(L,R)$ biti "DA" u sledećim slučajevima:
	
	- ako je $last_L \geq R-1$ (jer može biti obrisan $A_R$)
	- ako je $last_{last_L+1} \geq R$ i $last_L = L$ ili je $A_{last_L-1} \leq A_{last_L+1}$, jer se brisanjem elementa  $A_{last_L}$ dobija sortiran podniz.
	- ako je $last_{last_L+2} \geq R$ i $A_{last_L} \leq A_{last_L+2}$, jer se tada brisanjem elementa $A_{last_L+1}$ dobija sortiran podniz. 
	
	Elementi niza $last$ mogu biti sračunati korišenjem sledećih činjenica:
	
	- $last_N = N$,
	- $last_i = last_{i+1}$ ako je $A_i \leq A_{i+1}$ i $last_i = i$, ako je $A_i > A_{i+1}$, za $i=N-1, N-2, \dots, 2, 1$.
	Prema tome, složenost izračunavanja elemenata niza $last$ je $\Theta(N)$, a budući da je složenost odgovaranja na jedan upit $\Theta(1)$, složenost kompletnog rešenja je $\Theta(N+Q)$.
	
	``` cpp title="04_poklon.cpp" linenums="1"
	#include <iostream>
	using namespace std;
	
	const int N = 300000;
	
	int niz[N+5];
	int poslednji_dobar[N+5];
	
	int main(){
	    ios_base::sync_with_stdio(false), cin.tie(0);
	
	    int n;
	    cin >> n;
	    for(int i=1; i<=n; i++) cin >> niz[i];
	    poslednji_dobar[n] = n;
	    for(int i=n-1; i>=1; i--){
	        if(niz[i] > niz[i+1]) poslednji_dobar[i] = i;
	        else poslednji_dobar[i] = poslednji_dobar[i+1];
	    }
	    int q;
	    cin >> q;
	    for(int i=1; i<=q; i++){
	        int l, r;
	        cin >> l >> r;
	        int p = poslednji_dobar[l];
	        if(p >= r - 1) cout << "DA\n";
	        else if(poslednji_dobar[p+1] >= r && (p == l || niz[p-1] <= niz[p+1])) cout << "DA\n"; /// brisanje niz[p]
	        else if(poslednji_dobar[p+2] >= r && niz[p] <= niz[p+2]) cout << "DA\n"; /// brisanje niz[p+1]
	        else cout << "NE\n";
	    }
	    return 0;
	}
	```
