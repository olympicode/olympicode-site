---
hide:
  - toc
---

# B2 - Kralj Artur

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 100ms | 64MB |
	
	Kralj Artur priprema svoje vojnike za odlučujuću bitku protiv Saksonaca. Kako bi iskoristile svoj pun potencijal na bojnom polju, neophodno je za svaku od $m$ armija odabrati po jednog komandanta. Sve armije imaju isti broj vojnika, i on iznosi n. Artur zna da svaki komandant mora da dobro poznaje vojnike kojima komanduje, pa obično za tu ulogu bira nekog od vojnika iz same armije. Naprednim proračunima, shvatio je da ukupna moć (tj. zbir veština svih komandanata) ne sme da bude prevelika, jer tada može doći do nesuglasica među njima i postoji opasnost da se armije sukobe međusobno. Istog trena je napravio spisak svih mogućih izbora m komandanata i za svaki od izbora zabeležio ukupnu moć. Nakon toga je najsavremenijim algoritmom tog doba, „Bozo sort”-om, sortirao spisak opadajuće po moći. 
	
	Ipak, sedam dana nije uspeo da napravi pravilan izbor. Osmog dana mu je bilo dosta, i odlučio je da pita svog mudrog čarobnjaka-savetnika Merlina za savet. Nakon dužeg glađenja sede brade, Merlin je lupio magičan broj $k$ i rekao da je vrlo očigledno da je pravi izbor onaj $k$-ti sa Arturovog spiska (pri čemu Merlin zna da broj mogućih izbora nije manji od $k$). Arturu ovo svakako nije bilo očigledno, i odmah je otišao da obavesti vitezove okruglog stola o tome. Prvo što su ga vitezovi pitali bilo je kolika će u tom slučaju biti ukupna moć armije. Pomozite Arturu, koji je previše uzbuđen da bi se setio tačnog broja, da im odgovori na pitanje.
	
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se brojevi $m$, $n$ i $k$, koji predstavljaju broj armija, broj vojnika u svakoj armiji, i Merlinov magičan broj, redom. Svaka od narednih $m$ linija sadrži $n$ brojeva koji označavaju veštine vojnika. Brojevi u $i$-tom redu se odnose na vojnike iz $i$-te armije.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza potrebno je ispisati odgovor na viteško
	pitanje, tj. ukupnu moć odabrane armije.
	
	## Primer 1
	### Ulaz
	```
	2 3 6
	2 3 1
	4 5 6
	```
	
	### Izlaz
	```
	7
	```
	
	## Objašnjenja primera
	Artur na raspolaganju ima dve armije, i po tri vojnika u svakoj od njih. Kandidati za komandanta prve armije su vojnici sa veštinama iz skupa {2, 3, 1}, a druge armije vojnici sa veštinama iz skupa {4, 5, 6}. Arturov sortiran spisak svih mogućih ukupnih moći je: [9, 8, 8, 7, 7, 7, 6, 6, 5]. Traženi broj je šesti broj na spisku, tj. 7.
	
	## Ograničenja
	* $1 ≤ m ≤ 10$.
	* $1 ≤ n ≤ 1000$.
	* $1 ≤ k ≤ 10^18$.
	* Veštine vojnika su nenegativni celi brojevi manji ili jednaki 1000.
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u 5 podzadataka, u kojima važe sledeća dodatna ograničenja:
	
	* Podzadatak 1 [12 poena]: $m = 1$.
	* Podzadatak 2 [15 poena]: $k ≤ 2$.
	* Podzadatak 3 [24 poena]: $m ≤ 4, n ≤ 30$.
	* Podzadatak 4 [28 poena]: $n ≤ 6$.
	* Podzadatak 5 [21 poena]: Nema dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Marko Ilić | Nikola Jovanović |
	
	## Rešenje za $m = 1$:
	S tim da u ovom podzadatku imamo samo jednu armiju, njene vojnike možemo sortirati nerastuće po veštinama i izabrati $k$-tog vojnika za komandanta. Vremenska složenost: $O(nlogn$). Memorijska složenost: $O(m \cdot n)$.
	
	## Rešenje za $k \le 2$:
	Ukoliko je $k = 1$ treba izabrati najboljeg vojnika iz svake armije, dok za slučaj $k = 2$ biramo izbor sa najvećom moći, tako da je jedan komandant drugi najbolji vojnik u svojoj armiji, a svi ostali komandanti najbolji vojnici u svojim armijama. Vremenska složenost: $(n \cdot m + m)$. Memorijska složenost: $(m \cdot n)$.
	
	## Rešenje za $m \le 4$ i $n \le 30$: 
	S tim da su $n$ i $m$ dosta mali, možemo izračunati ukupnu moć za svaki izbor komandanata, sortirati sve odabire nerastuće po ukupnoj moći i izabrati $k$-ti najbolji. Za sortiranje možemo koristiti *counting sort*, pošto će ukupne moći biti vrednosti do $10^4$. Vremenska složenost: $O(n^m)$. Memorijska složenost: $O(n^m)$.
	
	## Rešenje za $n \le 6$:
	Ovaj podzadatak se može rešiti isto kao prethodni, ali je za simuliranje svih izbora komandanata najlakše koristiti rekurziju.
	
	## Glavno rešenje:
	Ideja nam je da za svaku moguću vrednost ukupne moći komandanata izračunamo na koliko načina je možemo postići. Neka nam je $dp_{i, x}$ taj broj izbora za ukupnu moć $x$ birajući samo vojnike iz prvih $i$ armija i neka je $a_{i, j}$ moć $j$-tog vojnika u $i$-toj armiji. Rekurentna formula je $dp_{i, x} = \sum_{j = 1}^{n} dp_{i-1, x - a_{i, j}}$, zato što kada izaberemo jednog vojnika iz $i$-te armije, ostale vojnike biramo iz prvih $i-1$ armija. Takođe, u formuli posmatramo samo one $j$ za koje važi da je $x$ veće ili jednako $a_{i, j}$. Vremenska složenost: $O(n \cdot m^2 \cdot maxa)$, gde je $maxa$ najveća moć svih vojnika. Memorijska složenost: $O(n \cdot m + m^2 \cdot maxa)$.
	
	``` cpp title="02_kralj_artur.cpp" linenums="1"
	#include <iostream>
	#include <algorithm>
	using namespace std;
	
	const long long lim = 1ll << 60ll;
	
	inline void add(long long& x, long long y){
	    x += y;
	    if (x > lim) x = lim;
	}
	
	int N, M;
	long long K;
	
	int A[11][1001];
	long long D[11][10001];
	
	int main(){
	    cin >> M >> N >> K;
	    for (int i=1; i<=M; i++){
	        for (int j=1; j<=N; j++){
	            cin >> A[i][j];
	        }
	    }
	    D[0][0] = 1;
	    for (int i=1; i<=M; i++){
	        for (int j=1; j<=N; j++){
	            int x = A[i][j];
	            for (int k=x; k<=1000*i; k++){
	                add(D[i][k], D[i-1][k-x]);
	            }
	        }
	    }
	    int w = 1000*M;
	    while (w>=0){
	        if (K <= D[M][w]){
	            cout << w << endl;
	            return 0;
	        } else {
	            K -= D[M][w];
	            w--;
	        }
	    }
	    return 0;
	}

	```
