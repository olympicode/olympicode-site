---
hide:
  - toc
---

# 1 - Računar

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Na jednom računaru se izvršava $N$ zadataka paralelno. Za svaki zadatak je poznat početni i krajnji tranutak njegovog izvršavanja. Nakon što zadatak završi sa izvršavanjem on prvo mora da sačeka da se završe svi zadaci koji su počeli pre njega pre nego što upiše svoj rezultat u memoriju. Upisivanje u memoriju se vrši trenutno.
	
	
	
	Vaš zadatak je da za svaki od $N$ zadataka odredite u kom trenutku će njegov rezultat biti upisan u memoriju.
	
	
	
	## Opis ulaza
	
	Prvi red standardnog ulaza sadrži jedan ceo broj $N$. Narednih $N$ redova standardnog ulaza sadrže dva cela broja $A_i$ i $B_i$, početni i krajnji trenutak zadatka.
	
	
	## Opis izlaza
	
	
	U $i$-tom redu standardnog izalaza ispisati trenutak u kom će $i$-ti zadatak upisati svoj rezultat.
	
	
	
	## Ograničenja
	- $1 \leq N \leq 2\cdot 10^5$
	- $1 \leq A_i, B_i \leq 10^9$
	- Početni i krajnji trenuci svih zadataka su međusobno različiti
	- Nijedan zadatak neće početi u trenutku kada se neki zadatak završio
	
	
	
	## Podzadaci
	- (22 poena): $1 \leq N \leq 200$
	- (27 poena): $1 \leq N \leq 2000$
	- (29 poena): $1 \leq A_i, B_i \leq 5\cdot  10^5$
	- (22 poena): Nema dodatnih ograničenja.
	
	
	
	## Primer 1
	### Ulaz
	```
	3
	2 6
	1 4
	3 5
	```
	### Izlaz
	```
	6
	4
	6
	```
	### Objašnjenje
	
	Prvi i drugi zadatak ne moraju da čekaju da ostali zadaci završe sa izvršavanjem. Treći zadatak će sačekati da prvi zadatak završi sa izvršavanjem zato što je on započet pre njega.
	
	
	## Primer 2
	### Ulaz
	```
	3
	5 6
	3 4
	1 2
	```
	### Izlaz
	```
	6
	4
	2
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Igor Pavlović | Igor Pavlović | Vladimir Milovanović | Vladimir Milovanović |
	
	Najpre je neophodno uočiti da svaki zadatak iz postavke ima svoj redni broj (indeks) u redosledu zadataka, početak i kraj izvršavanja, te trenutak upisa rezultata u memoriju koji je potrebno odrediti. Stoga je korisno iskoristiti neku od struktura koja grupiše ove četiri karateristike svakog zadatka. Takođe, prema postavci, zadaci nisu sortirani ni prema početnom, a ni prema krajnjem trenutku svog izvršavanja.
	
	## Kvadratno rešenje
	
	Dovoljno je u dve ugnežđene petlje redosledom proći po svim zadacima i za svaki zadatak ispitati da li postoji neki drugi zadatak koji je počeo pre njega, a koji se završava nakon njega. Drugim rečima, u petljama za svaka dva zadatka $i$ i $j$ proveravati da li je $A_j < A_i$ i $B_j > B_i$ i simultano ažurirati traženo vreme upisa u memoriju na maksimalno $B_j$ od zadataka koji zadovoljavaju prethodni uslov. Najzad, po redosledu proći i ispisati vremena. Kako se u svakoj od dve petlje prolazi kroz sve zadatke, ovo rešenje ima kvadratnu vremensku složenost, odnosno $\mathcal{O}(N^2)$, gde $N$ predstavlja broj zadataka.
	
	## Glavno rešenje u loglinearnoj složenosti
	
	Da bi se problem rešio na efikasan način, mogu se zadaci umesto po indeksu sortirati po vremenu početka izvršavanja. Pošto u tako sortiranim zadacima nakon $i$-tog zadatka nema zadataka koji su počeli posle njega, to je dovoljno u samo jednom prolasku kroz zadatke, vodeći računa o dotadašnjem maksimumu, ažurirati vreme upisa u memoriju kao trenutnu vrednost maksimuma. Najzad, potrebno je pre ispisa zadatke ponovo sortirati po redosledu učitavanja, odnosno po indeksima, kako bi se u jednom prolasku ispisala tražena vremena. Kako je operaciju sortiranja efikasnim algoritmima moguće izvršiti u loglinearnoj vremenskoj složenosti $\mathcal{O}(N\log N)$, a kako je ovo vremenski najzahtevnija operacija u predloženom rešenju, to je i ukupna složenost ovog rešenja loglinearna po broju zadataka.
	
	``` cpp title="01_racunar.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxN 200005
	
	using namespace std;
	
	struct Task{
	
	Task(int a,int b, int i){
	    start = a;
	    end = b;
	    id = i;
	};
	
	int start, end, id, ans;
	};
	
	bool cmp_start(Task a,Task b){
	    return a.start < b.start;
	}
	
	bool cmp_id(Task a,Task b){
	    return a.id < b.id;
	}
	
	vector <Task> tasks;
	
	int main(){
	    int n;
	    cin >> n;
	    assert(n<=2e5);
	    
	    for(int i=0;i<n;i++){
	        int a, b;
	        cin>>a>>b;
	        assert(a<=1e9);
	        assert(b<=1e9);
	        tasks.push_back({a,b,i});
	    }
	    
	    sort(tasks.begin(),tasks.end(),cmp_start);
	    
	    int m=-1;
	    for(int i=0;i<n;i++){
	        m=max(m,tasks[i].end);
	        tasks[i].ans = m;
	    }
	    
	    sort(tasks.begin(),tasks.end(),cmp_id);
	    
	    for(int i=0;i<n;i++){
	        cout<<tasks[i].ans<<endl;
	    }
	    return 0;
	}
	```
