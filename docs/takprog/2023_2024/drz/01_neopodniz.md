---
hide:
  - toc
---

# B1 - Neopodniz

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Za nisku $A$ kažemo da je **podniz** niske $B$ ukoliko se $A$ može dobiti brisanjem nekoliko karaktera iz $B$, zadržavajući redosled. Na primer, `a`, `ab` i `aa` su podnizovi niske `aba`, dok `bb` i `aab` to nisu.
	
	Za nisku $A$ kažemo da je **nepodniz** niske $B$ ukoliko ona nije njen podniz.
	
	Data je niska $S$ dužine $N$ i prirodan broj $K$. Poznato je da se $S$ sastoji od prvih $K$ malih slova Engleske abecede. Odrediti, za svako $i$ ($1 \leq i \leq N$), dužinu **najmanjeg** nepodniza niske $S_1 S_2 \ldots S_i$. Pritom, razmatramo nepodnize koji se sastoje samo od prvih $K$ slova Engleske abecede.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza, nalaze se dva prirodna broja $N$ i $K$.
	
	U drugom redu standardnog ulaza, nalazi se jedna niska $S$ dužine $N$. Garantuje se da se ona sastoji od prvih $K$ malih slova Engleske abecede.
	
	## Opis izlaza
	
	Na standardni izlaz ispisati $N$ celih brojeva u jednom redu. $i$-ti od njih predstavlja dužinu najmanjeg nepodniza niske $S_1 S_2 \ldots S_i$.
	
	## Primer 1
	
	### Ulaz
	
	```
	7 3
	abcbaca
	```
	
	### Izlaz
	
	```
	1 1 2 2 2 3 3
	```
	
	### Objašnjenje
	
	Najmanji po dužini nepodnizovi niske `a` su `b` i `c`. Oba imaju dužinu $1$ i odgovaraju prvom broju na izlazu.
	
	Najmanji po dužini nepodniz niske `ab` je `c`. On ima dužinu $1$, što odgovara drugom broju na izlazu.
	
	Jedan od najmanjih nepodnizova niske `abc` je `ba`. On ima dužinu $2$, što odgovara trećem broju na izlazu.
	
	Jedan on najmanjih nepodnizova niske `abcbaca` je `ccb` . On ima dužinu $3$ i odgovara poslednjem broju na izlazu.
	
	## Primer 2
	
	### Ulaz
	
	```
	26 26
	abcdefghijklmnopqrstuvwxyz
	```
	
	### Izlaz
	
	```
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2
	```
	
	## Ograničenja
	
	- $1 \leq N \leq 2\cdot 10^5$
	- $2 \leq K \leq 26$
	- $S$ se sastoji od prvih $K$ malih slova Engleske abecede.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	- U testovima vrednim 18 poena: $N\leq 5$, $K=2$;
	- U testovima vrednim 36 poena: $N \leq 1000$;
	- U testovima vrednim 10 poena: Niska $S$ je uređena leksikografski.
	- U testovima vrednim 36 poena: Bez dodatnih ograničenja.
	
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksandar Višnjić | Aleksandar Višnjić | Mladen Puzić | Dragan Urošević |
	
	## Rešenje kada $N \leq 5, K = 2$
	Za svaki prefiks, možemo probati prvo sve moguće niske dužine $1$, pa sve moguće niske dužine $2$, itd. dok ne nađemo rešenje. 
	
	Proveru za konkretnu nisku $T$ možemo uraditi tako što prolazimo sleva nadesno kroz prefiks niske $S$ i uparujemo redom karaktere čim naiđemo na njih. Ukoliko smo pronašli sve karaktere (istim redom kao u $T$), onda jeste podniz te niske, u suprotnom nije.
	
	Vremenska složenost je $O(K^N \cdot N^2)$, a memorijska $O(N)$.
	
	## Rešenje kada je niska uređena leksikografski
	Primetimo da ukoliko prefiks niske $S$ ne sadrži svih $K$ različitih karaktera, odgovor će biti $1$ (niska koja se sastoji samo od karaktera koji se tu ne nalazi). 
	
	Pošto je niska uređena leksikografski, postojaće neko $x$ tako da je prvih $x$ odgovora $1$ (jer još nisu dodati svi karakteri), a ostalih $N-x$ odgovora biće 2 - npr. niska `ba`, koja se svakako ne pojavljuje u nisci, pošto nije uređena leksikografski.
	
	Vremenska i memorijska složenost je $O(N)$.
	
	## Rešenje kada $N \leq 1000$
	Slično obzervaciji iz prethodnog podzadatka, optimalno je da prvi karakter našeg rešenja za neki prefiks, bude karakter koji se prvi put pojavljuje što kasnije - do tog karaktera svi rezultati biće $1$.
	
	Primetimo da isto razmišljanje možemo da primenimo ponovo. Tražimo karakter koji se pojavljuje što kasnije, ne računajući do sada viđene karaktere. Svi rezultati do te pozicije će sad biti $2$. 
	
	Ovo razmišljanje nastavljamo da primenjujemo dok ne odredimo sve rezultate.
	
	Vremenska složenost je $O(N^2)$, a memorijska $O(N)$.
	
	## Glavno rešenje
	Rešenje za prethodni podzadatak se može ubrzati tako što ćemo čuvati matricu dimenzija $K \times N$, gde za svaku poziciju i svaki karakter čuvamo kada će se sledeći put pojaviti. Ovo možemo jednostavno izračunati, krenuvši unazad kroz nisku $S$ i pamteći kad smo poslednji put videli svaki od karaktera.
	
	Kada popunimo ovu matricu, lako je ubrzati prethodno rešenje, bržim odabirom sledećeg karaktera.
	
	Vremenska i memorijska složenost je $O(NK)$.
	
	``` cpp title="01_neopodniz.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	bool ima[26];
	int cnt=0;
	
	int main()
	{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0),cout.tie(0);
	
	    int n,k; cin>>n>>k;
	    string s; cin>>s;
	    int duz=1;
	    for (int i=0;i<n;i++)
	    {
	        int c=s[i]-'a';
	        if (!ima[c]) ima[c]=true,cnt++;
	        if (cnt==k)
	        {
	            cnt=0;
	            for (int j=0;j<k;j++) ima[j]=false;
	            duz++;
	        }
	        cout<<duz<<" ";
	    }
	}

	```
