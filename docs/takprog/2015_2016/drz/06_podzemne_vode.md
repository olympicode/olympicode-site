---
hide:
  - toc
---

# A3 - Podzemne vode

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	U srednjevekovnom selu Enjored, nalazi se n srenjovekovnih placeva poređanih u red, jedan do drugog, numerisanih srednjevekovnim brojevima od 1 do $n$. Za svaki plac je poznata snaga uticaja srednjevekovnih podzemnih voda nad njim; za $i$-ti plac ta vrednost je $v_i$. Jednog dana, skupilo se $k$ srednjevekovnih vazalnih gospodara i odlučili su da izgrade $k$ velikih kuća pri čemu bi svaka kuća zauzimala tačno $t$ uzastopnih placeva i, naravno, nikoje dve kuće ne mogu imati zajednički plac.
	
	U dogovoru sa selom, vazalni gospodari su se obavezali da, na ime srednjevekovnog poreza, ukupno plate po 1 zlatnik za svaki od $n$ placeva koji nisu deo nijedne kuće. Ispostavilo se da su vrednosti $n$, $k$ i $t$ takve da kada $k$ vazalnih gospodara podjednako podele porez, svako od njih treba da plati ne više od 10 zlatnika.
	
	Naravno, najbitnija stvar u ovoj srednjevekovnoj priči je odbrana od srednjevekovnih veštica. U to vreme, kada bi ljudi gradili kuće, oni bi postavljali anti-veštične urećaje u najlevljem placu svoje kuće i otpornost kuće na veštice bi direktno zavisila od odgovarajuće podzemne vode. Npr. ukoliko se kuća nalazi na placevima $i, i+ 1, . . . i+t−1$, otpornost te kuće je $v_i$. Vazalnigospodari su razumni ljudi koji veruju u veštice i dogovorili su se da sagrade kuće tako da je suma otpornosti kuća na veštice najveća moguća. Pomozite im u tome!
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalaze se tri prirodna broja $n$, $k$ i $t$ koji predstavljaju, redom, broj placeva, broj kuća koje treba izgraditi i dužinu svake kuće u placevima. U narednom redu nalaze se $n$ prirodnih brojeva $v_i$, gde $i$-ti broj predstavlja snagu uticaja podzemne vode na $i$-ti plac.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati najveću moguću vrednost sume otpornosti svih kuća. Garantuje se da će rešenje (tj. bar jedan raspored kuća) uvek postojati.
	
	## Primer 1
	### Ulaz
	```
	8 3 2
	4 5 1 4 8 10 7 3
	```
	
	### Izlaz
	```
	20
	```
	## Objašnjenja primera
	Imamo 8 placeva i potrebno je izgraditi 3 kuće od kojih svaka zauzima po 2 uzastopna placa. Ukoliko kuće izgradimo na sledeći način: 4 {5 1} 4 {8 10} {7 3} , tada je ukupna otpornost kuća jednaka $v_2$ + $v_5$ + $v_7$ = 20. Može se pokazati da ne postoji raspored kuća koji daje otpornost veću od 20.
	
	## Ograničenja
	
	* $n ≤ 800 000$
	* $1 ≤ t, k ≤ 3 000$
	* $1 ≤ v_i ≤ 10^9$
	* Za brojeve $n$, $k$ i $t$ važe sva dodatna ogrančenja iz teksta zadataka.
	 
	## Podzadaci i bodovanje. 
	Test primeri su podeljeni u 4 podzadatka, u kojima važe sledeća dodatna
	ograničenja:
	
	* Podzadatak 1 [12 poena]: $n ≤ 20, k, t ≤ 5$
	* Podzadatak 2 [15 poena]: Posle izgradnje, ostaće tačno jedan slobodan plac
	* Podzadatak 3 [30 poena]: $n ≤ 30 000$
	* Podzadatak 4 [43 poena]: Nema dodatnih ograničenja.
	
	## Napomena
	Obratiti pažnju da je za ispis rešenja neophodan 64-bitni tip podataka.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Slobodan Mitrović | Nikola Milosavljević | Pavle Martinović | Slobodan Mitrović |
	
	## Решење када $N\leq 20$
	У овом случају ћемо да проверимо свих $2^N$ комбинација које плацеве ћемо изабрати као најлевље. Затим у линеарном времену се стандардно проверава да ли постоје два која су на дистанци мањој од $t$ и да ли их је тачно $k$. Стога налатимо решење у $O(2^N)$

	## Решење када oстане само један плац
	Ако фиксирамо $x$ који ће нам то плац остати непопуњен, локације свих кућа ће бити јединствено одређене, и то ће им се најлевљи плацеви налазити на сваких $t$ лево од $x-t$, и на сваких $t$ десно од $x+1$.  Памћењем префиксних и суфиксних сума на сваких $t$ (рекурентна веза $pref[x]=a[x]+pref[x-t]$) можемо за сваки плац који избацимо одмах да израчунамо решење, укупно у $O(N)$.

	## Решење када $N\leq 30000$
	У овом случају радимо динамичко програмирање са стањем $dp[i][j]$, које представља решење проблема ако посматрамо само првих $j$ плацева, и до сада смо доделили куће првих $i$ становника. Ово динамичко програмирање има јако једноставну рекурентну везу: последњи плац може да не буде део куће, у ком случају је одговор $dp[i][j-1]$, или да буде део куће у ком случају је одговор $dp[i-1][j-t]+a[i-t+1]$. Стога налазимо $O(1)$ транзицију задату формулом $dp[i][j]=max(dp[i][j-1],dp[i-1][j-t]+a[i-t+1])$, а како оно има $O(n^2)$ стања, налазимо решење у тој сложености. Како нема меморије запамтити сва стања, али свако стање зависи само од тренутног и претходног слоја (ако нам је "слој" колико има становника до сад), можемо применити стандардну фору памћења само последња два нивоа у динамичком.

	## Главно решење
	Главно решење представља модификацију претходног приступа динамичким програмирањем. Наиме приметимо да нема много смисла да $i$-ти становник има кућу пре позиције $(i-1)t$ и после $n-t(k-i)+1$, јер у том случају нема места да стану куће пре, односно после, његове куће. Тако да једино има смисла рачунати $n-kt$ од свих позиција за неку фиксну вредност од $i$ у претходном динамичком програмирању, па нам број стања постаје $k(n-kt)$. Најзад, како има тачно $n-kt$ незаузетих плацева, налазимо да је услов за порез еквивалентан са тиме да је $\frac{n-kt}{k}\le10$, па нам дозвољава да ограничимо број стања са $10k^2$, и налазимо решење у $O(10k^2)$.
	
	``` cpp title="06_podzemne_vode.cpp" linenums="1"
	#define _CRT_SECURE_NO_WARNINGS
	#include <cstdlib>
	#include <cstdio>
	#include<memory.h>
	#include<algorithm>
	
	using namespace std;
	
	const int MAX_N = 800010;
	const int MAX_K = 3010;
	const int MAX_T = 3010;
	
	int n, k, t;
	int v[MAX_N];
	long long d[2][MAX_N];
	
	long long solve(int n, int k, int t, int v[])
	{
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= n; i++)
		{
			d[0][i] = max(d[0][i - 1], (long long)v[i]);
		}
	
		int currRow = 0;
		for (int i = 2; i <= k; i++)
		{
			currRow = 1 - currRow;
			int L = 1 + (i - 1) * t;
			int R = n - (k - i) * t;
			d[currRow][L] = d[1 - currRow][L - t] + v[L];
			for (int j = L + 1; j <= R; j++)
			{
				d[currRow][j] = max(d[currRow][j - 1], d[1 - currRow][j - t] + v[j]);
			}
		}
	
		return d[currRow][n];
	}
	
	int main()
	{
	
		scanf("%d%d%d", &n, &k, &t);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
		}
		n = n - (t - 1);
	
		printf("%lld\n", solve(n, k, t, v));
	
		return 0;
	}
	```
