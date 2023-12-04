---
hide:
  - toc
---

# A1 - Vatromet

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	
	Stari kineski filozof, koji se u slobodno vreme bavi pravljenjem vatrometa, sada treba da napravi fitilj (da bi mogao da ih bezbedno upali). On ima kanap dužine $N$ metara, iz kog planira da iseče deo. Kako je pravljenje fitilja posao koji zahteva veliku preciznost, on želi da seče ovaj kanap tako da mora da meri samo dužine koje su celi brojevi u metrima – fitilj mora početi i završiti se na celobrojnom rastojanju od početka kanapa. Za svaki metar kanapa, on zna ceo broj $A_i$, koji predstavlja njegovu “pouzdanost” (metar i obuhvata deo kanapa između pozicija na rastojanjima $i$ i $(i + 1)$ metara od početka kanapa). Postoji $Q$ različitih vatrometa koje bi filozof mogao da koristi. Za svaki od njih postoje uslovi koje fitilj mora da ispuni – ne sme da bude ni previše kratak ni previše dug, a mora i da bude dovoljno pouzdan. Za vatromet $i$, ovi uslovi su definisani celim brojevima $L_i$ , $H_i$ , $T_i$ na sledeći način:
	* Dužina fitilja mora biti veća ili jednaka $L_i$ i manja ili jednaka $H_i$,
	* Srednja vrednost pouzdanosti fitilja mora biti barem $T_i$.
	
	Filozof želi da odabere jedan vatromet za koji će napraviti fitilj. Zbog toga, za svaki vatromet ga interesuje na koliko načina za njega može da napravi fitilj od kanapa koji mu je na raspolaganju. Pošto je zauzet i nema mnogo vremena, Vaš zadatak je da to odredite umesto njega.
	
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se broj $N$, koji predstavlja dužinu kanapa. U drugom redu se nalazi $N$ celih brojeva, gde je $i$-ti broj pouzdanost $i$-tog metra kanapa $A_i$. U trećem redu se nalazi $Q$ – broj vatrometa za koje se traži rešenje. U narednih $Q$ redova se nalaze po tri cela broja: u $i$-tom se nalaze $L_i$ , $H_i$ i $T_i$ , koji predstavljaju gore opisane uslove za vatromet $i$.
	
	## Opis izlaza
	Na standardni izlaz ispisati $Q$ celih brojeva, gde je $i$-ti od ispisanih brojeva broj načina da se iseče fitilj koji ispunjava uslove za vatromet $i$.
	
	## Primer 1
	### Ulaz
	```
	5
	3 2 3 1 2
	2
	1 1 2
	2 3 2
	```
	
	### Izlaz
	```
	4
	6
	```
	
	## Objašnjenja primera
	Za prvi vatromet, filozof može da iseče bilo koji metar kanapa osim četvrtog. Za drugi, potreban mu je deo koji je ili dužine 2 (dovoljno pouzdani su delovi koji počinju na rastojanju 0, 1 i 2 od početka, sa srednjom pouzdanosti redom 2.5, 2.5 i 2) ili dužine 3 (sva tri su dovoljno pouzdana).
	
	## Ograničenja
	* $1 ≤ N ≤ 200$
	* $1 ≤ Q ≤ 200000$
	* $1 ≤ A_i ≤ 10^9$
	* $1 ≤ L_i ≤ H_i ≤ N$
	* $1 ≤ T_i ≤ 10^9$
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u 3 podzadatka, u kojima važe sledeća dodatna
	ograničenja:
	
	* Podzadatak 1 [20 poena]: $Q ≤ 100$
	* Podzadatak 2 [20 poena]: $Q ≤ 10000$
	* Podzadatak 3 [60 poena]: Nema dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Boris Grubić | Dimitrije Erdeljan | Marko Ilić | Ivan Stošić |
	
	## Rešenje za $Q \le 100$
	U ovom podzadatku možemo za svaki upit proći kroz sve moguće fitilje (njih je $\frac{N\cdot(N-1)}{2}$) i za svaki proveriti da li nam odgovara. Da bismo izračunali srednju pouzdanost nekog fitilja, koristićemo prefiksne sume, kako bismo efikasno dobili zbir pouzdanosti svih metara fitilja. Vremenska složenost: $O(Q \cdot N^2)$. Memorijska složenost: $O(N)$. 
	
	## Rešenje za $Q \le 10000$
	Možemo pre nego što krenemo sa obrađivanjem upita, da za svaku moguću dužinu fitilja $X$, napravimo niz $b_X$ u kome ćemo držati srednje pouzdanosti svih fitilja dužine $X$. Te nizove treba sortirati neopadajuće. Sada, za svaki upit, možemo iterirati po dužinama od $L_i$ do $H_i$ i za svaku dužinu $X$ iz tog intervala, binarnom pretragom odrediti broj fitilja dužine $X$, takvih da im je srednja pouzdanost veća ili jednaka $T_i$. Vremenska složenost: $O(N^2logN + QNlogN)$. Memorijska složenost: $O(N^2)$. 
	
	## Glavno rešenje
	Razlika ovog i prethodnog podzadatka je u tome što ćemo u nizu $b_X$ držati srednje pouzdanosti svih fitilja koji su dužine manje ili jednake $X$. Kada obrađujemo upit, ne moramo više prolaziti kroz sve moguće dužine, već ćemo samo od broja fitilja koji imaju odgovarajuću srednju pouzdanost u nizu $b_{H_i}$ oduzeti broj fitilja sa odgovarajućom srednjom pouzdanošću iz niza $b_{L_i-1}$, jer ćemo time uračunati samo fitilje dužine od $L_i$ do $H_i$. Vremenska složenost: $O(N^3logN + QlogN)$. Memorijska složenost: $O(N^3)$. 
	
	``` cpp title="04_vatromet.cpp" linenums="1"
	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <cstdio>
	#include <ctime>
	
	using namespace std;
	
	const int N = 205;
	int a[N];
	
	struct fraction { long long up, down; } ;
	
	inline bool operator<(fraction a, fraction b)
	{
	    return a.up * b.down < b.up * a.down;
	}
	
	fraction means[N][N*N]; // means[i] = sve srednje vrednosti duzine najvise i
	int n_means[N];
	
	// broj elemenata a vecih ili jednakih x
	int num_larger(int mm, fraction x)
	{
		if(n_means[mm] == 0) return 0;
	    if(means[mm][n_means[mm] - 1] < x) return 0;
	    int left = 0, right = n_means[mm] - 1;
	    while(left < right)
	    {
	        int mid = (left + right) / 2;
	        if(means[mm][mid] < x) left = mid + 1;
	        else right = mid;
	    }
	    return n_means[mm] - right;
	}
	
	int main()
	{
	    int n, q;
		scanf("%d", &n);
	    for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
	
	    for(int i = 0; i < n; i++)
	    {
	        long long sum = 0;
	        for(int len = 1; i + len - 1 < n; len++)
	        {
	            sum += a[i + len - 1];
	            for(int j = 0; j <= len; j++)
					means[j][n_means[j]++] = {sum,len};
	        }
	    }
	
	    for(int i = 0; i <= n; i++)
	        sort(means[i], means[i] + n_means[i]);
	
		
		scanf("%d", &q);
	    for(int i = 0; i < q; i++)
	    {
	        int low, high, t;
			scanf("%d %d %d", &low, &high, &t);
	
			printf("%d\n", num_larger(low, {t, 1}) - num_larger(high + 1, {t, 1}));
	    }
	
	    return 0;
	}

	```
