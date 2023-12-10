---
hide:
  - toc
---

# 4 - Skladište

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 300ms | 128MB |
	
	Nizom čudnih događaja, članovi Komisije su postali vlasnici skladišta,
	u kojem se kutije drže poređane u niz. Svaki put kada se dostava
	pojavi da bi isporučila novu kutiju, potrebno je odlučiti da li će im
	se otvoriti prednja ili zadnja vrata, odnosno da li će kutija biti
	dodata na početak ili kraj niza.
	
	Kada je potrebno izvaditi kutiju iz skladišta, član Komisije koji
	poslednji smisli razlog zašto baš on nema vremena mora da uđe na prednja
	vrata, pronađe traženu kutiju, iznese je i sredi skladište. Ako je
	kutija na poziciji $i$, računato od početka niza (prva kutija je na
	poziciji $0$), ova operacija traje $i$ nanosekundi. Sređivanje uključuje
	"popravljanje" niza, tako da neće ostati prazno mesto (sve kutije nakon
	$i$-te će se pomeriti za jedno mesto).
	
	Pošto Komisija trenutno baš i nema vremena, zamolili su vas da
	preuzmete donošenje odluka tokom dostave. Dobili ste raspored za danas,
	u kom je dato vreme dostave i odnošenja svake kutije. Vaš zadatak je da
	odredite koliko je najmanje vremena potrebno provesti u vađenju kutija
	(u nanosekundama).
	
	## Opisi funkcija
	
	Potrebno je da implementirate sledeću funkciju:
	
	* $Resi(N, A[\ldots], B[\ldots])$
	
	$N$ je broj kutija koje će tokom dana biti dostavljene u skladište (i
	kasnije izvađene), $A$ i $B$ su nizovi dužine $N$ u kojima je dat
	raspored -- $A_i$ je vreme dostave $i$-te kutije (u minutima), a $B_i$
	vreme kada će Komisija izvaditi istu kutiju iz skladišta.
	
	Funkcija treba da vrati ceo broj $T$ -- vreme koje će Komisija
	provesti u skladištu (u nanosekundama), ako su dostave usmerene tako
	da je ovo vreme minimizovano. **Svi nizovi su indeksirani od 0.**
	
	## Primer
	
	Neka je $N = 4$, $A = [0, 1, 2, 5]$ i $B = [3, 7, 4, 6]$. Ovi
	parametri odgovaraju sledećem redosledu događaja:
	
	* kutije 1, 2 i 3 se redom donose u skladište,
	* kutije 1 i 3 (redom) se vade iz skladišta,
	* kutija 4 se donosi, i
	* kutije 4 i 2 se vade.
	
	Optimalan raspored dostava je: kutije 1, 2 i 4 dostaviti na zadnja
	vrata, a 3 na prednja. U ovom slučaju, sve kutije osim 1 će biti prve u
	skladištu kada se vade, a kutija 1 će biti druga, tako da je ukupno
	vreme $1$ nanosekunda.
	
	
	## Ograničenja
	
	* $1 \leq N \leq 10^5$
	* $0 \leq A_i, B_i < 2N$
	* sve vrednosti $A_i$ i $B_i$ su međusobno različite
	
	## Podzadaci
	
	* Podzadatak 1 [20 poena]: $N \leq 20$
	* Podzadatak 2 [40 poena]: $N \leq 3000$
	* Podzadatak 3 [21 poena]: $\forall i,j . A_i < B_j$
	* Podzadatak 4 [19 poena]: Nema dodatnih ograničenja
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `skladiste.cpp` koji
	implementira pomenfutu funkciju. Osim tražene funkcije, vaš fajl može
	sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne
	biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`long long Resi(int N, int *A, int *B)`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali
	ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete
	koristiti i menjati po potrebi. Takođe vam je obezbeđen program
	`grader.cpp` koji služi da lakše testirate kodove. Ovaj program
	učitava sa standardnog ulaza sledeće podatke:
	
	* y prvom redu broj $N$, i
	* u narednih $N$ redova po dva broja: vrednosti $A_i$ i $B_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa povratnu vrednost $T$.
	Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Erdeljan | Dimitrije Erdeljan | Dimitrije Erdeljan | Aleksandar Zlateski |
	
	Posmatrajmo trenutak dostave jedne od kutija. Neka se u skladištu trenutno nalazi $n$ kutija koje će biti izvađene u trenucima $T_0, T_1, \dots, T_n$, i neka je vreme vađenja one koju trenutno ubacujemo $t$.
	
	Ako je ukupno vreme potrebno da se izvade kutije koje su trenutno u skladištu $R$ (ako nema daljih dostava), nakon što dodamo novu, postoje dve mogućnosti:
	
	* novu kutiju stavimo na kraj: vremena vađenja pojedinačnih kutija koje su već u skladištu se neće promeniti. Kada nova kutija dođe na red, ispred nje će biti one za koje važi $T_i > t$, tako da je ukupno vreme $R + |i : T_i > t|$.
	* novu kutiju stavimo na početak: za kutije koje se vade pre nje ($T_i < t$), vreme će se povećati za $1$, a za novu kutiju će vreme vađenja biti $0$. Novo ukupno vreme je dakle $R + |i : T_i < t|$.
	
	Primetimo da ove dve vrednosti uopšte ne zavise od trenutnog redosleda kutija u skladištu. Samim tim, izbor koji daje manje ukupno vreme je optimalan i u slučaju u kom trenutna kutija nije poslednja, tako da je dovoljno da izračunamo ove dve vrednosti za svaku kutiju i odaberemo manju.
	
	Da bi dobili rešenje čija je vremenska složenost $\mathcal{O}(N \log{N})$, neophodna nam je struktura koja podržava sledeće operacije u logaritamskom vremenu:
	
	* dodaj $x$ u skup,
	* izbaci $x$ iz skupa, i
	* odgovori na "koliko elemenata skupa su manji od $x$?"
	
	Jedna opcija je struktura slična `set`-u, ali C++ standardna biblioteka ne podržava direktno upit koji nam je potreban. Pošto su svi elementi mali (maksimalno $2N$), jedna alternativa je segmentno stablo (ili Fenwick stablo). Ovde, u $i$-tom elementu čuvamo $1$ ako je $i$ u skupu, i $0$ u suprotnom. Upit se u tom slučaju svodi na pronalaženje zbira na intervalu $[0, x)$.
	
	``` cpp title="04_skladiste.cpp" linenums="1"
	#include <iostream>
	#include <algorithm>
	#include <vector>
	
	struct event
	{
	    int t, box;
	    bool delivery;
	} ;
	
	bool operator<(event a, event b)
	{
	    return a.t < b.t;
	}
	
	struct segtree
	{
	    static const int N = 1 << 18;
	    int tree[2 * N];
	
	    void set(int pos, int val)
	    {
	        tree[pos += N] = val;
	        for(pos /= 2; pos; pos /= 2)
	            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	    }
	
	    int query(int left, int right)
	    {
	        if(left == right) return tree[left + N];
	        int res = tree[left += N] + tree[right += N];
	        while(left / 2 != right / 2)
	        {
	            if(left % 2 == 0) res += tree[left + 1];
	            if(right % 2 == 1) res += tree[right - 1];
	            left /= 2; right /= 2;
	        }
	        return res;
	    }
	} ;
	
	segtree active;
	
	long long Resi(int N, int *A, int *B)
	{
	    std::vector<event> events;
	    for(int i = 0; i < N; i++)
	    {
	        events.push_back({A[i], i, true});
	        events.push_back({B[i], i, false});
	    }
	    std::sort(events.begin(), events.end());
	    
	    long long res = 0;
	    for(event e : events)
	    {
	        if(e.delivery)
	        {
	            int pre = active.query(B[e.box] + 1, 2 * N);
	            int post = active.query(0, B[e.box] - 1);
	            res += std::min(pre, post);
	            active.set(B[e.box], 1);
	        }
	        else
	        {
	            active.set(B[e.box], 0);
	        }
	    }
	
	    return res;
	}

	```
