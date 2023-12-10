---
hide:
  - toc
---

# B3 - Miniranje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 128MB |
	
	Mali Danilo treba da se nađe sa svojim najboljim drugom, ali zbog silnih radova u gradu to mu predstavlja problem. Srećom, Danilo uvek nosi par mina sa sobom koje može da iskoristi da stigne do svog druga.
	
	Stanje grada se može opisati matricom, gde je svako polje slobodno ili blokirano radovima. U svakom trenutku Danilo može da pređe sa polja na kom se nalazi na susedna slobodna polja, gde su susedna polja u matrici ona polja koja su neposredno iznad, ispod, levo ili desno od trenutnog polja.
	
	Danilo sme da postavi minu samo na polje koje mu je dostižno.  Nakon eksplozije prve mine, pod uslovom da mu je ostalo još mina, Danilo može da postavi sledeću minu na sva polja do koja su mu tada dostižna (moguće je da se skup dostižnih polja proširio nakon eksplozije prve mine).
	
	Ali Danilo je zaboravio snagu svojih mina. Pomozite mu da nađe minimalnu snagu mina $K$ koja mu je potrebna da bi stigao do svog druga.
	
	Snaga mina određuje veličinu njene eksplozije. Mina snage $K$ oslobađa sva polja u pravougaoniku veličine $(2K+1)*(2K+1)$, sa centrom u istom polju gde je mina postavljena.
	
	Na primer, ako se postavi mina u sredini leve matrice snage $K = 1$, polja koja je eksplozija obuhvatila su označena sa `O` i ta polja će na dalje biti prohodna.
	
	~~~
	X....      X....
	XXXXX      XOOOX
	X..X. ---> XOOO. 
	...X.      .OOO.
	XX..X      XX..X
	~~~
	
	Nađi minimalnu potrebnu snagu mina, $K$, da bi bilo moguće da Danilo postavi mine na neki način tako da stigne do svog druga.
	
	## Opis ulaza
	
	U prvom redu nalaze se dva broja $N$, koji predstavlja dužine stranice matrice, i $M$, broj mina koji je Danilo poneo sa sobom. Narednih $N$ redova predstavlja stanje grada.
	
	Slobodna polja su označena karakterom `.` , a blokirana polja sa `X`. Danilo se nalazi na polju označenim sa `A`, a njegov drug na polju označenim sa `B`. Ta dva polja su slobodna.
	
	## Opis izlaza
	
	Ispisati prirodan broj $K$ koji predstavlja minimalnu jačinu mina potrebnu da Danilo stigne do njegovog druga. Ako nije potrebno koristiti mine uopšte, ispisati -1.
	
	## Primer 1
	
	### Ulaz
	
	~~~
	6 1
	A.XX..
	..XX..
	XXXX..
	..XX..
	..XX..
	..XX.B
	
	~~~
	
	### Izlaz
	
	~~~
	2
	~~~
	
	## Primer 2
	
	### Ulaz
	
	~~~
	7 2
	AXXXXXX
	XXXXXXX
	XXXXXXX
	XXXXXXX
	XXXXXXX
	XXXXXXX
	XXXXXXB
	
	~~~
	
	### Izlaz
	
	~~~
	3
	~~~
	
	## Objašnjenje primera
	
	U prvom primeru, Danilo može da postavi minu na polje $(2,2)$ ili $(2,1)$ jačine $K = 2$ da bi napravio put do svog druga.
	
	U drugom primeru, Danilo može samo da stavi minu na svoju poziciju. Stanje matrice nakon prve eksplozije minom snage $K = 3$ na polje $(1,1)$:
	
	~~~
	....XXX
	....XXX
	....XXX
	....XXX
	XXXXXXX
	XXXXXXX
	XXXXXXB
	~~~
	
	Sad Danilo jedino može da postavi svoju poslednju minu na polje $(4,4)$ da bi otvorio put do svog druga.
	
	## Ograničenja
	* $2 \leq N \leq 500$
	* $1 \leq M \leq 2$
	
	Postoje tri podzadatka:
	
	* Podzadatak 1 [31 poena]: $M = 1$.
	* Podzadatak 2 [32 poena]: $N \leq 50$.
	* Podzadatak 3 [37 poena]: Nema dodatnih ograničenja.
	
	
	## Napomena
	
	Danilo i njegov drug su otporni na eksplozije.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Nenad Bauk | Dimitrije Erdeljan | Dušan Zdravković |
	
	## Analiza
	
	Ako je minama snage $K$ moguće doći do cilja, očito je moguće na isti
	način i sa snagom $K+1$. Samim tim, minimalno $K$ možemo naći binarnom
	pretragom "po rešenju". Za ovo nam je potreban algoritam kojim ćemo
	odrediti da li, za fiksno $K$, možemo stići od polaznog do ciljnog
	polja.
	
	Ako postavimo minu na neko polje i time oslobodimo kvadrat dimenzija
	$2K+1 \times 2K+1$, nakon što izađemo iz tog kvadrata nema razloga da
	se vraćamo u njega (u suprotnom, možemo "preskočiti" deo puta od
	izlaska do povratka). Zbog ovoga, mine možemo posmatrati kao
	"teleport" uređaje, koji omogućavaju da se prebacimo na proizvoljno
	polje na rastojanju ne većem od $K$ (koje može biti i zauzeto).
	
	Dakle, naš put od polaznog do ciljnog polja će imati sledeći oblik:
	
	* krećemo se slobodnim poljima do mesta gde postavljamo prvu minu,
	* "preskočimo" na polje, možda zauzeto, na rastojanju ne većem od $K$,
	* dalje se krećemo slobodnim poljima do mesta za drugu minu,
	* opet "preskočimo", i
	* krećemo se do cilja slobodnim poljima.
	
	Polja do kojih možemo stići u prvom koraku možemo naći pretragom u
	dubinu ili širinu od početnog polja. Zatim markiramo sva polja na
	rastojanju ne većem od $K$ od nekog od pronađenih, i pokrenemo novu
	pretragu od svih markiranih polja (za treći korak). Ovu proceduru
	ponovimo još jednom za drugu minu i kretanje posle nje. Ako je na kraju
	ovaj algoritam našao put do cilja, moguće je doći do cilja sa minama
	snage $K$.
	
	Ukupna složenost jedne provere (za fiksno $K$) je $\mathcal{O}(N^2)$
	(tri pretrage i dva prolaska kroz matricu), a kako nam za binarnu
	pretragu treba $\log{N}$ provera, složenost algoritma je
	$\mathcal{O}(N^2 \log{N})$.
	
	## Smernice za algoritam
	
	Pri implementaciji algoritma, treba voditi računa o koraku gde
	markiramo sva polja na rastojanju ne većem od $K$ od skupa polja do kojih
	već imamo put. Ovo ne možemo raditi tako što za svako svakog polje do
	kog znamo put obeležimo njegovo okruženje, jer je složenost ovoga
	$\mathcal{O}(N^2 K^2)$, tj. u najgorem slučaju (za $K=N$)
	$\mathcal{O}(N^4)$.
	
	Ovaj deo programa je moguće implementirati na više načina. Jedna
	mogućnost je da pokrenemo pretragu u širinu od svih polja do kojih
	imamo put (paralelno), koju prekidamo kada dođemo na rastojanje $K$
	(obratite pažnju da ova pretraga ne uzima u obzir "blokiranost" polja i
	da rastojanje moramo gledati odvojeno za vertikalno i horizontalno
	kretanje).
	
	Druga mogućnost je da izračunamo matricu prefiksnih suma na matrici
	"da li imamo put do ovog polja" (gde polja imaju vrednost $1$ ako imamo
	put do njih, a inače $0$). Pomoću ove matrice možemo u $\mathcal{O}(1)$
	odrediti koliko polja do kojih imamo put postoji u kvadratu $2K+1
	\times 2K+1$ centriranom na proizvoljnom polju, tj. da li je do njega
	moguće "skočiti".
	
	``` cpp title="03_miniranje.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	const int MAXN = 1010;
	const short INF = 10000;
	
	typedef pair<short,short> pii;
	
	int N, M;
	
	vector<vector<bool> > A(MAXN, vector<bool>(MAXN, 1));
	vector<vector<bool> > EMPTY(MAXN, vector<bool>(MAXN, 1));
	
	int AI,AJ,BI,BJ;
	
	vector<pii> BASIC_NEIGHBOURS = {{0,-1}, {0,1}, {-1,0}, {1,0}};
	vector<pii> BOMB_NEIGHBOURS = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	
	bool foundB = false;
	
	vector<pii > GetAllAdjacentCells(vector<vector<bool> > &mat, vector<pii> &sources, vector<pii> &neigh, short max_dist)
	{
	    foundB = false;
	    vector<vector<short> > visited(MAXN, vector<short>(MAXN, INF));
	    vector<pii> neighbours;
	
	    queue<pii> Q;
	    queue<short> COST;
	
	    for (pii source: sources)
	    {
	        // cout << "Source " << source.first << ' ' << source.second << endl;
	        Q.push(source);
	        COST.push(0);
	    }
	
	    while (!Q.empty())
	    {
	        pii x = Q.front();
	        Q.pop();
	
	        short cur_cost = COST.front();
	        COST.pop();
	
	        short cur_i = x.first, cur_j = x.second;
	
	        // cout << "Cur: " << cur_i << ' ' << cur_j << endl;
	
	        if ((cur_cost > 0 && mat[cur_i][cur_j]) || cur_cost >= visited[cur_i][cur_j] || cur_cost > max_dist)
	            continue;
	
	        // cout << "PASSED" << endl;
	
	        visited[cur_i][cur_j] = cur_cost;
	        neighbours.push_back(make_pair(cur_i, cur_j));
	
	        for (auto delta : neigh)
	        {
	            // int ti = cur_i + delta.first, tj = cur_j + delta.second;
	            Q.push(make_pair(cur_i + delta.first, cur_j + delta.second));            
	            COST.push(cur_cost + 1);
	        }
	
	        foundB = (visited[BI][BJ] < INF);
	    }
	
	    return neighbours;
	}
	
	void printA(vector<vector<int> > &mat, string fname)
	{
	    ofstream f;
	    f.open(fname);
	
	    for (int i = 0; i <= N+1;i++)
	    {
	        for (int j = 0; j <= N+1;j++)
	        {   
	            char c;
	            if (mat[i][j] == 0)
	                c = '.';
	            if (mat[i][j] == 1)
	                c = 'X';
	            if (mat[i][j] == 2)
	                c = ',';
	            
	            f << c;
	        }
	        f << endl;
	    }
	    f.close();
	}
	
	inline bool ValidInds(int i, int j)
	{
	    return (1 <= i) && (i <= N) && (1 <= j) && (j <= N);
	}
	
	int ExplodeMine(vector<vector<int> > &arr, int i, int j, int K)
	{
	    assert(K >= 0);
	
	    for (int ti = max(1, i - K); ti <= min(N, i + K); ti++)
	    for (int tj = max(1, j - K); tj <= min(N, j + K); tj++)
	        arr[ti][tj] = 0;
	}
	vector<pii> adj_A;
	
	bool solve(short K)
	{
	    
	    // Get all cells after first explosion.
	    vector<pii> cur_adj = GetAllAdjacentCells(EMPTY, adj_A, BOMB_NEIGHBOURS, K);
	    cur_adj = GetAllAdjacentCells(A, cur_adj, BASIC_NEIGHBOURS, INF);
	
	    if (M == 2)
	    {
	        cur_adj = GetAllAdjacentCells(EMPTY, cur_adj, BOMB_NEIGHBOURS, K);
	        cur_adj = GetAllAdjacentCells(A, cur_adj, BASIC_NEIGHBOURS, INF);
	    }
	
	    return foundB;
	}
	
	short bin()
	{
	    short lo = 0, hi = N;
	
	    while (lo < hi)
	    {
	        short mid = (lo + hi) / 2;
	    
	        if (solve(mid))
	            hi = mid;
	        else
	            lo = mid + 1;
	    }
	
	    return lo;    
	}
	
	
	int main()
	{
	    // Read input.
	    cin >> N >> M;
	    string s;
	    char c;
	    for (int i = 1; i <= N; i++)
	    {
	        cin >> s;
	
	        for (int j = 1; j <= N; j++)
	        {
	            c = s[j - 1];
	
	            if (c == 'A')
	            {
	                AI = i; AJ = j;
	                A[i][j] = 0;
	            }
	            else if (c == 'B')
	            {
	                BI = i; BJ = j;
	                A[i][j] = 0;
	            }
	            else if (c == 'X')
	                A[i][j] = 1;
	            else
	                A[i][j] = 0;
	
	            // Fill empty matrix.
	            EMPTY[i][j] = 0;
	            
	        }
	    }
	
	    // First find all adjacent cells from A without any mines.
	    vector<pii> A_as_source  = {{AI, AJ}};
	    adj_A = GetAllAdjacentCells(A, A_as_source, BASIC_NEIGHBOURS, INF);
	
	    if (foundB)
	    {
	        // No need for any mines.
	        cout << -1 << endl;
	        return 0;
	    }
	
	
	    // printA(A);
	
	    cout << bin() << endl;
	
	
	
	}
	
	
	
	
	
	

	```
