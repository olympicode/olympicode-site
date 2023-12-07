---
hide:
  - toc
---

# 6 - Metro

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 512MB |
	
	
	U toku je planiranje prve faze beogradskog metroa, koja radi jednostavnosti vozi isključivo sa juga na sever (ko želi da se vozi nazad ide tramvajem). Postoji $N$ stanica metroa, i one se mogu podeliti u tri grupe: južne (južno od Save), severne (severno od Save), i središnje (koje se nalaze baš ispod korita Save). Jedna od južnih stanica je **glavna polazna stanica** i ima redni broj 1, a jedna od severnih stanica je **glavna dolazna stanica** i ima redni broj 2.
	
	$M$ jednosmernih metro tuneli povezuje stanice. Važi sledeće:
	
	* Tuneli koje kreću iz južnih stanica idu **do južnih ili središnjih stanica**.
	* Tuneli koje kreću iz središnjih ili severnih stanica **idu do severnih stanica**.
	* Južne stanice imaju **tačno jedan ulazni tunel**, osim glavne polazne stanice, u koju ne ulazi nijedan tunel.
	* Severne stanice imaju **tačno jedan izlazni tunel**, osim glavne dolazne stanice, iz koje ne izlazi nijedan tunel.
	* Središnje stanice imaju **tačno jedan ulazni i jedan izlazni tunel**.
	* Mapa metroa se može nacrtati tako da se tuneli **ne seku**, pri čemu je **redosled stanica na ulazu isti kao redosled na mapi sa istoka na zapad** (svaka stanica je istočno od onih sa većim indeksom) i važi da **ukoliko postoji tunel od stanice $u$ do stanice $v$, onda je na mapi stanica $u$ južnije od stanice $v$**.
	* Garantuje da se u svaku stanicu može stići iz glavne polazne stanice, i da se iz svake stanice može stići u glavnu dolaznu stanicu.
	
	Data vam je mapa metroa i vreme potrebno da se prođe kroz svaki od tunela. Potrebno je da odgovorite na $Q$ upita sledećih tipova:
	
	* Promeni vreme potrebno da se prođe kroz dati tunel na $t$.
	* Odredi vreme potrebno da se stigne od glavne polazne do glavne dolazne stanice $K$-tim najbržim putem (garantuje se da će postojati bar $K$ puteva).
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $\text{Resi}(N, M, U[\dots], V[\dots], C[\dots], Q, A[\dots],
	  B[\dots], R[\dots])$
	  
	
	gde je:
	
	* $N$ broj stanica.
	* $M$ broj tunela.
	* $U$, $V$, $C$ nizovi dužine $M$ koji opisuju tunele: $i$-ti tunel ide od stanice $U[i]$ do $V[i]$ i potrebno je $C[i]$ sekundi da se prođe.
	* $Q$ broj upita.
	* $A$ i $B$ nizovi dužine $Q$ koji sadrže upite, a $R$ niz dužine $Q$ u koji je potrebno zapisati rezultate upita. Konkretno, za $i$-ti upit:
	    * Ako $A[i] = -1$, potrebno je u $R[i]$ zapisati vreme potrebno da se stigne od glavne polazne do glavne dolazne stanice $B[i]$-tim najbržim putem.
	    * U suprotnom, potrebno je promeniti vreme prolaska kroz $A[i]$-ti tunel na $B[i]$ i ostaviti vrednost $R[i]$ nepromenjenu.
	
	**Svi nizovi su indeksirani od 1.**
	
	## Primer
	
	Neka je $N = 6$, $M = 7$, $U = [1, 1, 5, 5, 3, 4, 6]$, $V = [5, 6, 3,
	4, 2, 2, 2]$, $C = [1, 8, 2, 4, 5, 5, 2]$, $Q = 4$, $A = [-1, -1, 6,
	-1]$ i $B = [1, 3, 7, 3]$.
	
	Ovaj ulaz opisuje metro u kom su stanice $1$ (glavna polazna) i $5$ južne, stanice $3$, $4$ i $6$ središnje i stanica $2$ (glavna dolazna) severna. Mogući putevi su:
	
	- $1 \to 5 \to 3 \to 2$, sa vremenom $8$,
	- $1 \to 5 \to 4 \to 2$, sa vremenom $10$, i 
	- $1 \to 6 \to 2$, sa vremenom $10$.
	
	Odgovor na prvi upit je vreme kroz najbrži put ($8$), a na drugi vreme kroz treći najbrži put ($10$). Nakon trećeg upita vreme kroz poslednji put postaje $12$ (jer je dužina tunela $4 \to 2$ povećana), što je i
	odgovor na poslednji upit.
	
	Dakle, očekivan izlaz je $R = [8, 10, ?, 12]$, gde $?$ predstavlja član koji odgovara upitu u kom se menja vreme prolaska kroz tunel.
	
	## Ograničenja
	
	* $3 \leq N \leq 50000$.
	* $1 \leq Q \leq 20000$.
	* $N-1 \leq M \leq 2N-4$.
	* Dužine tunela (i originalne, i nakon promene) su u intervalu $[0, 10^4]$.
	
	## Podzadaci
	
	Test primeri su podeljeni u šest podzadataka:
	
	* **[3 poena]:** $Q = 1$.
	* **[6 poena]:** $N, Q \leq 1000$.
	* **[14 poena]:** Postoji najviše $1000$ središnjih stanica.
	* **[21 poena]:** Sve promene vremena se odnose na tunele koji kreću iz
	  središnje stanice ili stižu u središnju stanicu.
	* **[23 poena]:** U svim upitima u kojima se traži vreme, važi $B[i] =
	  1$.
	* **[33 poena]:** Bez dodatnih ograničenja.
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `metro.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int M, int *U, int *V, int *C, int Q, int *A, int *B, long long *R);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program
	učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N, M$.
	* U narednih $M$ redova po tri broja. U $i$-tom redu nalaze se brojevi $U_i, V_i, C_i$.
	* U narednom redu broj $Q$.
	* U narednih $Q$ redova po dva broja: $A_i$ i $B_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa odgovore na upite koje funkcija popuni u nizu $R$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dimitrije Erdeljan | Tadija Šebez | Aleksa Milisavljević i Pavle Martinović |
	
	## Izgled metroa
	
	Stanice i tunele možemo smatrati čvorovima i granama usmerenog grafa. Prvo treba da zaključimo nekoliko stvari o tome kako ovaj graf izgleda. 
	
	Posmatrajmo prvo samo južne stanice i tunele između njih. Ove stanice imaju tačno jedan ulazni tunel, osim glavne polazne stanice u koju ne ulazi nijedan tunel. Prema tome, južne stanice formiraju usmereno stablo sa korenom u glavnoj polaznoj stanici tako da su sve grane usmerene od korena ka listovima. Slično, i severne stanice formiraju usmereno stablo sa korenom u glavnoj dolaznoj stanici, ali grane su suprotno usmerene, tj. od listova ka korenu. 
	
	Ova dva stabla su povezana preko središnjih stanica i za svaku središnju stanicu postoji tačno jedan put koji vodi od glavne polazne stanice do gravne dolazne stanice preko nje. Prema tome, broj različitih puteva jednak je broju središnjih stanica. Treba nekako da održavamo dužine puteva od glavne polazne stanice do svake središnje, i od svake središnje do glavne dolazne stanice. Ako srednje stanice smatramo zajedničkim listovima za dva stabla, ove udaljenosti su ustvari dubine listova u stablima.
	
	
	## Preprocesiranje grafa
	
	U ulazu nam nije dato koje stanice su južne, koje severne, a koje središnje, međutim, ovo možemo sami da zaključimo. 
	
	Svaka stanica koja ima više od jedne izlazne grane je južna stanica, a svaka stanica koja ima više od jedne ulazne grane je severna stanica. Ako krenemo **DFS** obilazak (pretragu u dubinu) od glavne polazne stanice, i ne prelazimo nijednu stanicu za koju već znamo da je severna, sve stanice do kojih nismo uspeli da dođemo su severne. Srednje stanice su one od preostalih stanica koje imaju tunel ka nekoj od severnih stanica. I na kraju kada smo našli severne i srednje stanice znamo i koje su južne.
	
	
	## Podzadaci kada je $Q = 1$ i $N, Q \leq 1000$
	
	Za svaki upit, pronađimo najkraći put od glavne polazne stanice do svake središnje stanice, i najkraći put od svake središnje stanice do glavne dolazne stanice. Ovo se može realizovati primenom Dijkstrinog algoritma dva puta, jednom počevši od glavne polazne stanice i drugi put iz glavne dolazne stanice, ali kada obrnemo smer svakog tunela. Kada za svaku središnju stanicu saberemo dve distance koje smo našli, lako možemo da odgovorimo na upit sortiranjem dobijenih vrednosti.
	
	
	## Podzadatak kada se sve promene vremena odnose na tunele koji kreću iz središnje stanice ili stižu u središnju stanicu
	
	Na početku možemo da nađemo dužine puteva od glavne polazne do glavne dolazne stanice preko svake središnje stanice. Svaka promena vremena menja tačno jedan od puteva. Treba nam način da brzo tražimo koja je $K$-ta najmanja dužina puta, podržavajući ove promene. Napravimo niz $C$ gde je $C_i$ broj puteva dužine $i$. Napravimo **Fenvikovo stablo** nad ovim nizom. Tako možemo u $O(logD)$ da promenimo vrednost niza $C$, i da nađemo koliko ima puteva ne dužih od $x$, gde je $D$ najveća dužina puta. Koristeći ovu strukturu možemo binarnom pretragom da nađemo dužinu $K$-tog puta. Kako dužine puteva mogu biti dosta velike, a biće manje od $N+Q$ različitih vrednosti dužina puteva, možemo da mapiramo ove vrednosti na interval $[1, d]$, gde je $d$ broj različitih dužina puteva, koristeći $std::map$ strukturu podataka.
	
	
	## Podzadatak kada postoji najviše $1000$ središnjih stanica
	
	Posmatrajmo na koje središnje stanice utiče promena vremena potrebnog da se prođe kroz neki tunel. Poređajmo središnje stanice u niz po njihovom rasporedu od istoka ka zapadu. Ako se promena odnosi na dve središnje stanice onda se ona odnosi i na sve središnje stanice između njih. Dakle, svaka promena se odnosi na neki podniz središnjih stanica. Za svaki tunel možemo naći na koji podniz utiče njegova promena ako pustimo **DFS** algoritam na severnom i južnom stablu. Sada u $O(S)$, gde je $S$ broj središnjih stanica, možemo da promenimo dužine puteva, a $K$-ti najkraći put možemo da nađemo u $O(SlogS)$ sortiranjem niza, ili u $O(S)$ primenom **quick select** algoritma.
	
	
	## Podzadatak kada se uvek traži samo prvi najkraći put
	
	Kao kod prošlog zadatka održavaćemo niz puteva poređanih od istoka ka zapadu po njihovim središnjim stanicama. Napravimo **segmentno stablo** nad ovim nizom. Koristeći **lazy propagation** tehniku na segmentnom stablu, možemo da podržimo upite dodavanja neke vrednosti na ceo podniz, i upite traženja minimuma na celom nizu. Vremenska složenost ovog rešenja je $O(N+QlogN)$.
	
	
	## Rešenje za 100 poena
	
	Umesto korišćenja segmentnog stabla, izdelimo niz u uzastopne blokove od $SQ$ puteva. Održavaćemo sortirane puteve u svakom bloku. Svaka promena dodaje neku vrednost na nekoliko celih blokova i na neki deo najviše još dva bloka. Primenimo **lazy propagation** na blokove tako da ne menjamo vrednosti svih puteva u bloku, već zapamtimo za koju vrednost treba promeniti ceo blok. Dva bloka koji se delom menjaju možemo ponovo da izgradimo, tako što ćemo promeniti dužine puteva koji se menjaju i spojiti deo bloka koji je promenjen sa delom bloka koji nije promenjen kao kod **merge sort**-a. Traženje $K$-tog najkraćeg puta možemo uraditi binarnom pretragom po dužini. Za neku dužinu možemo naći koliko postoji puteva ne dužih od te dužine ako prođemo kroz sve blokove i još jednom binarnom pretragom nađemo koliko takvih puteva postoji u svakom bloku. Vremenska složenost operacije promene je $O(\frac{N}{SQ} + SQ)$, a traženja rešenja $O(\frac{N}{SQ}logDlogSQ)$. Ako uzmemo da je $SQ = \sqrt{NlogNlogD}$, ukupna složenost ovog algoritma je $O(Q\sqrt{NlogNlogD})$.
	
	``` cpp title="06_metro.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxn 51000
	using namespace std;
	
	vector<pair<int,int> > a[maxn];
	vector<pair<int,int> > b[maxn];
	
	int cntu[maxn];
	int cntv[maxn];
	
	int bs;
	
	int si[maxn];
	int pos[maxn];
	
	bool posu[maxn];
	bool posv[maxn];
	
	bool sp[maxn];
	int lb[maxn];
	int rb[maxn];
	
	int paru[maxn];
	long long valu[maxn];
	int parv[maxn];
	long long valv[maxn];
	
	int arr[maxn];
	int parr1[maxn];
	int parr2[maxn];
	int ppermo1[maxn];
	int ppermo2[maxn];
	pair<int,int> marr[maxn];
	int permo[maxn];
	int ad[maxn];
	
	int ch[maxn];
	
	int t=0;
	int bc=0;
	
	vector<int> spec;
	
	void dfsu(int u) {
	    if(cntu[u]>1 || posu[u]) return;
	    posu[u]=true;
	    for(auto v:a[u]) dfsu(v.first);
	}
	
	void dfsv(int u) {
	    if(cntv[u]>1 || posv[u]) return;
	    posv[u]=true;
	    for(auto v:b[u]) dfsv(v.first);
	}
	
	void dfsfu(int u) {
	    if(sp[u]) {
	        si[u]=++t;
	        pos[t]=u;
	        lb[u]=rb[u]=si[u];
	        return;
	    }
	    lb[u]=maxn;
	    rb[u]=0;
	    for(auto v:a[u]) {
	        paru[v.first]=u;
	        valu[v.first]=valu[u]+v.second;
	        ch[u]++;
	        dfsfu(v.first);
	        lb[u]=min(lb[u],lb[v.first]);
	        rb[u]=max(rb[u],rb[v.first]);
	    }
	}
	
	void dfsfv(int u) {
	    if(sp[u]) {
	        lb[u]=rb[u]=si[u];
	        return;
	    }
	    lb[u]=maxn;
	    rb[u]=0;
	    for(auto v:b[u]) {
	        parv[v.first]=u;
	        valv[v.first]=valv[u]+v.second;
	        ch[u]++;
	        dfsfv(v.first);
	        lb[u]=min(lb[u],lb[v.first]);
	        rb[u]=max(rb[u],rb[v.first]);
	    }
	}
	int lg[maxn],rg[maxn];
	void process_block(int b,int l,int r,int diff) {
	    if(ad[b]) {
	        for(int j=lg[b];j<=rg[b];j++) arr[j]+=ad[b];
	        ad[b]=0;
	    }
	    int t1=0,t2=0;
	    for(int j=lg[b];j<=rg[b];j++) {
	        int rj=permo[j];
	        if(l<=rj && rj<=r) {
	            parr1[t1]=arr[j]+diff;
	            ppermo1[t1]=rj;
	            t1++;
	        }
	        else {
	            parr2[t2]=arr[j];
	            ppermo2[t2]=rj;
	            t2++;
	        }
	    }
	    int i1=0,i2=0;
	    int tr=0;
	    while(i1<t1 && i2<t2) {
	        if(parr1[i1]<parr2[i2]) {
	            arr[lg[b]+tr]=parr1[i1];
	            permo[lg[b]+tr]=ppermo1[i1];
	            i1++;
	        }
	        else {
	            arr[lg[b]+tr]=parr2[i2];
	            permo[lg[b]+tr]=ppermo2[i2];
	            i2++;
	        }
	        tr++;
	    }
	    while(i1<t1) {
	        arr[lg[b]+tr]=parr1[i1];
	        permo[lg[b]+tr]=ppermo1[i1];
	        i1++;
	        tr++;
	    }
	    while(i2<t2) {
	        arr[lg[b]+tr]=parr2[i2];
	        permo[lg[b]+tr]=ppermo2[i2];
	        i2++;
	        tr++;
	    }
	}
	void Resi(int N, int M, int *U, int *V, int *C, int Q, int *A, int *B, long long *R) {
	    for(int i=1;i<=M;i++) {
	        cntu[V[i]]++;
	        cntv[U[i]]++;
	        a[U[i]].push_back({V[i],C[i]});
	        b[V[i]].push_back({U[i],C[i]});
	    }
	    for(int i=1;i<=N;i++) sort(a[i].begin(),a[i].end()),sort(b[i].begin(),b[i].end());
	    dfsu(1);
	    dfsv(2);
	    for(int i=3;i<=N;i++) if(posu[i] && posv[i] && !posu[a[i][0].first]) sp[i]=true,spec.push_back(i);
	    dfsfu(1);
	    dfsfv(2);
	    for(int i=1;i<=t;i++) marr[i]={valu[pos[i]]+valv[pos[i]],i};
	    bs=(sqrt(t)*log(t)/log(2)+1);
	    bool ok=false;
	    for(int i=0;i*bs<t;i++) {
	        bc++;
	        lg[i]=i*bs+1;
	        rg[i]=min((i+1)*bs,t);
	        sort(marr+lg[i],marr+rg[i]+1);
	        for(int j=lg[i];j<=rg[i];j++) {
	            arr[j]=marr[j].first;
	            permo[j]=marr[j].second;
	        }
	    }
	    for(int i=1;i<=Q;i++) {
	        if(A[i]==-1) {
	            int l=0;
	            int r=5e8;
	            int k=B[i];
	            while(l<r) {
	                int m=(l+r)>>1;
	                int cnt=0;
	                for(int j=0;j<bc;j++) {
	                    int lb=lg[j];
	                    int rb=rg[j];
	                    while(lb<rb) {
	                        int mb=(lb+rb+1)>>1;
	                        if(arr[mb]+ad[j]<=m) lb=mb;
	                        else rb=mb-1;
	                    }
	                    while(lb>=lg[j] && arr[lb]+ad[j]>m) lb--;
	                    cnt+=(lb-lg[j]+1);
	                }
	                if(cnt>=k) r=m;
	                else l=m+1;
	            }
	            R[i]=l;
	        }
	        else {
	            int u=U[A[i]];
	            int v=V[A[i]];
	            int diff=B[i]-C[A[i]];
	            C[A[i]]=B[i];
	            int l,r;
	            if(u==paru[v] || u==parv[v]) l=lb[v],r=rb[v];
	            else l=lb[u],r=rb[u];
	            int b1=(l-1)/bs;
	            int b2=(r-1)/bs;
	            for(int j=b1+1;j<b2;j++) ad[j]+=diff;
	            process_block(b1,l,r,diff);
	            if(b1!=b2) process_block(b2,l,r,diff);
	        }
	    }
	}

	```
