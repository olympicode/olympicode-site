---
hide:
  - toc
---

# 3 - Autobusi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 1024MB |
	
	Tajna Komisija ni ovog puta nije imala vremena da takmičare povede u obilazak Beograda. Međutim, opšte je poznato da Beograd ima kvalitetan javni gradski prevoz, i da je ovaj prevoz besplatan za sve takmičare koji na sebi imaju značku na kojoj piše SIO 2015. Da bi takmičar ostvario pravo na besplatan prevoz, dovoljno je da vozaču pokaže značku. Međutim, Komisija je zabrinuta za bezbednost takmičara, pa želi da za neke parove početne i krajnje stanice zna koliko različitih autobuskih linija postoji, tako da je moguće doći od te početne do te krajnje stanice.
	
	Svaka autobuska linija je opisana nizom stanica - moguće je ponavljanje stanica. Svaka stanica ima svoj identifikacioni broj koji je prirodan i manji ili jednak $W$. Za neku liniju i neki par stanica $x$,$y$ kažemo da je moguće $i$-tom linijom doći od $x$ do $y$ ako i samo ako se u nizu stanica za tu liniju stanica $x$ pojavljuje bar jednom pre nekog pojavljivanja stanice $y$.
	
	## Opisi funkcija
	Vašoj funkciji prosleđuje se $n$, broj autobuskih linija; duzine, niz koji opisuje dužinu svake linije tj. broj stanica, zatim niz $a$, koji je dobijen nadovezivanjem nizova stanica za sve autobuse; $q$, broj upita; dva niza $x$ i $y$ - u $i$-tom upitu početna stanica je $x[i]$, a krajnja $y[i]$, i dat vam je niz $resenja$ koji vaša funkcija treba da popuni: u $resenja[i]$ upisati odgovor na $i$-ti upit.
	
	Dodatno, označimo dužinu niza $a$ sa $m$. **Svi nizovi su indeksirani od nule.**
	
	## Primer
	Neka je broj autobuskih linija $n=3$, i neka su te linije opisane nizovima $[1,2,3,4]$,$[2,4]$,$[2,3,1,4]$. Onda je niz $duzine=[4,2,4]$, i niz $a=[1,2,3,4,2,4,2,3,1,4]$. Neka je broj upita $q=4$ i neka su upiti $(1,3)$,$(2,4)$,$(1,4)$,$(4,1)$. Onda je $x=[1,2,1,4]$ i $y=[3,4,4,1]$. Vaša funkcija treba niz $resenja$ da popuni sledećim vrednostima: $[1,3,2,0]$.
	
	Za upit $(1,3)$, rešenje je $1$ – jedina autobuska linija kod koje se stanica označena brojem $1$ pojavljuje pre stanice označene brojem $3$ je linija $[1,2,3,4]$.
	
	Za upit $(2,4)$, rešenje je $3$ – svakom linijom se može doći  od stanice $2$ do stanice $4$.
	
	Za upit $(1,4)$, rešenje je $2$ – drugom linijom je nemoguće doći od $1$ do $4$ a preostalim dvema jeste.
	
	Za upit $(4,1)$, rešenje je $0$ – nijednom linijom se ne može doći od $4$ do $1$.
	
	## Ograničenja
	* $1\leq n,q\leq 100000$
	* $W<100000$
	* $m\leq 100000$
	* $1\leq x[i],y[i]\leq W$
	* $x[i] \neq y[i]$
	
	## Podzadaci i bodovanje
	* PODZADATAK 1 [9 POENA]: $n,q,m\leq 1000$
	* PODZADATAK 2 [14 POENA]: $n\leq 10$
	* PODZADATAK 3 [16 POENA]: $W\leq 1000$
	* PODZADATAK 4 [26 POENA]: $n,q,m\leq 50000$
	* PODZADATAK 5 [35 POENA]: Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom autobusi.c, autobusi.cpp ili autobusi.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	```
	C/C++
	    void resi(int n, int *duzine, int *a, int q, int *x, int *y, int *resenja);
	Pascal
	    procedure resi(n : longint; var duzine, a : array of longint; q : longint; var x, y, resenja : array of longint);
	```
	
	Ukoliko radite u C/C++-u, potrebno je na početku fajla staviti `#include “grader.h”` a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti `Unit autobusi;` **(ovo je već dodato u fajlovima koji su vam obezbeđeni)**.
	
	## Testiranje i eksperimentisanje
	Na raspolaganju su vam templejt fajlovi koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni pomoćni programi () koji služe da lakše testirate kodove. Ovi programi učitavaju podatke sa standardnog ulaza, pozivaju vašu funkciju $resi$ i ispisuju niz rešenja na standardni izlaz. Kodove ovih programa možete menjati po potrebi. Format ulaza za programe je sledeći:
	
	U prvi red upisati broj autobuskih linija $n$. U drugi red upisati $n$ brojeva - dužine autobuskih linija. Za narednih $n$ redova, u $i$-ti upisati $duzine[i]$ brojeva, oznake stanica. U naredni red upisati $q$ - broj upita.  Za narednih $q$ redova, u $i$-ti upisati dva broja $x[i]$ i $y[i]$, identifikacione brojeve početne i krajnje stanice.
	
	Izgled ulaza za gore opisan primer je sledeći:
	
	```
	3
	4 2 4
	1 2 3 4
	2 4
	2 3 1 4
	4
	1 3
	2 4
	1 4
	4 1
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Aleksandar Višnjić | Dragan Urošević |
	
	## Prvi podzadatak:
	Svakim upitom prolazimo jednom kroz niz $A$. Napravićemo pomoćni *bool* niz $B$ koji nam služi da pamtimo prethodno posećene stanice u tom prolasku. $A$ se po definiciji deli na disjunktne segmente koji označavaju po jednu autobusku liniju, stoga kada prođemo kroz jedan takav segment potrebno je opet proći i markirati sve njegove stanice kao neposećene, pošto se svaki segment rešava zasebno. Kada naiđemo na $Y_i$, potrebno je samo proveriti da li je stanica $X_i$ već posećena. (Napomena: broj rešenja se povećava najviše jednom po segmentu/autobuskoj liniji) Vremenska složenost je $O(Q\cdot M+N+W)$, a memorijska $O(W)$.
	
	## Drugi podzadatak:
	Pravimo dve pomoćne matrice $L[i][j]$ i $R[i][j]$ koje, redom, označavaju prvo i poslednje pojavljivanje stanice $j$ u liniji $i$. Broj $-1$ označava da takva stanica ne postoji. Sada za svaki upit možemo jednostavno proveriti da li se $X_i$ nalazi pre $Y_i$ u svakoj od $N$ autobuskih linija. Vremenska složenost je $O(N\cdot W+N\cdot Q+M)$, a memorijska $O(N\cdot W)$.
	
	## Treći podzadatak:
	Izračunaćemo za svake dve stanice broj linija, pa ćemo odgovarati na upite u $O(1)$. Za efikasno računanje ćemo po svakoj liniji zasebno proći po svim parovima stanica u njoj i odrediti da li je moguće da se jedna nađe pre druge. (Računamo samo jednistvene stanice u liniji)
	
	Ovo radi u $O(len_i^2)$ vremenu po liniji $i$ koja ima $len_i\leq W$ stanica. Neka je $f(len_1,len_2,...,len_N)=\sum_{i=1}^N len_i^2$. Nije teško videti da važi $f(...,len_i+1,...,len_j-1,...)>f(...,len_i,...,len_j,..)$ ako je $len_i\geq len_j$ i $i\neq j$. (Ne mora da važi $i<j$ kao u primeru gore, bitno je samo da su različiti indeksi) Iz ovoga neposredno sledi $f(len_1,...,len_N)\leq f(W,...,W,0,...,0)$. U drugoj funkciji se $W$ pojavljuje ne više od $\frac{M+W}{W}$ puta, pa važi $f(W,...,W,0,...,0)\leq (M+W)\cdot W$ i to je naše gornje ograničenje za broj operacija.
	
	Vremenska složenost je $O(M\cdot W+W^2 + N+Q)$, a memorijska $O(W^2)$.
	
	## Četvrti podzadatak:
	Napravimo dva niza **mapa** $L$ i $R$ veličine $N$. U njima za svaku autobusku liniju i stanicu u njoj pamtimo njeno prvo i poslednje pojavljivanje u okviru date linije. Takođe, pravimo niz **skupova** $S$ veličine $W$. U njemu za svaku stanicu određujemo koje sve linije prolaze kroz nju. Na upite odgovaramo na sledeći način:
	
	Ako smo već odgovorili na upit $(X_i,Y_i)$, samo ćemo uzeti prethodno zapamćeno rešenje. (ovo je neophodno jer će računanje novih odgovora biti sporo, a bitno je garantovati da oni budu različiti) Za nov upit ćemo jednom proći kroz **manji** od skupova $S[X_i]$ ili $S[Y_i]$, i za svaku njegovu autobusku liniju odrediti da li se $X_i$ nalazi pre $Y_i$.
	
	Ovo na prvi pogled izgleda kao da radi u $O(Q\cdot N)$ vremenu sa malom konstantom. Dokazaćemo da to nije slučaj. Neka niz $s_i$ predstavlja koliko smo puta prošli kroz skup $S[i]$. Možemo nadalje pretpostaviti, bez umanjenja opštosti, da je dat niz skupova sortiran u nerastućem poretku po njihovim veličinama. Kako nikad ne pitamo dva ista skupa više od dvaput, i kako uvek pitamo **manji** od dva skupa, možemo zaključiti $s_i \leq2( i-1)$ za svako $1\leq i \leq W$. Ukupan broj operacija iznosi $\sum s_i\cdot S[i].size$ , a maksimum se upravo postiže za $s_i=2(i-1)$, $1\leq i \leq \sqrt{Q}$. (Otprilike, mora da važi $\sum s_i=Q$, a $2\cdot \sum_{i=1}^{\sqrt{Q}} (i-1)$ prevazilazi $Q$) Kada bismo mogli da menjamo veličine skupova iz niza $S$ prebacivanjem jednog elementa u drugi, povećao bi se ukupni broj operacija kada bi se povećao i skup sa više prolaska. (tj. većim brojem $s_i$) Ovim se na kraju dobija da najveći ukupan broj operacija nije veći nego u slučaju u kom važi $S[1].size=S[2].size=...=S[Q].size= \sqrt{N}$, zbog poretka veličina. Algoritam će izvršiti najviše $O(Q\sqrt{N})$ operacija.
	
	Ako koristimo **std::map** i **std::set**, ukupna vremenska složenost je 
	$O(Q\cdot \sqrt{N}\cdot logN +N+M+W )$ , a memorijska $O(N+M+W)$.
	
	## Glavno rešenje:
	Rešenje je isto kao i  u četvrtom podzadatku, samo ćemo umesto **std::set** i **std::map** koristiti **std::unordered_set** i **std::unordered_map**, čime se vremenska složenost poboljšava na $O(Q\cdot\sqrt{N}+N+M+W)$. Zadatak se takođe može rešiti i **offline** nešto brže tako što ćemo postojanje linije koja prolazi kroz neku stanicu odrediti naknadno, ali implementacija toga je malo teža. Sve u svemu, ukupna vremenska složenost je $O(Q\cdot\sqrt{N}+N+M+W)$, a memorijska $O(N+M+W)$.
	
	``` cpp title="03_autobusi.cpp" linenums="1"
	#include "autobusi.h"
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	using namespace std;
	
	#define KORISTI_HASH_VELIKI
	#define KORISTI_HASH_MALI
	#define MAXN 100005
	#define LIMIT 316
	#define MAXX 100000
	#define MAX_VELIKI 318
	
	//veliki
	
	#ifdef KORISTI_HASH_VELIKI
	
	namespace veliki{
	    int *pl[MAX_VELIKI],*pr[MAX_VELIKI];
	    int br;
	
	    inline void napravi(int n, int sizes[], int a[]){
	        int *poc = new int[n+1],i,j;
	        poc[0] = 0;
	        for (int i=1; i<=n; i++) poc[i] = sizes[i-1] + poc[i-1];
	        br=0;
	        for (i=0; i<n; i++) if (sizes[i]>LIMIT){
	            pl[br] = new int[MAXX];
	            pr[br] = new int[MAXX];
	            memset(pl[br],63,sizeof(int)*MAXX); //beskonacno
	            memset(pr[br],255,sizeof(int)*MAXX); //-1
	            for (j=poc[i];  j<poc[i+1]; j++) pr[br][a[j]] = j;
	            for (j=poc[i+1]-1;  j>=poc[i]; j--) pl[br][a[j]] = j;
	            br++;
	        }
	        delete []poc;
	    }
	
	    inline int izbroji(int a,int b){
	        int c=0;
	        for (int i=0; i<br; i++){
	            if (pl[i][a] < pr[i][b]) c++;
	        }
	        return c;
	    }
	}
	
	#endif
	#ifndef KORISTI_HASH_VELIKI
	
	namespace veliki{
	    struct par{
	        int br,idx;
	        inline bool operator<(const par& drugi)const{
	            return br<drugi.br || (br==drugi.br && idx < drugi.idx);
	        }
	    };
	
	    par *parovi[MAX_VELIKI];
	    int duz[MAX_VELIKI];
	    int br;
	
	    inline void napravi(int n, int sizes[], int a[]){
	        int *poc = new int[n+1],i,j;
	        poc[0] = 0;
	        for (int i=1; i<=n; i++) poc[i] = sizes[i-1] + poc[i-1];
	        br=0;
	        for (i=0; i<n; i++) if (sizes[i]>LIMIT){
	            parovi[br] = new par[sizes[i]];
	            duz[br] = sizes[i];
	            for (j=0; j<sizes[i]; j++){
	                parovi[br][j].br = a[poc[i]+j];
	                parovi[br][j].idx = j;
	            }
	            sort(parovi[br],parovi[br]+duz[br]);
	            br++;
	        }
	        delete []poc;
	    }
	
	    inline int binarna_levo(int x,int niz){
	        static int l,r,m,o;
	        l = 0;
	        r = duz[niz]-1;
	        o = -1;
	        while (l<=r){
	            m = (l+r)/2;
	            if (parovi[niz][m].br < x){
	                l = m+1;
	            } else
	            if (parovi[niz][m].br > x){
	                r = m-1;
	            } else {
	                r = m-1;
	                o = m;
	            }
	        }
	        if (o==-1) return 999999999;
	        return parovi[niz][o].idx;
	    }
	
	    inline int binarna_desno(int x,int niz){
	        static int l,r,m,o;
	        l = 0;
	        r = duz[niz]-1;
	        o = -1;
	        while (l<=r){
	            m = (l+r)/2;
	            if (parovi[niz][m].br < x){
	                l = m+1;
	            } else
	            if (parovi[niz][m].br > x){
	                r = m-1;
	            } else {
	                l = m+1;
	                o = m;
	            }
	        }
	        if (o==-1) return -1;
	        return parovi[niz][o].idx;
	    }
	
	    inline int izbroji(int a,int b){
	        int c=0;
	        for (int i=0; i<br; i++){
	            if (binarna_levo(a,i) < binarna_desno(b,i)) c++;
	        }
	        return c;
	    }
	}
	
	#endif
	
	//mali
	
	#ifdef KORISTI_HASH_MALI
	
	namespace mali{
	    struct hash_entry{
	        int a,b,c;
	    };
	    struct par{
	        int a,b;
	        inline par(int _a=0, int _b=0):a(_a),b(_b){}
	        inline par(hash_entry e):a(e.a),b(e.b){}
	        inline bool operator<(const par& drugi)const{
	            return a<drugi.a || (a==drugi.a && b < drugi.b);
	        }
	        inline bool operator==(const par& drugi)const{
	            return a==drugi.a && b==drugi.b;
	        }
	    };
	    const int hash_mod = 1<<25; // 33554432
	
	    hash_entry Tabela[hash_mod];
	
	    inline void ubaci(const par& e){
	        //hash funkcije
	        int prim = (e.a*6991ll + e.b*97213ll)&(hash_mod-1);
	        int sek  = (e.a*5407ll + e.b*65993ll)&(hash_mod-1);
	        while (1){
	            if (!Tabela[prim].a){
	                Tabela[prim].a = e.a;
	                Tabela[prim].b = e.b;
	                Tabela[prim].c = -1;
	                return;
	            }
	            if (e==Tabela[prim]){
	                if (Tabela[prim].c>0){
	                    Tabela[prim].c = -(Tabela[prim].c+1);
	                }
	                return;
	            }
	            prim = (prim+sek)&(hash_mod-1);
	        }
	    }
	
	    inline void ispravi(const par& e){
	        //hash funkcije
	        int prim = (e.a*6991ll + e.b*97213ll)&(hash_mod-1);
	        int sek  = (e.a*5407ll + e.b*65993ll)&(hash_mod-1);
	        while (1){
	            if (!Tabela[prim].a){
	                return;
	            }
	            if (e==Tabela[prim]){
	                if (Tabela[prim].c<0) Tabela[prim].c*=-1;
	                return;
	            }
	            prim = (prim+sek)&(hash_mod-1);
	        }
	    }
	
	    inline void napravi(int n, int sizes[], int a[]){
	        int *poc = new int[n+1],i;
	        poc[0] = 0;
	        for (i=1; i<=n; i++) poc[i] = sizes[i-1] + poc[i-1];
	        static par tmp[LIMIT*(LIMIT-1)/2];
	        for (i=0; i<n; i++) if (sizes[i]<=LIMIT){
	            int x,y,k=0;
	            for (x=poc[i]; x<poc[i+1]; x++){
	                for (y=x+1; y<poc[i+1]; y++) if (a[x] != a[y]){
	                    tmp[k].a = a[x];
	                    tmp[k++].b = a[y];
	                }
	            }
	            //ubacujemo neduplikate u hash tabelu
	            for (x=0; x<k; x++) ubaci(tmp[x]);
	            for (x=0; x<k; x++) ispravi(tmp[x]);
	        }
	
	        delete []poc;
	    }
	
	    inline int izbroji(int a,int b){
	        par e(a,b);
	        int prim = (e.a*6991ll + e.b*97213ll)&(hash_mod-1);
	        int sek  = (e.a*5407ll + e.b*65993ll)&(hash_mod-1);
	        while (1){
	            if (!Tabela[prim].a){
	                return 0;
	            }
	            if (e==Tabela[prim]){
	                return Tabela[prim].c;
	            }
	            prim = (prim+sek)&(hash_mod-1);
	        }
	    }
	}
	
	#endif
	#ifndef KORISTI_HASH_MALI
	
	namespace mali{
	    struct par{
	        int a,b;
	        inline par(int _a=0, int _b=0):a(_a),b(_b){}
	        inline bool operator<(const par& drugi)const{
	            return a<drugi.a || (a==drugi.a && b < drugi.b);
	        }
	        inline bool operator==(const par& drugi)const{
	            return a==drugi.a && b==drugi.b;
	        }
	    };
	    struct trojka{
	        int a,b,c;
	        inline trojka(){}
	        inline trojka(par e):a(e.a),b(e.b),c(1){}
	        inline bool operator<(const trojka& drugi)const{
	            return a<drugi.a || (a==drugi.a && b < drugi.b);
	        }
	    };
	
	    trojka Tabela[MAXN*LIMIT/2];
	    int br;
	
	    inline void ubaci(par e){
	        Tabela[br++] = trojka(e);
	    }
	
	    inline void napravi(int n, int sizes[], int a[]){
	        int *poc = new int[n+1],i,j;
	        poc[0] = 0;
	        for (i=1; i<=n; i++) poc[i] = sizes[i-1] + poc[i-1];
	        par *tmp = new par[LIMIT*(LIMIT-1)/2];
	        br=0;
	        for (i=0; i<n; i++) if (sizes[i]<=LIMIT){
	            int x,y,k;
	            k=0;
	            for (x=poc[i]; x<poc[i+1]; x++){
	                for (y=x+1; y<poc[i+1]; y++) if (a[x] != a[y]){
	                    tmp[k].a = a[x];
	                    tmp[k].b = a[y];
	                    k++;
	                }
	            }
	            //ubacujemo neduplikate u hash tabelu
	            if (k>0){
	                sort(tmp,tmp+k);
	                ubaci(tmp[0]);
	                for (x=1; x<k; x++) if (tmp[x-1] < tmp[x]) ubaci(tmp[x]);
	            }
	        }
	
	        sort(Tabela,Tabela+br);
	
	        j=1;
	        for (i=1; i<br; i++){
	            if (Tabela[i-1] < Tabela[i]){
	                Tabela[j] = Tabela[i];
	                Tabela[j++].c = 1;
	            } else {
	                Tabela[j-1].c++;
	            }
	        }
	        br=j;
	
	        delete []tmp;
	        delete []poc;
	    }
	
	    int izbroji(int a,int b){
	        trojka t(par(a,b));
	        static int l,r,m,o;
	        l=0;
	        r=br-1;
	        o=-1;
	        while (l<=r){
	            m = (l+r)/2;
	            if (Tabela[m] < t){
	                l = m+1;
	            } else
	            if (t < Tabela[m]){
	                r = m-1;
	            } else {
	                o = m;
	                break;
	            }
	        }
	        if (o==-1) return 0;
	        return Tabela[o].c;
	    }
	}
	
	#endif
	
	void resi(int n, int *duzine, int *a, int q, int *x, int *y, int *resenja){
	    veliki::napravi(n,duzine,a);
	    mali::napravi(n,duzine,a);
	    for (int i=0; i<q; i++){
	        resenja[i] = veliki::izbroji(x[i],y[i]) + mali::izbroji(x[i],y[i]);
	    }
	}

	```
