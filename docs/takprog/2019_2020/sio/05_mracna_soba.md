---
hide:
  - toc
---

# 5 - Mračna soba

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 64MB |
	
	Nekada, ne toliko davno, na jednom fakultetu ne toliko daleko, čuveni Isidor je uslikao poveći broj slika svojom "MST"-kamerom. Međutim, on sada ima želju da te fotografije sam razvije, a za to mu je potrebno da prostor bude taman (sa akcentom na prvo a). Da bi to uradio, ogradiće neki deo svoje dnevne sobe i u njemu će isključiti sva svetla i baciti se na posao.
	
	Isidorova dnevna soba se može zamisliti kao matrica $N\times M$, i ima pomalo neobičan raspored  lampi i prekidača u njoj. Naime, u svakom polju te matrice se nalazi po jedna lampa, koja je na početku ili isključena ili uključena, što znači da ima ukupno $M\cdot N$ lampi. On takođe ima $(M-1)\cdot (N-1)$ prekidača koji se nalaze u tačkama preseka linija koje određuju matricu, i oni menjaju stanje lampama u svim poljima u čijem su ćošku. Formalnije, za svako $1\le i\le N-1$ i $1\le j\le M-1$ postoji prekidač koji menja stanja (isključeno u uključeno, i obrnuto) lampama $(i,j), (i+1,j), (i,j+1), (i+1,j+1)$. Isidor će ograditi jednu podmatricu kao svoju sobu za razvijanje slika.
	
	Isidor kaže da je podmatrica mračna soba ukoliko je moguće da posle ograđivanja koristeći prekidače **strogo unutar** te sobe načini da su sve lampe u sobi isključene. Ovo znači da ne sme da dira prekidače koji menjaju stanje lampama van ograđene podmatrice. On je to već odavno uradio i već uveliko razvija fotografije, ali ga ipak interesuje tačan broj načina na koji je mogao da ogradi takvu podmatricu.
	
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Prebroj(N, M, A[\ldots][\ldots])$
	
	gde su $M$ i $N$ brojevi koji predstavljaju broj kolona i vrsta u $A$, a $A$ je matrica u čijem polju $(i,j)$ piše broj $0$ ukoliko je lampa na polju $(i,j)$ početku isključena, a $1$ ukoliko je na početku uključena. **Indeksi matrice počinju od 1.**
	## Primer
	
	Neka je $N=2$, $M=3$ i neka je $A$:
	```
	0 1 1
	0 1 1
	```
	Tada je ukupan broj mračnih soba $5$, i to su sobe
	- Samo polje $(1,1)$
	- Samo polje $(2,1)$
	- Podmatrica od polja $(1,1)$ i $(2,1)$
	- Podmatrica od polja $(1,2)$, $(2,2)$, $(1,3)$ i $(2,3)$
	- Cela matrica
	
	Prve tri već na početku imaju sve ugašene lampe, dok za druge dve je moguće aktivitirati prekidač koji menja stanje lampama na poljima $(1,2)$, $(2,2)$, $(1,3)$ i $(2,3)$.
	
	## Ograničenja
	
	-   $1 \leq N,M \leq 500$
	-   $0 \leq A_i \leq 1$
	## Podzadaci
	Test primeri su podeljeni u $7$ podzadatka:
	
	-   **[4 poena]:** $N=1$
	-   **[7 poena]:** $N=2$
	-   **[6 poena]:** $N,M\leq5$
	-   **[12 poena]:** $N,M\leq50$
	-   **[16 poena]:** $N,M\leq100$
	-   **[29 poena]:** $N,M\leq300$
	-   **[26 poena]:** Nema dodatnih ograničenja
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `mracna_soba.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`long long Prebroj(int N, int M, int** A);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N, M$,
	* U narednih $N$ redova po $M$ brojeva. U $i$-tom redu nalaze se brojevi $A_{i,1}, A_{i,2}, \ldots, A_{i,M}$
	
	Zatim ovaj program zove vašu funkciju i štampa broj koji vrati funkcija.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |
	
	
	U ovom zadatku je potrebno izbrojati sve podmatrice date matrice jedinica i nula koje imaju svojstvo mračne sobe. Matrica ima svojstvo mračne sobe je da nizom poteza gde u svakom potezu uzmemo $2\times2$ podmatricu i promenimo svaki broj u njoj, možemo da dovedemo da ona sadrži samo nule. 
	
	## Podzadatak 1: $N=1$
	U ovom podzadatku, kakvu god pod podmatricu izabrao, nije moguće izvršiti nijedan potez, pa je dovoljno samo naći koliko ima podmatrica sa svim nulama. Ovo se lako implementira.
	
	## Podzadatak 3: $N,M\leq5$
	Da bi se rešio ovaj podzadatak,  potrebno je primetiti da ako rešenje postoji, postoji i rešenje gde se svaka $2\times2$ podmatrica aktivira najviše jednom. Ovo važi, jer ako neku $2\times2$ podmatricu aktiviramo dvaput, postižemo isti efekat kao da nismo nijednom. Sada kada znamo ovo, možemo proveriti svaku podmatricu u $O(MN\cdot2^{(M-1)(N-1)})$, proveravajući sve moguće kombinacije aktiviranih $2\times2$ podmatrica. Ovime nalazimo rešenje u $O(M^2N^2\cdot2^{(M-1)(N-1)})$.
	
	## Podzadatak 2: $N=2$
	U ovom podzadatku ćemo već dobiti osećaj kako treba da izgleda mračna soba. Na početku možemo da rešimo slučaj $N=1$ za obe vrste, kao u prvom podzadatku i sada nam ostaju još samo podmatice koje sadrže obe vrste. Očigledno da bi matrica $2\times P$ bila mračna soba, ne smemo imati nijednu kolonu sa različitim brojevima, jer će oni ostati različiti i kroz poteze. Stoga možemo te podmatrice koje preostaju da gledamo kao niz dužine $P$ sa jedinicama i nulama, gde u jednom potezu menjamo dva uzastopna broja. 
	
	Primetimo da operacijama menjamo broj jedinica za $-2,0$ ili $2$. Iz ovoga zaključujemo da se parnost broja jedinica ne menja kroz operacije, što znači da nam niz mora imati parno mnogo jedinica da bi odgovarao mračnoj sobi. Ovo je i dovoljan uslov i to možemo dokazati sledećim algoritmom: idemo redom po svim parovima uzastopnih i ukoliko je prvi broj jedan aktiviramo taj par u suprotnom ne aktiviramo. Indukcijom se lako pokaže da kad završimo prvih $k$ parova, prvih $k$ brojeva u nizu će biti $0$. Na kraju znamo da će nam svi članovi niza, osim možda poslednjeg, biti $0$. Međutim kako se parnost broja jedinica nije menjala kroz operacije, ako smo na početku imali parno mnogo jedinica, poslednji član isto mora biti $0$ jer bi u suprotnom imali tačno jednu jedinicu, što je neparan broj jedinica.
	
	Kada smo našli uslov, samo rešenje se trivijalno implementira.
	
	## Kako izgleda mračna soba?
	Sada ćemo nadograditi dokaz iz prethodnog dela na potreban i dovoljan uslov da je matrica mračna soba za svaku matricu. Ispostavlja se da je potreban i dovoljan uslov da u svakoj vrsti i svakoj koloni ima paran broj jedinica. 
	
	Dokaz da je potreban uslov je jako sličan dokazu maločas. U jednom potezu u svakoj vrsti i svakoj koloni promenimo broj jedinica za $-2,0$ ili $2$, a na kraju treba da ih je $0$ u svakoj koloni i vrsti. 
	
	Dokaz da je ovo dovoljan uslov prati sličan šablon kao prethodni takođe, ali je malo komplikovaniji. Naime, prolazićemo kroz sve $2\times2$ redom, krenuvši od gornjeg-levog ugla i idući redom po kolonama pa po vrstama (obradićemo prvo celu jednu kolonu, pa sledeću kolonu itd). U svakom trenutku ćemo gledati da li je gornje-levo polje naše matrice $2\times2$ i aktivirati matricu ako i samo ako je na tom polju jedinica. Opet se indukcijom relativno lako može dokazati da ćemo imati nule na svim pozicijama koje nisu poslednja vrsta ili poslednja vrsta. Međutim, jer znamo da su u svakom redu i svakoj vrsti broj jedinica paran, možemo da zaključimo da su i na ovim poljima nule, čime smo završili dokaz. 
	
	## Podzadatak 4:  $N,M\leq50$
	Sada kada smo dokazali prethodno tvrđenje rešenje u $O(M^3N^3)$ se prirodno nameće, gde svaku matricu prođemo i vidimo jel ispunjava uslov. S obzirom na malu konstantu ovog rešenja, ono je dovoljno brzo za ovaj podzadatak.
	
	## Podzadatak 5:  $N,M\leq100$
	Optimizacija na $O(M^2N^2(M+N))$ nije teška. Dovoljno je ubrzati proveru matrice $X\times Y$ iz $O(XY)$ u $O(X+Y)$. Ovo je moguće uraditi pamćenjem prefiksnih suma u svakom redu i svakoj koloni i onda vršeći proveru za svaku vrstu/kolonu u $O(1)$ oduzimajući dve parcijalne sume. Opet zbog male konstante ovo rešenje je dovolljno brzo za ovaj podzadatak.
	
	## Podzadatak 6:  $N,M\leq 300$
	Jedan način da se ovaj podzadatak reši je da se prethodni podzadatak ubrza pomoću "std::bitset". Alternativni način je da fiksiramo gornju i donju vrstu matrice koje ćemo da brojimo. Možemo kao iz prethodnog podzadatka u $O(1)$ da odredimo koje kolone su dobre i da to podelimo u klase uzastopnih dobrih kolona. Da bi sve vrste između njih bile dobre treba da kada sračunamo prefiksne sume po modulu $2$ treba da daju isti niz. Ovo u suštini znači kad zamenimo matricu prefiksnim sumama po modulu $2$ treba da nam se ram poklapa. Da bismo videli da li se levi i desni deo rama poklapaju brzo, moguće je koristiti heš koji se unapred izračuna. Sada za svaki mogući heš treba videti kolko ga ima da okdgovara nekom datom bloku uzastopnih dobrih kolona. Sada ako za neki blok dobrih uzastopnih imamo $X$ njih koji imaju dati heš, treba na reultat da dodamo $\binom{X}{2}$. Da bismo ovo uradili potrebno je heševe podeliti u skupove istih, što je najlakše sortom u $O(N\log N)$. Ovo nam daje $O(N^3\log N)$ rešenje.
	
	## Podzadatak 7:  $N,M\leq 500$
	Rešenje za ovaj podzatak je sličan prethodnom, sa jednom ključnom optimizacijom. Naime, podelu kolona u skupove koju smo ranije radili hešom i sortiranjem, ćemo raditi strukturom podataka "trie". Fiksiraćemo samo donju vrstu, dok ćemo gornju pomerati nagore za jedan po jedan, i sve iz jednog skupa istih prefiksnih suma propagiramo niz "trie" razdvajajući ih u $1$ ili $2$ skupa. Ovo je dosta slično sortiranju nizova putem "radix-sort". Ovako ubrzavamo rešenje na $O(N^3)$, što je dovoljno brzo za $100$ poena.
	
	``` cpp title="05_mracna_soba.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 507
	using namespace std;
	int v[MAXN][MAXN],h[MAXN][MAXN],nz[MAXN];
	vector<int> w[2][MAXN];
	long long cl[MAXN];
	long long Prebroj(int N, int M, int** A)
	{
		long long sol=0;
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) h[i][j]=h[i][j-1]^A[i][j];
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) v[i][j]=v[i-1][j]^A[i][j];
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++) w[0][j].clear();
			for(int j=0;j<M;j++) w[1][j].clear();
			for(int j=0;j<=M;j++) w[0][0].push_back(j);
			int t=0,cc=1,cp;
			for(int k=i-1;k>=0;k--)
			{
				cp=cc; cc=0;
				for(int j=0;j<cp;j++)
				{
					if(w[t][j].size()==1) {w[t][j].clear(); continue;}
					bool z[2]={false,false};
					for(int x=0;x<w[t][j].size();x++) z[h[k+1][w[t][j][x]]]=true;
					for(int y=0;y<2;y++) if(z[y]) 
					{
						for(int x=0;x<w[t][j].size();x++) if(h[k+1][w[t][j][x]]==y) w[t^1][cc].push_back(w[t][j][x]);	
						cc++;
					}
					w[t][j].clear();
				} 
				t^=1;
				int p=-1;
				nz[0]=-1;
				for(int j=1;j<=M;j++)
				{
					if(v[i][j]!=v[k][j]) p=-1;
					else if(p==-1) p=j;
					nz[j]=p;
				}
				for(int j=1;j<=M;j++) cl[j]=0;
				for(int j=0;j<cc;j++) 
				{
					for(int x=0;x<w[t][j].size();x++) 
					{
						if(nz[w[t][j][x]]!=-1) sol+=cl[nz[w[t][j][x]]];
						if(nz[w[t][j][x]+1]!=-1) cl[nz[w[t][j][x]+1]]++;
					}
					for(int x=0;x<w[t][j].size();x++) if(nz[w[t][j][x]+1]!=-1) cl[nz[w[t][j][x]+1]]--;
				}
			}
		}
		return sol;
	}

	```
