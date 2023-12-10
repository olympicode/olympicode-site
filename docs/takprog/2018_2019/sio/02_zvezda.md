---
hide:
  - toc
---

# 2 - Crno bela zvezda

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 400ms | 64MB |
	
	Svet je konačno postao jedno mirno mesto, puno sreće i ljubavi. Kako bi uspela da se suprostave kragujevačkom fudbalskom gigantu, dva mala fudbalska kluba Partizan i Crvena zvezda su se ujedinili u jedan i postali Crno Bela Zvezda. Nakon ujedinjenja, Crno Bela Zvezda je dobila novi grb. Grb je u obliku crno belog zvezda grafa sa $4$ čvora. Crno beli zvezda graf sa $4$ čvora predstalja stablo čiji su svi čvorovi obojeni crnom ili belom bojom i čiji je koren obojen suprotnom bojom od listova (ako je koren obojen crnom bojom onda su listovi obojeni belom, dok ako je koren obojen belom bojom listovi su obojeni crnom).
	
	Mladi Ćimi, vođa navijača Crno Bele Zvezde, dobio je crveni papir na kome su nacrtane crne i bele tačke. Nacrtano je tačno $N$ tačaka numerisanih brojevima od $1$ do $N$. Boje tačaka su određene nizom $A$, ako je $i$-ta tačka bela onda je $A_i = 0$, u suportnom $A_i = 1$. Kada bi se tačke spojile redom $1 -> 2 -> \dots -> N -> 1$, gradile bi pravilan $N$-tougao. Ćimi je prosto opsednut grbom novog kluba i želi da ga nacrta tačno  $\frac{N}{4}$ puta na tom crvenom papiru. On želi da svaka tačka pripada tačno jednom grbu i da se grbovi međusobno ne presecaju, jer misli da bi tako urušio lepotu grbova.
	 
	Ćimi vas je zamolio da mu pomognete da izračuna broj načina da nacrta tačno $\frac{N}{4}$ grbova. Dva načina se razlikuju ako postoji bar jedan grb koji je nacrtan na jednom crtežu i nije nacrtan na drugom. Kako broj načina može biti veliki, ispisati taj broj po modulu $10^9 + 7$. 
	
	## Opisi funkcija
	
	
	Potrebno je da implementirate funkciju:
	
	* $Zvezda ($N$, A[\dots])$
	
	$N$ je broj tačaka na papiru. $A$ je niz dužine $N$ koji predstavlja boje tačaka,  $i$-ta tačka je bela ako važi $A_i = 0$, inače je tačka crna i $A_i = 1$. 
	**Niz $A$ je indeksiran od $1$.**
	
	Funkcija treba da vrati ceo broj $X$ -- broj načina da Ćimi nacrta grbove po modulu $10^9 + 7$.
	
	## Primer 
	
	
	Neka je $N = 8$, $A = [1, 1, 0, 1, 0, 1, 1, 1]$. 
	
	Postoji $2$ načina da se nacrtaju zvezde:
	
	* prva zvezda : $[1, 2, 3, 4]$, druga zvezda $[5, 6, 7, 8]$
	* prva zvezda : $[8, 1, 2, 3]$, druga zvezda $[4, 5, 6, 7]$
	
	## Ograničenja
	 
	
	* $1 \leq N \leq 500$ , $N$ je deljivo sa $4$
	* $0 \leq A_i \leq 1$
	
	## Podzadaci
	
	Postoji ukupno $14$ podzadataka, koji zadovoljavaju ograničenja napisana u tabeli:
	
	| Redni broj podzadatka | Ograničenje za N | Broj poena |
	|:---------------------:|:---------------:|:----------:|
	|           1           |       12        |     4      |
	|           2           |       24        |     4      |
	|           3           |       52        |     4      |
	|           4           |       76        |     4      |
	|           5           |       100       |     4      |
	|           6           |       128       |     5      |
	|           7           |       152       |     5      |
	|           8           |       200       |     5      |
	|           9           |       252       |     5      |
	|           10          |       300       |     12     |
	|           11          |       352       |     12     |
	|           12          |       400       |     12     |
	|           13          |       452       |     12     |
	|           14          |       500       |     12     |
	    
	
	## Detalji implementacije
	
	
	Potrebno je da pošaljete tačno jedan fajl `zvezda.cpp`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	
	Vaša funkcija mora biti sledećeg oblika:
	
	
	`int Zvezda(int N, int *A);`
	
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova**.
	
	
	## Testiranje i eksperimentisanje
	
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	
	+ U prvom redu broj $N$,
	+ U narednom redu $N$ celih brojeva - $A_i$.
	
	Zatim ovaj program zove vašu funkciju i štampa vrednost koju je funkcija vratila. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Savić | Aleksa Plavšić | Nikola Spasić | Nikola Spasić |
	
	
	## Analiza
	
	Prvo napravima dva geometrijska zaključka.
	
	* Ukoliko bismo rekli da grb treba da bude konveksan četvorougao koji ima kao tri temena tačke jedne a kao preostalo teme tačku druge boje broj načina za iscrtavanje grbova ne bi se razlikovao od onog traženog u zadatku.
	* Ukoliko bi se početne crne i bele tačke nalazile u temenima proizvoljnog konveksnog mnogougla broj načina za iscrtavanje grbova ne bi se razlikovao od onog traženog u zadatku.
	
	Dakle kada odaberemo četiri tačke koje ćemo povezati tokom crtanja jednog grba one dele preostale tačke na četiri grupe (neke od kojih su potencijalno prazne) naime na četiri ciklična segmenta početnog niza tačaka. 
	
	Kako sada ne mogu postojati duži koje spajaju tačke iz različitih grupa svaki novi grb koji nacrtamo (odnosno njegova temena) nalaziće se tačno u jednoj od grupa, a kako tačke svake grupe opet čine konveksan mnogougao vidimo da je problem nalaženja broja načina da se nacrtaju grbovi koristeći temena neke grupe u stvari analogan početnom problemu.
	
	Rešimo sada problem dinamičkim programiranjem, definišimo:
	
	* $d[i][j][0]$ - broj načina da se na cikličnom segmentu $[i, j)$ (uključuje $i$, ne uključuje $j$) nađe tačka $s$ boje $0$ i da se tačke segmenata $[i,s)$ i $[s + 1, j)$ spoje u grbove (svaki grb (odnosno njegova temena) da se nalaze tačno u jednom od segmenata, u $[i,s)$ ili u $[s + 1, j)$)
	* $d[i][j][1]$ - analogno samo za $s$ boje $1$
	* $d[i][j][2]$ - broj načina da se tačke segmenata $[i, j)$ spoje u grbove.
	
	Pre nego što počnemo primetimo da $d[i][j][0]$ i $d[i][j][1]$ mogu biti ne nula samo ukoliko je dužina (broj tačaka) u cikličnom intervalu $[i, j)$ oblika $4k + 1$, dok $d[i][j][2]$ može biti ne nula samo ukoliko je udžina tog intervala oblika $4k$.
	
	Naši početni uslovi su 
	
	* Za svako $1 \leq i \leq n$, $d[i][i][2] = 1$
	* Za svako $1 \leq i \leq n$, $d[i][i + 1][a[i]] = 1$
	* Za svake $i, j, k$, $d[i][j][k] = 0$ sem za gore pomenute
	
	Ostaje još da prođemo kroz sve intervale, sortirane po dužini (broju tačaka u njima).
	
	Sada kada računamo $d[i][j][0]$ jasno je da za svaki $s$ iz intervala $[i, j)$ takav da $A[s] = 0$, trebamo $d[i][j][0]$ da uvećamo za $d[i][s][2] * d[s + 1][j][2]$, po definiciji.
	
	Analogno za $d[i][j][1]$.
	
	U slučaju računanja $d[i][j][2]$ znamo da je tačka $i$ u grbu sa još tri tačke nazovimo onu koja se u smislu cikličnog poretka nalazi između druge dve, odnosno "srednju" tačku, $s$. Ukoliko je ona iste boje kao tačka $i$ broj načina da se tačke intervala $[i, j)$ spoje u grbove na takav način je po definiciji $d[i + 1][s][0] * d[s + 1][j][1] + d[i + 1][s][1] * d[s + 1][j][0]$ (tačke koje su nesparene u popunjavanju manjih segmenata sada uzimamo u isti grb sa tačkama $i$ i $s$, i vodimo računa o tome da su različitih boja), dok analogno ukoliko su $i$ i $s$ istih boja broj načina je $d[i + 1][s][0] * d[s + 1][j][0] + d[i + 1][s][1] * d[s + 1][j][1]$.
	
	Sve prethodno rečeno daje nam ukupnu složenost $O(n^3)$.
	
	## Dodatak
	
	Rešenje se može dodatno ubrzati ukoliko se primeti da ao na segmentu $[i, j)$ ima $a$ tačaka boje $0$ i $b$ tačaka boje $1$, sistem jednačina $3A + B = a$, $A + 3B = b$, mora imati nenegativna rešenja (ukoliko posmatramo da je $A$ broj grbova kojima je teme obojeno bojom $1$, a $B$ broj grbova kojima je teme obojeno bojom $0$ jednačine direktno slede). Ovime i analognim uslovom za slučajeve kada računamo segment kom ostavljamo jednu tačku negrupisanu možemo izbeći bespotrebne prolaske kroz unutrašnju petlju algoritma.
	
	Takođe implementacija algoritma postaje značajno pojednostavljena ukoliko umesto cikličnih segmenata datog niza posmatramo obične segmente dvostruko dužeg niza koji bismo dobili ukoliko bismo na kraj našeg niza nalepili još jedan identičan, uz gotovo identične jednačine.
	
	
	``` cpp title="02_zvezda.cpp" linenums="1"
	#include <iostream>
	#include <stdlib.h>
	#include <stdio.h>
	
	using namespace std;
	
	static const int M = 1000000007;
	static const int N = 1005;
	
	
	long long d[2 * N][2 * N][3];
	int b[2 * N];
	
	int Zvezda(int n, int* a)
	{
	    for(int i = 1; i <= n; i++)
	    {
	        b[i] = a[i];
	        b[i + n] = a[i];
	    }
	
	    for(int i = 1; i <= 2 * n; i++)
	        for(int j = 1; j <= 2 * n; j++)
	            for(int k = 0; k < 3; k++)
	                d[i][j][k] = 0;
	
	    for(int i = 1; i <= 2 * n; i++)
	    {
	        d[i][i][2] = 1;
	        d[i][i + 1][b[i]] = 1;
	    }
	
	    for(int g = 4; g <= n; g += 4)
	    {
	        // deo za ceo
	
	        for(int i = 1; i <= n; i++)
	        {
	            int j = i + g;
	            for(int s = i + 2; s + 1 < j; s += 4)
	            {
	                if(b[i] == b[s])
	                {
	                    d[i][j][2] += d[i + 1][s][0] * d[s + 1][j][1];
	                    d[i][j][2] += d[i + 1][s][1] * d[s + 1][j][0];
	                }
	                else
	                {
	                    d[i][j][2] += d[i + 1][s][0] * d[s + 1][j][0];
	                    d[i][j][2] += d[i + 1][s][1] * d[s + 1][j][1];
	                }
	            	d[i][j][2] %= M;
	            }
	        }
	
	        // deo sa ostatkom
	
	        for(int i = 1; i <= n; i++)
	        {
	            int j = i + g + 1;
	            for(int s = i; s <= j; s += 4)
		    {
	                d[i][j][b[s]] += d[i][s][2] * d[s + 1][j][2];
		        d[i][j][b[s]] %= M;
		    }   
	        }
	    }
	
	    return d[1][n + 1][2];
	}
	
	int main()
	{
	    int A[N];
	    int n;
	
	    cin >> n;
	    for(int i = 1; i <= n; i++)
	        cin >> A[i];
	
	    cout << Zvezda(n, A) << endl;
	    return 0;
	}

	```
