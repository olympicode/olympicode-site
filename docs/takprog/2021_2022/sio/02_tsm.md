---
hide:
  - toc
---

# 2 - TSM

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	
	Đole Programer, bivši takmičarski programer, a sada gradonačelnik Bajtgrada, prestonice Bajtovije, treba da smisli plan za novi gradski metro. Već je određeno da će postojati $N$ stanica, kao i gde će se nalaziti.
	
	Postoji $M$ različitih predloga za metro linije, od kojih Đole mora da izabere podskup. Svaki predlog se sastoji od dve stanice koje linija direktno povezuje, kao i cenu izgradnje linije. **Sve cene izgradnje metro linija su međusobno različite.** Poznato je da je za svaki dobar metro potrebno da bude zadovoljen sledeći uslov:
	- može se stići od bilo koje stanice do bilo koje druge, **na tačno jedan način**.
	
	Takođe, Đole želi da ukupna cena metroa (zbir cena izabranih metro linija) bude što manja.
	
	Kada je ovako formalno definisao problem, Đole se odmah setio sličnih zadataka iz svojih takmičarskih dana, ali nije mogao da se seti tačno algoritma koji treba da koristi. Setio se da algoritam glasi ovako:
	- poređamo sve planove za metro linije u niz, nekim redosledom;
	- prolazimo kroz linije jednu po jednu tim redosledom i obavezno prihvatamo plan za tu metro liniju ukoliko nije u konfliktu sa do sada prihvaćenim linijama;
	- kažemo da je linija u konfliktu sa do sada prihvaćenim linijama ukoliko, kada dodamo tu liniju među prihvaćene linije, postoji više od jednog načina da se stigne između neke dve stanice.
	
	Đole nije uspeo da se seti tačno koji redosled linija (poredak) treba da koristi, ali znamo da voli velike brojeve i voleo bi da budu što bliže početku poretka. Iako je ipak najbitnija cena, vi želite i da Đole bude srećan. Zato, vaš zadatak je da nađete leksikografski najveći poredak linija **po ceni** koji će, prateći gorenavedeni algoritam, još uvek da nađe najjeftiniji moguć metro.
	
	## Opis funkcije
	Potrebno je da implementirate funkciju
	
	* $NadjiPoredak(N, M, X[\ldots], Y[\ldots], W[\ldots])$
	
	gde je $N$ broj stanica u Bajtgrada, a $M$ broj predloga linija. Nizovi $X$, $Y$ i $W$ opisuju predloge linija, gde su $X$ i $Y$ indeksi stanica koje povezuje, a $W$ cena da se linija napravi. Potrebno je da funkcija vrati traženi poredak. Vraćeni niz treba da sadrži **cene** linija, poređane u odgovarajući redosled. **Nizovi $X$, $Y$ i $W$ su indeksirani od $1$, poredak je indeksiran od $0$.**
	
	## Primeri
	Neka su $N=4$ i $M = 5$, i neka su nizovi $X=\{1, 2, 2, 3, 1\}$, $Y=\{
	2, 3, 4, 4, 4\}$ i $W=\{50, 10, 20, 30, 40\}$.
	Leksikografski najveći poredak koji daje najjeftiniji metro plan je $\{40, 20, 50, 10, 30\}$. Ovim poretkom dobijamo najjeftiniji metro plan koji sadrži grane $2$, $3$ i $5$, ukupne cene $70$.
	
	Neka su $N=5$ i $M = 5$, i neka su nizovi $X=\{2, 2, 1, 1, 3\}$, $Y=\{
	5, 4, 2, 4, 4\}$ i $W=\{12, 3, 50, 11, 36\}$.
	Leksikografski najveći poredak koji daje najjeftiniji metro plan je $\{36, 12, 11, 3, 50\}$. Ovim poretkom dobijamo najjeftiniji metro plan koji sadrži grane $1$, $2$, $4$ i $5$, ukupne cene $62$.
	
	## Ograničenja
	
	-   $1 \leq N, M \leq 3\cdot10^5$.
	- $1 \leq X_i, Y_i \leq N$.
	- $1 \leq W_i \leq 10^9$.
	- Garantuje se da će biti moguće napraviti makar jedan metro plan.
	- $W_i \neq W_j$, za $i \neq j$.
	- $X_i \neq Y_i$, za $1 \leq i \leq M$.
	- Dozvoljeno je da više planova predlaže liniju između neke dve stanice (ali sa različitom cenom).
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[7 poena]:** $M \leq 9$.
	-   **[11 poena]:** Svaki plan metro linije pripada najviše jednom *ciklusu* (pogledati napomenu)
	-   **[9 poena]:** $N, M \leq 5000$ i postoji najjeftiniji metro plan tako da iz svake stanice postoji najviše dve metro linije.
	-   **[12 poena]:** Postoji najjeftiniji metro plan tako da iz svake stanice postoji najviše dve metro linije.
	-   **[20 poena]:** $N, M \leq 5000$.
	-   **[41 poena]:** Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `tsm.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`vector<int> NadjiPoredak(int N, int M, int* X, int* Y, int* W);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$ i $M$.
	* U narednih $M$ redova po tri broja u svakom redu, $X_i$ $Y_i$ $W_i$.
	
	Zatim ovaj program poziva vašu funkciju i štampa poredak koji je vratila vaša funkcija.
	
	## Napomena
	Kažemo da je poredak grana $a$ leksikografski veći od poretka $b$ ako važi da je težina grane $a_i$ veća od težine grane $b_i$, za najmanje $i$ za koje te težine nisu jednake.
	
	Ciklus je niz stanica $x_1 x_2 \ldots x_k$ za neko $k$, gde važi da $x_1 = x_k$, nijedna druga stanica se ne pojavljuje više od jedanput i postoji plan metro linija koji direktno povezuje stanice $x_i$ i $x_{i+1}$ za svako $1 \leq i < k$. Kažemo da ti planovi metro linija pripadaju tom ciklusu.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Mladen Puzić | Mladen Puzić | Mladen Puzić | Tadija Šebez |
	
	## Rešenje kada $M \leq 9$
	Prvo nađimo neko minimalno razapinjuće stablo grafa koji dobijemo kada kao grane dodamo svaki metro plan (u daljem tekstu MST). Za to možemo koristiti neki poznati algoritam, poput Kruskalovog ili Primovog. Nakon toga, za svaki mogući poredak proverimo da li nam daje MST i od takvih uzimamo leksikografski najveći.
	
	Vremenska složenost je $O(M! \cdot M \cdot \alpha(M))$, a memorijska $O(M)$.
	
	## Rešenje kada se svaki plan linije nalazi u najviše jednom ciklusu
	Ovakav graf se zove *kaktus graf*. Možemo lako zaključiti da je u kaktus grafu, da bismo dobili MST, potrebno da u svakom ciklusu u grafu izbacimo najskuplju granu. Što znači, da se najskuplja grana mora naći u poretku nakon svih drugih grana u tom ciklusu.
	
	Pošto je u pitanju kaktus graf, lako možemo *DFS* algoritmom naći sve cikluse (npr. posmatranjem svih povratnih grana), i tako svesti problem na spajanje $K$ nizova na leksikografski najveći način, što je poznat problem koji se može rešiti primenom prioritetnog reda (*std::priority_queue*).
	
	Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.
	
	## Rešenje kada je MST put i $N,M \leq 5000$
	Pošto su cene svih grana različite, MST je jedinstven. Dakle, nađimo MST i znamo da će on biti put. Postavimo njegove grane redom u niz tako da je jedan kraj puta indeksiran sa $1$, a drugi sa $N-1$.
	
	Sada, za svaku granu koja nije u MST, recimo da povezuje stanice $x$ i $y$, mora da važi da se nalazi u permutaciji nakon svih grana na putu između $x$ i $y$ u MST. Ako to ne važi, dodali bismo skuplju granu, a kasnije ne bismo mogli da dodamo jeftiniju, što znači da ne bismo dobili MST. Taj put odgovara nekom intervalu u našem nizu.
	
	Sada možemo konstruisati novi, usmereni, graf, gde su planirane metro linije čvorovi, a grana od čvora $u$ do čvora $v$ postoji isključivo ako linija $u$ mora da se nađe pre linije $v$ u krajnjem poretku. Ove grane možemo lako naći prolaskom kroz niz za svaku granu van MST.
	
	Sada se problem svodi na leksikografski najveće topološko sortiranje, koje je moguće jer svi čvorovi imaju različite cene. Možemo ga uraditi prioritetnim redom.
	
	Vremenska složenost: $O(M^2\log M$), a memorijski $O(M^2)$.
	
	## Rešenje kada je MST put
	Slično prethodnom podzadatku, nalazimo MST i za svaku granu van njega znamo da sve grane na tom putu se moraju nalaziti pre nje. Ono što je potrebno da primetimo jeste da ćemo grane na tom putu dodavati opadajuće po ceni, tj. ako želimo leksikografski najveći poredak, nema razloga da dodamo manju granu MST-a pre veće.
	
	Zato, umesto da konstruišemo sve grane usmerenog grafa, dovoljno je konstruisati granu između najjeftinije grane na određenom intervalu i grane koju posmatramo. To je dovoljno ograničava, jer znamo da po tranzitivnosti onda neće se javiti pre nijedne grane na putu.
	
	Sada možemo raditi topološko sortiranje kao u prethodnom podzadatku, samo što ovaj put imamo mnogo manje grana. Takođe, možemo primetiti da je moguće i raditi leksikografsko spajanje $K$ nizova kao u drugom zadatku.
	
	Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.
	
	## Rešenje kada $N, M \leq 5000$
	Slično podzadatku u kome je MST put, samo kako bismo našli grane usmerenog grafa, potrebno je da prođemo kroz put na MST, umesto kroz interval niza. Ovo možemo uraditi tako što korenujemo stablo u nekom čvoru, pa pamtimo roditelja za svaki čvor.
	
	Vremenska složenost: $O(M^2\log M$), a memorijski $O(M^2)$.
	
	## Glavno rešenje
	Slično podzadatku u kome je MST put, samo kako bismo našli grane usmerenog grafa, potrebno je da efikasno nađemo najmanju granu na putu MST, umesto na intervalu niza. Ovo možemo uraditi preko tehnike binarnog podizanja (*binary lifting*). Korenujemo MST u proizvoljnom čvoru, nađemo pretka svakog čvora (za pretka korena stavimo samog sebe). Nakon toga, za svaki čvor i za svako $l$ od $0$ do $\log N$ pamtimo najmanju granu ako se $2^l$ grana penjemo na gore. To nam može pomoći da u $O(\log N)$ nađemo minimum na bilo kom putu (slično algoritmu traženja minimalnog zajedničkog pretka).
	
	Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.
	
	``` cpp title="02_tsm.cpp" linenums="1"
	#include <vector>
	#include <queue>
	#include <iostream>
	#include <algorithm>
	#define PRINT(x) cerr<<#x<<'='<<x<<endl;
	#define pii pair<int, int>
	#define fi first
	#define se second
	#define MAXN 300010
	#define MAXL 20
	#define INF 1000000001
	using namespace std;
	vector<pii> adj[MAXN], e;
	vector<int> v[MAXN];
	vector<pair<int, pii> > ec, add;
	priority_queue<pii> pq;
	int dsu[MAXN], anc[MAXN][MAXL], minn[MAXN][MAXL], in[MAXN], out[MAXN], timer;
	
	int root(int x) {
	  while(x != dsu[x]) {
	    dsu[x] = dsu[dsu[x]];
	    x = dsu[x];
	  }
	  return x;
	}
	bool connect(int x, int y) {
	  int rtX = root(x), rtY = root(y);
	  if(rtX == rtY) return false;
	  dsu[rtX] = rtY;
	  return true;
	}
	
	void dfs(int node, int prev, int nodeIdx) {
	  in[node] = ++timer;
	  anc[node][0] = prev;
	  minn[node][0] = nodeIdx;
	  for(auto x : adj[node]) {
	    if(x.fi != prev) {
	      dfs(x.fi, node, x.se);
	    }
	  }
	  out[node] = ++timer;
	}
	int W(int idx) {
	  return ec[idx].fi;
	}
	
	bool inSubtree(int x, int y) { ///da li je x u y
	  return in[y] <= in[x] && out[x] <= out[y];
	}
	int find_min(int x, int y) {
	  int minIdx = 0;
	  int _x = x, _y = y;
	  for(int l = MAXL-1; l >= 0; l--) {
	    if(!inSubtree(y, anc[_x][l])) {
	      if(W(minn[_x][l]) < W(minIdx)) minIdx = minn[_x][l];
	      _x = anc[_x][l];
	    }
	    if(!inSubtree(x, anc[_y][l])) {
	      if(W(minn[_y][l]) < W(minIdx)) minIdx = minn[_y][l];
	      _y = anc[_y][l];
	    }
	  }
	  if(!inSubtree(y, _x)) {
	    if(W(minn[_x][0]) < W(minIdx)) minIdx = minn[_x][0];
	  }
	  if(!inSubtree(x, _y)) {
	    if(W(minn[_y][0]) < W(minIdx)) minIdx = minn[_y][0];
	  }
	  return minIdx;
	}
	
	vector<int> NadjiPoredak(int N, int M, int* X, int* Y, int* w) {
	  ec.push_back({INF, {1, 1}});
	  for(int i = 1; i <= M; i++) {
	    e.push_back({w[i], i});
	    ec.push_back({w[i], {X[i], Y[i]}});
	  }
	  for(int i = 1; i <= N; i++) dsu[i] = i;
	  sort(e.begin(), e.end());
	  for(auto edge : e) {
	    int w = edge.fi, x = ec[edge.se].se.fi, y = ec[edge.se].se.se;
	    if(connect(x, y)) {
	      adj[x].push_back({y, edge.se});
	      adj[y].push_back({x, edge.se});
	      pq.push({w, edge.se});
	    } else {
	      add.push_back({edge.se, {x, y}});
	    }
	  }
	  dfs(1, 1, 0);
	  for(int l = 1; l < MAXL; l++) {
	    for(int i = 1; i <= N; i++) {
	      anc[i][l] = anc[anc[i][l-1]][l-1];
	
	      minn[i][l] = minn[i][l-1];
	      if(W(minn[i][l]) > W(minn[anc[i][l-1]][l-1])) {
	        minn[i][l] = minn[anc[i][l-1]][l-1];
	      }
	    }
	  }
	
	  for(auto edge : add) {
	    v[find_min(edge.se.fi, edge.se.se)].push_back(edge.fi);
	  }
	  vector<int> sol;
	  while(!pq.empty()) {
	    pii vrh = pq.top(); pq.pop();
	    sol.push_back(vrh.fi);
	    if(vrh.se != 0) {
	      for(auto x : v[vrh.se]) {
	        pq.push({W(x), 0});
	      }
	    }
	  }
	  return sol;
	}
	/*
	4 5
	1 2 50
	2 3 10
	2 4 20
	3 4 30
	1 4 40
	
	5 5
	2 5 12
	2 4 3
	1 2 50
	1 4 11
	3 4 36
	*/

	```
