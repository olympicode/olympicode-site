---
hide:
  - toc
---

# B2 - Izmena

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Mali Đurica, bivši član Tajne komisije iz senke, je kupio robota. Đurica je postavio robota na veliku tablu (radi jednostavnosti zamislićemo da tabla ima beskonačnu dužinu i širinu) preko koje je postavljen koordinantni sistem.
	
	Uz robota je dobio i niz komandi $Q$, dužine $N$, koji se sastoji od slova $L$, $R$, $D$ i $U$. Kad robot na poziciji $(x, y)$ učita slovo $q$ pomera se na poziciju $(w, z)$ na sledeći način: ako $q = L$ onda $(w, z) = (x – 1, y)$, tj. ide levo; ako $q = R$ onda $(w, z) = (x + 1, y)$, tj. ide desno; ako $q = U$ onda $(w, z) = (x, y + 1)$, tj. ide gore; i ako $q = D$ onda $(w, z) = (x, y - 1)$, tj. ide dole. Pored ovoga, mali Đurica je izabrao koordinatu $(r, s)$.
	
	Malog Đuricu zanima sledeće:
	
	- broj $A$ – koliki je najmanji broj komandi koje treba izmeniti u nizu $S$ tako da kad robot učita izmenjeni niz i krene sa pozicije $(0, 0)$ u **nekom** momentu prođe kroz koordinatu $(r, s)$;
	- broj $B$ – koliki je najmanji komandi koje treba izmeniti u nizu $S$ tako da kad robot učita izmenjeni niz i krene sa pozicije $(0, 0)$ **završi** na koordinati $(r, s)$.
	
	Pomozite malom Đurici i izračunajte $A$ i $B$.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se tri broja $N$, $r$ i $s$ razdvojena razmakom. U drugom redu se nalazi string $Q$ dužine $N$.
	
	## Opis izlaza
	U prvi i jedini red standardnog izlaza ispisati broj $A$ i broj $B$ razdvojeni jednim razmakom.
	
	## Primer 1
	### Ulaz 
	```
	6 0 2
	RRRRRR
	```
	
	### Izlaz
	```
	2 4
	```
	
	## Primer 2
	### Ulaz 
	```
	13 3 -4
	UURRRDUUDRLLL
	```
	
	### Izlaz
	```
	3 4
	```
	
	## Objašnjenje primera
	U prvom primeru ako robot prati niz UURRRR, koji se razlikuje u 2 karaktera od onog na ulazu, naći će se na koordinati (0, 2) posle druge učitane komande. Ako robot prati niz komandi LRLRUU naći će se na koordinati (0, 2) nakon što učita ceo niz.
	
	U drugom primeru mogući nizovi komandi koji odgovaraju izlazu su UDRRRDDDDRLLL i DURRRDDDDRRLL.
	
	## Ograničenja
	* $1 \leq N \leq 500 000$.
	* $Q$ je sastavljen od karaktera $L$, $R$, $D$ i $U$, kao što je opisano u postavci problema.
	* $|r| + |s| > 0$.
	* Niz će uvek moći da se izmeni tako da brojevi $A$ i $B$ postoje.
	
	## Napomena
	
	* Ako takmičar ispiše tačno broj $A$ dobija 60% poena na datom test primeru.
	* Ako takmičar ispiše tačno broj $B$ dobija 40% poena na datom test primeru.
	
	Test primeri su podeljeni u 4 disjuntkne grupe:
	
	* U test primerima vrednim 10 poena važi $s = 0$ i $Q$ se sastoji samo od karaktera $L$ i $R$.
	* U test primerima vrednim 10 poena važi $1 \leq N \leq 10$.
	* U test primerima vrednim 30 poena važi $1 \leq N \leq 1 000$.
	* U test primerima vrednim 50 poena nema dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Slobodan Mitrović | Dragan Urošević | - | Demjan Grubić |
	
	
	``` cpp title="02_izmena.cpp" linenums="1"
	/*
	  author: Slobodan Mitrovic
	*/
	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	#include <cmath>
	
	using namespace std;
	
	int main() {
	  int N, r, s;
	  cin >> N >> r >> s;
	  string Q;
	  cin >> Q;
	  int L = 0, R = 0, D = 0, U = 0;
	  int A = N + 1, B = N + 1;
	  for (int i = 1; i <= Q.size(); i++) {
	    char ch = Q[i - 1];
	    if (ch == 'L')
	      L++;
	    else if (ch == 'R')
	      R++;
	    else if (ch == 'D')
	      D++;
	    else
	      U++;
	
	    if (i < abs(r) + abs(s))
	      continue;
	    if (i % 2 != (abs(r) + abs(s)) % 2)
	      continue;
	
	    int toUse = 0, x = R - L, y = U - D;
	    if (r < x)
	      toUse += min(x - r, R);
	    else if (r > x)
	      toUse += min(r - x, L);
	
	    if (s < y)
	      toUse += min(y - s, U);
	    else if (s > y)
	      toUse += min(s - y, D);
	
	    int toChange = abs(x - r) + abs(y - s);
	    if (toChange % 2)
	      cout << "Error!" << endl;
	    int tmp = min(toChange, 2 * toUse);
	    B = tmp / 2 + toChange - tmp;
	    A = min(A, B);
	  }
	  cout << A << " " << B << endl;
	  return 0;
	}

	```
