---
hide:
  - toc
---

# A2 - Šmeker

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	
	
	Na igralištu se svašta dešava. Kako bi klan iz susednog igrališta mogao svakog trenutka da lansira napad, mora da postoji jasna podela uloga među decom. Zbog toga, svako igralište mora da ima svog predsednika, potpredsednika, šmekera, golmana i blagajnika.
	
	Dok se ostale uloge biraju tradicionalnim demokratskim putem, uloga dežurnog *šmekera*, koja je, svakako, po mnogo čemu posebna, ima i poseban način izbora. Naime, igralište možemo zamisliti kao koordinatnu ravan. Kako na igralištu postoje striktna pravila ponašanja, svako dete će doći direktno na svoju predodređenu poziciju $(x,y)$, i ostatak dana se odatle neće pomerati (nemojte da brinete, svakom detetu je obezbeđena lična ljuljaška i par klikera da mu ne bi bilo dosadno). Šmeker je neko ko je uvek u centru pažnje, pa taj jedino može biti dete sa pozicijom na koordinatama $(x_s,y_s)$ tako da važi sledeće:
	
	 - Broj dece na igralištu sa koordinatama $(x,y)$, gde je $x>x_s$ i $y>y_s$ je jednak broju dece na igralištu sa koordinatama $(x,y)$, gde je $x<x_s$ i $y<y_s$;
	 - Broj dece na igralištu sa koordinatama $(x,y)$, gde je $x>x_s$ i $y<y_s$ je jednak broju dece na igralištu sa koordinatama $(x,y)$, gde je $x<x_s$ i $y>y_s$.
	
	Na početku je igralište prazno i na njega redom dolaze deca. U $i$-tom minutu će $i$-to dete stići na svoju poziciju $(x_i,y_i)$. Predsednik igrališta vas je zamolio da pravedno regulišete dodelu uloge šmekera, tako što posle svakog novog dolaska deteta predložite kandidata koji ispunjava uslove, ili da kažete ukoliko takav ne postoji. 
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza se nalazi pozitivan ceo broj $N$, ukupan broj dece. U $i$-tom od narednih $N$ redova se nalaze po $2$ cela broja $x_i$ i $y_i$, koja predstavljaju poziciju $i$-tog deteta, koje će doći na igralište u $i$-tom minutu.
	## Opis izlaza
	Na standardni izlaz potrebno je ispisati $N$ linija. U $i$-toj liniji je potrebno ispisati indeks nekog deteta koje može biti šmeker (ukoliko ih ima više, ispisati bilo koje), a ukoliko takvo ne postoji, potrebno je ispisati $-1$.
	## Ograničenja
	- $1\leq N \leq 200.000$
	-   $1 \leq x_i,y_i \leq 1.000.000.000$
	-   Sve vrednosti $x_i$ su međusobno različite
	-   Sve vrednosti $y_i$ su međusobno različite
	## Podzadaci
	1. (12 poena) $N\leq500$ 
	2. (22 poena) $x_i=y_i$ 
	3. (23 poena) $N\leq4.000$ 
	4. (43 poena) Bez dodatnih ograničenja
	
	## Primer 1
	
	### Ulaz
	
	```
	3
	1 1
	2 2
	3 3
	```
	
	### Izlaz
	
	```
	1
	-1
	2
	```
	### Objašnjenje
	Posle prve minute će se na igralištu nalaziti samo jedno dete, tako da će biti po $0$ dece u svakom od četiri posmatrana skupa, pa će on moći da bude šmeker.
	Posle drugog minuta će na igralištu biti $2$ deteta, i nijedan neće moći da bude šmeker. 
	Posle trećeg minuta, dete broj $2$ može da bude šmeker jer ima po $1$ dete čije su obe koordinate veće/manje, dok je ovih "mešovitih" po $0$.
	## Primer 2
	
	### Ulaz
	
	```
	5
	1 1
	2 5
	3 3
	4 2
	5 4
	```
	
	### Izlaz
	
	```
	1
	-1
	-1
	-1
	3
	```
	
	### Objašnjenje
	Posle 5 minuta, za dete broj $3$ su sva $4$ skupa veličine $1$, pa on može da bude šmeker.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |
	
	## Rešenje kada $N, M \leq 500$
	
	U ovom slučaju, kao rešenje možemo da za svako dete samo izbrojimo koliko postoji dece u svakom od $4$ kvadranta. Za ovo naprosto iteriramo kroz svu decu posle svakog dodavanja, i sa par provera uslova nađemo šmekera. Složenost $O(N^3)$
	
	## Rešenje kada tačke imaju iste $x$ i $y$ koordinate
	
	U ovom slučaju, možemo da vidimo da je drugi uslov trivijalno ispunjen, pa samo treba da nađemo dete za koje važi da ima jednako dece gore desno i dole levo. Ovo je ekvivalentno sa time da ako posmatramo da su deca na pravoj, tražimo onog čija je pozicija medijana niza. Stoga nam je potrebna neka struktura koja nam omogućava održavanje medijane niza u kojem dodajemo nove elemente. Ovo može da se uradi nekim jakim strukturama kao `ordered statistic set`, ali najelementarnije rešenje bi bilo da održavamo dve `heap` strukture, jedan gde se čuva najvećih i drugi gde se čuva najmanjih pola elemenata. Kada dodajemo jedan element u niz, ubacimo ga u neki od njih, i onda najviše jednim prebacivanjem možemo da održimo traženu strukturu.
	
	## Rešenje kada $N\leq 4000$
	
	Primetimo da je uslov da je neko dete šmeker ekvivalentan sa time da je njegova $x$-koordinata medijana po svim $x$-koordinatama, i njegova $y$-koordinata medijana po svim $y$-koordinatama. Zaista, ako je gore levo $a_1$, gore desno $a_2$, dole desno $a_3$ i dole levo $a_4$ dece, uslov za medijane je $a_1+a_2=a_3+a_4$ i $a_1+a_4=a_2+a_3$, pa sabiranjem imamo $2a_1+a_2+a_4=a_2+2a_3+a_4\iff a_1=a_3$, iz čega zaključujemo i $a_2=a_4$, pa dete koje je po obe koordinate medijana je zaista šmeker. Obratno, ako je $a_1=a_3$ i $a_2=a_4$, uslovi $a_1+a_2=a_3+a_4$ i $a_1+a_4=a_2+a_3$ su trivijalno ispunjeni, pa smo dokazali traženu ekvivalenciju. 
	
	Sada imamo vrlo lako rešenje u $O(N^2logN)$ tako što posle svakog dodavanja po obe koordinate nađemo medijanu u $O(NlogN)$, i u zavisnosti od toga jel pripada istom detetu smo našli šmekera ili našli da šmeker ne postoji.
	
	## Glavno rešenje
	
	Ovde je neophodno samo kombinovati ideje iz prethodna dva podzadatka. Kao u drugom podzadatku održavamo medijanu, ali zasebno za $x$- i za $y$-koordinatu u našoj omiljenoj strukturi. Onda posle svakog novog deteta, vidimo da li su deca koji odgovaraju tim medijanama jednaki. Ukupna složenost $O(NlogN)$.
	
	``` cpp title="05_smeker.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	const string folder="testcases\\";
	priority_queue<pair<int,int>> pql[2];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqu[2];
	void addtoheaps(int i,int k,int val)
	{
	    pair<int,int> t={val,k};
	    if(k==1) {pql[i].push(t); return;}
	    if(k&1)
	    {
	        if(t<pqu[i].top()) pql[i].push(t);
	        else
	        {
	            pair<int,int> r=pqu[i].top();
	            pqu[i].pop(); pqu[i].push(t);
	            pql[i].push(r);
	        }
	        return;
	    }
	    if(t>pql[i].top()) pqu[i].push(t);
	    else
	    {
	        pair<int,int> r=pql[i].top();
	        pql[i].pop(); pql[i].push(t);
	        pqu[i].push(r);
	    }
	}
	int getmedian(int i)
	{
	    if(pql[i].size()!=pqu[i].size()) return pql[i].top().second;
	    return -1;
	}
	int main()
	{
	    int n;
	    scanf("%d",&n);
	    for(int i=1;i<=n;i++)
	    {
	        int x,y;
	        scanf("%d%d",&x,&y);
	        addtoheaps(0,i,x);
	        addtoheaps(1,i,y);
	        int a=getmedian(0);
	        int b=getmedian(1);
	        printf("%d\n",((a==b)?a:-1));
	    }
	}

	```
