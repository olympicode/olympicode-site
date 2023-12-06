---
hide:
  - toc
---

# A1 - Karibi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	Nekada davno, bilo je vreme programera koji nisu testirali svoje kodove, vreme Programera sa Kariba. Ovi programeri plovili su morem i sejali strah i nekvalitetne programe duž karipskih ostrva; za sobom su ostavljali uplakane korisnike, nezavršene aplikacije i članove posade koji bi koristili *C* umesto *C++*-a. Svaki brod koji bi im se suprotstavio, dobio bi floating point eksepšn i prestao bi da float...
	
	Popularno mesto za okupljanje Programera sa Kariba bilo je Karipsko ostrvo Tortuga. Zaliv ovog ostrva možemo predstaviti **binarnom matricom dimenzije $n \times m$ čije je svako polje kopno (označeno jedinicom) ili voda (označeno nulom)**. Programerski brodovi dolaze u raznim dužinama i ukoliko je dužina nekog broda $x$, to znači da taj brod zauzima tačno $x$ uzastopnih polja zaliva, bilo vertikalno ili horizontalno (širina broda je tačno jedno polje). Prema tome, **brod dužine $x$ se može parkirati u zaliv ako i samo ako postoji $x$ uzastopnih polja u istoj vrsti ili istoj koloni matrice zaliva pri čemu sva polja predstavljaju vodu i na nijednom od njih se ne nalazi deo nekog drugog broda.** U opštem slučaju, može postojati više načina za parkiranje.
	
	Jednog dana, u zaliv Tortuge stigao je programer Džek Vrabac na svom brodu *Black Perl* **dužine** $a$ i rešio da ga uparkira. Džek zna da posle njega u zaliv stiže programer Barbosa na svom brodu *Blue Pascal* **dužine** $b$, kao i da Barbosa najviše na svetu mrzi tri stvari: programera Džeka, debug mod i nedovoljno mesta za parkiranje broda. **Zato je Džek odlučio da parkira svoj brod tako da posle njegovog parkiranja bude najmanje moguće načina da se u zaliv uparkira Barbosin brod.** Kako je programer Džek poznat po tome što ne zna da programira, zatražio je pomoć od vas i kao nagradu neće vam hakovati računar.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se četiri prirodna broja $n$, $m$, $a$ i $b$, razdvojena razmakom, koja, redom, predstavljaju dimenzije zaliva, dužinu Džekovog broda i dužinu Barbosinog broda. Zatim sledi opis zaliva - u narednih $n$ redova nalazi se po $m$ karaktera (bez razmaka) od kojih je svaki '0' ili '1'.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati jedan prirodan broj - najmanji mogući broj načina za parkiranje Barbosinog broda nakon parkiranja Džekovog broda.
	
	## Primer 1
	### Ulaz
	```
	5 6 3 3
	110111
	000001
	000001
	111101
	100010
	```
	
	### Izlaz
	```
	2
	```
	
	## Primer 2
	### Ulaz
	```
	2 5 2 5
	00000
	00000
	```
	
	### Izlaz
	```
	0
	```
	
	## Objašnjenje primera
	U prvom test primeru su dužine Džekovog i Barbosinog broda po 3. Ukoliko Džek parkira svoj brod tako da zauzima polja (1,3)(2,3)(3,3), Barbosa će imati samo dva načina za parkiranje svog broda - (2,5)(3,5)(4,5) i (5,2)(5,3)(5,4) (vrste su numerisane odozgo nadole a kolone s leva udesno). Džek nikako ne može parkirati svoj brod tako da Barbosa ima manje od dva načina za parkiranje.
	
	## Ograničenja i podzadaci
	* $1 \leq a \leq max\{n,m\}$, $2 \leq b \leq max\{n,m\}$
	* Zaliv će biti takav da će postojati bar jedan način da Džek uparkira svoj brod.
	
	Postoje $5$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [11 poena]: $1 \leq n, m \leq 80$.
	* Podzadatak 2 [12 poena]: $n = 1$ i $1 \leq m \leq 2000$.
	* Podzadatak 3 [13 poena]: $a = 1$ i $1 \leq n, m \leq 2000$.
	* Podzadatak 4 [22 poena]: $1 \leq n, m \leq 500$.
	* Podzadatak 5 [42 poen]: $1 \leq n, m \leq 2000$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Miloš Purić | Ivan Stošić |
	
	Broj $A_{i,j}$ je jednak $1$ ako je na polju $(i,j)$ u zalivu kopno, a inače $0$.
	
	## Rešenje za $1 \leq N,M \leq 80$:
	Možemo za svako parking mesto Džekovog broda dužine $a$ sporo računati broj parking mesta za Barbosin brod dužine $b$ u tom slučaju, koristeći prefiskne sume pojedinačnih kolona i vrsta matrice $A$. Vremenska složenost: $O(N^2M^2)$, memorijska složenost: $O(NM)$.
	
	## Rešenje za $N=1$ i $1 \leq M \leq 2000$:
	Za ovaj podzadatak dovoljno je rešenje izloženo u prethodnom, ali je njega ovde moguće lakše implementirati zato što je $N=1$. Vremenska složenost: $O(M^2)$, memorijska složenost: $O(M^2)$.
	
	## Rešenje za $a=1$ i $1 \leq N,M \leq 2000$:
	Neka je $D_{i,j}^{b}$ jednako $1$ ako je $i+b-1 \leq N$ i $\sum_{k=i}^{i+b-1} A_{k,j} = 0$ (tj. ako su sva polja kolone $j$ od $(i,j)$ do $(i+b-1,j)$ pod vodom), a $0$ inače. Slično definišemo  i $R_{i,j}^{b}$ za polja $(i,j)$ i $(i,j+b-1)$. Analogno, mogu biti korisne i vrednosti $D_{i,j}^{a}$ i $R_{i,j}^{a}$ koje računamo na isti način, samo za brod dužine $a$. Ovi podaci nam omogućuju da proverimo da li je moguće uparkirati brod dužine $b$ ili $a$ u neko mesto, a možemo ih lako pronaći pomoću prefiksnih suma pojedinačnih kolona i vrsta matrice $A$. 
	
	Sada možemo da izračunamo broj $C_0$ - na koliko načina je moguće parkirati brod dužine $b$ u zalivu: $$C_0=\sum_{i=1}^{N} \sum_{j=1}^{M} D_{i,j}^{b}+R_{i,j}^{b}$$ 
	
	Pokušaćemo da brod dužine $a$ parkiramo sa početkom u svakom polju $(i,j)$ redom, i da izračunamo koliko smo pri tome blokirali mesta za parkiranje brodu dužine $b$. 
	
	Na primer, vertikalnim parkiranjem broda dužine $a$ od polja $(p,q)$ do polja $(p+a-1,q)$ (gde je $p+a-1 \leq N$) blokirali smo tačno $$V_{i,j}=(\sum_{i=p}^{p+a-1} \sum_{j=q-b+1}^{q} R_{i,j}^{b}) + (\sum_{i=p-b+1}^{p+a-1} D_{i,q}^{b})$$ parking mesta za brod dužine $b$. Pri tom se podrazumeva da ako je neka od granica u ovim sumama manja od $1$, sumu ćemo početi od $1$, odnosno ako je veća od indeksa najveće kolone ili vrste ($N$ ili $M$ u zavisnosti od toga da li se radi o granici za $i$ ili $j$), sumu ćemo završiti na odgovarajućem postojećem indeksu. Ova formula važi jer smo u stvari ovakvim parkiranjem broda dužine $a$, zauzeli sva mesta za brod dužine $b$ čiji se levi krajevi nalaze u podmatrici sa gornjim levim poljem $(p,q-b+1)$ i donjim desnim poljem $(p+a-1,q)$, kao i sva mesta čiji su gornji krajevi polja u $q$-toj koloni od $(p-b+1,q)$ do $(p+a-1,q)$.
	
	Na sličan način možemo pronaći izraz za broj blokiranih polja pri horizontalnom parkiranju broda dužine $a$ od polja $(p,q)$ do polja $(p,q+a-1)$ (gde je $q+a-1 \leq M$): 
	$$H_{i,j}=(\sum_{i=p-b+1}^{p} \sum_{j=q}^{q+a-1} D_{i,j}^{b}) + (\sum_{j=q-b+1}^{q+a-1} R_{p,j}^{b})$$
	
	U ovom slučaju, parking mesta koja zauzimamo su ona sa gornjim krajevima u podmatrici sa gornjim levim poljem $(p-b+1,q)$ i donjim desnim poljem $(p,q+a-1)$, kao i parking mesta čiji su levi krajevi u $p$-toj  vrsti od polja $(p,q-b+1)$ do polja $(p,q+a-1)$.
	
	U ovom podzadatku prve sume u izrazima za $V_{i,j}$ i $H_{i,j}$ se znatno pojednostavljuju jer je $a=1$, pa je moguće koristiti standardne prefiksne sume svake kolone i svake vrste matrica $R_{i,j}^{b}$ i $D_{i,j}^{b}$ za računanje vrednosti $V_{i,j}$ i $H_{i,j}$.
	
	Najmanji broj načina za parkiranje Barbosinog broda koji Džek Vrabac može da postigne dobijamo kao minimalnu vrednost koju uzima $\min(C_0-V_{i,j},C_0-H_{i,j})$ po svim poljima $(i,j)$ u zalivu. Vremenska složenost: $O(NM)$, memorijska složenost: $O(NM)$.
	
	## Rešenje za: $1 \leq N,M \leq 500$:
	U ovom podzadatku je zbog manjih dimenzija matrice moguće računanje $V_{i,j}$ i $H_{i,j}$ samo uz pomoć prefiksnih suma vrsta i kolona matrica $R_{i,j}^{b}$ i $D_{i,j}^{b}$. Na primer, u prvoj sumi u izrazu za $V_{i,j}$ ćemo za svaku vrstu od $p$ do $p+a-1$ korististi prefiksnu sumu te vrste u matrici $R_{i,j}^{b}$ da izračunamo  $\sum_{j=q-b+1}^{q} R_{i,j}^{b}$. Drugu sumu u izrazu za $V_{i,j}$ možemo i dalje računati sporim sabiranjem odgovarajućih vrednosti $D_{i,j}^{b}$. Vremenska složenost: $O(NM \cdot \max(N,M))$, memorijska složenost: $O(NM)$.
	
	## Glavno rešenje:
	Za dovoljno brzo računanje vrednosti $V_{i,j}$ i $H_{i,j}$ će nam biti potrebne dvodimenzionalne prefiksne sume matrica $R_{i,j}^{b}$ i $D_{i,j}^{b}$. Dvodimenzionalna prefiksna suma proizvoljne matrice $X$ je matrica $Y$ istih dimenzija za koju za svako njeno polje $(p,q)$ važi $Y_{p,q}=\sum_{i=1}^{i=p} \sum_{j=1}^{j=q} X_{i,j}$. Pomoću nje možemo u konstantnom  vremenu izračunati sumu brojeva u bilo kojoj podmatrici matrice $X$. Na primer, sumu brojeva u podmatrici matrice $X$ sa gornjim levim poljem $(p,q)$ i donjim desnim poljem $(r,s)$ nalazimo kao: $$\sum_{i=p}^{i=r} \sum_{j=q}^{j=s} X_{i,j}=Y_{r,s}-Y_{p-1,s}-Y_{r,q-1}+Y_{p-1,q-1}$$
	
	Ovo nam omogućava da u konstantnom vremenu nađemo vrednosti $V_{i,j}$ i $H_{i,j}$ za svako polje u zalivu. Minimalni broj mesta koji Džek može postići kao i pre dobijamo kao minimalnu vrednost koju uzima $\min(C_0-V_{i,j},C_0-H_{i,j})$ po svim poljima $(i,j)$.
	
	Vremenska složenost: $O(NM)$, memorijska složenost: $O(NM)$.
	
	``` cpp title="04_karibi.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	
	using namespace std;
	
	const int MAX_N = 2010;
	
	char s[MAX_N][MAX_N];
	int U[MAX_N][MAX_N], L[MAX_N][MAX_N], R[MAX_N][MAX_N], D[MAX_N][MAX_N];
	int currSum[MAX_N];
	
	// broj horizontalnih nacina za postavljanje koje zauzima brod na pozicijiama [i][j1]...[i][j2] brodu duzine d
	int H(int i, int j1, int j2, int d)
	{
		int l = j1 - L[i][j1] + 1;
		int r = j2 + R[i][j2] - d;
		if (r < l) return 0;
		int l1 = j1 - d + 1;
		int r1 = j2;
		return (std::min(r, r1) - std::max(l, l1) + 1);
	}
	// broj vertikalnih nacina za postavljanje koje zauzima brod na pozicijiama [i1][j]...[i2][j] brodu duzine d
	int V(int j, int i1, int i2, int d)
	{
		int l = i1 - U[i1][j] + 1;
		int r = i2 + D[i2][j] - d;
		if (r < l) return 0;
		int l1 = i1 - d + 1;
		int r1 = i2;
		return (std::min(r, r1) - std::max(l, l1) + 1);
	}
	
	int solve(int n, int m, int a, int b, char s[][MAX_N])
	{
		for (int i = 0; i <= n + 1; i++)
		{
			s[i][0] = '1';
			s[i][m + 1] = '1';
		}
		for (int j = 0; j <= m + 1; j++)
		{
			s[0][j] = '1';
			s[n + 1][j] = '1';
		}
	
		// racunanje U, L, R i D matrica
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				L[i][j] = U[i][j] = 0;
				if (s[i][j] == '0')
				{
					L[i][j] = 1 + L[i][j - 1];
					U[i][j] = 1 + U[i - 1][j];
				}
			}
		}
		for (int i = n + 1; i >= 1; i--)
		{
			for (int j = m + 1; j >= 1; j--)
			{
				R[i][j] = D[i][j] = 0;
				if (s[i][j] == '0')
				{
					R[i][j] = 1 + R[i][j + 1];
					D[i][j] = 1 + D[i + 1][j];
				}
			}
		}
	
		// racunanje ukupnog broja nacina da se postavi b-brod bez a-broda
		int totalNumOfWays = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (L[i][j] >= b) totalNumOfWays++;
				if (U[i][j] >= b) totalNumOfWays++;
			}
		}
	
		int maxReduction = 0;
		// proveri sve moguce horizontalne pozicije za a-brod
		for (int i = 1; i <= n; i++)
		{
			currSum[0] = 0;
			for (int j = 1; j <= m; j++)
			{
				if (s[i][j] == '0')
				{
					currSum[j] = currSum[j - 1] + V(j, i, i, b);
				}
				else
				{
					currSum[j] = 0;
				}
	
				if (L[i][j] >= a)
				{
					int currReduction = H(i, j - a + 1, j, b) + currSum[j] - currSum[j - a];
					if (currReduction > maxReduction)
					{
						maxReduction = currReduction;
					}
				}
			}
		}
		// proveri sve moguce vertikalne pozicije za a-brod
		for (int j = 1; j <= m; j++)
		{
			currSum[0] = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s[i][j] == '0')
				{
					currSum[i] = currSum[i - 1] + H(i, j, j, b);
				}
				else
				{
					currSum[i] = 0;
				}
	
				if (U[i][j] >= a)
				{
					int currReduction = V(j, i - a + 1, i, b) + currSum[i] - currSum[i - a];
					if (currReduction > maxReduction)
					{
						maxReduction = currReduction;
					}
				}
			}
		}
	
		return totalNumOfWays - maxReduction;
	}
	
	int main()
	{
		int n, m, a, b;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
		}
	
		int sol = solve(n, m, a, b, s);
		printf("%d\n", sol);
	
		return 0;
	}

	```
