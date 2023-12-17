---
hide:
  - toc
---

# A1 - Zamena

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Mali Piksel, dugogodišnji član Tajne Komisije u senci, je odlučio da posle mnogo godina odane službe Komisiji podnese ostavku. Međutim, kako ne želi da njegov odlazak protekne nezapaženo, odlučio je da šifrira svoj poslednji predlog zadatka za Državno takmičenje iz programiranja, koristeći ključ koji je samo njemu poznat. Ostalim članovima Komisije ostavio je samo jedan niz koji sadrži sve njihove identifikacione brojeve (**identifikacioni brojevi su fiksne dužine i ne moraju biti jedinstveni**), kao i tekst problema koji članovi Komisije moraju rešiti da bi došli do ključa:
	
	Piksel je najpre prolazio kroz niz, od prvog elementa prema poslednjem, sve dok nije odabrao jedan identifikacioni broj i zapamtio ga. Zatim je nastavio prolaz kroz niz, i ukoliko bi naišao na veoma sličan identifikacioni broj (takav da se razlikuje od zapamćenog **najviše u jednoj cifri**) imao bi *dve opcije*:
	
	- da **zapamti novi broj umesto starog** i da nastavi dalje kroz niz na isti način;
	- da **nastavi dalje bez promene zapamćenog broja**.
	
	Piksel takođe čuva ukupan broj ”bodova” koji je osvojio pri prolazu kroz niz; u početku broj bodova je 0, međutim **pri svakom pamćenju novog broja, broj bodova se povećava za apsolutnu razliku cifre starog i novog broja na onoj poziciji u kojoj se novi broj razlikuje od starog** (npr. ukoliko je prethodno zapamćeni broj bio 1234, a novi zapamćeni broj je 1274, onda se broj bodova povećava za 4). Potrebno je odrediti **najveći mogući osvojen broj bodova**.
	
	Državno takmičenje iz programiranja je već počelo, a Komisija nije uspela dešifrovati zadatak i nije u mogućnosti da takmičarima ponudi novi. Stoga su vas zamolili za pomoć pri dešifrovanju; kao dodatnu motivaciju nude vam 100 dodatnih bodova na Državnom takmičenju.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se prirodan broj $N$, koji predstavlja ukupan broj članova Tajne komisije u senci. U svakom od narednih $N$ redova nalazi se po jedan ceo broj $A_i$, koji predstavlja identifikacioni broj tekućeg člana Komisije u nizu.
	
	## Opis izlaza
	U prvi i jedini red standardnog izlaza ispisati broj $M$, koji predstavlja maksimalan broj bodova koji je Mali Piksel mogao da osvoji.
	
	## Primer 1
	### Ulaz
	```
	6
	8823
	2145
	2185
	3385
	4145
	4445
	```
	
	### Izlaz
	```
	5
	```
	
	## Objašenjenje primera
	Piksel najpre bira da zapamti broj 2145. Zatim odmah ima opciju da zapamti 2185, međutim on odbija to da učini – pošto ukoliko odabere da zapamti tek 4145, pa 4445 nedugo zatim, osvaja 5 bodova:
	
	$$
	2145\rightarrow 4145\rightarrow 4445 \Rightarrow br\_bodova=(4-2)+(4-1)= 5
	$$
	
	Ne postoji ni jedna strategija kojom Piksel može osvojiti više od 5 bodova.
	
	## Napomena
	Test primeri su podeljeni u tri disjunktne grupe:
	
	* U test primerima vrednim 30 poena važi $N\leq 1.000$.
	* U test primerima vrednim 20 poena važi $A_i<100$.
	* U test primerima vrednim 50 poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Vanja Petrović Tanković | Petar Veličković | Aleksandar Višnjić | Vanja Petrović Tanković |
	
	## Prvi podzadatak:
	Zadatak rešavamo dinamičkim programiranjem. Neka $dp_i$ predstavlja maksimalan broj bodova koji je moguće ostvariti ako Piksel završava sa pamćenjem na indeksu $i$. Odgovor na zadatak je maksimalna vrednost niza $dp$. Rekurentna jednačina je
	
	$$
	dp_i=max(dp_j+f(i,j) | j<i)
	$$
	
	gde funkcija $f(i,j)$ predstavlja koliko se bodova dobija ako se sa prethodno zapamćenog broja na poziciji $j$ zapamti broj $i$. Ona takođe iznosi $-\infty$ ako se novi broj razlikuje od starog za više od jedne cifre (nemoguć slučaj). Složenost ovog algoritma je $O(N^2 \cdot C)$, gde je $C$ broj cifara svakog broja.
	
	## Drugi podzadatak:
	Koristimo sličnu ideju, ali primetimo da je broj različitih vrednosti $A_i$ mali. Neka $dp_{i,j}$ sada predstavlja maksimalan broj bodova koji je moguće ostvariti na prefiksu niza $A_1,...,A_i$ ako je poslednji zapamćen broj jednak $j$. Rekurentna jednačina je 
	
	$$
	dp_{i,j}=max(dp_{i-1,k}+f(A_i,k))
	$$
	
	Funkcija $f(a,b)$ se slično definiše kao ranije - broj bodova koji se ostvaruje datim prelazom. Vremenska i memorijska složenost je $O(N\cdot maxAi)$.
	
	## Glavno rešenje:
	Koristićemo slično rešenje kao i ranije. Najpre, primetimo da ima najviše $10\cdot C$ različitih mogućnosti za stari broj ako posmatramo neki određeni novi koji pamtimo ($C$ je broj cifara). Napravimo niz $dp_i$ koji predstavlja matricu iz drugog podzadatka, samo što nećemo pamtiti ništa za prefiks nego ćemo je redom popunjavati kako bismo uštedeli memoriju. To znači da za dato $i$ rekurentna jednačina postaje
	
	$$
	dp_{A_i}=dp_k+f(A_i,k)
	$$
	
	gde je $k$ svaka moguća mogućnost starog broja za koje smo ranije rekli da ih nema mnogo. Vremenska složenost je $O(N\cdot C\cdot L)$, a memorijska $O(maxAi)$. $L$ predstavlja broj različitih cifara u dekadnom sistemu, odnosno iznosi $10$
	
	``` cpp title="04_zamena.cpp" linenums="1"
	/*
	 Petar 'PetarV' Velickovic
	 Task: Zamena
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	
	#define MAX_N 100001
	#define MAX_NUM 10000000
	
	int n, len;
	int A[MAX_N];
	
	int dp[MAX_NUM];
	bool in[MAX_NUM];
	
	int ret = 0;
	
	inline int fetch_kth(int x, int k)
	{
	    for (int i=0;i<k;i++) x /= 10;
	    return x % 10;
	}
	
	inline int set_kth(int x, int k, int v)
	{
	    int prev = fetch_kth(x, k);
	    int deg = 1;
	    for (int i=0;i<k;i++) deg *= 10;
	    return x + (v - prev) * deg;
	}
	
	int main()
	{
	    scanf("%d", &n);
	    for (int i=0;i<n;i++)
	    {
	        scanf("%d", &A[i]);
	    }
	    len = 0;
	    int aa = A[0];
	    while (aa) { len++; aa /= 10; }
	    
	    in[A[0]] = true;
	    for (int i=1;i<n;i++)
	    {
	        int max_score = 0;
	        for (int j=0;j<len;j++)
	        {
	            int stor = fetch_kth(A[i], j);
	            for (int dig=0;dig<=9;dig++)
	            {
	                int curr = set_kth(A[i], j, dig);
	                int score = abs(stor - dig);
	                if (in[curr] && dp[curr] + score > max_score) max_score = dp[curr] + score;
	            }
	        }
	        dp[A[i]] = max_score;
	        in[A[i]] = true;
	    }
	    
	    for (int i=0;i<n;i++) if (dp[A[i]] > ret) ret = dp[A[i]];
	    
	    printf("%d\n", ret);
	    return 0;
	}

	```
