---
hide:
  - toc
---

# 1 - Pacovi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 300ms | 256MB |
	
	Bila jednom jedna beskonačna usmerena prava linija. Ona je bila popločana stringovima koji su svi bili isti, isto orijentisani (u istom smeru kao prava) i bili su jednaki stringu $A$. Međutim, beskonačno (i to neprebrojivo) mnogo pacova je napalo pravu i pojelo sve pločice, pa je sad ostala samo gola prava. Vi na raspolaganju imate beskonačno (ali prebrojivo) mnogo kopija svakog od $M$ vrsta stringova, kojima treba popločati ovu pravu. Vaš zadatak je popločate pravu tako da ona izgleda isto kao ranije. **Obratite pažnju na to da ova prava nema ni početak ni kraj niti su pozicije na pravoj indeksirane na bilo koji način (videti primere za objašnjenje).** Kako biste majstorima olakšali posao, vaš zadatak je da napravite jednu pločicu konkatenacijom (nadovezivanjem) nekih od datih stringova, tako da se tom jednom pločicom može izvršiti popločavanje. **Nije dozvoljeno okretati ove stringove (a ni celu pločicu) naopačke.** Pomozite majstorima tako što ćete im reći koliko je najmanje stringova potrebno da se napravi pločica kojom može da se popravi šteta koju su naneli pacovi. Ukoliko ovo nije moguće, vaš odgovor treba da bude broj $-1$ (omiljeni broj svakog pacova).
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $Resi(N, A[\ldots], M, L[\ldots], B[\ldots][\ldots])$
	
	koja treba da nađe broj opisan u tekstu zadatka. $N$ označava dužinu stringa $A$ (koji je indeksiran od $1$). $M$ označava broj stringova u nizu stringova $B$. $L$ je niz dužine $M$ gde je $L[i]$ dužina stringa $B[i]$. $B$ je niz nizova karaktera. Vaša funkcija treba da vrati jedan ceo broj - odgovor na pitanje postavljeno u tekstu zadatka, ili $-1$ ako formiranje pločice nije moguće. **Svi nizovi su indeksirani od 1.**
	
	## Primer 1
	Neka je $A = baabaa, B = \{a, b, c\}$. Moguće je formirati pločicu $aba$ pomoću dva stringa $a$ i jednog stringa $b$. Ovom pločicom dobija se popločavanje koje je jednako popločavanju koje se dobija stringom $baabaa$:
	
	```
	...baabaabaabaa...
	.....abaabaabaaba...
	```
	
	Rešenje ovog primera je $3$, jer smo za formiranje pločice $aba$ iskoristili $3$ stringa.
	
	## Primer 2
	Neka je $A = bca, B = \{ab, bc, ca\}$. Moguće je formirati pločicu $abcabc$ redom pomoću stringova $ab, ca, bc$. Lako se uočava da se i ovom pločicom dobija popločavanje jednako popločavanju stringom $bca$:
	
	```
	...bcabcabcabca...
	.....abcabcabcabc...
	```
	
	## Ograničenja
	
	+ $N \leq 500$.
	+ $M \leq 100.000$.
	+ $1 \leq L_i \leq N$.
	+ $\sum_{i=1}^{M} L_i \leq 1.000.000$.
	+ Svi stringovi se sastoje samo od malih slova engleske abecede.
	
	## Podzadaci
	
	+ Podzadatak $1$ [$4$ poena]: String $A$ sadrži samo slova $a$.
	+ Podzadatak $2$ [$33$ poena]: $N, M \leq 100$.
	+ Podzadatak $3$ [$11$ poena]: $M \leq 1000$.
	+ Podzadatak $4$ [$52$ poena]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `pacovi.cpp` ili `pacovi.pas`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	U zavisnosti od programskog jezika koji koristite, vaša funkcija mora biti sledećeg oblika:
	
	| Jezik   | Deklaracija funkcije                                                                                    | 
	| ------- | --------------------------------------------------------- |
	| C++     | `int Resi(int N, char* A, int M, int* L, char** B);`   |
	| Pascal  | `function Resi(N : Longint; var A : Array of Char; M : Longint; var L : Array of Longint; var B : NizStringova) : Longint;`   |
	
	Za `Pascal`, `NizStringova` je tip koji je definisan kao `Array of Array of Char`.
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova**.
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam "template" fajlovi `code.cpp` i `code.pas` koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi `grader.cpp`, `grader.pas` koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu string $A$,
	+ U narednom redu broj $M$
	+ U narednih $M$ redova po jedan string, $B_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa njen rezultat. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Ivan Stošić | Aleksa Plavšić |
	
	Rešenje zadatka se okvirno može podeliti na dve faze: U prvoj, identifikujemo na kojim pozicijama se nalaze stringovi iz niza $B$ u stringu $A$, gde $A$ posmatramo kao cikličan string. U drugoj, proveravamo koliko najmanje stringova iz $B$ nam treba da bismo napravili string ekvivalentan stringu $A$.
	
	## Prva faza - traženje stringova
	
	Jedan od efikasnijih načina da se ovo uradi jeste da se skup stringova iz $B$ predstavi u obliku _Trie_ strukture podataka. Zatim, za svaku polaznu poziciju $i$ u stringu $A$ krećemo se unapred nizom slova $A_i, A_{i+1}, \ldots A_j$. Ako "izletimo" iz stabla _Trie_ prekidamo i nastavljamo sa narednom vrednošću $i$. Inače, ako se nalazimo u čvoru koji odgovara nekom stringu iz $B$ pamtimo da je $A_i, \ldots, A_j \in B$. Ovaj deo radi u vremenskoj složenosti $O(N^2 + \sum L_i)$.
	
	## Druga faza - nalaženje minimalnog broja stringova
	
	Pretpostavimo da je string $A$ aperiodičan. Ukoliko nije, nalazimo njegovu najmanju periodu. Primetimo da se prava može popločati na ekvivalentan način popločavanju stringom $A$ ako i samo ako postoji neki niz stringova $S_1, S_2, \ldots S_k$ iz $B$ koji pokrivaju pozicije $[x_1, x_2-1], [x_2, x_3-1], \ldots, [x_{k-1}, x_k-1]$ gde je $x_k = x_1$. Stoga, pravimo graf sa $N$ čvorova i stavljamo granu $(i, j)$ ukoliko je $A_i, \ldots, A_{j-1} \in B$, a zatim tražimo najkraći ciklus u grafu. U slučaju da $A$ nije aperiodičan, u obzir dolazi svaki put koji vodi od čvora $i$ do čvora $j$ gde važi $d | i-j$, gde je $d$ dužina najkraće periode. Nalaženje najkraćeg puta odnosno ciklusa u ovom grafu je najjednostavnije uraditi *Flojd-Varšalovim* algoritmom, u svega 4 linije koda. Ovaj deo radi u vremenskoj složenosti $O(N^3)$.
	
	``` cpp title="01_pacovi.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	const int MAXNODES = 1000005;
	const int MAXN = 505;
	
	struct node {
		int p[26];
		int c;
	} d[MAXNODES];
	int z;
	
	int f[MAXN][MAXN];
	
	int Resi(int n, char* a, int m, int* l, char** b) {
		// nadji najmanju periodu stringa i promeni n
		a++;
		for (int i=1; i<=n; i++) {
			if (n % i)
				continue;
			bool ok = true;
			for (int j=0; j<n; j++)
				if (a[j] != a[j % i]) {
					ok = false;
					break;
				}
			if (ok) {
				n = i;
				break;
			}
		}
	
		// napravi trie
		for (int i=1; i<=m; i++) {
	
			int r = 0;
	
			for (int j=1; j<=l[i]; j++) {
				int x = b[i][j] - 'a';
	
				if (!d[r].p[x])
					d[r].p[x] = ++z;
	
				r = d[r].p[x];
			}
	
			d[r].c = 1;
		}
	
		memset(f, 11, sizeof(f));
	
		// nadji grane
		for (int i=0; i<n; i++) {
			int r = 0;
			for (int j=0;; j++) {
				int x = a[(i+j) % n] - 'a';
				if (d[r].p[x])
					r = d[r].p[x];
				else
					break;
	
				if (d[r].c)
					f[i][(i+j+1) % n] = 1;
			}
		}
	
		for (int j=0; j<n; j++)
			for (int i=0; i<n; i++)
				for (int k=0; k<n; k++)
					f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
	
		int sol = 123123123;
		for (int i=0; i<n; i++)
			sol = min(sol, f[i][i]);
	
		if (sol > n)
			sol = -1;
		return sol;
	}
	```
