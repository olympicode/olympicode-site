---
hide:
  - toc
---

# B2 - Poljoprivrednik

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Miloranka, nova mlada nada Šljivograda, tek što je naučila da učitava nizove, a već je dobila zadatak od svog profesora Rastislava. Zadatak glasi:
	
	Data su tri broja $N$, $K$ i $X$. Pronaći jedan niz $A$ koji ima $N$ članova, svi članovi su prirodni brojevi manji od $10^6$ i u kojem postoji **tačno** $K$ parova indeksa ($i, j$) sa svojstvom: 
	
	* $1\leq i<j\leq N$
	* $|A_i - A_j|\geq X$. 
	
	Pošto je Rastislav poljoprivrednik i bavi se programiranjem jedino kada nije sezona šljiva, moguće da je pogrešio i dao takva tri broja da ne postoji nijedan niz $A$ koji ispunjava tražene uslove. U tom slučaju ispisati $-1$. Pomozite Miloranki da reši profesorov zadatak.
	
	## Opis ulaza
	
	U prvoj i jedinoj liniji standardnog ulaza nalaze se tri cela broja $N$, $K$ i $X$, opisana u tekstu zadatka.
	
	## Opis izlaza
	
	U jedinoj liniji standardnog izlaza ispisati $N$ prirodnih brojeva, članove niza $A$ koji ispunjava tražena svojstva. U slučaju da takav niz ne postoji ispisati $-1$.
	
	## Primer 1
	
	### Ulaz
	
	~~~
	3 2 5
	~~~
	
	
	### Izlaz
	
	~~~
	1 8 2
	~~~
	
	### Objašnjenje primera
	
	Niz $A={1, 8, 2}$, ima $N=3$ člana, i $K=2$ para indeksa, ($1, 2$) i ($2, 3$), ispunjavaju svojstvo iz zadatka:
	
	* $|A_1 - A_2| = 7 \geq 5 = X$   
	* $|A_2 - A_3| = 6 \geq 5 = X$
	
	## Ograničenja
	
	* $1 \leq N \leq 1000$
	* $2 \leq X \leq 1000$
	* $0 \leq K \leq \frac{N\cdot (N-1)}{2}$
	
	Postoje tri podzadatka:
	
	* Podzadatak 1 [21 poen]: $K=3$.
	* Podzadatak 2 [22 poena]: $N=K$.
	* Podzadatak 3 [57 poena]: Nema dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Aleksa Plavšić | Dimitrije Erdeljan | Aleksa Milisavljević |
	
	## Analiza
	
	Podelićemo zadatak na dva slučaja:
	
	* kada $K \geq N$, i
	* kada $K < N$.
	
	U slučaju u kom je $K \geq N$, zadatak možemo svesti na rešavanje
	zadatka za $N-1$ i $K - (N-1)$ tako što odaberemo prvi element niza
	(npr. postavimo ga na $1$), konstruišemo niz sa $N-1$ elemenata gde
	imamo $K - (N-1)$ parova na rastojanju većem od $X$, i "pomerimo" taj
	niz tako da je na rastojanju većem od $X$ od prvog elementa (tj. na sve
	elemente dodamo $X$).
	
	U slučaju kada $K < N$, zadatak možemo rešiti na sledeći način:
	
	* postavimo prvi element na $1$,
	* postavimo $K$ elemenata na $X$, i
	* ostale elemente stavimo između ova dva (na primer, na $2$).
	
	## Smernice za algoritam
	
	Da bi zadatak rešili u $\mathcal{O}(N)$ umesto $\mathcal{O}(N^2)$,
	možemo eliminisati korak u kom pomeramo celo rešenje tako što tokom
	izvršavanja programa pamtimo poziciju od koje počinju elementi koje još
	nismo postavili, i dodamo je na sve elemente koje postavimo od tog
	abattoirs na dalje.
	
	``` cpp title="02_poljoprivrednik.cpp" linenums="1"
	#include<bits/stdc++.h>
	
	using namespace std;
	
	int n,k,x;
	int rez[1001];
	
	void solve(int n, int k, int x, int poz)
	{
	    if (k < n)
	    {
	        rez[n--] = poz;
	        for (int i=1; i <= k; i++)
	            rez[n--] = poz + x;
	
	        while(n)
	            rez[n--] = poz + x / 2;
	    }
	    else
	    {
	        rez[n--] = poz;
	        solve(n, k - n, x, poz + x);
	    }
	}
	int main()
	{
	    cin>>n>>k>>x;
	
	    solve(n, k, x, 1);
	
	    for (int i=1; i <= n; i++)
	        cout<<rez[i]<<" ";
	
	    return 0;
	}

	```
