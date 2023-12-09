---
hide:
  - toc
---

# 6 - Metropole

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 512MB |
	
	
	U nekoj dalekoj zemlji ima $N$ metropola, koji su međusobno povezane sa $M$ puteva. Svaki put spaja $2$ metropole i dvosmeran je.  Međutim, prostorno planiranje u ovoj državi je jako neobično. Naime, centralna tema tamo su **ture** - nizovi metropola $a_1,a_2,\cdots,a_n$ tako da su sve te metropole različite i da su $a_1-a_2$, $a_2-a_3$, $\cdots$, $a_n-a_1$ spojeni putevima. Kako je vlast jako sujeverna, putevi su konstruisani tako **se svaka tura sastoji od tačno $4$ metropola.**
	
	Vi kao turista u ovoj zemlji želite da vidite što više metropola. Standardno bi turista obišao neku od tura, ali kako su sve ture dužine $4$ to deluje malko dosadno, pa vi želite da izaberete vaš obilazak kao najduži niz različitih metropola tako da su svake dve uzastopne spojene putem.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	-   $NajduziPut(N, M, U[\ldots], V[\ldots])$
	
	gde je $N$ broj koji predstavlja broj metropola,  a $M$ broj koji predstavlja broj puteva. Nizovi $U[\ldots]$ i $V[\ldots]$ opisuju te puteve - $i$-ti put spaja gradove $U[i]$ i $V[i]$.  **Svi nizovi su indeksirani od 1.**
	
	Funkcija treba da vraća broj **puteva** na najdužem mogućem obilasku).
	## Primer
	
	Neka je $N=4$, i neka je niz $M=4$ i grane $U=\{1,2,3,4\}$, $V=\{2,3,4,1\}$: tada je najduži obilazak $1-2-3-4$, što ima $3$ puta, pa je odgovor $3$
	## Ograničenja
	
	-   $1 \leq N,M \leq 200.000$
	-   $1 \leq U[i], V[i] \leq N$
	-   $U[i]\neq V[i]$
	-    Moguće je od svake metropole stići do svake druge nizom puteva.
	
	## Podzadaci
	
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[11 poena]:** $N\le20$.
	-   **[12 poena]:** $N\le2500$.
	-   **[6 poena]:** Ne postoji nijedna tura.
	-   **[21 poena]:** Svaki put se nalazi u najviše jednoj turi.
	-   **[22 poena]:** Svaki put koji se nalazi u barem jednoj turi se nalazi u barem dve ture.
	-   **[28 poena]:** Nema dodatnih ograničenja.
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl  `metropole.cpp`  koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int NajduziPut(int N, int M, int* U, int* V);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojeve $N$ i $M$.
	-   U narednih $M$ redova po jedan par brojeva: $U[i]$ i $V[i]$ .
	
	Zatim ovaj program zove vašu funkciju i štampa dužinu puta koju vaša funkcija vrati.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Plavšić |
	
	
	## Rešenje kada $N \leq 20$
	
	Ovo je klasičan zadatak iz dinamičkog programiranja sa bitmaskama - traženje najdužeg puta u grafu. Imamo dinamičko programiranje $dp[i][mask]$, gde je  $i$ predstavlja čvora do kog smo stigli, a $mask$ je bitmaska koja predstavlja koje smo čvorove posetili do sad.
	Složenost $O(N^2\cdot2^N)$ 
	## Rešenje kada nema tura
	
	U ovom slučaju, dati graf je stablo, a rešenje u tom slučaju je poznato: možemo ili raditi dinamičkim programiranjem, ili naprosto krenemo od proizvoljnog čvora i nađemo od njega najdalji, a zatim od tog najdaljeg nađemo najdalji, što će nam dati najduži put.
	
	## Kako dalje?
	
	Sada treba da nađemo neku ozbiljnu strategiju kako da tražimo najduži put. U tu svrhu ćemo pronaći blokove našeg grafa. To su maksimalni podskupovi čvorova tako da u tim skupovima nema artikulacionih tačaka. Za ovo postoji generalni algoritam, ali u našem slučaju to može da se uradi lakše. Naime, pustimo pretragu po dubili (DFS) u našem grafu, i za svaku granu van stabla uzmemo put na stablu koji spaja njene krajeve (koji je dužine $3$ zbog uslova sa dužinama ciklusa) i utrvdimo da su te $4$ grane u istom bloku (svaka grana je najviše u jednom bloku). Kada tako nađemo sve moguće četvorke, tranzitivno zatvorimo relaciju "u istom bloku" (u prevodu, napravimo graf nad granama i u njemu nađemo povezane komponente - čvorovi koje one obuhvataju nam predstavljaju blokove grafa). Sporije implementacije ovog dela su obuhvaćena podzadatkom $N\le2500$.
	
	Sada, u proizvoljnom grafu možemo uvesti pojam *block-cut* stabla tako što izbacimo sve grane koje su deo nekog bloka i onda za svaki blok napravimo novi čvor koji je povezan sa svim čvorovima u tom bloku. Ovo je interesantno, jer ako je početni graf povezan, onda nam je block-cut stablo zaista stablo (ako nije povezan onda je u pitanju šuma). Svaki put u ovom grafu može da se preslika u put na block-cut stablu, samo svaki fragment puta koji predstavlja kretanje unutar jednog bloka zamenimo sa putem od početnog do čvora koji predstavlja taj blok, i onda od tog do završnog.
	
	Sada nam je cilj da  modifikujemo block-cut stablo. Za svaki blok želimo da pronađemo stablo tako da su nam čvorovi bloka listovi, i da je najduži put od $u$ do $v$ unutar bloka jednak dužini puta od $u$ do $v$ u našem stablu. Ako svaki blok čvor u block-cut stablu zamenimo sa ovom mrežom koja enkodira optimizaciju traženja najdužeg puta na onom fragmentu puta koji se nalazi unutar stabla, onda nam se zadatak samo svodi na prethodni podzadatak - traženje najdužeg puta na stablu (ovde konkretno na tom našem modifikovanom block-cut stablu), jer svaki put u stablu možemo na isti način da preslikamo na put na modifikovanom block-cut stablu, a po konstrukciji će se najduži put preslikati u put iste dužine.
	
	Sada nam treba detaljan opis blokova našeg grafa. Za to nam treba sledeća lema:
	*Lema: Svaki blok u našem grafu je kompletan bipatritivan graf gde je jedna particija veličine $2$*.
	**Dokaz:** Pošto svaki ciklus parne dužine, graf je bipartitivan - neka je u našem bloku $b$ belih i $c$ crnih. Moguće je dokazati da unutar bloka, za svake dve grane postoji ciklus koji ih sadrži. Pretpostavimo da postoje crni čvor $u$ i beli čvor $v$ koji nisu spojeni granom, i neka iz njih izlaze grane $ua$ i $vb$. Po prethodno navedenom, postoji ciklus koji sadrži, a to jedino može biti ciklus $u-a-b-v$, tako da su $u$ i $v$ ipak povezani granom, pa je graf kompletan i bipartitivan. Najzad, onda trivijalno postoji ciklus dužine $2\min(b,c)=4$, pa je zaista u jednoj particiji samo $2$ čvora.  
	
	Sada smo već blizu kraja. Za konstrukciju naših stabala razlikujemo dva slučaja (i to baš oni iz podzataka!!)
	
	## Svaka grana se nalazi u najviše jednom ciklusu
	U ovom slučaju su  nam blokovi samo $K_{2,2}$ to jest ciklusi dužine $4$. Posmatrajmo ciklus $a-b-c-d$, tu suprotni na ciklusu treba da budu na distanci $2$, a susedni na ciklusu treba da budu na distanci $3$. Dodajmo čvorove $e$ i $f$ i povežemo parove $a-e$, $c-e$, $b-f$, $d-f$ i $e-f$. Lako se proverava da je ova konstrukcija baš ono što smo tražili.
	## Svaka grana koja se nalazi u jednom ciklusu se nalazi u barem dva ciklusa
	U ovom slučaju su  nam blokovi samo $K_{2,t}$ sa $t\ge3$, neka su nam ova $2$ čvora bela, a ostalih $t$ crni. Možemo da vidimo da najduža putanja između $2$ crna čvora dužine $4$, između crnog i belog dužine $3$ i između dva dela dužine $2$. Zato je dovoljno da uzmemo jedan novi čvor koji spojimo sa svim belima direktno granom, a sa svim crnima putem dužine $2$.
	
	## Glavno rešenje
	Naprosto spojimo konstrukcije iz predhotna dva slučaja, i onda na dobijenom stablu nađemo najduži put.
	Složenost $O(N)$.
	
	``` cpp title="06_metropole.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 200007
	using namespace std;
	vector<int> g[3*MAXN], ind[MAXN],c[2],ge[MAXN];
	int p[MAXN], a[MAXN], d[MAXN], u[MAXN], v[MAXN], b[MAXN];
	bool vi[MAXN], uc[MAXN], ve[MAXN];
	void dfs(int s,int f,int du)
	{
	    d[s]=du;
	    p[s]=f;
	    b[s]=du&1;
	    vi[s]=true;
	    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f)
	    {
	        int v=g[s][i];
	        if(vi[v])
	        {
	            if(d[v]>d[s]) continue;
	            uc[ind[s][i]]=true;
	            uc[a[s]]=true;
	            ge[ind[s][i]].push_back(a[s]);
	            ge[a[s]].push_back(ind[s][i]);
	            uc[a[p[s]]]=true;
	            ge[a[s]].push_back(a[p[s]]);
	            ge[a[p[s]]].push_back(a[s]);
	            uc[a[p[p[s]]]]=true;
	            ge[a[p[s]]].push_back(a[p[p[s]]]);
	            ge[a[p[p[s]]]].push_back(a[p[s]]);
	        }
	        else {a[v]=ind[s][i]; dfs(v,s,du+1);}
	    }
	}
	void dfsd(int s,int f,int du)
	{
	    d[s]=du;
	    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfsd(g[s][i],s,du+1);
	}
	void dfsblok(int s)
	{
	    ve[s]=true;
	    if(!vi[u[s]]) {c[b[u[s]]].push_back(u[s]); vi[u[s]]=true;}
	    if(!vi[v[s]]) {c[b[v[s]]].push_back(v[s]); vi[v[s]]=true;}
	    for(int i=0;i<ge[s].size();i++) if(!ve[ge[s][i]]) dfsblok(ge[s][i]);
	}
	int NajduziPut(int N, int M, int* U, int* V)
	{
	    for(int i=1;i<=M;i++) {u[i]=U[i]; v[i]=V[i];}
	    for(int i=1;i<=M;i++) g[U[i]].push_back(V[i]);
	    for(int i=1;i<=M;i++) ind[U[i]].push_back(i);
	    for(int i=1;i<=M;i++) g[V[i]].push_back(U[i]);
	    for(int i=1;i<=M;i++) ind[V[i]].push_back(i);
	    dfs(1,1,0);
	    for(int i=1;i<=N;i++) g[i].clear();
	    for(int i=1;i<=M;i++)
	    {
	        if(!uc[i])
	        {
	            g[U[i]].push_back(V[i]);
	            g[V[i]].push_back(U[i]);
	        }
	    }
	    fill(vi+1,vi+N+1,false);
	    for(int i=1;i<=M;i++) if(!ve[i] && uc[i])
	    {
	        dfsblok(i);
	        if(c[0].size()>c[1].size()) swap(c[0],c[1]);
	        if(c[1].size()==2)
	        {
	            N++;
	            g[N].push_back(c[0][0]); g[N].push_back(c[0][1]);
	            g[c[0][0]].push_back(N); g[c[0][1]].push_back(N);
	            N++;
	            g[N].push_back(c[1][0]); g[N].push_back(c[1][1]);
	            g[c[1][0]].push_back(N); g[c[1][1]].push_back(N);
	            g[N-1].push_back(N); g[N].push_back(N-1);
	        }
	        else
	        {
	            N++;
	            g[N].push_back(c[0][0]); g[N].push_back(c[0][1]);
	            g[c[0][0]].push_back(N); g[c[0][1]].push_back(N);
	            int x = N;
	            for(int i=0;i<c[1].size();i++)
	            {
	                N++;
	                g[c[1][i]].push_back(N);
	                g[N].push_back(x);
	                g[N].push_back(c[1][i]);
	                g[x].push_back(N);
	            }
	        }
	        for(int i=0;i<2;i++) for(int j=0;j<c[i].size();j++) vi[c[i][j]]=false;
	        c[0].clear(); c[1].clear();
	    }
	    dfsd(1,1,0);
	    int mx=0,mxi;
	    for(int i=1;i<=N;i++) if(d[i]>mx) {mx=d[i]; mxi=i;}
	    dfsd(mxi,mxi,0);
	    for(int i=1;i<=N;i++) if(d[i]>mx) mx=d[i];
	    return mx;
	}

	```
