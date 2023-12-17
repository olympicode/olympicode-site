---
hide:
  - toc
---

# A3 - Kontra-žmurke

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Članovi Tajne komisije u senci su prilično besposleni ovih dana pa u obližnjem parku igraju kontra-žmurke. Kontra-žmurke su potezna dečja igra u kojoj se jedan igrač krije dok ga jedan ili više igrača, koje nazivamo tragačima, traži.
	
	Park je pravougaonih dimenzija i podeljen je na jedinične kvadrate. Svako kvadratno polje predstavlja ili prohodni žbun ili neprohodno drvo. Za svakog tragača je poznata njegova početna pozicija kao i brzina koja predstavlja koliko polja može preći u jednom potezu. Sa trenutnog polja tragač može preći samo na neko od četiri susedna polja. Dva polja su susedna ukoliko imaju zajedničku stranicu. Svi tragači u isto vreme kreću sa potragom.
	
	Red je na malog Zokija da se sakrije. On želi da bude što bolji u ovoj igri pa želi da se sakrije u žbunu na polju čija je **skrivenost** najveća moguća. **Skrivenost** nekog polja je celobrojna vrednost koja predstavlja **u koliko najmanje poteza neki od tragača može stići do tog polja krećući se najkraćim putem**. Pomozite Zokiju da pronađe polje sa najvećom skrivenošću jer su tragači već počeli sa odbrojavanjem.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se dva prirodna broja $N$ i $M$, koji predstavljaju dimenzije parka. Svaki od narednih $N$ redova sadrži niz od $M$ cifara iz skupa $\{0, 1\}$ bez razmaka – izgled parka. $0$ označava da se na odgovarajućem mestu nalazi žbun, a $1$ drvo. Zatim sledi broj tragača $K$ i u narednih $K$ redova koordinate početne pozicije $X_i$ i $Y_i$ (redni broj reda i kolone) i brzina $V_i$ za svakog od njih. Redovi su numerisani od $1$ do $N$ odozgo nadole a kolone od $1$ do $M$ sleva nadesno.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati dva broja $i$ i $j$ – redni broj reda i kolone polja na kojem se Zoki treba sakriti u skladu sa svojim zahtevom. Ukoliko postoji više rešenja ispisati bilo koje.
	
	## Primer 1
	### Ulaz
	```
	5 7
	0010000
	0100000
	0000110
	0000000
	0000000
	2
	1 2 3
	4 4 1
	```
	
	### Izlaz
	```
	2 6
	```
	
	## Objašnjenje primera
	```
	Slika 1   Slika 2   Slika 3
	10X3344   67X3456   10X3344
	1X23334   5X32345   1X22334
	1222XX4   4321XX4   1221XX4
	2223334   3210123   2210123
	2233344   4321234   2221234
	```
	
	Na datim slikama neprohodna polja označena su X-om. Slike 1 i 2 predstavljaju koliko najmanje poteza je potrebno prvom i drugom tragaču da dođu do odgovarajućih polja u parku, tim redom. Na slici 3 vidimo **skrivenost** svakog polja. Primetimo da je najveća **skrivenost** nekog polja jednaka 4 i da ukupno takvih polja ima 5. Bilo koje od tih polja je rešenje.
	
	## Ograničenja
	* $1\leq N,M \leq 1,000$
	* $1\leq K\leq 1,000,000$
	* $1\leq V_i\leq 10^9$
	* U parku će biti prohodnog puta od svakog do svakog žbuna.
	* Nikoja dva tragača neće imati iste koordinate.
	* Početne pozicije tragača će biti na polju sa žbunom.
	
	## Napomena
	Test primeri su podeljeni u 4 disjuntkne grupe:
	
	* U test primerima vrednim 20 poena važi da su brzine svih tragača jednake.
	* U test primerima vrednim 20 poena važi $1\leq N,M\leq 400$, $1\leq V_i\leq 400$.
	* U test primerima vrednim 20 poena važi $1\leq K\leq 1,000$ i sva polja su prohodna.
	* U test primerima vrednim 40 poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Dimić | Dimitrije Dimić | Aleksandar Višnjić | Ivan Stošić |
	
	## Prvi podzadatak:
	Dat je lavirint predstavljen matricom. Skrivenost polja u ovom podzadatku jednaka je udaljenosti od najbližeg tragača. Te udaljenosti tražimo primenom pretrage u širinu. Potrebno je postaviti više izvora - u svakom tragaču. Složenost je $O(NM)$.
	
	## Drugi podzadatak:
	U ovom podzadatku moguće je implementirati odvojeni algoritam pretrage u širinu za svakog tragača nezavisno. Napomenimo da tragače koji imaju istu brzinu smatarmo istim - slično kao i ranije, za svakog takvog postavljamo više izvora. Simuliramo svaki trenutak vremena, i u njemu za svakog tragača odredimo najveću "dubinu" do koje može stići. Te dubine ažuriramo standardno u algoritmu pretrage. Potrebno je pronaći poslednji trenutak u kome postoji slobodno polje. On je brojno jednak skrivenosti. Direktna implementacija navedenog daje rešenje složenosti $O(NMV)$, gde $V$ predstavlja najveću brzinu nekog tragača.
	
	## Treći podzadatak:
	Koristimo prethodnu ideju za posmatranje trenutaka. Primetimo da ako u nekom trenutku $T$ postoji skriveno polje, onda postoji i u trenutku $T-1$. Dok ako u trenutku $T$ ne postoji, onda ne postoji ni u $T+1$. Odavde zaključujemo da su trenuci binarno pretraživi, tj. koristićemo binarnu pretragu po vrednosti rešenja. Tačnije, ako je skrivenost $S$ moguća, za svakog tragača $i$ znamo da pokriva sva polja na udaljenosti $S\cdot V_i$ i da nakon toga ostaje bar jedno slobodno polje (i njega je potrebno ispisati za najveću skrivenost). Ako ne ostaje slobodno polje, tražena skrivenost nije moguća.  Proveru da li ono postoji radimo pretragom u širini, ali ne preko reda nego preko niza vektora: za svaku "dubinu" pamtimo sva polja koja se nalaze na njoj. Susedna polja koja nisu posećena u sledećem koraku imaju dubinu za jednu manju od trenutne. Najmanja moguća dubina posećenog polja je $0$. Izvori imaju koordinate $(X_i,Y_i)$ i dubinu $S\cdot V_i$. 
	
	Složenost ovog rešenja je $O((NM+K)\log (NM)$.
	
	## Glavno rešenje:
	Rešenje se suštinski ne razlikuje od prethodnog. Potrebno je uračunati blokirana polja, i eventualno optimizovati rešenje. Složenost je $O((NM+K)\log (NM)$.
	
	``` cpp title="06_kontra_zmurke.cpp" linenums="1"
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	#define DEBUG (false)
	using namespace std;
	
	struct tragac{
	    int x,y,v;
	    inline friend bool operator <(tragac a,tragac b){
	        return a.v < b.v;
	    }
	};
	
	int N,M,K;
	tragac T[1000005];
	char A[1005][1005];
	
	void ucitaj_matricu(){
	    int i;
	    scanf("%d%d",&N,&M);
	    for (i=1; i<=N; i++){
	        scanf("%s",A[i]+1);
	    }
	}
	
	void ucitaj_tragace(){
	    scanf("%d",&K);
	    int i;
	    for (i=1; i<=K; i++){
	        scanf("%d%d%d",&T[i].x,&T[i].y,&T[i].v);
	    }
	    sort(T+1,T+K+1);
	}
	
	int D[1005][1005];
	
	int Qx[2000005],Qy[2000005],qs,qe; //mozda treba veci queue
	int K2;
	
	void citaj_red(int &x,int &y){
	    //T[0].x tj. y je inic. na 0, ok
	    if (K2==0 || D[Qx[qs]][Qy[qs]] > D[T[K2].x][T[K2].y] && qs<=qe){
	        x = Qx[qs];
	        y = Qy[qs++];
	    } else {
	        x = T[K2].x;
	        y = T[K2--].y;
	    }
	    if (DEBUG) printf("dequeue %d %d %d\n",x,y,D[x][y]);
	}
	
	void upisi_red(int x,int y,int d){
	    if (D[x][y]==-1) return;
	    if (d <= D[x][y]) return;
	    D[x][y] = d;
	    if (DEBUG) printf("enqueue %d %d %d\n",x,y,d);
	    Qx[++qe] = x;
	    Qy[qe] = y;
	}
	
	void bfs_debug(){
	    int i,j;
	    puts("----------------------");
	    for (i=1; i<=N; i++){
	        for (j=1; j<=M; j++){
	            printf("%3d ",D[i][j]);
	        }
	        puts("");
	    }
	}
	
	void bfs(int mult,int &x0,int &y0){
	    int i,j,k,x,y,d;
	    x0=y0=-1;
	    memset(D,255,sizeof(D)); //postavi -1
	    for (i=1; i<=N; i++){
	        for (j=1; j<=M; j++){
	            if (A[i][j]=='0') D[i][j] = 0;
	        }
	    }
	    //mnozimo brzine sa mult i ubacujemo u matricu
	    for (i=1; i<=K; i++){
	        D[T[i].x][T[i].y] = ((1ll*T[i].v*mult+1) > 12345678)?12345678:(T[i].v*mult+1);
	    }
	    //krecemo u bfs
	    K2=K;
	    qs=1;
	    qe=0;
	    while (qs<=qe || K2>0){
	        citaj_red(x,y);
	        d = D[x][y]-1;
	        upisi_red(x-1,y,d);
	        upisi_red(x+1,y,d);
	        upisi_red(x,y-1,d);
	        upisi_red(x,y+1,d);
	    }
	    if (DEBUG){
	        printf(":::::: %d\n",mult);
	        bfs_debug();
	    }
	    for (i=1; i<=N; i++){
	        for (j=1; j<=M; j++){
	            if (D[i][j] == 0){
	                x0 = i;
	                y0 = j;
	                goto doublebreak;
	            }
	        }
	    }
	    doublebreak:;
	}
	
	void resi(){
	    int l,r,m,x,y,xo,yo;
	    l=1;
	    r=12345678;
	    xo=yo=-1;
	    while (l<=r){
	        m = (l+r)/2;
	        bfs(m,x,y);
	        if (x==-1){
	            r = m-1;
	        } else {
	            xo = x;
	            yo = y;
	            l = m+1;
	        }
	    }
	    if (xo==-1){
	        if (DEBUG) printf("trigger\n");
	        for (l=1; l<=N; l++){
	            for (r=1; r<=M; r++){
	                if (A[l][r]=='0'){
	                    xo=l;
	                    yo=r;
	                    goto dbb;
	                }
	            }
	        }
	    }
	    dbb:
	    printf("%d %d\n",xo,yo);
	}
	
	int main(){
	    ucitaj_matricu();
	    ucitaj_tragace();
	    resi();
	    return 0;
	}
	
	

	```
