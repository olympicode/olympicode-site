---
hide:
  - toc
---

# B1 - Apsolutno broj

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 200ms | 64MB |
	
	Nakon celodnevnog rada na zadacima i test primerima, članovi Tajne komisije iz senke ostaju da podele poslove za sutra tradicionalnim algoritmom.
	
	Najpre zapišu dva niza $A$ i $B$, svaki sa $N$ celih brojeva. Nakon toga, $N$ puta računaju sledeću sumu $\sum_{i=1}^N |A_i-B_i|$ i nakon svakog računanja rotiraju niz A za jedno mesto u desno. Sve rezultate na kraju saberu i ovo rešenje nazovu „suma svih suma“.
	
	Članovi komisije koriste „sumu svih suma“ da određenim algoritmom podele poslove. Kako računanje ove sume oduzima mnogo vremena, komisija je odlučila da napiše program. Ali da bi podela poslova bila fer, zamolili su Vas da im pomognete i napišete program koji će izračunati „sumu svih suma“.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se ceo broj $N$. U sledeća dva reda nalazi se po $N$ celih brojeva razdvojenih razmakom, nizovi $A$ i $B$ redom.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza nalazi se jedan ceo broj, tražena „suma svih suma“.
	
	## Primer 1
	### Ulaz
	```
	3
	4 2 8
	2 7 3
	```
	
	### Izlaz
	```
	24
	```
	
	## Objašnjenje primera
	Za početni niz 4 2 8 suma razlika je 2 + 5 + 5 = 12. Nakon rotiranja niz A je 8 4 2, a suma razlika 6 + 3 + 1 = 10. Nakon još jednog rotiranja, niz A je 2 8 4, a suma razlika 0 + 1 + 1 = 2. Posle računanja treće sume, rotiramo niz $A$ ali ne računamo nikakvu sumu. Tražena „suma svih suma“ je 12 + 10 + 2 = 24.
	
	## Ograničenja
	
	* U 30% test primera važi $1\leq N\leq 10^3$  i $|A_i|,|B_i| \leq 10^3$
	* U narednih 20% test primera važi $1\leq N\leq 10^5$  i $A_i,B_i \in \{0,1\}$
	* U preostalim test primerima važi $1\leq N\leq 10^5$ i $|A_i|, |B_i| \leq 10^6$
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Dimić | Marko Baković | Uroš Vukićević | Petar Veličković |
	
	## Rešenje za $1 \leq N \leq 10^3$ i $|A_i|, |B_i| \leq 10^3$:
	Ograničenje za $N$ je dovoljno malo da simuliramo proces iz teksta zadatka, postojaće $N$ rotacija, a za svaku rotaciju imamo $N$ računanja, pa je krajnja vremenska složenost $O(N^2)$. Memorijska složenost: $O(N)$. 
	
	## Rešenje za $A_i, B_i \in \{0, 1\}$:
	Sa obzirom da će svaki element u nekom trenutku biti na svakoj od pozicija u nizu ukupna suma će zapravo biti $\sum_{i=1}^{n}\sum_{j=1}^{n}|A_i-B_j|$, odnosno, traži nam se zbir apsolutnih razlika svakog elementa niza $A$ sa svakim elementom niza $B$. Iz ove sume se vidi da svaki element možemo da gledamo zasebno.  
	Svaka jedinica iz niza $A$ daje apsolutnu razliku $1$ sa svim nulama iz niza $B$, dok svaka nula iz niza $A$ daje apsolutno razliku $1$ sa svim jedinicama iz niza $B$. Sve ostale apsolutne razlike iznose $0$. Samim tim, krajnji rezultat je $cntA_0\cdot cntB_1 + cntA_1\cdot cntB_0$, gde je npr. $cntA_0$ broj nula u nizu $A$. Vremenska složenost: $O(N)$, memorijska složenost: $O(1)$. 
	
	## Glavno rešenje:
	Primenimo istu sumu iz prethodnog rešenja, samo je sada komplikovanije da je izračunamo. Nakon što sortiramo niz $B$, za svaki element $A_i$ mogli bismo da razdvojimo niz $B$ uspravnom linijom, gde bi nam sa desne strane te linije svi elementi bili veći od $A_i$ (ako ih ima), dok bi nam sa leve strane bili svi elementi manji ili jednaki od $A_i$ (ako ih ima). To bi značilo da bi sve apsolutne razlike sa leve strane bile $A_i-B_j$, dok bi sa desne strane bile $B_j-A_i$. Liniju možemo pronaći pomoću binarne pretrage, a sumu sa leve i desne strane linije uz pomoć prefiksnih suma. Nakon toga, za dato $A_i$, rezultat je $(brojLevo\cdot A_i - sumaLevo) + (sumaDesno - brojDesno\cdot A_i)$. Vremenska složenost: $O(NlogN)$, memorijska složenost: $O(N)$.
	
	
	``` cpp title="01_apsolutno_broj.cpp" linenums="1"
	/*
	    Drzavno takmicenje iz programiranja
	    21. mart 2015. godine
	
	    B1 Apsolutno broj
	    Trazeno resenje, 100 poena
	*/
	
	#include <cstdio>
	#include <algorithm>
	
	using namespace std;
	
	const int maxn = 1e5 + 5;
	
	int n, a[maxn], b[maxn];
	
	int main()
	{
	    scanf("%d", &n);
	    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	
	    sort(a, a + n);
	    sort(b, b + n);
	
	    long long sol = 0, left_sum = 0, right_sum = 0, first_in_right = 0;
	    for (int i = 0; i < n; i++) right_sum += b[i];
	    for (int i = 0; i < n; i++)
	    {
	        while (first_in_right < n && b[first_in_right] < a[i])
	        {
	            left_sum += b[first_in_right];
	            right_sum -= b[first_in_right];
	            first_in_right++;
	        }
	        sol += first_in_right * a[i] - left_sum +
	               right_sum - (n - first_in_right) * a[i];
	    }
	
	    printf("%lld\n", sol);
	
	    return 0;
	}

	```
