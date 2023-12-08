---
hide:
  - toc
---

# B1 - Bakterijada

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Osim Državnog takmičenja iz informatike, Kragujevac je domaćin i ovogodišnje Bakterijade. Naučnica Maša je odlučila da ove godine pobedi na Bakterijadi i osvoji ogromnu količinu vrednih nagrada. Bakterijada je takmičenje gde svaki takmičar donosi $N$ bakterija i meri im težine na specifičan način:
	
	- Naučnik prvo izmeri težinu svih bakterija odjednom i zapiše rezultat na tablu
	- Zatim, od izmerenih bakterija pravi dve neprazne disjunktne grupe bakterija na merenje
	- Za novodobijene grupe ponavlja proces
	- Ukoliko izmerena grupa bakterija se sastoji od samo jedne bakterije, ona se ne deli, već se vraća u laboratoriju i završava takmičenje 
	- Suma svih brojeva napisanih na tabli predstavlja rezultat na takmičenju koji je naučnik ostvario
	
	Mašu interesuje kako da izvrši podele bakterija u grupe posle svakog merenja tako da joj rezultat bude što veći. Kako je ona prezauzeta silnim obavezama, zamolila je vas da joj pomognete, a za uzvrat će vam dati poene na Državnom takmičenju iz informatike preko veze.
	
	## Opis ulaza
	U prvoj liniji ulaza nalazi se prirodan broj $T$ - broj test primera.
	
	Svaki test primer je u sledećem formatu:
	
	* U prvoj liniji test primera nalazi se prirodan broj $N$ - broj bakterija koje Maša dovodi na takmičenje;
	* U drugoj liniji test primera se nalazi niz od $N$ prirodnih brojeva $A_1, A_2, \ldots, A_N$ - gde broj $A_i$ predstavlja težinu $i$-te bakterije u nanonjutnima, za $1 \leq i \leq n$.
	
	## Opis izlaza
	U $T$ linija izlaza ispisati po jedan prirodan broj koji predstavlja najveći rezultat koji Maša može da ostvari na Bakterijadi u tom test primeru.
	
	## Primer 1
	### Ulaz
	```
	1
	3
	20 20 20
	```
	
	### Izlaz
	```
	160
	```
	
	## Primer 2
	### Ulaz
	```
	1
	3
	12 7 18
	```
	
	### Izlaz
	```
	104
	```
	
	## Objašnjenje primera
	U prvom primeru, Maša prvo izmeri ukupnu težinu $20+20+20=60$, i zatim podeli na dve grupe. Prva grupa sadrži bakterije težina $20$ i $20$, a druga grupa sadrži bakteriju težine $20$. Zatim, Maša izmeri prvu grupu i zapiše rezultat $20+20=40$ i podeli je na dve grupe (treću i četvrtu grupu) od po jednu bakteriju težine $20$. Nakon merenja druge grupe, Maša zapisuej na tablu $20$ i ta bakterija odlazi sa takmičenja. Isto se desi i za treću i četvrtu grupu. Na tabli se sada nalaze brojevi $60$, $40$, $20$, $20$, $20$ i njihov zbir je $160$.
	
	## Ograničenja
	
	- $1 \leq T \leq 10$.
	- $1 \leq N \leq 10^5$.
	- $1 \leq A_i \leq 10^9$.
	
	Test primeri su podeljeni u četiri disjunktnih grupa:
	
	- U test primerima vrednim $10$ poena, $T = 1$ i $1 \leq N \leq 20$.
	- U test primerima vrednim $20$ poena, $1 \leq N \leq 1000$.
	- U test primerima vrednim $20$ poena, sve bakterije imaju istu težinu.
	- U test primerima vrednim $50$ poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Milenković | Marko Milenković | Marko Milenković | Dragan Urošević |
	
	## Rešenje kada $T = 1$ i $N \leq 20$
	U ovom podzadatku je dovoljno u svakom potezu generisati sve moguće podele bakterija, njih $2^N$. Svaka bakterija može da učestvuje u najviše $N$ merenja. Vremenska složenost je $O(N2^N)$.
	
	## Rešenje kada sve bakterije imaju istu težinu
	Možemo uočiti da je optimalno odvajati po jednu bakteriju u jednu grupu i preostale u drugu. Na ovaj način maksimizujemo ukupnu sumu (dokaz ostavljamo čitaocu za vežbu - pomoć: kada quick sort radi najsporije?). Suma će iznositi $X(N + N + N - 1 + N - 2 + \ldots + 3 + 2) = X\left(\frac{N(N+1)}{2} + N - 1\right)$, gde je $X$ težina bakterija. Vremenska složenost je $O(1)$.
	
	## Rešenje kada $1 \leq N \leq 1000$
	Slično, kao u prethodnom podzadatku, odvajaćemo po jednu bakteriju i to baš onu sa najmanjom težinom (dokaz sličan kao u prethodnom podzadatku). Posle svakog merenja nalazićemo najlakšu bakteriju i shodno tome računati sumu, a deljenja će biti tačno $N$. Vremenska složenost je $O(N^2)$.
	
	## Rešenje bez dodatnih ograničenja
	Umesto simulacije biranja u prethodnom podzadatku, lakše je izanalizirati da će se najlakša bakterija brojati dva puta, druga najlakša tri puta, ..., druga najteža $N$ puta i najteža $N$ puta. Vremenska složenost je $O(N)$.
	
	``` cpp title="01_bakterijada.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	typedef long long ll;
	
	int main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(nullptr); 
		cout.tie(nullptr); 
		cerr.tie(nullptr);	
	
		int t;
		cin >> t;
	
		for (int e = 0; e < t; ++e){
	
			int n;
			cin >> n;
	
			vector<ll> a(n);
			for (auto& i : a)
				cin >> i;
	
			sort(a.begin(), a.end());
	
			ll sol = 0;
			for (int i = 0; i < n; ++i)
				sol += (i + 2) * 1ll * a[i];
	
			sol -= a[n-1];
	
			cout << sol << '\n';
		}
	}

	```
