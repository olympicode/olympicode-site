---
hide:
  - toc
---

# 4 - Dugmići

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 700ms | 64MB |
	
	
	Posle svih svojih dogodovština na takmičenjima iz programiranja, mali Perica je shvatio da je najzanimljiviji deo svakog takmičenja kliktanje "Refresh" dugmeta dok čeka rezultate. Zato je Perica odlučio da postane profesionalni kliktač dugmića.
	
	U pripremama za MOKD (Međunarodnu Olimpijadu iz Kliktanja Dugmića), Perica je dizajnirao specijalni trening. Poređao je, na ekranu računara, $N$ dugmića u niz, pri čemu **dugme $i$ ima tajmer koji odbrojava $T_i$ stotinki**. Kada Perica startuje trening, on pomera kursor po ekranu i klikće. 
	
	Da bi kursor pomerio između dva susedna dugmeta, Perici treba jedna stotinka. Peričin cilj je da klikne svako dugme pre nego što tajmer tog dugmeta istekne. Takođe, kada god Perica **klikne dugme $i$, tajmer tog dugmeta se resetuje i kreće da odbrojava $T_i$ stotinki od početka**. Perica želi da pronađe strategiju kojom može da pomera kursor i klikće dugmiće **proizvoljno dugo, a da tajmer nijednog dugmeta ne istekne do kraja** (to jest da između dva uzastopna klika dugmeta $i$ ne protekne striktno više od $T_i$ stotinki). 
	
	Pri tome, pretpostavljamo da Perica može da izabere proizvoljnu startnu poziciju kursora na ekranu, kao i da svi tajmeri kreću da odbrojavaju tek kada se trening startuje. Takođe, pretpostavljamo da sam klik traje zanemarljivo kratko, pa je pomeranje kursora jedina stvar za koju je potrebno vreme.
	
	Pošto je Perici kliktanje dugmića dosadilo jako brzo, smislio je zadatak za Vas. Data su Vam početna vremena za tajmer svakog dugmeta $T_i$, kao i $Q$ upita, koji mogu doći u dva tipa. Za upite prvog tipa dat je indeks dugmeta $i$ i novo trajanje tajmera za to dugme, $T_i$. Za upite drugog tipa, dati su indeksi $L$ i $R$, i treba da odredite da li Perica može da klikće dugmiće sa indeksima u intervalu $[L, R]$ proizvoljno dugo (to jest, da li Perica može da uspešno obavi trening ukoliko su tajmeri aktivni samo na dugmićima u intervalu $[L, R]$).
	
	Ukoliko uspešno obavite ovaj zadatak, pomoćićete Perici da se spremi za MOKD, a on će sa Vama podeliti deo nagrade koje pobeda na ovom prestižnom takmičenju donosi.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju 
	
	- $Trening(N, T[\ldots], Q, X[\ldots], Y[\ldots], Z[\ldots], Ans[\ldots])$,
	
	gde je $N$ broj dugmića u nizu, a $Q$ broj upita. Niz $T[\ldots]$ sadrži početna vremena za svaki od tajmera - tajmer dugmeta $i$ na početku treninga odbrojava $T[i]$ stotinki. Niz $X[i]$ predstavlja tip upita $i$: ukoliko je $X[i]=1$, upit $i$ je prvog tipa, a ukoliko je $X[i]=2$, onda je upit $i$ drugog tipa. 
	
	Ukoliko je upit $i$ prvog tipa, $Y[i]$ predstavlja indeks dugmeta čiji tajmer treba promeniti, dok $Z[i]$ predstavlja novu vrednost tajmera. Ukoliko je upit $i$ drugog tipa, $Y[i]$ predstavlja levu, a $Z[i]$ desnu granicu intervala na kome treba odrediti da li Perica može proizvoljno dugo da klikće dugmiće bez da ijedan tajmer istekne. Konačno, ako je upit $i$ drugog tipa, u niz $Ans$ treba upisati $Ans[i]=1$ ako Perica može da trenira na intervalu $[Y[i], Z[i]]$ proizvoljno dugo. U suprotnom, treba upisati $Ans[i]=0$. Za upite prvog tipa, vrednost $Ans[i]$ neophodno je ostaviti nepromenjenu.
	
	**Svi nizovi su indeksirani od 1.**
	
	## Primer
	
	Neka je $N=5$ i $Q=5$. Neka su početna vremena tajmera $T=[4, 5, 6, 2, 3]$ i neka su nizovi $X=[2, 2, 2, 1, 2], Y=[1, 1, 4, 3, 1]$, $Z=[5, 3, 5, 2, 3]$ i $Ans=[-1, -1, -1, -1, -1]$. Prvi upit je drugog tipa, i odgovor na njega je **NE**, jer ne postoji način da Perica proizvoljno dugo klikće sve dugmiće bez da ijedan tajmer istekne. Na drugi upit je odgovor **DA**, jer Perica može da klikće dugmiće po u rasporedu 1, 2, 1, 2, 3, 2, 1, 2, 1, 2, 3, 2, 1, 2, 1... Na treći upit je odgovor **DA** takođe, jer Perica može kliktati po rasporedu 4, 5, 4, 5, 4... U četvrom upitu se tajmer trećeg dugmeta postavlja na 2 stotinke, pa je odgovor na peti upit **NE**. 
	
	Dakle, niz $Ans$ treba postaviti na $Ans=[0, 1, 1, -1, 0]$.
	
	## Ograničenja 
	 - $1\leq N, Q\leq 2\cdot 10^5$,
	 - $1\leq T[i] \leq 10^9$, za sve $i\in [1, N]$,
	 - $1\leq X[i] \leq 2$, za sve $i\in [1, Q]$,
	 - Ako je $X[i]=1$, tada $1\leq Y[i] \leq N$ i $1\leq Z[i] \leq 10^9$,
	 - Ako je $X[i]=2$, tada $1\leq Y[i] \leq Z[i] \leq N$,
	 - $Ans[i]=-1$ za sve $i\in [1, Q]$.
	
	## Podzadaci
	Test primeri su podeljeni u $4$ podzadatka:
	
	 - **[6 poena]:** $T[i]\leq 6$ i $Z[i]\leq 6$ kadgod je $X[i]=1$.
	 - **[15 poena]:** $N, Q\leq 2\cdot 10^3$.
	 - **[23 poena]:** Svi su upiti drugog tipa, to jest važi $X[i]=2$ za sve $i \in [1, Q]$.
	 - **[56 poena]:** Nema dodatnih ograničenja.
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `dugmici.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Trening(int N, int* T, int Q, int* X, int* Y, int* Z, int* Ans);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$ i $Q$.
	* U drugom redu $N$ brojeva koji predstavljaju početne vrednosti tajmera.
	* U narednih $Q$ redova po tri broja, $X[i], Y[i], Z[i]$ koji opisuju upit.
	
	Zatim ovaj program poziva vašu funkciju uz niz $Ans=[-1, \ldots, -1]$ i štampa niz $Ans$ koji je vratila vaša funkcija.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksa Milojević | Momčilo Tošić | Momčilo Tošić |
	
	## Rešenje kada $T_i \leq 6$, i $Z_i \leq 6$ za $X_i = 1$:
	U ovom slučaju treba razmatrati jedino kratke segmente $[L,R]$, jer ukoliko je odgovor DA, moraćemo u jednom trenutku da odemo od krajnjeg levog do krajnjeg desnog dugmeta, što bi ugasilo početni tajmer ukoliko je $T_L < (R-L)$. Na ovim segmentima možemo da pokušamo da idemo levo-desno par puta, menjajući na svakom koraku sve tajmere u segmentu.
	## Rešenje kada $N,Q \leq 2000$:
	Uočimo da, ukoliko postoji rešenje, ćemo do svakog dugmeta morati u nekom trenutku da dođemo do levog, kao i do desnog kraja segmenta, i nazad. Dakle, za trajanje svakog tajmera u traženom segmentu mora da važi $T_i \geq 2(i-L)$ (dugme-levi kraj-dugme) i $T_i \geq 2(R-i)$ (analogno za desni kraj). Obilazak 'levo-desno' nam upravo garantuje da uspevamo čak i ako važi $T_i = 2(i-L)$ i $T_i = 2(R-i)$. Ove nejednakosti možemo ručno da proverimo za svako dugme u segmentu. 
	## Rešenje kada $X_i = 2$
	Činjenica da nema promena u nizu implicira offline rešenje. Naime, potrebno je naći odgovore za sve segmente $[L,R]$ prolaskom kroz niz jednom. Primetimo da ako važi nejednakost $T_i \geq 2(i-L)$, za neko $L$, ona važi i za sve manje $L$. Shodno tome, obilazimo sve dugmiće od $1$ ka $N$ i na svakom dodajemo u neku strukturu sve leve krajeve segmenata koji u njemu počinju, dok brišemo redom (od manjih ka većim) sve leve početke za koje ne važi $T_i \geq 2(i-L)$ (što postižemo tako što npr. u multiset držimo vrednosti $2L$ i poređujemo ih sa $2i-T_i$), a potvrđujemo mogućnost rešenja za neki segment kad dođemo do dugmeta koje predstavlja njegov desni kraj. Ovo je potrebno uraditi i u drugom smeru (od kraja ka početku).
	## Rešenje za pun broj poena
	Kako u svim dugmićima segmenta treba da važi $T_i \geq 2(i-L), T_i \geq 2(R-i)$ (što je ekvivalentno sa $2L \geq 2i-T_i, 2R \leq T_i+2i$), to znači da nam je potreban način da odredimo da li postoji vrednost $2i-T_i \leq 2L$ i $2i+T_i \geq 2R$ za $i$ u segmentu $[L, R]$ (vrednost za koje ne važi nejednakost), kao i da promenimo vrednost na nekoj poziciji. Ovo nam omogućavaju dva segmentna stabla, gde čuvamo vrednosti $2i+T_i$ i $2i-T_i$ i poređujemo maksimum, odnosno minimum na traženim segmentima sa $2R$ i $2L$. 
	
	``` cpp title="04_dugmici.cpp" linenums="1"
	//SIO 2022 - Zadatak 4 - Dugmici 
	
	#include <bits/stdc++.h>
	#define INF INT_MAX
	#define MAX_N 200005
	
	using namespace std;
	
	int A[4*MAX_N], B[4*MAX_N];
	int N, Q;
	int *X, *Y, *Z, *T;
	
	void segtree(int* tree, int v, int l, int r, int sign){
		if(l+1 == r){
			tree[v]=T[l]+2*sign*l;
			return;
		}
		int m=(l+r)/2;
		segtree(tree, 2*v+1, l, m, sign);
		segtree(tree, 2*v+2, m, r, sign);
		tree[v]=tree[2*v+1]<tree[2*v+2]?tree[2*v+1]:tree[2*v+2];
	}
	
	int query(int* tree, int v, int tl, int tr, int l, int r){
		if(l >= tr || r <= tl){
			return INF;
		}
		if(tl >= l && tr <= r){
			return tree[v];
		}
		int tm=(tl+tr)/2;
		int val1=query(tree, 2*v+1, tl, tm, l, r);
		int val2=query(tree, 2*v+2, tm, tr, l, r);
		return val1<val2?val1:val2;
	}
	
	void update(int* tree, int v, int l, int r, int i, int val, int sign) {
	    if (l+1 == r) {
	        tree[v] = val+2*sign*l;
	        return;
	    } 
		int m = (l+r)/2;
	    if (i < m)
	        update(tree, v*2+1, l, m, i, val, sign);
		else
	        update(tree, v*2+2, m, r, i, val, sign);  
	    tree[v]=tree[2*v+1]<tree[2*v+2]?tree[2*v+1]:tree[2*v+2];
	}
	
	void Trening(int n, int* t, int q, int* x, int* y, int* z, int* Ans){
		
		X=x+1, Y=y+1, Z=z+1, T=t+1;
		N=n, Q=q;
		
		segtree(A, 0, 0, N, -1);
		segtree(B, 0, 0, N, 1);
		
		for(int i=0; i<Q; ++i){
			if(X[i]==1){
				update(A, 0, 0, N, Y[i]-1, Z[i], -1);
				update(B, 0, 0, N, Y[i]-1, Z[i], +1);
			}
			
			if(X[i]==2){
				int L=Y[i]-1;
				int R=Z[i]-1;
				int Aquery=query(A, 0, 0, N, L, R+1);
				int Bquery=query(B, 0, 0, N, L, R+1);
				if(Aquery>=-2*L && Bquery>=2*R)
					Ans[i+1]=1;
				else 
					Ans[i+1]=0;
			}
		}
	}
	

	```
