---
hide:
  - toc
---

# 1 - Klikeri

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 64MB |
	
	Malo je poznato da je za održavanje drugog dana SIO potrebno aktivirati
	mašinu koju Komisija drži u jednom podrumu, koja će zameniti zadatke
	za prvi dan sa zadacima za drugi. Ta mašina ima prilično komplikovan
	sistem za aktivaciju, koji čine traka dužine $L$ polja, od kojih na $N$
	postoje prekidači.
	
	Na traci se nalazi $N$ klikera (svi su na različitim poljima), i za
	aktivaciju je neophodno da se u istom trenutku na svakom prekidaču
	nalazi po kliker. Članovi Komisije ovo obično postižu tako što
	odjednom gurnu sve klikere, tako da se kreću levo ili desno (različiti
	klikeri se mogu kretati u različitim smerovima) konstantnom brzinom od
	jednog polja u sekundi. Klikeri se mogu sudarati sa krajevima trake ili
	međusobno, u kom slučaju se odbijaju i nastavljaju istom brzinom u
	suprotnom smeru (pogledajte objašnjenje primera za primer odbijanja).
	
	Pošto član Komisije koji je trebalo da aktivira mašinu nema vremena da
	smisli kako će to uraditi, jer gleda utakmicu između Mančester Vilidža
	i Fejk Madrida, na vama je da odredite kako treba usmeriti
	klikere. Pošto do drugog dana SIO nema previše vremena, treba da
	pronađete rešenje koje će aktivirati mašinu u što kraćem vremenu.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza nalaze se dva cela broja $L$ i $N$ --
	broj polja na traci i broj klikera. U drugom redu nalazi se $N$ brojeva
	$A_1, A_2, \dots, A_n$, koji predstavljaju trenutne pozicije svih
	klikera. U trećem i poslednjem redu se takođe nalazi $N$ brojeva $B_1,
	B_2, \dots, B_n$, koji predstavljaju pozicije prekidača.
	
	Pozicije su indeksirane od 1, tj. prvom polju trake odgovara $A_i = 1$,
	a poslednjem $A_i = L$.
	
	## Opis izlaza
	U prvom i jedinom redu standardnog izlaza ispisati jedan ceo broj $T$
	-- najmanje vreme (u sekundama) za koje je moguće dovesti sve klikere
	na prekidače. Ukoliko je to nemoguće, ispisati -1.
	
	## Primer 1
	### Ulaz
	```
	4 2
	2 4
	1 4
	```
	
	### Izlaz
	```
	1
	```
	
	## Primer 2
	### Ulaz
	```
	8 4
	1 3 6 7
	1 3 5 8
	```
	
	### Izlaz
	```
	2
	```
	
	## Objašnjenje primera
	U prvom primeru, ako se prvi kliker kreće levo, a druga desno, posle
	jedne sekunde će se prva pomeriti jedno polje levo, a druga udariti u
	kraj trake i vratiti se na svoju početnu poziciju (trebaće joj pola
	sekunde da dođe do zida i pola sekunde nazad, tako da joj pozicija
	ostaje ista).
	
	U drugom primeru, pravci u kojima je potrebno da se klikeri kreću da
	bi se doveli na prekidače za dve sekunde su redom: desno, levo, desno
	i levo. Prve dve kuglice će se sudariti i vratiti na početne
	pozicije. Druge dve će se takođe međusobno odbiti.
	
	## Ograničenja
	* $1 \leq N, L$
	* $1 \leq A_i, B_i \leq L$
	* Sve pozicije $A_i$ će biti međusobno različite.
	* Sve pozicije $B_i$ će biti međusobno različite.
	
	Postoji $5$ podzadataka, u kojima dodatno važi:
	
	* Podzadatak 1 [15 poena]: $N, L \leq 8$.
	* Podzadatak 2 [20 poena]: $N, L \leq 100$.
	* Podzadatak 3 [20 poena]: $N, L \leq 3000$.
	* Podzadatak 4 [25 poena]: $N \leq 1000$, $L \leq 10^9$.
	* Podzadatak 5 [20 poena]: $N \leq 3000$, $L \leq 10^9$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Erdeljan | Dimitrije Erdeljan | Dimitrije Erdeljan | Ivan Stošić |
	
	Možemo zanemariti odbijanje klikera: ako se dva klikera odbiju, pozicija koja se dobija je identična kao da su se mimoišli. Koristeći ovo, za fiksno T je lako odrediti dve moguće pozicije u koje svaki kliker može stići.
	
	Postoji 2N kandidata za rešenje: za prvi kliker na N načina možemo fiksirati prekidač na kom će se naći. Do njega može stići na dva načina – ili direktno ili odbijanjem od zida (dovoljno je odabrati zid za koji brže stiže do prekidača, jer ako može da se reši za jedan zid, može i za drugi tako što obrnemo sve smerove). Ostaje samo da proverimo da li se mogu odabrati smerovi za fiksno T tako da svi klikeri završe na prekidačima.
	
	Konstruišimo bipartitni graf u kom čvorovi sa jedne strane predstavljaju klikere, a sa druge strane prekidače. Grana od klikera do prekidača postoji ukoliko taj kliker može da bude na tom prekidaču za T sekundi (dakle, svaki kliker ima najviše dve izlazne grane). Očito je da rešenje postoji ukoliko možemo upariti svaki kliker sa po jednim prekidačem, odnosno ukoliko postoji perfect matching na ovom grafu, što možemo proveriti u O(N) (jer postoji O(N) čvorova i grana).
	
	Ovaj graf ima jednu specijalnu osobinu: stepen svakog čvora je najviše dva. Samim tim, sačinjen je od izolovanih čvorova, puteva i ciklusa. Ako postoji izolovan čvor, matching ne postoji. U suprotnom, potreban i dovoljan uslov je da su dužine svih puteva parne (ciklusi sigurno imaju matching), tako da je dovoljno proveriti ovo umesto “redovnog” matching algoritma.
	
	``` cpp title="01_klikeri.cpp" linenums="1"
	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	
	const int N = 30005;
	int marble[N], target[N];
	int n, len;
	
	int left[2 * N], right[2 * N]; // targets represented as N and above
	
	int abs(int x) { return x < 0 ? -x : x; } 
	
	int shift(int pos, int diff)
	{
	    pos += diff;
	    if(pos <= 0) pos = 1 - pos;
	    if(pos > len) pos = 2 * len - pos + 1;
	    return pos;
	}
	
	void make_jumps(int from[], int to[], int left[], int right[], int t)
	{   
	    int j = n - 1;
	    for(int i = 0; i < n; i++)
	    {
		int pos = shift(from[i], -t);
		if(from[i] <= t)
		    while(j && to[j] > pos) j--;
		else
		{
		    if((i && from[i - 1] <= t) || (i == 0)) j = 0;
		    while(j < n - 1 && to[j] < pos) j++;
		}
		
		if(to[j] == pos) left[i] = j;
		else left[i] = -1;
	    }
	
	    j = 0;
	    for(int i = 0; i < n; i++)
	    {
		int pos = shift(from[i], t);
		if(from[i] >= len - t + 1)
		{
		    if((i && from[i - 1] < len - t + 1) || (i == 0)) j = n - 1;
		    while(j && to[j] > pos) j--;
		}
		else
		    while(j < n - 1 && to[j] < pos) j++;
	
		if(to[j] == pos) right[i] = j;
		else right[i] = -1;
	    }
	}
	
	bool can_activate(int t)
	{
	    make_jumps(marble, target, left, right, t);
	    for(int i = 0; i < n; i++)
	    {
		if(left[i] != -1) left[i] += N;
		if(right[i] != -1) right[i] += N;
	    }
	    
	    make_jumps(target, marble, left + N, right + N, t);
	    
	    for(int i = 0; i < n; i++)
	    {
	       	if(left[i] == -1 && right[i] == -1)
		    return false; 
	
		else if((left[i] == -1) != (right[i] == -1))
		{
		    int curr = (left[i] == -1) ? right[i] : left[i];
		    int prev = i;
		    int cnt = 2;
	
		    while(1)
		    {
		        if(left[curr] == -1 || right[curr] == -1)
			    break;
	
			int tmp = curr;
			curr = left[curr] + right[curr] - prev; // stupid hack
			prev = tmp;
			
			cnt++;
		    }
	
		    if(cnt % 2 != 0) return false;
		}
	
		// don't care about those with two matches: either in cycle
		// (so OK) or on path (will check when starting from an end of
		// the path)
	    }
	
	    return true;
	}
	
	int main()
	{
	    scanf("%d %d", &len, &n);
	    for(int i = 0; i < n; i++)
		scanf("%d", &marble[i]);
	    for(int i = 0; i < n; i++)
		scanf("%d", &target[i]);
	
	    std::sort(marble, marble + n);
	    std::sort(target, target + n);
	
	    int res = 1 << 30;
	    for(int i = 0; i < n; i++)
	    {
		// go directly
		int t = abs(marble[0] - target[i]);
		if(can_activate(t))
		    res = std::min(res, t);
	
		// bounce off a wall
		t = std::min(abs(marble[0] + target[i] - 1), abs(marble[0] - (2 * len - target[i] + 1)));
		if(can_activate(t))
		    res = std::min(res, t);
	    }
	
	    if(res == (1 << 30))
		res = -1;
	    printf("%d\n", res);
	    
	    return 0;
	}

	```
