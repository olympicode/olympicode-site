---
hide:
  - toc
---

# 4 - Mudrac

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Tajna komisija nema vremena ni za šta a samim tim ni za smišljanje zadataka za SIO. Zbog toga su prevalili daleki put do Kazahstanskih planina (za to imaju vremena) i zatražili od čuvenog mudraca-programera iz pećine Didžita Programbajeva da im smisli zadatak. I on im reče:
	
	“Ljudi, na početku, prvog dana, imao sam $A$ kamila. Svakog narednog dana dobijam još onoliko kamila koliko je jednaka najveća cifra broja mojih kamila dan pre toga. Obratite pažnju da ja sve to stalno posmatram po modulu $M$ tj. ukoliko je $a_i$ broj kamila koje imam $i$-tog dana, tada važi 
	
	$$
	a_{i+1}=(a_i+\text{najveća cifra broja }a_i ) \text{ mod } M.
	$$
	
	Ukoliko je prošlo $N$ dana, odrediti koliko ima kilometara između Astane i Alma-Atija. Eto.”
	
	Članovi komisije su se malo zbunili neočekivanim krajem zadatka pa su rešili da ga malo izmene: za date prirodne brojeve $A$, $M$ i $N$, izračunajte koliko kamila ima mudrac na kraju $N$-tog dana.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* BrojKamila(A,M,N)
	
	gde je $A$ – broj kamila prvog dana, $M$ – moduo po kome se posmatraju članovi niza i $N$ – broj dana koji su prošli. Ova funkcija mora da vrati jedan ceo broj iz segmenta $[0,M-1]$ – broj kamila koje poseduje mudrac na kraju $N$-tog dana.
	
	## Primer
	Neka je $A=123$, $M=134$ i $N=6$. Ukoliko sa $a_i$ označimo broj kamila $i$-tog dana, tada važi: $a_1=A=123$, $a_2=(123+3) \text{ mod } 134=126$, $a_3=(126+6) \text{ mod } 134=132$, $a_4=(132+3) \text{ mod } 134=1$, $a_5=(1+1) \text{ mod } 134=2$, $a_6=(2+2) \text{ mod }134=4$. Prema tome, u ovom slučaju vaša funkcija mora da vrati broj $4$.
	
	## Ograničenja
	* $1\leq A < M\leq 10^{18}$
	* $1\leq N\leq 10^{18}$
	
	## Podzadaci i bodovanje
	* PODZADATAK 1 [5 POENA]: $N\leq 10^6$
	* PODZADATAK 2 [12 POENA]: $M\leq 10^6$
	* PODZADATAK 3 [25 POENA]: $A=1$, $M=201520152015$ i $N\leq 10^9$.
	* PODZADATAK 4 [41 POENA]: $A,N\leq 10^{17}$, $M=10^{18}$.
	* PODZADATAK 5 [17 POENA]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom mudrac.c, mudrac.cpp ili mudrac.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	```
	C/C++
	    long long BrojKamila(long long A, long long M, long long N);
	Pascal
	    function BrojKamila(A, M, N : int64) : int64;
	```
	
	Ukoliko radite u C/C++-u, potrebno je na početku fajla staviti `#include “mudrac.h”` a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti `Unit mudrac;` **(ovo je već dodato u fajlovima koji su vam obezbeđeni)**.
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (mudrac.c, mudrac.cpp, mudrac.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	* U prvom i jedinom redu brojeve $A$, $M$ i $N$, redom, razdvojene razmakom
	
	a zatim pozivaju vašu funkciju $BrojKamila$ iz odgovarajućeg fajla (mudrac.c, mudrac.cpp, mudrac.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Mihail Tihomirov | Aleksandar Ivanović |
	
	For now, ignore the modulo. Suppose that the current number $x = a\cdot 10^p + d$ for some non-negative integers $a$, $p$ and $0 \leq d < 10$.
	
	Until $x$ reaches $\geq (a + 1)\cdot 10^p$, the sequence of changes to $x$ depends only on $p$, $d$, and $k$ — the largest digit of $a$. Right after that we will have $(a+1)\cdot 10^p \leq x < (a+1)\cdot 10^p+10$, since each increase is by at most $9$.
	
	Let $steps_{p,d,k}$ and $delta_{p,d,k}$ be the number of steps and total change made to $x$ until $x$ reaches $\geq (a + 1) \cdot 10^p$. We can calculate $steps_{p,d,k}$ and $delta_{p,d,k}$ for all $p > 0$, $d$, $m$ by using $steps_{p−1,\ldots,\ldots}$ and $delta_{p−1,\ldots,\ldots}$ to quickly skip stages of the process.
	
	Note that $steps_{p,0,0}$ and $delta_{p,0,0}$ are undefined since no increases are ever made.
	
	Using $steps_{p,d,k}$ and $delta_{p,d,k}$ we can quickly calculate:
	
	* the value of any $x$ after $n$ steps (provided $x$ never exceeds $m$);
	* the number of steps we take starting from $x$ until $x > m$, and the resulting value of $x$.
	
	To do this, find the largest $p$ such that $x \text{ mod } 10^p < 10$, and also, if $p > 0$, $steps_{p,x \text{ mod } 10^p,k} \leq n$ or $x+ delta_{p,x \text{ mod } 10^p,k} \leq m$ ($k$ being the largest digit of $\lfloor x/10^p\rfloor$), and use this to skip ahead in the process. Only $O(\log m)$ of such skips are required.
	
	Now we can solve the problem. Whenever we skip ahead, we assume that $x$ and the remaining number of steps $n$ decrease accordingly. Whenever $n = 0$, we terminate.
	
	One method is to repeatedly find the first moment when either $x > m$ or $n = 0$. After that, if $n > 0$, we take $x \text{ mod } m$ and go again. If at any point $x = 0$, we immedaitely terminate.
	
	This may work very slow when $n$ is much larger than $m$. However, by looking at the values of $x$ after taking modulo $m$, we notice that the process becomes periodic after at most $10$ loops.
	
	If the period takes $z$ steps, take $n$ modulo $z$ to skip many periods ahead. After this, at most $10$ further loops are required.
	
	``` cpp title="04_mudrac.cpp" linenums="1"
	#include "mudrac.h"
	
	#include <cstdlib>
	#include <cstdio>
	
	const int MAX_DIGITS = 20;
	
	long long StepNum[10][MAX_DIGITS + 1][10];
	int NextLastDigit[10][MAX_DIGITS + 1][10];
	long long pow10[MAX_DIGITS + 1];
	bool mark[10];
	int next[10];
	long long cost[10];
	
	int max(int a, int b)
	{
		return (a > b ? a : b);
	}
	
	int MaxDigit(long long num)
	{
		int ret = 0;
		while (num > 0)
		{
			int lastDigit = num % 10;
			ret = max(ret, lastDigit);
			num = num / 10;
		}
		return ret;
	}
	
	void Precalculate()
	{
		pow10[0] = 1LL;
		for (int i = 1; i <= MAX_DIGITS; i++)
			pow10[i] = pow10[i - 1] * 10;
	
		// base
		for (int maxPrefDigit = 0; maxPrefDigit < 10; maxPrefDigit++)
		{
			for (int lastDigit = 0; lastDigit < 10; lastDigit++)
			{
				if (maxPrefDigit == 0 && lastDigit == 0) continue;
				int c = lastDigit;
				StepNum[maxPrefDigit][1][lastDigit] = 0;
				while (c < 10)
				{
					c = c + max(maxPrefDigit, c);
					StepNum[maxPrefDigit][1][lastDigit]++;
				}
				NextLastDigit[maxPrefDigit][1][lastDigit] = c % 10;
			}
		}
	
		for (int len = 2; len <= MAX_DIGITS; len++)
		{
			for (int maxPrefDigit = 0; maxPrefDigit < 10; maxPrefDigit++)
			{
				for (int lastDigit = 0; lastDigit < 10; lastDigit++)
				{
					if (maxPrefDigit == 0 && lastDigit == 0) continue;
					StepNum[maxPrefDigit][len][lastDigit] = 0;
					int currLastDigit = lastDigit;
					for (int c = 0; c <= 9; c++)
					{
						StepNum[maxPrefDigit][len][lastDigit] += StepNum[max(maxPrefDigit, c)][len - 1][currLastDigit];
						currLastDigit = NextLastDigit[max(maxPrefDigit, c)][len - 1][currLastDigit];
					}
					NextLastDigit[maxPrefDigit][len][lastDigit] = currLastDigit;
				}
			}
		}
	}
	
	// vraca broj A_{n+1} ako je A_1 = startNum, tj. broj koji se dobije kada
	// se n puta primeni povecavanje za max cifru (ne gleda module)
	long long F(long long startNum, long long n)
	{
		if (startNum == 0LL)
			return 0LL;
	
		int C = startNum % 10;
		int B = 1;
		long long val = startNum / 10;
		int A = MaxDigit(val);
		// num = val * 10^B + C, A - max cifra u val
		while (n > 0 && B > 0)
		{
			if (StepNum[A][B][C] <= n)
			{
				n = n - StepNum[A][B][C];
				C = NextLastDigit[A][B][C];
				val = val + 1;
				A = MaxDigit(val);
				if (val % 10 == 0)
				{
					B++;
					val = val / 10;
				}
			}
			else
			{
				B--;
				val = val * 10;
			}
		}
	
		long long sol;
		if (n > 0)
		{
			val = val + C;
			for (int i = 1; i <= n; i++)
			{
				val = val + MaxDigit(val);
			}
			sol = val;
		}
		else
		{
			sol = val * pow10[B] + C;
		}
	
		return sol;
	}
	
	// racuna broj koraka (dodavanja max cifre) da bi se od broja
	// start dobio najmanji broj >= goal
	long long MinNumOfStepsToReach(long long start, long long goal)
	{
		long long L = 1, R = goal - start;
		while (L < R)
		{
			long long M = (L + R) / 2;
			if (F(start, M) < goal)
				L = M + 1;
			else
				R = M;
		}
		return L;
	}
	
	void RemoveModulo(long long& A, long long& M, long long& N)
	{
		long long x = MinNumOfStepsToReach(A, M);
		if (N < x)
			return;
		N = N - x;
		A = F(A, x) - M;
		for (int i = 0; i < 10; i++) 
			mark[i] = false;
	
		while (!mark[A])
		{
			mark[A] = true;
			if (A == 0LL) return;
			cost[A] = MinNumOfStepsToReach(A, M);
			if (N < cost[A]) return;
			N = N - cost[A];
			next[A] = F(A, cost[A]) - M;
			A = next[A];
		}
	
		long long totalCost = cost[A];
		int curr = next[A];
		while (curr != A)
		{
			totalCost = totalCost + cost[curr];
			curr = next[curr];
		}
		
		N = N % totalCost;
		while (N >= cost[A])
		{
			N = N - cost[A];
			A = next[A];
		}
	}
	
	long long BrojKamila(long long A, long long M, long long N)
	{
		N = N - 1;
		Precalculate();
		RemoveModulo(A, M, N);
		return F(A, N);
	}

	```
