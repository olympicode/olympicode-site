---
hide:
  - toc
---

# A2 - Prorok

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 300ms | 64MB |
	
	Nakon što je proveo ceo dan gledajući naučnofantastične filmove, Petar
	je odlučio da iskoristi ideje i znanje koje je iz njih pokupio i napravi
	mehaničkog proroka, odnosno mašinu koja odgovara na bilo kakvo da-ne
	pitanje koje joj se postavi.
	
	Nakon što je napravio proroka, Petar mu je postavio $N$ pitanja i
	beležio odgovore koje je dobio. Da ne bi trošio previše papira, svako
	pitanje je skraćeno obeležio identifikacionim brojem (tako da istim
	brojevima odgovara isto pitanje -- Petar je neka pitanja postavio više
	puta). Primetio je da su odgovori koje je dobio kontradiktorni, tj.
	da je na neka pitanja dobio i odgovor "da" i odgovor "ne".
	
	Petar pretpostavlja da je problem u neispravnoj prostor-vremenskoj
	ferfucni, zbog koje prorok na svako $K$-to postavljeno pitanje odgovara suprotno od
	tačnog odgovora (gde $2 \leq K \leq N$). Da bi mogao da počne popravke
	odmah, umesto da čeka da sazna prave odgovore, zamolio vas je da
	nađete najmanje $K$ koje odgovara ovoj pretpostavci i dobijenim
	odgovorima.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se jedan prirodan broj $N$ --
	broj pitanja koja je Petar postavio. U narednih $N$ redova nalaze se
	identifikacioni broj $i$-tog pitanja $Q_i$ i odgovor koji je prorok dao
	$A_i$. Sve vrednosti $A_i$ će biti ili "da" ili "ne".
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati $K$ -- najmanju
	vrednost "perioda" sa kojim je moguće da prorok greši. Ukoliko takvo
	$K$ ne postoji, ispisati -1.
	
	## Primer 1
	### Ulaz
	```
	5
	1 da
	2 ne
	1 ne
	3 da
	2 ne
	```
	
	### Izlaz
	```
	3
	```
	
	## Primer 2
	### Ulaz
	```
	3
	1 da
	1 ne
	1 ne
	```
	
	### Izlaz
	```
	-1
	```
	
	## Objašnjenje primera
	U prvom primeru, ako su odgovori na pitanja sa identifikacionim brojevima $1, 2, 3$ redom "da", "ne"
	i "da", odgovori proroka su konzistentni ako je na treće postavljeno pitanje dao
	suprotan odgovor (tj. $K = 3$). Za $K = 2$ se ne slažu odgovori na prvo
	i treće pitanje (prorok na njih ne bi odgovorio suprotno), kao ni odgovori na drugo i peto
	(prorok bi na drugo pitanje odgovorio suprotno a ne peto ne bi).
	
	## Ograničenja i podzadaci
	* $1 \leq Q_i \leq 10^9$
	
	Postoje $3$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [20 poena]: $1 \leq N \leq 2000$.
	* Podzadatak 2 [35 poena]: $1 \leq N \leq 100000$, i
	  za sve $i$ važi $Q_i \leq 200$.
	* Podzadatak 3 [45 poena]: $1 \leq N \leq 100000$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Erdeljan | Dimitrije Erdeljan | Dimitrije Erdeljan | - |
	
	Najjednostavnije rešenje bi bilo da probamo svaku moguću vrednost
	za period suprotnih odgovora $K$, i ispišemo prvu koja daje
	konzistentne odgovore. Za svako $K$, možemo prvo okrenuti svaki
	$K$-ti odgovor, pa prebrojati odgovore "da" i "ne" na svako
	pitanje jednim prolazom kroz niz. Ovo zahteva prolazak kroz ceo
	niz za svaki od $N$ kandidata za $K$, tako da bi ukupna složenost
	bila $\mathcal{O}(N^2)$.
	
	Način na koji vodimo evidenciju o broju odgovora na svako pitanje
	je bitan: pošto njihovi identifikacioni brojevi mogu biti do
	$10^9$, niz sa jednim elementom za svaki od njih neće stati u
	memoriju. Umesto ovoga, možemo koristiti strukturu kao što je
	`std::map`, po cenu dodatnog $\mathcal{O}(\log N)$ faktora u
	složenosti. Pošto možemo imati najviše $N$ različitih pitanja,
	bolje rešenje je da na početku "prepakujemo" brojeve u interval od
	$1$ do $N$, a zatim koristimo niz sa $N$ članova. Ovo možemo
	uraditi, na primer, tako što sortiramo sva pitanja, i onda
	najmanjem dodelimo broj 0, sledećem 1, i tako dalje.
	
	Da bi postigli bolju složenost, možemo iskoristiti sledeću
	optimizaciju: pošto se za svako $K$ menja samo svaki $K$-ti
	odgovor, posmatraćemo samo njih i nećemo prolaziti kroz ceo niz,
	osim na početku programa da bi izračunali neke početne vrednosti
	koje će nam biti potrebne. Za $K = 1$ ćemo proći kroz $N$
	vrednosti, za $K = 2$ kroz $\frac{N}{2}$, i tako dalje, tako da će
	ukupna složenost biti:
	
	$$ \frac{N}{1} + \frac{N}{2} + \frac{N}{3} + \dots = \mathcal{O}(N \log N) $$
	
	Za svako $K$, naš algoritam je:
	* Počinjemo od početnog stanja, gde za svako pitanje imamo broj
	  odgovora "da" i "ne" datih na ulazu.
	* Promenimo svaki $K$-ti odgovor tako što odgovarajućem pitanju
	  prebacimo $1$ iz "originalnog" odgovora u novi.
	* Proverimo da li postoji pitanje koje ima i "da" i "ne" odgovore.
	  Ako ne postoji, našli smo rešenje $K$.
	* Poništimo sve izmene koje smo napravili, na primer još jednim
	  prolaskom kroz svaki $K$-ti odgovor.
	
	Svaki od ovih koraka je jednostavan, osim trećeg -- prolazak kroz
	sva pitanja bi nas koštao $\mathcal{O}(N)$ vremena, i ukupna
	složenost bi opet bila kvadratna. Umesto toga, možemo proći samo
	kroz ona pitanja za koja smo menjali odgovore, i proveriti da važe
	dva uslova:
	
	* Nijedno više nema i "da" i "ne" odgovore.
	* Broj pitanja koja su na početku imala oba odgovora je isti kao
	  prethodno izračunat broj ovakvih pitanja u celom ulazu (tj. sva
	  kontradiktorna pitanja su "ispravljena").
	
	``` cpp title="05_prorok.cpp" linenums="1"
	#include <cstdio>
	#include <algorithm>
	
	const int N = 100005;
	
	struct question
	{
	    int id, pos;
	    bool answer;
	} ;
	
	int n;
	question a[N];
	int cnt[N][2];  // cnt[n][x] == # of questions w/ id n and ans x
	int n_both;
	
	bool answer[N];
	int timestamp[N];
	
	bool is_valid(int k)
	{
	    int both = n_both, target = 0;
	    for(int i = k - 1; i < n; i += k)
		if(timestamp[a[i].id] != k)
		{
		    timestamp[a[i].id] = k;
		    answer[a[i].id] = !a[i].answer;
	
		    if(cnt[a[i].id][0] && cnt[a[i].id][1])
			both--;
		    target += cnt[a[i].id][a[i].answer];
		}
		else
		{
		    if(answer[a[i].id] != !a[i].answer)
			return false;
		}
	
	    return both == 0 && target == n / k;
	}
	
	int main()
	{
	    scanf("%d", &n);
	    for(int i = 0; i < n; i++)
	    {
		char ans[10];
		scanf("%d %s", &a[i].id, &ans);
		a[i].answer = (ans[0] == 'd');
		a[i].pos = i;
	    }
	
	    // compress ids
	    std::sort(a, a + n, [](question a, question b) {
		    return a.id < b.id;
		});
	
	    int curr_val = 0, curr_id = a[0].id;
	    a[0].id = curr_val;
	    for(int i = 1; i < n; i++)
		if(a[i].id == curr_id)
		    a[i].id = curr_val;
		else
		{
		    curr_id = a[i].id;
		    curr_val++;
		    a[i].id = curr_val;
		}
	    
	    std::sort(a, a + n, [](question a, question b) {
		    return a.pos < b.pos;
		});
	
	    // precompute cnt
	    for(int i = 0; i < n; i++)
		cnt[a[i].id][a[i].answer]++;
	    
	    for(int i = 0; i < n; i++)
		if(cnt[i][0] && cnt[i][1])
		    n_both++;
	    
	    // solve
	    for(int k = 2; k <= n; k++)
		if(is_valid(k))
		{
		    printf("%d\n", k);
		    return 0;
		}
	
	    printf("-1\n");
	    return 0;
	}

	```
