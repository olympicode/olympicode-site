---
hide:
  - toc
---

# 6 - Svemir

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	Sredinom 23. veka ljudi sa planete Zemlje su konačno razvili tehnike međuplanetarnog putovanja i krenuli sa osvajanjem svemira! Već za dve godine su osvojili $N$ planeta, numerisali ih brojevima od 1 do $N$ i napravili svemirske tunele između nekih od njih! Svi tuneli su dvosmerni i sistem tunela je napravljen tako da za svake dve planete postoji jedinstven način da se od jedne dođe do druge koristeći ove tunele i neke usputne planete. Može se zaključiti da tih tunela ima tačno $N-1$ i da zajedno sa planetama obrazuju strukturu koju ljudi na Zemlji nazivaju stablom. Ti tuneli su zapravo neka vrsta crnih rupa i to nema puno smisla ali ono što je bitno je činjenica da se ovaj zadatak dešava u svemiru!
	
	Osim što su u svemiru, ove planete imaju i neka druga svojstva – za svaku planetu je poznata vrednost $C_i$ koja predstavlja kvalitet svemirskih sarmi na ovim planetama; neke od ovih vrednosti mogu biti i negativne što je logično u svemiru. Poznati krijumčar svemirskih sarmi Jurij Margarin je skovao svemirski plan – izabraće dve (ne nužno različite) planete $A$ i $B$ i trejdovaće sarme na svim planetama (uključujući i ove dve) koje se nalaze na (setimo se) jednistvenom putu između $A$ i $B$. Juriju je naravno cilj da zbir kvaliteta trejdovanih sarmi bude najveći moguć.
	
	Jedini problem u celoj ovoj svemirskoj priči je što Margarina (i sve nas) vidi Svemirska policija, svetlost univerzuma. Preciznije, postoji tačno $K$ svemirskih patrola – za svaku je poznata početna i krajnja planeta $P_i$ i $Q_i$ ($P_i \neq Q_i$) njihovog patroliranja i ta patrola obilazi sve planete na jedinstvenom putu između planeta $P_i$ i Qi (uključujući i njih). Sa vedrije strane, Jurij Margarin ima dovoljno sarmi u svemirskom šteku da podmiti najviše jednu svemirsku patrolu. Prema tome, Jurij mora izabrati put sa najvećim zbirom kvaliteta sarmi ali takav da se na tom putu on može susresti sa najviše jednom patrolom (možda više puta). Pomozite mu!
	
	  
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	$$SvemirskiPut(N, K, t,pat, c[…])$$
	
	gde je $N$ – broj planeta, $K – broj svemirskih patrola, t niz dužine 2(N-1) koji opisuju tunele, pat niz dužine 2K koji opisuje patrole i c je niz kvaliteta dužine N. U nizu t su, redom, navedeni parovi planeta između kojih postojoje tuneli (postoji tunel između planeta $t[0]$ i $t[1]$, između planeta $t[2]$ i $t[3]$ i u opštem slučaju između planeta $t[2i]$ i $t[2i+1]$ za svako $i=[0,N-2]$). Na potpuno isti način niz pat opisuje parove planeta između kojih postoji svemirska patrola. Na kraju, za svako $i=[0,N-1]$ kvalitet sarmi na planeti $i+1$ je $c[i]$. Svi nizovi su indeksirani od 0. Ova funkcija mora da vrati jedan ceo broj – najveći mogući zbir kvaliteta sarmi na Margarinovom put koji zadovoljava gore pomenute uslove.
	
	  
	
	## Primer:
	
	Neka je N=9, K=3, t=[1, 3, 3, 9, 2, 4, 7, 8, 9, 8, 9, 6, 8, 5, 2, 9], pat=[4, 2, 3, 8, 7, 5] i c=[-3, 15, 20, 10, 20, 10, 20, 20, -2]. Ovi podaci opisuju sistem planeta i tunela kao na slici: plavi krugovi predstavljaju planete pri čemu su njihovi redni brojevi unutar krugova a brojevi pored njih predstavljaju kvalitet njihvih sarmi; plave linije predstaljaju tunele; ostale linije predstavljaju patrole – imamo 3 patrole, prva patroliše između planeta 2 i 4 (obilazi obe), druga između planeta 3 i 8 (obilazi planete 3, 9 i 8) i treća između planeta 7 i 5 (obilazi planete 5, 8 i 7). Jurij će najbolje trejdovati sarme ako izabere planete 3 i 6 – tada podmićuje samo drugu patrolu a ukupan kvalitet sarmi na putu od 3 do 6 jednak 20 + (-2) + 10 = 28; bolje od toga ne može i to je broj koji vaša funkcija treba da vrati. Primetimo da Jurij npr. ne može izabrati put između planeta 3 i 4 ili između 3 i 8 jer bi se onda mogao susresti sa dve različite patrole.
	
	![](https://lh7-us.googleusercontent.com/mx2YgwX_v0Fj1xkPWkMGmI-a0Rjp5PYQIjHxzjWWdtG3_x02hLXdvibxtaIZJTKnXOjofoWvyQB-bUeZhdGHKkT8eZvw2rh7hy3Eqqexd4G8zZ6CNkymEpuOdEEmZOksAPuD0UcsOXReIR_QiXimdV1rJRHiksKEBHYI7gRGNTCVgHi_avK-krlXNUE9JMHh)
	
	## Ograničenja
	
	-   $2≤N≤200.000$
	    
	-   $1≤K≤200.000$
	    
	-   Za svako $0≤i<2N-1$ važi $1≤t[i]≤N$
	    
	-   Za svako $0≤i<2K$ važi $1≤ pat[i]≤N$
	    
	-   Za svako $0≤i<K$ važi $pat[2i]≠pat[2i+1]$
	    
	-   Za svako $0≤i<N$ važi $-10^9 \leq c[i] \leq 10^9$
	    
	-   Ulazni podaci će biti takvi da će između svake dve planete postojati jedinstven put
	    
	-   Ulazni podaci će biti takvi da će rešenje uvek postojati
	    
	
	## Podzadaci i bodovanje
	
	-   PODZADATAK 1 [15 POENA]: $N,K≤1.000$
	    
	-   PODZADATAK 2 [15 POENA]: Planete su povezane na sledeći način: $1-2-3-⋯-n$
	    
	-   PODZADATAK 3 [20 POENA]: Sve sarme u svemiru su nekvalitetne tj. $c[i]<0$ za svako $i$
	    
	-   PODZADATAK 4 [20 POENA]: K≤100
	    
	-   PODZADATAK 5 [30 POENA]: Nema dodatnih ograničenja
	    
	
	  
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom svemir.c, svemir.cpp ili svemir.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	C/C++
	
	long long SvemirskiPut(int N, int K, int* t, int* pat, int* c);
	
	Pascal
	
	function SvemirskiPut(N, K : longint; var t, pat, c : array of longint) : int64;
	
	  
	
	Ukoliko radite u C/C++ -u, potrebno je na početku fajla staviti #include “svemir.h” a ukoliko radite u Pascal -u, potrebno je na početku fajla staviti Unit svemir; (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	  
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam “template” fajlovi (svemir.c, svemir.cpp, svemir.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojeve $N$ i $K$, redom
	    
	-   U narednom redu $2(N-1)$ brojeva $t[i]$, razdvojenih razmakom
	    
	-   U narednom redu $2K$ brojeva $pat[i]$, razdvojenih razmakom
	    
	-   U narednom redu $N$ brojeva $c[i]$, razdvojenih razmakom
	    
	
	a zatim pozivaju vašu funkciju SvemirskiPut iz odgovarajućeg fajla (svemir.c, svemir.cpp, svemir.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Dimitrije Dimić | Nemanja Majski | Nikola Milosavljević |
	
	
	
	``` cpp title="06_svemir.cpp" linenums="1"

	```
