---
hide:
  - toc
---

# 1 - Restorani

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Kako svi dobro znamo, ove godine će se IOI održati na Tajvanu. Jedan od najpoznatijih restorana na Tajvanu “Din Tai Fung”, koji je izabran kao restoran u kojem će takmičari jesti, je već polako krenuo da sprema meni za takmičare i nabavlja sastojke.
	
	S vremena na vreme, šef kuhinje se seti novog jela i naruči određene količine sastojaka za to jelo. Dobro je poznato da nikada ne naručuje jedan te isti sastojak više od jednom, i da su naručene količine uvek različite. Pošto dobije sastojke, on ih spremi u ostavu.
	
	Međutim, najveći konkurent ovom restoranu je restoran “Fuda Shangong Zhengijao Dawang”, i njihova želja je da oni budu glavni restoran na IOI-u. Kako bi u toj nameri uspeli oni su saznali gde “Din Tai Fung” drži svu naručenu hranu, pa s vremena na vreme odu i uzmu dobar deo nje. Ali, kako “Din Tai Fung” ne bi primetio odmah šta se dešava, oni svaki put uzmu $\lfloor \frac{n}{2}\rfloor$ sastojaka (gde $n$ predstavlja broj sastojaka u ostavi u tom trenutku) kojih ima najmanje.
	
	Preciznije, ukoliko sa $A[i]$ predstavimo količine sastojaka koji su trenutno u ostavi,  i sortiramo u rastućem redosledu **(ne postoje dva sastojka sa istim količinama)**, prvih $\lfloor \frac{n}{2}\rfloor$ sastojaka će biti ukradeno.
	
	Njima bi bilo veoma lagano ovo da urade, međutim izgubili su informacije o količinama sastojaka, jedino što imaju je poredak količine sastojaka. Tačnije, za bilo koja dva naručena sastojka, oni znaju da li je prvog sastojka naručeno manje ili više od drugog.
	
	Vaš zadatak je da pomognete restoranu “Fuda Shangong Zhengijao Dawang” u nameri da budu glavni restoran na IOI-u (pošto je u ovom restoranu bolja hrana), tako što ćete im govoriti koje sastojke treba da uzmu, tako da ih konkurent ne bi primetio.
	
	## Opisi funkcija
	Potrebno je da implementirate sledeće tri funkcije:
	
	1. `Init(int M)` - ova funkcija se poziva samo jednom na početku i broj $M$ predstavlja ukupan broj poziva funkcija `NoviSastojak()` i `Nadji()`;
	2. `NoviSastojak()` – ova funkcija će biti pozvana svaki put kada šef naruči novi sastojak;
	3. `Nadji()` – ova funkcija će biti pozvana svaki put kada se od vas traži da nađete $\lfloor \frac{n}{2}\rfloor$ ($n$ predstavlja broj sastojaka trenutno u ostavi) najmanjih sastojaka. Pošto nađete sastojke koje treba, potrebno je tačno $\lfloor \frac{n}{2}\rfloor$ puta pozvati funkciju `Izbaci(i)` koja će izbaciti $i$-ti naručeni sastojak.
	
	Na raspolaganju vam je funkcija `Uporedi(i, j)` koja vraća:
	
	* $1$ ukoliko je $i$-toj naručenog sastojka više naručeno od $j$-tog;
	* $-1$ ukoliko je $i$-tog sastojka naručeno manje od $j$-tog.
	
	Primetimo da su naručivanja **numerisana od $1$**.
	
	## Primer 1
	Neka je $M=8$ i neka su operacije date u sledećem redosledu:
	
	1. `NoviSastojak()` – ubaci sastojak količine $5$ - trenutni sastojci $[5]$;
	2. `NoviSastojak()` - ubaci sastojak količine $4$ - trenutni sastojci $[5,4]$;
	3. `Nadji()` – izbaci manji sastojak ($2$. naručeni sastojak) - trenutni sastojci $[5]$;
	4. `NoviSastojak()` – ubaci sastojak količine $7$ - trenutni sastojci $[5,7]$;
	5. `NoviSastojak()` - ubaci sastojak količine $9$ - trenutni sastojci $[5,7,8]$;
	6. `NoviSastojak()` - ubaci sastojak količine $8$ - trenutni sastojci $[5,7,9,8]$;
	7. `NoviSastojak()` – ubaci sastojak količine $1$ - trenutni sastojci $[5,7,9,8,1]$;
	8. `Nadji()` – izbaci $2$ najmanja sastojka ($1$. i $7$. naručeni) trenutni sastojci $[7,8,9]$.
	
	Na prvi poziv vaše funkcije `Nadji()` u ovom slučaju treba da pozove funkciju `Izbaci(2)`, dok drugi poziv funkcije `Nadji()` treba da pozove `Izbaci(1)` i `Izbaci(7)`.
	
	## Ograničenja
	Označimo sa $M$ ukupan broj poziva funkcija `NoviSastojak()` i `Nadji()` zajedno, a sa $P$ označimo broj poziva funkcije `Uporedi(i, j)` koje vaš program uradi.
	
	* $1\leq M\leq 100.000$.
	* $1\leq P\leq 1.000.000$.
	
	**Drugo ograničenje znači da će se vaš program dobiti $0$ poena na test primeru ukoliko pozove funkciju `Uporedi(i,j)` više od $1.000.000$ puta.**
	
	* PODZADATAK $1$ [$20$ POENA]:$1\leq M\leq 1000$.
	* PODZADATAK $2$ [$35$ POENA]: $1\leq M\leq 20.000$.
	* PODZADATAK $3$ [$45$ POENA]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom `restorani.c`, `restorani.cpp` ili `restorani.pas`, koji implementira gore pomenute funkcije. Osim traženih funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaše funkcije/procedure moraju biti sledećeg oblika:
	```
	C/C++:
	void Init(int M);
	void NoviSastojak();
	void Nadji();
	Pascal:
	Procedure Init(M : LongInt);
	Procedure NoviSastojak();
	Procedure Nadji();
	```
	
	Na raspolaganju su vam sledeće funkcije:
	```
	C/C++:
	int Uporedi(int i, int j);
	void Izbaci(int i);
	Pascal:
	Function Uporedi(i,j : LongInt) : Integer;
	Function Izbaci(i : LongInt);
	```
	
	**C/C++:** Implementacije ovih funkcija su date u fajlu `grader.cpp`, a njihovi potpisi u fajlu `restorani.h`. Zbog toga je obavezno u vašem fajlu `restorani.cpp` staviti `#include “restorani.h”`.
	
	**Pascal:** Implementacije ovih funkcija su date u fajlu `graderhelplib.pas` – da biste ih mogli koristiti potreno je u vašem fajlu `restorani.pas` dodati `Uses graderhelplib;`.
	
	Vaši template fajlovi već sadrže sve potrebne stvari – dovoljno je samo implementirati vaše funkcije. Implementacije funkcija `Uporedi` i `Izbaci` nisu nužno iste kao na zvaničnom grejderu.
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (`restorani.c`, `restorani.cpp`, `restorani.pas`) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (`grader.c`, `grader.cpp`, `grader.pas`, `restorani.h`, `graderhelplib.pas`) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	* U prvom redu broj M
	* U narednih M redova nalaze se upiti sledećeg tipa:
	* `1 x` – ubaci novi sastojak količine $x$;
	* `2` - izvaci najmanjih $\lfloor \frac{n}{2} \rfloor$ sastojaka.
	
	zatim pozivaju vašu funkciju `Init(int M)` iz odgovarajućeg fajla (`restorani.c`, `restorani.cpp`, `restorani.pas`) i potom se pozivaju vaše funkcije `Ubaci()` i `Nadji()`. Na kraju će vam se ispisati korisne informacije (npr. broj poziva funkcije `Uporedi(int I, int j)` koje je vaš program izvršio). Kodove ovih programa možete menjati po potrebi.
	
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Boris Grubić | Boris Grubić | - | Dušan Zdravković |
	
	
	``` cpp title="01_restorani.cpp" linenums="1"
	#include <iostream>
	#include <algorithm>
	#include <cstdlib>
	
	#include "restorani.h"
	
	using namespace std;
	
	static int m;
	static int n;
	static int cur;
	static int *a;
	
	void Init(int M) {
	    n = 0;
	    m = M;
	    cur = 0;
	    a = (int*) malloc(M * sizeof(int));
	}
	
	void NoviSastojak() {
	    a[n++] = ++cur;
	    int p = n - 1;
	    while (p > 0 && Uporedi(a[p], a[p - 1]) == -1) {
	        swap(a[p], a[p - 1]);
	        --p;
	    }
	}
	
	void Nadji() {
	    int t = n / 2;
	    for (int i = 0; i < t; ++i) Izbaci(a[i]);
	    for (int i = t; i < n; ++i)
	        a[i - t] = a[i];
	    n = n - t;
	}

	```
