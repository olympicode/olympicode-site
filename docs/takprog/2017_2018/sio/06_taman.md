---
hide:
  - toc
---

# 6 - Taman

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 128MB |
	
	U drevnom podrumu Komisije za žalbe, nalazi se $N$ gomila takmičarskih žalbi poređanih u niz - na $i$-toj gomili se nalazi $a_i$ žalbi. Došlo je vreme da se i te žalbe odbiju pa je Glavni Arhivator Đorđe Kavurmov dobio zadatak da podeli gomile članovima komisije. Kavurmov planira da podeli ove gomile žalbi u  **hrpe (veće gomile) - uzastopne podnizove gomila žalbi pri čemu će svaka gomila žalbi pripadati tačno jednoj hrpi (podnizu).**
	
	Međutim, to nije trivijalan posao jer veličine hrpi moraju biti **taman** (akcenat na drugo 'a') tj. ni prevelike ni premale. Preciznije, **za svaku hrpu mora važiti da njena veličina (broj gomila žalbi u njoj, tj. dužina podniza) nije manja od najmanje gomile koja joj pripada (jer to nema smisla) i da nije veća od najveće gomile koja joj pripada (jer je to bezveze).**  Kako Arhivator ne voli da radi, on je odlučio da sedi i razmišlja **na koliko načina može podeliti dati niz gomila na hrpe**. Zapravo, odlučio je samo da sedi a razmišljanje prepušta vama - kao nagradu, proslediće vašu žalbu nekome ko ih zapravo čita pre odbijanja.
	
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $TamanPodela(N, a[\ldots])$
	
	gde je $N$ - broj gomila žalbi dok je $a$ niz koji opisuje gomile žalbi: $i$-ta gomila sadrži $a_i$ žalbi. **Niz $a$ je indeksiran od 1.** Ova funkcija mora da vrati jedan ceo broj -- traženi broj podela **po modulu $1.000.000.007$ $(10^9 + 7)$.** Obratiti pažnju da rešenje mora biti u segmentu $[0, 10^9 + 6]$.
	
	## Primer
	Neka je $N = 7$ i $a = [1, 6, 2, 3, 4, 3, 4]$. Tada je niz od ovih 7 gomila žalbi moguće podeliti na hrpe na sledećih $6$ načina: | 1 | 6 2 3 4 3 4 |, | 1 6 2 | 3 4 3 4 |, | 1 6 2 3 | 4 3 4 |, | 1 | 6 2 | 3 4 3 4 |, 
	| 1 | 6 2 3 | 4 3 4 |, | 1 6 | 2 3 | 4 3 4 |; dakle, u ovom slučaju vaša funkcija mora vratiti broj $6$ $mod$ $(10^9 + 7)$ $=$ $6$. Obraditi pažnju da npr. podela | 1 6 | 2 3 4 3 4 | nije validna jer je veličina (dužina) desne hrpe $5$ što je veće od najveće gomile koja joj pripada ($4$); takođe, podela | 1 6 2 | 3 4 | 3 4 | nije validna jer je veličina poslednje dve hrpe $2$ što je manje od najmanjih gomila koje im pripadaju (u oba slučaja $3$).
	
	## Ograničenja
	
	+ $1 \leq N \leq 500.000$
	+ Za svako $i = \overline{1,N}$ važi $1 \leq a_i \leq N$
	
	## Podzadaci
	
	+ Podzadatak $1$ [$9$ poena]: $N \leq 1.000$.
	+ Podzadatak $2$ [$10$ poena]: $N \leq 100.000$, $a_i \leq 500$.
	+ Podzadatak $3$ [$12$ poena]: U nizu $a$ postoje tačno 2 različite vrednosti.
	+ Podzadatak $4$ [$24$ poena]: Za svaki paran indeks $i$ važi $a_i = N$.
	+ Podzadatak $5$ [$45$ poena]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `taman.cpp` ili `taman.pas`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	U zavisnosti od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	| Jezik   | Deklaracija funkcije                                                                                    | 
	| ------- | ------------------------------------------------------------------------------------------------------- |
	| C++     | `int TamanPodela(int N, int a[]);`  |
	| Pascal  | `function TamanPodela(N : longint; var a : array of longint) : longint;`   |
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova**.
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam "template" fajlovi `code.cpp` i `code.pas` koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi `grader.cpp`, `grader.pas` koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu broj $N$,
	+ U narednom redu $N$ brojeva, elemente niza $a$
	
	a zatim pozivaju vašu funkciju sa učitanim parametrima i, na kraju, vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Bhuvnesh Jain | Ivan Stošić |
	
	Možete pročitati editorijal na engleskom (CodeChef je koristio naš zadatak za Challenge rundu): [Link](https://discuss.codechef.com/t/safpar-editorial/24848)
	
	``` cpp title="06_taman.cpp" linenums="1"
	#include <cstdlib>
	#include <algorithm>
	
	using namespace std;
	
	const int MAX_N = 500005;
	const int MOD = 1000000007;
	
	int s[MAX_N];
	int index_left[MAX_N];
	int L[MAX_N];
	int R[MAX_N];
	int d[MAX_N];
	int preff_sum[MAX_N];
	
	int sum(int l, int r)
	{
		if (l == 0)
			return preff_sum[r];
		else
			return (preff_sum[r] - preff_sum[l - 1]) % MOD;
	}
	
	int TamanPodela(int N, int a[])
	{
		// index_left[i] = najveci indeks j <= i takav da je a[j..i] taman podniz ili <= 0 ako takvo j ne postoji
		// dovoljno je samo proveravati uslov (i - j + 1) >= min[j..i]
		// koristimo dequeue gde odrzavamo strogo rastuce vrednosti
		int l = 1, r = 0;
		for (int i = 1; i <= N; i++)
		{
			while (l <= r && a[i] <= a[s[r]]) r--;
			s[++r] = i;
			if (l < r && min(s[l], i - a[s[l]] + 1) <= min(s[l + 1], i - a[s[l + 1]] + 1)) l++;
			index_left[i] = min(s[l], i - a[s[l]] + 1);
		}
	
		// L[i] - najveci indeks j < i tako da je a[j] > a[i]
		for (int i = 1; i <= N; i++)
		{
			int curr = i - 1;
			while (curr != 0 && a[curr] <= a[i])
				curr = L[curr];
			L[i] = curr;
		}
		// R[i] - najmanji indeks j > i tako da je a[j] >= a[i]
		for (int i = N; i >= 1; i--)
		{
			int curr = i + 1;
			while (curr <= N && a[curr] < a[i])
				curr = R[curr];
			R[i] = curr;
		}
	
		// d[i] = optimalno resenje za podniz a[1..i]
		for (int i = 1; i <= N; i++) d[i] = 0;
		d[0] = 1;
		preff_sum[0] = 1;
		int currSum = 0;
		for (int i = 1; i <= N; i++)
		{
			currSum = (currSum + d[i]) % MOD;
			// dodati d[l..r] trenutnoj sumi
			int r = i - 1;
			int l = max(i - a[i], L[i]);
			currSum = (currSum + sum(l, r)) % MOD;
	
			// unapred oduzeti d[curr] odgovarajucim d[]-ovima
			int curr = l;
			while (curr + a[i] + 1 < R[i] && curr < i)
			{
				d[curr + a[i] + 1] = (d[curr + a[i] + 1] - d[curr]) % MOD;
				curr++;
			}
			if (curr + a[i] + 1 >= R[i])
				d[R[i]] = (d[R[i]] - sum(curr, r)) % MOD;
	
			// izracunati d[i]
			if (index_left[i] <= 0)
				d[i] = 0;
			else
				d[i] = (currSum - sum(index_left[i], i - 1)) % MOD;
	
			if (d[i] < 0) d[i] = (d[i] + MOD) % MOD;
			preff_sum[i] = (preff_sum[i - 1] + d[i]) % MOD;
		}
	
		return d[N];
	}

	```
