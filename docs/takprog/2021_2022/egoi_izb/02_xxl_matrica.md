---
hide:
  - toc
---

# 2 - XXL matrica

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	
	Poznato je da komisija sve svoje odluke donosi nakon razmatranja jedne velike magične matrice sa crnim i belim poljima. Nažalost, tokom jesenjeg čišćenja, komisija je ovu matricu negde sklonila i zagubila!
	
	Jedine informacije koje su preostale o matrici su broj belih polja kojima počinje svaka vrsta i broj belih polja kojima počinje svaka kolona (tj. indeks prvog crnog polja u svakoj vrsti i u svakoj koloni, ili dužina vrste/kolone ako u njima nema crnih polja). Komisija je ove podatke odvajkada koristila da bi odredila broj takmičara koje će pozvati na naredni krug takmičenja.
	
	Komisiju sada zanima koliko je matrica minimalno ili maksimalno mogla da sadrži crnih polja. Pored ostalih podataka, komisija Vam je dala i broj $t$, kojim Vam govori da li je važan minimalan broj crnih polja ili maksimalan broj crnih polja. Ukoliko je $t=0$, komisiju zanima minimalan broj crnih polja, a ukoliko je $t=1$, komisiju interesuje maksimalan broj crnih polja.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza, data su tri cela broja $N$, broj vrsta matrice, $M$, broj kolona matrice i $t$. U drugom redu, dato je $N$ celih brojeva, $i$-ti od njih predstavlja broj belih polja sa kojima počinje $i$-ta vrsta. U trećem redu, nalazi se $M$ celih brojeva, $i$-ti od njih predstavlja broj belih polja sa kojima počinje $i$-ta kolona.
	
	## Opis izlaza
	
	Potrebno je ispisati jedan ceo broj, minimalan broj crnih polja u matrici, ukoliko je $t=0$, odnosno maksimalan broj crnih polja u matrici, ukoliko je $t=1$.
	
	## Ograničenja
	
	* $1  \leq N \leq  10^5$.
	* $1  \leq M \leq  10^5$.
	* $0 \leq t \leq 1$.
	* Garantuje se da postoji barem jedna matrica koja ispunjava sva ograničenja zadata ulaznim podacima.
	
	## Podzadaci
	
	1. (6 poena) $N, M \leq  4$, $t=0$.
	2. (9 poena) $N, M \leq  4$, $t=1$.
	3. (12 poena) $N, M \leq  1000$, $t=0$.
	4. (18 poena) $N, M \leq  1000$, $t=1$.
	5. (22 poena) $t=0$.
	6. (33 poena) $t=1$.
	
	## Primer 1
	
	### Ulaz
	
	~~~
	
	5 5 0
	
	2 0 2 5 1
	
	1 4 0 2 2
	
	~~~
	
	### Izlaz
	
	~~~
	
	6
	
	~~~
	
	## Primer 2
	
	### Ulaz
	
	~~~
	
	5 5 1
	
	2 0 2 5 1
	
	1 4 0 2 2
	
	~~~
	
	### Izlaz
	
	~~~
	
	10
	
	~~~
	
	### Objašnjenje primera
	
	Ukoliko sa `x` označimo crna polja u matrici, a sa `o` bela, matrica koja ima minimalnih $6$ crnih polja i ispunjava ograničenja zadata ulaznim podacima je:
	
	`o o x o o`
	
	`x o o o o`
	
	`o o x x x`
	
	`o o o o o`
	
	`o x o o o`
	
	Matrica koja ima maksimalnih $10$ crnih polja i ispunjava ograničenja zadata ulaznim podacima je:
	
	`o o x o o`
	
	`x o x o o`
	
	`o o x x x`
	
	`o o o o o`
	
	`o x x x x`
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Savić | Aleksa Milisavljević | Dragan Urošević | Vladimir Milovanović |
	
	Neka je $N$ broj vrsta i neka je $M$ broj kolona. Pretpostavimo da su vrste numerisane brojevima od $0$ do $N-1$, a kolone brojevima od $0$ do $M-1$. 
	
	Primetimo da ne mora za svaki izbor ulaznih podataka postojati rešenje. Naime ako je $0\leqslant a_i < M$, onda to znači da se na polju sa koordinatama $(i,a_i)$ nalazi crno polje. Zbog toga broj belih polja kojima počinje kolona $a_i$ nije veći od $a_i$, pa je $b_{a_i} \leqslant i$. Odnosno, ako je $0\leqslant a_i < M$ i $b_{a_i} > i$ za neko $i$, onda ne postoji matrica koja zadovoljava uslove opisane nizovima $a$ i $b$. Slično, ako je $0\leqslant b_j < N$, onda je polje sa koordinatama $(b_j, j)$ crno, pa vrsta $b_j$ počinje sa ne više od $j$ belih polja i zbog toga je $a_{b_j} \leqslant j$. Dakle ako za neko $j$ ($0\leqslant j < M$) važi da je $0\leqslant b_j < N$ i $a_{b_j}>j$, onda ne postoji matrica koja zadovoljva uslove opisane nizovima $a$ i $b$.
	
	Pretpostavimo da postoji matrica opisana nizovima $a$ i $b$. Tada za svako $i$ za koje je $0\leqslant a_i < M$ važi da je polje sa koordinatama $(i,a_i)$ crno. Slično, ako za neko $j$ važi da je $0\leqslant b_j < N$, onda je polje sa koordinatama $(b_j,j)$ crno.  I to je minimalni skup crnih polja. Prema tome, broj crnih polja ćemo odrediti tako što izbrojimo koliko ima različitih polja u uniji skupova
	$$
	A=\{(i,a_i)|0\leqslant i < N, 0\leqslant a_i < M\}
	\quad \text{i} \quad
	B=\{(b_j,j)|0\leqslant j < M, 0\leqslant b_j < N\}.
	$$
	
	Pretpostavimo da postoji matrica koja zadovoljava uslove opisane nizovima $a$ i $b$. Tada mogu biti crna sva polja $(i,j)$ ($0\leqslant i < N$, $0\leqslant j < M$) koja zadovoljavaju i sledeća dva uslova:
	$$
	a_i \leqslant j < M
	\quad \text{i}\quad
	b_j \leqslant i < N.
	$$
	
	
	## Rešenje kad je $N,M \leq 4$
	U ovom slučaju se mogu ispitati sve matrice dimenzija $N\times M$ čija su polja bela ili crna (tj, za svaku od njih se može proveriti da li zadovoljava uslove opisane nizovima $a$ i $b$). Naime matrica ima $2^{N M} \leqslant 2^{16} = 65536$. Nakon toga se lako odredi broj crnih polja u matrici koja ima najmanji i/ili najveći broj crnih polja.
	
	## Rešenje kad je $N,M \leq 1.000$
	
	U ovom slučaju se za svako polje matrice određuje da li je crno, za varijantu kada treba da odredimo najmanji broj crnih polja i/ili za varijantu kada treba da odredimo najveći broj crnih polja. Za određivanje boje koristimo gore navedene uslove. Složenost ovog rešenja je $\Theta(NM)$.
	
	## Rešenje kad je $N, M \leq 100.000$
	
	Opišimo kako određujemo maksimalni broj crnih polja (opet ćemo pretpostaviti da postoji matrica koja zadovoljava uslove problema). Maksimalan broj crnih polja određujemo tako što određujemo maksimalan broj crnih polja u vrstama polazeći od nulte vrste i obrađujući ih redom. Ako trenutno obrađujemo vrstu sa rednim brojem $i$, onda mogu biti crna sva polja $(i,j)$ koja zadovoljavaju uslove $j\geqslant a_i$ i $b_j \leqslant i$. Jedan od načina da to uradimo je da definišemo pomoćni niz $c$ dužine $M$ čiji elementi na početku imaju vrednost $0$, a ako se trenutno obrađuje vrsta broj $i$, onda će vrednosti elemenata niza $c$ biti
	$$
	c_j = \begin{cases}
	1,\quad &\text{ako je }b_j\leqslant i\\
	0,\quad &\text{ako je }b_j > i.
	\end{cases}
	$$
	Tada će najveći broj crnih polja u vrsti broj $i$ biti
	$$
	c_{a_i} + c_{a_i+1} + c_{a_i+2} + \dotsb + c_{M-1}.
	$$
	Ove zbirove ćemo najefikasnije odrediti koristeći Fenvikovo stablo (Fenwick tree) ili segmentno stablo. Primetimo da se niz $c$ (potencijalno) menja pri obradi svake vrste, pa u skladu sa tim treba ažurirati i odgovarajuće stablo. Složenost ovog rešenja je $\Theta(N\log M)$.
	
	
	Minimalni broj crnih polja možemo odrediti tako što formiramo skup sastavljen od parova $(i,a_i)$ ($0\leqslant i < N$, $a_i < M$) i $(b_j,j)$ ($0\leqslant j < M$, $b_j < N$), a zatim izbrojimo koliko u tom skupu ima elemenata. 
	
	
	``` cpp title="02_xxl_matrica.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 100005
	using namespace std;
	int n,m,t;
	int a[maxn];
	int b[maxn];
	set<pair<int,int> > s;
	vector<int> ad[maxn];
	int bt[maxn];
	void upd(int i) {
	    while(i<=m) {
	        bt[i]++;
	        i+=(i&(-i));
	    }
	}
	int que(int i) {
	    int ret=0;
	    while(i>0) {
	        ret+=bt[i];
	        i-=(i&(-i));
	    }
	    return ret;
	}
	int main() {
	    scanf("%d %d %d",&n,&m,&t);
	    for(int i=0;i<n;i++) scanf("%d",&a[i]);
	    for(int i=0;i<m;i++) scanf("%d",&b[i]);
	    for(int i=0;i<n;i++) {
	        if(a[i]!=m) s.insert({i,a[i]});
	    }
	    for(int i=0;i<m;i++) {
	        if(b[i]!=n) s.insert({b[i],i});
	    }
	    long long mn=s.size();
	    for(int i=0;i<m;i++) {
	        ad[b[i]].push_back(i);
	    }
	    long long mx=0;
	    for(int i=0;i<n;i++) {
	        for(auto j:ad[i]) {
	            upd(m-j);
	        }
	        mx+=que(m-a[i]);
	    }
	    if(t==0) printf("%lld\n",mn);
	    if(t==1) printf("%lld\n",mx);
	    return 0;
	}

	```
