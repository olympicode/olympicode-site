---
hide:
  - toc
---

# B3 - Bitvajz oranje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	
	Anja i Bogdan igraju igru "Njive". Ona se igra tako što se na početku odredi broj $x$ i špil karata $S_1, S_2, \ldots , S_K$. Na $i$-toj karti nalazi se $S_i$ zrna kukuruza ($1 \leq i \leq K$). Zatim se vuku sledeći potezi:
	
	* Anja bira dve karte sa $a$ i $b$ zrna kukuruza.
	
	* Bogdan izbacuje te dve karte iz igre, a zatim ima izbor da ubaci kartu sa $a \ | \ b$ ili $a\oplus b$ zrna kukuruza.
	
	* Primetimo da se broj karata smanjuje za tačno jedan nakon ovog procesa. Igra se završava kada ostane samo jedna karta. Pobednik se određuje na osnovu vrednosti te poslednje karte. Ako ona ima $x$ zrna kukuruza, onda Anja pobeđuje. U suprotnom, Bogdan je pobednik.
	
	
	
	Prisetimo se da $a\ |\ b$ označava bitovsku disjunkciju, a $a\oplus b$ bitovsku ekskluzivnu disjunkciju. Na primer, $(0110)_2 \ |\ (1010)_2 = (1110)_2$ , dok $(0110)_2 \oplus (1010)_2 = (1100)_2$
	
	
	
	Igra još nije počela, a pred vama je trenutno špil karata $A_1,A_2,\ldots,A_N$. Kako igra ne bi predugo trajala, neće se igrati na celom špilu, već samo na nekim njegovim uzastopnim delovima. Naime, desiće se $Q$ scenarija dve vrste:
	
	* Dat je (ne nužno isti) podniz $A_L, A_{L+1}, \ldots, A_R$ špila karata, a na vama je da odredite koliko ima celih brojeva $x$ ($0 \leq x < 2^{64}$) za koje Anja pobeđuje nezavisno od toga koje poteze Bogdan vuče.
	
	* Karta $P$ se pohabala, čime njen novi broj zrna kukuruza postaje $X$.
	
	
	
	## Opis ulaza
	
	
	
	U prvom redu standardnog ulaza, nalazi se prirodan broj $N$ koji predstavlja veličinu celog špila.
	
	
	
	U drugom redu standardnog ulaza, nalazi se $N$ nenegativnih celih brojeva $A_1,A_2,\ldots A_N$ - opis špila.
	
	
	
	U trećem redu standardnog ulaza, nalazi se prirodan broj $Q$ koji predstavlja broj scenarija.
	
	
	
	U narednih $i$-om od narednih $Q$ redova, nalaze se dva cela broja $L_i$ i $R_i$. Ukoliko je $L_i>0$, onda je reč o scenariju prve vrste. Igra počinje špilom za igru $A_{L_i}, A_{L_i + 1}, \ldots , A_{R_i}$. Pritom, garantuje se $L_i < R_i$. Ukoliko je $L_i<0$, onda je reč o scenariju druge vrste. Tada karta $-L_i$ dobija novi broj zrna kukuruza $R_i$.
	
	
	
	Garantuje se da postoji scenario prve vrste, kao i da $L_i \neq 0$.
	
	
	
	## Opis izlaza
	
	 
	
	Za svaki scenario prve vrste potrebno je u zasebnoj liniji ispisati broj početnih vrednosti $x$ ($0 \leq x < 2^{64}$) za koje Anja pobeđuje nezavisno od Bogdanovih poteza.
	
	
	
	
	## Primer 1
	
	
	
	### Ulaz
	
	
	
	```
	5
	3 1 2 4 5
	3
	1 2
	2 4
	3 5
	```
	
	
	
	### Izlaz
	
	
	
	```
	0
	1
	0
	```
	
	
	
	## Primer 2
	
	
	
	### Ulaz
	
	
	
	```
	4
	1 2 3 4
	5
	-1 4
	-3 1
	1 4
	-1 192
	1 4
	```
	
	
	
	### Izlaz
	
	
	
	```
	0
	1
	```
	
	
	
	
	
	## Ograničenja
	
	
	
	- $2 \leq N \leq 2\cdot 10^5$
	- $1 \leq Q \leq 2\cdot 10^5$
	- $1 \leq A_i < 2^{60}$
	
	
	
	Test primeri su podeljeni u šest disjunktnih grupa:
	
	- U testovima vrednim 8 poena: $N=2$;
	- U testovima vrednim 16 poena: Moguće vrednosti karata su $1$, $2$ i $3$;
	- U testovima vrednim 16 poena: Moguće vrednosti karata su oblika $2^x$ za neki ceo broj $x$;
	- U testovima vrednim 16 poena: $N \leq 100$;
	- U testovima vrednim 16 poena: Nema upita druge vrste;
	- U testovima vrednim 28 poena: Bez dodatnih ograničenja.
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksandar Višnjić | Pavle Martinović | Pavle Martinović |
	
	## Rešenje kada $N=2$
	
	Vidimo da ukoliko je u pitanju interval dužine $1$, Anja ima pobedničku strategiju samo sa jedan broj (upravo tu vrednost). Ukoliko je interval dužine $2$, onda Bogdan bira da li će na ta dva primeniti `or` ili `xor`, tako da Anja može pobediti samo za jednu vrednost i to samo ukoliko su $a\bigoplus b$ i $a|b$ jednaki. 
	
	## Kada Anja ima pobedničku strateiju?
	
	Dokažimo sledeće tvrđenje: Za svaki poziciju bita $i$ pogledajmo u koliko elemenata je inicijalno postavljen na $1$. Ukoliko je svaki bit najviše jednom postavljen na $1$, onda Anja pobeđuje za tačno jednu vrednost, a ukoliko nije tako, onda Anja nikad ne pobeđuje.
	
	Zaista, ako se svaki bit javlja najviše jednom, onda ma šta radili Anja i Bogdan, na kraju će se dobiti broj koji ima jedinice upravo na pozicijama na kojima postoji jedinica na nekom inicijalnih brojeva. (ovo se može npr formalno videti indukcijom). Ukoliko postoji neki bit na kom bar dva inicijalna broja imaju jedinice, onda Bogdan može da namesti da je vrednost na toj poziciji ili $0$ ili $1$ na kraju kako želi, i samim tim izbegne bilo koji Anjin ciljni broj. Naime, on može da uvek bira da radi $a|b$, dok ne ostanu tačno dva broja sa tim bitom. Nadalje radi proizvoljno dok ga ne pita upravo za ta dva broja što imaju jedinicu na bitu koji posmatramo (ako učestvuje samo jedan takav broj u operaciji, ne smeta Bogdanu ništa jer šta god radio, novi broj će opet imati jedinicu na toj poziciji, pa će još uvek ostati tačno dva broja sa jedinicom na toj poziciji). Ukoliko želi da dobije na kraju $0$ na toj poziciji, uradiće $a\bigoplus b$ i neće ostati nijedna jedinica na toj poziciji, pa će i na kraju tu biti $0$. Sa druge strane ako želi na kraju da dobije $1$ na toj poziciji, uradiće $a|b$, pa će ostati jedna jedinica na toj poziciji, a nadalje šta god Anja i Bogdan radili će ostati tačno jedna jedinica na toj poziciji, slično prvom rešenju. Ovime je tvrđenje dokazano.
	
	## Rešenje kada su sve vrednosti $1$, $2$ ili $3$
	
	Može se  lako dokazati iz prethodnog da ovde Anja ima pobedničku strategiju za jednu vrednost ako je niz dužine $1$ ili je skup karata upravo $\{1,2\}$, u suprotnom je odgovor $0$. 
	## Rešenje kada su sve vrednosti stepeni dvojke
	
	Može se dokazati iz prethodnog da ovde Anja ima pobedničku strategiju za jednu vrednost ako  i samo ako su sve vrednosti niza različite, a u suprotnom je odgovor $0$. Implementaciju ovog možemo uraditi tako što ako je interval dužine preko $60$ samo kažemo da je odgovor $0$ (jer postoji samo $60$ različitih vrednosti), a u suprotnom možemo da ga sortiramo i vidimo da li su susedne vrednosti različite, što nam daje da na svaki upit možemo odgovoriti u složenosti $O(\log\max A_i\log\log\max A_i)$.
	## Rešenje kada je $N\leq 100$
	Ovde za svaki bit možemo da idemo redom kroz i vidimo da li je na jedinstvenoj poziciji setovan na jedan, i time svaki upit rešimo u $O(N\log\max A_i)$.
	
	## Rešenje kada nema upita prvog tipa
	Ukoliko nema promena niza, možemo za svaki bit da zapamtimo prvo sledeće i prvo prethodno pojavljivanje na svakoj poziciji. Onda možemo preko tih nizova lako u $O(\log\max A_i)$ po upitu da nađemo odgovor.
	
	## Glavno rešenje
	Slično kao u trećem zadatku vidimo da   ako je interval dužine $>60$ onda je odgovor $0$. Zaista, jer je svaki broj pozitivan, svaki ima barem po jedan bit setovan na $1$, ali onda po Dirihleovom principu mora da postoje dva broja sa zajedničkim bitom, pa Anja ne može da pobedi. Ako je interval dužine do $60$ možemo da izvršimo proveru u linearnom vremenu kao u $4$ podzadatku, pa nam treba $O(\log^2\max A_i)$ po upitu.
	
	``` cpp title="03_bitvajz_oranje.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	long long typedef ll;
	
	ll a[200005];
	
	int main()
	{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0),cout.tie(0);
	
	    int n; cin>>n;
	    for (int i=0;i<n;i++) cin>>a[i];
	    int q; cin>>q;
	    while (q--)
	    {
	        int l; cin>>l;
	        if (l<0)
	        {
	            ll r; cin>>r;
	            a[-l-1]=r;
	        }
	        else
	        {
	            int r; cin>>r;
	            if (r-l>=60)
	            {
	                cout<<0<<"\n";
	                continue;
	            }
	
	            ll x=0;
	            bool moze=true;
	            for (int i=l-1;i<=r-1;i++)
	            {
	                if (x&a[i])
	                {
	                    moze=false;
	                    break;
	                }
	                x|=a[i];
	            }
	
	            if (moze) cout<<1<<"\n";
	            else cout<<0<<"\n";
	        }
	    }
	}

	```
