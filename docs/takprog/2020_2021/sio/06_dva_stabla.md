---
hide:
  - toc
---

# 6 - Dva stabla

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3000ms | 256MB |
	
	Data su vam dva stabla sa po $N$ čvorova. Potrebno je odgovoriti na $Q$ upita. Svaki upit je opisan sa po 4 broja $A$, $B$, $C$ i $D$. Odgovor na upit je broj indeksa $i$ tako da se čvor sa indeksom $i$ nalazi na putu od $A$ do $B$ u prvom stablu i čvor sa indeksom $i$ se nalazi na putu od $C$ do $D$ u drugom stablu. Drugim rečima, ako je $S1$ skup indeksa svih čvorova na putu od $A$ do $B$ u prvom stablu i $S2$ skup indeksa svih čvorova na putu od $C$ do $D$ u drugom stablu, odgovor na upit je $|S1 \cap S2|$.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $\text{Resi}(N, Q, P, U1[\dots], V1[\dots], U2[\dots], V2[\dots], A1[\dots], B1[\dots], C1[\dots], D1[\dots], R[\dots])$
	
	gde je:
	* $N$ broj čvorova u stablima
	* $Q$ broj upita
	* $P$ parametar koji se koristi pri izračunavanju vrednosti nizova $A$, $B$, $C$ i $D$.
	* $U1$ i $V1$ nizovi dužine $N-1$ koji opisuju grane prvog stabla. $i$-ta grana spaja čvorove $U1_i$ i $V1_i$.
	* $U2$ i $V2$ nizovi dužine $N-1$ koji opisuju grane drugog stabla. $i$-ta grana spaja čvorove $U2_i$ i $V2_i$.
	* $A1$, $B1$, $C1$ i $D1$ nizovi dužine $Q$ pomoću kojih se izračunavaju nizovi $A$, $B$, $C$ i $D$ na sledeći način: Neka je $ans_i$ odgovor na $i$-ti upit i $ans_0=0$. Onda je:
	- $A_i = (A1_i + ans_{i-1}*P - 1) \% N + 1$
	- $B_i = (B1_i + ans_{i-1}*P - 1) \% N + 1$
	- $C_i = (C1_i + ans_{i-1}*P - 1) \% N + 1$
	- $D_i = (D1_i + ans_{i-1}*P - 1) \% N + 1$
	* $R$ niz u koji treba upisati odgovore na upite.
	
	**Svi nizovi su indeksirani od 1.**
	
	## Ograničenja
	* $1 \leq N \leq 2 \times 10^5$
	* $1 \leq Q \leq 2 \times 10^5$
	* $1 \leq A[i], B[i], C[i], D[i] \leq N$
	
	## Podzadaci
	Test primeri su podeljeni u 9 podzadataka:
	
	* **[3 poena]:** $P=0$, $N, Q \leq 1000$.
	* **[7 poena]:** $P=0$, $N, Q \leq 3 \times 10^4$, oba stabla su lanci.
	* **[8 poena]:** $P=0$, $N, Q \leq 3 \times 10^4$, drugo stablo je lanac.
	* **[11 poena]:** $P=0$, $N, Q \leq 3 \times 10^4$.
	* **[14 poena]:** $P=0$, oba stabla su lanci.
	* **[15 poena]:** $P=0$, drugo stablo je lanac.
	* **[30 poena]:** $P=0$.
	* **[6 poena]:** $P=1$, oba stabla su lanci.
	* **[6 poena]:** $P=1$.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `dva_stabla.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može da sadrži i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int Q, int P, int *U1, int *V1, int *U2, int *V2, int *A1, int *B1, int *C1, int *D1, int *R);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova, ali ne smeju da pristupaju van njihovih granica.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sedeće podatke:
	
	* U prvom redu tri broja $N$, $Q$ i $P$.
	* U narednih $N-1$ redova nalazi se po dva broja. U $i$-tom redu $U1_i$ i $V1_i$.
	* U narednih $N-1$ redova nalazi se po dva broja. U $i$-tom redu $U2_i$ i $V2_i$.
	* U narednih $Q$ redova nalazi se po 4 broja. U $i$-tom redu $A1_i$, $B1_i$, $C1_i$ i $D1_i$.
	
	Zatim ovaj program poziva vašu funkciju i štampa odgovore na upite koje je funkcija popunila u nizu $R$, po jedan u svakom redu.
	
	## Primer
	### Ulaz
	```
	5 1 0
	1 4
	2 3
	1 5
	1 2
	1 3
	2 3
	1 5
	4 3
	5 3 2 4
	```
	
	### Izlaz
	```
	2
	```
	
	### Objašnjenje
	- Na putu od čvora $5$ do čvora $3$ u prvom stablu nalaze se čvorovi sa indeksima $1$, $2$, $3$ i $5$.
	- Na putu od čvora $2$ do čvora $4$ u drugom stablu nalaze se čvorovi sa indeksima $2$, $3$ i $4$.
	- Indeksi $2$ i $3$ se pojavljuju na oba puta, pa je rešenje 2.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Tadija Šebez | Tadija Šebez | Tadija Šebez | Aleksa Milisavljević |
	
	Za $P=0$ svi upiti su unapred poznati pa ih možemo rešavati u proizvoljnom redosledu. Kada je $P=1$ moramo da odgovorimo na $i$-ti upit da bismo saznali $i+1$-vi upit, pa zadatak moramo da rešavamo **online**, odnosno da na upite odgovaramo redom kojim su zadati.
	
	## Rešenje kada je $N, Q \leq 1000$
	Iskoristimo **DFS** algoritam da nađemo sve čvorove na jednom i na drugom putu i zatim prebrojmo koliko čvorova se nalazi na oba puta. Vremenska složenost je $O(QN)$.
	
	## Rešenje kada su oba stabla lanci
	Uz pomoć **DFS** algoritma možemo da poređamo čvorove oba stabla u dva niza. Neka su to nizovi $S$ i $T$. U ovom slučaju se upiti svode na pitanja za podnizove. Posmatrajmo upit za podniz $L1 \dots R1$ niza $S$ i podniz $L2 \dots R2$ niza $T$. Ako bismo u nizu $T$ označili sa 1 poziciju $i$ ako se $T_i$ nalazi na podnizu $L1 \dots R1$ niza $S$, i sa 0 u suprotnom, rešenje za upit bi bilo zbir oznaka na podnizu $L2 \dots R2$ niza $T$. 
	
	Za podzadatak kada je $N, Q \leq 3 \times 10^4$, možemo da održavamo oznake u **Fenvikovom stablu** i upite rešavamo **offline** pomoću **Mo-ovog algoritma**. Upite sortiramo po paru $(\lfloor frac{L1}{\sqrt{N}} \rfloor, R1)$ i rešavamo ih u tom redosledu. Kada rešimo upit sa podnizom $L1_{i-1} \dots R1_{i-1}$ levu granicu pomeramo do $L1_i$, a desnu do $R1_i$, menjajući $|L1_i-L1_{i-1}|+|R1_i-R1_{i-1}|$ oznaka u nizu $T$. Na ovaj način imaćemo $O(N \sqrt{N})$ promena i za svaku promenu nam treba $O(logN)$ vremena za izmenu u **Fenvikovom stablu**, pa je vremenska složenost ovog rešenja $O(N \sqrt{N} logN)$.
	
	Kada je $N, Q \leq 2 \times 10^5$ i $P=0$, rešenje je slično kao prethodno, ali potrebna nam je jedna ključna opservacija: Rešenje za upit $L1, R1, L2, R2$ jednako je rešenje za $1, R1, L2, R2$ minus rešenje za $1, L1-1, L2, R2$. Na ovaj način možemo da rastavimo upite na po dva upita za koje je podniz niza $S$ zapravo prefiks istog. Ako upite sortiramo po desnoj granici podniza niza $S$, ukupan broj izmena u **Fenvikovom stablu** će biti najviše $N$. Vremenska složenost ovog rešenja je $O(NlogN)$.
	
	Kada je $P=1$, možemo da primenimo isto rešenje, ali umesto **Fenvikovog stabla** treba da iskoristimo **prezistentno segmentno stablo** kako bismo mogli da sačuvamo po verziju segmentnog stabla za svaki od $N$ prefiksa niza $S$, i kasnije ih koristili da odgovaramo na upite u zadatom redosledu.
	
	## Rešenje kada je jedno stablo lanac
	U ovom slučaju lanac možemo da pretvorimo u niz $S$ i na njemu radimo **Mo-ov algoritam** ili da rastavimo upite kao u prošlom rešenju. Deo rešenja koji se menja je to da nam više nisu potrebni upiti za zbir na podnizu već za zbir na putu u stablu. Put od $A$ do $B$ u stablu možemo da rastavimo na put od korena do $A$, plus put od korena do $B$, minus put od korena do $\text{LCA}(A,B)$, minus put od korena do $\text{parent}(\text{LCA}(A,B))$. Treba još da nađemo način da dobijemo zbir oznaka svih čvorova na putu od korena do nekog čvora. Uradimo **Ojlerov obilazak** stabla i smestimo čvorove u niz tim redom kako smo ih posetili u **DFS**-u. Na ovaj način će svako podstablo da čini jedan podniz. Tokom **DFS**-a možemo da zapamtimo i granice podnizova za svako podstablo. Nad nizom koji smo ovako dobili možemo da napravimo **Fenvikovo stablo** koje podržava upite povećavanja i smanjivanja vrednosti svih članova nekog podniza, i upite koji vraćaju vrednost nekog čvora. Ako koristimo **Mo-ov algoritam** sa ovom strukturom dobijamo složenost $O(N \sqrt{N} logN)$, što prolazi podzadatak kada je $N, Q \leq 3 \times 10^4$, a ako rastavimo podnizove niza $S$ kao u prethodnom podzadatku, dobijamo rešenje u vremenskoj složenosti $O(NlogN)$ što prolazi i podzadatak kada je $N, Q \leq 2 \times 10^5$.
	
	## Rešenje kada je $N, Q \leq 3 \times 10^4$
	Rešenje za ovaj podzadatak je da na jedno stablo primenimo **Mo-ov algoritam**, a na drugo stablo istu strukturu podataka kao u prethodnom rešenju. **Mo-ov algoritam** na stablu zapravo primenjujemo na **Ojlerovom obilasku**. Napravimo od stabla niz dužine $2N$ tako što stavimo čvor u niz kada ulazimo i kada izlazimo iz čvora. Put od $A$ do $B$, gde je prvo pojavljivanje čvora $A$ pre prvog pojavljivanja čvora $B$, mapiramo na podniz od drugog pojavljivanja čvora $A$ do prvog pojavljivanja čvora $B$, osim ako je $A$ predak čvora $B$, kada ovaj put mapiramo na podniz od prvog pojavljivanja $A$ do prvog pojavljivanja $B$. U prvom slučaju se svi čvorovi na putu osim $\text{LCA}(A, B)$ pjavljuju tačno jednom, a ostali čvorovi 0 ili 2 puta. U drugom slučaju svi čvorovi na putu od $A$ do $B$ se pajavljuju tačno jednom, a ostali čvorovi 0 ili 2 puta. Kada sortiramo upite, u strukturi za drugo stablo održavamo sve čvorove koji se pojavljuju tačno jednom i pre rešavanja upita ubacimo i čvor $\text{LCA}(A, B)$ ako već nije ubačen. Vremenska složenost ovog algoritma je $O(N \sqrt{N} logN)$.
	
	## Rešenje kada je $P=0$
	Kao što smo rastavili put u drugom stablu, tako možemo da rastavimo i put u prvom stablu. I u ovom rešenju na isti način radimo sa drugim stablom, a za prvo stablo upite rastavljamo na po 4 upita za puteve od korena do nekog čvora. Upite ćemo rešiti **offline**, **DFS** algoritmom. Kada uđemo u neki čvor dodamo ga u strukturi za drugo stablo, zatim rešimo sve upite za puteve od korena do trenutnog čvora i na kraju kada izađemo iz čvora izbacujemo trenutni čvor iz strukture za drugo stablo. Vremenska složenost ovog rešenja je $O(NlogN)$.
	
	## Rešenje za 100 poena
	**Online** rešenje je slično kao i **offline** rešenje, samo što koristimo **perzistentno segmentno stablo** umesto **Fenvikovog stabla** kao strukturu za drugo stablo. Na taj način možemo da zapamtimo verzije strukture kakva je bila nakon ulaska u svaki čvor, i uz pomoć toga možemo redom da odgovaramo na upite. Vremenska i memorijska složenost ovog rešenja je $O(NlogN)$.
	
	``` cpp title="06_dva_stabla.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	#define pb push_back
	
	const int N=200050;
	const int M=2*20*N;
	
	int root[N],ls[M],rs[M],sum[M],tsz;
	void Add(int p,int&c,int ss,int se,int qi,int x){
		c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+x;
		if(ss==se)return;
		int mid=ss+se>>1;
		if(qi<=mid)Add(ls[p],ls[c],ss,mid,qi,x);
		else Add(rs[p],rs[c],mid+1,se,qi,x);
	}
	int Get(int c,int ss,int se,int qs,int qe){
		if(qs>qe||qs>se||ss>qe)return 0;
		if(qs<=ss&&qe>=se)return sum[c];
		int mid=ss+se>>1;
		return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	}
	
	vector<int> E[2][N];
	int lid[N],rid[N],tid;
	void Euler(int u,int p,int t){
		lid[u]=++tid;
		for(int v:E[t][u])if(v!=p)Euler(v,u,t);
		rid[u]=++tid;
	}
	
	void Build(int u,int p,int t){
		Add(root[p],root[u],1,tid,lid[u],1);
		Add(root[u],root[u],1,tid,rid[u],-1);
		for(int v:E[t][u])if(v!=p)Build(v,u,t);
	}
	
	
	const int L=20;
	int par[2][N][L],dep[2][N];
	void DFS(int u,int p,int t){
		par[t][u][0]=p;
		dep[t][u]=dep[t][p]+1;
		for(int i=1;i<L;i++){
			par[t][u][i]=par[t][par[t][u][i-1]][i-1];
		}
		for(int v:E[t][u])if(v!=p)DFS(v,u,t);
	}
	int LCA(int u,int v,int t){
		if(dep[t][u]<dep[t][v])swap(u,v);
		for(int i=L-1;~i;i--)if(dep[t][par[t][u][i]]>=dep[t][v])u=par[t][u][i];
		for(int i=L-1;~i;i--)if(par[t][u][i]!=par[t][v][i])u=par[t][u][i],v=par[t][v][i];
		return u==v?v:par[t][v][0];
	}
	
	int Get(int x,int y){
		if(x==0||y==0)return 0;
		return Get(root[x],1,tid,1,lid[y]);
	}
	
	int Get(int node,int C,int D,int lca){
		return Get(node,C)+Get(node,D)-Get(node,lca)-Get(node,par[1][lca][0]);
	}
	
	void Resi(int N, int Q, int P, int *U1, int *V1, int *U2, int *V2, int *A1, int *B1, int *C1, int *D1, int *R){
		for(int i=1;i<N;i++){
			E[0][U1[i]].pb(V1[i]);
			E[0][V1[i]].pb(U1[i]);
	
			E[1][U2[i]].pb(V2[i]);
			E[1][V2[i]].pb(U2[i]);
		}
		Euler(1,0,1);
		Build(1,0,0);
		DFS(1,0,0);
		DFS(1,0,1);
		int last_ans=0;
		for(int i=1;i<=Q;i++){
			int A=(A1[i]+last_ans*P-1)%N+1;
			int B=(B1[i]+last_ans*P-1)%N+1;
			int C=(C1[i]+last_ans*P-1)%N+1;
			int D=(D1[i]+last_ans*P-1)%N+1;
			int lca1=LCA(A,B,0);
			int lca2=LCA(C,D,1);
			R[i]=Get(A,C,D,lca2)+Get(B,C,D,lca2)-Get(lca1,C,D,lca2)-Get(par[0][lca1][0],C,D,lca2);
			last_ans=R[i];
		}
	}

	```
