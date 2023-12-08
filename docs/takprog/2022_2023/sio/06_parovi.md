---
hide:
  - toc
---

# 6 - Parovi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Dat je povezan neusmeren težinski graf od $N$ čvorova i $M$ grana, i prirodan broj $K$. Grane su numerisane od $1$ do $M$, gde $i$-ta grana ima težinu $\lceil \frac{i}{K} \rceil$.
	
	Označimo sa $f(x, y)$, gde je $1 \leq x < y \leq N$, odgovor na sledeći upit:
	
	* Među svim minimalnim razapinjućim stablima datog grafa, naći ono sa najvećom vrednosti zbira stepena čvorova $x$ i $y$, i vratiti tu vrednost.
	
	Izračunajte $\sum\limits_{x=1}^N \sum\limits_{y=x+1}^N f(x, y)$, tj. sumu vrednosti $f(x, y)$ za sve $1 \leq x < y \leq N$. 
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $Resi(N, M, K, U[\dots], V[\dots])$
	
	Funkcija $Resi$ se poziva samo jednom na početku ivršavanja programa, a njeni parametri su:
	
	* $N$: broj čvorova u grafu.
	* $M$: broj grana u grafu.
	* $K$: parametar koji označava da $i$-ta grana ima težinu $\lceil \frac{i}{K} \rceil$.
	* $U[\dots]$, $V[\dots]$: nizovi dužine $M$, **indeksirani od 1**, koji opisuju grane: $i$-ta grana spaja čvorove $U_i$ i $V_i$.
	
	Funkcija $Resi$ treba da vrati jedan ceo broj - vrednost $\sum\limits_{x=1}^N \sum\limits_{y=x+1}^N f(x, y)$.
	
	## Primer
	Neka je $N=4$, $M=4$, $K=2$, $U = [1, 3, 4, 2]$, $V = [2, 4, 1, 3]$. U ovom grafu su grane $1-2$ i $3-4$ težine $1$, a grane $4-1$ i $2-3$ težine $2$. Ovaj graf ima dva moguća minimalna razapinjuća stabla - jedno sa granama $1-2$, $3-4$ i $1 - 4$, drugo sa granama $1 - 2$, $3 - 4$, $2 - 3$. 
	
	U prvom stablu čvorovi  $1$ i $4$ imaju stepen $2$, a $2$ i  $3$ stepen $1$. U drugom stablu čvorovi  $1$ i $4$ imaju stepen $1$, a $2$ i  $3$ stepen $2$. Ako za svaki par uzmemo bolje od data dva stabla, dobijamo vrednosti $f(1, 2) = 3$, $f(1, 3)  = 3$, $f(1, 4) = 4$, $f(2, 3) = 4$, $f(2, 4) = 3$, $f(3, 4) = 3$, pa je broj koji funkcija $Resi$ treba da vrati jednak $3+3+4+4+3+3=20$.
	
	## Ograničenja
	
	* $1 \leq N \leq 100.000$
	* $1 \leq M \leq 200.000$
	* $1 \leq K \leq 100$
	*   $1 \leq u_i, v_i \leq N$ i $u_i \neq v_i$ za $1 \leq i \leq M$
	* Dati graf je povezan.
	
	## Podzadaci
	
	*  **[5 poena]:** $M \leq 18$
	*  **[11 poena]:** $N \leq 50, M = K$
	*  **[12 poena]:** $N \leq 100, M \leq 200$
	*  **[14 poena]:** $K \leq 6$
	*  **[16 poena]:** $N \leq 1.000, M \leq 2.000$
	*  **[42 poena]:** Bez dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl  `parovi.cpp`  koji implementira pomenutu funkciju. Osim traženih funkcija, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`long long Resi(int N, int M, int K, int* U, int* V);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojevi $N$, $M$ i $K$.
	-   U narednih $M$ redova brojevi $A_i$ i $B_i$.
	
	Zatim ovaj program zove vašu funkciju i ispisuje rezultate koje ona vrati.
	
	## Napomena
	Razapinjuće stablo povezanog težinskog neusmerenog grafa je težinsko stablo (povezan acikličan neusmeren graf) koje sadrži sve čvorove i čije se sve grane sadrže i u početnom grafu.
	
	Minimalno razapinjuće stablo je bilo koje razapinjuće stablo sa minimalnom sumom težina grana.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Jovan Bengin | Jovan Bengin | Momčilo Tošić | Jovan Bengin |
	
	## Rešenje kad $M \leq 18$
	U ovom slučaju možemo isprobati svako razapinjujuće stablo (biranjem svakog podskupa grana), naći sva minimalna i za svaki par čvorova (kojih isto ima malo jer je graf povezan) naći i dodati rešenje. 
	Tada je složenost $O(N^2 2^M)$
	
	## Rešenje kad $M = K, N \leq 50$
	Uočimo da će težina svake grane biti 1. Dakle, MST je svako razapinjujuće stablo, a kako je i broj čvorova manji, možemo da izračunamo rešenje za svaki par na tzv. pohlepan način.
	Ovde je potrebno uraditi analizu slučajeva, prebrojimo sve čvorove sa direktnim vezama do ona dva koje posmatramo, oduzimajući one koji su zajednički (s tim da se s jednim
	mogu oba povezati ukoliko ne postoji grana između njih).
	Složenost će biti $O(N^2(N+M))$.
	
	## Rešenje kad je $N \leq 100, M \leq 200$
	Možemo ponovo rešavati za svaka dva čvora, s tim što puštamo simulaciju nalaženja MST sa optimalnim biranjem grana tako da se maksimizuju one koje uključuju neki od dva odabrana čvora.
	Složenost je u ovom slučaju $O(N^2 M\log{M})$.
	
	## Rešenje kad $K \leq 6$
	Za ovo rešenje potrebno je preći na drugačiji način prebrojavanja (koji se koristi i u celon rešenju) - grupišemo grane sa jednakim težinama (kažemo da je čvor u grupi ako
	postoji grana u grupi koja ga sadrži) i brojimo koliko puta grane
	iz date grupe "figurišu" u konačnom zbiru (dakle bar jedan od selektovanih čvorova je neki iz grupe).
	Pošto Kruskalov algoritam dodaje grane u sortiranom redosledu, možemo računati da kada posmatramo grupu težine $W$ su čvorovi već povezani
	u komponente koje formiraju grane težina ispod $W$. Da bi se formirao MST svakako se u njega dodaje neki podskup novih grana, a kako je broj $K$ mali,
	možemo ručno probati svaki podskup i videti koliko grane doprinose zbiru (za svaka dva čvora koja se pojavljuju u grupi kao krajevi veza). Kako ima $\frac{M}{K}$ grupa,
	a $O(K)$ i čvorova i grana u grupi, složenost je $O(2^K MK)$.
	
	## Rešenje za pun broj poena
	Moguće je izvršiti prebrojavanje pojavljivanja grana u maks stepeninma čvorova iz grupe i brže, tako da ne postoji dodatni faktor osim kvadratnog po $K$. Posmatrajmo
	veze čvorova iz grupe sa već formiranim komponentama.
	Fiksiramo 2 čvora u grupi i za njih dodajemo broj komponenti s kojima su povezani, oduzimajući broj s kojim su oba povezana, sa obraćanjem pažnje na specijalne
	slučajeve (neki od dva čvora povezan je sa komponentom od ovog drugog, u istoj su komponenti, ili postoji direktna veza između dva selektovana čvora).
	Ovde se radi nešto donekle slično kao u drugom podzadatku, s tim što je (uslovno rečeno) tada jedina grupa bio skup svih čvorova, sada treba dodati i doprinos grana u 
	trenutnoj grupi na zbir stepena kad selektovan par uključuje jedan čvor koji se ne pojavljuje u grupi, mada ovo se računa samo kao broj komponenti s kojim je povezan
	onaj čvor koji jeste u grupi (naravno onoliko puta koliko ima čvorova van grupe). Nakon ovog procesa, ažuriramo komponente i prelazimo na narednu grupu.
	Ukupna složenost je (istim rezonom kao i pre) $O(MK)$.
	
	``` cpp title="06_parovi.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	using ll = long long;
	using ld = long double;
	
	#define pb push_back
	#define si(x) int(x.size())
	#define all(x) x.begin(), x.end()
	#define fi first
	#define se second
	
	const int N = 200000;
	
	struct DSU{
	    int n;
	    int par[N+5], sz[N+5];
	    void init(int _n){
	        n = _n;
	        for(int i=1; i<=n; i++){
	            par[i] = i;
	            sz[i] = 1;
	        }
	    }
	    int root(int x){
	        return x == par[x] ? x : par[x] = root(par[x]);
	    }
	    void unite(int u, int v){
	        u = root(u), v = root(v);
	        if(u == v) return;
	        if(sz[u] < sz[v]) swap(u, v);
	        sz[u] += sz[v];
	        par[v] = par[u];
	    }
	} dsu;
	
	int n, m;
	
	vector <int> gc[N+5];
	vector <int> gn[N+5];
	pair <int, int> e[N+5];
	
	int shares[N+5];
	bool has_edge[N+5];
	int ima_c[N+5], ima_n[N+5];
	bool bitan[N+5];
	
	ll solve(int l, int r){
	    vector <int> nodes, comps;
	    for(int i=l; i<=r; i++){
	        int u = e[i].fi, v = e[i].se;
	        int u1 = dsu.root(u), v1 = dsu.root(v);
	        if(u1 == v1) continue;
	        nodes.pb(u);
	        nodes.pb(v);
	        comps.pb(u1);
	        comps.pb(v1);
	        gc[u].pb(v1);
	        gc[v].pb(u1);
	        gn[u1].pb(v);
	        gn[v1].pb(u);
	    }
	    sort(all(nodes));
	    sort(all(comps));
	    nodes.erase(unique(all(nodes)), nodes.end());
	    comps.erase(unique(all(comps)), comps.end());
	    for(auto u : nodes){
	        bitan[u] = 1;
	        sort(all(gc[u]));
	        gc[u].erase(unique(all(gc[u])), gc[u].end());
	    }
	    for(auto cm : comps){
	        sort(all(gn[cm]));
	        gn[cm].erase(unique(all(gn[cm])), gn[cm].end());
	    }
	    ll res = 0;
	    for(int i=0; i<si(nodes); i++){
	        int u = nodes[i];
	        for(auto cm : gc[u]){
	            ima_c[cm] = 1;
	            for(auto c : gn[cm]) shares[c]++;
	        }
	        for(auto c : gn[dsu.root(u)]){
	            ima_n[c] = 1;
	        }
	        res += 1LL*(n - si(nodes))*si(gc[u]);
	        for(int j=l; j<=r; j++){
	            if(e[j].fi == u && bitan[e[j].se]) has_edge[e[j].se] = 1;
	            if(e[j].se == u && bitan[e[j].fi]) has_edge[e[j].fi] = 1;
	        }
	        for(int j=i+1; j<si(nodes); j++){
	            int v = nodes[j];
	            res += si(gc[u]) + si(gc[v]) - shares[v];
	            if(has_edge[v] || dsu.root(u) == dsu.root(v)){
	                continue;
	            }
	            res -= ima_n[v] + ima_c[dsu.root(v)];
	            if(ima_n[v] || ima_c[dsu.root(v)] || shares[v]) res++;
	        }
	        for(auto c : nodes){
	            shares[c] = 0;
	            has_edge[c] = 0;
	            ima_n[c] = 0;
	        }
	        for(auto c : comps){
	            ima_c[c] = 0;
	        }
	    }
	    for(auto c : nodes){
	        bitan[c] = 0;
	        gc[c].clear();
	    }
	    for(auto c : comps) gn[c].clear();
	    for(int i=l; i<=r; i++){
	        dsu.unite(e[i].fi, e[i].se);
	    }
	    return res;
	}
	
	long long Resi(int _n, int _m, int _k, int *U, int *V){
	    int k;
	    n = _n, m = _m, k = _k;
	    for(int i=1; i<=m; i++){
	        e[i].fi = U[i], e[i].se = V[i];
	    }
	    dsu.init(n);
	    ll res = 0;
	    for(int i=1; i<=m; i+=k){
	        res += solve(i, min(m, i + k - 1));
	    }
	    return res;
	}
	```
