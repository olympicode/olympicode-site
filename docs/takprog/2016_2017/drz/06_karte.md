---
hide:
  - toc
---

# A3 - Karte

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 600ms | 64MB |
	
	Vučko je preturajući po sobi, iza jednog baštenskog rekvizita koji je dobio od drugara kao rođendanski poklon, pronašao stari špil karata. Na svakoj karti bio je ispisan jedan prirodan broj. On je odmah pozvao Kocu da igraju sledeću igru: Prvo Vučko položi sve karte licem nadole a zatim Koca bira dve karte, čita brojeve sa njih i zatim traži prirodan broj veći od $1$ koji deli oba izvučena broja. Ako se ispostavi da takav broj ne postoji, Vučko pobeđuje. U suprotnom, niko ne pobeđuje (svakako Koca ne pobeđuje). Vučko sprema ispit iz verovatnoće pa želi da kao vežbu izračuna verovatnoću da će pobediti u ovoj igri. Za to mu je potrebna vaša pomoć! Recite Vučku na koliko načina se mogu odabrati dve karte tako da on pobedi.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se jedan prirodan broj $N$, broj karata u špilu. U narednih $N$ redova nalazi se po jedan prirodan broj $A_i$, broj sa $i$-te karte.
	
	## Opis izlaza
	Na standardni izlaz ispisati jedan ceo broj -- broj načina da se izvuku dve karte tako da Vučko pobeđuje.
	
	## Primer 1
	### Ulaz
	```
	3
	2
	3
	6
	```
	
	### Izlaz
	```
	1
	```
	
	## Primer 2
	### Ulaz
	```
	4
	1
	6
	10
	15
	```
	
	### Izlaz
	```
	3
	```
	
	## Objašnjenje primera
	U prvom primeru, jedini način da Vučko pobedi jeste da Koca izvuče prvu i drugu kartu. U drugom primeru, postoje tri načina -- ako Koca izvuče prvu kartu i bilo koju od preostale tri.
	
	## Ograničenja i podzadaci
	* $1 \leq A_i \leq 10^8$
	
	Postoje $4$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [9 poena]: $1 \leq N, A_i \leq 100$.
	* Podzadatak 2 [10 poena]: $1 \leq N \leq 1000$
	* Podzadatak 3 [30 poena]: $1 \leq N \leq 7000$.
	* Podzadatak 4 [51 poena]: $1 \leq N \leq 30000$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Ivan Stošić | - |
	
	U ovom zadatku traži se da se nađe broj uređenih parova $(i, j), 1 \leq i < j \leq N$ tako da su $A_i, A_j$ uzajamno prosti brojevi. Za svaka dva broja $x, y$ možemo direktnom proverom, u vremenskoj složenosti $O(min(x, y))$ proveriti da li postoji neki prirodan broj, veći od $1$, koji deli oba ova broja. Ovakav algoritam je dovoljan za rešavanje prvog podzadatka.
	Za drugi podzadatak možemo koristiti Euklidov algoritam, koji u samo $O(log(min(x, y)))$ deljenja nalazi NZD dva broja. Međutim, ovaj algoritam nije dovoljan za treći podzadatak -- operacije deljenja su veoma skupe.
	Zato, za treći, a i četvrti podzadatak, prvo potražimo sve proste brojeve do $\sqrt{10^8} = 10^4$, npr. pomoću Eratostenovog sita, a zatim pomoću ovih brojeva faktorišimo sve date brojeve, odnosno, napišimo ih u obliku proizvoda prostih brojeva. Primetimo da su dva broja uzajamno prosta ako i samo ako njihove liste prostih delilaca nemaju nijedan zajednički element, što znači da pri pamćenju listi prostih delilaca možemo izostaviti duplikate. Pošto je $2 \times 3 \times 5 \times 7 \times 9 \times 11 \times 13 \times 17 \times 19 > 10^8$, nijedan od datih brojeva neće imati više od $8$ različitih prostih delilaca.
	Za treći podzadatak, za svaka dva broja uporedimo njihove liste prostih delilaca i na ovaj način ispitujemo da li su oni uzajamno prosti. Ovaj korak se može uraditi u vremenskoj složenosti $O(k+l)$, gde su $k, l$ dužine listi za te brojeve, ako prethodno sortiramo sve ove liste.
	Za maksimalan broj poena možemo koristiti sledeći postupak. Prvo, modifikujmo postavku problema. Umesto broja uređenih parova oblika $(i, j), 1 \leq i < j \leq N$ potražimo broj uređenih parova oblika $(i, j), 1 \leq i, j \leq N$. Od broja ovakvih parova treba oduzeti broj parova oblika $(i, i), 1 \leq i \leq N$, odnosno, broj jedinica u datom nizu, a zatim podeliti ovu razliku sa $2$. Zatim, za svaki broj iz datog niza izračunajmo sve "bezkvadratne" delioce -- one koji nisu deljivi kvadratom nijednog prostog broja. Ako broj $x$ ima $q$ različitih prostih delioca, onda on ima tačno $2^q$ bezkvadratnih delioca. Ovo možemo efikasno uraditi pomoću već dobijene proste faktorizacije. Naš cilj je da možemo za svaki bezkvadratni broj da efikasno proverimo koliko brojeva iz datog niza je deljivo tim brojem. Ovo možemo uraditi na više načina, brojanjem i/ili sortiranjem svih nađenih bezkvadratnih delioca. Zatim, za neki broj $x$ čiju prostu faktorizaciju imamo, možemo proveriti koliko brojeva iz datog niza je uzajamno prosto sa njim pomoću principa uključenja-isključenja i prethodno pomenute provere. Prvo, uzmimo da su svi brojevi iz datog niza uzajamno prosti sa $x$. Zatim, izbacimo sve one koji su deljivi sa $p_1, p_2, ..., p_q$ pa ubacimo one koji su deljivi sa $p_1 p_2 , p_1 p_3, ..., p_{q-1} p_q$, itd. Izraz za konačnu vremensku složenost ovog algoritma je dosta komplikovan i stoga izostavljen. Ovo je dovoljno brzo i za poslednji, najopštiji podzadatak.
	
	## Napomene
	Brojanje bezkvadratnih delioca može se postići na više načina, kombinacijom sortiranja i binarne pretrage, brojanjem (slično Counting Sort-u) za dovoljno male vrednosti, ili smeštanjem u mapu (C++).
	
	``` cpp title="06_karte.cpp" linenums="1"
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	#include <vector>
	using namespace std;
	
	vector<int> f[30005];
	int a[30005], n;
	
	bool sl[10005];
	vector<int> prosti; // 1229 brojeva
	
	// svi brojevi do 100M imaju najvise 8 razlicitih prostih delioca
	
	int moj_lzcnt[256];
	int moj_parity[256];
	
	void sito_i_lzcnt() {
		for (int i=2; i<=10000; i++) {
			if (!sl[i]) {
				prosti.push_back(i);
				for (int j=i*i; j<=10000; j+=i) {
					sl[j] = true;
				}
			}
		}
		for (int i=1; i<256; i++) {
			int x = i, c = 0;
			while (x % 2 == 0) {
				c++;
				x >>= 1;
			}
			moj_lzcnt[i] = c;
		}
		moj_parity[0] = 1;
		for (int i=1; i<256; i++) {
			moj_parity[i] = -moj_parity[i - (1 << moj_lzcnt[i])];
		}
	}
	
	void ucitaj() {
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", a+i);
		sort(a, a+n);
	}
	
	void faktorisi() {
		for (int i=0; i<n; i++) {
			int k = a[i];
			for (int x : prosti) {
				if (k % x == 0) {
					f[i].push_back(x);
					do {
						k /= x;
					} while (k % x == 0);
				}
				if (x > k) break;
			}
			if (k > 1) {
				f[i].push_back(k);
			}
		}
	}
	
	const int MAX = 100'000'000;
	const int LIMIT = 10'000'000;
	uint16_t br[LIMIT+5];
	
	int br_delioca;
	int delioci[256];
	
	// ne idu svi delioci vec samo oni koji nemaju isti prost broj vise puta
	void napuni_deliocima(int i) {
		delioci[0] = 1;
		br_delioca = 1 << f[i].size();
		for (int mask=1; mask<br_delioca; mask++) {
			int lz = moj_lzcnt[mask];
			delioci[mask] = delioci[mask - (1 << lz)] * f[i][lz];
		}
	}
	
	int broj_deljivih(int x) {
		if (x <= LIMIT) {
			return br[x];
		}
		int c = 0;
		for (int y=x; y<=MAX; y+=x) {
			c += upper_bound(a, a+n, y) - lower_bound(a, a+n, y);
		}
		return c;
	}
	
	void resi() {
		for (int i=0; i<n; i++) {
			napuni_deliocima(i);
			for (int mask=1; mask<br_delioca; mask++) {
				if (delioci[mask] <= LIMIT) {
					br[delioci[mask]]++;
				}
			}
		}
		long long sol = 0;
		for (int i=0; i<n; i++) {
			napuni_deliocima(i);
			sol += n;
			for (int mask=1; mask<br_delioca; mask++) {
				sol += moj_parity[mask] * broj_deljivih(delioci[mask]);
			}
		}
		// odbaci jedinice
		sol -= count(a, a+n, 1);
		
		// odbaci simetricne parove
		sol /= 2;
		
		printf("%lld\n", sol);
	}
	
	int main() {
		sito_i_lzcnt();
		ucitaj();
		faktorisi();
		resi();
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	

	```
