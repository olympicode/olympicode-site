---
hide:
  - toc
---

# 5 - Meteori

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 100ms | 256MB |
	
	U eri brzih i dramatičnih dešavanja u vasioni se desila eksplozija ogromnih razmera. Ona je izazvala pomeranje ogromnog broja meteora. Naučnici pokušavaju da izmodeliraju dešavanja u vasioni. Položaje meteora predstavljaju njihovim koordinatama u ravni. Iako je za očekivati da se meteori kreću u ogromnom broju različitih pravaca, svaki od njih se kreće u jednom od četiri pravca: na gore, na dole, udesno ili ulevo. Svi se kreću konstantnom brzinom od jednog metra po sekundi.
	
	Za objašnjavanje događanja, naučnici su zaključili da im treba konveksni omotač za skup tačaka koje odgovaraju pozicijama meteora po isteku $10^{1000}$ sekundi od eksplozije. Za to im treba vaša pomoć.
	
	## Opisi funkcija
	
	Potrebno je implementirati funkciju
	
	$$KonveksniOmotac(N, x[…],y[…],d[…])$$
	
	gde je $N$ - broj meteora, a $x$, $y$ i $d$ nizovi koji opisuju meteore: $i$-ti meteor se nalazi na poziciji $(x_i, y_i)$ i, ukoliko je $d[i]=0$, on se kreće na gore, ukoliko je $d[i]=1$, on se kreće udesno, ukoliko je $d[i]=2$, on se kreće na dole, a ukoliko je $d[i]=3$ on se kreće ulevo. Svi nizovi su indeksirani od 0. Ova funkcija mora da vrati jedan ceo broj – broj temena na konveksnom omotaču skupa tačaka koje predstavljaju pozicije meteora u toj dalekoj budućnosti. One tačke iz tog skupa, koje nisu temena konveksnog omotača, već se nalaze na stranicama poligona se ne računaju.
	
	## Primer:
	
	Neka $N=6$, $x=[1, 12, 7, 3, 5, 4]$, $y=[1, 2, 10, 4, 7, 8]$ i $d=[0, 2,1,2,3,0]$. Ovi podaci označavaju da imamo 6 meteora: prvi je na poziciji 1,1 i ide na gore, drugi je na poziciji (12,2) i ide na dole, treći je na poziciji (7,10) i ide udesno, četvrti na poziciji (3,4) ide na dole, peti na poziciji (5,7) ide ulevo i šesti na pozicji (4,8) ide na gore. Oba meteora koja idu na dole će biti na konveksnom omotaču. Meteor koji kreće sa pozicije (1,1) će biti unutar omotača. Meteori koji idu udesno i ulevo (po jedan) će biti na konveksnom omotaču. Tako je odgovor 5.
	
	## Ograničenja
	
	-   $4≤N≤100.000$
	    
	-   Za svako $i=[0,N-1]$ važi $-10^9≤x_i, y_i \leq 10^9$ i $d[i] \in \{0, 1, 2, 3\}$
	    
	-   Sve koordinate su celi brojevi
	    
	
	## Podzadaci i bodovanje
	
	-   PODZADATAK 1 [9 POENA]: $N≤1.000$.
	    
	-   PODZADATAK 2 [24 POENA]: Svi meteori se kreću na gore ili na dole (ali bar po jedan u svakom od ta dva smera) tj. $d[i]=0$ ili $d[i]=2$ za svako [i].
	    
	-   PODZADATAK 3 [18 POENA]: Koordinate meteora su brojevi između -5000 i 5000.
	    
	-   PODZADATAK 4 [49 POENA]: Nema dodatnih ograničenja.
	    
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom meteori.c, meteori.cpp ili meteori.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	C/C++
	
	int KonveksniOmotac(int N, int* x, int* y, int* d);
	
	Pascal
	
	function KonveksniOmotac(N : longint; var x, y, s : array of longint) : longint;
	
	  
	
	Ukoliko radite u C/C++ -u, potrebno je na početku fajla staviti #include “meteori.h” a ukoliko radite u Pascal -u, potrebno je na početku fajla staviti Unit meteori; (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam “template” fajlovi (meteori.c, meteori.cpp, meteori.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu broj $N$
	    
	-   U sledećih $N$ redova brojeve $x_i$, $y_i$, $d[i]$, redom, razdvojene razmakom
	    
	
	a zatim pozivaju vašu funkciju KonveksniOmotac iz odgovarajućeg fajla (meteori.c, meteori.cpp, meteori.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Dragan Urošević | Uroš Kostadinović | Ivan Stošić |
	
	Zadatak rešavamo koristeći neki od poznatih algoritama za konvkesni omotač poput "Graham scan" i "Monotone chain". Problem se javlja kada želimo da izračunamo vektorski proizvod zato što su koordinate reda veličine $10^{1000}$.
	
	## Prvi podzadatak:
	Možemo implementirati množenje, sabiranje i oduzimanje velikih brojeva koristeći niske. Primetimo takođe da je dovoljno posmatrati poziciju $10^{200}$ sekundi nakon eksplozije te će množenje niskih biti dovoljno brzo.
	
	## Drugi podzadatak:
	U daljem tekstu $\aleph$ predstavlja $10^{1000}$. Označimo sa $U$ skup svih meteora koji idu nagore i sa $D$ skup svih meteora koji idu nadole. Ako želimo da odredimo da li tačka $C$ ima desni ili levi zaokret u odnosu na (orijentisanu) duž $AB$ posle $\aleph$ sekundi razmotrićemo sledeće slučajeve: 
	
	1.  $A,B,C\in U$: U ovom slučaju možemo izračuanti orjentaciju pre eksplozije. 
	
	2. $A,B\in U$ i $C\in D$: Ako $A_x=B_x$ onda se prava $AB$ neće translirati i zbog toga možemo da uporedimo $C_x$ sa $A_x$ i $A_y$ sa $B_y$. U suprotnom pošto će se prava $AB$ translirati za $\aleph$ nagore, tačka $C$ će biti ispod prave $AB$ posle eksplozije pa će zbog toga biti desni zaokret ako $B_x>A_x$, a inače levi.
	
	3. $A,C\in U$ i $B\in D$: Koeficijent prave $AB$ će biti reda $10^{991}$ i $A$ i $C$ se neće pomeriti relativno (ostaju "blizu" jedna drugoj za razliku od tačke $B$), $|A_x-C_x| \leq 2\cdot 10^9$, $|A_y-C_y| \leq 2\cdot 10^9$ te će zaokret $C$ u odnusu na $AB$ biti isti kao i zaokret $C$ u odnosu na $AD$ gde je $D=(A_x,B_y)$.
	
	Svaki od ostalih 5 slučajeva je analogan nekom od prethodnih. Vremenska složenost je $O(N \log N)$, a memorijska $O(N)$.
	
	## Treći podzadatak:
	Dovoljno je na svaku kordinatu dodati odnosno oduzeti $10^9$ umesto $10^{1000}$ i naći konveksni omotač za te tačke. Ovo se može dokazati predstavljanjem brojeva kao parova slično kao u glavnom rešenju. Kada računamo vektorski proizvod nikada nećemo 
	množiti neki broj više od jednom. Zbog toga će nam drugi broj u uređenom paru biti maksimalno reda $O(M^2)$, gde je $|M| \leq 5000$, što će biti manje od $10^9$, pa će tad i $c$-u određivati znak. Vremenska složenost je $O(N \log N)$, a memorijska $O(N)$.
	
	## Glavno rešenje:
	Svaki broj $A$ ćemo predstaviti kao uređenu trojku $(a,b,c)$ tako da $A = a\cdot \aleph ^2 + b \cdot \aleph + c$ i $|a|,|b|,|c| < \aleph$. Definišimo sabiranje, oduzimanje i množenje dva para na sledeći način:
	 $$(a,b,c) + (d,e,f) = (a + d, b+e, c+f)$$
	 
	$$(a,b,c) - (d,e,f) = (a-d, b-e, c-f)$$
	
	$$(a,b,c)\cdot (d,e,f) = (a\cdot f + d\cdot c + b \cdot e, b\cdot f + e\cdot c, c \cdot f)$$
	
	U kodu $b$ član u uređenoj trojki $(a,b,c)$ nikad neće preći po apsolutnoj vrednosti $\aleph$ jer je ono preveliko, kao ni $a$ . U množenju dve trojke smo zanemarili vrednosti reda većeg od $\aleph ^2$ jer kada računamo vektorski proizvod nijednu trojku nećemo množiti više od jedamput, a svaka na početku ima $c = 0$.  Svaku tačku posle $\aleph$ vremena ćemo predstaviti kao uređen par uređenih trojki $((a,b,c),(d,e,f))$ gde su $c$ i $f$ koordinate tačke na početku, $b$ i $e$ određeni u odnosu na pravac i smer kretanja meteora, a $a = c = 0$. Možemo vektorski proizvod dva vektora da računamo koristeći prethodno definisane operacije. 
	
	Kada dobijemo $(a,b,c)$ kao rezultat potrebno je da proverimo znak broja $A = a\cdot \aleph^2 + b\cdot \aleph +c$. Ako $A\neq 0$ onda znak određuje član u uređenoj trojci s najvećom težinom.
	
	Vremenska složenost je $O(N \log N)$, a memorijska $O(N)$.
	
	``` cpp title="05_meteori.cpp" linenums="1"
	# include <stdio.h>
	# include <stdlib.h>
	
	# define MAXN 100100
	
	typedef struct {
	  int x, y;
	} tacka;
	
	int nc, na;
	int nau, nbu, ncu;
	int nad, nbd, ncd;
	int nal, nbl, ncl;
	int nar, nbr, ncr;
	tacka ct[MAXN];
	tacka atu[MAXN], btu[MAXN], ctu[MAXN];
	tacka atd[MAXN], btd[MAXN], ctd[MAXN];
	tacka atl[MAXN], btl[MAXN], ctl[MAXN];
	tacka atr[MAXN], btr[MAXN], ctr[MAXN];
	
	long long vecpr(tacka t1, tacka t2, tacka t3) {
	  long long x12, x13, y12, y13;
	  x12 = t2.x - t1.x;
	  y12 = t2.y - t1.y;
	  x13 = t3.x - t1.x;
	  y13 = t3.y - t1.y;
	  return x12 * y13 - x13 * y12;
	}
	
	double tang(tacka t1, tacka t2) {
	  if (t1.x == t2.x) {
	  	if (t2.y > t1.y) 
		  return 1000;
		else
		  return -1000;
	  }	
	  return (double)(t2.y - t1.y) / (t2.x - t1.x);
	}
	
	double tangje1(tacka t1, tacka t2) {
		return (t2.x - t1.x) == (t2.y - t1.y);
	}
	
	double tangjem1(tacka t1, tacka t2) {
		return (t2.x - t1.x) == (t1.y - t2.y);
	}
	
	
	double ctang(tacka t1, tacka t2) {
	  if (t1.y == t2.y) {
	  	if (t2.x > t1.x) 
		  return 1000;
		else
		  return -1000;
	  }	
	  return (double)(t2.x - t1.x) / (t2.y - t1.y);
	}
	
	int cmptackaxu(const void *p1, const void *p2) {
	  const tacka *pt1, *pt2;
	  pt1 = (const tacka *)p1;
	  pt2 = (const tacka *)p2;
	  if (pt1->x != pt2->x)
	    return pt1->x - pt2->x;
	  else
	    return pt1->y - pt2->y;
	}
	
	int cmptackaxd(const void *p1, const void *p2) {
	  const tacka *pt1, *pt2;
	  pt1 = (const tacka *)p1;
	  pt2 = (const tacka *)p2;
	  if (pt1->x != pt2->x)
	    return pt1->x - pt2->x;
	  else
	    return pt2->y - pt1->y;
	}
	
	int cmptackayl(const void *p1, const void *p2) {
	  const tacka *pt1, *pt2;
	  pt1 = (const tacka *)p1;
	  pt2 = (const tacka *)p2;
	  if (pt1->y != pt2->y)
	    return pt1->y - pt2->y;
	  else
	    return pt2->x - pt1->x;
	}
	
	int cmptackayr(const void *p1, const void *p2) {
	  const tacka *pt1, *pt2;
	  pt1 = (const tacka *)p1;
	  pt2 = (const tacka *)p2;
	  if (pt1->y != pt2->y)
	    return pt1->y - pt2->y;
	  else
	    return pt1->x - pt2->x;
	}
	
	int chup(int n, tacka *at, tacka *bt) {
	  tacka pt;
	  int i, m, j1, j2;
	  if (n == 0) return 0;
	  if (n == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  qsort(at, n, sizeof(tacka), cmptackaxu);
	  j1 = j2 = n - 1;
	  while ((j1 >= 0) && (at[j1].x == at[j2].x)) j1--;
	  j1++;
	  while (j1 < j2) {
	  	pt = at[j1]; at[j1] = at[j2]; at[j2] = pt;
	  	j1++; j2--;
	  }  
	  bt[0] = at[0]; bt[1] = at[1];
	  m = 2;
	  for (i = 2; i < n; i++) {
	    while ((m >= 2) && 
	           (vecpr(bt[m-2], bt[m-1], at[i]) >= 0)) m--;
	    bt[m++] = at[i];
	  }
	  return m;
	}
	
	int chdown(int n, tacka *at, tacka *bt) {
	  tacka pt;
	  int i, j1, j2, m;
	  if (n == 0) return 0;
	  if (n == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  qsort(at, n, sizeof(tacka), cmptackaxd);
	  j1 = j2 = n - 1;
	  while ((j1 >= 0) && (at[j1].x == at[j2].x)) j1--;
	  j1++;
	  while (j1 < j2) {
	  	pt = at[j1]; at[j1] = at[j2]; at[j2] = pt;
	  	j1++; j2--;
	  }  
	  bt[0] = at[0]; bt[1] = at[1];
	  m = 2;
	  for (i = 2; i < n; i++) {
	    while ((m >= 2) && 
	           (vecpr(bt[m-2], bt[m-1], at[i]) <= 0)) m--;
	    bt[m++] = at[i];
	  }
	  return m;
	}
	
	int chleft(int n, tacka *at, tacka *bt) {
	  tacka pt;
	  int i, j1, j2, m;
	  if (n == 0) return 0;
	  if (n == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  qsort(at, n, sizeof(tacka), cmptackayl);
	  j1 = j2 = n - 1;
	  while ((j1 >= 0) && (at[j1].y == at[j2].y)) j1--;
	  j1++;
	  while (j1 < j2) {
	  	pt = at[j1]; at[j1] = at[j2]; at[j2] = pt;
	  	j1++; j2--;
	  }  
	  bt[0] = at[0]; bt[1] = at[1];
	  m = 2;
	  for (i = 2; i < n; i++) {
	    while ((m >= 2) && 
	           (vecpr(bt[m-2], bt[m-1], at[i]) >= 0)) m--;
	    bt[m++] = at[i];
	  }
	  return m;
	}
	
	int chright(int n, tacka *at, tacka *bt) {
	  tacka pt;
	  int i, j1, j2, m;
	  if (n == 0) return 0;
	  if (n == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  qsort(at, n, sizeof(tacka), cmptackayr);
	  j1 = j2 = n - 1;
	  while ((j1 >= 0) && (at[j1].y == at[j2].y)) j1--;
	  j1++;
	  while (j1 < j2) {
	  	pt = at[j1]; at[j1] = at[j2]; at[j2] = pt;
	  	j1++; j2--;
	  }  
	  bt[0] = at[0]; bt[1] = at[1];
	  m = 2;
	  for (i = 2; i < n; i++) {
	    while ((m >= 2) && 
	           (vecpr(bt[m-2], bt[m-1], at[i]) <= 0)) m--;
	    bt[m++] = at[i];
	  }
	  return m;
	}
	
	int filterup(int nt, tacka *at, tacka *bt) {
	  int i, mt;
	  if (nt == 0)
	    return 0;
	  if (nt == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  i = 0;
	  while ((i+1 < nt) && (tang(at[i], at[i+1]) > 1)) i++;
	  bt[0] = at[i];
	  mt = 1;
	  for (i++; i < nt; i++) {
	  	if (tang(bt[mt-1], at[i]) < -1) break;
	  	bt[mt] = at[i];
	  	mt++;
	  }  
	  return mt;
	}
	      
	
	int filterdown(int nt, tacka *at, tacka *bt) {
	  int i, mt;
	  if (nt == 0)
	    return 0;
	  if (nt == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  i = 0;
	  while ((i+1 < nt) && (tang(at[i], at[i+1]) < -1)) i++;
	  bt[0] = at[i];
	  mt = 1;
	  for (i++; i < nt; i++) {
	  	if (tang(bt[mt-1], at[i]) > 1) break;
	  	bt[mt] = at[i];
	  	mt++;
	  }  
	  return mt;
	}
	
	int filterright(int nt, tacka *at, tacka *bt) {
	  int i, mt;
	  if (nt == 0)
	    return 0;
	  if (nt == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  i = 0;
	  while ((i+1 < nt) && (ctang(at[i], at[i+1]) > 1)) i++;
	  bt[0] = at[i];
	  mt = 1;
	  for (i++; i < nt; i++) {
	  	if (ctang(bt[mt-1], at[i]) < -1) break;
	  	bt[mt] = at[i];
	  	mt++;
	  }  
	  return mt;
	}
	      
	
	int filterleft(int nt, tacka *at, tacka *bt) {
	  int i, mt;
	  if (nt == 0)
	    return 0;
	  if (nt == 1) {
	    bt[0] = at[0];
	    return 1;
	  }
	  i = 0;
	  while ((i+1 < nt) && (ctang(at[i], at[i+1]) < -1)) i++;
	  bt[0] = at[i];
	  mt = 1;
	  for (i++; i < nt; i++) {
	  	if (ctang(bt[mt-1], at[i]) > 1) break;
	  	bt[mt] = at[i];
	  	mt++;
	  }  
	  return mt;
	}
	      
	      
	int KonveksniOmotac(int n, int x[], int y[], int d[]) {
	  int i;
	  nau = nad = nal = nar = 0;
	  for (i = 0; i < n; i++) 
	    switch (d[i]) {
	      case 0:
	      	atu[nau].x = x[i];
	      	atu[nau].y = y[i];
	      	nau++;
	      	break;
	      case 2:
	      	atd[nad].x = x[i];
	      	atd[nad].y = y[i];
	      	nad++;
	      	break;
	      case 1:
	      	atr[nar].x = x[i];
	      	atr[nar].y = y[i];
	      	nar++;
	      	break;
	      case 3:
	      	atl[nal].x = x[i];
	      	atl[nal].y = y[i];
	      	nal++;
	      	break;
	    }
	  nbu = chup(nau, atu, btu);
	  nbd = chdown(nad, atd, btd);
	  nbr = chright(nar, atr, btr);
	  nbl = chleft(nal, atl, btl);
	/***
	  printf("%d %d %d %d\n", nau, nad, nal, nar);
	  printf("%d %d %d %d\n", nbu, nbd, nbl, nbr);
	  for (i = 0; i < nbu; i++) 
	    printf("U %d %d %lf\n", btu[i].x, btu[i].y, tang(btu[i], btu[i+1]));
	  for (i = 0; i < nbd; i++) 
	    printf("D %d %d %lf\n", btd[i].x, btd[i].y, tang(btd[i], btd[i+1]));
	  for (i = 0; i < nbl; i++) 
	    printf("L %d %d %lf\n", btl[i].x, btl[i].y, ctang(btl[i], btl[i+1]));
	  for (i = 0; i < nbr; i++) 
	    printf("R %d %d %lf\n", btr[i].x, btr[i].y, tang(btr[i], btr[i+1]));
	***/
	  if (nar + nal == 0) {
	  	int nd = 0;
	  	int n1u, n2u, n1d, n2d;
	  	n1u = 0; n2u = nbu - 1;
	  	n1d = 0; n2d = nbd - 1;
	  	if (btu[n1u].x < btd[n1d].x) {
	  	  if ((n1d < n2d) && (btd[n1d].x == btd[n1d+1].x)) n1d++; 
	  	} else {
	  	  if (btu[n1u].x > btd[n1d].x) {
	  	    if ((n1u < n2u) && (btu[n1u].x == btu[n1u+1].x)) n1u++; 
	  	  } else {
	  	    if ((n1u < n2u) && (btu[n1u].x == btu[n1u+1].x)) n1u++; 
	  	    if ((n1d < n2d) && (btd[n1d].x == btd[n1d+1].x)) n1d++; 
	  	  }
	  	}
	  	if (btu[n2u].x < btd[n2d].x) {
	  	  if ((n1u < n2u) && (btu[n2u].x == btu[n2u-1].x)) n2u--; 
	  	} else {
	  	  if (btu[n2u].x > btd[n2d].x) {
	  	    if ((n1d < n2d) && (btd[n2d].x == btd[n2d-1].x)) n2d--; 
	  	  } else {
	  	    if ((n1u < n2u) && (btu[n2u].x == btu[n2u-1].x)) n2u--; 
	  	    if ((n1d < n2d) && (btd[n2d].x == btd[n2d-1].x)) n2d--; 
	  	  }
	    }
	  	return n2u - n1u + n2d - n1d + 2;
	  }
	  nc = 0;
	  nc += ncu = filterup(nbu, btu, ctu);
	  nc += ncd = filterdown(nbd, btd, ctd);
	  nc += ncr = filterright(nbr, btr, ctr);
	  nc += ncl = filterleft(nbl, btl, ctl);
	
	/***
	  printf("%d %d %d %d\n", ncu, ncd, ncl, ncr);
	  for (i = 0; i < ncu; i++) 
	    printf("U %d %d\n", ctu[i].x, ctu[i].y);
	  for (i = 0; i < ncd; i++) 
	    printf("D %d %d\n", ctd[i].x, ctd[i].y);
	  for (i = 0; i < ncl; i++) 
	    printf("L %d %d\n", ctl[i].x, ctl[i].y);
	  for (i = 0; i < ncr; i++) 
	    printf("R %d %d\n", ctr[i].x, ctr[i].y);
	***/
	  
	  int n1u, n2u, n1d, n2d, n1r, n2r, n1l, n2l;
	  n1u = n1d = n1r = n1l = 0;
	  n2u = ncu - 1;
	  n2d = ncd - 1;
	  n2r = ncr - 1;
	  n2l = ncl - 1;
	  if ((n2u > n1u) && tangjem1(ctu[n2u-1], ctu[n2u])) {
	  	if (ctu[n2u].x + ctu[n2u].y <= ctr[n2r].x + ctr[n2r].y) {
	  		n2u--; nc--;
	  	}
	  }
	  if ((n2r > n1r) && tangjem1(ctr[n2r-1], ctr[n2r])) {
	  	if (ctr[n2r].x + ctr[n2r].y <= ctu[n2u].x + ctu[n2u].y) {
	  		n2r--; nc--;
	  	}
	  }
	  if ((n1u < n2u) && tangje1(ctu[n1u], ctu[n1u+1])) {
	  	if (ctu[n1u].y - ctu[n1u].x <= ctl[n2l].y - ctl[n2l].x) {
	  		n1u++; nc--;
	  	}
	  }
	  if ((n1l < n2l) && tangje1(ctl[n2l-1], ctl[n2l])) {
	  	if (ctu[n1u].y - ctu[n1u].x >= ctl[n2l].y - ctl[n2l].x) {
	  		n2l--; nc--;
	  	}
	  }
	  if ((n1l < n2l) && tangjem1(ctl[n1l], ctl[n1l+1])) {
	  	if (ctd[n1d].x + ctd[n1d].y <= ctl[n1l].x + ctl[n1l].y) {
	  		n1l++; nc--;
	  	}
	  }
	  if ((n1d < n2d) && tangjem1(ctd[n1d], ctd[n1d+1])) {
	  	if (ctd[n1d].x + ctd[n1d].y >= ctl[n1l].x + ctl[n1l].y) {
	  		n1d++; nc--;
	  	}
	  }
	  if ((n1d < n2d) && tangje1(ctd[n2d-1], ctd[n2d])) {
	  	if (ctr[n1r].y - ctr[n1r].x <= ctd[n2d].y - ctd[n2d].x) {
	  		n2d--; nc--;
	  	}
	  }
	  if ((n1r < n2r) && tangje1(ctr[n1r], ctr[n1r+1])) {
	  	if (ctr[n1r].y - ctr[n1r].x >= ctd[n2d].y - ctd[n2d].x) {
	  		n1r++; nc--;
	  	}
	  }
	  return nc;
	}      
	
	
	int chff(int n, int x[], int y[], int d[]) {
	  int nd;
	  int i, dd;
	  dd = 1000000000;
	  nau = nad = nal = nar = 0;
	  for (i = 0; i < n; i++) 
	    switch (d[i]) {
	      case 0:
	      	atu[nau].x = x[i];
	      	atu[nau].y = y[i] + dd;
	      	nau++;
	      	break;
	      case 2:
	      	atu[nau].x = x[i];
	      	atu[nau].y = y[i] - dd;
	      	nau++;
	      	break;
	      case 1:
	      	atu[nau].x = x[i] + dd;
	      	atu[nau].y = y[i];
	      	nau++;
	      	break;
	      case 3:
	      	atu[nau].x = x[i] - dd;
	      	atu[nau].y = y[i];
	      	nau++;
	      	break;
	    }
	  nbu = chup(nau, atu, btu);
	  nbd = chdown(nau, atu, btd);
	/***
	  printf("%d %d %d %d\n", nau, nad, nal, nar);
	  printf("%d %d %d %d\n", nbu, nbd, nbl, nbr);
	  for (i = 0; i < nbu; i++) 
	    printf("U %d %d\n", btu[i].x, btu[i].y);
	  for (i = 0; i < nbd; i++) 
	    printf("D %d %d\n", btd[i].x, btd[i].y);
	***/
	  nd = 2;
	  if (btu[0].x == btu[1].x) nd++;
	  if (nbu > 2)
	    if (btu[nbu-1].x == btu[nbu-2].x) nd++;
	  nc = nbu + nbd - nd;
	  return nc;
	}      
	
	
	int n;
	int x[MAXN], y[MAXN], d[MAXN];
	
	main() {
	  int i;
	  scanf("%d", &n);
	  for (i = 0; i < n; i++) 
	    scanf("%d%d%d", &x[i], &y[i], &d[i]);
	  printf("%d\n", KonveksniOmotac(n, x, y, d));
	//  printf("%d\n", chff(n, x, y, d));
	}
	       
	       
	

	```
