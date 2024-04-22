---
hide:
  - toc
---

# A3 - Palindromska šetnja

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3000ms | 256MB |
	
	Bob voli šetnje. Ali ne bilo kakve! Bob isključivo voli palindromske šetnje.
	
	Graf u kojem Bob živi ima $N$ čvorova. Na početku nikoja dva čvora nisu povezana. Potrebno je izvršiti $Q$ upita dva tipa:
	
	* $1$ $u$ $v$ $c$ - Između čvorova $u$ i $v$ dodaje se grana sa karakterom $c$ napisanim na njoj.
	* $2$ $u$ $v$ - Potrebno je odogovoriti da li postoji **šetnja** između čvorova $u$ i $v$ tako da karakteri sa grana koje pripadaju šetnji formiraju palindrom. Palindrom je niz karaktera koji se čita isto sa obe strane, npr. "oko", "kajak", "ratar" itd. Šetnja između $u$ i $v$ je naizmenični niz čvorova i grana, koji počinje sa čvorom $u$, a završava se sa čvorom $v$. U toj šetnji se ista grana može ponoviti više puta. Ukoliko takva šetnja postoji, ispisati `1`, a u suportnom ispisati `0`.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalaze se celi brojevi $N$ i $Q$, koji redom predstavljaju broj čvorova i broj upita. U narednih $Q$ linija, nalaze se upiti u formatu opisanom u tekstu.
	
	## Opis izlaza
	Za svaki upit drugog tipa ispisati `1` ukoliko šetnja postoji i `0` ukoliko šetnja ne postoji.
	
	## Ograničenja
	
	*   $1 \leq N \leq 1.000$
	*   $1 \leq Q \leq 300.000$
	*   $1 \leq u \neq v \leq N$
	*   $c \in \{a,b,c,...,x,y,z\}$
	*   Garantuje se da će svaka dva čvora direktno biti povezana najviše jednom granom.
	
	## Podzadaci
	
	*   (9 poena): U svakom upitu $c$ = `a`
	*   (10 poena): U svakom upitu prvog tipa $v = u + 1$
	*   (32 poena): $N \leq 100$
	*   (49 poena): Bez dodatnih ograničenja
	
	## Primer
	
	### Ulaz
	
	```
	5 6
	1 1 2 a
	1 2 3 b
	2 1 3
	2 2 3
	1 3 4 a
	2 1 4
	```
	
	### Izlaz
	
	```
	0
	1
	1
	```
	
	### Objašnjenje

	* U prvom upitu tipa $2$ ne postoji šetnja između čvora $1$ i čvora $3$ takva da karakteri sa šetnje formiraju palindrom. 
	* U drugom upitu tipa $2$ postoji šetnja između čvora $2$ i čvora $3$ takva da karakteri sa šetnje formiraju palindrom. Ta šetnja je: $2 - 3$, a formirani palindrom je `b`.
	* U trećem upitu tipa $2$ postoji šetnja između čvora $3$ i čvora $4$ takva da karakteri sa šetnje formiraju palindrom. Ta šetnja je $1 - 2 - 3 - 4$, a formirani palindrom je `aba`.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Aleksa Milisavljević | nPavle Martinović |
	
	##  Rešenje kada je u svakom upitu $c$ = `a`
	
	U ovom podzadatku je svaka šetnja palindrom. Dovoljno je proveriti da li su dva čvora u istoj komponenti povezanosti.  Ovo možemo da postignemo tako što koristimo čuvamo kojoj komponenti pripada koji čvor. Svaki upit u kojem se granom povezuju dva čvora iz iste komponente ignorišemo. Kada se spajaju dva čvora iz različitih komponenti, dodajemo novu granu između njih i puštamo `bfs` u kojem sve čvorove do kojih je moguće stići do jednog iz ta dva stavljamo u istu komponentu. Ovo rešenje radi u složenosti $O(N^2 + Q)$. Za bolju složenost je potrebno koristiti adekvatnu strukturu, npr. `dsu (disjoint set union)`.
	
	##  Rešenje kada $N \leq 100$
	
	Da bi rešili ovaj podzadatak, moramo da primetimo par stvari. Posmatrajmo sledeću relaciju nad neuređenim parovima čvorova:
	
	* $(a,b)$ je u relaciji sa $(x,y)$ $\leftrightarrow$ moguće je stići palindromskom šetnjom od $a$ do $b$ akko je moguće stići palindromskom šetnjom od $x$ do $y$ .
	
	Primetimo da je ovo relacija ekvivalencije. Štaviše, primetimo da je u svakoj klasi ekivalencije u kojoj su palindromske šetnje bar jedan neuređen par oblika $(a,a)$ ili oblika $(a,b)$, gde postoji grana između $a$ i $b$. Dodavanjem grane između čvorova $u$ i $v$ sa karakterom $c$ stapa neke klase ekvivalencije u jednu. Posmatrajmo sve grane $(x,y)$ na kojima je napisan karakter $c$. Tada se stapaju tačno sledeće klase ekvivalencije:
	
	* $(x,u)$ i $(y,v)$ u jednu klasu ekvivalencije (jer ako je postoji palindromska šetnja između $x$ i $u$, tada postoji i palindromska šetnja između $y$ i $v$, npr produžavanjem prethodne granama $(x,y)$ i $(u,v)$).
	
	* $(x,v)$ i $(y,u)$ u jednu klasu ekvivalencije.
	
	Prema tome za svaku dodatu granu, možemo iterirati po svim prethodnim dodatim granama istog tipa i spajati odgovarajuće klase ekvivalencije. Ovo rešenje radi u vremenskoj složenosti $O(N^4 + N^2 \log N + Q \log N)$.
	
	## Rešenje bez dodatnih ograničenja
	
	Za ovaj podzadatak, neophodno je optimizovati prethodno rešenje. Možemo primetiti da nije neophodno iterirati kroz sve prethodne grane, već možemo da preskočimo grane koje bi formirale ciklus koji ne menja bipartitnost komponente povezanosti na istom karakteru. Formalno, pretpostavimo da dodajemo granu između $u$ i $v$ sa karakterom $c$. Tada, razlikujemo sledeće slučajeve:
	
	* $u$ i $v$ do sada nisu bili povezani u podgrafu koji je formiran granama sa karakterom $c$. Tada procesiramo ovu granu.
	* $u$ i $v$ jesu u istoj komponenti povezanosti i ta komponenta je bipartitna, ali dodavanjem nove grane, ta komponenta prestaje biti bipartitna. Tada procesiramo ovu granu.
	* U suprotnom ignorišemo dodavanje grane. Pažljivijom analizom klasa koje se stapaju u jednu iz rešenja prethodnog podzadatka se može videti da grana u ovom slučaju ne bi stopila nikoje dve klase ekvivalencije, niti bi uticala na neke naredne upite.
	
	Prema tome, za svaki karakter, grana koje treba da procesiramo ima $O(N)$ (zašto?). Ovo rešenje radi u složenosti $O(N^2 \cdot |\Sigma| \cdot \log N)$.
	
	
	
	``` cpp title="06_palindromska_setnja.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxn 1005
	#define maxt 700000
	#define maxc 27
	using namespace std;
	int n,q;
	int mp[maxn][maxn];
	int par[maxt];
	bool pc[maxt];
	int h[maxt];
	inline int get_par(int x) {
	    if(par[x]==x) return x;
	    par[x]=get_par(par[x]);
	    return par[x];
	}
	inline void merge(int x,int y) {
	    x=get_par(x);
	    y=get_par(y);
	    if(x==y) return;
	    if(h[x]<h[y]) {
	        par[x]=y;
	        pc[y]|=pc[x];
	    }
	    else {
	        if(h[y]<h[x]) {
	            par[y]=x;
	            pc[x]|=pc[y];
	        }
	        else {
	            par[y]=x;
	            pc[x]|=pc[y];
	            h[x]++;
	        }
	    }
	}
	int cnt=0;
	bool col[maxc][maxn];
	int incomp[maxc][maxn];
	vector<int> comps[maxc][maxn];
	bool nbp[maxc][maxn];
	vector<pair<int,int> > relevant[maxc];
	inline bool path(int u,int v) {
	    return pc[get_par(mp[u][v])];
	}
	int tot[maxc];
	inline void add_edge(int u,int v,int c) {
	    pc[get_par(mp[u][v])]=true;
	    bool ok=false;
	    int cu=incomp[c][u];
	    int cv=incomp[c][v];
	    if(cu!=cv) {
	        ok=true;
	        int x;
	        if(col[c][u]!=col[c][v]) x=0;
	        else x=1;
	        if(comps[c][cv].size()<comps[c][cu].size()) swap(cu,cv);
	        for(auto w:comps[c][cu]) {
	            incomp[c][w]=cv;
	            comps[c][cv].push_back(w);
	            tot[c]++;
	            col[c][w]^=x;
	        }
	        nbp[c][cv]|=nbp[c][cu];
	    }
	    else {
	        if(col[c][u]==col[c][v]) {
	            if(!nbp[c][cu]) ok=true;
	            nbp[c][cu]=true;
	        }
	    }
	    if(ok) {
	        for(auto pr:relevant[c]) {
	            int x=pr.first;
	            int y=pr.second;
	            merge(mp[x][u],mp[y][v]);
	            merge(mp[x][v],mp[y][u]);
	        }
	        relevant[c].push_back({u,v});
	    }
	}
	int main() {
	    ios::sync_with_stdio(false); cin.tie(0);
	    cin>>n>>q;
	    for(int u=1;u<=n;u++) {
	        for(int v=u;v<=n;v++) {
	            par[cnt]=cnt;
	            if(u==v) pc[cnt]=true;
	            mp[u][v]=cnt++;
	            mp[v][u]=mp[u][v];
	        }
	        for(int j=0;j<26;j++) {
	            incomp[j][u]=u;
	            comps[j][u].push_back(u);
	        }
	    }
	    for(int i=0;i<q;i++) {
	        int t;
	        cin>>t;
	        if(t==1) {
	            int u,v;
	            char c;
	            cin>>u>>v>>c;
	            add_edge(u,v,c-'a');
	        }
	        else {
	            int u,v;
	            cin>>u>>v;
	            if(path(u,v)) cout<<1<<endl;
	            else cout<<0<<endl;
	        }
	    }
	    return 0;
	}

	```
