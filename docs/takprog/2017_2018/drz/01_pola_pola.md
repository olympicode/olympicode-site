---
hide:
  - toc
---

# B1 - Pola-pola

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 256MB |
	
	Natalija i Mila se po ceo dan dosađuju pa su rešile da igraju sledeću igru. Mila otvara Noutped, pravi prazan fajl a zatim redom kuca u Noutpedu mala slova engleskog alfabeta. Međutim, s vremena na vreme, Natalija uzima iskucani tekst, deli ga na dva jednaka dela a zatim menja redosled tim polovinama. Natalija je jako pažljiva pa ovo radi samo kada je dužina teksta pozitivan paran broj. Nažalost, njima se pokvario hard disk pa je ovaj fajl izgubljen. Srećom, one se sećaju svih akcija koje su izvele i u kom redosledu. Pomozite im da rekonstruišu tekst koji je sadržao Noutped pre nego što im se pokvario hard disk.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalazi se jedan prirodan broj $N$ - broj akcija koje su izvele Mila i Natalija. U narednih $N$ redova nalazi se opis jedne akcije. Sa `1 x` označavamo akciju u kojoj je Mila dodala slovo `x` na kraj fajla u Noutpedu. Sa `2` označavamo akciju u kojoj je Natalija zamenila prvu i drugu polovinu fajla.
	
	## Opis izlaza
	U jedini red standardnog izlaza ispisati rekonstruisani izgled fajla nakon svih akcija.
	
	## Primer 1
	### Ulaz
	```
	4
	1 a
	1 b
	2
	1 c
	```
	
	### Izlaz
	```
	bac
	```
	
	## Primer 2
	### Ulaz
	```
	9
	1 a
	1 b
	2
	1 a
	1 m
	2
	1 a
	1 d
	2
	```
	
	### Izlaz
	```
	aadamb
	```
	
	## Objašnjenje primera
	U prvom primeru Mila dodaje slova _a_ i _b_ nakon čega Natalija deli ovaj tekst na dva dela (od po jednog slova) i zamenjuje ih. Na kraju, Mila zapisuje _c_ pa je konačni izgled teksta _bac_.
	
	U drugom primeru izgled teksta nakon svakog poteza je sledeći:
	
	```
	a
	ab
	ba
	baa
	baam
	amba
	ambaa
	ambaad
	aadamb
	```
	
	## Ograničenja i podzadaci
	
	* $1 \leq N \leq 500000$.
	
	Postoji pet podzadataka:
	
	* Podzadatak $1$ [$4$ poena]: Mila uvek piše isto slovo.
	* Podzadatak $2$ [$13$ poena]: $N \leq 5000$.
	* Podzadatak $3$ [$19$ poena]: Mila neće zapisati više od 5000 slova.
	* Podzadatak $4$ [$22$ poena]: Mila piše samo slova _a_ ili _b_, $N \leq 50000$.
	* Podzadatak $5$ [$42$ poena]: Nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Vladimir Milovanović | Slobodan Mitrović |
	
	Ključno je uvideti da je najefikasniji način za rešavanje ovog problema korišćenje listi (ili pak dvostranih redova) kao strukture podataka za čuvanje slova. Preciznije govoreći, neophodne su dve ovakve strukture u kojima bi se u svakom trenutku čuvale i održavale prva, odnosno druga polovina trenutnog niza slova.
	
	Svako (neparno) ubacivanje novog slova zapravo predstavlja dodavanje novog člana na kraj jedne liste (reda), pri čemu treba voditi računa da se prilikom svakog drugog (tj. parnog) dodavanja, prvi član te liste (reda) izbaci i doda na kraj prve liste (reda). Time bi obe liste (reda) u svakom trenutku bile ili podjednake dužine ili bi se razlikovale najviše za jedan član.
	
	Operacija zamene redosleda prve i druge polovine se svodi na trivijalnu zamenu dva pokazivača i odvija se samo kada su liste (redovi) jednakih dužina. Kako se dodavanje i prebacivanje članova, kao i promena mesta nad ovim strukturama podataka mogu uraditi u konstantnoj složenosti, $\mathcal{O}(1)$, i kako ukupno imamo $N$ ovakvih operacija, tako je, računajući tu i krajnje ispisivanje rezultata, zadatak na ovaj način rešen u linearnoj $\mathcal{O}(N)$ vremenskoj složenosti.
	
	``` cpp title="01_pola_pola.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	
		int q;
		cin >> q;
		deque<char> leva, desna;
	
		while (q--) {
			int t;
			cin >> t;
			if (t == 1) {
				char x;
				cin >> x;
				desna.push_back(x);
				if (desna.size() == leva.size() + 2) {
					leva.push_back(desna.front());
					desna.pop_front();
				}
			} else {
				if (leva.size() != desna.size()) {
					cerr << "bad\n";
					return 1;
				}
				swap(leva, desna);
			}
		}
	
		cout << string(leva.begin(), leva.end());
		cout << string(desna.begin(), desna.end());
		cout << '\n';
	}
	```
