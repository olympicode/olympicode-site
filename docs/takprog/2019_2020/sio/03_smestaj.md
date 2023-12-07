---
hide:
  - toc
---

# 3 - Smeštaj

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 512MB |
	
	
	Postoji $N$ osoba i $M$ soba. Osobe mogu rezervisati sobe, ali ni u jednom trenutku neće dve osobe imati rezervisanu istu sobu, dok svaka osoba uvek ima najviše jednu rezervisanu sobu. Na početku niko nema ništa rezervisano. U nekim momentima se vrši simuliranje raspoređivanja po sobama, na osnovu trenutnih rezervacija, i to funkcioniše na sledeći način:
	
	* Za svaku osobu, redom od $1$ do $N$, se odlučuje koja će joj soba biti dodeljena, nakon čega je do kraja raspoređivanja ta soba zauzeta.
	* Ukoliko osoba $U$ nije rezervisala sobu, ona dobija sobu sa najmanjim indeksom koja nije ni zauzeta ni rezervisana.
	* Ukoliko je osoba $U$ rezervisala sobu, ona dobija sobu sa manjim indeksom između sobe koju je rezervisala i sobe sa najmanjim indeksom koja nije ni zauzeta ni rezervisana. Ukoliko $U$ nije dobila sobu koju je rezervisala, ta rezervacija prestaje da važi do kraja raspoređivanja i soba koju je $U$ bila rezervisala postaje slobodna.
	
	Dato je i $Q$ upita, svaki upit je jedan od sledeća dva tipa:
	
	* $1$ $U$ $X$. Osoba $U$ rezerviše sobu $X$. Ukoliko je $U$ pre toga imala neku drugu rezervaciju, ta rezervacija se poništava. Ukoliko je $X = 0$, tada se samo poništava rezervacija sobe osobe $U$. Garantuje se da za $X \neq 0$ nijedna osoba nema rezervisanu sobu $X$ u ovom trenutku. 
	
	* $2$ $U$. Simulira se raspoređivanje po sobama na opisani način. Treba odgovoriti na pitanje u kojoj sobi će završiti osoba $U$, **ukoliko bi se izvršila simulacija raspoređivanja u sobe po opisanom algoritmu, uzevši u obzir sve upite tipa $1$ do ovog upita, ali ne uzimajući u obzir prethodne upite tipa $2$**. Dakle, nakon ovog upita su ponovo sve sobe prazne i važe iste rezervacije koje su važile neposredno pre upita. Ukoliko ne postoji soba u koju osoba $U$ može da uđe, odgovor je $-1$.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Smestaj(N, M, Q, T[\dots], U[\dots], X[\dots], Ans[\ldots])$
	
	gde je $N$ broj osoba, $M$ broj soba, $Q$ broj upita, $T_i$ tipovi upita, $U_i$ osoba koja rezerviše sobu u upitu tipa $1$, odnosno osoba za koju treba naći odgovor u upitu tipa $2$, $X_i$ soba koju osoba $U_i$ rezerviše u upitu tipa $1$, i $Ans$ niz u koji treba upisati odgovore na upite tipa $2$. **Svi nizovi su indeksirani od $1$**. Niz $Ans$ je takođe indeksiran od $1$, odgovor na $i$-ti upit tipa $2$ treba da bude u $Ans_i$. Ako je $T_i = 2$, garantuje se da važi $X_i = 0$.
	
	## Primer
	
	Neka je $N=5$, $M=8$, $Q=7$ i neka su dati upiti:
	```
	2 2
	1 3 1
	2 2
	1 2 2
	2 2
	1 3 5
	2 3
	```
	Tada:
	
	-   U prvom upitu treba pronaći koju će sobu dobiti osoba $2$:
	-   Osoba $1$ dobija sobu, slobodne su $\{1,2,3,4,5,6,7,8\}$. Kako osoba $1$ nije rezervisala sobu, ona dobija sobu $1$.
	-   Osoba $2$ dobija sobu, slobodne su $\{2,3,4,5,6,7,8\}$. Kako osoba $2$ nije rezervisala sobu, ona dobija sobu $2$. Dakle, $Ans_1 = 2$.
	-   U drugom upitu osoba $3$ rezerviše sobu $1$.
	-   U trećem upitu treba pronaći koju će sobu dobiti osoba $2$:
	-   Osoba $1$ dobija sobu, slobodne su $\{2,3,4,5,6,7,8\}$. Kako osoba $1$ nije rezervisala sobu, ona dobija sobu $2$.
	-   Osoba $2$ dobija sobu, slobodne su $\{3,4,5,6,7,8\}$. Kako osoba $2$ nije rezervisala sobu, ona dobija sobu $3$. Dakle, $Ans_2 = 3$.
	-   U četvrtom upitu osoba $2$ rezerviše sobu $2$.
	-   U petom upitu treba pronaći koju će sobu dobiti osoba $2$:
	-   Osoba $1$ dobija sobu, slobodne su $\{3,4,5,6,7,8\}$. Kako osoba $1$ nije rezervisala sobu, ona dobija sobu $3$.
	-   Osoba $2$ dobija sobu, slobodne su $\{4,5,6,7,8\}$. Kako je osoba $2$ rezervisala sobu $2$, a soba koja je slobodna sa najmanjim indeksom je soba $4$, ona dobija sobu $2$. Dakle, $Ans_3 = 2$.
	-   U šestom upitu osoba $3$ rezerviše sobu $5$. Njena prethodna rezervacija sobe $1$ se poništava.
	-   U sedmom upitu treba pronaći koju će sobu dobiti osoba $3$:
	-   Osoba $1$ dobija sobu, slobodne su $\{1,3,4,6,7,8\}$. Kako osoba $1$ nije rezervisala sobu, ona dobija sobu $1$.
	-   Osoba $2$ dobija sobu, slobodne su $\{3,4,6,7,8\}$. Kako je osoba $2$ rezervisala sobu $2$, a soba koja je slobodna sa najmanjim indeksom je soba $3$, ona dobija sobu $2$.
	-   Osoba $3$ dobija sobu, slobodne su $\{3,4,6,7,8\}$. Kako je osoba $3$ rezervisala sobu $5$, a soba koja je slobodna sa najmanjim indeksom je soba $3$, ona dobija sobu $3$. Dakle, $Ans_4 = 3$.
	
	
	
	Dakle, za ovaj primer važi:
	
	-   $T = [2,1,2,1,2,1,2]$
	-   $U = [2,3,2,2,2,3,3]$
	-   $X = [0,1,0,2,0,5,0]$
	-   $Ans = [2,3,2,3]$
	
	## Ograničenja
	
	-   $1 \leq N,M,Q \leq 300.000$
	-   $N \leq M$
	-   $1 \leq U_i \leq N$
	-   $0 \leq X_i \leq M$
	-   **Garantuje se da ni u jednom trenutku dve osobe neće imati rezervisanu istu sobu.**
	
	## Podzadaci
	Test primeri su podeljeni u $7$ podzadatka:
	
	-   **[5 poena]:** $N,M,Q \leq 500$
	-   **[7 poena]:** $N,M \leq 1.000, Q \leq 20.000$
	-   **[6 poena]:** $N,M \leq 1.000, Q \leq 200.000$
	-   **[11 poena]:** $N,M,Q \leq 300.000, X_i \leq 30$ 
	-   **[14 poena]:** $N,M \leq 8.000, Q \leq 300.000$
	-   **[23 poena]:** $N,M \leq 100.000, Q \leq 100.000$
	-   **[34 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `smestaj.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Smestaj(int N, int M, int Q, int *T, int *U, int *X, int *Ans);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N, M, Q$,
	* U narednih $Q$ redova po jedan upit.
	
	Zatim ovaj program zove vašu funkciju i štampa odgovre koje vaša funkcija upiše u niz `Ans`.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Aleksa Milisavljević | Vladimir Milenkovic |
	
	
	## Podzadatak 1: $N,M, Q \leq 500$
	U ovom podzadatku dovoljno je simulirati rešenje, tako što ćemo u svakom upitu proći kroz svih $n$ osoba i za svaku osobu proveriti koja je slobodna soba sa najmanjim indeksom. Složenost: $O(NMQ)$.
	
	## Podzadatak 2: $N,M \leq 1.000, Q \leq 20.000$
	U ovom podzadatku možemo da radimo sličnu simulaciju, kao i u prethodnom, samo što ćemo u "std::set" ubaciti sve slobodne sobe i potom za svaku osobu izabrati ili njenu rezervaciju (ukoliko je ima i manja je od prvog elementa seta) ili najmanji element u setu. Ukoliko izaberemo element iz seta, izbacujemo ga, a ubacujemo rezervaciju (ukoliko je ima). Složenost: $O(QN \log M)$.
	
	## Podzadatak 3: $N,M \leq 1.000, Q \leq 200.000$
	U ovom podzadatku možemo da radimo sličnu simulaciju, ali tako što ćemo, umesto čuvanja skupa slobodnih soba, u svakom trenutku pamtiti pokazivač na poslednju slobodnu sobu. Složenost: $O(QN)$.
	
	## Koju sobu će izabrati osoba $X$?
	Lema: Prvih $X$ osoba će popuniti prvih $X$ nerezervisanih soba, ukoliko samo posmatramo sobe koje su rezervisale osobe posle osobe $X$.
	
	Ova lema se može lako pokazati indukcijom i razdvajanjem na slučajeve da li je osoba $X+1$ rezervisala sobu i gde se ta soba nalazi u odnosu na poslednju zauzetu sobu. Sada lako vidimo da će osoba $X$ da izabere ili $X$-tu slobodnu sobu, ukoliko posmatramo rezervacije soba posle osobe $X$ ili sobu koju je ona rezervisala (ako je ima). Odavde vidimo i da će za svaku osobu uvek biti bar jedna slobodna soba, tj. odgovor nikada neće biti $-1$.
	
	## Podzadatak 4:  $N,M,Q \leq 300.000, X_i \leq 30$
	U ovom podzadatku je dovoljno za svaku sobu zapamtiti koja osoba ju je rezervisala. Potom u upitu za $U_i \leq 30$ simuliramo odabir sobe kao u podzadatku 3, a za preostale proverimo koliko soba su rezervisale osobe sa indeksima većim od $U_i$. Složenost: $O(Q \max X_i)$.
	
	## Podzadatak 5:  $N,M \leq 8.000, Q \leq 300.000$
	Za ovaj podzadatak je potrebna struktura podataka 2d segmentno stablo u kojem pamtimo za interval osoba $[l,r]$ i interval soba $[x,y]$ koliko soba iz tog intervala nije rezervisala ni jedna osoba iz intervala $[l,r]$. Potom binarno pretražujemo po rešenju najmanje $t$, tako da u intervalu $[1,t]$ ima bar $U_i$ nerezervisanih soba, ukoliko posmatramo rezervacije osoba iz intervala $[U_i + 1, N]$. Složenost: $O(Q \log N \log^2 M)$.
	
	## Podzadatak 6:  $N,M \leq 100.000, Q \leq 100.000$
	U ovom podzadatku koristimo istu ideju kao i u prethodnom, ali zbog velikog broja osoba i soba, moramo da koristimo implicitno 2d segmentno stablo. Složenost: $O(Q \log N \log^2 M)$.
	
	## Podzadatak 7:  $N,M \leq 300.000, Q \leq 300.000$
	U ovom podzadatku optimizujemo ideju iz prethodnog zadatka. Naime, možemo da primetimo da nam je $\log$ od binarne pretrage višak i da možemo da se "šetamo" po implicitnom 2d segmentnom stablu. Ovo radimo tako što zapamtimo skup segmentnih stabala koja se odnose na osobe posle osobe $U_i$ i potom u se u njima šetamo tako što pronađemo sumu brojeva slobodnih soba u levom podstablu svakog. Ukoliko je ta suma veća ili jednaka sa $k = U_i$, onda idemo u to podstablo u svakom stablu iz skupa, u suprotnom idemo u desno i od $k$ oduzmemo sumu iz levih. Složenost: $O(Q \log N \log M)$.
	
	``` cpp title="03_smestaj.cpp" linenums="1"
	#include<bits/stdc++.h>
	#pragma GCC optimize("O3")
	#define maxn 600000
	using namespace std;
	struct Segment {
	    int cnt;
	    int child_left;
	    int child_right;
	};
	int reser[maxn];
	Segment arr[182*maxn];
	Segment emp;
	int al=0;
	int segs[30];
	inline void erase_reservation(int o,int p,int N,int M) {
	    int len=0;
	    while(o<=N) {
	        segs[len++]=o;
	        o+=(o&(-o));
	    }
	    int l=1,r=M;
	    while(l<r) {
	        int m=(l+r)>>1;
	        if(p<=m) {
	            for(int i=0;i<len;i++) {
	                arr[segs[i]].cnt--;
	                segs[i]=arr[segs[i]].child_left;
	            }
	            r=m;
	        }
	        else {
	            for(int i=0;i<len;i++) {
	                arr[segs[i]].cnt--;
	                segs[i]=arr[segs[i]].child_right;
	            }
	            l=m+1;
	        }
	    }
	    for(int i=0;i<len;i++) arr[segs[i]].cnt--;
	}
	inline void add_reservation(int o,int p,int N,int M) {
	    int len=0;
	    while(o<=N) {
	        segs[len++]=o;
	        o+=(o&(-o));
	    }
	    int l=1,r=M;
	    while(l<r) {
	        int m=(l+r)>>1;
	        if(p<=m) {
	            for(int i=0;i<len;i++) {
	                arr[segs[i]].cnt++;
	                if(arr[segs[i]].child_left==0) arr[segs[i]].child_left=al++;
	                segs[i]=arr[segs[i]].child_left;
	            }
	            r=m;
	        }
	        else {
	            for(int i=0;i<len;i++) {
	                arr[segs[i]].cnt++;
	                if(arr[segs[i]].child_right==0) arr[segs[i]].child_right=al++;
	                segs[i]=arr[segs[i]].child_right;
	            }
	            l=m+1;
	        }
	    }
	    for(int i=0;i<len;i++) arr[segs[i]].cnt++;
	}
	inline int traverse(int o,int x,int M,int c) {
	    int len=0;
	    while(o>0) {
	        segs[len++]=o;
	        o-=(o&(-o));
	    }
	    int l=1,r=M;
	    while(l<r) {
	        if(l>=c) return l;
	        int m=(l+r)>>1;
	        int cfree=m-l+1;
	        for(int i=0;i<len;i++) cfree-=arr[arr[segs[i]].child_left].cnt;
	        if(x<=cfree) {
	            r=m;
	            if(l==r) return l;
	            for(int i=0;i<len;i++) segs[i]=arr[segs[i]].child_left;
	        }
	        else {
	            l=m+1;
	            if(l==r) return l;
	            x-=cfree;
	            for(int i=0;i<len;i++) segs[i]=arr[segs[i]].child_right;
	        }
	    }
	    return l;
	}
	void Smestaj(int N,int M,int Q,int *T,int *U,int *X,int *Ans) {
	    al=N+1;
	    int l=1;
	    for(int i=1;i<=Q;i++) {
	        if(T[i]==1) {
	            int o=N+1-U[i];
	            if(reser[o]!=0) erase_reservation(o,reser[o],N,M);
	            reser[o]=X[i];
	            if(reser[o]!=0) add_reservation(o,reser[o],N,M);
	        }
	        else {
	            int o=N-U[i];
	            int vx=reser[o+1];
	            if(vx==0) vx=M+1;
	            Ans[l]=traverse(o,U[i],M,vx);
	            Ans[l]=min(Ans[l],vx);
	            l++;
	        }
	    }
	}

	```
