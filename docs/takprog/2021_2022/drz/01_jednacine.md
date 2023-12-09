---
hide:
  - toc
---

# B1 - Jednačine

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	
	Za dati prirodan broj $n$, označimo sa $S(n)$ sumu njegovih cifara. Dakle, $S(12) = 1 + 2 = 3$, $S(1005) = 1 + 0 + 0 + 5 = 6$. Duško voli da ispituje svojstva prirodnih brojeva, pa je smislio sebi zadatak. Za date brojeve $X, Y, A, B$ ($X \leq Y$) njega zanima da li postoji neki broj $n$ takav da $X \leq n \leq Y$ za koji važi da je $n = A \cdot S(n) + B$. 
	
	## Opis ulaza
	
	U prvom i jedinom redu standardnog ulaza nalaze se celi brojevi $X, Y, A, B$.
	
	## Opis izlaza
	
	Ukoliko postoji neki broj $n$ za koji važi i $X \leq n \leq Y$ i $n = A \cdot S(n) + B$, u prvom i jedinom redu standardnog izlaza ispisati taj broj. Ukoliko postoji više od jednog rešenja, ispisati bilo koje od njih. Ukoliko ne postoji nijedno rešenje, ispisati $-1$.
	
	## Ograničenja
	
	$1 \leq X \leq Y \leq 10^{18}$
	$0 \leq A, B \leq 10^{18}$
	
	## Podzadaci
	
	1. (10 poena) $A = 0$ 
	2. (20 poena) $Y \leq 10^6$ 
	3. (35 poena) $A, B \leq 10^{15}$ 
	4. (35 poena) Bez dodatnih ograničenja 
	
	## Primeri
	
	### Primer 1
	
	### Ulaz
	
	~~~
	9 142 1 0
	~~~
	
	### Izlaz
	
	~~~
	3
	~~~
	
	### Objašnjenje primera
	
	Broj $9$ zadovoljava i uslov da je između $9$ i $142$, i važi da je $9 = 1 \cdot S(9) + 0 = 9$, tako da je $9$ validno rešenje. U ovom primeru, ne postoji nijedno više validno rešenje.
	
	### Primer 2
	
	### Ulaz
	
	~~~
	18 23 4 3
	~~~
	
	### Izlaz
	
	~~~
	23
	~~~
	
	### Objašnjenje primera
	
	$23$ je validno rešenje jer je u zadatom intervalu i jer je $23 = 4 \cdot S(23) + 3$. U ovom primeru, broj $23$ je jedino validno rešenje.
	
	### Primer 3
	
	### Ulaz
	
	~~~
	1 9 1 1
	~~~
	
	### Izlaz
	
	~~~
	-1
	~~~
	
	### Objašnjenje primera
	
	Nijedan broj iz intervala ne zadovoljava dati uslov.
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Vladimir Milenković | Dragan Urošević | Aleksandar Zlateski |
	
	## Rešenje podzadatka 1
	Primetimo da je u ovom slučaju jedina moguća vrednost za $n$ broj
	$$
	n = A\cdot S(n) + B = 0 \cdot S(n) + B = B.
	$$
	Zbog toga je dovoljno samo proveriti da li je broj $n=B$ između $X$ i $Y$ i ako jeste ispisati taj broj, u suprotnom ispisati vrednost $-1$. Složenost ovog rešenja je $O(1)$.
	
	## Rešenje podzadatka 2
	Kako je $n\leq Y \leq 10^6$, dovoljno je za svako $n$ iz intervala $[X,Y]$ odrediti zbir cifara (uzastopnim deljenjem tog broja sa $10$ i sabiranjem ostataka), a nakon toga proveriti da li zadovoljava jednačinu . Naravno, nakon pronalaska prve takve vrednosti za broj $n$ ispisuje se ta vrednost i prekida izvršavanje programa. Ako nijedan broj iz intervala $[X,Y]$ ne zadovoljava jednačinu, ispisuje se vrednost $-1$. Složenost ovog rešenja je $O(Y\log Y)$.
	
	## Rešenje podzadataka 3 i 4
	Primetimo da ako je $1\leq X \leq n \leq Y \leq 10^{18}$, onda je $1 \leq S(n) \leq 18 \cdot 9 = 162$. Samim tim je skup mogućih vrednost za izraz $A\cdot S(n) +B$ zapravo skup
	$$
	U = \{A\cdot T + B|T = 1, 2, \dots, 162\}
	$$
	i to je skup mogućih vrednosti za broj $n$.
	
	Prema tome, dovoljno je za elemente $n\in U$, proveriti da li zadovoljavaju jednačinu 
	$$
	S(n) = S(A\cdot T + B) = T
	$$
	i ako neki od njih zadovoljava ispisati njegovu vrednost, u suprotnom ispisati broj $-1$. Broj elemenata skupa $U$ je $O(\log Y)$, a provera da li neki element $n$ skupa $U$ zadovoljava gornju jednakost ima složenost $O(\log n)=O(\log Y)$, pa je složenost celog algoritma $O(\log^2 Y)$. 
	
	Pri rešavanju podzadatka 4 treba voditi računa da pri računanju vrednosti $A\cdot T + B$ može doći do prekoračenja.  
	
	
	``` cpp title="01_jednacine.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	const ll LIM = 1'000'000'000'000'000'000;
	inline int digit_sum (ll x) {
		int ans = 0;
		while (x) {
			ans += x % 10;
			x /= 10;
		}
		return ans;
	}
	int main() {
		ll x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		for (int sum_digits = 0; sum_digits <= 200; sum_digits++) {
			ll guess = sum_digits * a + b;
			if (guess > LIM) break;
			// cout << sum_digits << " " << guess << " " << digit_sum(guess) << endl;
			if (x <= guess && guess <= y && digit_sum(guess) == sum_digits) {
				printf("%lld\n", guess);
				return 0;
			}
		}
		printf("-1\n");
		return 0;
	}

	```
