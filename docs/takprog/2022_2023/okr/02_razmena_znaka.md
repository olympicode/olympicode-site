---
hide:
  - toc
---

# B2 - Razmena znaka

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	Žika je za rođendan dobio ono što protagonisti informatičkih zadataka uvek dobiju kad pisci tekstova nemaju bolju ideju o čemu da naprave priču u svom zadatku - niz $A_i$ od $N$ celih brojeva. Međutim, ovaj fenomen je toliko čest, da je Žika i za prošli rođendan dobio niz dužine $N$ - niz $B_i$! Žika, kao i svaki normalan čovek, nema potrebe za dva različita niza dužine $N$, pa hoće da transformiše svoj novodobijeni niz $A_i$ u $B_i$. 
	
	Pošto nam je potreban zadatak za svrhu drugog zadatka u B kategoriji, Žika je odlučio da jedina operacija koju može da izvrši na nizu $A$ je da izabere dva susedna broja u nizu i zameni im mesta, a zatim im promeni znakove. Ovo znači da ako je niz pre bio $A_1$, $A_2$, $\cdots$, $A_i$, $A_{i+1}$, $\cdots$, $A_N$, posle jedne operacije postaje $A_1$, $A_2$, $\cdots$, $-A_{i+1}$, $-A_i$, $\cdots$, $A_N$. Vaš zadatak je da kažete Žiki da li je moguće da ovim operacijama tranformiše niz $A_i$ tako da važi da je $A_i=B_i$ za svako $i\in\{1,2,\cdots,N\}$.
	
	## Opis ulaza
	Prva linija standardnog ulaza sadrži broj test primera $T$. U narednim redovima su opisani svaki od nezavisnih $T$ test primera. U prvom redu svakog test primera se nalazi jedan nenegativan ceo broj $N$ koji predstavlja dužine nizova $A_i$ i $B_i$. Zatim u naredna dva reda se nalazi po $N$ celih brojeva, koji predstavljaju vrednosti u nizovima $A_i$ i $B_i$, redom.
	
	## Opis izlaza
	U $i$-tom redu standardnog izlaza napisati odgovor  na $i$-ti test primer. Ako je moguće stići od niza $A_i$ do niza $B_i$ primenkom konačno mnogo opisanih operacija, napisati "DA" (bez navodnika), a u suprotnom "NE" (opet, bez navodnika).
	
	## Primer
	### Ulaz
	```
	3
	2
	1 2
	-1 -2
	2
	1 2
	-2 -1
	4
	1 2 3 4
	-4 -3 -2 -1
	```
	
	### Izlaz
	```
	NE
	DA
	DA
	```
	
	## Objašnjenje primera
	Ako je početni niz $1,2$, jedini drugi niz koji je moguće dobiti je $-2,-1$ (primenom još jedne zamene, vraća se na originalni niz), tako da je odgovor u test primeru upitu "NE", a u drugom "DA". U trećem primeru je moguće naći niz poteza koji $A_i$ pretvara u $B_i$ tako što redom radimo razmene na $(1,2)$, $(2,3)$, $(3,4)$, $(1,2)$, $(2,3)$, $(1,2)$. 
	
	## Ograničenja
	-   $1 \leq T \leq 10$.
	-   $1 \leq N \leq 30.000$.
	-   $0\leq |A_i|,|B_i|\leq 1.000.000.000$.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	-   U test primerima vrednim $15$ poena: U oba niza su sve vrednosti $0$ osim jedne.
	-   U test primerima vrednim $25$ poena: $A_i,B_i\in\{-1,1\}$.
	-   U test primerima vrednim $25$ poena: $|A_i|\neq|A_j|$ i $|B_i|\neq|B_j|$ za $i\neq j$.
	-   U test primerima vrednim $35$ poena: Bez dodatnih ograničenja.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Dragan Urošević | Dragan Urošević |
	
	## Analiza
	Pretpostavimo za trenutak da se operacija koju izvršava Žika sastoji samo od zamene mesta dva susedna elementa, tj. da se ne izvršava promena znaka. Može se pokazati da se primenom takve operacije, od polaznog niza može dobiti bilo koji niz sastavljen od elemenata niza $A$, tj. bilo koji raspored elemenata niza $A$:
	$$
	A_{i_1}, A_{i_2}, A_{i_3}, \dots, A_{i_n}. 
	$$
	
	Ako operacija koju izvodi Žika sastoji i od promene znaka, onda je za određivanje vrednosti nekog elementa nakon izvođenja svih operacija dovoljno da znamo njegovu početnu poziciju i njegovu poziciju na kraju (tj. nakon svih izvedenih operacija). Naime, čak i u slučaju da se isti element pomerao levo-desno (prema početku i prema kraju), njegov znak na kraju će biti određen samo rastojanjem između početne o krajnje pozicije (zato što se pri svakom pomeranju levo-desno ili desno-levo izvodi paran broj operacija, pa element niza promeni znak paran broj puta, a to znači da ima isti znak kao da to pomeranje levo-desno nije ni izvodio).
	
	Prema tome, ako se element $A_i$ premestio sa pozicije $i$ na poziciju $j$ ($j\lt i$), onda će njegova vrednost biti  $B_j = (-1)^{i-j}A_i$, tj. $B_j = (-1)^i : (-1)^j A_i$, odnosno važiće $(-1)^j B_j = (-1)^i A_i$. Slično, ako se element $A_i$ premestio sa pozicije $i$ na poziciju $j$ ($j>i$), onda će njegova vrednost biti  $B_j = (-1)^{j-i}A_i = (-1)^{i-j}A_i$, tj. $B_j = (-1)^i : (-1)^j A_i$, odnosno važiće $(-1)^j B_j = (-1)^i A_i$.   Odavde zaključujemo da Žika od niza $A$ može dobiti niz $B$ ako i samo ako se nizovi $C$ ($C_i = (-1)^iA_i$) i $D$ ($D_i = (-1)^iB_i$) sastoje od istih elemenata (naravno, ne nužno na istim pozicijama).
	
	## Rešenje prvog podzadatka
	U ovom slučaju je dovoljno odrediti pozicije elemenata koji su različiti od nule. Ako je $A_i \ne 0$ i $B_j \ne 0$, tada mogu nastupiti tri slučaja
	 
	-   Ako je $A_i = B_j$ i $2 | (i-j)$, onda se od niza $A$ može dobiti niz $B$;
	-   Ako je $A_i = -B_j$ i $2 \not | (i-j)$, onda se od niza $A$ može dobiti niz $B$;
	-   Ako ne važi nijedan od dva gornja uslova, onda od niza $A$ nije moguće dobiti niz $B$.
	
	Složenost opisanog rešenja je $\Theta(n)$.
	
	## Rešenje drugog podzadatka
	Prema analizi, niz $B$ se može dobiti od niza $A$ ako i samo ako se nizovi $C$ ($C_i = (-1)^iA_i$) i $D$ ($D_i = (-1)^iB_i$) sastoje od istih elemenata. Međutim svi elementi nizova $C$ i $D$ imaju vrednost $1$ ili $-1$ i dovoljno je izbrojati da li nizovi $C$ i $D$ imaju isti broj elemenata čija je vrednost $1$ (odnosno isti broj elemenata čija je vrednost $-1$),
	Složenost opisanog rešenja je $\Theta(n)$.
	
	## Rešenje trećeg podzadatka
	U ovom slučaju možemo sortirati nizove parova $E$ $(E_i = (|A_i|, i))$ i $F$  $(F_i=(|B_i|, i))$, pri čemu parove poredimo po vrednosti prvog elementa (komponente) para. Tada od niza $A$ možemo dobiti niz $B$, ako i samo ako za sve odgovarajuće parove važi
	-   prvi elementi parova moraju biti jednaki (jer oni predstavljaju apsolutne vrednosti odgovarajućih elemenata nizova $A$ i $B$);
	-   drugi elementi parova predstavljaju pozicije tih elemenata u nizovima $A$ i $B$; na osnovu pozicija možemo saznati i odgovarajuće elemente nizova $A$ i $B$; oni treba da budu jednaki (ako je razlika pozicija parna) ili suprotnih znakova (ako je razlika pozicija neparna).
	
	Složenost opisanog rešenja je $\Theta(n\log n)$, zbog sortiranja nizova.
	 
	## Glavno rešenje
	Koristimo činjenicu da nizovi $C$ i $D$, opisani u Analizi, treba da sadrže iste elemente (naravno, ako se od niza $A$  može dobiti niz $B$). Ako te nizove sortiramo, onda odgovarajući elementi imaju jednake vrednosti. Zbog toga možemo srtirati nizove $C$ i $D$ i proveriti da li su odgovarajući elementi jednaki. Složenost opisanog rešenja je $\Theta(n\log n)$, zbog sortiranja nizova.
	
	``` cpp title="02_razmena_znaka.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 30007
	using namespace std;
	int a[MAXN],b[MAXN];
	int main()
	{
	    int t;
	    cin>>t;
	    while(t--)
	    {
	        int n;
	        cin>>n;
	        for(int i=0;i<n;i++) cin>>a[i];
	        for(int i=0;i<n;i++) cin>>b[i];
	        for(int i=0;i<n;i++) if(i&1) a[i]=-a[i];
	        for(int i=0;i<n;i++) if(i&1) b[i]=-b[i];
	        sort(a,a+n);
	        sort(b,b+n);
	        bool ok=true;
	        for(int i=0;i<n;i++) if(a[i]!=b[i]) ok=false;
	        if(ok) cout<<"DA\n";
	        else cout<<"NE\n";
	    }
	}

	```
