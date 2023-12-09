---
hide:
  - toc
---

# 3 - Zagrade

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Arsenije sa svoje terase ima prelep pogled na more. Međutim, trenutno postoje planovi za izgradnju koji nastoje da mu zagrade taj pogled. On je odlučio da se žali kome već treba i dobio je odgovor da jedini način da razmotre njegovu žalbu je da reši tajni zadatak koji će mu poslati u bliskoj budućnosti.
	
	Kroz par dana je Arsenije u pošti dobio niz od $N$ zagrada, sa porukom "znaš šta ti je činiti". Zaista, Arsenije je znao šta mora da uradi. On jednom potezu može da premesti zagradu sa početka niza na kraj niza, i potrebno je da nađe najmanji broj poteza tako da dobijeni niz zagrada bude **validan**. Podsetnik, za niz zagrada kažemo da je validan ako je moguće umetnuti neki broj znakova $0$ i $+$ tako da se dobije validan matematički izraz. 
	
	Međutim, u narednih $Q$ dana mu stiže po jedna zapovest: "promeni zagradu na poziciji $i$ (ako je otvorena, promeni u zatvorenu i obrnuto)". Arsenije vrši ove promene **nezavisno** od operacija koje je vršio prethodnih dana, to jest on menja svoj originalni niz zagrada. Vaš zadatak u ovih $Q+1$ dana je da pomognete Arseniju da reši ovaj problem.
	## Opis ulaza
	U prvoj liniji standardnog ulaza se nalaze dva broja $N$ i $Q$ iz teksta zadatka. U narednoj liniji se nalazi niska zagrada dužine $N$. U narednih $Q$ linija se nalazi po jedan broj koji označava indeks zagrade koje Arsenije treba da promeni.
	## Opis izlaza
	Potrbeno je ispisati $Q+1$ brojeva, svaki u zasebnoj liniji; u prvoj liniji treba ispisati rešenje Arsenijevog problema pre svih promena, a u $i$-toj liniji od narednih linija treba ispisati rešenje Arsenijevog problema posle $i$-te promene. Ako rešenje ne postoji, ispisati $-1$. **Niz zagrada je indeksiran od 1.**
	## Ograničenja
	-  $1\leq N,Q \leq 300.000$
	-  $N$ je parno 
	-  Svaka promena je određena brojem između $1$ i $N$.
	
	## Podzadaci
	-   (17 poena): $N,Q\leq500$
	-   (23 poena): $N,Q\leq5000$
	-   (21 poena): Sve promene menjaju zatvorene zagrade  u otvorene
	-   (39 poena): Bez dodatnih ograničenja
	## Primer 1
	
	### Ulaz
	
	```
	2 2
	()
	1
	2
	```
	
	### Izlaz
	
	```
	0
	-1
	1
	
	```
	### Objašnjenje
	Početni niz je validan jer je $(0)$ validan matematički izraz, pa je prvi broj ispisa $0$. Posle prve  promene niz postaje $))$, što nikad ne može postati validno. Posle druge promene, dobijamo niz $)($, a posle jednog poteza, niz postaje $()$, što je već prokomentarisano da je validno.
	## Primer 2
	
	### Ulaz
	
	```
	4 4
	))((
	1
	2
	3
	4
	```
	
	### Izlaz
	
	```
	2
	-1
	-1
	-1
	0
	```
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Mladen Puzić | Aleksa Milisavljević |
	
	## Rešenje kada $N, Q \leq 500$
	
	Nakon svake promene, prebacujmo jednu po jednu zagradu sa početka na kraj, dok ne naiđemo na prvi put kada imamo validan niz zagrada. Rešenje je broj prebačenih zagrada. Proveravamo da li je niz zagrada validan tako što idemo sleva nadesno i održavamo broj neuparenih otvorenih zagrada. Ukoliko naiđemo na otvorenu zagradu, povećavamo taj broj. Ukoliko naiđemo na zatvorenu zagradu, a broj neuparenih otvorenih zagrada je veći od $0$, onda uparujemo jednu otvorenu zagradu sa tom zatvorenom zagradom, pa smanjujemo taj broj. Ukoliko nemamo neuparenih otvorenih zagrada, a naiđemo na zatvorenu zagradu, niz zagrada nije validan. On takođe nije validan ako završimo proces sa neuparenim otvorenim zagradama. Vremenska složenost je $O(QN^2)$, a memorijska $O(N)$.
	
	## Rešenje kada $N, Q \leq 5000$
	
	U ovom podzadatku ćemo primeniti svaku promenu i pokušati da nađemo rešenje u $O(N)$. Posmatrajmo sledeći niz:
	
	$$
	p_0 = 0
	$$
	
	$$
	p_i = 
	\begin{cases}
	p_{i − 1} + 1, i\text{-ta zagrada je otvorena} \\
	p_{i − 1} − 1, i\text{-ta zagrada je zatvorena}
	\end{cases}
	$$
	
	Primetimo da je uslov da niz zagrada bude validan da važi $p_i \leq 0$ za svako $1\leq i \leq N$ i $p_N = 0$ (ovo je ekvivalentno tome da nijedan prefiks nema više zatvorenih nego otvorenih zagrada i da ukupno imamo jednako otvorenih i zatvorenih zagrada).
	
	Posmatrajmo sad šta se desi kada prvih $i$ zagrada prebacimo na kraj. Možemo primetiti da će se prvih $i$ elemenata niza $p_i$ prebaciti na kraj i onda će se ceo niz povećati za $−p_i$. Pošto želimo da svi elementi budu veći ili jednaki $0$, onda moramo da ga povećamo za što više, što znači da ćemo uzeti što manje $p_i$. Dakle, rešenje je $i$ za koje je $p_i$ najmanje. Ukoliko ima izjednačenja, onda uzimamo najmanje takvo $i$. Nakon svake promene samo ponovo izračunamo niz $p_i$. Vremenska složenost je $O(QN)$, a memorijska $O(N)$.
	
	## Rešenje kada sve promene menjaju zatvorene zagrade u otvorene
	
	Primetimo da, kako bi niz zagrada bio validan, moramo imati jednak broj otvorenih i zatvorenih zagrada. Recimo da na početku imamo $l$ otvorenih, a $r$ zatvorenih zagrada. Ukoliko $r < l$ onda očigledno nikad ne možemo dobiti validan niz zagrada. U suprotnom, moći ćemo da imamo validan niz zagrada samo nakon što $\frac{r−l}{2}$ zatvorenih zagrada pretvorimo u otvorene. Ukoliko $\frac{r−l}{2} > Q$, onda opet nikad nećemo imati rešenje. U suprotnom, dovoljno je da primenimo rešenje iz prethodnog podzadatka nakon $\frac{r−l}{2}$ promena (svi ostali rezultati su $−1$). Vremenska složenost je $O(N+Q)$, a memorijska $O(N)$.
	
	## Glavno rešenje
	
	Ovaj podzadatak se radi slično kao drugi podzadatak, samo zbog efikasne promene niza $p_i$ potrebno je da održavamo segmentno stablo sa lenjom propagacijom nad njim. Promena koja je potrebna je dodavanje $+1$ ili $−1$ na neki sufiks, i nalaženje minimuma celog niza. Da bismo uzeli najlevlji minimum celog niza, segmentno stablo gradimo nad nizom parova $\{p_i, i\}$, pa ćemo upitom minimuma dobiti onaj par sa najmanjim $p_i$, a najmanjim indeksom u slučaju izjednačenja. Vremenska složenost je $O(Q\log N)$, a memorijska $O(N)$.
	
	``` cpp title="03_zagrade.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 300007
	using namespace std;
	string s;
	pair<int,int> seg[4*MAXN];
	int bag[4*MAXN],cnt=0;
	void relax(int ind)
	{
	    bag[2*ind]+=bag[ind];
	    bag[2*ind+1]+=bag[ind];
	    seg[ind]=min(make_pair(seg[2*ind].first+bag[2*ind],seg[2*ind].second),make_pair(seg[2*ind+1].first+bag[2*ind+1],seg[2*ind+1].second));
	    bag[ind]=0;
	}
	void upd(int val,int l,int r,int lt,int rt,int ind)
	{
	    if(l>rt || r<lt) return;
	    if(l>=lt && r<=rt) {bag[ind]+=val; return;}
	    relax(ind);
	    int s=(l+r)/2;
	    upd(val,l,s,lt,rt,2*ind);
	    upd(val,s+1,r,lt,rt,2*ind+1);
	    seg[ind]=min(make_pair(seg[2*ind].first+bag[2*ind],seg[2*ind].second),make_pair(seg[2*ind+1].first+bag[2*ind+1],seg[2*ind+1].second));
	}
	void make(int l,int r,int ind)
	{
	    if(l==r) {seg[ind].second=l; return;}
	    int s=(l+r)/2;
	    make(l,s,2*ind);
	    make(s+1,r,2*ind+1);
	}
	int main()
	{
	    ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	    int n,q;
	    string s;
	    cin>>n>>q;
	    cin>>s;
	    make(0,n,1);
	    for(int i=0;i<n;i++) {upd(((s[i]=='(')?1:-1),0,n,i+1,n,1); cnt+=((s[i]=='(')?1:-1);}
	    if(cnt!=0) printf("-1\n");
	    else printf("%d\n",seg[1].second);
	    while(q--)
	    {
	        int t;
	        cin>>t; t--;
	        upd(((s[t]=='(')?-2:2),0,n,t+1,n,1); cnt+=((s[t]=='(')?-2:2);
	        s[t]^=1;
	        if(cnt!=0) printf("-1\n");
	        else printf("%d\n",seg[1].second);
	    }
	}

	```
