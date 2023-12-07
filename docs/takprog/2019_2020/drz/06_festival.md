---
hide:
  - toc
---

# A3 - Festival

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2500ms | 256MB |
	
	
	Kao što znate, usled trenutne svetske epidemiološke situacije, mnogobrojni festivali širom sveta su otkazani. Međutim, postoji jedan festival, koji se održava svake godine u blizini jednog vama vrlo poznatog gradića u Rusiji, koji je odlučio da se uprkos svemu ipak održi. Kako nemate mnogo izbora koji festival da posetite ovog leta, odlučili ste da i vi postanete ove godine učesnik svetski poznatog **Festivala intervala**.
	
	Na ovom festivalu svaka atrakcija je predstavljena jednim intervalom na brojevnoj pravi. Zbog neke bizarne geometrije koja se javlja u opskurnim delovima Rusije, znamo da su dve atrakcije susedne ako i samo ako je interval koji odgovara jednoj od te dve atrakcije podinterval intervala koji odgovara drugoj od njih. Podsećamo vas da je interval $[a,b]$ podinterval intervala $[c,d]$ ako $c\leq a\leq b\leq d$.
	
	Vi ne znate tačno kako ćete se kretati po festivalu, pa vas za date atrakcije $u$ i $v$ interesuje najkraći put od atrakcije $u$ do atrakcije $v$, to jest, koliko puta morate da putujete između susednih atrakcija da biste stigli od atrakcije $u$ do atrakcije $v$. Veoma ste uzbuđeni povodom vašeg provoda na festivalu, pa želite da saznate odgovor na prethodno pitanje za čak $Q$ različitih parova atrakcija $(u,v)$!
	
	## Opis ulaza
	
	Prva linija standardnog ulaza sadrži dva broja, broj intervala $N$, i broj upita $Q$.
	Druga linija standardnog ulaza sadrži niz $A_i$ od $2\cdot N$ brojeva, po $2$ pojavljivanja svakog broja iz skupa $\{1,2,\ldots,N\}$, tako da indeks prvog pojavljivanja broja $i$ u tom nizu predstavlja početak intervala $i$, dok indeks drugog pojavljivanja broja $i$ u tom nizu predstavlja kraj intervala $i$.
	U narednih $Q$ linija standardnog ulaza nalaze se po dva prirodna broja $u_i,v_i$: indeksi atrakcija između kojih tražimo dužinu najkraćeg puta.
	
	## Opis izlaza
	
	Na standardni izlaz ispišite $Q$ linija: u $i$-toj liniji treba da piše odgovor na $i$-ti upit.
	
	## Primer 1
	
	### Ulaz
	
	```
	3 2
	3 1 2 1 2 3
	2 3
	1 2
	```
	
	### Izlaz
	
	```
	1
	2
	```
	## Objašnjenje primera
	
	Od $2$ do $3$ možemo da stignemo direktno, jer je interval koji odgovara atrakciji $2$ podinterval intervala koji odgovara atrakciji $3$. Atrakcije $1$ i $2$ nisu susedne, pa je najkraći put među njima $1-3-2$.  
	
	## Ograničenja
	
	-   $1 \leq N,Q \leq 300.000$
	-   $1 \leq A_i \leq N$
	-  Svaka vrednost od $1$ do $N$ se pojavljuje tačno $2$ puta u nizu $A_i$.
	-   $1 \leq u_i,v_i \leq N$
	-   $u_i \neq v_i$
	
	Test primeri su podeljeni u 4 podzadatka:
	
	-   **[18 poena]:** $N,Q\leq500$
	-   **[26 poena]:** $N,Q\leq3000$
	-   **[16 poena]:** Svaka dva intervala su ili disjunktna, ili je jedan podinterval drugog
	-   **[40 poena]:** Nema dodatnih ograničenja
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Lazar Milenković | Aleksa Plavšić |
	
	
	## Analiza
	Na početku je potrebno proveriti da li je jedan interval podinterval drugog i u tom slučaju rešenje je 1. Ukoliko su u pitanju dva ista intervala, tada je rešenje 0. Nakon što smo razrešili dva specijalna slučaja, možemo se upustiti u generalniju diskusiju.
	
	Nakon toga, pretpostavimo bez gubitka opštosti da tražimo najkraći put od intervala čiji je početak levo u odnosu na početak drugog intervala. Najbitnija stvar koju je potrebno primetiti ovde jeste da je uvek dovoljno da se krećemo (u desno) ka podintervalu čiji je početak najudaljeniji ili ka nadintervalu čiji je kraj najudaljeniji. Ako smo u prvom koraku krenuli ka podintervalu, tada u narednom koraku idemo ka nadintervalu. Ovaj proces se nastavlja sve dok ne stignemo do traženog intervala ili ne možemo učiniti naredni korak. Podstičemo takmičare da dokažu korektnost ovog pristupa.
	
	## Rešenje u $O(N \cdot Q)$
	Gore opisano kretanje po intervalima možemo implementirati u linearnoj složenosti, tako da za svaki od $Q$ upita imamo najviše $N$ koraka.
	
	## Rešenje za sve poene
	U ovom slučaju, kretanje po intervalima je potrebno implementirati u logaritamskoj složenosti, koristeći takozvani "binary lifting". Naime, za svaki interval čuvamo intervale koji se nalaze na rastojanju $2^0, 2^1, 2^2,... 2^{\lfloor \log_2 N \rfloor}$.
	
	## Rešenje u $O(N^3)$
	U ovom slučaju eksplicitno konstruišemo graf gde su čvorovi intervali a ivice postoje između susednih intervala. Nakon toga, možemo odrediti sve parove najkraćih puteva koristeći BFS ili Flojdov algoritam. Pošto imamo $N$ čvorova i $O(N^2)$ ivica, složenost ovog pristupa je $O(N^3)$, što je dovoljno za slučaj kada je $N \leq 500$.
	
	## Rešenje za slučaj kada su intervali ili disjunktni ili je jedan podinterval drugog
	U ovom slučaju nije teško videti da je rešenje uvek -1, 0, 1 ili 2 (zašto?). Pošto smo razrešili slučajeve kada je rešenje 0 ili 1, potrebno je proveriti da li je rešenje -1 ili 2. Za svaki interval, čuvamo najširi interval koji ga sadrži. Ukoliko se najširi interval koji sadrži početni poklapa sa najširim intervalom koji sadrži krajnji, tada je rešenje 2. U suprotnom je rešenje -1.
	
	``` cpp title="06_festival.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 300007
	#define MAXL 20
	using namespace std;
	int a[2*MAXN],nxt[MAXL][MAXN],rs[MAXN],rf[MAXN],l[MAXN],r[MAXN],p[2*MAXN];
	bool check(int u, int v)
	{
		return (l[u]<l[v] && r[v]<r[u]) || (l[v]<l[u] && r[u]<r[v]);
	}
	bool left(int u,int v)
	{
		if(check(u,v)) return false;
		return l[u]<l[v];
	}
	int dist(int u,int v)
	{
		if(u==v) return 0;
		if(check(u,v)) return 1;
		int w=u,d=1;
		for(int i=MAXL-1;i>=0;i--) if(left(nxt[i][w],v)) {w=nxt[i][w]; d+=(1<<i);}
		return d+1;
	}
	int main()
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=2*n;i++)
		{
			if(!l[a[i]]) l[a[i]]=i;
			else r[a[i]]=i;
		}
		for(int i=1;i<=n;i++) {p[l[i]]=r[i]; p[r[i]]=l[i];}
		int mxr=0,nd=0;
		for(int i=1;i<=2*n;i++) if(p[i]>i)
		{
			if(p[i]<mxr) rf[a[i]]=nd;
			else {rf[a[i]]=-1; mxr=p[i]; nd=a[i];}
		}
		int mxl=0; nd=0;
		for(int i=1;i<=2*n;i++) if(p[i]<i)
		{
			if(p[i]<mxl) rs[a[i]]=nd;
			else {rs[a[i]]=-1; mxl=p[i]; nd=a[i];}
		}
		for(int i=1;i<=n;i++)
		{
			if(rs[i]==-1) nxt[0][i]=(rf[i]==-1)?i:rf[i];
			if(rf[i]==-1) nxt[0][i]=(rs[i]==-1)?i:rs[i];
		}
		for(int i=1;i<MAXL;i++) for(int j=1;j<=n;j++) nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		for(int i=1;i<=q;i++)
		{
			int u,v; scanf("%d%d",&u,&v);
			if(u==v) {printf("0\n"); continue;}
			if(check(u,v)) {printf("1\n"); continue;}
			if(left(v,u)) swap(u,v);
			int ws=u,wf=u,ds=0,df=0;
			if(rs[u]!=-1) {ws=rs[u]; ds++;}
			if(rf[u]!=-1) {wf=rf[u]; df++;}
			int w=nxt[MAXL-1][ws];
			if(left(w,v)) {printf("-1\n"); continue;}
			int res1=dist(ws,v)+ds,res2=dist(wf,v)+df;
			printf("%d\n",min(res1,res2));
		}
	}

	```
