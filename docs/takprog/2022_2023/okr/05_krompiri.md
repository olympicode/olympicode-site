---
hide:
  - toc
---

# A2 - Krompiri

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 750ms | 64MB |
	
	Čuveni astro-botaničar Mateja Dejmon se još od 2017. godine uspešno bavi uzgojem krompira na Marsu zahvaljujući pomoći takmičara iz informatike.
	
	On je ove godine odlučio da napravi novu farmu krompira na Marsu i ponovo mu je potrebna vaša pomoć. Njemu je na raspolaganju plodno marsovsko zemljište dimenzija $N \times M$ koje je on izdelio na $N \cdot M$ jediničnih polja. Na svakom polju je moguće posaditi određen broj krompira, međutim, zbog posebnog sastava marsovskog zemljišta u redu $i$ ukupno ne sme biti manje od $a_i$ niti više od $b_i$ krompira (za svako $i = 1,2,\ldots,N$). Takođe, u koloni $j$ ukupno ne sme biti manje od $c_j$ niti više od $d_j$ krompira (za svako $j = 1,2,\ldots,M$).
	
	Pomozite Mateji da odredi raspored krompira koji će maksimizovati njegov prinos tj. pomozite mu da posadi što više krompira.
	
	## Ulaz
	U prvom redu standardnog ulaza nalaze se, redom, dva cela broja $N$ i $M$ - dimenzije zemljišta.
	
	U narednih $N$ redova nalaze se po dva cela broja $a_i$ i $b_i$ - ograničenja za $i$-ti red.
	
	U narednih $M$ redova nalaze se po dva cela broja $c_j$ i $d_j$ - ograničenja za $j$-tu kolonu.
	
	## Izlaz
	U prvom redu standardnog izlaza ispisati maksimalan broj krompira koji Mateja može da posadi.
	
	U drugom redu ispisati broj $K$ - broj polja na kojima treba posaditi krompire.
	
	U narednih $K$ redova ispisati po tri cela broja $x$, $y$ i $n$ ($1 \leq x \leq N$, $1 \leq y \leq M$, $n \geq 0$), redom, koji označavaju da na polju u preseku $x$-tog reda i $y$-te kolone treba posaditi $n$ krompira.
	
	Raspored krompira mora biti takav da poštuje sva ograničenja iz teksta zadatka. **Ukoliko ima više rešenja, ispisati bilo koje.**
	
	## Primer 1
	### Ulaz
	```
	2 2
	1 2
	1 1
	1 3
	0 0
	```
	
	### Izlaz
	```
	3
	2
	1 1 2
	2 1 1
	```
	
	## Primer 2
	
	<br>
	
	### Ulaz
	
	<br>
	
	```
	2 3
	2 2
	2 2
	1 2
	1 2
	1 2
	```
	
	<br>
	
	### Izlaz
	
	<br>
	
	```
	4
	4
	1 1 1
	1 3 1
	2 2 1
	2 3 1
	```
	
	<br>
	
	## Objašnjenje primera
	U tabeli ispod je prikazan jedan mogući raspored krompira koji zadovoljava ograničenja i maksimizuje prinos u **prvom primeru** (izrazi oblika $x-y$ u tabeli označavaju donju i gornju granicu za broj krompira u odgovarajućem redu/koloni).
	
	| | 1-3 |0-0|
	| ---        |    :----:   |          :---: |
	|**1-2**| 2 | 0 |
	|**1-1**| 1 | 0 |
	
	U tabeli ispod je prikazan jedan mogući raspored krompira koji zadovoljava ograničenja i maksimizuje prinos u **drugom primeru**:
	
	| | 1-2 |1-2| 1-2 |
	| ---   |    :----:   | :---: | :---:|
	|**2-2**| 1 | 0 | 1 |
	|**2-2**| 0 | 1 | 1 |
	  
	## Ograničenja
	
	- $1 \leq N, M \leq 50000$.
	- $0 \leq a_i \leq b_i \leq 10^9$.
	- $0 \leq c_i \leq d_i \leq 10^9$.
	- **Garantuje se da postoji raspored krompira koji zadovoljava sve uslove**.
	
	Test primeri su podeljeni u pet disjunktnih grupa:
	
	- U testovima vrednim $10$ poena: $N=M, a_i \leq c_i \leq b_i \leq d_i$.
	- U testovima vrednim $10$ poena: $a_i = b_i, c_i = d_i$.
	- U testovima vrednim $15$ poena: $a_i = b_i$.
	- U testovima vrednim $15$ poena: $N = 1$.
	- U testovima vrednim $30$ poena: $a_i = c_i = 0$.
	- U testovima vrednim $20$ poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Igor Pavlović | Igor Pavlović | Igor Pavlović | Nikola Pešić |
	
	## Rešenje kada $N=M, a_i \leq c_i \leq b_i \leq d_i$
	U ovom podzadatku je dovoljno duž dijagonale posaditi $b_i$ krompira.
	
	## Rešenje kada $a_i = b_i, c_i = d_i$
	Za rešavanje ovog podzadatka možemo primeniti tehniku dva pokazivača. Pokazivač $i$ iterira po redovima, a pokazivač $j$ iterira po kolonama.
	Ako je $b_i=0$ ili $d_i=0$ tada uvećamo $i$ to jest $j$ za 1. Ako je $b_i \neq 0$ i $d_j \neq 0$ posadi $min(b_i,d_j)$ krompira na polje $i, j$ i smanji $b_i$ i $d_j$ za $min(b_i,d_j)$.
	
	## Rešenje kada $a_i = b_i$
	Ovaj podzadatak možemo rešiti analogno prethodnom. U ovom podzadatku je potrebno iterirati po kolonama 2 puta. Prvi put postavljamo broj krompira u svakoj koloni na donju granicu, a drugi put na gornju i ažuriramo broj krompira u svakoj koloni. Kada završimo sa iteracijom po redovima tada prekidamo iteraciju po kolonama takođe. Nakon što smo odredili broj krompira u svakoj koloni možemo primeniti rešenje iz prethodnog podzadatka.
	
	## Rešenje kada $N = 1$
	U slučaju da važi $\sum_{i=1}^{M} d_i \leq b_1$ dovoljno je samo u $i$-toj koloni posaditi $d_i$ krompira.
	
	U suprotnom se rešenje ovog podzadatka svodi na rešenje prethodnog kada donju granicu postavimo da bude jednaka gornjoj (jer je neophodno posaditi $b_i$ krompira u prvom redu kako bismo maksimizovali prinos).
	
	## Rešenje kada $a_i = c_i = 0$
	Ovaj podzadatak možemo rešiti gramzivom metodom i tehnikom 2 pokazivača. Pokazivač $i$ iterira po redovima, a pokazivač $j$ iterira po kolonama.
	Ako je $b_i=0$ ili $d_i=0$ tada uvećamo $i$ to jest $j$ za 1. Ako je $b_i \neq 0$ i $d_j \neq 0$ posadi $min(b_i,d_j)$ krompira na polje $i, j$ i smanji $b_i$ i $d_j$ za $min(b_i,d_j)$. Primetimo da je ovo rešenje identično podzadatku 2 samo što je u ovom slučaju neophono završiti iteraciju po kolonama čim se završi iteracija po vrstama i obrnuto. U podzadatku 2 se ove dve iteracije zaršavaju istovremeno s obirom da rešenje mora postojati.
	
	## Glavno rešenje
	Primetimo prvo da nije moguće posaditi više od $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ krompira ukupno. Dakle ukoliko konstruišemo rešenje sa tačno $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ krompira onda smo takođe dostigli maksimalan mogući prinos.
	
	Bez umanjenja opštosti pretpostavimo da važi $\sum_{i=1}^{N} b_i \leq \sum_{j=1}^{M} d_i$. Da bismo maksimizovali prinos potrebno je u svakom redu posaditi $b_i$ krompira. Pošto nam je poznat broj krompira koji je potrebno posaditi u svakom redu sada se rešenje zadatka svodi na rešenje podzadatka 3. Primetimo takođe da ukuliko postoji neko rešenje tada važi $\sum_{j=1}^{M} c_i \leq \sum_{i=1}^{N} b_i$, odakle sledi da moguće konstruisati rešenje sa tačno $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ primenom algoritma iz podzadatka 3.
	
	``` cpp title="05_krompiri.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxN 50005
	
	using namespace std;
	
	int n,m,a[maxN],b[maxN],c[maxN],d[maxN],cnt[maxN],i,j;
	bool transposed = false;
	long long s1=0,s2=0,sl=0;
	
	vector<pair<pair<int,int>,int>> ans;
	
	int main() {
		std::ios_base::sync_with_stdio(false);
		
		cin>>n>>m;
		for(i=0;i<n;i++){
			cin>>a[i]>>b[i];
			s1+=b[i];
		}
		
		for(i=0;i<m;i++){
			cin>>c[i]>>d[i];
			s2+=d[i];
		}
		
		if(s2<s1){
			transposed=true;
			swap(s1,s2);
			swap(n,m);
			for(i=0;i<max(n,m);i++){
				swap(a[i],c[i]);
				swap(b[i],d[i]);
			}
		}
		
		cout<<s1<<endl;
		
		for(i=0;i<m;i++) sl+=c[i];
		
		long long dif = s1-sl;
		
		for(i=0;i<m;i++){
			cnt[i]=min((long long)d[i],c[i]+dif);
			dif-=cnt[i]-c[i];
		}
		
		i=j=0;
		
		while(i<n && j<m){
			if(b[i]==0){
				i++;
				continue;
			}
			if(cnt[j]==0){
				j++;
				continue;
			}
			int tmp = min(b[i],cnt[j]);
			ans.push_back({{i+1,j+1},tmp});
			b[i]-=tmp;
			cnt[j]-=tmp;
		}
		
		cout<<ans.size()<<endl;
		
		for(i=0;i<ans.size();i++){
			if(transposed) {
				swap(ans[i].first.first,ans[i].first.second);
			}
			cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
		}
		return 0;
	}
	```
