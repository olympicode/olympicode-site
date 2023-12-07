---
hide:
  - toc
---

# 4 - Dido

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 512MB |
	
	
	
	Kraljica Dido, takođe poznata i kao Eliza, je u strahu od svog nemilosrdnog brata, Pigmaliona, pobegla u severozapadnu Afriku. Tu je odlučila da osnuje svoje kraljevstvo, drevni grad Kartagu. To će uraditi tako što će ograditi neki deo zemlje i unutar njega osnovati kraljevstvo. 
	
	Severozapadna Afrika se može predstaviti kao deo koordinatne ravni iznad $x$-ose. Dido je već izgradila deo ograde od tačke $(0,0)$ do $(W,0)$ i trenutno se nalazi u tački $(0,0)$. Kako ima ograničeno mnogo materijala za ogradu, ostatak ograde ne sme biti duži od $L$ jedinica dužine. U jednom potezu, Dido može da izgradi segment ograde od trenutne tačke do neke druge tačke tako da se $x$ i $y$ koordinate promene za najviše $1$ (za šta postoji 8 mogućnosti). Dido hoće da se novi deo ograde završi u tački $(W,0)$ kako ne bi bilo delova ograde koji su beskorisni. Zbog toga što Dido hoće da osnuje moćno kraljevstvo, površina ograđena ogradom treba da bude što veća. Ograda (računajući i nov i već izgrađeni deo) ne sme da ima samopresecanja.
	
	Pomozite Dido i recite joj dvostruku najveću površinu koje njeno kraljevstvo može da ima.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Dido(W, L)$
	
	gde je $W$ $x$-koordinata drugog kraja ograde, a $L$ maksimalna dužina novog dela ograde.
	Funkcija treba da vrati dvostruku najveću površinu kraljevstva.
	
	## Primer
	
	Neka je $W=1$ i $L=6$,
	
	Tada je najveća moguća površina $3$ (funkcija treba da vrati dvostruku najveću površinu tj. $6$), i jedan način da se dobije ta površina je sledeći:
	
	$(0,0) \rightarrow (-1,1) \rightarrow (0,2) \rightarrow (1,2) \rightarrow (1,1) \rightarrow (1,0)$ 
	
	Ukupna dužina ograde je $5.8284271247\dots$
	
	
	## Ograničenja
	
	- $0\leq W, L\leq300$
	- Postoji bar jedan način da se ogradi kraljevstvo pozitivne površine.
	
	## Podzadaci
	Test primeri su podeljeni u $5$ podzadatka:
	
	-   **[21 poena]:** $W, L \leq 5$
	-   **[16 poena]:** $W, L \leq 10$
	-   **[18 poena]:** $W, L \leq 40$
	-   **[22 poena]:** $W, L \leq 70$
	-   **[23 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `dido.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int Dido(int W,int L);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom i jedinom redu brojeve $W$ i $L$.
	
	Zatim ovaj program zove vašu funkciju i štampa broj koji vrati funkcija.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Nikola Pešić | Ivan Stošić | Nikola Milosavljević |
	
	
	
	
	Zajedničko za sve podzadatke jeste to što treba proveriti dužinu izlomljene linije koja ima oblik kao što je opisano u zadatku. Naime, neka se ta linija sastoji od $u$ segmenata dužine $1$ i $v$ dijagonalnih segmenata dužine $\sqrt{2}$. Tada, treba da važi $u+v\sqrt{2} \leq L$ odnosno $v \sqrt{2} \leq L-u$, tj. $2v^2 \leq (L-u)^2$ i $u \leq L$.
	
	Takođe, potrebno je da za datu izlomljenu liniju odredimo dvostruku površinu između nje i $x$ ose. To možemo uraditi pomoću metode označenih trapeza. Za svaki segment te duži, izračunamo površinu trapeza koji formiraju ta duž i dve vertikalne duži koje je spajaju sa $x$ osom. Pri tome, površinu trapezoida uzimamo sa pozitivnim znakom ako duž ide sleva na desno, u suprotnom je uzimamo sa negativnim znakom. Za duž $((x_1,y_1),(x_2,y_2))$, ta dvostruka površina iznosi $(y_1+y_2)(x_2-x_1)$. Površina ispod cele izlomljene linije jednaka je zbiru označenih površina svih ovako dobijenih trapeza.
	
	**U prvom podzadatku** dovoljno je rekurzivno izgenerisati sve putanje dužine do $L$, a zatim proveriti da li one stižu u ciljnu tačku i zatim izračunati njihovu površinu.
	
	**Drugi podzadatak** se može rešiti ako se u rekurziju dodaju neki od sledećih uslova za rani izlazak:
	* Ako smo previše udaljeni od ciljne tačke,
	* Ako smo iskoristili smer duži suprotan od prethodne.
	
	**Treći podzadatak** se može rešiti ako primetimo da je rešenje uvek konveksna figura. Neformalam dokaz ovog tvrđenja dat je na samom kraju rešenja. Ovo znači da smer u kojem se krećemo počinje od "levo", zatim rotira u smeru kazaljke na satu i ponovo se završava u "levo". Ovo znači da se svako rešenje može opisati sa $9$ nenegativnih celih brojeva, koji označavaju dužine dela puta na kojima se krećemo u gore opisanim smerovima. Ovakvi nizovu se mogu pažljivo rekurzivno generisati i za svaki može da se proveri površina dobijene figure. Vremenska složenost rešenja je $O(\binom{L}{9}) = O(L^9)$, što je dovoljno, s obzirom na jako malu skrivenu konstantu.
	
	**Četvrti podzadatak** se može rešiti primenom dinamičkog programiranja. Neka je $d_{x,y,u,v}$ najveći zbir označenih površina trapeza koji se može dobiti nekom putanjom od $(0,0)$ do $(x,y)$ pri čemu smo iskoristili $u$ segmenata dužine $1$ i $v$ segmenata dužine $\sqrt{2}$. Prelazi su jednostavni, za svaki od osam smerova, povećavamo $u$ ili $v$ za jedan i korigujemo $x,y$ koordinate, dok novu površinu računamo pomoću formule date u drugom pasusu. Redosled izračunavanja može biti rastući po $u+v$. Konačno rešenje je maksimalna vrednost $d_{W,0,u,v}$, gde $u,v$ zadovoljavaju nejednakosti iz prvog pasusa. Vremenska složenost rešenja je $O(L^4)$, ali sa relativno malom skrivenom konstantom.
	
	**Peti podzadatak** se može rešiti primenom dinamičkog programiranja sa drugačijim načinom računanja površine. Da bi se smanjila složenost, figura se može graditi sa oba kraja ograde odjednom. Neka je $d_{w,u,v}$ najveća površina figure koja se može dobiti nekom putanjom od $(0,0)$ do $(w,0)$ pri čemu smo iskoristili $u$ segmenata dužine $1$ i $v$ segmenata dužine $\sqrt{2}$. Za prelaze jedna opcija je da dodamo horizontalni segment dužine $1$ na neki kraj ograde i time povećamo ili smanjimo $w$ za 1, druga opcija je da povećamo $y$ koordinatu na oba kraja ograde dodavanjem segmenata i dodamo odgovarajuću površinu koja se dobija između ta 2 segmenta. 
	
	Svi mogući prelazi iz stanja $d_{w,u,v}$ su:
	
	* U stanje $d_{w+1,u+1,v}$, na površinu se ne dodaje ništa
	* U stanje $d_{w-1,u+1,v}$, na površinu se ne dodaje ništa
	* U stanje $d_{w+2,u,v+2}$, na površinu se dodaje $2*w+2$
	* U stanje $d_{w+1,u+1,v+1}$, na površinu se dodaje $2*w+1$
	* U stanje $d_{w,u+2,v}$, na površinu se dodaje $2*w$
	* U stanje $d_{w-1,u+1,v+1}$, na površinu se dodaje $2*w-1$
	* U stanje $d_{w-2,u,v+2}$, na površinu se dodaje $2*w-2$
	
	Nama je potrebna maksimalna vrednost od ovih prelaza. 
	Redosled izračunavanja može biti opadajući po $u+v$. Konačno rešenje je $d_{W,0,0}$. Vremenska složenost rešenja je $O(L^3)$.
	
	**Izazov:**
	Da li možete da rešite zadatak u vremenskoj složenosti $O(L^2)$?
	
	**Dokaz:**
	Neka je $(p,q)$ najkraća duž čija unutrašnjost cela leži van figure, dok tačke $p,q$ leže na ivici figure tj. na putanji. Ukoliko ovu duž zamenimo jednom najkraćom putanjom (mereno u osmosmernoj metrici) koja je "ispupčena" u odnosu na duž $p,q$, dobićemo putanju strogo manje dužine a figuru strogo veće površine.
	
	
	``` cpp title="04_dido.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	int Dido(int W,int L){
		int M = L/sqrtl(2);
		auto goodState=[&](int dist,int a,int b){
			if(dist<0||dist>=L||a>L||b>M)
				return false;
			if(L-a-dist<0)
				return false;
			if(2*b*b>(L-a-dist)*(L-a-dist))
				return false;
			return true;
		};
		vector<vector<vector<int>>> dp(L,vector<vector<int>>(L+1,vector<int>(M+1)));
		for(int a=L;a>=0;a--)
			for(int b=M;b>=0;b--)
				for(int dist=0;dist<L;dist++){
					if(!goodState(dist,a,b))
						continue;
					dp[dist][a][b]=0;
					
					if(goodState(dist+1,a+1,b))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist+1][a+1][b]);
						
					if(goodState(dist+2,a,b+2))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist+2][a][b+2]+dist+dist+2);
						
					if(goodState(dist+1,a+1,b+1))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist+1][a+1][b+1]+dist+dist+1);
						
					if(goodState(dist,a+2,b))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist][a+2][b]+dist+dist);
					
					if(goodState(dist-1,a+1,b+1))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist-1][a+1][b+1]+dist+dist-1);
					
					if(goodState(dist-2,a,b+2))
						dp[dist][a][b]=max(dp[dist][a][b],dp[dist-2][a][b+2]+dist+dist-2);
				}
		return dp[W][0][0];
	}
	```
