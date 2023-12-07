---
hide:
  - toc
---

# 5 - Xorko

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Poznati junak iz poznatog modernog superherojskog stripa "Bitovske operacije protiv Muse Kesedžije", Ksorko, je u najnovijem poglavlju upao u nezgodnu klopku i sada mu je život u velikoj opasnosti! Međutim, kako to obično biva u stripovima edukativnog karaktera, on se može izvući i to samo uz vašu pomoć!
	
	Ksorko pred sobom ima niz nenegativnih celih brojeva $A_1,A_2\cdots,A_N$ dužine $N$. Kako je Musa zapovedio, Ksorko može da menja elemente ovog niza po sledećem pravilu: u jednom potezu bira prirodan broj $1<i<N$ i menja vrednosti brojeva $A_{i-1}$ i $A_{i+1}$ u $(A_{i-1}\text{ xor }A_i)$ i $(A_{i+1}\text{ xor }A_i)$ redom, gde $\text{xor}$ predstavlja operaciju bitovske ekskluzije. Kako njemu treba vrlo jak niz da bi pobegao, on želi da primeni datu operaciju neki broj puta **tako da dobijeni niz bude leksikografski najveći mogući.**
	
	Vi, kao verni obožavaoci ovog stripa, nestrpljivo čekate sledeće poglavlje, koje neće izaći dok neko ne reši Ksorkov problem. Stoga, na vama je da spasete Ksorka i omogućite nastavak ovoj epskoj priči.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	-   $LexMax(N, A[\ldots], B[\ldots])$
	
	gde je $N$ broj koji predstavlja broj elemenata Ksorkovog niza, a taj niz je upravo $A$. U niz $B$ dužine $N$ treba da upišete vrednosti brojeva koji će se nalaziti u Ksorkovom nizu na kraju. **Svi nizovi su indeksirani od 1.**
	
	## Primer
	Neka je $N=3$, i neka je niz $A=\{1,3,2\}$: tada jedina operacija koju možemo da izvršimo je da izaberemo $i=2$ i zamenimo  $1$ i $2$ sa $(1 \text{ xor } 3)=2$ i $(2 \text{ xor } 3)=1$. Time dobijamo leksikografski jači niz niz $\{2,3,1\}$. Ako primenimo operaciju opet, vraćamo se u početno stanje pa trea vratiti $B=\{2,3,1\}$.
	
	Neka je $N=5$, i neka je niz $A=\{31,31,31,31,31\}$. Primenom bilo kakvih operacija na ovaj niz nije moguće dobiti veći niz, pa treba vratiti $B=\{31,31,31,31,31\}$.
	
	## Ograničenja
	-   $1 \leq N \leq 150.000$
	-   $0 \leq A_i \leq 10^{18}$
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[6 poena]:** $N\leq10$, $A_i\leq 1$
	-   **[7 poena]:**  $N\leq10$, $A_i\leq 63$
	-   **[12 poena]:** $A_i\leq1$
	-   **[21 poena]:** $N\leq3000$
	-   **[22 poena]:** $A_i\leq15$
	-   **[32 poena]:**  Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl  `xorko.cpp`  koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void LexMax(int N, int* A, int* B);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu broj $N$.
	-   U narednom redu $N$ nenegativnih celih broja $A_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa $N$ brojeva koje predstavljaju rešenje koje vrati funkcija.
	
	## Napomena
	Operator ekskluzivne disjunkcije u Pascal-u je označen sa  `xor`, dok u C++ ga zapisujemo pomoću simbola  `^`. Ova operacija $x\ \text{xor} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in {1, \ldots, k }$ računa $c_i$ pomoću sledećih pravila:
	
	-   Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	-   Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 1$
	-   Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 1$
	-   Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 0$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{xor} \ y$.
	
	Kažemo da je niz $P$ leksikografski manji od niza $Q$ iste dužine ako važi da je $P_i < Q_i$ za najmanje $i$ za koje je $P_i \neq Q_i$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |
	
	## $N\leq10,A_i\leq1$
	Primetimo da ima najviše $2^{10}$ mogućih kombinacija (svaki broj može biti $1$ ili $0$). Sada naprosto ručno bektrekom pretražimo sva moguća stanja do kojih možemo stići obraćajući pažnju da nijedno stanje ne posećujemo više puta. Ukupna složenost $O(2^N\cdot N)$.
	
	## $N\leq10,A_i\leq63$
	Ovaj podzadatak je sličan prethodnom, ali sa opštim brojevima. Naime, isto rešenje bektrekom (mada sa malo komplikovanijom proverom stanja - npr. nekom heš funkcijom), će u ovom podzadatku raditi u složenosti $O(N!\cdot N)$, jer zapravo postoji postoji najviše $N!$ mogućih stanja niza. Dokaz ovoga predstavljamo u narednim podzadacima.
	
	## $N\leq3000$
	Primetimo sledeće:
	Neka su $P[i]$ prefiksni bitovski ksorovi niza $A$ (znači $P[i]=A[1]\text{ xor }A[2]\text{ xor }\cdots\text{ xor }A[i]$). Sada ako izvršimo operaciju iz teksta zadatka na element $i$, primetimo da to zameni vrednosti $P[i-1]$ i $P[i]$. Zaista, ako krenemo da računamo nove vrednosti
	
	$$
	P'[i-1]=A[1]\text{ xor }A[2]\text{ xor }\cdots\text{ xor }A[i-1]\text{ xor }A[i]=P[i]
	$$
	
	$$
	P'[i]=A[1]\text{ xor }A[2]\text{ xor }\cdots\text{ xor }A[i-1]\text{ xor }A[i]\text{ xor }A[i]=P[i-1]
	$$
	
	dok sve ostale vrednosti niza $P[i]$ ostaju nepromenjene jer se dejstvo na elemente $A[i-1]$ i $A[i+1]$ skrati (ili uopšte ne utiče).
	Primetimo sada da možemo na proizvoljan način da ispermtujemo prvih $N-1$ prefiksnih ksorova ovog niza, i kako za dati niz prefiksnih ksorova možemo na jedinstven način rekonstruisati niz ($A[i]=P[i]\text{ xor }P[i-1]$), takvi nizovi koji se dobiju tim permutovanjem prefiksnih ksorova su upravo i jedini nizovi koje je moguće dobiti (odakle i sledi da je najveći broj različitih nizova koje moguće dobiti $(N-1)!$). 
	Sada kad smo ovo uočili smo skoro pa gotovi sa ovim podzadatkom. Naime, treba pohlepno birati permutaciju prefiksnih ksorova tako da se dobije leksikografski najveći niz. U svakom trenutku prođemo kroz ostale prefiksne ksorove koji su nam ostali i naprosto izaberemo onaj koji nam daje najveći ksor sa prethodno izabranim. Obratiti posebnu pažnju na poslednji prefiksni ksor, koji se ne može menjati. Složenost $O(N^2)$.
	
	## $A_i\leq1$
	Sa opservacijama iz prethodnog podzadatka, ovde se može smisliti relativno lako rešenje oblika: pohlepno uzimamo alternirajuće prefiksne ksorove koji su $1$ i $0$ alternirajuće dok nam nekih ne ponestane.
	
	## $A_i\leq15$
	Ovaj podzadatak (a i poslednji), se oslanja na to da se ubrza pohlepno traženje narednog člana u $N\leq3000$ rešenju. Ovde pošto nam je samo bitna vrednost prefiksnog ksora, koja je do $15$, pa onda je dovoljno da samo imamo $count$ niz koji broji koliko imamo koje vrednosti među prefiksnim sumama i onda prođemo kroz sve moguće vrednosti sledećeg člana i izaberemo onu optimalnu. Složenost $O(N\cdot\max A_i)$
	
	## Puno rešenje
	Ubacimo sve prefiksne ksorove u binarni *trie*. Naime, zapišimo svaki taj broj kao njegov binarni zapis tako da ima tačno $60$ cifara (sa potencijalnim vodećim nulama). Sada sve te vrednosti ubacimo u naš *trie*. Sada za tako pripremljenu strukturu, moguće je vrlo brzo naći element koji sa datim brojem $x$ daje najveći ksor, tako što se spuštamo niz trie i pohlepno biramo da odemo u dete sa suprotnom cifrom, ukoliko postoji. Takođe moguće je brzo izbaciti broj iz naše strukture. 
	Sada naprosto izgradimo tu strukturu i idemo redom, i uvek biramo iz nje onaj element koji sa prethodnom vrednošću daje najveći mogući ksor, a zatim je izbacujemo iz iste. 
	Složenost $O(N\cdot\log \max A_i)$. 
	
	``` cpp title="05_xorko.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 150007
	using namespace std;
	int lc[MAXN*62],rc[MAXN*62],cnt[MAXN*62],br;
	long long p[MAXN];
	void ubaci(long long a,int x,int node)
	{
	    cnt[node]++;
	    if(x==-1) return;
	    if(a&(1LL<<x))
	    {
	        if(lc[node]==-1) lc[node]=++br;
	        ubaci(a,x-1,lc[node]);
	    }
	    else
	    {
	        if(rc[node]==-1) rc[node]=++br;
	        ubaci(a,x-1,rc[node]);
	    }
	}
	long long findmax(long long a,int x,int node)
	{
	    cnt[node]--;
	    if(x==-1) return 0;
	    long long sol=0;
	    if((!(a&(1LL<<x)) && lc[node]!=-1) || rc[node]==-1)
	    {
	        sol=findmax(a,x-1,lc[node]);
	        if(!cnt[lc[node]]) lc[node]=-1;
	        sol+=(1LL<<x);
	    }
	    else
	    {
	        sol=findmax(a,x-1,rc[node]);
	        if(!cnt[rc[node]]) rc[node]=-1;
	    }
	    return sol;
	}
	void LexMax(int N, long long* A,long long *B)
	{
	    fill(lc,lc+MAXN*62,-1);
	    fill(rc,rc+MAXN*62,-1);
	    for(int i=1;i<=N;i++) p[i]=p[i-1]^A[i];
	    for(int i=1;i<N;i++) ubaci(p[i],59,0);
	    long long last=0;
	    for(int i=1;i<N;i++)
	    {
	        long long t=findmax(last,59,0);
	        B[i]=last^t;
	        last=t;
	    }
	    B[N]=last^p[N];
	}

	```
