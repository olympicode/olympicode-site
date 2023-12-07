---
hide:
  - toc
---

# 2 - Šašavo odelo

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 512MB |
	
	
	
	Drva su jako interesantna živa vrsta. Uprkos tome šta su vam pričali na časovima biologije, ona zapravo su samo kolekcije $N$ tačaka i $N-1$ duži između parova njih, tako da krećući se samo po parovima tačaka spojenih dužima je moguće stići od svake tačke do svake druge.
	
	Ono što vas isto nisu naučili na časovima biologije je da drva imaju jako razvijen smisao za modu. Stabla se oblače tako što svakoj njihovoj tački pripiše jedan **pozitivan ceo broj** broj (njihov ekvivalent boja). Kroz istoriju različita bojenja su bila popularna počevši od tradicionalnih monohromatskih do današnjih "retro" crno-belih (ono što mi čitamo kao $1$-$2$).
	
	Međutim, naš heroj, Mirko, je jedno jako kreativno i nekonvencijalno drvo. Stoga, on želi da započne novi trend u svetu drvene mode i da svakoj tački dodeli neki broj, tako da **ako je nekoj tački dodelio broj $x$, onda je ta tačka dužima povezana sa tačno $x$ tačaka kojima nije dodelio $x$ (i moguće još nekima kojima jeste dodelio $x$)**. Mirko je sasvim siguran da će promeniti svet drvene mode zauvek, ako uspe da dizajnira svoje odelo. Da bi to uradio potrebna mu je vaša pomoć.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Oboji(N, U[\ldots], V[\ldots], C[\ldots])$
	
	gde je $N$  broj koji predstavlja broj tačaka koji ima Mirko,  nizovi $U$ i $V$, dužine $N-1$ predstavljaju da postoji duž između tačaka $U[i]$ i $V[i]$.  U niz $C$ dužine $N$ treba da upišete vrednosti brojeva koje Mirko treba da dodeli tačkama, ili da ceo niz bude jednak $-1$ ukoliko to nije moguće. **Svi nizovi su indeksirani od 1.**
	## Primer
	
	Neka je $N=4$, i neka su nizovi $U=\{1,1,1\}$ i $V=\{2,3,4\}$:
	Tada je moguće izabrati $C=\{3,1,1,1\}$, jer je tada tačka $1$ boje $3$ spojena sa tri tačke boje $1$, što opravdava njegovu boju, dok su svi ostali boje $1$ i spojeni su samo sa jednom tačkom, koja je pri tome različite boje.
	
	Neka je $N=4$, i neka su nizovi $U=\{1,2,3\}$ i $V=\{2,3,4\}$:
	Tada rešenje ne postoji i treba izabrati $C=\{-1,-1,-1,-1\}$.
	
	## Ograničenja
	
	-   $1 \leq N \leq 300.000$
	-   $1 \leq U_i,V_i \leq N$
	-    Garantuje se da je drvo
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[6 poena]:** Svaka tačka je povezana sa najviše dve druge tačke.
	-   **[9 poena]:** $N\leq20$
	-   **[24 poena]:** $N\leq500$
	-   **[16 poena]:** $N\leq3000$
	-   **[12 poena]:** Svaka tačka je povezana sa najviše $10$ drugih tačaka.
	-   **[33 poena]:** Nema dodatnih ograničenja
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `sasavo_odelo.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Oboji(int N, int* U, int* V, int* C);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu broj $N$.
	* U narednih $N$ redova po $2$ broja. U $i$-tom redu nalaze se brojevi $U_i, V_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa $N$ brojeva koje predstavljaju bojenje koje vrati funkcija.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Lazar Milenković | Aleksa Plavšić |
	
	
	## Rešenja nekih potproblema
	
	Najpre ćemo početi sa nekoliko potproblema koji ne vode nužno ka finalnom rešenju.
	
	### Svaka tačka je povezana sa najviše dve druge tačke.
	
	Nije teško videti da je ovo stablo zapravo prost put. Pošto svaki čvor ima najviše dva suseda, boje koje dolaze u obzir su samo 1 ili 2. Znamo da oba kraja puta moraju imati boju 1, pa nije toliko teško razmotriti sve slučajeve za ostale brojeve u zavisnosti od dužine puta [Pomoć 1].
	
	### $N\leq20$
	
	Ovaj potproblem moguće je rešiti jednostavnim bektrek algoritmom. Za svaki čvor isprobamo sve mogućnosti za njegove boje. Probajte dokazati da je ukupna složenost ovakve implementacije odozgo ograničena proizvodom stepeni čvorova i da ovaj proizvod nikada ne premašuje $2^20$ [Pomoć 2].
	
	## Rešenja potproblema korišćenjem dinamičkog programiranja
	
	Ideja je računati matricu dinamičkog programiranja gde su moguća stanja označena sa $dp[r][i][c]$. Prva dimenzija $r \in \{0, 1\}$ označava nulom da roditelja nije potrebno bojiti istom bojom, a jedinicom da je roditelja potrebno obojiti istom bojom. Druga dimenzija $1 \le i \le N$ označava čvor koji se trenutno razmatra, dok na kraju treća dimenzija $1 \le c \le N$ označava boju koja se trenutno razmatra. Vrednosti u matrici biće 0 ukoliko je konfiguracija izvodljiva i 1 ukoliko nije. Pretpostavićemo da je stablo ukorenjeno u nekom čvoru (recimo čvoru $1$) i obilazićemo stablo rekurzivno, tako da se $dp$ vrednost čvora računa nakon $dp$ vrednosti njegovih naslednika. Ukoliko je stablo moguće obojiti vrednost $dp[0][1][c]$ biće 1 za neku od boja $c$.
	
	### $N\leq500$
	
	Za svaki čvor $i$ i svaku boju $c$, prolazimo po svim naslednicima čvora i proveravamo za svakog od njih da li ga je moguće obojiti u $c$ (ovaj tip naslednika zovemo <em>istobojni</em> naslednici za boju $c$), da li ga je moguće obojiti u neku drugu boju (ovaj tip naslednika zovemo <em>raznobojni</em> naslednik za boju $c$), kao i da li ga je moguće obojiti u istu i u različitu boju (ovaj tip naslednika zovemo <em>šareni</em> naslednik za boju $c$). Na osnovu broja istobojnih, raznobojnih i šarenih naslednika, moguće je utvriditi $dp[0][i][c]$, kao i $dp[1][i][c]$.
	
	### $N\leq3000$
	
	Malo pažljivija implementacija računanja $dp$ tabele dovoljna je za sve poene na ovom potproblemu. Naime, za svaki čvor $i$, prolazimo po svim bojama $c$ i po svim susedima. Ukupna složenost je $\sum_{1 \le i \le N} \deg(i)^2 = O(N^2)$. Probajte videti zašto [Pomoć 3].
	
	### Svaka tačka je povezana sa najviše $10$ drugih tačaka.
	
	Primetimo da najveća boja koju bilo koji čvor može imati nije nikada veća od njegovog stepena. Ukoliko znamo da najveći stepen nikada ne premašuje 10, tada treća dimenzija $dp$ tabele ima najviše 10 kolona. Rešenje iz prethodnog potproblema sada radi u složenosti $N \cdot d^2$, gde je $d \le 10$ najveći stepen u stablu.
	
	### Rešenje za sve poene
	
	Ideja iz prethodnog potproblema biće korisna i u ovom potproblemu. Ukoliko za svaki čvor $i$ napravimo treću kolonu $dp$ tabele da bude veličine $\deg(i)$, tada će ukupna veličina ove matrice uvek biti linearna po $N$. Takođe, primetimo da za svaki čvor možemo odrediti da li će biti istobojni, raznobojni ili šareni naslednik za boju $c$ odmah nakon što smo izračunali sve vrednosti njegove $dp$ tabele. Pretpostavimo da svaki čvor sadrži informaciju o broju naslednika svakog od tri moguća tipa za svaku od mogućih boja. Kada za neki čvor odredimo kog je on tipa, jednostavno možemo ažurirati brojač njegovog roditelja u stablu za svaku boju $c$. Na taj način, roditelj može u konstantnoj vremenskoj složenosti odrediti za svaku od boja koliko ima naslednika kog tipa pa samim tim i koja je $dp$ vrednost za tu boju.
	
	### Još jedno interesantno rešenje
	
	Primetićemo da boje koje su moguće za svaki čvor jesu samo one od $1$ do $\sqrt{N}$, kao i od $N - \sqrt{N}$ do $N$. Pažljivo implementirano rešenje potproblema kada je stepen najviše $10$ i korišćenje ove ideje bilo je dovoljno za sve poene na ovom zadatku.
	
	
	
	
	
	[Pomoć 1]: Posmatrajte deljivost sa 3.
	
	[Pomoć 2]: Koristite nejednakost između aritmetičke i geometrijske sredine.
	
	[Pomoć 3]: Koliki je zbir stepenova svih čvorova?
	
	[Pomoć 4]: Šta se dešava ako važi da boja nekog čvora nije u tom opsegu? Koliko on ima istobojnih naslednika i koliko oni ukupno imaju istobojnih naslednika?
	
	``` cpp title="02_sasavo_odelo.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 300007
	using namespace std;
	vector<int> g[MAXN];
	vector<int> dp[2][MAXN];
	bool op[MAXN];
	int k[MAXN],co[MAXN];
	bool cmp(int x,int y) {return g[x].size()<g[y].size();}
	void dfs(int s,int p)
	{
	    if(g[s].size()==1 && s!=p) {dp[1][s][1]=true; op[s]=true; k[s]=1; return;}
		int deg=g[s].size();
		vector<int> v;
		for(int i=0;i<deg;i++) if(g[s][i]!=p) {dfs(g[s][i],s); v.push_back(g[s][i]);}
		sort(v.begin(),v.end(),cmp);
		int t=0;
		bool fas=false;
		for(int i=1;i<=deg;i++)
		{
			int a=0,b=0,c=0;
			while(t<v.size() && g[v[t]].size()<i) {if(!op[v[t]]) fas=true; t++;}
			if(fas)
			{
				for(int j=i;j<=deg;j++) dp[0][s][j]=dp[1][s][j]=false;
				break;
			}
			b=t;
			for(int j=t;j<v.size();j++)
			{
				bool gr=dp[0][v[j]][i],d=(op[v[j]] && k[v[j]]!=i);
				if(gr && d) c++;
				if(!gr && d) b++;
				if(gr && !d) a++;
			}
			if(a+b+c==v.size())
			{
				if(b+c>=i && a+c>=(int)v.size()-i) dp[0][s][i]=true;
				if(b+c>=i-1 && a+c>=(int)v.size()+1-i) dp[1][s][i]=true;
			}
		}
		for(int i=1;i<=deg;i++) if(dp[1][s][i])
		{
			if(op[s]) k[s]=-1;
			else {op[s]=true; k[s]=i;}
		}
	}
	void reconstruct(int s,int p,int x,int y)
	{
		co[s]=x;
		vector<int> a,b,c,v;
		int deg=g[s].size();
		for(int i=0;i<deg;i++) if(g[s][i]!=p) v.push_back(g[s][i]);
		for(int j=0;j<v.size();j++)
		{
			bool gr=(x<dp[0][v[j]].size() && dp[0][v[j]][x]),d=(op[v[j]] && k[v[j]]!=x);
			if(gr && d) c.push_back(v[j]);
			if(!gr && d) b.push_back(v[j]);
			if(gr && !d) a.push_back(v[j]);
		}
		for(int i=0;i<a.size();i++) reconstruct(a[i],s,x,x);
		for(int i=0;i<b.size();i++)
		{
			int color;
			for(int j=1;j<=g[b[i]].size();j++) if(dp[1][b[i]][j] && j!=x) color=j;
			reconstruct(b[i],s,color,color-1);
			y--;
		}
		for(int i=0;i<c.size();i++)
		{
			if(!y) reconstruct(c[i],s,x,x);
			else
			{
				int color;
				for(int j=1;j<=g[c[i]].size();j++) if(dp[1][c[i]][j] && j!=x) color=j;
				reconstruct(c[i],s,color,color-1);
				y--;
			}
		 }
	}
	void Oboji(int N,int* U,int* V,int* C)
	{
		for(int i=1;i<=N-1;i++) g[U[i]].push_back(V[i]);
		for(int i=1;i<=N-1;i++) g[V[i]].push_back(U[i]);
		for(int i=1;i<=N;i++) for(int j=0;j<g[i].size()+1;j++) dp[0][i].push_back(false);
		for(int i=1;i<=N;i++) for(int j=0;j<g[i].size()+1;j++) dp[1][i].push_back(false);
		dfs(1,1);
		for(int i=1;i<=g[1].size();i++) if(dp[0][1][i])
		{
			reconstruct(1,1,i,i);
			for(int i=1;i<=N;i++) C[i]=co[i];
			return;
		}
		for(int i=1;i<=N;i++) C[i]=-1;
	}

	```
