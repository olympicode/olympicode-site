---
hide:
  - toc
---

# 1 - Kombinovanje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Naš omiljeni čarobnjak je poznat po tome što voli da se hvali kako ima ne jedan, već dva automobila. Kako nikog od njegovih prijatelja ne želi da 58. put sluša o njima, čarobnjak je odlučio da ih iskombinuje u jedan.
	
	Oba automobila možemo predstaviti kao matrice $A$ i $B$ nenegativnih celih brojeva dimenzija $N \times N$. Kombinovanjem dva automobila nastaje novi automobil čija se vrednost računa kao suma proizvoda elemenata početnih matrica, tj. vrednost automobila je $\sum_{i=1}^N\sum_{j=1}^NA_{ij}B_{ij}$. Čarobnjakov cilj je da napravi auto što veće vrednosti.
	
	Čarobnjak može da zameni bilo koja dva reda ili bilo koje dve kolone drugog automobila. Dobroćudni čarobnjak želi da i vi učestvujete u čarima kombinovanja automobila. Vaš zadatak je da mu date niz transformacija matrice $B$. Čarobnjak će učiniti da vaš broj poena na ovom zadatku bude proporcionalan vrednosti automobila koji se dobija kombinovanjem početna dva.
	
	## Napomena
	
	Ovo je zadatak sa poznatim ulazom (*output-only* zadatak). Vama su dati ulazni fajlovi (`1.in`, `2.in`, `3.in`, `4.in`), dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`1.out`, `2.out`, `3.out`, `4.out`).
	
	## Opis ulaza
	
	U prvom redu ulaznih fajlova nalaze se tri prirodna broja $N$, $P$ i $Q$ - dimenzija automobila, kao i parametri za bodovanje. U narednih $N$ redova se nalazi po $N$ brojeva koji predstavljaju automobil $A$. U preostalih $N$ redova se nalazi po $N$ brojeva koji predstavljaju automobil $B$.
	
	## Opis izlaza
	
	Na početku vaših izlaznih fajlova treba da se nalazi prirodan broj $M$, broj transformacija. Nakon toga potrebno je ispisati $M$ linija tako da $(i+1)$-va sadrži tip transformacije - jedan karakter $T_i$ (`R` ako je željena transformacija zamena redova, ili `C` inače), kao i dva broja $X_i, Y_i$, ($1 \leq X_i, Y_i \leq N$) koji predstavljaju indekse kolona i vrsta koje želite da zamenite.
	
	## Primer 1
	
	### Ulaz
	
	~~~
	2 0 1
	0 0
	1 0
	1 0
	0 0
	~~~
	
	### Izlaz
	
	~~~
	1
	R 1 2
	~~~
	
	### Objašnjenje primera
	
	Nakon zamene prvog i drugog reda, dobijena je sledeća matrica:
	~~~
	0 0
	1 0
	~~~
	
	## Bodovanje
	
	Vaše rešenje za neki od ulaza će se smatrati nevažećim ukoliko je ispunjen bar jedan od sledećih uslova:
	
	- $M > 2 \times N^2$
	- $T_i$ nije ni 'R' ni 'C'
	- $X_i$ ili $Y_i$ nisu u intervalu $[1, N]$
	- Ulaz ne sadrži $M+1$ liniju
	
	U suprotnom, neka je \$k\$ vrednost koju postiže vaše rešenje.
	
	- Ukoliko važi $k \geq Q$, osvajate 25 poena za taj ulaz;
	- Ukoliko važi $k \leq P$, osvajate 0 poena za taj ulaz;
	- Inače, osvajate $\lfloor 25\frac{k - P}{Q - P}\rfloor$ poena za taj ulaz.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Momčilo Topalović | Nikola Spasić | Aleksa Plavšić |
	
	S obzirom da početna konfiguracija matrice može biti ciljano postavljena u nepovoljan položaj kolone, i redovi matrice se izmešaju na sledeći način. Za svako $i$ slučajno se biraju dva broja $j$ i $k$ i zatim se $i$-ta kolona zameni sa $j$-tom a $i$-ti red sa $k$-tim redom.
	
	Zatim prođe se kroz sve parove $(i, j)$ i ukoliko bi se zamenom $i$-te i $j$-te kolone rezultat poboljšao kolone se zamene, zatim ukoliko bi se zamenom $i$-tog i $j$-tog reda rezultat poboljšao redovi se zamene.
	
	Prethodno prolazenje kroz sve parove ponovi se 20 puta.
	
	Nakon toga izaberu se 4 slučajna broja $a$, $b$, $c$ i $d$ i ukoliko bi se zamenom $a$-te i $b$-te kolone a zatim zamenom $c$-tog i $d$-tog reda poboljšao rezultat pomenute kolone i redovi se zamene.
	
	Poslednji opisan deo ponovimo $20*n^2$ puta. 
	
	``` cpp title="01_kombinovanje.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	#define ll long long
	
	const int SVE=10,PUTA=20; //Moze se igrati sa ovim konstantama da se dobije dobro resenje
	
	int n;
	ll p,q,bestAns;
	struct resenje{
	    int cntResenje;
	    string resenje;
	}trResenje, best;
	struct matrica{
	    vector<vector<int> > mat;
	    vector<int> rowid, colid;
	    void ucitaj(){
	        mat.resize(n, vector<int>(n));
	        rowid.resize(n);
	        iota(rowid.begin(), rowid.end(), 0);
	        colid.resize(n);
	        iota(colid.begin(), colid.end(), 0);
	        for(int i=0;i<n;i++)
	            for(int j=0;j<n;j++)
	                cin >> mat[i][j];
	    }
	    void swap_row(int i,int j){
	        trResenje.cntResenje++;
	        trResenje.resenje+="R " + to_string(i+1) + " " + to_string(j+1) + "\n";
	        swap(rowid[i],rowid[j]);
	    }
	    void swap_col(int i,int j){
	        trResenje.cntResenje++;
	        trResenje.resenje+="C " + to_string(i+1) + " " + to_string(j+1) + "\n";
	        swap(colid[i],colid[j]);
	    }
	    void izmesaj(){
	        for(int i=0;i<n;i++){
	            int j = rng()%n, k = rng()%n;
	            swap_row(i,j);
	            swap_col(i,k);
	        }
	    }
	    int get(int i,int j){
	        return mat[rowid[i]][colid[j]];
	    }
	}A,B,Backup;
	ll getSum(){
	    ll sum=0;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            sum+=(ll)A.get(i,j)*B.get(i,j);
	    return sum;
	}
	int main(){
	    freopen("1.in","r",stdin);  //Ovo se menja za razlicite inputa
	    freopen("1.out","w",stdout);
	    cin >> n >> p >> q;
	    A.ucitaj();
	    Backup.ucitaj();
	    for(int oo=0;oo<SVE;oo++){
	        trResenje.cntResenje=0;
	        trResenje.resenje.clear();
	        B=Backup;
	        B.izmesaj();
	        for(int o=0;o<PUTA;o++){
	            for(int i=0;i<n;i++)
	                for(int j=i+1;j<n;j++){
	                    ll diffRow=0;
	                    for(int k=0;k<n;k++)
	                        diffRow+=(ll)A.get(i,k)*B.get(j,k)-(ll)A.get(i,k)*B.get(i,k)+(ll)A.get(j,k)*B.get(i,k)-(ll)A.get(j,k)*B.get(j,k);
	                    if(diffRow>0)
	                        B.swap_row(i,j);
	                    ll diffCol=0;
	                    for(int k=0;k<n;k++)
	                        diffCol+=(ll)A.get(k,i)*B.get(k,j)-(ll)A.get(k,i)*B.get(k,i)+(ll)A.get(k,j)*B.get(k,i)-(ll)A.get(k,j)*B.get(k,j);
	                    if(diffCol>0)
	                        B.swap_col(i,j);
	                }
	        }
	        for(int o=0;o<n*n*PUTA;o++){
	            int a=rng()%n, b=rng()%n, c=rng()%n, d=rng()%n;
	            ll diffRow=0;
	            for(int k=0;k<n;k++)
	                diffRow+=(ll)A.get(c,k)*B.get(d,k)-(ll)A.get(c,k)*B.get(c,k)+(ll)A.get(d,k)*B.get(c,k)-(ll)A.get(d,k)*B.get(d,k);
	            if(diffRow>0)
	                B.swap_row(c,d);
	            ll diffCol=0;
	            for(int k=0;k<n;k++)
	                diffCol+=(ll)A.get(k,a)*B.get(k,b)-(ll)A.get(k,a)*B.get(k,a)+(ll)A.get(k,b)*B.get(k,a)-(ll)A.get(k,b)*B.get(k,b);
	            if(diffCol>0)
	                B.swap_col(a,b);
	        }
	        if(getSum()>bestAns)
	            bestAns=getSum(),best=trResenje;
	    }
	    cerr << bestAns;
	    cout << best.cntResenje << endl << best.resenje << endl;
	}

	```
