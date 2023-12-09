---
hide:
  - toc
---

# 1 - Laž

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	U dalekoj zemlji Bajtoviji živi $n$ programera. Za ovu zemlju je karakteristično to da su njeni stanovnici ili istinoljupci, oni koji uvek govore istinu, ili lažljivci, oni koji uvek govore laži. 
	
	Našli ste se na odmoru u ovoj čudnovatoj zemlji i želite da otkrijete jednog od lažljivaca. Kako ne biste trošili previše vremena, želite to da uradite tako što ćete postaviti najviše $q$ pitanja. Svako pitanje treba da postavite jednom od stanovnika Bajtovije i da ga pitate da li među stanovnicima iz skupa $S = \{ s_1, s_2, \dots, s_k \}$ postoji neparno lažljivaca. Skup $S$ može da bude prazan, a može i da sadrži stanovnika kome postavljate pitanje.
	
	## Opis funkcija
	
	Potrebno je da implementirate funkciju
	
	* $\text{NadjiLazova}(n, q)$
	
	gde je $n$ broj stanovnika Bajtovije, $q$ dozvoljeni broj pitanja, a funkcija vraća indeks jednog od lažova, ili $-1$ ukoliko svi stanovnici govore istinu.
	
	Vaš program može da koristi funkciju
	
	$\text{Pitaj}(x, s)$
	
	koja vraća odgovor stanovnika sa indeksom $x$ na pitanje "da li se u skupu $s$ nalzi neparno stanovnika Bajtovije koji lažu?"
	
	* Skup $s$ treba da prosledite kao niz međusobno različitih indeksa stanovnika.
	
	**Stanovnici Bajtovije su indeksirani od 1.**
	
	**Informacija o tome ko su istiniljupci, a ko lažljivci je fiksirana pre pokretanja vaše funkcije i ne zavisi od pitanja koje postavljate.**
	
	## Ograničenja
	
	Test primeri su podeljeni u nekoliko podzadataka. U svakom podzadatku je dato ograničenje $q$, koje predstavlja dozvoljen broj poziva funkcije $\text{Pitaj}$.
	
	* **[10 poena]:** $n = 1000$, $q = 2000$
	* **[12 poena]:** $n = 1000$, $q = 1000$
	* **[25 poena]:** $n = 1000$, $q = 30$, tačno jedan stanovnik Bajtovije laže.
	* **[33 poena]:** $n = 1000$, $q = 30$, neparan broj stanovnika Bajtovije su lažovi.
	* **[20 poena]:** $n = 1000$, $q = 30$
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može da sadrži i dodatne globale promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int NadjiLazova(int n, int q)`
	
	Vaš program mora ulljučivati header `code.h`, u kom je definisana funkcija $\text{Pitaj}$ sledećeg potpisa:
	
	`bool Pitaj(int koga, vector<int> skup)`
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom i jedinom redu, brojeve $n$ i $q$, i string $s$ dužine $n$ sačinjen od jedinica i nula. Svaki karakter stringa $s$ odnosi se na jednog stanovnika Bajtovije tako da jedinica označava one stanovnike koji lažu, a nula one koji govore istinu.
	
	Zatim ovaj program poziva vašu funkciju i štampa povratnu vrednost na ekran. Ukoliko vaše rešenje koristi funkciju $\text{Pitaj}$ više od $q$ puta, biće prekinuto sa statusom `RTE` (runtime error).
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Tadija Šebez | Pavle Martinović | Mladen Puzić |
	
	## Rešenje kada $q = 2000$
	Ovaj podzadatak je tu za takmičare koji na neoptimalan način iskucaju rešenje iz sledećeg podzadatka.
	
	## Rešenje kada $q = 1000$
	Možemo da saznamo da li je neko lažov ili istinoljubac sa samo jednim pitanjem. Ako osoba $x$ pitamo za skup $\{x, y\}$, gde je $y$ bilo koja druga osoba, saznaćemo da li je $y$ lažov ili istinoljubac (samo ukoliko kaže da u njemu ima neparno lažova, onda je osoba $y$ lažov). Ovo znamo, jer ako osoba $x$ govori istinu, onda odgovor zavisi samo od toga da li je $y$ lažov. Ako laže, i ako su obojica lažovi, $x$ će još uvek reći da je neparno lažova. U suprotnom, reći će da ima neparno lažova.
	
	Sad možemo proći kroz niz i za svaku osobu saznati da li je istinoljubac ili lažov sa po jednim pitanjem.
	
	## Rešenje kada $q = 30$ i postoji tačno jedan lažov
	
	Koristeći ideju iz prethodnog podzadatka, odredimo da li je osoba $1$ istinoljubac ili lažov. Ukoliko je lažov, možemo vratiti njegov indeks, u suprotnom, možemo ga koristiti da saznamo informacije o ostalim ljudima.
	
	Ako je istinoljubac, onda je lažov neka od osoba na intervalu $[2, N]$. Podelimo ovaj interval na pola. Lažov se mora nalaziti u jednoj od te dve polovine. Pitajmo osobu $1$ da li je lažov u prvoj polovini. Ukoliko jeste, dalje razmatramo samo nju, u suprotnom, razmatramo samo drugu polovinu.
	
	Ovom metodom nalik na binarnu pretragu, možemo naći lažova sa još desetak pitanja.
	
	## Rešenje kada $q = 30$ i postoji neparno lažova
	Slično prethodnom podzadatku, prvo nalazimo informaciju o osobi $1$. Nakon toga, ponovo radimo binarnu pretragu na intervalu $[2, N]$. Ovaj put, umesto da održavamo samo jednog lažova, želimo da interval koji posmatramo uvek ima neparan broj lažova. Kada podelimo interval koji ima neparan broj lažova na dve polovine, jedna polovina imaće paran broj lažova, a druga neparan. Pretragu nastavljamo u onoj polovini koja ima neparan broj. Tako radimo dok ne dođemo do jednog lažova.
	
	## Glavno rešenje
	Poslednji podzadatak rešavamo kao prethodni, samo što je prvo potrebno da nađemo neki podskup ljudi u kojem ima neparno lažova. To možemo uraditi nasumičnim (randomiziranim) pristupom. 
	
	Svaki element ubacujemo u naš podskup sa verovatnoćom $50\%$. Samim tim, verovatnoća da će taj podskup imati neparno lažova je takođe $50\%$. Ukoliko podskup koji smo dobili ima parno mnogo lažova, onda konstruišemo novi podskup, dok ne dobijemo neki koji nam odgovara. 
	
	Verovatnoća da će nam za to trebati preko $19$ pokušaja je jako mala, $\frac{1}{2^{19}}$, pa je možemo zanemariti. Ostala pitanja možemo iskoristiti na drugi deo rešenja, gde opet radimo nešto nalik na binarnu pretragu, samo ovaj put delimo skup na dva, umesto interval. 
	
	``` cpp title="01_laz.cpp" linenums="1"
	#include "code.h"
	
	#include <vector>
	#include <random>
	
	using namespace std;
	
	bool Pitaj(vector<int> s) {
		int x = s.back();
		s.pop_back();
		return Pitaj(x, s);
	}
	
	int NadjiLazova(int n, int q) {
		mt19937 rng;
	
		vector<int> svi;
		for (int i = 1; i <= n; ++i)
			svi.push_back(i);
	
		vector<int> podskup;
		bool nasao = false;
	
		for (int pokusaj = 1; pokusaj <= 20; ++pokusaj) {
			podskup.clear();
			for (int i = 1; i <= n; ++i)
				if (rng() % 2 == 0)
					podskup.push_back(i);
			if (Pitaj(podskup)) {
				nasao = true;
				break;
			}
		}
	
		if (!nasao)
			return -1;
	
		while (podskup.size() > 1) {
			vector<int> levo, desno;
			int mid = podskup.size() / 2;
			for(int i = 0; i < podskup.size(); ++i) {
				if (i < mid)
					levo.push_back(podskup[i]);
				else
					desno.push_back(podskup[i]);
			}
			if (Pitaj(levo))
				podskup = levo;
			else
				podskup = desno;
		}
	
		return podskup[0];
	}

	```
