---
hide:
  - toc
---

# A2 - Bekstvo

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 512MB |
	
	Ispostavlja se da obilazak previše koncerta pred takmičenje u Kragujevcu možda i nije bila najpametnija ideja. Nakon što ste se zatekli na koncertu po ko zna koji put, shvatili ste da takmičenje uskoro počinje i da je možda bolje da nastavite put što pre. Jedini problem koji morate da prevaziđete predstavlja činjenica da ste okruženi vernom publikom benda, koja ne namerava da se pomeri do kraja performansa.
	
	Srećom, ni Vi niste nespremni! Brže-bolje ste posegnuli rukom u ranac i izvadili magično stablo koje uvek držite blizu sebe, baš zbog ovakvih neprilika. Vaše magično stablo, naravno, ima $N$ čvorova i $N-1$ granu. Grane povezuju parove čvorova tako da postoji tačno jedan put između svaka dva čvora. Časkom ste posadili stablo, primenili **najviše $K$ magičnih operacija** i zbrisali što ste dalje mogli. 
	
	U jednoj operaciji, dozvoljeno je izabrati proizvoljnu granu stabla i pomeriti je, ali tako da graf i nakon primenjene operacije ostane stablo. Formalno, u jednoj operaciji, dozvoljeno je izabrati proizvoljnu granu stabla, izbrisati je, i potom dodati tačno jednu novu granu, tako da nakon brisanja i dodavanja graf ostane stablo (tj. tako da postoji tačno jedan put između bilo koja dva čvora). Vaš cilj je da pobegnete što dalje, te želite da maksimizujete dijametar krajnjeg stabla (dakle stabla posle svih operacija). Dijametar stabla se definiše kao maksimalan broj grana na putu između neka dva čvora. 
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalazi se ceo broj $T$, broj test primera. Svaki test primer je sledećeg formata: U prvom redu nalaze se dva cela broja $N$ i $K$. U $i$-tom od narednih $N - 1$ redova nalaze se po dva cela broja, $u_i$ i $v_i$, koji opisuju čvorove stabla povezane granom.
	
	## Opis izlaza
	Za svaki od $T$ test primera, potrebno je u jednom redu ispisati jedan ceo broj, koji predstavlja maksimalni dijametar nakon primene najviše $K$ operacija.
	
	## Primer 1
	
	### Ulaz
	
	```
	2
	5 0
	1 4
	3 4
	2 4
	5 2
	5 1
	1 4
	3 4
	2 4
	5 2
	
	```
	
	### Izlaz
	
	```
	3
	4
	```
	### Objašnjenje
	U prvom primeru $K = 0$, te nije moguće promeniti izgled stabla. Najveće rastojanje je $3$ i postiže se između čvorova $3$ i $5$. Put između ta dva čvora je: $3 - 4 - 2 - 5$ i sadrži $3$ grane. U drugom primeru, dozvoljeno je primeniti najviše jednu operaciju. Ukoliko izbrišemo granu između čvorova $4$ i $1$, te je dodamo između čvorova $1$ i $3$, dobijamo stablo sa dijametrom $4$, koji se postiže na putu između čvorova $1$ i $5$.  Put između ta dva čvora je: $1 - 3 - 4 - 2 - 5$ i sadrži $4$ grane.
	
	## Primer 2
	
	### Ulaz
	
	```
	1
	7 1
	1 4
	3 4
	2 4
	5 2
	6 4
	7 5
	```
	
	### Izlaz
	
	```
	5
	```
	### Objašnjenje
	U jedinom primeru je maksimalni dijametar nakon jedne primenjene operacije upravo jednak $5$. Ovaj dijametar se postiže nakon premeštanja grane između čvorova $3$ i $4$, tako da povezuje čvorove $1$ $3$. Tada je rastojanje između $7$ i $3$ upravo jednako $5$. Put između $7$ i $3$ je $7 - 5 - 2 - 4 - 1 - 3$ i sadrži $5$ grana.
	
	## Ograničenja
	
	-   $1 \leq T \leq 10$.
	-   $1 \leq N \leq 3.000$.
	-   $0 \leq K \leq N$.
	
	Test primeri su podeljeni u šest disjunktnih grupa:
	
	- U test primerima vrednim $6$ poena, $N \leq 7$.
	- U test primerima vrednim $14$ poena, $N \leq 20$.
	- U test primerima vrednim $27$ poena, $N \leq 200$.
	- U test primerima vrednim $7$ poena, $K=0$, $N \leq 1.000$.
	- U test primerima vrednim $11$ poena, $K=1$, $N \leq 1.000$.
	- U test primerima vrednim $35$ poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Jovan Bengin | Andrej Ivašković |
	
	## Analiza
	Primena $K$ operacija se zapravo može uraditi odjednom: izbrišemo najviše $K$ grana, i dodamo nove tako da nam graf ponovo postane stablo.  Primetimo da je optimalno da nove grane dodajemo na krajeve dijametara "izrezanih" stabala (stabla na koja smo podelili originalno stablo kada smo izbrisali neke grane) tako da od njih napravimo put. Tada će, u optimalnom rešenju, krajnji dijametar stabla biti jednak sumi dijametara izrezanih stabala plus broj dodatih grana.
	
	Slučaj $K=N$ je ekvivalentan sa $K=N-1$, pa ćemo razmatrati samo $0 \leq K < N$.
	
	## Rešenje prvog i drugog podzadatka
	Biraćemo grane koje brišemo i za sva stabla koja nam ostanu izračunati dijametre, i te dijametre ćemo sumirati. Mogućih podela u najgorem slučaju ima $2^{N-1}$ (svaku granu ili brišemo ili ne brišemo), a dijametar stabla možemo naći u $O(N)$ - pustimo pretragu iz nasumičnog čvora, obeležimo najdalji čvor od njega kao prvi kraj dijametra, pustimo pretragu iz tog čvora i obeležimo najdalji čvor kao drugi kraj dijametra. Ovaj algoritam radi jer je najdalji čvor od proizvoljnog čvora uvek kraj nekog dijametra, a najdalji čvor od kraja dijametra je drugi kraj tog dijametra.
	
	Vremenska složenost ovog algoritma je $O(2^NTN)$, što prolazi prvi podzadatak. Međutim, ne moramo razmatrati svih $2^{N-1}$ podela - dovoljne su samo one gde brišemo tačno $K$ grana (ako smo izbrisali neki broj grana, nikad ne možemo dobiti lošije rešenje ako izbrišemo još neke). Ovako ćemo razmatrati samo ${N \choose K} \leq {N \choose N/2}$ podela, i rešenje nam lako prolazi drugi podzadatak.
	
	## Rešenje četvrtog podzadatka
	Pošto je $K = 0$, rešenje je samo dijametar početnog stabla. Ovde dijametar ne moramo ni tražiti $O(N)$ algoritmom: dovoljno je da iz svakog čvora pustimo po pretragu.
	
	Vremenska složenost: $O(TN)$ ili $O(TN^2)$
	
	## Rešenje petog podzadatka
	Iteriraćemo kroz sve grane, i za svaku u $O(N)$ računati dijametre dva stabla koja dobijemo njenim brisanjem.
	
	Vremenska složenost: $O(TN^2)$
	
	## Rešenje trećeg podzadatka
	Nije potrebno eksplicitno tražiti dijametre izrezanih stabala. Lakše nam je da uz svako izrezano stablo samo izaberemo neki put koje mu pripada - u optimalnom rešenju će se svakako ispostaviti da su to dijametri.
	
	Definišimo $dp[u][k][x]$ kao najveću moguću sumu izabranih puteva u podstablu čvora $u$ ako smo u njemu primenili $k$ operacija, a $x$ je $0$, $1$, ili $2$ u zavisnosti od toga koliko još možemo da "dodajemo" na naš izabran put. Drugim rečima, ako je izabran put trenutnog podstabla samo čvor $u$, onda na njega možemo dodati puteve koji dolaze iz dva različita sina, pa je $x = 0$.  Ako se izabran put trenutnog podstabla završava u $u$, onda je $x=1$, a ako je put već u potpunosti izabran i ne dodajemo mu ništa, onda je $x=2$.
	
	$dp[u][k][x]$ se nalazi dinamičkim programiranjem po stablu: iteriramo kroz sinove, neka je trenutni sin $v$. U $dp[u]$ imamo izračunat $dp$ za podstablo od $u$, a u $dp[u]$ imamo izračunat $dp$ za stablo sačinjeno od $u$ i podstabala svih sinova kroz koje smo do sada iterirali. Želimo da "spojimo" $dp$ vrednosti za $u$ i $v$, pa da u $dp[u]$ posle bude izračunat $dp$ za stablo kome je dodato i podstablo od $v$.
	
	Spajanje $dp$-ova dva stabla se može uraditi u $O(N^2)$: iteriramo kroz broj grana koje ćemo brisati u prvom stablu ($i$), nakon toga kroz broj grana koje brišemo u drugom ($j$), i u neki novi $dp$ niz ažuriramo vrednosti za $i + j$ ili $i +j +1$ izbrisanih grana (u zavisnosti od toga da li brišemo granu od $u$ do $v$). Postoji nekoliko slučajeva: da brišemo granu od $u$ do $v$ i dodajemo dužine njihovih izabranih puteva,  da ne brišemo granu od $u$ do $v$ već na put koji se završava u $u$ dodajemo put koji se završava u $v$, ili da ne brišemo granu ali da izaberemo samo jedan od dva izabrana puta podstabala $u$ i $v$.
	
	Krajnje rešenje će biti $max(dp[1][K][0], dp[1][K][1], dp[1][K][2]) + K$. Ako razmatramo da svako stanje u $dp[u][k][0]$ pripada i $dp[u][k][1]$, i da svako stanje u $dp[u][k][1]$ pripada i $dp[u][k][2]$ (što značajno olakšava implementaciju), rešenje je $dp[1][K][2] + K$.
	
	Vremenska složenost: $O(TN^3)$
	
	## Glavno rešenje
	Glavno rešenje je isto kao za treći podzadatak, samo što tokom spajanja podstabala ne iteriramo kroz vrednosti koje su sigurno nemoguće. Drugim rečima, za sina ($v$) ćemo samo iterirati do veličine njegovog podstabla, a za koren podstabla ($u$) ćemo samo iterirati do veličine trenutnog stabla koje njegov $dp$ predstavlja (jer je nemoguće izbrisati više grana od toga).
	
	Nije teško dokazati da složenost algoritma sada postaje $O(N^2)$. Kada spajamo $dp$-ove dva stabla, iteriramo do njihovih veličina - što možemo predstaviti kao da se svaki čvor koji pripada prvom stablu uparuje sa svakim iz drugog. Pošto će nakon toga svi ti čvorovi pripadati istom stablu, možemo primetiti da će svaka dva čvora da se upare tačno jednom - što daje ukupno $O(N^2)$ uparivanja.
	
	Vremenska složenost: $O(TN^2)$
	
	**Bonus**: Rešite zadatak u $O(TNlogN)$.
	
	``` cpp title="05_bekstvo.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 3005
	using namespace std;
	int t;
	int n,k;
	vector<int> a[maxn];
	int dp[maxn][maxn][3];
	int gp[maxn][3];
	int sz[maxn];
	void dfs(int u,int pr=-1) {
	    sz[u]=1;
	    dp[u][0][0]=dp[u][0][1]=dp[u][0][2]=0;
	    dp[u][1][0]=-1e9;
	    dp[u][1][1]=0;
	    dp[u][1][2]=0;
	    for(auto v:a[u]) {
	        if(v!=pr) {
	            dfs(v,u);
	
	            for(int i=sz[u]+1;i<=sz[u]+sz[v] && i<=k+1;i++) {
	                dp[u][i][0]=dp[u][i][1]=dp[u][i][2]=0;
	            }
	            dp[u][sz[u]+sz[v]][0]=-1e9;
	            for(int i=0;i<=sz[u]+sz[v] && i<=k+1;i++) {
	                gp[i][0]=gp[i][1]=gp[i][2]=0;
	            }
	            gp[sz[u]+sz[v]][0]=-1e9;
	
	            for(int i=0;i<=sz[u] && i<=k+1;i++) {
	                for(int j=0;j<=sz[v] && i+j<=k+1;j++) {
	                    gp[i+j][0]=max(gp[i+j][0],dp[u][i][0]+dp[v][j][2]);
	                    if(i) {
	                        gp[i+j][1]=max(gp[i+j][1],dp[u][i][1]+dp[v][j][2]);
	                    }
	                    if(j) {
	                        gp[i+j][1]=max(gp[i+j][1],dp[u][i][0]+dp[v][j][1]+1);
	                    }
	                    if(i>0 && j>0) {
	                        gp[i+j-1][2]=max(gp[i+j-1][2],dp[u][i][1]+dp[v][j][1]+1);
	                    }
	                    gp[i+j][2]=max(gp[i+j][2],dp[u][i][2]+dp[v][j][2]);
	                }
	            }
	
	            for(int i=0;i<=sz[u]+sz[v] && i<=k+1;i++) {
	                for(int j=0;j<=2;j++) {
	                    dp[u][i][j]=max(dp[u][i][j],gp[i][j]);
	                }
	            }
	
	
	            sz[u]+=sz[v];
	
	        }
	    }
	    for(int i=0;i<=sz[u];i++) {
	        dp[u][i][2]=max(dp[u][i][0],max(dp[u][i][1],dp[u][i][2]));
	    }
	    /*cout<<u<<" "<<sz[u]<<endl;
	    for(int i=0;i<=sz[u];i++) {
	        cout<<"dp["<<u<<"]["<<i<<"][0]="<<dp[u][i][0]<<", "<<"dp["<<u<<"]["<<i<<"][1]="<<dp[u][i][1]<<", "<<"dp["<<u<<"]["<<i<<"][2]="<<dp[u][i][2]<<", "<<endl;
	    }*/
	}
	int main() {
	
	    scanf("%d",&t);
	    while(t--) {
	        scanf("%d %d",&n,&k);
	        k=min(k+1,n);
	        for(int i=0;i<n-1;i++) {
	            int u,v;
	            scanf("%d %d",&u,&v);
	            a[u].push_back(v);
	            a[v].push_back(u);
	        }
	
	        dfs(1);
	
	        int ans=0;
	        for(int i=0;i<=k;i++) {
	            for(int j=0;j<=2;j++) {
	                ans=max(ans,dp[1][i][j]+max(i-1,0));
	            }
	        }
	
	        printf("%d\n",ans);
	
	        for(int i=1;i<=n;i++) a[i].clear();
	    }
	    return 0;
	}

	```
