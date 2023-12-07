---
hide:
  - toc
---

# 2 - Marsko

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Kao što svi znamo, ljudi su odavno kolonizovali Mars i na njemu izgradili $N$ gradova i $M$ puteva. Kako do površine Marsa dopire velika doza jonizujućeg zračenja iz svemira, oko gradova i puteva izgrađene su zaštitne kupole. Međutim, nisu svi putevi napravljeni i održavani po propisima (kao i na Zemlji). Poznato je da je količina zračenja koju propušta zaštita puta $i$ jednaka $W_i$. Vozila koja se koriste na Marsu imaju dodatnu zaštitu od zračenja. Vozilom koje ima zaštitu $A$, bezbedno je voziti se po putu $i$ ako je $W_i \leq A$. U svakom gradu nalazi se po jedno vozilo. Vozilo koje se nalazi u $i$-tom gradu ima zaštitu $A_i$. Junak našeg zadatka, Marsko, planira da se preseli na Mars, ali još uvek nije odlučio u koji grad. Kako bi doneo odluku, za svaki grad $i$ zanima ga do koliko gradova može bezbedno da stigne ako krene odatle i sme da menja vozila. Pomozite Marsku da se preseli na Mars tako što ćete rešiti ovaj problem umesto njega.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $\text{Resi}(N, A[\dots], M, U[\dots], V[\dots], W[\dots], R[\dots])$
	
	gde je:
	
	* $N$ broj gradova.
	* $A$ niz celih brojeva gde $i$-ti broj predstavlja zaštitu vozila koje se nalazi u gradu $i$.
	* $M$ broj puteva.
	* $U$, $V$ i $W$ nizovi dužine $M$ koji opisuju puteve: $i$-ti put povezuje gradove $U_i$ i $V_i$, dok je količina zračenja koju propušta zaštita ovog puta $W_i$.
	* $R$ niz u koji treba da upišete rešenje za svaki grad.
	
	**Svi nizovi su indeksirani od 1.**
	
	## Ograničenja
	* $1 \leq N, M \leq 2 \times 10^5$
	* $1 \leq A_i, W_i \leq 10^9$
	* $1 \leq U_i, V_i \leq N$
	* $U_i \neq V_i$
	* Postoji najviše jedan put koji direktno povezuje neki par gradova.
	
	## Podzadaci
	* **[7 poena]:** Sve vrednosti u nizu $A$ su jednake.
	* **[7 poena]:** Sve vrednosti u nizu $W$ su jednake.
	* **[12 poena]:** $N, M \leq 250$.
	* **[33 poena]:** $N, M \leq 2500$.
	* **[41 poena]:** Bez dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `marsko.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova, ali ne smeju da pristupaju van njihovih granica**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$ i $M$.
	* U narednom redu niz $A$.
	* U narednih $M$ redova po tri broja. U $i$-tom redu nalaze se brojevi $U_i$, $V_i$ i $W_i$.
	
	Zatim ovaj program poziva vašu funkciju i štampa niz $R$ koji je funkcija popunila, u jednom redu.
	
	## Primeri
	### Primer 1
	#### Ulaz
	```
	5 7
	7 7 7 7 7
	1 2 3
	1 3 8
	2 5 7
	4 5 10
	1 5 6
	2 3 9
	3 5 8
	```
	
	#### Izlaz
	```
	3 3 1 1 3
	```
	
	#### Objašnjenje
	Vozilom sa zaštitom $7$ moguće je bezbedno se voziti po prvom, trećem i petom putu. Iz prvog, drugog i petog grada moguće je bezbedno stići u prvi, drugi i peti grad. Iz trećeg i četvrtog grada nije moguće bezbedno stići u neki drugi grad.
	
	### Primer 2
	#### Ulaz
	```
	5 4
	1 7 8 5 3
	1 3 7
	1 5 7
	3 5 7
	2 4 7
	```
	
	#### Izlaz
	```
	1 2 3 1 1
	```
	
	#### Objašnjenje
	Iz prvog, četvrtog i petog grada nije moguće bezbedno stići u neki drugi grad. Iz drugog grada moguće je bezbedno stići u drugi i četvrti grad. Iz trećeg grada moguće je bezbedno stići u prvi, treći i peti grad.
	
	### Primer 3
	#### Ulaz
	```
	5 5
	5 9 6 1 3
	1 5 7
	1 2 4
	2 5 9
	4 3 2
	3 5 6
	```
	
	#### Izlaz
	```
	5 5 3 1 1
	```
	
	#### Objašnjenje
	Iz prvog grada moguće je bezbedno stići u drugi grad. Kada u drugom gradu zamenimo vozilo možemo bezbedno da stignemo do svih gradova.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Tadija Šebez | Tadija Šebez | Tadija Šebez | Aleksa Plavšić |
	
	## Rešenje kada su sve vrednosti u nizu $A$ jednake
	Kako sva vozila imaju istu zaštitu, možemo da izbacimo puteve kojima Marsko ne može bezbedno da se vozi. Nakon toga možemo DFS algoritmom da nađemo povezane komponente i njihove veličine. Rešenje za svaki grad je veličina njegove povezane komponente.
	
	## Rešenje kada su sve vrednosti u nizu $W$ jednake
	Za svako vozilo važi da Marsko može bezbedno da se vozi po bilo kom putu ili uopšte ne može bezbedno da se vozi. U prvom slučaju je rešenje veličina povezane komponente u kojoj se grad nalazi, a u drugom slučaju rešenje je 1. I ovaj podzadatak rešavamo DFS algoritmom.
	
	## Rešenje za $N, M \leq 250$
	Za svaki grad $i$ nađimo skup gradova koje Marsko može da poseti krenuvši iz $i$-tog grada ako koristi samo vozilo koje je zatekao u početnom gradu. Napravimo usmereni graf tako što ćemo dodati granu od $i$-tog grada do svakog grada iz prethodno pomenutog skupa. Rešenje za grad $i$ je broj čvorova koje možemo da posetimo krenuvši od čvora $i$ u usmerenom grafu. Ovaj podzadatak takođe možemo da rešimo primenom DFS algoritma. Vremenska složenost ovog rešenja je $O(N^3)$.
	
	## Rešenje za $N, M \leq 2500$
	Krenimo iz grada $i$ i pamtimo najveću vrednost $A$ za gradove koje smo posetili. Ubacimo sve puteve od posećenih gradova u **heap** strukturu podataka. Uzmimo put sa najmanjim $W$ i ako je ova vrednost manja od najvećeg $A$ za posećene gradove, možemo da pređemo preko tog puta i posetimo novi grad ako već nije posećen. Ako smo posetili novi grad ažuriramo maksimalno $A$ i dodajemo nove puteve na **heap**. Kada više nemamo puteva ili svi putevi na **heap**-u imaju preveliku vrednost $W$, prekidamo i pamtimo broj posećenih čvorova kao rešenje za grad $i$. Ovo rešenje pokrećemo za svaki grad pa je vremenska složenost $O(NMlogM)$
	
	## Rešenje za 100 poena
	Rešenje za neki grad jednako je rešenju grada sa najvećim $A_i$ među gradovima koje može da poseti. Posmatrajmo grad $i$ i skup $S$ svih gradova koji ne mogu da posete grad sa većim $A$ od svog. Neka je $j$ grad sa najmanjim $A$ među gradovima iz skupa $S$ koji mogu da posete grad $i$. Rešenje za $i$ je isto kao rešenje za $j$. Dokazaćemo prethodno tvrđenje tako što ćemo pokazati da $i$ može da poseti $j$. Ako $i$ može da poseti neki grad $k$ sa $A_k \geq A_j$, može i da poseti $j$ tako što ode do $k$, pređe u vozilo iz tog grada, vrati se u $i$ i ode u $j$ obrnutim putem kojim bi se od $j$ došlo do $i$ (znamo da su na tom putu svi $W_e \leq A_j \leq A_k$ jer $j$ ne može da poseti grad sa većim $A$). Ako je $A_k < A_j$ za sve gradove koje $i$ može da poseti, onda postoji grad u skupu $S$ koji može da poseti $i$ i ima manje $A$ nego grad $j$, što je kontradikcija. Sada znamo da je rešenje za svaki grad jednako rešenju za najmanji grad po vrednosti $A$ u skupu $S$ koji može da poseti taj grad i možemo da rešimo zadatak na sledeći način. Procesirajmo gradove rastuće po njihovim vrednostima $A$. Kada procesiramo neki grad $i$ dodajemo sve grane $e$ koje imaju $W_e$ manje ili jednako $A_i$. Za svaku povezanu komponentu čuvajmo najveće $A$ za čvorove u njoj. Ako je najveće $A$ za čvorove u komponenti čvora $i$ jednako $A_i$, čvor $i$ je u skupu $S$ i njegovo rešenje je veličina povezane komponente. Takođe je to i rešenje za svaki čvor u ovoj komponenti koji se već nije našao u komponenti nekog čvora iz skupa $S$. Možemo da održavamo ove gradove za svaku komponentu u nizu i da ih prebacujemo iz manje u veću komponentu kada se dogodi spajanje dve komponente. Na ovaj način dobijamo rešenje koje radi u vremenskoj složenosti $O(NlogN + MlogM)$.
	
	``` cpp title="02_marsko.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	const int N=200005;
	
	int edge_order[N],node_order[N];
	
	struct Component{
		int size,max_a;
		vector<int> alive,all_nodes;
		Component(){}
		void init(int u,int A){
			size=1;
			max_a=A;
			alive=all_nodes={u};
		}
	}components[N];
	int my_component[N];
	
	void Merge(int a,int b){
		if(a==b)return;
	
		if(components[a].size<components[b].size)swap(a,b);
	
		components[a].size+=components[b].size;
		components[a].max_a=max(components[a].max_a,components[b].max_a);
	
		for(int i:components[b].alive){
			components[a].alive.push_back(i);
		}
		for(int i:components[b].all_nodes){
			components[a].all_nodes.push_back(i);
			my_component[i]=a;
		}
	}
	
	void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R){
	
		for(int i=1;i<=M;i++)edge_order[i]=i;
		sort(edge_order+1,edge_order+1+M,[&](int i,int j){return W[i]<W[j];});
	
		for(int i=1;i<=N;i++)node_order[i]=i;
		sort(node_order+1,node_order+1+N,[&](int i,int j){return A[i]<A[j];});
	
		for(int i=1;i<=N;i++){
			components[i].init(i,A[i]);
			my_component[i]=i;
		}
	
		int ptr=1;
		for(int i=1;i<=N;i++){
			while(ptr<=M && W[edge_order[ptr]]<=A[node_order[i]]){
				Merge(my_component[U[edge_order[ptr]]],my_component[V[edge_order[ptr]]]);
				ptr++;
			}
	
			if(components[my_component[node_order[i]]].max_a==A[node_order[i]]){
	
				for(int j:components[my_component[node_order[i]]].alive){
					R[j]=components[my_component[node_order[i]]].size;
				}
	
				components[my_component[node_order[i]]].alive.clear();
			}
		}
	}

	```
