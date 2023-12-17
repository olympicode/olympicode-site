---
hide:
  - toc
---

# 1 - Zadatak

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Komisija ove godine nema vremena ni za šta, pa ni za smišljanje zanimljivih tekstova problema. Zato se u tekstu ovog zadatka neće pominjati likovi sa smešnim imenima, izostaće prikrivena međusobna prozivanja članova Komisije,  a neće tu biti ni uobičajenog zafrkavanja takmičara.
	
	Dato je stablo sa $N$ čvorova označenih brojevima od $1$ do $N$, tako da je svaki broj upotrebljen za tačno jedan čvor. (Stablo je ono što je Komisija do sad uglavnom nazivala državom koja je povezana putevima tako da između svaka dva grada postoji jedinstven put.)
	
	Potrebno je napraviti matricu u kojoj je svako polje označeno nekim brojem od $1$ do $N$, tako da su sledeći uslovi zadovoljeni:
	
	* Za svaki par povezanih čvorova u stablu mora postojati bar jedan par susednih polja u matrici koji su označeni sa istim brojevima kao i ta dva čvora.
	* Za svaki par susednih polja u matrici označenih različitim brojevima mora postojati par povezanih čvorova u stablu koji su označeni sa ista ta dva broja.
	* Za svaka dva polja u matrici koja su označena istim brojem mora postojati niz susednih polja označenih tim brojem koji počinje i završava se tim poljima (sva polja sa istom oznakom u matrici moraju biti povezana).
	Dva polja u matrici su susedna ako dele zajedničku stranicu.
	
	Dva polja u matrici su susedna ako dele zajedničku stranicu.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju 
	
	* $NapraviMatricu(N, S, T)$
	
	gde je $N$ broj čvorova u stablu, a $S$ je niz dužine $2(N-1)$ u kome su redom navedeni parovi povezanih čvorova u stablu (prvi i drugi element niza $S$ su oznake dva povezana čvora, isto to važi za treći i četvrti element niza, potom peti i šesti, itd.).
	
	Funkciji se takođe prosleđuje niz $T$ kroz koji treba da vratite vaše rešenje.  Prvi element niza $T$  je broj $H$, broj vrsta konstruisane matrice, drugi element je $W$, broj kolona te matrice, i narednih $H*W$ elemenata su oznake polja u toj matrici koje se navode red po red (najpre se navodi $W$ polja prvog reda, potom $W$ polja drugog reda, itd.). Preostali elementi niza nisu od značaja. Nizovi $S$ i $T$ su indeksirani od $0$, što znači da je prvi element ovih nizova onaj sa indeksom $0$.
	
	## Primer 1
	Neka je $N = 5$, a $S = [1, 2, 2, 3, 2, 4, 4, 5]$. Ovim je opisano sledeće stablo.
	
	```
	1 - 2 - 4 - 5
	    |
	    3
	```
	
	Primeri matrica koje zadovoljavaju postavljene uslove:
	
	```
	5 4 2 3
	5 4 2 2
	4 4 2 1
	
	1 1 2 2
	1 2 2 4
	2 2 4 4
	3 2 4 5
	
	2 2 2 2 1 (Primetite da polja sa oznakama 3 i 4 nisu susedna)
	2 2 2 2 2
	2 2 3 2 2
	4 4 2 2 2
	5 4 2 2 2
	```
	
	Za matricu iz prvog primera odgovarajući niz $T$, koji funkcija treba da vrati je $[3, 4, 5, 4, 2, 3, 5, 4, 2, 2, 4, 4, 2, 1]$. Primeri matrica koje **ne** zadovoljavaju postavljene uslove:
	
	```
	5 4 2 3 (3 i 1 nisu povezani u stablu, a susedni su u matrici.)
	5 4 2 1
	
	1 1 1 1 (4 i 5 su povezani u stablu, a nisu susedni u matrici (jer u matrici ne postoji polje sa oznakom 5))
	2 2 2 2
	3 2 4 4
	
	2 1 2 2 2 (Polja sa oznakom 2 nisu povezana)
	3 2 4 2 5
	```
	
	## Ograničenja
	* $N \leq 100$
	* Nijedna dimenzija konstruisane matrice ne sme biti veća od $1000$. (Niz $T$ će imati $2+1000*1000$ elemenata.)
	
	## Bodovanje
	Rešenje koje ne ispunjava neki od uslova boduje se sa $0$ poena. Ukoliko rešenje ispunjava sve uslove broj bodova za svaki test primer određuje se na osnovu veličine konstruisane matrice i to:
	
	* Ako je bar jedna dimenzija veća od $10N$ na tom test primeru dobijate $0$ poena.
	* Inače, broj bodova se računa na osnovu formule: $\min(1.0, 0.12 + 0.88 \cdot \frac{N}{\max(H,W)})\cdot X$, gde je $X$ maksimalni broj poena koje možete osvojiti po test primeru. 
	
	Ukupan broj poena jednak je zbiru poena za svaki test primer.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom zadatak.c, zadatak.cpp ili zadatak.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	```
	C/C++
	    void NapraviMatricu(int N, int *S, int *T);
	Pascal
	    procedure NapraviMatricu(N : Integer; var S, T : array of Integer);
	```
	
	Ukoliko radite u C/C++-u, potrebno je na početku fajla staviti `#include “zadatak.h”` a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti `Unit zadatak;` **(ovo je već dodato u fajlovima koji su vam obezbeđeni)**.
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (zadatak.c, zadatak.cpp, zadatak.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	* Iz prvog redu učitavaju broj $N$,
	* Iz svakog od narednih $N-1$ redova učitavaju po dva broja koji predstavljaju par povezanih čvorova u stablu,
	
	a zatim pozivaju vašu funkciju NapraviMatricu iz odgovarajućeg fajla (zadatak.c, zadatak.cpp, zadatak.pas) sa učitanim podacima, i na kraju konstruisanu matricu koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dimitrije Dimić | Dimitrije Dimić | - | Ivan Stošić |
	
	
	``` cpp title="01_zadatak.cpp" linenums="1"

	```
