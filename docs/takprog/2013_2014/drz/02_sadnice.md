---
hide:
  - toc
---

# B2 - Sadnice

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Kao što svi znamo, prvog dana proleća, naš poznati komšija Žika posadi cveće, ne znam da li znate, ali... Žika je cvećoholičar. Ove godine je posadio $N$ sadnica zgodno numerisanih brojevima od $1$ do $N$. Kako Žika nikada nije bio dobar u ovome, često se dešava da mu određeni broj sadnica ne uspe.
	
	Pošto vidi koje su mu sadnice uspele, a koje ne, on u svoju svesku napiše niz rednih brojeva sadnica $[a_1, a_2, \ldots, a_k]$, $(1\leq a_1 < a_2< \ldots < a_k \leq N)$ koje su mu uspele (uvek ispisuje niz u **rastućem** redosledu). Međutim, ove godine Žika je, umesto rednih brojeva sadnica koje su mu uspele $A = [a_1, a_2, \ldots, a_k]$, napisao samo jedan broj $M$ – redni broj niza $A$ u **leksikografski sortiranom** nizu svih mogućih rastućih nizova uspelih sadnica (takvih nizova ima $2N$). Nažalost, posle je zaboravio svoj niz $A$.
	
	Vaš zadatak je da pomognete Žiki i za dati broj $M$ koji predstavlja redni broj niza $A$ ispišete redne brojeve sadnica koje su mu uspele.
	
	Podsetimo se da je niz $A = [a_1, a_2,\ldots ,a_k]$ leksikografski manji od niza $B=[b_1, b_2, \ldots, b_l]$ ako i samo ako važi jedan od sledeća dva uslova (analogno poređenju $2$ stringa):
	
	* Postoji $1\leq j\leq min(k, l)$ tako da važi i $a_i = b_i$ za svako $1\leq i < j$ i pri tom $a_j < b_j$;
	* $k<l$ i $a_i = b_i$ za svako $1\leq i\leq k$.
	
	## Ulaz
	U prvom i jedinom redu standardnog ulaza se nalaze dva prirodna broja $N$ i $M$, gde $N$ predstavlja broj sadnica, a $M$ predstavlja redni broj niza Žikinih uspelih sadnica (indeksiranje kreće od $1$).
	
	## Izlaz
	U prvi red standardnog izlaza treba ispisati niz brojeva, razdvojenix znakom razmaka, koji predstavljaju redne brojeve sadnica koje su uspele, u rastućem redosledu.
	
	## Primer 1
	### Ulaz
	```
	4
	12
	```
	
	### Izlaz
	```
	2 3 4
	```
	
	## Objašnjenje primera
	Posađene su sadnice sa rednim brojevima $\{1, 2, 3, 4\}$.
	Leksikografski sortirani niz svih mogućih uspelih sadnica u ovom slučaju je:
	
	1. []
	2. [1]
	3. [1, 2]
	4. [1, 2, 3]
	5. [1, 2, 3, 4]
	6. [1, 2, 4]
	7. [1, 3]
	8. [1, 3, 4]
	9. [1, 4]
	10. [2]
	11. [2, 3]
	12. [2, 3, 4]
	13. [2, 4]
	14. [3]
	15. [3, 4]
	16. [4]
	
	Niz sa rednim brojem $12$ u ovom nizu je niz $[2, 3, 4]$.
	
	## Ograničenja
	
	* $1 \leq N \leq 60$.
	* $1 \leq M \leq 2^N$.
	
	Test primeri su podeljeni u tri disjunktne grupe:
	
	* U test primerima vrednim $15$ poena važi $N\leq 5$.
	* U test primerima vrednim $35$ poena važi $N\leq 15$.
	* U test primerima vrednim $50$ poena nema dodatnih ograničenja.
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Boris Grubić | Boris Grubić | Bogdan Petrović | Demjan Grubić |
	
	## Prvi podzadatak
	Zbog malih ograničenja prvi podzadatak možemo rešiti hardcodovanjem rešenja za svaki slučaj. Vremenska i memorijska složenost je $O(1)$.
	
	## Drugi podzadatak
	Podzadatak rešavamo tako što generišemo sve podskupove i ispisujemo traženi. Ukoliko podskupove generišemo leksikografski vremenska složenost je $O(2^N \cdot N)$, u suprotnom moramo sortirati podskupove pa će vremenska složenost biti $O(2^N \cdot N^2)$. Oba pristupa zadovoljavaju vremensko ograničenje. Memorijska složenost je $O(2^N \cdot N)$.
	
	## Glavno rešenje
	Primetimo da je svaki podskup koji sadrži jedinicu leksikografski manji od svakog podskupa koji je ne sadrži (osim praznog skupa koji je leksikografski najmanji).
	
	Dakle,  ako je $M=1$, rešenje je prazan skup, ako je $M<=2^{N-1}+1$, rešenje će sadržati jedinicu, u suprotnom rešenje neće sadržati jedinicu. Sličnu ideju dalje primenjujemo za $k=2, 3, 4, ... N$. Generalizovaćemo ovaj pristup na sledeći način:
	
	Na početku, za $k=1$  posmatramo sve podskupove, pa su nam granice intervala $l=1$ i $r=2^N$.
	
	- Ukoliko je $M=l$, tu zaustavljamo rad programa.
	- Ukoliko je $M<=l+2^{N-k}$, ispisujemo $k$ i postavljamo gornju granicu $r$ na $l+2^{N-k}$.
	- Ukoliko je $M>l+2^{N-k}$, postavljamo donju granicu $l$ na $l+2^{N-k}$.
	
	Ovu proceduru ponavljamo za svako $k\in[1,N]$.
	
	Vremenska složenost je $O(N)$, a memorijska $O(1)$.
	
	
	
	``` cpp title="02_sadnice.cpp" linenums="1"
	#include <iostream>
	#include <cstring>
	#include <cstdio>
	
	using namespace std;
	
	bool res[50];
	
	void solve(long long x, int cur, int n) {
		if (x == 0) return;
		x = x - 1;
		int t = n - 1;
		while ((1LL << t) <= x) {
			x -= (1LL << t);
			t = t - 1;
			cur++;
		}
		res[cur] = true;
		solve(x, cur + 1, t);
	}
	
	int main() {
		int n;
		long long m;
		cin >> n >> m;
	
		memset(res, false, sizeof(res));
		solve(m - 1, 1, n);
	
		for (int i = 1; i <= n; ++i)
			if (res[i])
				printf("%d ", i);
		printf("\n");
	
		return 0;
	}
	```
