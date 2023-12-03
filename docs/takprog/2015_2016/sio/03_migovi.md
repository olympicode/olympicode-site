---
hide:
  - toc
---

# 3 - Migovi

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	U prvoj polovini 20. veka, umesto velikog naučnog napretka, dominatni su bili vojni sukobi. Poznato je da su velika imena nauke, poput Alana Tjuringa i Džona fon Nojmana, dali veliki doprinos za brži završetak ovih sukoba. Nažalost, ljudi lako zaboravljaju istoriju, pa i dan-danas često nije bitno da li neko ima britak um i visoko obrazovanje već da li ima veliku vojsku i moderne Migove 323...
	
	Jedan od najpoznatijih generala današnjice, Dimi Gavi, najviše od svega voli da gleda paradu svojih N najmodernijih Migova 323 na nebu i zamišlja da je Maverik iz Top Gan-a. Međutim, Dimi Gavi ne voli svež vazduh pa ih on ne gleda na nebu već na monitoru svog radara na kome se migovi vide kao tačkice. Svaki od migova se kreće u jednom od 4 smera (gledano na ekranu, ti smerovi su: gore, desno, dole i levo) i svi se kreću istom brzinom od 1 kilometra u sekundi. Dimi Gavi kaže da je rastojanje između dva miga, koja se nalaze na pozicijama $(x_1,y_1)$ i $(x_2,y_2)$ u koordinatnom sistemu ekrana, jednako $x_1-x_2+|y_1-y_2|$ i svi to poštuju.
	
	Dimi Gavi posmatra svaka dva miga i u trenutku kada oni budu na najmanjem mogućem međusobnom rastojanju (to može biti u početnom trenutku ili u nekom kasnijem trenutku) on uzvikne “Danger Zone!” i zabeleži to rastojanje. Zatim sva ta rastojanja sabere. Zatim ode kući. Na vama je da, znajući početne pozicije i smerove kretanja svih migova, odredite koji je rezultat dobio Dimi Gavi.
	
	  
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	ZbirRastojanja($N$, $x$, $y$,$s[…]$)
	
	gde je $N$ – broj migova a $x$, $y$ i $s$ nizovi koji opisuju migove: $i$-ti mig se nalazi na poziciji $(x_i, y_i)$ i, ukoliko je $s_i=0$, on se kreće nagore, ukoliko je $s_i=1$, on se kreće udesno, ukoliko je si=2, on se kreće nadole i ukoliko je si=3 on se kreće ulevo. Svi nizovi su indeksirani od 0. Ova funkcija mora da vrati jedan ceo broj – zbir najmanjih mogućih rastojanja između svaka dva miga .
	
	  
	
	## Primer:
	
	Neka $N=3$, $x=[0, 3, 5]$, $y=[3, 0, 4]$ i $s=[0, 1, 2]$. Ovi podaci označavaju da imamo 3 miga: prvi je na poziciji 0,3 i ide nagore, drugi je na poziciji (3,0) i ide udesno i treći je na poziciji (5,4) i ide nadole. Najmanje međusobno rastojanje između prvog i drugog miga se dostiže u nultom trenutku i iznosi 0-3+3-0=6. Najmanje rastojanje između prvog i trećeg miga je 5 i dostiže se posle pola sekunde (ako pretpostavimo da su jedinična rastojanja – kilometri). Najmanje rastojanje između drugog i trećeg miga je 2 (dostiže se u više trenutaka, npr. u trećoj sekundi). Prema tome, u ovom slučaju vaša funkcija mora da vrati broj 6+5+2=13.
	
	  
	
	## Ograničenja
	
	-   $2≤N≤200.000$
	    
	-   Za svako $i=[0,N-1]$ važi $-5⋅10^7≤x_i, y_i≤5⋅10^7$ i $s_i \in \{0, 1, 2, 3\}$
	    
	-   Sve koordinate su celi brojevi
	    
	-   Nikoja dva miga nemaju iste početne koordinate
	    
	
	## Podzadaci i bodovanje
	
	-   PODZADATAK 1 [9 POENA]: $N≤1.000$.
	    
	-   PODZADATAK 2 [18 POENA]: Svi migovi se kreću nagore tj. $s_i=0$ za svako $i$.
	    
	-   PODZADATAK 3 [24 POENA]: Svaki mig se kreće ili levo ili desno tj. $s_i∈\{1,3\}$ za svako $i$.
	    
	-   PODZADATAK 4 [49 POENA]: Nema dodatnih ograničenja.
	    
	
	  
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom migovi.c, migovi.cpp ili migovi.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	C/C++
	
	long long ZbirRastojanja(int N, int* x, int* y, int* s);
	
	Pascal
	
	function ZbirRastojanja(N : longint; var x, y, s : array of longint) : int64;
	
	  
	
	Ukoliko radite u C/C++ -u, potrebno je na početku fajla staviti #include “migovi.h” a ukoliko radite u Pascal -u, potrebno je na početku fajla staviti Unit migovi; (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	  
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam “template” fajlovi (migovi.c, migovi.cpp, migovi.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu broj $N$
	    
	-   U sledećih $N$ redova brojeve $x_i, y_i, s[i]$, redom, razdvojene razmakom
	    
	
	a zatim pozivaju vašu funkciju ZbirRastojanja iz odgovarajućeg fajla (migovi.c, migovi.cpp, migovi.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Boris Grubić |
	
	Formulacija zadatka je prilično jednostavna a jasno je i da se radi sa standardnim **Menhetn-rastojanjem<sup>1</sup>** između tačaka koje poseduje nekoliko korisnih osobina koje ćemo i eksploatisati. Koristićemo termine $U$-mig, $R$-mig, $D$-mig i $L$-mig za migove čiji su smerovi kretanja, redom, gore, desno, dole i levo. Takođe, za par migova ćemo reći da čine $ort$--par (ortogonalni par) ukoliko su im smerovi kretanja normalni jedan na drugi, a inače oni čine $par$--par (paralelni par); intuitivno je jasno da će nam veći problem praviti $ort$--parovi. Da bismo došli do optimalnog alogritma najlakše (i najprirodnije) je rešavati podzadatke redom.
	
	## Podzadatak $1$
	Na osnovu ograničenja, jasno je da je ovde dovoljan trivijalan alogoritam koji određuje minimalna rastojanja između svaka dva miga (posebno) u složenosti $O(N^2)$. Ipak, sama implementacija zahteva analizu nekoliko slučajeva a jedan od pametnijih načina je sledeći: neka su $i(x_i, y_i)$ i $j(x_j, y_j)$ dva miga; nije teško uočiti da je minimalno rastojanje između $i$ i $j$ upravo njihovo menhetn-rastojanje  $|x_i -x_j| + |y_i - y_j|$ osim u slučaju kada oni čine $par$--par i kreću se jedan ka drugom ili $ort$--par i oba idu ka presečnoj tački (tada su tražena rastojanja manja). Za poslednja dva slučaja treba oduzeti odgovarajući "višak" a tu tehniku ćemo koristiti i u narednim podzadacima.
	
	## Podzadatak $2$
	Kako svi migovi idu nagore jednakim brzinama, njihova međusobna rastojanja ostaju ista pa možemo zamisliti da se ne kreću. Problem se svodi na (poznat) problem određivanja sume svih menhetn-rastojanja (po parovima) datih $N$ tačaka. Kako je menhetn rastojanje nezavisno po koordinatama, tj. $\sum_{1 \leq i < j \leq n} (|x_i - x_j| + |y_i - y_j|) = \sum_{1 \leq i < j \leq n} |x_i - x_j| + \sum_{1 \leq i < j \leq n} |y_i - y_j|$, problem se svodi na izračunavanje izraza $F(a) = \sum_{1 \leq i < j \leq n} |a_i - a_j|$ za dati niz $a$. Suma ne zavisi od pozicija elemenata u nizu već samo od njihovih vrednosti pa sortiranjem niza $a$ ($a_1 \leq a_2 \leq \ldots \leq a_N$) "gubimo" apsolutne vrednosti i nakon malo transformacija dobijamo $F(a) =  \sum_{1 \leq i < j \leq n} (a_j - a_i) = \sum_{j = 1}^N (j\cdot a_j - p_{j-1})$ gde je $p$ niz prefiksnih suma tj. $p_i = a_1 + a_2 + \ldots + a_i$.
	
	Izraz za $F(a)$ smo posle sortiranja mogli transformisati i na drugi način: za svako $k$, vrednost $a_k$ se u sumi $\sum_{1 \leq i < j \leq n} (a_j - a_i)$ javlja tačno $k-1$ puta sa predznakom "$+$" i tačno $N - k$ puta sa predznakom "$-$" (toliko ima manjih/većih vrednosti od $a_k$) pa dobijamo da je $F(a) = \sum_{k=1}^N (k - 1 - (N - k)) \cdot a_k = \sum_{k=1}^N (2k - N - 1)\cdot a_k$. U oba slučaja je jasno da se suma može izračunati u složenosti $O(N)$ pa se računanje izraza $F(x) + F(y)$ može odraditi u složenosti $O(N \log N)$ (zbog sortiranja) što je dovoljno za ovaj podzadatak.
	
	## Podzadatak $3$
	U ovom podzadatku svaki par migova čini $par$--par pri čemu se $y$ koordinate migova ne menjaju. Primetimo da je minimalno rastojanje između migova $i$ i $j$ jednako $|y_i - y_j|$ ukoliko idu "jedan drugom u susret" (jer će u nekom trenutku biti $|x_i - x_j| = 0$), odnosno $|x_i - x_j| + |y_i - y_j|$ u ostalim slučajevima (tada se vrednost $|x_i - x_j|$ neće smanjivati).  Dakle, i dalje možemo posmatrati odvojeno $x$ i $y$ koordinate a jedan od najlakših načina za rešavanje ovog podzadatka je izračunati tražena rastojanja pod pretpostavkom da se migovi ne pomeraju (u složenosti $O(N \log N)$ kao u prethodnom zadatku) a zatim od dobijenog rezultata oduzeti "višak", tj. oduzeti po $|x_i - x_j|$ za svaka dva miga $i$ i $j$ koji idu jedan drugom u susret.
	
	Ukoliko neopadajuće sortiramo $x$ koordinate migova, problem se svodi na efikasno računanje sume svih $|x_j - x_i|$ za svako $i < j$ gde je mig $i$ $R$-mig a mig $j$ $L$-mig. Očekivano, ovo se može uraditi u složenosti $O(N)$: dovoljno je kretati se s leva na desno i u svakom trenutku pamtiti vrednosti $sumR$ i $numR$ koji, redom, predstavljaju sumu $x$--koordinata i broj svih prethodnih $R$-migova. Ukoliko je $i$-ti mig $R$-mig, odradimo $update$ trenutnih vrednosti a u suprotnom našoj traženoj sumi treba dodati vrednost $numR \cdot x_i - sumR$ (trenutni mig će "poništiti" rastojanja za svih $numR$ $R$-migova sa njegove leve strane). Dakle, ukupna složenost za ovaj podzadatak je $O(N\log N)$.
	
	## Podzadatak $4$
	Ovde nastaje pravi problem jer je zbog $ort$--parova nemoguće posmatrati nezavisno $x$ i $y$ koordinate. Zaista, ukoliko migovi $i$ i $j$ čine $ort$--par i oba idu ka presečnoj tački (nazovimo ovakve parove *loši*), tada će oni (prvi put) dostići minimalno rastojanje kada mig koji je bliži tački preseka dođe u istu -- tada je rastojanje $||x_i - x_j| - |y_i - y_j||$ i ne može se lepo "razložiti" na koordinate. 
	
	<figure style="text-align:center">
	  <img src="Migovi_Image_Dist_And_Triangle.png" alt="Rastojanje i podela oblasti" width="700">
	  <figcaption> *Slika $1$:  $a)$ minimalno rastojanje kod lošeg para; $b)$ Podela gornjeg-desnog kvadratna za $R$-miga $(x_i, y_i)$ na dva beskonačna trougla: "gornji trougao" (oblast $I$) ograničen pravama $x = x_i$ i $y = x + (y_i - x_i)$ i "donji trougao" (oblast $II$) ograničen pravama $y = y_i$ i $y = x + (y_i - x_i)$.* </figcaption>
	</figure> 
	
	Prethodni izraz možemo transformisati u $|x_i - x_j| + |y_i - y_j| - 2 \cdot \min\{|x_i - x_j|, |y_i - y_j|\}$ sa motivacijom da primenimo metod "oduzimanja viška": ukoliko saberemo sva početna međusobna rastojanja (podzadataka $2$) a zatim oduzmemo višak za $par$--parove (Podzadatak $3$, posebno za grupu $L/R$-migova i grupu $U/D$-migova) ostaje samo da za svaki loš par migova $i$ i $j$ oduzmemo vrednost $2 \cdot \min\{|x_i - x_j|, |y_i - y_j|\}$. Loše parove možemo, zavisno od smerova migova, podeliti u $4$ disjunktne grupe ($RD$, $DL$, $LU$ i $UR$) koje se (očekivano) rešavaju na simetričan način. Zbog toga opisujemo rešenje samo za $RD$ grupu, tj. problem se svodi na efikasno računanje sume
	$$2\sum_{\substack{i \in R, \enspace j \in D \\ (i,j) \text{ je loš par}}} \min\{|x_i - x_j|, |y_i - y_j|\}.$$ Koristeći činjenicu da su za dati $R$-mig $i$ svi migovi koji čine loš par sa njim upravo $D$-migovi koji su "gore-desno" od njega (tj. $D$-migovi $j$ za koje važi $x_i \leq x_j$ i $y_i \leq y_j$) problem se (posle izbacivanja faktora $2$) dodatno svodi na računanje izraza
	$$\sum_{i \in R} \sum_{\substack{j \in D, \\ x_i \leq x_j, \; y_i \leq x_j}} \min\{x_j - x_i, y_j - y_i\}$$ Za izbacivanje nezgodnog minimuma, uvedimo sledeće oznake na osnovu Slike $1$: za dati $R$-mig $i$ neka su $T_x(i)$ i $T_y(i)$, redom, skupovi svih $D$-migova koji se nalaze "gornjem trouglu" (oblast $I$), odnosno "donjem trouglu" (oblast $II$) miga $i$.  Nije teško videti da ako $j \in T_x(i)$ tada $x_j - x_i \leq y_j - y_i$ i da iz $j \in T_y(i)$ sledi $y_j - y_i \leq x_j - x_i$. Sada prethodnu sumu možemo napisati kao $$\sum_{i \in R}\sum_{j \in T_x(i)} (x_j - x_i) + \sum_{i \in R}\sum_{j \in T_y(i)} (y_j - y_i).$$ Zbog simetrije, koncentrisaćemo se na levu sumu prethodnog izraza. Za početak, možemo se obezbediti da unutrašnja suma što manje zavisi od $i$: neka je $n_i = |T_x(i)|$ (broj $D$-migova u trouglu) i $s_i = \sum_{j \in T_x(i)} x_j$ (suma $x$ koodinata $D$-migova iz trougla). Konačno, prethodna desna suma se svodi na $$\sum_{i \in R} (s_i - n_i \cdot x_i).$$ U ovom trenutku (a iskusni takmičar to može shvatiti mnogo ranije) problem možemo konačno svesti na efikasno odgovaranje na upite sledećeg tipa: za datu tačku $(x_i, y_i)$, odrediti broj tačaka (kao i zbir njihovih $x$ koordinata) koje leže u "donjem trouglu" određenom tačkom $(x_i, y_i)$. Standardni pokušaj je sortirati $R$ i $D$-migove zajedno po nekom parametru a zatim ih redom obilaziti ($sweep$) i prilikom nailaska na $D$-miga vršiti ubacivanje u neku strukturu a prilikom nailaska na $R$-miga vršiti upit nad tom strukturom. Najprirodniji pristup -- $sweep$ po jednoj koordinati a određivanje pozicija u strukturi po drugoj, ovde ne prolazi jer trouglovi nisu samo određeni pravama paralelnim $x$ i $y$-osama već i pravama paralenim pravoj $y = x$. **I upravo je ključni deo zadatka raditi $sweep$ po pravama paralelnih pravoj $y = x$ u smeru "gore-levo" $\rightarrow$ "dole-desno".** 
	
	Preciznije, prvo sortiramo migove neopadajuće po vrednosti $x_i - y_i$; u tom redosledu ćemo ih obilaziti. Dodatno za svakog miga $i$ izračunamo $pos_i$ -- pozicija u nizu na kojoj bi se mig našao ukoliko bismo ih sve sortirali po $x$ koordinatama. Prilikom obilaska u gore pomenutom redosledu, mi nailazimo na migove i, zavisno od tipa miga, radimo sledeće (vidi Sliku $2$):
	
	* $D$-mig $j$: ubacujemo mig $j$ u pomoćni niz $A$ na poziciji $pos_j$.
	* $R$-mig $i$: računamo broj migova i sumu $x$ koordinata svih migova koji se nalaze u segmentu $[pos_i, N]$ u nizu $A$. Činjenica da je neki mig $j$ već u nizu $A$ i da je $pos_j > pos_i$ je ekvivalentna sa $x_j - y_j \leq x_i - y_i$ i $x_j \geq x_i$ što je uslov da $j$ pripada "gornjem trouglu", tj. $j \in T_x(i)$.
	
	
	
	Zbog prirode upita, jasno je da umesto niza $A$ možemo koristiti **Segmentno stablo<sup>2</sup>** ili **Kumulativnu tabelu<sup>3</sup>** i postići složenost $O(\log N)$ za svaki od pomenuta dva upita/događaja, pa gore pomenutu sumu $\sum_{i \in R} (s_i - n_i \cdot x_i)$ možemo izračunati u složenosti $O(N \log N)$.  Analogno računamo sumu i za "donje trouglove" -- tada radimo obrnuti obilazak ("dole-desno" $\rightarrow$ "gore-levo") a niz $pos$ se odnosi na $y$ koordinate. Sve ovo radimo $4$ puta (za svaku grupu loših parova) pa je ukupna složenost algoritma $O(N \log N)$.
	
	## Detalji implementacije
	
	Iz opisa optimalnog rešenja vidi se da je potrebno odraditi $8$ sličnih $sweep$-ova vršeći odgovarajuće upite (po dva obilaska za svaku od $4$ grupe). Ovde nikako ne treba raditi sa $8$ različitih oblasti od interesa ("trouglova") i $8$ puta dužim kodom, već svaku grupu loših parova svesti na $RD$ grupu rotacijom ravni za $90^\circ$ i pozivom iste funkcije. Dodatno, dva pomenuta $sweep$-a u okviru iste grupe je moguće implementirati pozivom iste funkcije ukoliko se strukturi kao parametar prenosi i informacija da li se radi o $x$ ili $y$ osi. Takođe, potrebno je preciznije u kodu definisati "gornji i donji trougao", tj. odrediti kome od njih pripadaju migovi na dijagonali da se ne bi računali dva puta. Napomenimo i to da smo $sweep$ mogli raditi po nekoj od osa a niz $pos$ indeksirati na osnovu razlika $x_i - y_i$.
	
	
	``` cpp title="03_migovi.cpp" linenums="1"
	#include "migovi.h"
	
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	
	using namespace std;
	
	const int MAX_N = 200020;
	const int TREE_SIZE = (1 << 19);
	const int X_AXIS = 0;
	const int Y_AXIS = 1;
	const int DIR_UP = 0;
	const int DIR_RIGHT = 1;
	const int DIR_DOWN = 2;
	const int DIR_LEFT = 3;
	
	struct Mig
	{
		long long x, y;
		int s;
		int posx, posy;
		Mig(int x, int y, int s) : x(x), y(y), s(s) {}
		Mig() {}
	};
	
	Mig migs[MAX_N];
	long long pos[MAX_N];
	long long dir[MAX_N];
	long long sol;
	
	bool cmpX(const Mig& m1, const Mig& m2)
	{
		if (m1.x != m2.x) return (m1.x < m2.x);
		return (m1.y < m2.y);
	}
	
	bool cmpY(const Mig& m1, const Mig& m2)
	{
		if (m1.y != m2.y) return (m1.y < m2.y);
		return (m1.x < m2.x);
	}
	
	bool cmpDiffXY(const Mig& m1, const Mig& m2)
	{
		if (m1.x - m1.y != m2.x - m2.y) return (m1.x - m1.y < m2.x - m2.y);
		return (m1.x < m2.x);
	}
	
	struct SegmentTree
	{
		int axis;
		int count[TREE_SIZE];
		long long sum[TREE_SIZE];
	
		void init(int axis)
		{
			this->axis = axis;
			memset(count, 0, sizeof(count));
			memset(sum, 0, sizeof(sum));
		}
	
		// add value val at position pos
		void add(int pos, long long val)
		{
			pos = pos + (TREE_SIZE >> 1) - 1;
			while (pos > 0)
			{
				count[pos] = count[pos] + 1;
				sum[pos] = sum[pos] + val;
				pos = (pos >> 1);
			}
		}
	
		// calculate sum[l..r] - count[l..r] * val
		long long calculate(int node, int node_L, int node_R, int l, int r, long long val)
		{
			if (node_R < l || node_L > r)
				return 0;
			if (l <= node_L && node_R <= r)
				return (sum[node] - val * count[node]);
	
			int node_M = (node_L + node_R) >> 1;
			return calculate((node << 1), node_L, node_M, l, r, val) + calculate((node << 1) + 1, node_M + 1, node_R, l, r, val);
		}
	
		void addMig(Mig& mig)
		{
			if (axis == X_AXIS)
				add(mig.posx, mig.x);
			else
				add(mig.posy, mig.y);
		}
	
		long long extraSum(Mig& mig)
		{
			if (axis == X_AXIS)
				return calculate(1, 1, (TREE_SIZE >> 1), mig.posx, (TREE_SIZE >> 1), mig.x);
			else
				return calculate(1, 1, (TREE_SIZE >> 1), mig.posy, (TREE_SIZE >> 1), mig.y);
		}
	
	
	};
	
	SegmentTree xTree, yTree;
	
	long long SolveByCoordinate(int N, Mig* migs, int axis, int forwardDir, int backDir)
	{
		long long res = 0LL;
	
		if (axis == X_AXIS)
			sort(migs, migs + N, cmpX);
		else
			sort(migs, migs + N, cmpY);
	
		for (int i = 0; i < N; i++)
		{
			dir[i] = migs[i].s;
			pos[i] = (axis == X_AXIS ? migs[i].x : migs[i].y);
		}
	
		// suma svih |pos[i] - pos[j]|
		long long totalSum = 0LL;
		for (int i = 0; i < N; i++)
		{
			res = res + (pos[i] * i - totalSum);
			totalSum = totalSum + pos[i];
		}
	
		// oduzeti rastojanja izmedju onih migova koji idu jedan ka drugom
		long long forwardSum = 0LL;
		long long forwardNum = 0LL;
		for (int i = 0; i < N; i++)
		{
			if (dir[i] == backDir)
			{
				res = res - (pos[i] * forwardNum - forwardSum);
			}
			else if (dir[i] == forwardDir)
			{
				forwardNum = forwardNum + 1;
				forwardSum = forwardSum + pos[i];
			}
		}
	
		return res;
	}
	
	// Rotiramo ravan za 90 stepeni ulevo
	void RotateLeft(int N, Mig* migs)
	{
		for (int i = 0; i < N; i++)
		{
			migs[i].s = (migs[i].s + 3) % 4;
			long long x = migs[i].x;
			long long y = migs[i].y;
			migs[i].x = -y;
			migs[i].y = x;
		}
	}
	
	// Kompenzacija koju treba oduzeti za migove koji idu
	// udesno i na dole jedan ka drugom
	long long SolveRightDown(int N, Mig* migs)
	{
		long long ret = 0LL;
	
		sort(migs, migs + N, cmpX);
		for (int i = 0; i < N; i++)
			migs[i].posx = i + 1;
	
		sort(migs, migs + N, cmpY);
		for (int i = 0; i < N; i++)
			migs[i].posy = i + 1;
	
		sort(migs, migs + N, cmpDiffXY);
	
		xTree.init(X_AXIS);
		for (int i = 0; i < N; i++)
		{
			if (migs[i].s == DIR_RIGHT)
			{
				ret = ret + xTree.extraSum(migs[i]);
			}
			if (migs[i].s == DIR_DOWN)
			{
				xTree.addMig(migs[i]);
			}
		}
	
		yTree.init(Y_AXIS);
		for (int i = N - 1; i >= 0; i--)
		{
			if (migs[i].s == DIR_RIGHT)
			{
				ret = ret + yTree.extraSum(migs[i]);
			}
			if (migs[i].s == DIR_DOWN)
			{
				yTree.addMig(migs[i]);
			}
		}
	
		return ret * 2;
	}
	
	
	long long ZbirRastojanja(int N, int * x, int * y, int * s)
	{
		for (int i = 0; i < N; i++)
			migs[i] = Mig(x[i], y[i], s[i]);
	
		sol = 0;
		// suma svih pocetnih rastojanja - kompenzacija za one koji idu jedni ka drugima
		sol = sol + SolveByCoordinate(N, migs, X_AXIS, DIR_RIGHT, DIR_LEFT);
		sol = sol + SolveByCoordinate(N, migs, Y_AXIS, DIR_UP, DIR_DOWN);
	
		// sada je potrebno za svaka dva miga koji idu normalno jedan ka drugom
		// oduzeti 2 * Min(distX, distY), gde su distX i distY pocenta rastojanja po x i y osi
		sol = sol - SolveRightDown(N, migs);
		RotateLeft(N, migs);
		sol = sol - SolveRightDown(N, migs);
		RotateLeft(N, migs);
		sol = sol - SolveRightDown(N, migs);
		RotateLeft(N, migs);
		sol = sol - SolveRightDown(N, migs);
	
		return sol;
	}

	```
