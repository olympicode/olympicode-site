---
hide:
  - toc
---

# A2 - Magija

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 100ms | 64MB |
	
	
	U srednjem veku se mnogo pričalo o zlim vešticama koje su koristile crnu magiju da naude ljudima. Znalo se da su one organizovane u hijerarhijsku strukturu, tj. svaka zla veštica, osim glavne veštice Baba Jaga, je imala tačno jednu nadređenu vešticu kojoj je morala da govori sve svoje zle planove pre izvršavanja. Isto tako, svaka veštica je znala koje su joj veštice podređene. Za razliku od toga što se mnogo znalo o zlim vešticama, mnogo manje se znalo o vešticama koje su koristile belu magiju da bi se borile protiv zlih veštica i sprečile ih u njihovoj nameri da naude ljudima. Najpoznatija veštica koja je koristila belu magiju je bila magična Sonja. Ona je bila jedina osoba koja je znala da izvede magiju koja oduzima svu moć zloj veštici, te je onesposobi u nameri da načini neku ozbiljnu štetu. Jedino ograničenje je bilo da Sonja može iskoristiti ovu čin samo na zlim vešticama koje nemaju nijednu podređenu vešticu, jer u suprotnom bi sve podređene veštice zajedno napale Sonju.
	
	U jednom trenutku su se sve zle veštice dogovorile da izvrše napade i svaka veštica je odredila kojeg dana će iskoristiti svoju najrazorniju čin. Sonjin zadatak je da onesposobi sve veštice u njihovoj nameri. Ona mora da iskoristi svoju specijalnu čin na svakoj veštici pre nego što ta veštica iskoristi svoju čin. Kao što je prethodno navedeno, Sonja može da iskoristi čin samo na vešticama koje nisu nikome nadređene. Kada onesposobi jednu vešticu, ta veštica se uklanja iz hijerarhijske strukture zlih veštica (te njena nadređena veštica ima za jednu manje podređenu vešticu). Svaka zla veštica ima svoj jedinstveni redni broj, a zna se da Baba Jaga ima redni broj 1. Sonja na početku zna izgled hijerarhijske strukture zlih veštica i za svaku vešticu zna kog dana će iskoristiti svoju najrazorniju čin. Sonjina moć je ograničena, te može da iskoristi svoju specijalnu čin samo jednom dnevno. Vaš zadatak je da pomognete Sonji i preporučite raspored kojim treba da napada veštice, tj. da joj za svaki dan kažete redni broj veštice na koju mora da baci svoju čin.
	
	
	## Opis ulaza
	U prvom redu standardnog ulaza se nalazi prirodan broj $N$. U drugom redu standardnog
	ulaza se nalazi $N$ brojeva gde $i$-ti broj, ti, predstavlja redni broj dana u kome će veštica sa rednim brojem i iskoristiti svoju razornu čin. U narednih $N − 1$ redova se nalazi po dva prirodna broja $p$ i $q$ ($1 ≤ p, q ≤ N$) koji označavaju da je veštica sa rednim brojevim $p$ nadređena veštici sa rednim brojem $q$.
	
	## Opis izlaza
	Ukoliko je moguće da Sonja onesposobi svaku vešticu pre nego što ta veštica upotrebi
	svoju čin, potrebno je u jednom redu ispisati $N$ brojeva gde $i$-ti broj predstavlja redni broj zle veštice koju Sonja treba da onesposobi $i$-tog dana (ukoliko postoji više takvih redosleda ispisati bilo koji). Ukoliko to nije moguće, ispisati poruku “Pobedila je crna magija”
	
	## Primer 1
	### Ulaz
	```
	5
	10 7 2 6 2
	4 2
	1 4
	4 5
	1 3
	```
	
	### Izlaz
	```
	5 3 2 4 1
	```
	
	## Primer 2
	### Ulaz
	```
	5
	10 7 9 2 8
	4 2
	1 4
	4 5
	1 3
	```
	
	### Izlaz
	```
	Pobedila je crna magija
	```
	## Objašnjenja primera
	U prvom test primeru prvog dana se onesposobi veštica sa rednim brojem 5, te drugog dana veštica sa rednim brojem 3. Primetimo da smo vešticu sa rednim brojem 3 onesposobili u poslednjem trenutku, jer da smo pokušali da je onesposobimo jedan dan kasnije ona bi već iskoristila čin. Posle veštice sa rednim brojem 3 redom smo onesposobili veštice sa rednim brojevima 2, 4 i 1 i nijedna od zlih veštica nije stigla da iskoristiti svoju čin. Primetimo da je i redosled 3, 5, 2, 4, 1 validno rešenje u ovom test primeru.
	
	U drugom test primeru ne možemo stići da onesposobimo vešticu sa rednim brojem 4 pre nego što ona iskoristi svoju čin.
	
	## Ograničenja
	
	* $1 ≤ n ≤ 10^5$
	* $1 ≤ t_i ≤ 10^9$
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u 4 podzadatka, u kojima važe sledeća dodatna
	ograničenja:
	
	* Podzadatak 1 [16 poena]: Svaka veštica ima najviše jednu direktno podređenu vešticu.
	* Podzadatak 2 [18 poena]: Veštica će uvek iskoristiti svoju čin tek nakon što njene
	podređene veštice iskoriste svoje čini i $n ≤ 1000$
	* Podzadatak 3 [31 poena]: $n$ je oblika $2 x − 1$ gde je $x$ prirodan broj. Svaka veštica ima ili dve ili nijednu direktno podređenu vešticu. Uzmimo bilo koju vešticu v i posmatrajmo niz $v = f_0, f_1, f_2, · · · , f_k$ gde je $f_i$ nadređena veštica od $f_{i−1}$ za sve $i ∈ 1, 2, · · · , k$. Bilo koji tako opisan niz neće biti duži od $log_2(n + 1)$. Drugim rečima, biće dato kompletno binarno balansirano stablo, tj. svi čvorovi na nivoima manjim od $x$ će imati tačno dva sina, a čvorovi na poslednjem nivou nemaju nijednog sina.
	* Podzadatak 4 [35 poena]: Nema dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nemanja Škorić | Demjan Grubić | Aleksandar Višnjić | Nikola Jovanović |
	
	## Prvi podzadatak:
	U ovom podzadatku data hijerarhija predstavlja vertikalni lanac čiji je čvor $1$ na vrhu. Jedina dozvoljena operacija koju mi smemo da izvršimo jeste brisanje čvora sa dna. Svaki čvor ima rok do kog moramo da ga obrišemo. Ovaj proces je moguće simulirati jednim prolaskom kroz lanac jer postoji samo jedna moguća opcija za brisanje po danu. Potrebno je  proveriti za svaki čvor da li smo ga obrisali pre isteka njegovog roka. Vremenska složenost je $O(N)$.
	
	## Drugi podzadatak:
	Koristićemo pohlepan algoritam. Data hijerarhija je stablo i smemo da brišemo njegove listove. U svakom trenutku ćemo obrisati bilo koji list koji ima najskoriji rok.  
	To možemo učiniti u $O(N)$ tako što prolazimo po svim čvorovima i tražimo minimalan list. Kako ima $N$ brisanja, ukupna vremenska složenost je $O(N^2)$.
	
	## Treći podzadatak:
	Istim postupkom brišemo čvorove, ali potrebno je efikasnije naći minimalan list i garantovati uslov da deca imaju raniji rok od roditelja. Uslov možemo ispuniti tako što ćemo za svaki čvor sa rokom $T$ postaviti rok $T-1$ na svako njegovo dete koje trenutno ima veći rok. Ako je moguće obrisati roditelja na vreme, onda se moraju ispuniti i dati rokovi za njegovu decu. Ovo se efikasno implementira jednim $DFS$ prolaskom kroz stablo, počev od čvora $1$. (korena stabla) 
	
	Minimalni list tražimo na sledeći način: u svakom čvoru binarnog stabla jednostavno pamtimo indeks minimalnog koji je u njegovom podstablu. (Biće minimum od 2 njegova deteta, ili sam taj čvor ako nema decu) Kada obrišemo list, potrebno je za sve njegove pretke (kojih ima $O(logN)$ ) postaviti novu adekvatnu vrednost. Ukupna vremenska složenost je $O(NlogN)$ .
	
	## Glavno rešenje:
	
	Opet ćemo garantovati uslov za rok, ali nam treba nov način za traženje minimalnog lista. Ovaj put ćemo jednostavno stavljati sve listove u *min heap* strukturu (odnosno ***priority_queue*** u koji stavljamo parove, prvi član para je rok čvora i onaj po kome poredimo parove, a drugi član je indeks čvora). Kada brišemo čvor jednostavno brišemo element na vrhu u  *min heap*. Ukoliko nastane novi list brisanjem čvora, dodajemo ga u *min heap*. Vremenska složenost je $O(NlogN)$ .
	
	``` cpp title="05_magija.cpp" linenums="1"
	#include <iostream>
	#include <cstring>
	#include <vector>
	#include <stdio.h>
	#include <algorithm>
	using namespace std;
	
	#define MaxN 100010
	
	struct Vestica {
		int t;
		int id;
	
		Vestica() {}
		Vestica(int _t, int _id) {
			t = _t;
			id = _id;
		}
	
		bool operator < (const Vestica &other) const {
			if (t != other.t) return t < other.t;
			return id < other.id;
		}
	};
	
	int n;
	Vestica a[MaxN];
	Vestica b[MaxN];
	vector<int> edge[MaxN];
	bool deleted[MaxN];
	vector<int> output;
	int currTime;
	
	bool DFS(int node) {
		if (deleted[node]) return true;
		
		for (int i = 0; i < edge[node].size(); ++i) {
			int v = edge[node][i];
	
			if (!DFS(v)) return false;
		}
	
		if (currTime > a[node].t) return false;
	
		currTime++;
		deleted[node] = true;
		output.push_back(node);
	
		return true;
	}
	
	int main()
	{
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&a[i].t);
			a[i].id = i;
			b[i] = a[i];
		}
	
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d %d",&u,&v);
	
			u--; v--;
			edge[u].push_back(v);
		}
	
		sort(b, b+n);
		memset(deleted, 0, sizeof(deleted));
		output.clear();
		
		currTime = 1;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			ok &= DFS(b[i].id);
		}
	
		if (output.size() == n) {
			for (int i = 0; i < output.size(); ++i) {
				printf("%d ",output[i]+1);
			}
			printf("\n");
		}
		else {
			printf("Pobedila je crna magija\n");
		}
	
		return 0;
	}
	```
