---
hide:
  - toc
---

# A1 - Život u gradu

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	> *(Život u gradu) Znaš da moraš da preživiš 
	> (Život u gradu) Moraš da održiš taj san živim 
	> (Život u gradu) Gde sve je besplatno 
	> (Život u gradu) Zar ne možeš da vidiš* 
	
	Gore je naveden autorov slobodni prevod teksta pesme "Život u gradu", koja je izvorno pesma za drugi nivo, "Radikalni grad", u igrici Sonik R iz 1997. Muzičke kritičare i analitičare širom sveta je godinama bunilo tačno značenje reči. Međutim, danas je dan kada se konačno otkriva šta se krilo iza ovih vešto napisanih stihova - pesma se odnosi na državno takmičenje iz informatike srednjih škola 2023. godine nove ere. Zaista, navedeni grad se očigledno odnosi na Kragujevac, preživljavanje na izbegavanje bučnih Kragujevačkih koncerta, san je ništa drugo nego 300 poena na takmičenju, dok je interpretacija šta je tačno to sve besplatno, i čin opažanja istog jednostavna i ostavlja se kao vežba čitaocu.
	
	Postavka je sledeća. Takmičari dolaze u Kragujevac, na državno takmičenje. Kao što to često biva sa gradovima u informatičkim zadacima, Kragujevac može zamisliti kao matricu dimenzija $N\times M$ . Takmičari ulaze u grad na polje $(1,1)$, dok se takmičenje održava u polju $(N,M)$. Kako takmičenje uskoro kreće, nema vremena za gubljenje, tako da takmičari moraju da stignu do takmičenja tako što u svakom potezu pređu na polje direktno desno ili direktno ispod trenutnog. 
	
	Međutim, u nekim poljima se održavaju koncerti. Mnogi bi savetovali mladim takmičarima da se klone ovih polja, ali kako je ovo prvo takmičenje iz informatike van Beograda u ko zna koliko vremena, oni su odlučili da moraju da iskuse svaki deo lokalne kulture i samim tim posete tačno $K$ polja sa koncertima. Vaš cilj je da vašim kolegama takmičarima kažete da li je ovo moguće i (u nekim podzadacima), ukoliko jeste, date primer takvog puta.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalaze se dva cela broja $T$, broj test primera i $Z$ koji je jednak nula ukoliko dati test primer ne zahteva rekonstrukciju, a $1$ ukoliko zahteva. Svaki test primer je sledećeg formata: U prvom redu nalaze se $3$ cela broja $N$, $M$ i $K$. U $i$-tom od narednih $N$ redova se po $M$ celih brojeva, gde je $j$-ti jednak $1$ ukoliko se održava koncert na polju $(i,j)$, a jednak $0$ u suprotnom.
	
	## Opis izlaza
	Za svaki od $T$ test primera je potrebno u prvom redu ispisati "DA" (bez navodnika), ukoliko je moguće ispuniti uslove zadatka, a "NE" (bez navodnika) ukoliko nije. Dalje, ukoliko je $Z=1$ i odogvor je bio "DA", potrebno je ispisati nisku od $M+N-2$ karatkera, gde je $i$-ti karakter $S$ ukoliko takmičari treba da idu na dole, a ukoliko treba da idu desno, karatker treba da bude $D$. Ukoliko postoji više rešenja ispisati bilo koje.
	
	## Primer 1
	### Ulaz
	```
	3 1
	3 3 1
	000
	000
	100
	3 3 2
	001
	010
	100
	3 4 0
	0011
	1000
	1100
	```
	
	### Izlaz
	```
	DA
	SSDD
	NE
	DA
	DSDDS
	```
	## Objašnjenje primera
	U prvom primeru se održava samo jedan koncert u Kragujevcu, i to u donjem levom uglu. Da bi ga takmičari posetili, moraju prva dva poteza da idu na dole, a zatim da produže do mesta takmičenja sa 2 poteza desno (kako je $Z=1$ potrebno je ispisati i konstrukciju puta). U drugom ne postoji način da posete dve koncerta, pa je odgovor "NE".
	
	## Ograničenja
	- $1 \leq T \leq 10$.
	- $1 \leq N,M \leq 1.500$.
	- $0 \leq K \leq 3.000$.
	
	Test primeri su podeljeni u osam disjunktnih grupa:
	
	- U test primerima vrednim $8$ poena, $N,M\leq 10$.
	- U test primerima vrednim $6$ poena, sva polja sa koncertima formiraju podmatricu i $Z=0$.
	- U test primerima vrednim $10$ poena, sva polja sa koncertima formiraju podmatricu.
	- U test primerima vrednim $13$ poena, $N,M\leq 150$, $Z=0$.
	- U test primerima vrednim $13$ poena, $N,M\leq 150$.
	- U test primerima vrednim $11$ poena, $K=0$.
	- U test primerima vrednim $20$ poena, $Z=0$.
	- U test primerima vrednim $19$ poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Dragan Urošević | Aleksa Milisavljević |
	
	## Rešenje prvog podzadatka
	U ovom slučaju, zbog ograničenja na dužinu veličinu table moguće je u datom vremenskom ograničenju proveriti sve puteve i odrediti za svaki od njih koliko se koncerta održava na tom putu. Naime broj raznih putvea je $2^{N+M-2}\leq 2^{18}$. Naravno, ako je na nekom putu broj koncerta baš $K$, prekida se proveravanje puteva, ispisuje odgovor  "DA" i ako je potrebno ispisuje odgovarajući put. Ako ni na jednom putu nije bilo $K$ koncerta, ispisuje se odgovor "NE". Složenost opisanog rešenja je ${\mathcal O}(2^{N+M})$.
	
	## Rešenje drugog i trećeg podzadatka
	 Za početak je potrebno odrediti podmatricu koju čine polja na kojima se održavaju koncerti. Nakon toga treba diskutovati (razlikovati) nekoliko slučajeva, u zavisnosti od dimenzija i pozicije podmatrice i broja $K$. Mislimo da nema potrebe da izvodimo kompletnu diskusiju. Složenost opisanog rešenja je ${\mathcal O}(NM)$.
	
	## Rešenje četvrtog i petog podzadatka
	Ovi podzadaci se mogu rešiti primenom dinamičkog programiranja. Neka je $dp[i][j][l]=true$, ako postoji put od polja $(1,1)$ do polja $(i,j)$ na kome postoji $l$ polja na kojima se održava koncert i $dp[i][j][l]=false$ u suprotnom. Tada je $dp[N][M][K]$ odgovor na pitanje da li postoji traženi put ili ne. Niz $dp$ popunjavama (računamo) vrsta po vrsta:
	
	- $dp[1][1][1]=true$, ako se na polju $(1,1)$ održava koncert i $dp[1][1][1]=false$, ako se na polju $(1,1)$ ne održava koncert.
	- $dp[1][1][0]=true$, ako se na polju $(1,1)$ ne održava koncert i $dp[1][1][0]=false$, ako se na polju $(1,1)$ održava koncert.
	- $dp[1][1][l]=false$, za $2\leq l \leq K$.
	- Ako se na polju $(i,j)$  održava koncert, onda je $dp[i][j][l]=true$, ako i samo ako je $dp[i-1][j][l-1]=true$ ili $dp[i][j-1][l-1]=true$ (naravno, ako je $i \geq 2$ i $j \geq 2$, u suprotnom, odgovarajući element ne postoji). Primetimo takođe da je u ovom slučaju $dp[i][j][0]=false$.
	- Ako se na polju $(i,j)$  ne održava koncert, onda je $dp[i][j][l]=true$, ako i samo ako je $dp[i-1][j][l]=true$ ili $dp[i][j-1][l]=true$ (naravno, ako je $i \geq 2$ i $j \geq 2$, u suprotnom, odgovarajući element ne postoji).
	
	 Ako traženi put postoji, on se može rekonstrisati korišćenjem niza  $dp$. Naime, krećemo od polja $(N,M)$ i tražimo put na kome se održava $K$ koncerta. Ako se nalazimo na polju $(i,j)$ i tražimo put na kome se održava $l$ koncerta, onda mora biti $dp[i][j][l]=true$ i mogu nastupiti sledeća dva slučaja:
	
	- Na polju $(i,j)$ se odžava koncert. Tada broj koncerata smanjujemo za jedan, tj. $l$ se smanjuje za jedan ($l \leftarrow l-1$) i pomeramo se na polje levo ili gore (ako postoji) za koje odgovarajući element niza $dp$ ($dp[i-1][j][l-1]$ ili $dp[i][j-1][l-1]$) ima vrednost $true$.
	- Na polju $(i,j)$ se ne odžava koncerta. Tada broj kocerta ostaje nepromenjen, a pomeramo se na polje levo ili gore (ako postoji) za koje odgovarajući element niza $dp$ ($dp[i-1][j][l]$ ili $dp[i][j-1][l]$) ima vrednost $true$.
	- Postupak prekidamo kada stignemo do polja $(1,1)$.
	
	Složenost opisanog rešenja je određena složenošću popunjavanja niza $dp$ i iznosi ${\mathcal O}(NMK)$.
	
	## Rešenje šestog podzadatka
	U ovom slučaju možemo formirati graf u kome su čvorovi polja na koja je podeljen grad, a ivice postoje od polja do njegovih suseda levo i dole. Polja na kojima se održavaju koncerti su zabranjena i na njih se ne može stati. Traženi put postoji, ako postoji put u grafu (put zaobilazi zabranjena polja). Taj put možeo pronaći, na primer, primenom obilaska u širinu. Za svako polje možemo pamtiti odakle smo stigli i na taj način rekonstruisati rešenje. Složenost opisanog rešenja je  ${\mathcal O}(NM)$.
	
	## Glavno rešenje
	Neka je $dp_1[i][j]$ minimalni broj $l$ takav da postoji put od polja $(1,1)$ do polja $(i,j)$, na kome se održava $l$ koncerata. Neka je $dp_2[i][j]$ maksimalni broj $l$ takav da postoji put od polja $(1,1)$ do polja $(i,j)$, na kome se održava $l$ koncerata. Tada za svako polje $(i,j)$ važi da postoji put od polja $(1,1)$ do polja $(i,j)$ na kome se održava $l$ koncerta, gde je $l$ bilo koji broj između $dp_1[i][j]$ i $dp_2[i][j]$  ($dp_1[i][j]\leq l  \leq dp_2[i][j]$). Naime od bilo kog početnog puta između dva polja se može stići do bilo kog završnog, tako što se prelazi preko niza puteva od kojih se svaka dva uzastopna razlikuju u samo jednom polju. Kada se na putu promeni samo jedno polje i broj polja na kojima se održava koncert se može promeniti (smanjiti ili povećati) za najviše jedan (1). Ako krenemo od puta sa minimalnim brojem koncerta prema putu sa maksimalnim brojem koncerta, proći ćemo preko puteva na kojima je broj koncerta bilo koji broj između ta dva broja. 
	Zbog toga, postoji put sa tačno $K$ koncerata, ako i samo ako je $dp_1[N][M]\leq K  \leq dp_2[N][M]$.
	Nizove $dp_1$ i $dp_2$ računamo na sličan način kao niz $dp$ u četvrtom i petom podzadatku:
	
	- Ako se na polju $(1,1)$ održava koncert, onda je $dp_1[1][1]=dp_2[1][1]=1$.
	- Ako se na polju $(1,1)$ ne održava koncert, onda je $dp_1[1][1]=dp_2[1][1]=0$.
	- Ako se na polju $(i,j)$ održava koncert, onda je $dp_1[i][j]=\min(dp_1[i-1][j],dp_1[i][j-1])+1$ i $dp_2[i][j]=\max(dp_2[i-1][j],dp_2[i][j-1])+1$.
	- Ako se na polju $(i,j)$ ne održava koncert, onda je $dp_1[i][j]=\min(dp_1[i-1][j],dp_1[i][j-1])$ i $dp_2[i][j]=\max(dp_2[i-1][j],dp_2[i][j-1])$.
	
	Ako postoji put sa tačno $K$ koncerata, onda se on rekonstruiše tako što se krene od polja $(N,M)$ i traži put koji ima $l=K$ koncerata. Ako se nalazimo na polju $(i,j)$ i tražimo put koji ima $l$ koncerata ($dp_1[i][j]\leq l \leq dp_2[i][j]$), onda mogu nastupiti dva slučaja:
	
	- Ako se na polju $(i,j)$ održava koncert, onda treba smanjiti broj koncerata $l$ za jedan i preći na polje iznad ili polje levo, tako da broj koncerata bude između $dp_1$ i $dp_2$ za to novo polje.
	- Ako se na polju $(i,j)$ ne održava koncert, onda se broj koncerata $l$ ne menja, a treba preći na polje iznad ili polje levo, tako da broj koncerata bude između $dp_1$ i $dp_2$ za to novo polje.
	- Postupak prekidamo kada stignemo do polja $(1,1)$.
	
	Složenost opisanog rešenja je određena složenošću popunjavanja nizova $dp_1$ i $dp_2$ i iznosi ${\mathcal O}(NM)$.
	
	``` cpp title="04_zivot_u_gradu.cpp" linenums="1"
	#include <bits\stdc++.h>
	#define MAXN 3007
	using namespace std;
	const string folder="testcases\\";
	int a[MAXN][MAXN],dp[2][MAXN][MAXN];
	int main()
	{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    int t,z;
	    for(int i=0;i<MAXN;i++) dp[0][0][i]=dp[0][i][0]=1000000000;
	    cin>>t>>z;
	    while(t--)
	    {
	        int n,m,k;
	        cin>>n>>m>>k;
	        for(int i=1;i<=n;i++)
	        {
	            string s;
	            cin>>s;
	            for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	        }
	        dp[0][1][1]=dp[1][1][1]=a[1][1];
	        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	        {
	            if(i==1 && j==1) continue;
	            dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
	            dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1])+a[i][j];
	        }
	        if(k<dp[0][n][m] || k>dp[1][n][m]) {cout<<"NE"<<endl; continue;}
	        cout<<"DA\n";
	        if(!z) continue;
	        int x=n,y=m,cur=k;
	        string res="";
	        while(x!=1 || y!=1)
	        {
	            assert(cur>=dp[0][x][y] && cur<=dp[1][x][y]);
	            cur-=a[x][y];
	            if(cur>=dp[0][x-1][y] && cur<=dp[1][x-1][y]) {x--; res+='S';}
	            else {y--; res+='D';}
	        }
	        reverse(res.begin(),res.end());
	        cout<<res<<endl;
	    }
	}

	```
