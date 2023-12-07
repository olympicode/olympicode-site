---
hide:
  - toc
---

# B3 - Trookrugao

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2500ms | 512MB |
	
	
	
	Mali Programer Pera mnogo voli geometriju i kada poraste želi biti geometar. Omiljene geometrijske figure su mu trougao i krug, pa se pohvalio profesoru matematike da je smislio novi pojam: trookrugao -- trougao oko koga se može opisati krug. Dobio je odgovor da mu je mašta na nivou digitrona i da se oko svakog trougla može opisati krug. Pera se hitro ispravio -- sada je odlučio da 'trookrugao' označava krug sa tri ugla. Dobio je odgovor da batali matematiku i bavi se nečim lakšim, npr. programiranjem. Poslednjim atomima kreativnosti, Pera je smislio ultimativnu definiciju: **Trookrugao je trougao čija su sva temena u celobrojnim tačkama koordinatne ravni i čiji je centar opisanog kruga takođe u celobrojnoj tački te ravni.** 'Štagod', rekao je profesor.
	
	Dato je $N$ različitih tačaka u ravni sa celobrojnim koordinatama kao i prirodan broj $R$. **Odrediti koliko trookruglova čiji je poluprečnik opisane kružnice jednak $R$ određuju ove tačke.**
	
	
	## Opis ulaza
	
	Prvi red standardnog ulaza sadrži dva prirodna broja broja $N$ i $R$, broj tačaka i zadatu dužinu poluprečnika. U narednih $N$ redova nalaze se po dva cela broja $x_i$ i $y_i$, koji predstavljaju koordinate odgovarajuće tačke.
	
	## Opis izlaza
	
	U prvom i jedinom redu standardnog izlaza ispisati broj trookruglova poluprečnika $R$ koje određuju date tačke.
	
	## Primer 1
	
	### Ulaz
	```
	7 5
	0 0
	8 0
	0 6
	-5 0
	0 -5
	-4 3
	-8 6
	```
	
	### Izlaz
	```
	3
	```
	
	## Primer 2
	
	### Ulaz
	```
	4 1
	100000 99999
	99999 99998
	99998 99999
	99999 100000
	```
	
	### Izlaz
	```
	4
	```
	
	## Objašnjenje primera
	
	U prvom primeru svi trookruglovi poluprečnika $5$ su $\{ (0,0), (8,0), (0,6) \}$, $\{ (0,0), (0,6), (-8, 6) \}$ i $\{ (-5,0), (0,-5), (-4,3) \}$. U drugom test primeru, svake tri tačke određuju trookrugao poluprečnika $1$.
	
	## Ograničenja
	
	-   $3 \leq N \leq 50.000$
	-   $1 \leq R \leq 10^5$
	-   $-10^5 \leq x_i, y_i \leq 10^5$
	-   Ne postoje dve tačke koje se poklapaju.
	
	Test primeri su podeljeni u 5 podzadataka:
	
	-   **[16 poena]:** $N \leq 200$
	-   **[17 poena]:** $N \leq 2000$
	-   **[19 poena]:** $R = 1$
	-   **[21 poena]:** $1 \leq x_i, y_i, R \leq 300$
	-   **[27 poena]:** Nema dodatnih ograničenja
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Pavle Martinović |
	
	
	## Analiza
	
	Najjednostavnije rešenje je za svake tri tačke proveriti da li formiraju trookrugao poluprečnika $R$ - sve što nam treba su koordinate centra opisane kružnice. Ako su koordinate temena trougla $(x_1, y_1)$, $(x_2, y_2)$ i $(x_3, y_3)$ a koordinate centra $(x_c, y_c)$, tada izjednačavanjem rastojanja dobijamo:
	$(x_1-x_c)^2 + (y_1 - y_c)^2 = (x_2-x_c)^2 + (y_2 - y_c)^2$
	$(x_1-x_c)^2 + (y_1 - y_c)^2 = (x_3-x_c)^2 + (y_3 - y_c)^2$
	Nakon sređivanja se gube kvadrati uz $x_c$ i $y_c$ pa dobijamo samo dve linearne jednačine sa dve nepoznate. Ukoliko su rešenja celobrojna i poluprečnik je $R$, povećamo rešenje za $1$. Složenost algoritma je $O(N^3)$ i rešava **podzadatak 1**.
	
	Skup $C$ svih mogućih centara opisanih kružnica traženih trookruglova možemo dobiti tako što za svake dve tačke $A$ i $B$ odredimo (najviše) 2 druge tačke koje su i od $A$ i od $B$ udaljene tačno $R$ i, ukoliko su celobrojne, ubacimo ih u pomenuti skup. Račun za koordinte te dve tačke je analogan kao u rešenju podzadatka 1 (koristmo i $R$ ovog puta) a mogu se odrediti i binarnom pretragom po simetrali duži $AB$. Ukoliko se u skupu $C$ neka tačka $T$ javlja $a$ puta, to znači da je na kružnici poluprečnika $R$ opisanoj oko $T$ tačno $b$ tačaka, gde je $a = \frac{b(b-1)}{2}$ jer smo svaki par brojali tačno jednom. Svake 3 od tih $b$ tačaka formiraju traženi trookrugao pa rešenju treba dodati $\binom{b}{3}$ za svaku tačku $T$ iz $C$. Brojanje pojavljivanja svake tačke je najlakše uraditi sortiranjem skupa $S$; kako on sadrži $O(N^2)$ mogućih centara, složenost algoritma je $O(N^2 \log N)$ i rešava **podzadatke 1 i 2**.
	
	Ako je $R = 1$, zadatak se svodi na "koliko jednakokrako-pravouglih trouglova sa hipotenuzom dužine $2$ ima među datim tačkama?". Ovo se može rešiti proverom za svaku od $N$ tačaka da li je teme pravog ugla takvog trougla - npr. ako proveravamo da li postoji takav trougao čije je teme pravog ugla "nadole" i u tački $(x, y)$, treba ispitati da li se tačke $(x-1, y+1)$ i $(x+1, y+1)$ nalaze među datih $N$ tačaka. Ukoliko na početku soritramo tačke, ovo ispitivanje možemo odraditi u $O(\log N)$ preko binarne pretrage (može i preko nekih drugih struktura, npr. C++ mapa). Složenost ovog pristupa je $O(N \log N)$ i rešava **podzadatak 3**.
	
	Označimo sa $minVal$ i $maxVal$ najmanje i najveće koordinate datih tačaka. Centar opisane kružnice traženog trookrugla može biti samo u delu koordinatne ravni ograničen sa $[minVal - R, maxVal + R] \times [minVal - R, maxVal + R]$. Za svaku tačku iz ove oblasti možemo izračunati koliko se datih tačaka nalazi na rastojanju $R$ od nje (ako ih ima $a$, tada ima $\binom{a}{3}$ trookruglova čiji je centar opisanog kruga ova tačka) ispitivanjem svih $O(R)$ kandidata (provera u složenosti $O(1)$ jer su koordinate male i možemo markirati tačke u matrici). Ukupna složenost ovog algoritma je $O((maxVal - minVal + 2R)^2 \cdot R)$ i rešava **podzadatak 4**. 
	
	Označimo sa $f(R)$ broj celobrojnih tačaka koje se nalaze na kružnici poluprečnika $R$ čiji je centar u nekoj celobrojnoj tački. Npr. $f(1) = f(2) = f(3) = f(4) = 4$, $f(5) = 12$, itd. (primetimo da nije bitno u kojoj celobrojnoj tački je centar). $f(R)$ je zapravo broj celobrojnih rešenja jednačine $x^2 + y^2 =R^2$ i sva ta rešenja možemo pronaći u složenosti $O(R)$ npr. isprobavanjem svih mogućnosti za $x$. Ovo izračunamo na početku i označimo skup tih rešenja sa $\{(x_i,y_i), (x_2, y_2), \ldots, (x_{f(R)}, y_{f(R)}\}$. 
	Ukoliko oko svake od $N$ tačaka opišemo kružnicu poluprečnika $R$ i sve celobrojne tačke sa te kružnice (za tačku $(x,y)$ tih $f(R)$ celobrojnih tačaka su $(x+x_i, y+y_i)$, $i = \overline{1, f(R)}$) smestimo u jedan skup (niz) $C$ (veličine $N \cdot f(R)$), tada je $C$  skup svih potencijalnih centara traženih trookruglova jer svaki takav centar mora biti na rastojanju $R$ od bar jedne od $N$ tačaka. Ukoliko se $C$ sastoji od $M$ različitih tačaka od kojih se $i$-ta pojavljuje $a_i$ puta, ukupno rešenje je $\binom{a_1}{3} + \binom{a_2}{3} + \ldots + \binom{a_M}{3}$. Broj ponavljanja svake tačke možemo izračunati sortiranjem niza $C$ i brojanjem uzastopnih istih elemenata. Zavisno od toga da li koristimo QuickSort ili CountingSort (prvo po $x$ pa po $y$), složenost algoritma je $O(N\cdot f(R) \cdot \log(N\cdot f(R)))$ ili $O(N \cdot f(R))$.
	
	Ključna stvar koju treba uočiti je da su vrednosti $f(R)$ "dovoljno male" za data ograničenja - ispostavlja se da je za  $f(R) \leq 324$ za svako $1\leq R\leq 10^5$. Ovo je intuitivno (obično nema baš puno celobrojnih tačaka na opisanim kružnicama) a moglo se i lako proveriti za vreme takmičenja: ukoliko takmičar (na lokalnoj mašini) izračuna $f(R)$ za svako $R$ do $10^5$ u ukupnoj složenosti $O(R^2)$, dobiće traženi rezultat za 2-3 minuta. Dakle, poslednji opisani algoritam zaista **rešava ceo zadatak** u zadatom vremenskom ograničenju.
	
	``` cpp title="03_trookrugao.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	
	const int MAX_N = 50000;
	const int MAX_COORD = 100000;
	const int MAX_CIRC_POINTS = 324;
	
	struct point
	{
		int x, y;
	
		point() {}
		point(int x_, int y_)
		{
			x = x_; y = y_;
		}
	};
	
	int n, R;
	int X[MAX_N + 10], Y[MAX_N + 10];
	int N;
	point centers[MAX_N * MAX_CIRC_POINTS + 10];
	point tmp[MAX_N * MAX_CIRC_POINTS + 10];
	int c[4 * MAX_COORD + 10];
	int RN;
	point circlePoints[MAX_CIRC_POINTS + 10];
	
	void findPointsOnCircle(int R)
	{
		RN = 0;
		circlePoints[RN++] = point(0, R);
		circlePoints[RN++] = point(0, -R);
		circlePoints[RN++] = point(R, 0);
		circlePoints[RN++] = point(-R, 0);
	
		long long rsqr = (long long)R * (long long)R;
		long long b = R - 1;
		for (long long a = 1; a < R; a++)
		{
			while (a*a + b*b > rsqr)
				b--;
			if (a*a + b*b == rsqr)
			{
				circlePoints[RN++] = point((int)a, (int)b);
				circlePoints[RN++] = point((int)a, (int)-b);
				circlePoints[RN++] = point((int)-a, (int)b);
				circlePoints[RN++] = point((int)-a, (int)-b);
			}
		}
	}
	
	
	void countSort(int N, point points[], bool sortByX)
	{
		int K = 4 * MAX_COORD;
	
		for (int i = 0; i <= K; i++)
			c[i] = 0;
		for (int i = 0; i < N; i++)
			c[sortByX ? points[i].x : points[i].y]++;
		for (int i = 1; i <= K; i++)
			c[i] = c[i - 1] + c[i];
	
		for (int i = N - 1; i >= 0; i--)
		{
			tmp[c[sortByX ? points[i].x : points[i].y] - 1] = points[i];
			c[sortByX ? points[i].x : points[i].y]--;
		}
	
		for (int i = 0; i < N; i++)
			points[i] = tmp[i];
	}
	
	int main()
	{
		scanf("%d%d", &n, &R);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &X[i], &Y[i]);
		}
	
		findPointsOnCircle(R);
	
		N = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < RN; j++)
			{
				centers[N++] = point(2 * MAX_COORD + X[i] + circlePoints[j].x, 2 * MAX_COORD + Y[i] + circlePoints[j].y);
			}
		}
	
		countSort(N, centers, false);
		countSort(N, centers, true);
	
		long long sol = 0;
		int k = 1;
		for (int i = 0; i < N; i++)
		{
			if (i < N - 1 && (centers[i].x == centers[i + 1].x && centers[i].y == centers[i + 1].y))
			{
				k++;
			}
			else
			{
				sol = sol + k * (k - 1) * (k - 2) / 6;
				k = 1;
			}
		}
	
		printf("%lld\n", sol);
	
		return 0;
	}
	

	```
