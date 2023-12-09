---
hide:
  - toc
---

# B2 - Turnir

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 267MB |
	
	
	Žetonska igra se igra u $N$ rundi: $M$ takmičara rasporede svoje žetone u $N$ gomila i u svakoj rundi se poredi broj žetona svakog takmičara. Svaka runda se igra u vidu turnira (svako sa svakim), pri čemu pobeđuje igrač sa većim brojem žetona i u $i$-toj rundi pobednik pri jednom pređenju dobija $s_i$ poena (ako nema pobednika, niko ne dobija poene).
	
	Mi se poslednji priključujemo igri i nekako smo uspeli da saznamo kako su svi ostali takmičari rasporedili svoje žetone. Na raspolaganju imamo $K$ žetona. Odrediti neki raspored naših $K$ žetona koji maksimizuje broj poena koje možemo da ostvarimo.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza nalaze se pozitivni celi brojevi $N$, $M$ i $K$, gde je $N$ broj rundi, $M$ takmičara, a $K$  broj žetona koje mi posedujemo. 
	
	U narednom redu, nalazi se $N$ nenegativnih celih brojeva, od kojih je $i$-ti broj $s_i$, broj poena koje dobije pobednik pri jednom poređenju u jednoj rundi.
	
	Narednih $N$ redova nalazi se po $M$ nenegativnih celih brojeva, $j$-ti broj u $i$-tom redu je $a_{i,j}$, broj žetona koje je $j$-ti igrač raspodelio u $i$-toj rundi.
	
	## Opis izlaza
	
	U jedinom redu standardnog izlaza ispisati najveći mogući broj poena koje je moguće ostvariti pri optimalnom raspoređivanju $K$ žetona u $N$ rundi.
	
	## Ograničenja
	
	- $1 \leq N, M \leq 200$
	- $1 \leq K \leq 10^4$
	- $0 \leq s_i \leq 10^9$, za svako $1 \leq i \leq N$
	- $0 \leq a_{i,j} \leq 10^4$, za svako $1 \leq i \leq N, 1\leq j \leq M$
	
	## Podzadaci
	
	1. (4 poena) $N = 1$
	2. (7 poena) $N, K \leq 6$
	3. (21 poena) $M = 1$
	4. (26 poena) $N, M, K \leq 100$
	5. (42 poena) Bez dodatnih ograničenja.
	
	
	## Primeri
	
	### Primer 1
	
	### Ulaz
	
	```
	2 3 10
	1 3
	3 0 7
	8 5 1
	```
	
	### Izlaz
	
	```
	10
	```
	### Objašnjenje
	
	Ukoliko naših $10$ rasporedimo tako što $1$ iskoristimo u prvoj rundi, a preostalih $9$ u drugoj rundi, pobedićemo u jednom poređenju u prvoj rundi i u sva tri poređenja u drugoj rundi. Na taj način dobićemo ukupno $1 \cdot 1 + 3 \cdot 3 = 10$ poena.
	
	### Primer 2
	
	### Ulaz
	
	```
	3 2 10
	3 4 5
	5 6
	9 3
	1 9
	```
	
	### Izlaz
	
	```
	11
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Andrej Ivašković | Aleksa Milisavljević | Andrej Ivašković | Vladimir Milenković |
	
	## Rešenje prvog podzadatka
	
	Ukoliko se igra sastoji od samo jedne runde, to znači da svih svojih $K$ žetona koristimo u toj rundi. Ukupan broj poena koji možemo da ostvarimo jednak je broju ostalih igrača koji imaju manje od $K$ žetona. Ovo rešenje radi u vremenskoj složenosti $O(M)$.
	
	## Rešenje drugog podzadatka
	
	Dovoljno je isprobati sve moguće načine da se $K$ predstavi kao zbir $N$ nenegativnih celih sabiraka, generisane _bektrekingom_, i da se za svaku od tih podela odredi broj poena koji možemo da ostvarimo. Broj načina da se $K$ razbije na $N$ sabiraka jednak je $N+K-1 \choose N-1$, a određivanje broja poena za datu podelu se radi u složenosti $O(MN)$. Bektreking rešenje ne mora da bude posebno efikasno da bi se u ovom podzadatku dobili svi poeni.
	
	## Rešenje trećeg podzadatka
	
	Za $M=1$ postoji samo jedan igrač protiv kog igramo, te je pitanje kako rasporediti žetone da ostvarimo najveći broj pobeda u rundama. Ukoliko je u $i$-toj rundi ovaj igrač postavio $a_{i,1}$ žetona, onda pobedu u ovoj rundi ostvarujemo postavljanjem $a_{i,1}+1$ žetona. Za ostvarivanje pobede u najvećem broju rundi, dovoljno je pobediti u onim rundama u kojima je naš protivnik stavio najmanje žetona. Ovo vodi ka jednostavnom gramzivom algoritmu: najpre se sortiraju runde po broju žetona saigrača (u rastućem poretku), nakon čega se “budžet” od $K$ žetona troši redom u ovim rundama sve dok nam ne ostane nijedan žeton. Vremenska složenost ovog rešenja je $O(N \log N)$.
	
	## Rešenje četvrtog podzadatka
	
	Ovaj podzadatak se rešava primenom _dinamičkog programiranja_. Definišimo trodimenzioni niz $S_{n,k}$, uz $0 \leq n \leq N$, $0 \leq k \leq K$:
	
	* $S_{n,k}$: najveći broj poena koji se može ostvariti ukoliko je iskorišćeno $k$ žetona u prvih $n$ rundi
	
	Trivijalno poznate vrednosti u ovom nizu su:
	
	* $S_{0,k}=0$ za svako $k$
	
	Neka je $[B]$ indikator nekog logičkog izraza: $1$ ukoliko $B$ važi i $0$ ukoliko ne važi. U slučajevima $n>0$ koristimo rekurentnu vezu:
	
	* $S_{n,k} = \max_{1 \leq z \leq k} (S_{n-1,k-z} + \sum_{j=1}^{m} [a_{n,j} < z])$ (*)
	
	Ova rekurentna veza može da se objasni na sledeći način: najbolji način da se $k$ žetona rasporedi u $n$ rundi može da se odredi ukoliko se razmotre svi mogući brojevi žetona $z$ u $n$-toj rundi, odredi koliko igrača ima manje od $z$ žetona u $n$-toj rundi i tako odredi broj poena, na to doda optimalna raspodela $k-z$ žetona u prethodnim rundama, i odredi najbolje takvo $z$. Tada je konačan odgovor na pitanje iz zadatka vrednost $S_{N,K}$, koja može da se odredi u vremenskoj složenosti $O(NMK^2)$.
	
	## Rešenje petog podzadatka
	
	Rešenje koje donosi sve poene je optimizacija rešenja četvrtog podzadatka.
	
	Primetimo da su jedini značajni brojevi žetona u $n$-toj rundi $0, a_{n,1}+1, a_{n,2}+1, \ldots, a_{n,M}+1$, odnosno brojevi žetona pri kojima se ostvaruju različiti brojevi poena. U okviru jedne runde je nebitno koji igrač je stavio koliko žetona, bitni su samo brojevi. Stoga ne gubimo nikakve informacije sortiranjem brojeva žetona različitih igrača u okviru jedne runde.
	
	Primetimo i da je $S_{n,k}$ za fiksirano $k$ rastuće u $n$, odnosno $S_{n,k} \leq S_{n',k}$ za $n < n’$.
	
	Uz ova dva koraka, primetimo da nije neophodno ispitati sve moguće $z$ u formuli (*). Samim tim računanje $S_{n,k}$, koje se u prethodnom podzadatku radilo u vremenskoj složenosti $O(MK)$, može da se uradi u $O(M)$. Ukupna vremenska složenost je $O(NMK)$.
	
	Za one koji žele da znaju više: ovaj zadatak je inspirisan igrom Blotto.
	
	``` cpp title="02_turnir.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 202
	#define maxk 10005
	using namespace std;
	int n,m,k;
	int s[maxn];
	long long dp[maxn][maxk];
	int a[maxn][maxn];
	int main() {
	    scanf("%d %d %d",&n,&m,&k);
	    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	    for(int i=1;i<=n;i++) {
	        for(int j=1;j<=m;j++) {
	            scanf("%d",&a[i][j]);
	        }
	        sort(a[i]+1,a[i]+(m+1));
	    }
	    for(int i=1;i<=n;i++) {
	        for(int j=0;j<=k;j++) dp[i][j]=dp[i-1][j];
	        for(int l=0;l<=m;l++) {
	            int c;
	            if(l==0) c=0;
	            else c=a[i][l]+1;
	            for(int j=c;j<=k;j++) {
	                dp[i][j]=max(dp[i][j],dp[i-1][j-c]+1ll*l*s[i]);
	            }
	        }
	    }
	    long long ans=dp[n][0];
	    for(int j=1;j<=k;j++) ans=max(ans,dp[n][j]);
	    printf("%lld",ans);
	    return 0;
	}

	```
