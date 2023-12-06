---
hide:
  - toc
---

# 3 - Tetke

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3000ms | 192MB |
	
	U ključnom momentu, kada je trebalo da se pripreme zadaci za SIO, $N$ članova Komisije je shvatilo da moraju pod hitno da odnesu lek svojim tetkama. Poznato je da se kuća svake tetke nalazi na nekom od polja matrice $A \times B$, kao i da ne postoji polje na kome su dve kuće.
	
	Kako bi ubedili Potpredsednika Komisije da je njihovo odsustvo opravdano, svi članovi su redom javno objavili na kom polju se nalazi kuća njihove tetke, kao i na kojoj je nadmorskoj visini. Potpredsednik nije od juče, i pažljivo beleži sve što čuje. Pored toga, iako ne zna nadmorske visine svih polja u matrici, on zna da je apsolutna razlika nadmorske visine svaka dva susedna polja u matrici **tačno 1** (polja su susedna ako dele stranicu). Imajući to u vidu, on nakon objave svakog člana proba da rekonstruiše celu matricu, tj. da dodeli **svakom** polju neku nadmorsku visinu, kako bi se uverio da su sve objave bile istinite (ova rekonstrukcija ne mora nužno biti jedinstvena).
	
	Ako nakon objave nekog člana, Potpredsenik po prvi put ne može da odredi visinu svakog polja tako da bude u skladu sa svim dosadašnjim objavama (tj. ne postoji matrica konzistentna sa svim dosadašnjim objavama), jasno je da je taj član lupio glupost. Vaš zadatak je da pronađete prvog člana Komisije koji je lupio glupost.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se tri prirodna broja $N$, $A$ i $B$ --
	broj članova komisije tj. broj kuća, broj redova matrice i broj kolona matrice. U svakom od narednih $N$ redova nalaze se tri prirodna broja $R_i$, $C_i$ i $H_i$ koji označavaju red, kolonu i nadmorsku visinu kuće u kojoj živi tetka $i$-tog člana Komisije.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati jedan prirodan broj koji predstavlja indeks člana Komisije koji je lupio glupost (članovi su indeksirani počevši od broja $1$). Ukoliko takav član ne postoji, ispisati "bravo komisijo" (bez navodnika).
	
	## Primer 1
	### Ulaz
	```
	4 3 5
	1 2 1
	2 1 3
	2 5 21
	2 2 8
	```
	
	### Izlaz
	```
	3
	```
	
	## Primer 2
	### Ulaz
	```
	5 6 5
	1 1 5
	4 2 3
	4 5 6
	5 2 2
	1 3 5
	```
	
	### Izlaz
	```
	bravo komisijo
	```
	
	## Objašnjenje primera
	U prvom primeru, nakon prve dve objave moguće je odrediti visinu za svako polje tako da se ispoštuju uslovi, npr:
	
	```
	2 1 2 3 4
	3 2 3 4 3
	4 3 4 5 4
	```
	
	Nakon treće objave, ne postoji način da se to uradi, pa je treći član Komisije lupio glupost.
	
	U drugom primeru, postoji raspored visina koji se uklapa sa svih pet objava, npr:
	
	```
	5 4 5 6 7 8
	4 5 6 7 6 7
	3 4 5 6 5 6
	4 3 4 5 6 5
	3 2 3 4 5 4
	```
	
	## Ograničenja i podzadaci
	* $1 \leq A, B \leq 10^9$
	* $1 \leq N \leq 10^5$
	* Za svako $H_i$ važi $1 \leq H_i \leq 10^8$
	
	Postoji $5$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [11 poena]: $B = 1$.
	* Podzadatak 2 [11 poena]: $N \leq 1000$.
	* Podzadatak 3 [16 poena]: Za svako $H_i$ važi $1 \leq H_i \leq 10$.
	* Podzadatak 4 [28 poena]: $A, B \leq 800$.
	* Podzadatak 5 [34 poena]: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Jovanović | Nikola Milosavljević | Nikola Milosavljević |
	
	Označimo sa dist(i,j) menhetn rastojanje izmedju i-tog i j-tog polja a sa h[i] visinu i-tog polja.
	
	Lema: Skup od n polja sa visinama u matrici je konzistentan (u smislu da postoji opisana matrica koja sadrži ova polja) ako i samo ako važe sledeća dva uslova
	(1) Svi parni h[i]-ovi su na poljima čiji je zbir koordinata paran, a svi neparni h[i]-ovi na poljima čiji je zbir koordinata neparan ili obrnuto
	(2) Za svaka dva polja i i j vazi |h[i] - h[j]| <= dist(i,j)
	
	Ovo su očigledno potrebni uslovi, dok je za obrnut smer dovoljno pokazati da ako ovi uslovi važe, tada za bilo koje polje (x,y) postoji vrednost h koju možemo upisati u njega tako da ova dva uslova važe i za novi skup polja sa ovim poljem (to bi značilo da mozemo da popunimo celu matricu i da važe ova dva uslova, ali onda je ta matrica ok na osnovu primene tih uslova na susedna polja). Ideja dokaza je: u novo poolje (označimo ga sa n+1) možemo upisati konzistentnu vrednost (u smislu (2)) akko je pesek svih segmenata (na realnoj pravoj) [h[i] - dist(i,n+1), h[i] + dist(i,n+1)] neparazn (tada upisujemo odgovarajuću vrednost iz preseka vodeći računa i o (1)) a ovo se pokazuje koristeći već pretpostavljene uslove za prvih n polja i nejednakost trougla.
	
	Uslov (1) se može trivijalno proveravati nezavisno od uslova (2) pa se koncentrišemo isključivo na uslov (2). Nazovimo par polja (i, j) “loš” ukoliko ne zadovoljava uslov (2) tj. ukoliko važi
	() |h[i] - h[j]| > |x[i] - x[j]| + |y[i] - y[j]|
	Koristeći oznake
	Vpp(i) = L[i] + x[i] + y[i], Vpm(i) = h[i] + x[i] - y[i], Vmp(i) = h[i] - x[i] + y[i], Vmm(i) = h[i] - x[i] - y[i]
	možemo se osloboditi apsolutnih vrednosti iz () razlikovanjem slučajeva. Tačnije, važi:
	
	Za polje i postoji polje j za koje je (i,j) loš par ako i samo ako je tačno bar jedno od sledećih tvrđenja
	
	j je “gore-levo” od i i važi Vmm(i) > Vmm(j)
	j je “gore-levo” od i i važi Vpp(i) < Vpp(j)
	… (ukupno 8 slučaja koja zavise od položaja gore/dole-levo/desno i odnosa h[i] i h[j])
	Ovo možemo rešavati 2D segmentnim stablom - za svako novo polje postavljamo 8 upita “vrati min/max iz date 2D oblasti” i ubacujemo ga u strukturu posle upita. Međutim, ovde je problem memorijsko ograničenje - čak i implicitno (dinamičko) stablo uz kompresiju koordinata zauzima n * log^2(n) memorije što je praktično nemoguće uklopiti u zadata ograničenja.
	
	Bolji pristup je korišćenje binarne pretrage po rešenju - tada problem postaje “da li postoji loš par među prvih m polja” i više nije bitno da vratimo najmanji indeks tj. da na prethodne upite odgovaramo redom. Koristimo “offline” pristup - sortiramo sva polja npr. po y-koordinati a zatim ih redom ubacujemo u obično segmentno stablo (indeksirano po x-koordinatama) uz upite “min/max na segmentu” (potrebno je 2 puta proći kroz stablo, po jednom u svakom smeru). Vremenska složenost ovog pristupa je O(n * log^2(n)) a memorijska je O(n) i nosi maksimalan broj poena.
	
	Podzadaci uključuju slučajeve kada prolazi rešenje složenosti O(n^2) (što je jedan od načina za “proveru” leme za vreme takmičenja), 1D slučaj (novo polje je dovoljno uporediti sa njegovim susedima), slučajeve u kojima su visine polja mali brojevi (na osnovu (*) za svako polje je dovoljno proveriti samo ona koja su na rastojanju ne većem od MaxH a njih ima O(MaxH^2)) kao i slučaj gde prolazi 2D segmentno.
	
	``` cpp title="03_tetke.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 100005
	#define MAXH 100000005
	#define INF 2110000000
	#define mid (l+r)/2
	using namespace std;
	
	struct house
	{
	    int r, c;
	    int h;
	    int newc;
	    int idx;
	};
	
	int N, A, B;
	house a[MAXN];
	
	// indeks onog koji kvari parnost, N+1 ako su svi ok
	int ParityCheck() 
	{
	    int val = (a[1].h + a[1].r + a[1].c) % 2;
	    for(int i = 1; i <= N; i++)
	    {
	        if((a[i].h + a[i].r + a[i].c) % 2 != val)
	        {
	            return i;
	        }
	    }
	    return N+1;
	}
	
	bool ManhattanCheck(const house &a, const house &b) 
	{
	    int dist = abs(a.r - b.r) + abs(a.c - b.c);
	    return dist >= abs(a.h - b.h);
	}
	
	
	struct VS
	{
	    int v1, v2, v3, v4;
	};
	// Node template
	struct node
	{
	    bool NULLNODE;
	    VS minv;
	    VS maxv;
	    node(){ NULLNODE = false; }
	    node(bool nullNode) {NULLNODE = nullNode;}
	    void print()
	    {
	        cout<<"MIN: ["<<minv.v1<<", "<<minv.v2<<", "<<minv.v3<<", "<<minv.v4<<"]"<<endl;
	        cout<<"MAX: ["<<maxv.v1<<", "<<maxv.v2<<", "<<maxv.v3<<", "<<maxv.v4<<"]"<<endl;
	    }
	};
	
	struct seg3
	{
	
	    // Merging function
	    node segMerge(node a, node b)
	    {
	        // RMinQ
	        if(a.NULLNODE) return b;
	        if(b.NULLNODE) return a;
	        node ret;
	        ret.minv.v1 = min(a.minv.v1, b.minv.v1);
	        ret.minv.v2 = min(a.minv.v2, b.minv.v2);
	        ret.minv.v3 = min(a.minv.v3, b.minv.v3);
	        ret.minv.v4 = min(a.minv.v4, b.minv.v4);
	        ret.maxv.v1 = max(a.maxv.v1, b.maxv.v1);
	        ret.maxv.v2 = max(a.maxv.v2, b.maxv.v2);
	        ret.maxv.v3 = max(a.maxv.v3, b.maxv.v3);
	        ret.maxv.v4 = max(a.maxv.v4, b.maxv.v4);
	        return ret;
	    }
	
	    // Original array, segment tree
	    node seg[MAXN*4];
	
	    // Build
	    void init(int idx, int l, int r)
	    {
	        if(l == r)
	        {
	            // Leaf node
	            seg[idx].minv.v1 = seg[idx].minv.v2 = 
	            seg[idx].minv.v3 = seg[idx].minv.v4 = INF;
	            seg[idx].maxv.v1 = seg[idx].maxv.v2 = 
	            seg[idx].maxv.v3 = seg[idx].maxv.v4 = -INF;
	            return;
	        }
	        init(2*idx, l, mid);
	        init(2*idx+1, mid+1, r);
	        seg[idx] = segMerge(seg[2*idx], seg[2*idx+1]);
	    }
	
	    // a[qi] = v
	    void update(int qi, node v, int idx, int l, int r)
	    {
	        if(l == r)
	        {
	            // Leaf node
	            seg[idx] = v;
	            return;
	        }
	        if(qi <= mid) update(qi, v, 2*idx, l, mid);
	        else update(qi, v, 2*idx+1, mid+1, r);
	        seg[idx] = segMerge(seg[2*idx], seg[2*idx+1]);
	    }
	
	    // max & min[lq..rq]?
	    node query(int lq, int rq, int idx, int l, int r)
	    {
	        if(lq <= l && rq >= r)
	        {
	            // Canonic cover
	            return seg[idx];
	        }
	        node ret(true);
	        if(lq <= mid) ret = segMerge(ret, query(lq, rq, 2*idx, l, mid));
	        if(rq > mid) ret = segMerge(ret, query(lq, rq, 2*idx+1, mid+1, r));
	        return ret;
	    }
	};
	
	const bool operator<(const house& a, const house& b) 
	{
	    if(a.r == b.r)
	    {
	        return a.c < b.c;
	    }
	    return a.r < b.r;
	}
	
	bool cmpc(house a, house b)
	{
	    if(a.c == b.c)
	    {
	        return a.r < b.r;
	    }
	    return a.c < b.c;
	}
	
	seg3 seg;
	
	int scaling_cols = 0;
	
	bool IsValid(int k)
	{
	    // take first k
	    vector<house> houses(a+1, a+k+1);
	    sort(houses.begin(), houses.end());
	    seg.init(1, 1, scaling_cols);
	    for(house& H : houses) 
	    {
	        // build me
	        node me;
	        me.minv.v1 = H.h - H.r - H.c;
	        me.minv.v2 = H.h - H.r + H.c;
	        me.minv.v3 = H.h + H.r - H.c;
	        me.minv.v4 = H.h + H.r + H.c;
	        me.maxv = me.minv;
	        // do queries
	        node lres = seg.query(1, H.newc, 1, 1, scaling_cols);
	        node rres = seg.query(H.newc, scaling_cols, 1, 1, scaling_cols);
	        // query, use minv for me always
	        // DIRECT LEFT V1
	        // DIRECT RIGHT V2
	        if(me.minv.v1 > lres.minv.v1 || me.minv.v2 > rres.minv.v2)
	        {
	            return false;
	        }
	        // INDIRECT LEFT V3
	        // INDIRECT RIGHT V4
	        if(lres.maxv.v4 > me.minv.v4 || rres.maxv.v3 > me.minv.v3)
	        {
	            return false;
	        }
	        // update
	        seg.update(H.newc, me, 1, 1, scaling_cols);
	    }
	    return true;
	}
	
	bool cmpidx(house a, house b)
	{
	    return a.idx < b.idx;
	}
	
	int main() 
	{
	    scanf("%d %d %d", &N, &A, &B);
	    for(int i = 1; i <= N; i++)
	    {
	        scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].h);
	        a[i].idx = i;
	    }
	    sort(a+1, a+N+1, cmpc);
	    a[1].newc = 1;
	    for(int i = 2; i <= N; i++)
	    {
	        if(a[i].c == a[i-1].c)
	        {
	            a[i].newc = a[i-1].newc;
	        } else {
	            a[i].newc = a[i-1].newc + 1; 
	        }
	    }
	    scaling_cols = a[N].newc;
	    sort(a+1, a+N+1, cmpidx);
	
	    // Scale
	    // Dp
	    int pidx = ParityCheck();
	    int midx = N+1;
	    int hi = N, lo = 2, pivot;
	    while(hi > lo)
	    {
	        pivot = (hi + lo) / 2;
	        bool valid = IsValid(pivot);
	        if(valid)
	        {
	            lo = pivot + 1;
	        }
	        else
	        {
	            hi = pivot;
	        }
	    }
	    if(!IsValid(hi))
	    {
	        midx = hi;
	    }
	    int sol = min(pidx, midx);
	    if(sol == N+1)
	    {
	        printf("bravo komisijo\n");
	    }
	    else
	    {
	        printf("%d\n", sol);
	    }
	    return 0;
	}

	```
