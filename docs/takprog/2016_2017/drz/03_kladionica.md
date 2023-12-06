---
hide:
  - toc
---

# B3 - Kladionica

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 700ms | 256MB |
	
	Pametni koder Aki je sinoć gledao film *”Ocean's eleven” (Igraj svoju igru)*. Kako mu je film bio dosadan, negde na polovini se uspavao i počeo da sanja o tome kako može prevariti kladionicu kao akteri filma. Sanjao je da ima pristup bazi podataka kladionice i da može namestiti rezultat bilo koje utakmice.
	
	Odlučio je da se kladi na fudbalske mečeve. Postoji $N$ različitih fudbalskih liga, a u svakoj ligi po $M$ utakmica za koje je moguće uložiti opkladu. Za svaku utakmicu koju je odabrao je poznata **kvota** - prirodan broj koji predstavlja koeficijent dobitka koji nosi ta utakmica ukoliko je rezultat pogođen.
	
	Aki će **iz svake lige** izabrati bar jednu utakmicu (moguće i više), i tako sastaviti **tiket**. Za svaku ligu je poznat broj utakmica koje je moguće izabrati iz te lige na istom tiketu - npr. postoji slučaj gde  je za neku ligu moguće izabrati tačno 2 ili 4 utakmice, ali nije moguće izabrati 3.
	
	Dobitak tiketa se određuje tako što se **pomnože kvote** svih odabranih utakmica, a zatim se dobijeni proizvod **pomnoži sa bonusom** koji zavisi od broja odigranih utakmica. Bonusi za svaki mogući broj odigranih utakmica su dati od strane kladionice.
	
	Kako Aki u svom snu može namestiti rezultate svih utakmica, i želi da zaradi što više para, on će **sastaviti sve moguće tikete**. Dva tiketa se razlikuju ukoliko bar jedna utakmica postoji na jednom tiketu, a ne postoji na drugom. Na kraju, Aki će zaraditi onoliko para koliko je zbir dobitaka sa svih tiketa.
	
	Izračunajte i ispišite koliko će para Aki zaraditi u svom snu (računajući po modulu $10^9 + 7 = 1000000007$).
	
	## Opis ulaza
	U prvom redu se nalaze dva prirodna broja: $N$ - broj liga, i $M$ - broj utakmica u svakoj ligi.
	U narednih $N$ redova se nalazi po $M$ prirodnih brojeva koji predstavljaju kvote za svaku utakmicu.
	
	U sledećih $N$ redova se nalazi po $M$ brojeva koji predstavljaju matricu $C$. Elementi te matrice mogu imati vrednost nula ili jedan. Ako je $j$-ti broj u $i$-tom od tih redova jednak jedan ($C[i][j]=1$), onda to znači da se iz $i$-te lige može izabrati $j$ utakmica, a ako je jednak nuli, onda se iz $i$-te lige ne može izabrati $j$ utakmica.
	
	U poslednjem redu ulaza ima ukupno $N \times M$ prirodnih brojeva gde $i$-ti broj u nizu predstalja bonus za ukupno odigranih $i$ utakmica.
	
	## Opis izlaza
	U prvom redu izlaza ispisati koliko će para Aki zaraditi, računajući po modulu $10^9 + 7 = 1000000007$.
	
	## Primer 1
	### Ulaz
	```
	2 3
	2 3 4
	5 6 7
	1 0 1
	0 1 1
	10 20 30 40 50 60
	```
	
	### Izlaz
	```
	535290
	```
	
	## Objašnjenje primera
	Postoje dve lige sa po tri utakmice. Kvote utakmica u prvoj ligi su $2$, $3$ i $4$, dok u drugoj ligi postoje utakmice sa kvotama $5$, $6$ i $7$.
	Iz prve lige je moguće izabrati tačno jednu ili tačno tri utakmice, dok nije moguće izabrati dve utakmice iz prve lige. Iz druge lige je moguće izabrati dve ili tri utakmice.
	Neki od mogućih tiketa su:
	
	* Iz prve lige biramo prvu utakmicu (kvota $2$), iz druge lige biramo prvu i drugu utakmicu (kvote $5$ i $6$). Ukupna kvota je $2 \cdot 5 \cdot 6 = 60$. Pošto smo izabrali 3 utakmice, kvota se množi sa bonusom za 3 utakmice ($30$), i tako dobijamo ukupan dobitak za ovaj tiket: $60 \cdot 30 = 2400$
	* Iz prve lige biramo sve tri utakmice (kvote $2$, $3$ i $4$), iz druge lige biramo prvu i treću utakmicu (kvote $5$ i $7$). Ukupna kvota je $2 \cdot 3 \cdot 4 \cdot 5 \cdot 7 = 840$. Kako smo izabrali ukupno 5 utakmica, kvota se množi sa bonusom ѕa 5 utakmica ($50$) i tako dobijamo ukupan dobitak: $840 \cdot 50 = 42000$
	
	Kombinovanjem svih mogućih tiketa, a onda sabiranjem njihovih dobitaka, dobijamo ukupnu zaradu od $535290$.
	
	## Ograničenja i podzadaci
	* Kvote tiketa i bonusi su prirodni brojevi između 1 i 1000
	
	Postoje $5$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [7 poena]: $N \cdot M \leq 20$.
	* Podzadatak 2 [25 poena]: $N=1$, i $M \leq 100$.
	* Podzadatak 3 [12 poena]: $N,M \leq 100$ i **iz svake lige se može igrati tačno jedna utakmica** ($C[i][1]=1$, $C[i][j]=0$ ako je $j>1$).
	* Podzadatak 4 [25 poena]: $N,M \leq 100$ i **svi bonsi su tačno 1**.
	* Podzadatak 5 [31 poen]: $N,M \leq 100$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dragan Urošević | Dragan Urošević | Dušan Zdravković |
	
	Pravolinijsko rešenje se dobija tako što se utakmice numerišu, npr. brojevima od $0$ do $N\cdot M - 1$ (ako su lige numerisane brojevima od 1 do $N$, a utakmice u okviru svake lige brojevima od 1 do $M$, onda će utakmica  $j$ iz lige broj $i$ biti numerisana brojem $(i-1)\cdot M + (j-1)$) i nakon toga svaki tiket posmatra kao podskup skupa $\{0, 1, 2, ..., N\cdot M - 1\}$. Primetimo da ne mora svaki podskup skupa  $\{0, 1, 2, ..., N\cdot M - 1\}$ predstavljati ispravan tiket: može se desiti da je iz nekih liga izabran nedozvoljen broj utakmica.
	No bez obzira na to, podskupovi se mogu reprezentovati pomoću celih brojeva između 0 i $2^{N\cdot M}-1$. Svaki broj iz tog opsega se može zapisati u binarnom brojnom sistemu sa najviše $N\cdot M$ cifara (bitova). Ako zapis ima manje od $N\cdot M$ cifara dopuni se nulama (sa leve strane). Cifra nula na mestu određene težine označava da utakmica čija se oznaka poklapa sa težinom nije izabrana u podskup (na tiket), a cifra 1, da je odgovarajuća utakmica izabrana u podskup (na tiket). Prema tome, potrebno je od broja formirati tiket, proveriti da li je tiket ispravan (validan), ako jeste, odrediti dobitak i dodati na zbir dobitaka. Složenost ovog rešenja je $\Theta(N\cdot M \cdot 2^{N\cdot M})$. Ovo predstavlja rešenje podzadatka 1.
	
	Podzadatak 3 se takođe može rešiti na poseban način. Pretpostavimo radi pojednostavljenja da imamo samo dve lige. Iz svake lige je moguće uzeti po jednu utakmicu, a dobitak se računa kao proizvod kvota za izabrane utakmice i bonusa za tiket sa dve utakmice. Za svaki tiket će bonus biti isti (jer svaki tiket ima tačno dve utakmice), pa se zbog toga mogu prvo izračunati samo proizvodi kvota za tikete, sabrati i na kraju pomnožiti sa bonusom. Kao što smo rekli, ispravne tikete čine sve kombinacije sastavljene od po jedne utakmice iz obe lige. Zbog distributivnosti množenja u odnosu na sabiranje, zbir proizvoda kvota za sve moguće tikete će biti jednak proizvodu zbira kvota za prvu ligu i zbira kvota za drugu ligu. Ovo se može poopštiti i na slučaj kada postoji više od dve lige, pa se zbir svih dobitaka može odrediti tako što se pomnože zbirovi kvota za sve lige i to na kraju pomnoži sa bonusom (uvek isti broj - broj odigranih utakmica je jednak broju liga). Složenost ovog rešenja je $\Theta(N\cdot M)$.
	
	Opišimo rešenje koje "pokriva" sve podzadatke. Pretpostavimo opet da imamo samo dve lige. Ako je dozvoljeno iz prve lige uzeti $k_1$ utakmica, a iz druge lige $k_2$ utakmica, onda se bilo koji podskup od $k_1$ utakmica iz prve lige može kombinovati sa bilo kojim podskupom od $k_2$ utakmica iz druge lige, a dobitak će se računati kao proizvod kvota izabranih utakmica i bonusa za $k_1+k_2$ odigranih utakmica. Kako je bonus uvek isti, može se opet računati samo zbir proizvoda kvota, pa na kraju dobijeni zbir pomnožiti sa bonusom. Zbog distributivnosti, zbir proizvoda se može dobiti tako što se saberu svi proizvodi od po $k_1$ kvota za prvu ligu, odnosno svi proizvodi od po $k_2$ kvota za drugu ligu i na kraju ta dva zbira pomnože. Ako bi bilo više od dve lige, onda bi se opet zbirove proizvoda (sa istim brojem odigranih utakmica) za pojedine lige množili i nakon toga množili  sa odgovarajućim bonusom . Prema tome,  potrebno je za početak za svaku ligu $i$ i svaku vrednost $j\in\{1, 2, ..., M\}$ odrediti zbir svih proizvoda kvota za tačno $j$ utakmica odigranih u ligi $i$ (označimo te zbirove sa $pr_{ij}$).
	 
	Izraze  $pr_{ij}$ ćemo izračunati koristeći dinamičko programiranje. Neka je $pr_{i,j}^{(k)}$ zbir svih proizvoda kvota od tačno $j$ utakmica iz lige $i$, pri čemu  svi podskupovi sadrže samo utakmice sa rednim brojevima između 1 i $k$ (naravno ne nužno sve). Tada će $pr_{i,j}^{(M)}$ biti zbir svih mogućih proizvoda kvota od po $j$ utakmica u ligi broj $i$.
	Lako se može zaključiti da je
	
	$$
	pr_{i,j}^{(0)}=\begin{cases}
	1, &\text{ako je }j=0\\
	0, &\text{ako je }j > 0
	\end{cases}.
	$$
	
	Što se tiče zbira svih proizvoda kvota za tačno $j$ utakmica gde je svih $j$ utakmica iz skupa $\{1, 2, ..., k, k+1\}$, primetimo da postoje dve mogućnosti:
	
	 - Svih $j$ izabranih utakmica su iz skupa $\{1, 2, ..., k\}$, tj. nije izabrana utakmica $k+1$,
	 -  Jedna od izabranih utakmica je baš $k+1$. Onda je preostalih $j-1$ utakmica iz skupa $\{1, 2, ..., k\}$. Pri tome se svaki tiket sa $j-1$ utakmicom može proširiti do tiketa sa $j$ utakmica dodavanjem utakmice $k+1$. Zbog distributivnosti množenja u odnosu na sabiranje, zbir svih proizvoda sa $j$ izabranih utakmica, gde je poslednja baš utakmica $k+1$ biće jednak proizvodu kvote za tu utakmicu $k+1$ i zbira proizvoda svih tiketa sa $j-1$ utakmicom (gde su sve te utakmice iz skupa $\{1, 2, ..., k\}$ .
	
	Na osnovu ovog razmatranja može se izvesti formula za izračunavanje zbirova: 
	
	$$
	pr_{i,j}^{(k+1)}=\begin{cases}
	pr_{i,j}^{(k)} + pr_{i,j-1}^{(k)} \cdot q_{i,k+1}, &\text{ako je }j\leq k+1\\
	0, &\text{ako je }j > k+1
	\end{cases}.
	$$
	U gornjem izrazu $q_{i,k+1}$ predstavlja kvotu za utakmicu $k+1$ u ligi $i$.
	
	Kada imamo zbirove proizvoda sa fiskiranim brojem utakmica za svaku ligu, onda sličnim postupkom određujemo zbirove proizvoda kvota na tiketu koji sadrži utakmice iz raznih liga. Označimo sa $gpr_{k,j}$ zbir proizvoda svih tiketa koji imaju tačno $j$ utakmica iz prvih $k$ liga.
	Tada će važiti da je
	
	$$
	gpr_{1,j}^{(1)} = pr_{1,j}.
	$$
	
	Lako se zaključuje da ako iz prvih $k+1$ liga treba izbrati tačno $j$ utakmica, to možemo uraditi tako što iz lige broj $k+1$ izaberemo bilo koji dozvoljeni broj utakmica (ne veći od $j$) a ostatak dopunimo iz prvih $k$ liga. Mi već imamo izračunate zbirove proizvoda kvota za sve moguće brojeve utakmica na tiketu. Ako uvedemo oznake 
	
	$$
	c_{i,j} = \begin{cases}
	1,&\text{ može izabrati tačno  $j$ utakmica iz lige $i$}\\
	0,&\text{ ne može se izabrati tačno  $j$ utakmica iz lige $i$}
	\end{cases},
	$$
	
	onda se $gpr_{k+1,j} $ može računati na sledeći način
	
	$$
	g_{k+1,j} = \sum_{j'=1}^{\min(M,j)} c_{k+1,j'}\cdot pr_{k+1,j'}\cdot gpr_{k,j-j'}
	$$
	
	Nakon određivanja svih pomenutih zbirova proizvoda potrebno je samo odgovarajuće zbirove pomnožiti sa bonusima i sabrati:
	
	$$
	\sum_{j}^{N\cdot M} F_j \cdot gpr_{N,j}
	$$
	
	Ovde je sa $F_j$ označen bonus za tiket sa $j$ utakmica.
	
	Napomenimo da se sve operacije izvode po modulu $10^9+7$, tj. svaki put posle izvedene operacije (sabiranje ili množenje) se određuje ostatak pri deljenju sa $10^9+7$.
	
	Na kraju, par reči o složenosti postupka. Složenost računanja matrice $pr$ je $O(N\cdot M^2)$, a složenost računanja matrice $gpr$ je $O(N^2\cdot M^2)$.
	
	``` cpp title="03_kladionica.cpp" linenums="1"
	# include <stdio.h>
	
	# define MAXNM 110
	# define MAXK 10100
	# define MOD 1000000007
	
	int n, m;
	
	int t[MAXNM][MAXNM];
	int c[MAXNM][MAXNM];
	int cz[MAXNM][MAXNM];
	
	int F[MAXK];
	
	long long rez;
	
	long long prs[MAXNM][MAXNM];
	long long prt[MAXNM][MAXK];
	
	citaj() {
	  int i, j, k;
	  scanf("%d%d", &n, &m);
	  for (i = 1; i <= n; i++)
	  	for (j = 1; j <= m; j++)
		  scanf("%d", &t[i][j]);
	  for (i = 1; i <= n; i++) {
	  	k = 0;
	  	for (j = 1; j <= m; j++) {
	  		scanf("%d", &c[i][j]);
	  		if (c[i][j] == 1) {
	  			k++;
				cz[i][k] = j;	
			}
		}
		k++;
		cz[i][k] = -1;
	 }
	  for (i = 1; i <= n * m; i++)
	  	scanf("%d", &F[i]);	
	}
	
	
	void racunajprs() {
		int i, j, k;
		for (i = 1; i <= n; i++) {
			prs[i][0] = 1;
			for (j = 1; j <= m; j++) 
				prs[i][j] = 0;
			for (j = 1; j <= m; j++) {
				for (k = j; k >= 1; k--) {
					prs[i][k] = (prs[i][k] + prs[i][k-1] * t[i][j]) % MOD;
				}
			}
		}
	}
	
	void racunajprt() {
		int i, j, j1, k;
		for (j1 = 1; cz[1][j1] != -1; j1++) {
			j = cz[1][j1];
			prt[1][j] = prs[1][j];
		}
		for (i = 2; i <= n; i++) {
			for (j1 = 1; cz[i][j1] != -1; j1++) {
				j = cz[i][j1];
				for (k = (i - 1) * m; k >= 0; k--) {
					prt[i][k+j] = (prt[i][k+j] + prt[i-1][k] * prs[i][j]) % MOD;
				}
			}
		}
		rez = 0;
		for (k = 1; k <= m * n; k++) {
			rez = (rez + prt[n][k] * F[k]) % MOD;
		}
	}
	
	pisi() {
		printf("%lld\n", rez);
	}
	
	main() {
		citaj();
		racunajprs();
		racunajprt();
		pisi();
		return 0;	
	}

	```
