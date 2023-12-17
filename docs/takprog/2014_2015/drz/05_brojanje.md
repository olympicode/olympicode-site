---
hide:
  - toc
---

# A2 - Brojanje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 128MB |
	
	Mali haker Drejko redovno pokušava da izbegne izradu domaćih zadataka. Kako ih nije radio kada je bilo vreme, a približava se kontrolna vežba, shvatio je da mu se nakupilo $N$ zadataka koje nije uradio. Međutim, umesto da se istog trenutka baci na posao, uočio je mnogo zanimljivu temu za razmišljanje nakon što je svakom zadatku dodelio, po svojoj proceni, neki prirodan broj koji predstavlja koliko je dosadan (zadaci kojima su dodeljeni veći brojevi su dosadniji).
	
	Drejkova odluka je da reši neki **podniz uzastopnih** zadataka iz zbirke. Međutim, taj podniz zadataka će odabrati tako da je najdosadnijem odabranom zadatku pridružen neki dati broj $k$. Postoji potencijalno mnogo ovakvih izbora zadataka, a svakog iole pristojnog hakera zanima **koliko takvih izbora postoji**. Pošto je ovo muka i većeg dela Tajne Komisije u Senci, koja broji $Q$  članova (pri čemu su svi saglasni sa Drejkovom metrikom dosade), pomenuta Komisija će vas bogato nagraditi ukoliko joj rešite problem.
	
	## Opis ulaza
	U prvom redu standardnog ulaza se zadaje prirodan broj $N$. U narednom redu se zadaje $N$ prirodnih brojeva koji predstavljaju koliko je odgovarajući zadatak u zbirci dosadan. U trećem redu se zadaje prirodan broj $Q$, nakon čega se u narednih $Q$ redova nalazi po jedan prirodan broj $k$, koji predstavlja upit "koliko postoji podnizova uzastopnih zadataka iz zbirke takvih da je vrednost najdosadnijeg zadatka $k$?".
	
	## Opis izlaza
	U $Q$ redova standardnog izlaza ispisati odgovore na upite iz ulaza onim redom kojim su bili zadati. Pošto su izlazni brojevi potencijalno veliki, ispisati odgovore **po modulu** $10^9+7$.
	
	## Primer 1
	### Ulaz
	```
	5
	1 2 3 4 3
	3
	2
	3
	4
	```
	
	### Izlaz
	```
	2
	4
	8
	```
	
	## Objašnjenje primera
	Jedini podnizovi uzastopnih zadataka čiji je maksimum dosade jednak 2 su [2] i [1,2].
	
	Podnizovi čiji je maksimum dosade jednak 3 su [1,2,3], [2,3], [3] i [3].
	
	Podnizovi čiji je maksimum dosade jednak 4 su [1,2,3,4], [1,2,3,4,3], [2,3,4], [2,3,4,3], [3,4], [3,4,3], [4], [4,3].
	
	## Ograničenja
	* $1\leq N\leq 10^6$
	* $1\leq Q\leq 10^6$
	* "Dosadnosti" zadataka su prirodni brojevi koji nisu veći od $10^9$.
	* Za sve $k$ iz ulaza važi $1\leq k\leq 10^9$.
	
	Test primeri su podeljeni u disjunktne grupe.
	
	* U test primerima vrednim 10 poena važe ograničenja: $N\leq 10$, $Q\leq 10$, "dosadnosti" zadataka nisu veće od $10$.
	* U test primerima dalje vrednim 10 poena je zadovoljeno $N\leq 1000$ i nijednom zadatku neće biti pridružena "dosadnost" veća od $1000$.
	* U test primerima dalje vrednim 30 poena je zadovoljeno $N\leq 100$.
	* U preostalim test primerima nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Baković | Andrej Ivašković | Miloš Purić | Marko Baković |
	
	Podniz niza $A$ od indeksa $i$ do indeksa $j$ označavamo sa $[i,j]$, gde je $1 \leq i,j \leq N$.
	
	## Rešenje za $1 \leq N,Q,A_i \leq 10$:
	Dovoljno je za svaki upit isprobati svaki mogući podniz uzastopnih brojeva.
	
	## Rešenje za $1 \leq N,A_i \leq 1000$ :
	Možemo za svaki podniz $[i,j]$ naći najveći broj u njemu $M$ i povećati broj podnizova sa maksimalnim elementom $M$ za jedan. Tada na upite odgovaramo u konstantnom vremenu. Vremenska složenost: $O(N^2+Q)$, memorijska složenost: $O(N)$.
	
	## Rešenje za $1 \leq N \leq 100$ :
	Možemo koristiti isto rešenje kao u prethodnom podzadatku uz izmenu da umesto niza za brojanje podnizova sa maksimalnim elementom $M$ koristimo *C++ map*-u. Vremenska složenost: $O(N^2 \cdot \log(10^{9})+Q \cdot \log(10^{9}))$, memorijska složenost: $O(N)$.
	 
	## Glavno rešenje:
	Ukoliko želimo da baš element $A_i$ bude najveći broj u nekom podnizu, možemo to zamisliti kao da počinjemo od jednočlanog podniza $[i,i]$ koji pokušavamo da što je više moguće proširimo ulevo i udesno uz uslov da njegov najveći element ostane $A_i$. Moguće je da pri tome stignemo do levog ili desnog kraja niza. Drugim rečima, možemo pronaći indekse $l$ i $r$ takve da je $1 \leq l \leq i \leq r \leq N$ i da za svaki indeks $j$ od $l$ do $r$ važi $A_j \leq A_i$, i na kraju, da važi ili da je $l=1$ ili $A_{l-1} > A_i$ kao i da važi ili $r=N$ ili $A_{r+1} > A_i$. Neka $L_i$ i $R_i$ označavaju upravo ove jedinstvene vrednosti $l$ i $r$ za fiskiran indeks $i$.
	
	Vrednosti $L_i$ i $R_i$ možemo izračunati pomoću strukture podataka poput *C++ stack*-a. Sledeći pseudokod predstavlja algoritam za pronalaženje $R_i$ (za $L_i$ je  postupak sličan):
	
	```
	S #prazan stek
	for i = 1 . . . n:
	while(!S.empty && a[i] > a[S.top]) #dodeljujemo vrednosti R[i] manjim elementima u steku
	R[S.top] = i-1
	S.pop
	S.push(i)
	
	while(!S.empty)
	R[S.top] = N
	S.pop
	```
	
	Ove vrednosti nam govore dokle je dozvoljeno produžiti podniz u obe strane tako da najveća vrednost i dalje ostane $A_i$. Zato je broj podnizova u kojima je najveći element baš $A_i$ jednak 
	
	$$
	C_i=(i-L_i+1) \cdot (R_i-i+1)
	$$
	
	jer je bilo koja kombinacija dozvoljenih produženja jednočlanog podniza $[i,i]$ ulevo i udesno validna - ulevo smemo produžiti za najviše $i-L_i$ pozicija a udesno za najviše $R_i-i$ pozicija.
	
	Kada bi svi elementi niza bili različiti, rešenje bi prosto bilo $\sum_{i=1}^{N} C_i$. Međutim, kada postoje jednaki elementi, može se desiti da smo u vrednostima $C_i$ za različite indekse brojali iste podnizove više puta. Na primer, ako se vrednost $v$ pojavljuje tačno dva puta, tj. $A_p = A_q=v$ za $p < q$,  i ako je $L_q \leq p$ tada se neki podnizovi koje smo brojali u $C_q$, a koji sadrže $A_p$, pojavljuju i u $C_p$. Štaviše, kako je $L_q \leq p$, onda mora važiti i $R_q \geq q$, pa smo,  u stvari, sve podnizove koje smo brojali u $C_q$, a koji sadrže $A_p$, brojali i u $C_p$ (čak važi i potpuna jednakost ovih parametara, tj. $L_p=L_q$ i $R_p=R_q$, ali to je manje važno). Ovo zapažanje olakšava stvari jer sada broj podnizova u kojima je $v$ najveća vrednost, bez višestrukog brojanja istih podnizova, možemo dobiti kao $C_p+C_q^{\prime}$, gde je $C_q^{\prime}$ ista vrednost $C_q$, ali izračunata koristeći $L_q^{\prime}=p+1$ umesto stare vrednosti $L_q$, tj. $C_q^{\prime}=(q-(p+1)+1) \cdot (R_q-q+1)$.
	
	Čak i ako se dogodi da postoje više od dva pojavljivanja vrednosti $v$ u nizu, na pozicijama $p_1,p_2, \dots  ,p_k$ ($1 \leq p_1 < p_2 < \dots < p_k \leq N$), broj podnizova u kojima je $v$ najveća vrednost, bez višestrukog brojanja istih podnizova, će biti
	
	$$
	T_v=C_{p_1}+\sum_{j=2}^{k} C_{p_j}^{\prime}
	$$
	
	gde je $C_{p_j}^{\prime}$ vrednost $C_{p_j}$ izračunata koristeći $L_{p_j}^{\prime}=p_{j-1}+1$ umesto stare vrednosti $L_{p_j}$ u slučaju da važi $L_{p_j} \leq p_{j-1}$, ili samo $C_{p_j}$ inače. Znači:
	
	$$
	C_{p_j}^{\prime}=\left\{
	\begin{array}{l}
	      (p_j-(p_{j-1}+1)+1) \cdot (R_{p_j}-p_j+1), \text{ ako }  L_{p_j} \leq p_{j-1}\\
	      C_{p_j}, \text{ inače}
	\end{array}
	\right.
	$$
	
	Dakle, ako leva granica za proširivanje podniza $[i,i]$ trenutnog elementa $A_i$ obuhvata prethodni element iste vrednosti $A_j$ $(j < i)$, dovoljno je na ovaj način promeniti $L_i$ da bismo izbegli višestruko brojanje. Sada možemo izračunati $T_v$ za svaku vrednost $v$ koja se pojavljuje u nizu, čuvati je u *C++ map*-i i tako dati odgovor na svaki od $Q$ upita u $O(\log (10^{9}))$. 
	
	Vremenska složenost: $O((N+Q) \cdot \log(10^9))$, memorijska složenost: $O(N)$.
	
	``` cpp title="05_brojanje.cpp" linenums="1"
	/*
	    ZADATAK: brojanje, A2 drzavno 2015.
	    AUTOR ZADATKA: Marko Bakovic
	    AUTOR RESENJA: Andrej Ivaskovic
	
	    Za ovo resenje je predvidjeno 100 poena. Zasniva se na
	    "postepenom" izbacivanju elemenata iz niza, i to u rastucem
	    (odnosno neopadajucem) redosledu. Pri izbacivanju nastaju
	    "supljine" u kojima mogu da budu granice podnizova. Uz
	    pazljivo belezenje podataka o ovim supljinama je moguce u
	    O(1) slozenosti dobiti broj podnizova ciji je maksimum neki
	    element na nekoj poziciji.
	    (U slucaju jednakosti elemenata ipak uvodimo neki proizvoljan
	    poredak medju njima.)
	
	    Slozenost ovog resenja je O((Q + N) log N), pri cemu log N
	    faktor potice od sortiranja i od binarne pretrage.
	*/
	
	#include <cstdio>
	#include <algorithm>
	
	using namespace std;
	
	const int maxN = 1000000;
	const long long MOD = 1000000007;
	
	struct parVredIdx
	{
	    int v;
	    long long idx;
	    long long r;
	} p[maxN];
	
	struct parVredRez
	{
	    int v;
	    long long r;
	} q[maxN];
	
	bool operator <(parVredIdx x, parVredIdx y)
	{
	    return x.v < y.v || (x.v == y.v && x.idx < y.idx);
	}
	
	int N, Q;
	int A[maxN];
	int k;
	bool suplje[maxN];
	int levo[maxN], desno[maxN];
	int brojVrednosti;
	int poz;
	
	int binPret(int vred)
	{
	    int l = 0, d = brojVrednosti - 1, s;
	    while (l < d)
	    {
	        s = (l + d) / 2;
	        if (vred == q[s].v)
	            l = d = s;
	        else if (vred < q[s].v)
	            d = s - 1;
	        else
	            l = s + 1;
	    }
	    if (q[l].v == vred)
	        return l;
	    return -1;
	}
	
	int main()
	{
	    scanf("%d", &N);
	    for (int i = 0; i < N; i++)
	    {
	        scanf("%d", &A[i]);
	        p[i].v = A[i];
	        p[i].idx = i;
	        p[i].r = 0L;
	        suplje[i] = false;
	        levo[i] = desno[i] = -1;
	    }
	    sort(p, p + N);
	    for (int i = 0; i < N; i++)
	    {
	        suplje[p[i].idx] = true;
	        levo[p[i].idx] = desno[p[i].idx] = p[i].idx;
	        if (p[i].idx - 1 >= 0 && suplje[p[i].idx - 1])
	            levo[p[i].idx] = levo[p[i].idx - 1];
	        if (p[i].idx + 1 < N && suplje[p[i].idx + 1])
	            desno[p[i].idx] = desno[p[i].idx + 1];
	        p[i].r = (p[i].idx - levo[p[i].idx] + 1) * (desno[p[i].idx] - p[i].idx + 1) % MOD;
	        levo[desno[p[i].idx]] = levo[p[i].idx];
	        desno[levo[p[i].idx]] = desno[p[i].idx];
	    }
	    brojVrednosti = 1;
	    q[0].v = p[0].v;
	    q[0].r = p[0].r;
	    for (int i = 1; i < N; i++)
	    {
	        if (p[i].v == p[i - 1].v)
	        {
	            q[brojVrednosti - 1].r += p[i].r;
	            q[brojVrednosti - 1].r %= MOD;
	        }
	        else
	        {
	            q[brojVrednosti].v = p[i].v;
	            q[brojVrednosti].r = p[i].r;
	            brojVrednosti++;
	        }
	    }
	    scanf("%d", &Q);
	    for (int i = 0; i < Q; i++)
	    {
	        scanf("%d", &k);
	        poz = binPret(k);
	        if (poz == -1)
	            printf("0\n");
	        else
	            printf("%lld\n", q[poz].r);
	    }
	    return 0;
	}

	```
