---
hide:
  - toc
---

# B3 - Esikez

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Esikez je grad u kojem živi oko sto dvadeset miliona stanovnika. Kroz grad prolaze dva nadaleko poznata bulevara Naprolenez i Melkefrener. Na svakom od njih nalazi se veliki broj fontana. Ove fontane su neplanski građene hiljadama godina, pa je zato gradonačelnica odlučila da konačno celu ovu situaciju dovede u red. Srećom, **za oba bulevara važi da na njemu ne postoje dve fontane iste boje**. Vlast želi da sruši neke od fontana tako da nizovi fontana koji preostanu nakon ovog rušenja budu isti za oba bulevara, tačnije, od svih fontana koje preostanu, prva fontana sa Naproleneza treba da bude iste boje kao prva fontana sa Melkefrenera, druga fontana sa Naproleneza treba da bude iste boje kao druga fontana sa Melkefrenera, i tako dalje, i poslednja fontana sa Naproleneza treba da bude iste boje kao poslednja fontana sa Melkefrenera. Naravno, treba da ostane isti broj fontana na oba bulevara. Ako se sruše sve fontane, u tom slučaju ne preostaje nijedna fontana pa i tad kažemo da su nizovi fontana jednaki.
	
	Pomozite gradonačelnici tako što ćete joj reći koliko najmanje fontana treba da sruši.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalaze se dva prirodna broja $N, M$ odvojena razmakom - broj fontana na Naprolenezu i Melkefreneru, redom. U narednom redu nalazi se $N$ prirodnih brojeva $a_i$ odvojenih razmakom, koji predstavljaju boje fontana na Naprolenezu. U narednom redu nalazi se $M$ prirodnih brojeva $b_i$ odvojenih razmakom, koji predstavljaju boje fontana na Melkefreneru.
	
	## Opis izlaza
	U jedinom redu standardnog izlaza ispisati najmanji broj fontana koje treba srušiti tako da se dobiju isti nizovi fontana na oba bulevara.
	
	## Primer
	### Ulaz
	```
	4 6
	4 2 1 6
	3 2 5 9 6 1
	```
	
	### Izlaz
	```
	6
	```
	
	## Objašnjenje primera
	Rušimo fontane na sledeći način:
	
	```
	. 2 1 .
	. 2 . . . 1
	```
	
	Dobijaju se nizovi $2,1$. Nije moguće srušiti manje od $6$ fontana.
	
	## Ograničenja i podzadaci
	
	* $1 \leq N, M \leq 200000$.
	* $1 \leq a_i, b_i \leq 2 \times 10^9$.
	* $a_i \neq a_j$ za svako $i, j$, $1 \leq i < j \leq N$.
	* $b_i \neq b_j$ za svako $i, j$, $1 \leq i < j \leq M$.
	
	Postoji šest podzadataka:
	
	* Podzadatak $1$ [$3$ poena]: $N, M \leq 2$.
	* Podzadatak $2$ [$11$ poena]: $N+M \leq 20$.
	* Podzadatak $3$ [$10$ poena]: $N \leq 18$.
	* Podzadatak $4$ [$21$ poen]: $N, M \leq 1000$
	* Podzadatak $5$ [$14$ poena]: $N, M \leq 10000$
	* Podzadatak $6$ [$41$ poen]: Nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Dragan Urošević | Aleksa Plavšić |
	
	Lako se zaključuje da je potrebno odrediti najduži zajednički podniz za nizove koji predstavljaju boje fontana na dva bulevara iz zadatka. Takođe je dobro poznat algoritam baziran na dinamičkom programiranju za određivanje najdužeg zajedničkog podniza dva data niza. Međutim, složenost tog algoritma Je jednaka $\Theta(NM)$, gde su i dužine ta dva niza.
	
	Ono što karakteriše ove nizove je činjenica da su u svakom od njih sve vrednosti međusobno različite. Označimo sa $a$ i $b$ ta dva niza. Onda ćemo formirai treći niz koji će imati isti broj elemenata kao niz $b$, tako da je $c_i$ indeks elementa niza $a$ koji se poklapa sa elementom $b_i$  (ako takav element ne postoji onda će odgovarajući element niza $c$ imati vrednost $-1$). Ovo možemmo izvesti tako što ćemo sortirati elemenete niza $a$ uz priruživanje pozicija na kojima se nalaze u originalnom nizu, a zatim primeniti binarnu pretragu pri traženju svakog od elemenata niza $b$.
	
	Nakon toga ćemo iz niza $c$ izbaciti sve element koji imaju vrednost $-1$ i ono što je ostalo u nizu $c$ su indeksi elemenata niza $a$ koji se pojavljuju u nizu $b$, ali baš u redosledu u kome se pojavljuju (od početka prema kraju niza $b$). 
	
	Nije teško zaključiti da će dužina najdužeg zajedničkog podniza za nizove $a$ i $b$ biti jednaka dužini najdužeg rastućeg podniza (ne obavezno uzastopnih elemenata) niza $c$.
	
	Najduži rastući niz niza $c$ možemo odrediti korišćenjem dinamičkog programiranja. Obrađuje se jedan po jedan element niza $c$ i nakon obrade $i$-tog elementa poznata je dužina najdužeg rastućeg podinza za niz koga čini prvih $i$ elemenata niza $c$ (neka je to h) i takođe za svako $g \leq h$ je poznata najmanja moguća vrednost poslednjeg elementa u rastućem podnizu dužine $g$ )te vrednosti obrazuju niz koji ćemo nazvati $d$). Pri obradi $i+1$-og elementa niza $c$ određuje se najmanji indeks $g$ sa osobinom da je $c_{i+1} < d_g$, To znači da je $d_{g-1} < c_{i+1} < d_g$. Ako takav element ne postoji onda se $c_i$ može dodati na kraj niza dužine $h$ i formirati rastući podniz dužine $h+1$ (tj. vrednost za $h$ se povećava za 1 i vrednost odgovarajućeg $d_h$ se izjednačava sa $c_{i+1}$). U suprotnom se može smanjiti vrednost $d_g$ (tj. najmanja moguća vrednost poslednjeg elementa u rastućem podnizu dužine $g$).
	
	Ako na opisani način obradimo sve elemente niza $c$, krajnja vrednost za $h$ će biti dužina najdužeg rastućeg podniza (tj. rešenje našeg zadatka). Složenost opisanog algoritma je $O(N\log N)$.
	
	``` cpp title="03_esikez.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	int n, m, k;
	pair<int, int> a[200005];
	int b[200005];
	int bsel[200005];
	int dp[200005];
	
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
		cerr.tie(nullptr);
	
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i=0; i<m; i++)
			cin >> b[i];
	
		sort(a, a+n);
	
		for (int i=0; i<m; i++) {
			auto p = lower_bound(a, a+n, pair<int, int>(b[i], -1));
			if (p != a+n && p->first == b[i]) {
				bsel[k++] = p->second;
			}
		}
	
		int h = 0;
		for (int i=0; i<k; i++) {
			auto p = lower_bound(dp+1, dp+h+1, bsel[i]);
			*p = bsel[i];
			if (p == dp+h+1)
				h++;
		}
		cout << n+m-h-h << '\n';
	}
	```
