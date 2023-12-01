---
hide:
  - toc
---

# A1 - Pelikani

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Sa početkom proleća, pelikani iz Afrike doleću u krajeve Srbije sa idealnim klimatskim uslovima. Omiljeno mesto za okuljanje im je veliko kvadratno jezero dimenzija $N\times N$ metara.
	
	Možemo zamisliti da je jezero izdeljeno na $N\times N$ kvadratnih polja površine $1m^2$. Sa $(i, j)$ ćemo označavati polje koje je $i$-to po redu u odnosu na severnu (gornju) stranu i $j$-to po redu u odnosu na istočnu (levu) stranu jezera (npr. $(1, 1)$ je gornje-levo a $N$, $1$ donje-levo polje). **U svakom trenutku se na proizvoljnom polju može nalaziti najviše jedan pelikan.**
	
	Takođe sa početkom proleća, na jezero dolaze šetači koji bacaju mrvice bajatog hleba (omiljena hrana pelikana) u jezero. Kada se u nekom trenutku pojavi šetač na nekoj od $4$ obale jezera (istok, zapad, sever ili jug), **svi pelikani krenu istom brzinom ka toj obali u pravcu normale na tu obalu** (npr. ako se šetač pojavi na severu, svi pelikani se kreću isključivo u pravcu severa tj. “nagore”; slično i za ostale strane sveta) **sve dok ne dođu do same obale ili do nekog od pelikana ispred njih** tj. “sabiju” se ispred odgovarajuće obale (videti objašnjenje test primera). Ukoliko se posle toga pojavi novi šetač, oni **iz trenutne pozicije** ponaljaju kretanje u pravcu nove obale itd.
	
	Poznat je početni raspored pelikana u jezeru i pozanto je da se, redom, dešavalo $Q$ događaja jednog od sledeća $2$ tipa:
	
	* `1 i` – pojavio se šetač na obali $i$ ($1$ – severna, $2$ – zapadna, $3$ – južna, $4$ – istočna) i pelikani su promenili svoje pozicije na prethodno opisan način;
	* `2 i j` – konstatovano je da li se u datom trenutku na polju $(i, j)$ nalazi neki pelikan ili ne.
	
	**Ispisati odgovor na sve događaje tipa $2$.**
	
	## Ulaz
	U prvom redu standardnog ulaza nalazi se prirodan broj $N$ – dimenzija jezera. U narednih $N$ redova nalazi se po jedan string dužine $N$ sastavljen isključivo od nula i jedinica – $j$-ti karakter $i$-tog stringa je $1$ ukoliko se na početku na polju $(i, j)$ nalazi pelikan, a $0$ inače.  U narednom redu nalazi se broj $Q$ – broj događaja. U narednih $Q$ redova nalaze se opisi događaja u gore pomenutom obliku u redosledu kojim su se dogodili.
	
	## Izlaz
	Za svaki događaj tipa $2$ ispisati u posebnom redu (i u redosledu datim na ulazu) odgovarajući odgovor – `1`, ukoliko se u tom trenutku na datom polju nalazi neki pelikan, odnosno `0` u suprotnom.
	
	## Primer 1
	### Ulaz
	```
	5
	00000
	01000
	11000
	01010
	00000
	6
	2 5 2
	1 3
	2 5 2
	2 3 2
	1 4
	2 5 2
	```
	
	### Izlaz
	```
	0
	1
	1
	0
	```
	
	## Objašnjenje primera
	Imamo $5$ pelikana u jezeru dimenzija $5\times 5$ i $6$ događaja. Za prvi događaj tipa $2$ odgovor je $0$ jer nema pelikana na polju $(5, 2)$. Zatim se pojavljuje šetač na južnoj obali i svi pelikani idu “nadole” – pelikani sa polja $(3, 1)$, $(2, 2)$, $(3, 2)$, $(4, 2)$ i $(4, 4)$ prelaze, redom, na polja $(5, 1)$, $(3, 2)$, $(4, 2)$, $(5, 2)$ i $(5, 4)$ i jasno je da na poljima $(5, 2)$ i $(3, 2)$ ima pelikana. Zatim se pojavljuje šetač na istočnoj obali; posle nove promene pozicija, pelikani zauzimaju polja $(5, 3)$, $(3, 5)$, $(4, 5)$, $(5, 4)$ i $(5, 5)$, pa je polje $(5, 2)$ prazno.
	
	## Ograničenja
	
	* $1\leq N\leq 1.000$.
	* $1\leq Q\leq 300.000$.
	* U svakom upitu `1 i` je $1\leq i\leq 4$, a u svakom upitu `2 i j` je $1\leq i, j\leq N$.
	
	Test primeri su podeljeni u tri disjunktne grupe:
	
	* U test primerima vrednim $20$ poena važi $n, m, Q\leq 100$.
	* U test primerima vrednim $40$ poena važi $Q\leq 30.000$.
	* U test primerima vrednim $40$ poena nema dodatnih ograničenja.
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Bogdan Petrović | Nepoznato |
	
	## Prvi podzadatak:
	Zbog malih ograničenja prvi podzadatak možemo rešiti simuliranjem događaja tipa $1$. To se najjednostavnije radi tako što izbrojimo koliko pelikana ima u svakom redu ako se šetač pojavio na istočnoj ili zapadnoj obali, tj. izbrojimo koliko pelikana ima u svakoj koloni ako se šetač pojavio na severnoj ili južnoj obali. Nakon toga samo popunimo matricu shodno izbrojanim vrednostima. Na događaje tipa $2$ odgovaramo jednostavnom proverom vrednosti matrice na toj poziciji.
	Vremenska složenost je $O(QN^2)$, a memorijska $O(N^2)$.
	
	## Drugi podzadatak:
	Drugi podzadatak je unapređenje tehnike prvog podzadatka. Posmatrajmo broj pelikana u svakom redu i u svakoj koloni. Primetimo da operacija tipa $1$ menja broj pelikana ili u redovima ili u kolonama, ne može da promeni oba. Prema tome, dovoljno je izračunati samo kako se redovi ili kolone menjaju na sledeći način:
	Pretpostavimo da šetač dolazi sa severne strane, ostali slučajevi se analogno rešavaju.
	Broj pelikana za svaku kolonu ostaje isti. Kako svi pelikani idu u redove koji su manjeg indeksa, broj pelikana u redu sa indeksom $i$ posle dolaska šetača jednak je broju kolona koje imaju $\geq i$ pelikana. To se u složenosti $O(N)$ može izračunati korišćenjem tehnike dva pokazivača.
	Na događaje tipa $2$ odgovaramo tako što pamtimo na kojoj strani se pojavio poslenji šetač i proveravamo za traženo polje u odgovarajućem redu ili koloni.
	Vremenska složenost je $O(QN)$, a memorijska $O(N^2)$.
	
	## Glavno rešenje
	Sve rasporede pelikana možemo podeliti u $3$ situacije i njih ćemo analizirati posebno. Nazovimo događaj tipa $1$ gde šetač dolazi sa severne ili sa južne strane vertikalan događaj, a događaj tipa $1$ gde šetač dolazi sa istočne ili sa zapadne strane horizontalan događaj.
	
	1. Pre događaja tipa $2$ na koji treba odgovoriti, nije se desio događaj tipa $1$. U ovom slučaju samo ispisujemo vrednost traženog polja u početnoj matrici.
	2. Pre događaja tipa $2$ na koji treba odgovoriti desili su se ili samo horizontalni, ili samo vertikalni događaji. U tom slučaju, kao u prethodnom podzadatku, pamtimo za svaki red (ili kolonu u zavisnosti od toga da li su događaji tipa $1$ vertikalni ili horizontalni) koliko pelikana ima, i jednostavnim računom u odnosu na obalu poslednjeg šetača dajemo odgovor.
	3. Pre događaja tipa $2$ na koji treba odgovoriti desili su se i horizontalni i vertikalni događaji. Primetimo da nakon što su se desili i horizontalni i vertikalni događaj, broj pelikana po redovima je monoton niz, to isto važi i za broj pelikana po kolonama. Drugim rečima, pelikani će na jezeru imati oblik stepenica, slično kao na primeru dole:
	
	$$ \begin{matrix}
	1 & 1 & 1 & 1 & 0 & 0\\
	1 & 1 & 1 & 0 & 0 & 0\\
	1 & 1 & 0 & 0 & 0 & 0\\
	1 & 1 & 0 & 0 & 0 & 0\\
	1 & 0 & 0 & 0 & 0 & 0\\
	0 & 0 & 0 & 0 & 0 & 0
	\end{matrix}$$
	
	Primetimo da za pelikane koji obrazuju takav stepenast oblik, svaki događaj tipa $1$ simetrično preslikava izgled jezera. Vertikalan događaj preslikava jezero u odnosu na $x$ osu, dok horizontalan događaj preslikava jezero u odnosu na $y$ osu.
	
	To je značajno jer kada izračunamo matricu jezera koja se dobije nakon obrazovanja stepenaste strukture možemo odgovarati na upite direktno iz te matrice tako što vraćamo polje $(i,j), (n-i+1,j), (i,n-j+1)$ ili $(n-i+1, n-j+1)$ u zavisnosti od obala poslednjeg vertikalnog i poslednjeg horizontalnog šetača.
	
	Vremenska složenost je $O(Q + N^2)$, a memorijska $O(N^2)$.
	
	``` cpp title="04_pelikani.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	
	const int MaxN = 1010;
	
	const int c = 0;
	const int u = 1;
	const int l = 2;
	const int d = 3;
	const int r = 4;
	const int ur = 5;
	const int ru = 6;
	const int dr = 7;
	const int rd = 8;
	const int dl = 9;
	const int ld = 10;
	const int ul = 11;
	const int lu = 12;
	
	int n, q;
	bool a[MaxN][MaxN], b[MaxN][MaxN];
	int ns[13][5]; // next state
	int col[13][MaxN], row[13][MaxN];
	int cnt[MaxN];
	char s[MaxN];
	int state, dir;
	
	void transform(int old[], int new1[], int new2[], int currDir)
	{
		for (int i = 0; i <= n; i++)
			cnt[i] = 0;
	
		for (int i = 1; i <= n; i++)
		{
			new1[i] = old[i];
			cnt[ old[i] ]++;
		}
	
		new2[n] = cnt[n];
		for (int i = n - 1; i >= 1; i--)
			new2[i] = new2[i + 1] + cnt[i];
	
		if (currDir > 2)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				int tmp = new2[i]; new2[i] = new2[n - i + 1]; new2[n - i + 1] = tmp;
			}
		}
	}
	
	int answer(int x, int y)
	{
		if (state == 0) return (a[x][y] ? 1 : 0);
	
		if (dir == 1) return (col[state][y] >= x ? 1 : 0);
		if (dir == 2) return (row[state][x] >= y ? 1 : 0);
		if (dir == 3) return (col[state][y] >= n - x + 1 ? 1 : 0);
		if (dir == 4) return (row[state][x] >= n - y + 1 ? 1 : 0);
		return 0;
	
	}
	
	int main()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
			for (int j = 1; j <= n; j++)
				a[i][j] = (s[j - 1] == '1' ? true : false);
		}
	
		for (int i = 1; i <= n; i++)
		{
			row[c][i] = 0;
			col[c][i] = 0;
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j]) row[c][i]++;
				if (a[j][i]) col[c][i]++;
			}
		}
		
		transform(row[c], row[l], col[l], l);
		transform(row[c], row[r], col[r], r);
		transform(col[c], col[u], row[u], u);
		transform(col[c], col[d], row[d], d);
	
		transform(row[u], row[ur], col[ur], r);
		transform(row[u], row[ul], col[ul], l);
		transform(row[d], row[dr], col[dr], r);
		transform(row[d], row[dl], col[dl], l);
	
		transform(col[l], col[lu], row[lu], u);
		transform(col[l], col[ld], row[ld], d);
		transform(col[r], col[ru], row[ru], u);
		transform(col[r], col[rd], row[rd], d);
	
		ns[c][u] = u; ns[c][l] = l; ns[c][d] = d; ns[c][r] = r;
	
		ns[u][u] = u; ns[u][l] = ul; ns[u][d] = d; ns[u][r] = ur;
		ns[l][u] = lu; ns[l][l] = l; ns[l][d] = ld; ns[l][r] = r;
		ns[d][u] = u; ns[d][l] = dl; ns[d][d] = d; ns[d][r] = dr;
		ns[r][u] = ru; ns[r][l] = l; ns[r][d] = rd; ns[r][r] = r;
	
		ns[ul][u] = ul; ns[ul][l] = ul; ns[ul][d] = dl; ns[ul][r] = ur;
		ns[ur][u] = ur; ns[ur][l] = ul; ns[ur][d] = dr; ns[ur][r] = ur;
		ns[dl][u] = ul; ns[dl][l] = dl; ns[dl][d] = dl; ns[dl][r] = dr;
		ns[dr][u] = ur; ns[dr][l] = dl; ns[dr][d] = dr; ns[dr][r] = dr;
	
		ns[lu][u] = lu; ns[lu][l] = lu; ns[lu][d] = ld; ns[lu][r] = ru;
		ns[ru][u] = ru; ns[ru][l] = lu; ns[ru][d] = rd; ns[ru][r] = ru;
		ns[ld][u] = lu; ns[ld][l] = ld; ns[ld][d] = ld; ns[ld][r] = rd;
		ns[rd][u] = ru; ns[rd][l] = ld; ns[rd][d] = rd; ns[rd][r] = rd;
	
		scanf("%d", &q);
		state = 0;
		dir = 0;
	
		for (int num = 1; num <= q; num++)
		{
			int val, x, y;
			scanf("%d", &val);
			if (val == 1)
			{
				scanf("%d", &dir);
				state = ns[state][dir];
			}
			else
			{
				scanf("%d%d", &x, &y);
				printf("%d\n", answer(x, y));
			}
	
		}
	
		return 0;
	}
	```
