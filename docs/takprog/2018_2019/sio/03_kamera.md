---
hide:
  - toc
---

# 3 - Kamera

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 5000ms | 512MB |
	
	Na nedavno održanom takmičenju iz programiranja, vaš tim je osvojio kameru - i to ne bilo kakvu kameru! Proizvođač kamere, firma "MST" tvrdi da ova kamera ima neverovatnu sposobnost - kada se njom slika neki skup neusmerenih grana nekog grafa, ona je u stanju da izračuna da li je moguće od tih grana formirati stablo (stablo je povezan graf bez ciklusa) koje obuhvata sve čvorove tog grafa, i ne samo to! Ako se svakoj od grana dodeli neka nenegativna celobrojna težina, ona će pronaći ono stablo kod kojeg je zbir
	težina svih grana koje učestvuju u stablu minimalan.
	
	Vaš zadatak je da proverite da li kamera radi korektno. Vama će biti dat pravougaoni list papira podeljen na $R$ vrsta i $C$ kolona, kao i broj $N$ - broj čvorova grafa. U svakom polju nalazi se jedna neusmerena grana, tačnije, brojevi $U_{i, j}, V_{i, j}, W_{i, j}$ ($U_{i, j} \neq V_{i, j}$) koji znače da se u polju $i, j$ ($1 \leq i \leq R, 1 \leq j \leq C$) nalazi neusmerena grana koja spaja čvorove $U_{i, j}, V_{i, j}$ i ima težinu $W_{i, j}$. Zatim, dato vam je $Q$ upita oblika $X_1, Y_1, X_2, Y_2$ ($1 \leq X_1 \leq X_2 \leq R, 1 \leq Y_1 \leq Y_2 \leq C$). Vaš zadatak je da za svaki upit odredite da li postoji stablo koje povezuje sve čvorove od $1$ do $N$ a čije se grane nalaze u toj podmatrici, tačnije, uzimaju se u obzir samo one grane koje se nalaze u poljima $x, y$ za koja važi $X_1 \leq x \leq X_2, Y_1 \leq y \leq Y_2$, a ako postoji, da odredite minimalnu ukupnu težinu takvog stabla. Kako se radi o kameri, važiće sledeće: Označimo sa $a$ vrednost $\frac{X_2-X_1+1}{Y_2-Y_1+1}$. U svim upitima važi $\frac{2}{3} \leq a \leq \frac{3}{2}$.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Resi(N, R, C, Q, U[\ldots][\ldots], V[\ldots][\ldots], W[\ldots][\ldots], X1[\ldots], Y1[\ldots], X2[\ldots], Y2[\ldots], O[\ldots])$
	
	koja treba da obradi sve upite i smesti odgovore u niz $O$. Ako stablo ne postoji, u odgovarajući element niza $O$ upisati $-1$, u suprotnom, upisati minimalnu težinu stabla. **Svi nizovi su indeksirani od 1.**
	
	## Primer
	
	Neka je $N = 4, R = 3, C = 4, Q = 3$. Radi preglednosti, neka je zajednička matrica trojki $(U_{i, j}, V_{i, j}, W_{i, j})$ sledeća:
	~~~
	  (1,2,1)     (1,2,2)     (1,2,3)     (1,2,100)
	  (2,3,2)     (2,3,3)     (2,3,1)     (2,3,101)
	  (3,4,3)     (3,4,1)     (3,4,2)     (3,4,102)
	~~~
	
	a zajednički niz upita $(X_1, Y_1, X_2, Y_2)$ sledeći: $(1,1,3,4), (1,2,3,3), (3,4,3,4)$. U prvom upitu učestvuju sve grane:
	~~~
	**(1,2,1)** **(1,2,2)** **(1,2,3)** **(1,2,100)**
	**(2,3,2)** **(2,3,3)** **(2,3,1)** **(2,3,101)**
	**(3,4,3)** **(3,4,1)** **(3,4,2)** **(3,4,102)**
	~~~
	
	Minimalno stablo dobijamo ako odaberemo grane $(1,2,1), (2,3,1), (3,4,1)$, pa je odgovor na prvi upit $3$.
	
	U drugom upitu učestvuju sledeće grane:
	~~~
	  (1,2,1)   **(1,2,2)** **(1,2,3)**   (1,2,100)
	  (2,3,2)   **(2,3,3)** **(2,3,1)**   (2,3,101)
	  (3,4,3)   **(3,4,1)** **(3,4,2)**   (3,4,102)
	~~~
	
	Minimalno stablo dobijamo ako odaberemo grane $(1,2,2), (2,3,1), (3,4,1)$, pa je odgovor na ovaj upit $4$.
	
	U trećem upitu učestvuju sledeće grane:
	~~~
	  (1,2,1)     (1,2,2)     (1,2,3)     (1,2,100)
	  (2,3,2)     (2,3,3)     (2,3,1)     (2,3,101)
	  (3,4,3)     (3,4,1)     (3,4,2)   **(3,4,102)**
	~~~
	
	Jasno je da stablo koje povezuje sve čvorove ne postoji, pa u niz $O$ na poziciji $3$ treba upisati $-1$.
	
	## Ograničenja
	
	* $2 \leq N \leq 40$
	* $1 \leq R, C \leq 250$
	* $1 \leq Q \leq 200000$
	* $0 \leq W_{i, j} \leq 65535$
	
	## Podzadaci
	
	* Podzadatak 1 [8 poena]: $N \leq 4, R,C,Q \leq 10$
	* Podzadatak 2 [13 poena]: $R,C,Q \leq 100$
	* Podzadatak 3 [12 poena]: $N=2$
	* Podzadatak 4 [16 poena]: $N=3$
	* Podzadatak 5 [20 poena]: $Q \leq 50000$
	* Podzadatak 6 [31 poena]: bez dodatnih ograničenja
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `kamera.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int R, int C, int Q, int** U, int** V, int** W, int* X1, int* Y1, int* X2, int* Y2, int* O);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N, R, C, Q$,
	* U narednih $R$ redova po $3C$ brojeva. U $i$-tom redu nalaze se brojevi $U_{i,1}, V_{i,1}, W_{i,1}$, $U_{i,2}, V_{i,2}, W_{i,2}$, $\ldots$, $U_{i,C}, V_{i,C}, W_{i,C}$,
	* U narednih $Q$ redova po 4 broja: $X_1, Y_1, X_2, Y_2$.
	
	Zatim ovaj program zove vašu funkciju i štampa brojeve $O[1], \ldots, O[Q]$, svaki u posebnom redu. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Ivan Stošić | Aleksa Plavšić |
	
	Kod prva dva podzadatka bilo je dovoljno implementirati bilo koji efikasan algoritam za nalaženje minimalnog pokrivajućeg stabla - u nastavku MST od *minimum spanning tree*, takođe, sa $MSF$ ćemo označiti minimalnu pokrivajuću šumu grafa, tačnije, to je podgraf koji je šuma minimalne težine a ima iste povezane komponente, pri čemu je za prvi podzadatak bio dovoljan bilo koji tačan *brute force* pristup.
	
	Za 3. i 4. podzadatak mogla je da se koristi bilo koja *2D* struktura podataka koja efikasno odgovara na upite "koji je minimum u podmatrici". Za 3. podzadatak ($N=2$) dovoljno je samo naći granu minimalne težine. Za 4. podzadatak ($N=3$) potrebno je naći minimalnu težinu grane među svim granama koje spajaju čvorove $1,2$, analogno za čvorove $2,3$ i $1,3$. Ukoliko se među ovim granama javlja jedna ili nijedna, onda stablo ne postoji. Ako se javljaju tačno dve onda upravo one čine stablo, a ako se jave tri onda se stablo dobija odbacivanjem najteže od te tri grane. Najlakša za implementaciju (a ipak dovoljno brza) takva struktura bi bila sledeća asimetrična tabela: Za svaki podsegment svakog reda izračunamo minimalni element, ovo radimo u složenosti $O(R \times C^2)$, svaki upit rešavamo u $O(R)$ prolazom kroz odgovarajuće redove.
	
	Da bi se zadatak rešio za 100 poena ključna je sledeća opservacija vezana za pojam MST-a:
	
	Neka je $A$ skup grana grafa sa čvorovima $V = \{1, \ldots, N\}$, i neka je $T(A)$ minimalna pokrivajuća **šuma** tog grafa (ukoliko ih ima više, onda bilo koja). Tada važi sledeće: $T(T(A) \cup T(B))$ je minimalna pokrivajuća **šuma** za skup grana $A \cup B$. Ovo se može dokazati analizom rada *Kruskal*-ovog algoritma za nalaženje MST-a. U prevodu, ovo znači da, ako hoćemo da izračunamo $MSF$ za neki, potencijalno veliki skup grana, mi ga možemo podeliti na dva manja skupa, koji se čak mogu i preklapati (potrebno je samo da je njihova unija jednaka početnom skupu), zatim naći njihov $MSF$ a zatim zajednički $MSF$ na sada već znatno manjem skupu grana.
	
	Ovo nas usmerava ka tome da napravimo dvodimenzionu *sparse table* strukturu podataka, gde ćemo za svako $i,j,k$ ($1 \leq i \leq R$, $1 \leq j \leq C$, $0 \leq k \leq \log_2(\min(R,C))$ čuvati skup grana koji učestvuje u $MSF$-u skupa grana koje se nalaze u kvadratnoj podmatrici čije je gornje levo teme polje $i,j$ a stranica tog kvadrata je $2^k$. Jasno je da se svako polje ove tabele može izračunati kao unija četiri polja gde su stranice kvadrata duplo manje. Ako sa $\alpha(N)$ označimo složenost jedne operacije pomoćne strukture podataka za disjunktne skupove *(DSU, Disjoint Set Union)* a koja je za ovako male vrednosti $N$ praktično konstantna, tada se cela ova tabela može konstruisati u složenosti $O(RC\log(\min(R,C))N \alpha(N))$.
	
	Još jedna ključna stvar je ta što, usled toga što je količnik stranica pravougaonika kod svakog upita broj između $\frac23$ i $\frac32$, svaki ovakav pravougaonik može da se "pokrije" sa najviše $6$ kvadrata čija je stranica stepen dvojke, što nam omogućava da rešimo svaki upit u složenosti $O(N \alpha(N))$.
	
	``` cpp title="03_kamera.cpp" linenums="1"
	#include <array>
	#include <numeric>
	#include <algorithm>
	#include <iostream>
	using namespace std;
	
	typedef uint16_t tezina_t;
	typedef uint8_t cvor_t;
	const int MAX_N = 42;
	const int MAX_SZ = 252;
	const int MAX_LOG = 8;
	
	struct grana {
		cvor_t u, v;
		tezina_t w;
	
		grana() : u(0), v(0), w(0) {}
		grana(cvor_t u, cvor_t v, tezina_t w) : u(u), v(v), w(w) {}
	
		bool operator< (const grana& b) const {
			return w < b.w;
		}
	};
	
	typedef array<grana, MAX_N> mst;
	
	struct dsu {
		array<cvor_t, MAX_N> p, s;
	
		dsu() {
			iota(p.begin(), p.end(), 0);
			fill(s.begin(), s.end(), 1);
		}
	
		cvor_t e(cvor_t x) {
			if (x == p[x])
				return x = p[x];
			return p[x] = e(p[x]);
		}
	
		bool spoji(cvor_t x, cvor_t y) {
			x = e(x);
			y = e(y);
			if (x == y)
				return false;
			if (s[x] > s[y])
				swap(x, y);
			p[x] = y;
			s[y] += s[x];
			return true;
		}
	};
	
	mst spoji(const mst& a, const mst& b) {
		mst c;
		dsu d;
		int i = 0, j = 0, k = 0;
		while (a[i].u || b[j].u) {
			bool prva = (a[i].u && b[j].u && a[i].w < b[j].w) || !b[j].u;
			grana g = prva ? a[i++] : b[j++];
			if (d.spoji(g.u, g.v))
				c[k++] = g; 
		}
		return c;
	}
	
	mst tbl[MAX_SZ][MAX_SZ][MAX_LOG], prazan;
	
	const mst& daj(int x, int y, int z) {
		if (x >= MAX_SZ || y >= MAX_SZ)
			return prazan;
		return tbl[x][y][z];
	}
	
	void Resi(
		int N, int R, int C, int Q,
		int** U, int** V, int** W,
		int* X1, int* Y1, int* X2, int* Y2,
		int* O)
	{
		for (int i=1; i<=R; i++)
			for (int j=1; j<=C; j++)
				tbl[i][j][0][0] = grana(U[i][j], V[i][j], W[i][j]);
		for (int k=1; k<MAX_LOG; k++) {
			int w = 1 << (k-1);
			for (int i=1; i<=R; i++)
				for (int j=1; j<=C; j++)
					tbl[i][j][k] = spoji(
						spoji(daj(i+w, j, k-1), daj(i, j+w, k-1)),
						spoji(daj(i, j, k-1), daj(i+w, j+w, k-1)));
		}
	
		for (int i=1; i<=Q; i++) {
			int p = X2[i] - X1[i] + 1;
			int q = Y2[i] - Y1[i] + 1;
			int k = 0, l = 1;
			while (2*l <= min(p, q))
				l<<=1, k++;
	
			mst tmp;
			if (p >= q) {
				int xt = X1[i];
				while (1) {
					if (X2[i]-xt+1 > l) {
						tmp = spoji(tmp, daj(xt, Y1[i]    , k));
						tmp = spoji(tmp, daj(xt, Y2[i]-l+1, k));
						xt += l;
					} else {
						tmp = spoji(tmp, daj(X2[i]-l+1, Y1[i]    , k));
						tmp = spoji(tmp, daj(X2[i]-l+1, Y2[i]-l+1, k));
						break;
					}
				}
			} else {
				int yt = Y1[i];
				while (1) {
					if (Y2[i]-yt+1 > l) {
						tmp = spoji(tmp, daj(X1[i],     yt, k));
						tmp = spoji(tmp, daj(X2[i]-l+1, yt, k));
						yt += l;
					} else {
						tmp = spoji(tmp, daj(X1[i],     Y2[i]-l+1, k));
						tmp = spoji(tmp, daj(X2[i]-l+1, Y2[i]-l+1, k));
						break;
					}
				}
			}
	
			int z = 0, uw = 0;
			for (int j=0; j<MAX_N; j++)
				if (tmp[j].u)
					uw += tmp[j].w, z++;
			if (z < N-1)
				uw = -1;
			O[i] = uw;
		}
	}
	```
