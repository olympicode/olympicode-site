---
hide:
  - toc
---

# 4 - Šestougao

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	
	Data je celobrojna matrica $m$, dimenzija $N \times N$. Šestougao je skup povezanih polja u matricija čija ivična linija obrazuje prost šestougao (sa stranicama paralelnim stranama matrice). Lep šestougao je šestougao u kome važi da za svaku stranicu postoji druga stranica sa istom dužinom i čiji je ukupan obim jednak $A$. 
	
	Dato je $Q$ upita - svaki upit je podmatrica originalne matrice i za svaki upit odrediti najveću moguću vrednost zbira elemenata u nekom lepom šestouglu koji je kompletno sadržan u toj podmatrici.
	
	## Opis ulaza
	U prvom redu standardong ulaza, data su dva cela broja $N$, dimenzija matrice i $A$, obim lepih šestouglova. U narednih $N$ redova, dato je po $N$ celih brojeva. $j$-ti broj u $i$-tom od tih redova je $j$-ta vrednost u $i$-tom redu matrice, (tj. vrednost $m_{i,j}$). U narednom redu, dat je ceo broj $Q$, broj upita. U narednih $Q$ redova, data su po četiri cela broja, $u$, $d$, $l$ i $r$. Ovi brojevi predstavljaju upit nad podmatricom kojoj su dva naspramna ćoška $m_{u,l}$ i $m_{d,r}$ (tj. podmatricom koja sadrži sve elemente koji su između $u$-tog i $d$-tog reda i između $l$-te i $r$-te kolone).
	
	## Opis izlaza
	U svakom od $Q$ redova, potrebno je ispisati po jedan ceo broj. U $i$-tom redu, potrebno je ispisati najveći mogući zbir elemenata u nekom lepom šestouglu koji je kompletno sadržan u podmatrici opisanoj u $i$-tom upitu.
	
	 
	## Ograničenja
	* $1  \leq N \leq  500$.
	* $1  \leq A \leq  10^4$.
	* $1  \leq Q \leq 10^5$.
	* $-10^9 \leq m_{i,j} \leq 10^9$.
	* Garantuje se da u svakoj podmatrici postoji barem jedan lep šestougao.
	
	
	## Podzadaci
	1. (7 poena) $N \leq 5$.
	2. (8 poena) $A = 8, Q \leq 10$.
	3. (11 poena) $N \leq 50, Q \leq 10$.
	4. (13 poena) $A = 8$.
	5. (19 poena) $N \leq 50$.
	6. (42 poena) Nema dodatnih ograničenja.
	
	  
	
	## Primer 1
	
	### Ulaz
	~~~
	3 8
	2 3 2
	5 6 -3
	2 3 4
	2
	1 2 1 2
	1 3 2 3
	~~~
	
	  
	
	  
	
	### Izlaz
	~~~
	14
	13
	~~~
	
	  
	
	  
	
	### Objašnjenje primera
	Podmatrica nad kojom je postavljen prvi upit je obojena zelenom bojom na slici ispod. Lep šestougao sa najvećom sumom koji je kompleto sadržan u njoj je oivičen crvenom bojom na slici ispod:
	
	
	<br>
	
	![Primer logotipa](https://petljamediastorage.blob.core.windows.net/problemmedia/134800/sestougao_resenje_1-1.png)
	
	<br>
	
	Podmatrica nad kojom je postavljen drugi upit je obojena zelenom bojom na slici ispod. Lep šestougao sa najvećom sumom koji je kompleto sadržan u njoj je oivičen crvenom bojom na slici ispod:
	
	<br>
	
	![Primer logotipa](https://petljamediastorage.blob.core.windows.net/problemmedia/134800/sestougao_resenje_2-1.png)
	
	<br>
	
	Primetimo da se u oba šestougla stranice dužine $2$ javljaju dva puta, a stranice dužine $1$ četiri puta, tj šestouglovi imaju obim $8$ i za svaku stranicu postoji druga stranica sa istom dužinom.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Aleksa Milisavljević | Aleksa Milisavljević | Pavle Martinović |
	
	Prva stvar koju treba da primetimo je da uslov da je figura šestogao i da ima stranice paralelne ivicama matrice zapravo znači da je u pitanju figura koja se dobija tako što iz pravougaonika izbacimo manji pravougaonik koji je takav da im se tačno jedan ćošak poklapa.
	
	## Rešenje kada $N \leq 5$
	  
	U ovom podzadatku možemo da fiksiramo svaki šestougao, proverimo da li je on lep i preračunamo odgovor za svaku podmatricu. Različitih šestouglova ima $O(N^6)$, dok različitih podmatrica ima $O(N^4)$. Zbog toga, ovo rešenje radi u vremenskoj složenosti $O(N^{10})$.
	
	Vremenska složenost je $O(N^{10})$, a memorijska $O(N^4)$.
	
	## Rešenje kada $A = 8, Q \leq 10$
	
	Primetimo da su šestouglovi sa obimom $8$ upravo kvadrati dimenzija $2  \times  2$ iz kojih je izbačen jedan ćošak. Takvih šestouglova ima $O(N^2)$ u matrici. U svakom upitu možemo da iteriramo kroz celu podmatricu i izračunamo zbir brojeva u svakom lepom šestouglu.
	
	Vremenska složenost je $O(Q \cdot N^2)$, a memorijska je $O(N^2)$.
	
	## Rešenje kada $N \leq 50, Q \leq 10$
	
	Za rešavanje ovog podzadatka moramo detaljnije da razmotrimo kada tačno izbacivanjem manjeg pravougaonika iz većeg nastaje lep šestougao.
	
	Pretpostavimo da smo imali pravougaonik dimenzija $w \times h$ i da smo iz jednog njegovog ćoška izbacili pravougaonik dimenzija $p \times q$. Posmatrajmo dva slučaja:
	
	- Prvi slučaj: $w \neq h$, tj. orginalni pravougaonik nije kvadrat. Bez umanjenja opštosti, pretpostavimo da $w > h$. Šestougao koji nastaje brisanjem pravougaonika ima stranice dužina $w$, $h$, $w-p$, $q$, $p$, $h-q$. Kako $w \neq h$ i kako u šestouglu, da bi bio lep, svaka dužina mora da se javlja barem dva puta , to mora da važi $w = w-p$ ili $w = q$ ili $w = p$ ili $w = h-q$. Međutim, kako važi $p, w-p < w$ i $q, h-q < h < w$ , to ovaj slučaj nije moguć, tj. šestougao mora biti kvadarat.
	- Drugi slučaj: $w = h$. Uvedimo $a = w = h$. Šestougao koji nastaje brisanjem pravougaonika ima stranice dužina $a$, $a$, $a-p$, $q$, $p$, $a-q$. Kako svaka dužina mora da se javlja barem dva puta, to razlikujemo sledeća dva slučaja: $p = q$ i $p = a - q$. Dodatno, primetimo da je obim ovog šestougla upravo $a + a + a - p + q + p + a - q = 4a$, tj. $a = \frac{A}{4}$.
	
	Dakle, da bi šestougao bio lep, on mora da nastane tako što se iz kvadrata stranice $a = \frac{A}{4}$ izbaci pravougaonik dimenzija $p \times q$, za koje važi $p = q$ ili $p + q = a$. Primetimo da u početnoj matrici kvadrata stranice $a$ ima $(N-a+1)^2$, a za svaki od njih postoji $4(a-1)$ pravougaonika koje možemo da izbacimo da bi dobili lep šestougao. Dakle, ukupno postoji $O(N^3)$ lepih šestouglova u matrici.
	
	Koristeći ovu informaciju, lako možemo da rešimo podzadatak. U svakom upitu, prođemo kroz sve lepe šestouglove. Ovo je najlakše uraditi tako što prvo fiksiramo gornji levi ćošak kvadrata iz kojeg brišemo pravougaonik, zatim stranice pravougaonika i konačno jedan od četiri ćoška kvadrata koji se poklapa sa pravougaonikom.
	
	
	Vremenska složenost je $O(Q N^3)$, a memorijska je $O(N^2)$.
	
	## Rešenje kada $N \leq 50$
	
	Ovaj zadatak zahteva da malo popravimo rešenje iz prethodnog. Ključno je primetiti da za svaki gornji levi ćošak kvadrata iz kojeg izbacujemo pravougaonik možemo da izračunamo lep šestougao koji nastaje sa najvećim zbirom. Ovo zapamtimo za svako polje. Potom u svakom upitu prođemo kroz sva polja koja su kandidati za gornji levi ćošak pravougaonika i na taj način pronađemo lep šestougao sa najvećim zbirom koji se potpuno nalazi u podmatrici iz upita.
	
	Vremenska složenost je $O(Q N^2)$, a memorijska je $O(N^2)$.
	
	## Rešenje kada $A = 8$ 
	
	Za rešenja ovog podzadatka je neophodna tehnika sparse tabela.
	
	Prvo u pomoćnoj matrici $b[i][j]$ zapamtimo lep šestougao sa najvećim zbirom koji je nastao tako što smo kvadratu kome je gornje levo polje upravo $(i,j)$ sklonili jedan ćošak.
	
	U pomoćnoj matrici $sparse[i][j][k]$, preračunamo maksimume svih lepih šestouglova koji nastaju od kvadrata dimenzija $2 \times 2$ kojima je gornji levi ćošak na nekom od polja iz skupa $\{(i,j),(i,j+1),...,(i,j+2^k-1)\}$. Za ovu matricu je lako naću rekurzivnu formulu:
	
	$$
	sparse[i][j][0] = b[i][j],
	$$
	
	$$
	sparse[i][j][k] = max(sparse[i][j][k-1],sparse[i][j+2^(k-1)][k-1])
	$$
	
	Na osnovu ove matrice, možemo da odgovaramo na upite u vremenskoj složenosti $O(N)$. Neka je $k$ najveći broj takav da je $2^k \leq r-l$. Da bi odgovorili na upit, prođemo kroz svaki red $i$ u intervalu $[u,d-1]$ i za svaki od njih izračunamo vrednost $max(b[i][l][k],b[i][r-2^k][k])$ (na ovaj način smo uzeli maksimum svih lepih šestouglova kojima je gornji levi ćošak u redu $i$). Maksimum od svih tih vrednosti je odgovr na upit.
	
	
	Vremenska složenost je $O(N^2 \log N + Q N)$, a memorijska $O(N^2 \log N)$ (ako pamtimo uvek samo rezultate prethodnog kola).
	
	## Glavno rešenje
	
	Za glavno rešenje, neophodno je generalizovati ideju iz prethodnog podzadatka, korišćenjem opservacije o tome kakav pravougaonik moramo da izbacimo da bi dobili lep šestougao. U matrici $b[i][j]$ zapamtimo maksimum svih lepih šestouglova koji su nastali tako što smo izbacili neki pravougaonik iz kvadrata kojem je gornje levo polje $(i,j)$. Potom računamo i koristimo tabelu na sličan način kao u prethodnom podzadatku.
	
	Vremenska složenost je $O(N^3 + Q N)$, a memorijska $O(N^2 \log N)$.
	
	Zadatak je bilo moguće rešiti i u boljoj vremenskoj složenosti $O(N^3 + N^2 \log^2 N + Q)$, korišćenjem dvodimenzionalnih tabela, ali to nije bilo potrebno za maksimalne poene.
	
	
	
	``` cpp title="04_sestougao.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 501
	#define maxl 9
	using namespace std;
	int n;
	int a;
	int s;
	int m[maxn][maxn];
	long long pref[maxn][maxn];
	long long b[maxn][maxn];
	long long sprs[maxn][maxn][maxl][maxl];
	int gdeg[maxn];
	inline long long sum(int u,int d,int l,int r) {
	    return pref[d][r]-pref[d][l-1]-pref[u-1][r]+pref[u-1][l-1];
	}
	inline long long maxsum(int u,int d,int l,int r) {
	    long long ans=-1e18;
	    while(u<=d) {
	        int c=l;
	        while(c<=r) {
	            ans=max(ans,sprs[u][c][gdeg[d-u+1]][gdeg[r-c+1]]);
	            c=c+(1<<gdeg[r-c+1]);
	        }
	        u=u+(1<<gdeg[d-u+1]);
	    }
	    return ans;
	}
	int main() {
	    scanf("%d %d",&n,&a);
	    s=a/4;
	    int j=0;
	    for(int i=1;i<=n;i++) {
	        if(1<<(j+1)<=i) j++;
	        gdeg[i]=j;
	    }
	    for(int i=1;i<=n;i++) {
	        for(int j=1;j<=n;j++) {
	            scanf("%d",&m[i][j]);
	            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+m[i][j];
	        }
	    }
	    for(int i=1;i+s-1<=n;i++) {
	        for(int j=1;j+s-1<=n;j++) {
	            b[i][j]=-1e18;
	            long long tot=sum(i,i+s-1,j,j+s-1);
	            for(int k=1;k<s;k++) {
	                long long k1=sum(i,i+k-1,j,j+k-1);
	                long long k2=sum(i,i+k-1,j+s-k,j+s-1);
	                long long k3=sum(i+s-k,i+s-1,j,j+k-1);
	                long long k4=sum(i+s-k,i+s-1,j+s-k,j+s-1);
	                long long k5=sum(i,i+k-1,j,j+(s-k)-1);
	                long long k6=sum(i,i+k-1,j+k,j+s-1);
	                long long k7=sum(i+s-k,i+s-1,j,j+s-k-1);
	                long long k8=sum(i+s-k,i+s-1,j+k,j+s-1);
	                b[i][j]=max(b[i][j],tot-k1);
	                b[i][j]=max(b[i][j],tot-k2);
	                b[i][j]=max(b[i][j],tot-k3);
	                b[i][j]=max(b[i][j],tot-k4);
	                b[i][j]=max(b[i][j],tot-k5);
	                b[i][j]=max(b[i][j],tot-k6);
	                b[i][j]=max(b[i][j],tot-k7);
	                b[i][j]=max(b[i][j],tot-k8);
	            }
	            sprs[i][j][0][0]=b[i][j];
	        }
	    }
	    for(int k=0;k<9;k++) {
	        for(int l=0;l<9;l++) {
	            if(k==0 && l==0)  continue;
	            if(k==0) {
	                for(int i=1;i+s-1<=n;i++) {
	                    for(int j=1;j+(1<<l)-1+s-1<=n;j++) {
	                        sprs[i][j][k][l]=max(sprs[i][j][k][l-1],sprs[i][j+(1<<(l-1))][k][l-1]);
	                    }
	                }
	            }
	            else {
	                for(int i=1;i+(1<<k)-1+s-1<=n;i++) {
	                    for(int j=1;j+(1<<l)-1+s-1<=n;j++) {
	                        sprs[i][j][k][l]=max(sprs[i][j][k-1][l],sprs[i+(1<<(k-1))][j][k-1][l]);
	                    }
	                }
	            }
	        }
	    }
	    int q;
	    scanf("%d",&q);
	    while(q--) {
	        int u,d,l,r;
	        scanf("%d %d %d %d",&u,&d,&l,&r);
	        printf("%lld\n",maxsum(u,d-s+1,l,r-s+1));
	    }
	    return 0;
	}

	```
