---
hide:
  - toc
---

# B3 - Starući prsten

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Igrate najnoviji nastavak popularne igrice "Starući prsten". Poznato je da u ovoj igrici postoji $Q$ šefova, od kojih $i$-ti ima $H_i$ zdravstvenih poena. Da bi završili igricu, morate da pobedite svakog od njih.
	
	Borba sa svakim šefom traje najviše $N$ poteza. Sa svakim šefom se borba odigrava kroz istih $N$ poteza. Tokom $k$-tog od njih, na raspolaganju su Vam dve opcije:
	
	 * Primeniti direktan napad na šefa i time mu smanjiti broj zdravstvenih poena za $D_k$.
	 * Primeniti napad sa otrovom. Primenom ovog napada se šefu nakon svakog narednog poteza (uključujući i trenutni) broj zdravstvenih poena smanjuje za $P_k$. **Primetite da se napadi sa otrovom akumuliraju**, tj. nakon kraja svakog poteza, šefu se broj zdravstvenih poena smanjuje za ukupnu sumu primenjenih napada sa otrovom zaključno sa tim potezom.
	
	Ukoliko nakon završetka nekog poteza šef ima najviše $0$ zdravstvenih poena, on je pobeđen i borba sa njim se završava.
	
	Pošto ste veteran ove igrice, trenutno Vas jedino zanima da je što brže završite. Za svakog šefa ispisati koliko je najmanje poteza potrebno da bi ga pobedili. "Starući prsten" je poznat kao igrica sa teškim šefovima, te neke od njih nije fizički ni moguće pobediti. Ukoliko nije moguće pobediti šefa nakon najviše $N$ poteza, ispisati $-1$.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalaze se celi brojevi $N$ i $Q$, koji redom predstavljaju broj poteza i broj šefova. U svakoj od narednih $N$ linija, nalaze se po dva cela broja. U $k$-toj liniji, nalaze se brojevi $D_k$ i $P_k$. U narednih $Q$ linija, nalazi se po jedan ceo broj, $H_i$, broj zdravstvenih poena $i$-tog šefa.
	
	## Opis izlaza
	Za svakog od $Q$ šefova ispisati po jedan ceo broj - broj poteza potrebnih da se dati šef pobedi. Ukoliko šefa nije moguće pobediti nakon najviše $N$ poteza, ispisati $-1$.
	
	## Ograničenja
	
	*   $1 \leq N, Q \leq 200.000$
	*   $0 \leq D_k, P_k \leq 100.000.000$
	*   $1 \leq H_i \leq 1.000.000.000$
	
	
	## Podzadaci
	
	*   (11 poena): $P_k = 0$
	*   (13 poena): $D_k = 0$
	*   (29 poena): $Q \leq 10$
	*   (14 poena): $2 \cdot P_k > D_k$
	*   (33 poena): Bez dodatnih ograničenja
	
	## Primer
	
	### Ulaz
	
	```
	4 5
	1 2
	2 1
	1 0
	1 0
	2
	3
	14
	13
	6
	```
	
	### Izlaz
	
	```
	1
	2
	-1
	4
	2
	```
	### Objašnjenje
	
	* Prvi šef ima $2$ zdravstvena poena. Na njega primenimo napad sa otrovom u prvom potezu. Nakon prvog poteza, taj mu napad smanjuje broj zdravstvenih poena na $0$, čime je šef pobeđen nakon jednog poteza.
	* Drugi šef ima $3$ zdravstvena poena. Na njega u prvom potezu primenimo napad sa otrovom. Nakon prvog poteza, taj mu napad smanjuje broj zdravstvenih poena za $2$, čime mu preostaje $1$ zdravstveni poen. U drugom potezu na šefa možemo ponovo da primenimo napad sa otrovom. Nakon kraja poteza akumulirani napadi sa otrovom mu smanjuju broj zdravstvenih poena za $2+1=3$, čime mu preostaju $1 - 3 = -2$ zdravstvena poena. Time je šef pobeđen nakon dva poteza.
	* Treći šef ima $14$ zdravstvenih poena i nije ga moguće pobediti sa $4$ data poteza.
	* Četvrti šef ima $13$ zdravstvenih poena. Na njega u prvom potezu primenjujemo napad sa otrovom. Nakon prvog poteza, taj mu napad smanjuje broj zdravstvenih poena za $2$, čime mu preostaje $11$ zdravstvenih poena. U drugom potezu na šefa možemo ponovo da primenimo napad sa otrovom. Nakon kraja poteza akumulirani napadi sa otrovom mu smanjuju broj zdravstvenih poena za $2+1=3$, čime mu preostaje $11 - 3 = 8$ zdravstvenih poena. U trećem potezu na šefa primenjujemo direktni napad čime mu smanjujemo broj zdravstvenih poena za $1$, tj. nakon napada mu preostaje $8 - 1 = 7$ zdravstvenih poena. Nakon kraja poteza akumulirani napadi sa otrovom mu smanjuju broj zdravstvenih poena za $2+1=3$, čime mu preostaje $7 - 3 = 4$ zdravstvena poena. U četvrtom potezu na šefa primenjujemo direktni napad čime mu smanjujemo broj zdravstvenih poena za $1$, tj. nakon napada mu preostaje $4 - 1 = 3$ zdravstvena poena. Nakon kraja poteza akumulirani napadi sa otrovom mu smanjuju broj zdravstvenih poena za $2+1=3$, čime mu preostaje $3 - 3 = 0$ zdravstvenih poena. Time je šef pobeđen nakon četiri poteza. 
	* Peti šef ima $6$ zdravstvenih poena. Na njega u prvom potezu primenimo napad sa otrovom. Nakon prvog poteza, taj mu napad smanjuje broj zdravstvenih poena za $2$, čime mu preostaju $4$ zdravstvena poena. U drugom potezu na šefa primenjujemo direktni napad čime mu smanjujemo broj zdravstvenih poena za $2$, tj. nakon napada mu preostaju $4 - 2 = 2$ zdravstvena poena. Nakon kraja poteza akumulirani napadi sa otrovom mu smanjuju broj zdravstvenih poena za $2$, čime mu preostaje $2 - 2 = 0$ zdravstvenih poena. Time je šef pobeđen nakon dva poteza.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksa Milisavljević | Pavle Martinović | Pavle Martinović |
	
	## Rešenje kada $P_i=0$
	
	Primetimo da ćemo u ovom slučaju uvek raditi direktan napad, tako da posle $k$ poteza ćemo naneti ukupno $S_k=D_1+D_2+\cdots+D_k$ poena štete. Ovaj niz je sortiran, te binarnom pretragom za svaki upit možemo da nađemo najmanji element $S$ koji je veći od traženog $H_i$. Složenost je $O(N+Q\log N)$.
	
	## Rešenje kada $D_i=0$
	
	U ovom slučaju čemo uvek raditi napad otrovom, tako da posle $k$ poteza ćemo naneti ukupno $S_k=k\cdot P_1+(k-1)\cdot P_2+\cdots+1\cdot P_k$ poena štete. Ako sračunamo ovaj niz, možemo završiti binarnom pretragom, kao i u prvom podzadatku. Ovo se, međutim, lako može uraditi tako što se uzme parcijalna suma parcijalnih suma niza $P_i$. Složenost je $O(N+Q\log N)$.
	
	## Rešenje kada $D_i=0$
	
	U ovom slučaju čemo uvek raditi napad otrovom, tako da posle $k$ poteza ćemo naneti ukupno $S_k=k\cdot P_1+(k-1)\cdot P_2+\cdots+1\cdot P_k$ poena štete. Ako sračunamo ovaj niz, možemo završiti binarnom pretragom, kao i u prvom podzadatku. Ovo se, međutim, lako može uraditi tako što se uzme parcijalna suma parcijalnih suma niza $P_i$. Složenost je $O(N+Q\log N)$.
	
	## Rešenje kada je $Q\leq 10$
	U daljim podzadacima, slično prva dva, ćemo označiti sa $S_k$ koliko najviše štete možemo naneti u prvih $k$ poteza. U ovom podzadatku ćemo pokazti kako se proizvoljno $S_k$ može sračunati u $O(N)$. Zaista, primetimo da ako znamo da ćemo raditi tačno $k$ poteza, onda u nekom $i$-tom potezu imamo izbor da ili radimo $D_i$ štete direktnim napadom, ili $P_i$ otrova koje će trajati $k-i+1$ poteza, odnosno naneti ukupno $(k-i+1)P_i$ štete. Pošto je $k$ fiksirano, potrebno je samo izabrati veću od ove dve vrednosti. Sada radimo binarnu pretragu po $S$, ali računajući konkretne vrednosti za $S_i$ samo kad nam trebaju (jer je niz svakako sortiran). Ovo nam daje složenost $O(QN\log N)$.
	## Rešenje kada nema upita prvog tipa
	U ovom slučaju možemo lako sračunati niz $S_i$. Zaista, zbog uslova važi da jedini potez kad je možda optimalno primeniti direktan napad poslednji pred ubijanje, te su nam jedine opcije za $S_k$ ili ono što je bilo u drugom podzataku, ili $k\cdot P_1+(k-1)\cdot P_2+\cdots+2\cdot P_{k-1}+D_k$. Uzimajući maksimum od te dve vrednosti, nalazimo niz $S_k$, i možemo opet da završimo binarnom pretragom kao u prva dva podzadatka. Složenost $O(N+Q\log N)$.
	
	## Glavno rešenje
	
	U ovom rešenju ćemo sračunati sve vrednosti $S_k$ u $O(N)$, oslanjajući se na opservacije iz trećeg podzadatka. Glavno je videti da za svako $i$, kako pomeramo $k$ će nam prvo biti optimalno raditi direktan napad, pa onda od  $k\ge i+\lfloor\frac{D_i}{P_i}\rfloor$ će biti optimalno raditi napad otrovom. Sada pomeramo $k$ i zapamtimo "događaje" oblika od kada je optimalno raditi napad otrovom. Kada naiđemo na novi događaj preračunamo vrednost nanete štete do sad ako bismo uradili napad otrovom umesto direktnog napada u tom potezu, i dodamo taj otrov na neki brojač totalnog otrova. Zatim u svakom potezu dodamo totali otrov i nađemo novu vrednost niza $S$. Ovime smo sračunali niz $S$ i možemo opet binarnom pretragom dovršiti zadatak u $O(N+Q\log N)$
	
	``` cpp title="03_staruci_prsten.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxn 200005
	using namespace std;
	int n, q;
	int p[maxn];
	int d[maxn];
	long long gt[maxn];
	long long ad[maxn];
	long long off[maxn];
	void solve()
	{
	    long long cur = 0;
	    long long sum = 0;
	    for (int i = 1; i <= n; i++)
	    {
	        sum += d[i];
	        if (p[i])
	        {
	            int steps = d[i] / p[i] + 1;
	            int j = i + steps - 1;
	            if (j <= n)
	            {
	                ad[j] += p[i];
	                off[j] += (1ll * p[i] * (j - i) - d[i]);
	            }
	        }
	        cur += ad[i];
	        sum += off[i];
	        sum += cur;
	        gt[i] = sum;
	    }
	}
	int main()
	{
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cin >> n >> q;
	    for (int i = 1; i <= n; i++)
	    {
	        cin >> d[i] >> p[i];
	    }
	    solve();
	    while (q--)
	    {
	        int x;
	        cin >> x;
	        if (x > gt[n])
	            cout << -1 << endl;
	        else
	        {
	            int l = 1;
	            int r = n;
	            while (l < r)
	            {
	                int m = (l + r) / 2;
	                if (gt[m] >= x)
	                    r = m;
	                else
	                    l = m + 1;
	            }
	            cout << l << endl;
	        }
	    }
	    return 0;
	}

	```
