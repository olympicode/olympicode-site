---
hide:
  - toc
---

# 2 - Kule

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Članovi Tajne Komisije, mali Perica i mali Tuks, u pauzama između pripreme zadataka i spremanja ispita vole da igraju društvenu igru ”Kule”. Pravila igre podrazumevaju da u početku na raspolaganju imamo neki broj kockica, naslaganih jedna na drugu, u obliku kule. 
	
	Jedan potez podrazumeva da Perica izdeli kulu na **dve ili više manjih kula**, i poređa takve kule u niz; Tuks zatim mora da **odabere jednu od tih manjih kula**, koja će se koristiti za naredne poteze (*sve ostale kule se odbacuju*). Ukoliko je Tuks odabrao $k$-tu kulu u nizu, Perica je u obavezi da mu isplati $k^2$ dinara (npr. ukoliko je Tuks odabrao treću kulu, Perica mora odmah da mu da devet dinara). Igra se završava u onom momentu **kada trenutna kula ima samo jednu kockicu**.
	
	Kako je odveć poznato da članovi Tajne Komisije nemaju vremena ni za šta (a samim tim ni za igranje igara), Perica i Tuks su odlučili da, umesto da odigraju partiju ”Kula”, poveruju jedan drugom da bi obojica igrali **optimalno**, i da Perica odmah isplati Tuksu iznos koji bi osvojio pod tim uslovom. Zamolili su vas za pomoć u određivanju ovog iznosa.
	
	## Opisi funkcija
	Potrebno je implementirati funkciju
	
	* $Iznos(L,N[…],Sol[…],N_k,N_(C_1 ),C_1 […])$; 
	
	ova funkcija se poziva samo jednom na početku programa i označava da treba odrediti iznos koji Perica mora isplatiti Tuksu, ukoliko je početna kula imala $N$ kockica **($N$ je zadat kao niz cifara dužine $L$)**. Traženi iznos treba **”popuniti”** u niz $Sol$, takođe u vidu niza cifara. Vaša funkcija mora da kao povratnu vrednost vrati dužinu niza $Sol$, tj. broj cifara rešenja. 
	
	Vaše rešenje takođe treba da odredi **prvi potez koji Perica povlači, ukoliko rezultuje u manje od $1000$ kula**. U promenljivu $N_k$ je potrebno smestiti broj manjih kula u prvoj optimalnoj podeli; ukoliko je ovaj broj veći od $1000$, upisati $-1$. 
	
	Ukoliko je optimalan broj manjih kula manji ili jednak $1000$, niz $C_1$ treba ”popuniti” **nizovima cifara visina ovih kula** (kraj jednog takvog niza cifara označiti brojem -1). Na primer, ukoliko želite da napravite podelu na kule visina 10 i 4, onda $C_1=[1,0,-1,4,-1]$. Veličinu niza $C_1$ treba smestiti u promenljivu $N_{C_1}$.
	
	Ukoliko ima više optimalnih prvih podela, odredite bilo koju. **Nizove indeksirati od 0!**
	
	## Primer
	Pretpostavimo da je vaš program dobio naredbu da izvrši: `Iznos(1,[7],Sol,N_k,N_(C_1 ),C_1 )`.
	
	U ovom slučaju, rešenje je $Sol=[8]$, $N_k=2$, $N_{C_1}=4$, $C_1=[5,-1,2,-1]$; povratna vrednost vaše funkcije treba da bude 1.
	
	U jednom od mogućih optimalnih rešenja, Perica najpre deli kulu na dve kule visina 5 i 2. Ukoliko Tuks odabere drugu kulu (visine 2), dobija odmah 4 dinara, i Perica je nakon toga primoran da ovu kulu podeli na dve kule visine 1, nakon čega Tuks ponovo dobija 4 dinara (**8 ukupno**). Ukoliko Tuks odabere prvu kulu, Perica može u svakom narednom potezu da deli kulu na dve kule od kojih druga ima visinu 1; u ovom slučaju, Tuks će pri optimalnoj strategiji četiri puta dobiti po jedan dinar, da bi na samom kraju dobio četiri (ponovo **8 ukupno**).
	
	Ne postoji početna podela kule visine 7 koja će rezultovati u manjem iznosu.
	
	## Ograničenja
	* $2\leq N\leq 10^{100}$
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u pet podzadatka, u kojima važe sledeća dodatna ograničenja:
	
	* PODZADATAK 1 [10 POENA]: $N\leq 20$.
	* PODZADATAK 2 [15 POENA]: $N\leq 1000$.
	* PODZADATAK 3 [20 POENA]: $N\leq 10^6$.
	* PODZADATAK 4 [20 POENA]: $N\leq 10^18$.
	* PODZADATAK 5 [35 POENA]: Nema dodatnih ograničenja.
	
	Ukoliko na svim test primerima jednog podzadatka izračunate tačan iznos koji Perica treba da isplati Tuksu, **dobijate 60% poena za taj podzadatak**. Ukoliko korektno odredite optimalan prvi Peričin potez na svim test primerima jednog podzadatka, **dobijate 40% poena za taj podzadatak**.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom kule.c, kule.cpp ili kule.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	```
	C/C++
	    int Iznos(int L, int* N, int* Sol, int* Nk, int* NC1, int* C1);
	Pascal
	    function Iznos(L : longint; var N, Sol : array of longint; var Nk, NC1 : longint; var C1 : array of longint) : longint;
	```
	
	Ukoliko radite u C/C++-u, potrebno je na početku fajla staviti `#include “kule.h”` a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti `Unit kule;` (**ovo je već dodato u fajlovima koji su vam obezbeđeni**).
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (kule.c, kule.cpp, kule.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza string koji predstavlja niz cifara broja $N$, $Cif[...]$.
	
	Zatim pozivaju funkciju $Iznos(L,Cif,Sol,N_k,N_{C_1},C_1)$ i ispisuju na standardni izlaz sadržaj niza  $Sol$, kao i vrednost promenljive $N_k$ i sadržaj niza $C_1$. Nizovi se ispisuju bez razmaka; unutar niza $C_1$ umesto $-1$ se ispisuju razmaci.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dragan Urošević | - | Petar Veličković |
	
	
	``` cpp title="02_kule.cpp" linenums="1"
	# include <stdio.h>
	# include <string.h>
	# include <stdlib.h>
	
	# define MAXC 200
	# define MAXN 2000
	
	using namespace std;
	
	typedef struct vbr {
	  int nc;
	  int nizc[MAXC];
	} tvbroj;
	
	long long nizll[MAXN];
	tvbroj nizvb[MAXN];
	int c3[1000*MAXC];
	
	void llong2vbroj(long long a, tvbroj &x) {
	  if (a == 0) {
	    x.nc = 1;
	    x.nizc[0] = 0;
	    return;
	  }
	  x.nc = 0;
	  while (a) {
	    x.nizc[x.nc++] = a % 10;
	    a /= 10;
	  }
	}
	
	void niz2vbroj(int n, int c[], tvbroj &a) {
	  int i, j;
	  a.nc = n;
	  i = 0; j = n;
	  while (j > 0) {
	    a.nizc[i++] = c[j--];
	  }
	}
	
	void dodaj(tvbroj &a, tvbroj b) {
	  int i, j, p;
	  if (b.nc < a.nc) {
	    p = 0;
	    for (i = 0; i < b.nc; i++) {
	      p = a.nizc[i] + b.nizc[i] + p;
	      a.nizc[i] = p % 10;
	      p = p / 10;
	    }
	    while (i < a.nc) {
	      p = a.nizc[i] + p;
	      a.nizc[i] = p % 10;
	      p = p / 10;
	      i++;
	    }
	    if (p) {
	      a.nizc[a.nc++] = p;
	    }
	  } else {
	    p = 0;
	    for (i = 0; i < a.nc; i++) {
	      p = a.nizc[i] + b.nizc[i] + p;
	      a.nizc[i] = p % 10;
	      p = p / 10;
	    }
	    while (i < b.nc) {
	      p = b.nizc[i] + p;
	      a.nizc[i] = p % 10;
	      p = p / 10;
	      i++;
	    }
	    a.nc = b.nc;
	    if (p) {
	      a.nizc[a.nc++] = p;
	    }
	  }
	}
	
	void oduzmi(tvbroj &d, tvbroj b) {
	  int p;
	  int i;
	  int nd, nb;
	  nd = d.nc;
	  nb = b.nc;
	  p = 0;
	  for (i = 0; i < nb; i++) {
	    p = d.nizc[i] - p - b.nizc[i];
	    if (p < 0) {
	      d.nizc[i] = p + 10;
	      p = 1;
	    } else {
	      d.nizc[i] = p;
	      p = 0;
	    }
	  }
	  for (; i < nd; i++) {
	    p = d.nizc[i] - p;
	    if (p < 0) {
	      d.nizc[i] = p + 10;
	      p = 1;
	    } else {
	      d.nizc[i] = p;
	      p = 0;
	    }
	  }
	  while ((nd > 1) && (d.nizc[nd-1] == 0)) nd--;
	  d.nc = nd;
	}
	
	int cmpvbroj(tvbroj a, tvbroj b) {
	  int na, nb;
	  na = a.nc-1;
	  while ((na >= 0) && (a.nizc[na] == 0)) na--;
	  nb = b.nc-1;
	  while ((nb >= 0) && (b.nizc[nb] == 0)) nb--;
	  if (na > nb) return 1;
	  if (na < nb) return -1;
	  while ((na >= 0) && (a.nizc[na] == b.nizc[na])) na--;
	  if (na < 0) return 0;
	  return a.nizc[na] - b.nizc[na];
	}
	
	int dopisi(tvbroj a, int nk, int c[]) {
	  int na;
	  na = a.nc;
	  while (na > 0) {
	    c[++nk] = a.nizc[--na];
	  }
	  c[++nk] = -1;
	  return nk;
	}
	
	int radill(long long a) {
	  int i, j, k;
	  nizll[0] = 1;
	  nizll[1] = 1;
	  nizll[2] = 1;
	  nizll[3] = 1;
	  nizll[4] = 2;
	  for (i = 5; i < MAXN; i++) {
	    nizll[i] = 0;
	    for (j = 1; j * j <= i; j++)
	      nizll[i] += nizll[i-j*j];
	    if (nizll[i] >= a) return i;
	  }
	  return -1;
	}
	
	int int2nizc(int b, int c[]) {
	  int i, j, k, n;
	  i = 0;
	  while (b) {
	    c[++i] = b % 10;
	    b /= 10;
	  }
	  n = i;
	  j = 1;
	  while (j < i) {
	    int tc;
	    tc = c[j]; c[j] = c[i]; c[i] = tc;
	    j++; i--;
	  }
	  return n;
	}
	
	int radivb(tvbroj a, int c2[], int &ns, int &n3, int c3[]) {
	  int i, j, k, n2;
	  tvbroj b, c, d;
	  llong2vbroj(1, nizvb[0]);
	  llong2vbroj(1, nizvb[1]);
	  llong2vbroj(1, nizvb[2]);
	  llong2vbroj(1, nizvb[3]);
	  llong2vbroj(2, nizvb[4]);
	  for (i = 5; i < MAXN; i++) {
	    llong2vbroj(0, nizvb[i]);
	    for (j = 1; j * j <= i; j++)
	      dodaj(nizvb[i], nizvb[i-j*j]);
	    if (cmpvbroj(nizvb[i], a) >= 0) {
	      n2 = int2nizc(i, c2);
	      llong2vbroj(0, b);
	      j = 1;
	      n3 = 0;
	      ns = 0;
	      while (cmpvbroj(b, a) < 0) {
	        c = b;
	        dodaj(b, nizvb[i-j*j]);
	        if (cmpvbroj(b, a) <= 0) {
	          n3 = dopisi(nizvb[i-j*j], n3, c3);
	          ns++;
	          j++;
	        } else {
	          d = a;
	          oduzmi(d, c);
	          n3 = dopisi(d, n3, c3);
	          ns++;
	          return n2;
	        }
	      }
	    }
	  }
	  return -1;
	}
	
	int Iznos(int n, int c1[], int c2[], int &ns, int &n3, int c3[]) {
	  tvbroj avb;
	  niz2vbroj(n, c1, avb);
	  return radivb(avb, c2, ns, n3, c3);
	}
	
	main() {
	  int nc2, nc3, ns;
	  char c[MAXC+1];
	  int c1[MAXC+1];
	  int c2[MAXC+1];
	  long long all; 
	  scanf("%s", c);
	  int i, j, n;
	  i = 1; j = 0; n = strlen(c);
	  while (j < n) 
	    c1[i++] = c[j++] - '0';
	  nc2 = Iznos(n, c1, c2, ns, nc3, c3);
	  for (int i = 1; i <= nc2; i++)
	    printf("%d", c2[i]);
	  printf("\n%d\n", ns);
	  for (i = 1; i <= nc3; i++)
	    if (c3[i] != -1)
	      printf("%d", c3[i]);
	    else
	      printf("\n");
	  return 0;
	}

	```
