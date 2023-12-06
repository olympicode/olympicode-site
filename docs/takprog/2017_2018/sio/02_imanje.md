---
hide:
  - toc
---

# 2 - Imanje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| - | - |
	
	Deda Vido, poljoprivrednik iz sela u okolini Novog Pazara, već duži niz godina održava svoje imanje. Imanje se može predstaviti kao matrica dimenzija $N \times M$, gde jedno polje u matrici označava $1$ metar kvadratni imanja. Vidovo zemljište je malo močvarno, tako da svako polje u matrici može sadržati zemlju ili vodu. Svi povezani delovi vode prave jedno jezero na imanju. Dva polja su povezana ako dele jednu stranicu u matrici. Primetimo da deda Vidovo imanje trenutno može sadržati više odvojenih jezera.
	
	Danas u goste dolazi njegov unuk Lale koji mnogo voli da peca. Lale je prilično nestašan i nikada se ne zadržava dugo na jednom jezeru. Kada obiđe sva jezera on se ponovo vraća u grad i ostavlja svog dedu usamljenog. 
	
	Deda Vido silno želi da zadrži unuka što duže na selu, tako da je nabavio dovoljno materijala da najviše $K$ metara kvadratnih ($K$ polja matrice) promeni iz vode u zemlju. Na ovaj način on bi pregradio neka od postojećih jezera i od jednog jezera dobio više njih.
	
	Vaš je zadatak da pomognete deda Vidu da rasporedi materijal tako da maksimizuje broj dobijenih jezera.
	
	## Napomena
	Ovo je zadatak sa poznatim ulazom (*output-only* zadatak). Vama su dati ulazni fajlovi (`01.in`, `02.in`, `03.in`, `04.in`, `05.in`), dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`01.out`, `02.out`, `03.out`, `04.out`,  `05.out`).
	
	## Opis ulaza
	U prvom redu ulaznih fajlova nalaze se tri prorodna broja  $N$, $M$ i $K$, dužina imanja, širina imanja, broj metara kvadratnih koje možemo promeniti iz vode u zemlju.
	U svakom od narednih $N$ redova nalazi se po $M$ karaktera. Svaki karakter u matrici može predstavljati zemlju ili vodu. Ako je karakter u preseku $i$-te vrste i $j$-te kolone `x` (bez navodnika) onda se na tom polju nalazi zemlja, u suportnom, karakter u preseku $i$-te vrste i $j$-te kolone je `.` (bez navodnika) i označava vodu.
	
	## Opis izlaza
	Svaki vaš izlazni fajl treba da sadrži matricu dimenzija $N \times M$. Svako polje u matrici može biti `x` (zemlja), `.` (voda), `o` (polje na kome se nalazila voda i sada je promenjeno u zemljište).
	
	## Primer 1
	### Ulaz
	```
	4 8 3
	.x...x..
	.x.x.x..
	.x...xxx
	.xxxxx..
	```
	
	### Izlaz
	```
	.x...x..
	.xoxox..
	ox...xxx
	.xxxxx..
	```
	
	### Objašnjenje primera
	Imanje je dimenzija  $4 \times 8$. Možemo promeniti najviše $3$ polja na kojima se nalazi voda u polja na kojima se nalazi zemlja. U početnom trenutku na imanju se nalazi $4$ jezera. Promenili smo polja sa koordinatama $(3, 1), (2, 3), (2, 5)$. Nakon navedenog pregrađivanja na imanju se nalazi $6$ jezera.
	
	## Napomena 1
	
	- Svi fajlovi moraju biti u opisanom formatu, u fajlovima se ne sme nalaziti nijedan karakter osim `x`, `.` i `o`.
	- U matrici se ne sme nalaziti više od $K$ karaktera `o`. 
	- Svaki karakter `o` mora nalaziti na polju gde se prethodno nalazio karakter `.`.
	- Ako se na nekom polju u finalnoj matrici nalazi karakter `x` ili karakter `.`, onda se na tom polju morao nalaziti isti karakter i u početnoj matrici.
	
	## Bodovanje
	Dato vam je pet ulaznih fajlova.
	
	- Prvi primer (`01.in`) vredi $10$ poena.
	- Drugi primer (`02.in`) vredi $20$ poena.
	- Treći primer (`03.in`) vredi $20$ poena. 
	- Četvrti primer (`04.in`) vredi $25$ poena.
	- Peti primer (`05.in`) vredi $25$ poena.
	
	Vaša rešenja se boduju u odnosu na rešenje komisije. Rešenje komisije će nositi $100$ poena. Za svaki procenat za koji vaše rešenje bude gore od komisijskog gubite $10$ poena sve do $0$ poena (to znači da rešenja koja budu gora od komisijskog za više od $10$% nose $0$ poena). Ako vaše rešenje za određen unos bude bolje od komisijskog dobićete $100$ poena.
	
	Rezultati komisije redom po fajlovima, u odnosu na koje se računa skor, su:
	
	- Prvi fajl $18$ jezera.
	- Drugi fajl $1091$ jezero.
	- Treći fajl $1009$ jezera.
	- Četvrti fajl $14566$ jezera.
	- Peti fajl $46103$ jezera.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Aleksa Plavšić | Aleksa Plavšić | Nikola Spasić |
	
	Kao i većina drugih _output only_ problema, ovaj zadatak zahteva detaljniju analizu priloženih fajlova i testiranje različitih rešenja na datim test primerima. Rešenje ne mora biti preterano vremenski i memorijski efikasno, jedino je važno da se program izvrši u nekom doglednom vremenu kako bi mogle da se testiraju i druge strategije. Osnovna ideja algoritma koji je koristila komisija je maksimizovanje broja jezera farbanjem jednog jezera (jedne povezane komponente vode) poput šahovske table. Na taj način od jednog jezera veličine $X$, dobićemo otprilike $\frac{X}{2}$ jezera, sa približno toliko utrošenog materijala. Pošto je očigledno da nećemo moći da prekrijemo sva jezera na ovaj način, nećemo imati dovoljno materijala, moramo na neki način da odredimo koja jezera su najoptimalnija za prekrivanje. Za rešavanje ovog podzadatka možemo koristiti dinamičko programiranje i problem ranca. Ranac bi imao ukupnu zapreminu $K$, predmeti su u ovom slučaju ekvivalentni jezerima, težine predmeta bi bile jednake broju polja koja moramo transformisati iz vode u zemlju da bi dobili šahovsku tablu, dok bi zarađeni novac bio ekvivalentan broju jezera koja smo dobili pregrađivanjem velike komponente. Nakon biranja nekih optimalnih komponenti i njihovog farbanja, proćićemo kroz sva ofarbana jezera još jednom i ukloniti polja koja su viškom promenjena. Može se desiti da neko polje nema potrebe pretvarati u zemlju, zato što je recimo već okruženo zemljom i uništili smo jedno jezero, na taj način malo rušimo izgled šahovske table ali je jasno da broj jezera ne smanjujemo i dobijamo dodatni materijal koji možemo iskoristiti.
	
	Postavlja se pitanje šta dodatno možemo odraditi sa preostalim materijalom, koji nismo iskoristili u prvom bojenju ili smo dodatno uklonili. Naravno i njega je potrebno raspodeliti na određena mesta. Strategija kojom smo se vodili u ovom slučaju je, pregrađivanje nekog od trenutnih jezera na dva jezera gde bi veličina drugog jezera bila $1 \times 1$. Ovde možemo zapamtiti za svako polje vode koliko je potrebno dodavanja zemlje da bi se ono ogradilo (taj broj može ići od $1$ do $4$). U svakom potezu ćemo birati jezero kome nedostaje najmanje polja da bude ograđeno(trebalo bi da se može lako pokazati da će uvek postojati vodeno polje kome neće nedostajati više od $2$ polja zemlje). 
	
	U priloženim materijalima imate još nekoliko strategija rešavanja ovog problema, treba obratiti pažnju na strategiju koja koristi _BFS_ u određivanju optimalnog rešenja. Ona je imala najbolje rezultate na nekim od primera, ali je poprilično spora i na rešenje se treba čekati i do $10$ minuta.
	
	Složenost opisanog algoritma je $O(k \times BrojJezera)$.
	
	## Smernice za algoritam
	
	Prvi deo bojenja jezera poput šahovske table možemo uraditi jednostavno korišćenjem zakonitosti da sva polja na šahovskoj tabli iste boje daju ujedno i isti ostatak pri deljenju sa dva njihovih koordinata - $(i+j) mod 2$. Važno je probati bojenje i parnih i neparnih polja i na neki način izabrati bolju od opcija. Deo sa dinamičkim programiranjem i rancem može biti vrlo memorijiski zahtevan, tako da se mora osmisliti pažljivo algoritam za uklanjanje jedne koordinate iz dinamičke matrice. Ideja koju smo koristili je računanje niza parova $DP[i]$, koji bi davao informaciju o maksimalnom rezultatu koji možemo dobiti ako smo ofarbali ne više od $i$ polja i iz kog stanja smo došli do ove pozicije. Druga vrednost nam pomaže oko dalje rekonstrukcije jezera za bojenje. Za poslednji deo i farbanje jezera može se koristiti neka od struktura koja bi pamtila polja sa tačno $i$ potrebnih ograđivanja, koja bi mogla lako da briše brojeve iz skupa i da ih ponovo ubacuje u drugi skup. Detanje implementacije možete videti u priloženim kodovima.
	
	Voleli bismo da čujemo i vaše ideje za ovaj zadatak, tako da budite slobodni i napišite ako vas je zainteresovao.
	
	``` cpp title="02_imanje.cpp" linenums="1"
	#include<bits/stdc++.h>
	
	using namespace std;
	
	
	//ranac po sahovnicama, onda greedy ograditi one koje ima najmanje da se ograde
	// officijalno resenje komisije(tj mene :P)
	
	const int ma=2e3+3;
	
	#define pb push_back
	
	int n,m,k;
	int a[ma][ma],ob[ma][ma];
	string s;
	int comp;
	int b[ma][ma];
	int total,neparne;
	vector<pair<pair<int,int>, int > >v;
	pair<int,int> dp[1000002],pre[1000002];
	map<pair<int,int>, pair<int,int> > mp;
	int k1;
	int koji[1000002];
	set<pair<int,int> > st[10];
	int cnt[ma][ma];
	int broj[1000002];
	
	int in_range(int x, int y)
	{
	    if (x>n || x<=0 || y>m || y<=0) return 0;
	    return 1;
	}
	void dfs(int x, int y)
	{
	    if (a[x][y]) return;
	    ob[x][y]=comp;
	    broj[comp]++;
	    total++;
	    if ((x+y)%2) neparne++;
	    if (in_range(x-1,y) && !ob[x-1][y]) dfs(x-1,y);
	    if (in_range(x+1,y) && !ob[x+1][y]) dfs(x+1,y);
	    if (in_range(x,y-1) && !ob[x][y-1]) dfs(x,y-1);
	    if (in_range(x,y+1) && !ob[x][y+1]) dfs(x,y+1);
	    return ;
	}
	void ocisti()
	{
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	        {
	            a[i][j]=b[i][j];
	            ob[i][j]=0;
	        }
	
	    comp=0;
	    k=k1;
	}
	
	void ispisi()
	{
	    freopen("imanje-04.out","w",stdout);
	    for (int i=1; i<=n; i++)
	    {
	        for (int j=1; j<=m; j++)
	            if (a[i][j]==2) printf("o");
	            else if (a[i][j]==1) printf("x");
	            else
	                printf(".");
	        printf("\n");
	
	    }
	
	    fclose(stdout);
	}
	
	int okolo(int x, int y)
	{
	    if (x>1 && !a[x-1][y]) return 1;
	    if (x<n && !a[x+1][y]) return 1;
	    if (y>1 && !a[x][y-1]) return 1;
	    if (y<m && !a[x][y+1]) return 1;
	    return 0;
	}
	void update(int x, int y)
	{
	    st[cnt[x][y]].erase( {x,y});
	    cnt[x][y]++;
	    st[cnt[x][y]].insert( {x,y});
	    return;
	}
	void ogradi(int xi, int yi)
	{
	    if (cnt[xi][yi]==3) return;
	    a[xi][yi]=2;
	    k--;
	
	    st[cnt[xi][yi]].erase( {xi,yi});
	
	    if (!a[xi][yi-1]) update(xi,yi-1);
	    if (!a[xi][yi+1]) update(xi,yi+1);
	    if (!a[xi-1][yi]) update(xi-1,yi);
	    if (!a[xi+1][yi]) update(xi+1,yi);
	
	    return;
	}
	
	int main()
	{
	
	    freopen("imanje-04.in","r",stdin);
	    scanf("%d%d%d",&n,&m,&k);
	    k1=k;
	
	
	       for (int i=1; i<=n; i++)
	    {
	        cin>>s;
	        for (int j=1; j<=m; j++)
	            if (s[j-1]=='.') b[i][j]=0;
	            else
	                b[i][j]=1;
	    }
	
	    fclose(stdin);
	
	    ocisti();
	
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	            if (ob[i][j]==0 && !a[i][j])
	            {
	                comp++;
	                total=0;
	                neparne=0;
	                dfs(i,j);
	                if (neparne>0 && total-neparne>0)
	                {
	                    if (total-neparne>neparne)
	                    {
	                        v.pb( {{total-neparne,neparne},comp});
	                        koji[comp]=1;
	                    }
	                    else
	                    {
	                        v.pb( {{neparne,total-neparne},comp});
	                    }
	                }
	            }
	
	
	    for (auto j:v)
	    {
	        for (int i=k; i>0; i--)
	        {
	
	            int cmp = j.second;
	            int prepreke = j.first.second;
	            int dodaje  = j.first.first;
	            if (prepreke >0 && prepreke<=i && dp[i].first<dp[i-prepreke].first+dodaje)
	            {
	                dp[i]= {dp[i-prepreke].first+dodaje,cmp};
	                mp[dp[i]]=dp[i-prepreke];
	            }
	        }
	    }
	
	
	    int x=k;
	    int count=0;
	
	    while(dp[x].second!=0)
	    {
	        for (int i=1; i<=n; i++)
	            for (int j=1; j<=m; j++)
	                if (dp[x].second== ob[i][j] && a[i][j]==0 && (i+j)%2==koji[dp[x].second])
	                {
	                    a[i][j]=2;
	                    broj[ob[i][j]]--;
	                    count++;
	                }
	
	        dp[x]=mp[dp[x]];
	
	    }
	
	    k-=count;
	
	    for (int i=1; i<=n; i++)
	    {
	        a[i][0]=1;
	        a[i][m+1]=1;
	    }
	
	    for (int i=1; i<=m; i++)
	    {
	        a[0][i]=1;
	        a[n+1][i]=1;
	    }
	
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	        {
	            broj[ob[i][j]]=0;
	            ob[i][j]=0;
	
	        }
	
	    comp=0;
	
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	            if (!ob[i][j] && a[i][j]==0)
	            {
	                comp++;
	                dfs(i,j);
	            }
	
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	            if (a[i][j]==2 && min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1])>=2)
	            {
	                a[i][j]=0;
	                broj[ob[i][j]]++;
	                k++;
	            }
	
	    for (int i=1; i<=n; i++)
	        for (int j=1; j<=m; j++)
	            if (!a[i][j] && broj[ob[i][j]]>2)
	            {
	                st[min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1])].insert( {i,j});
	                cnt[i][j]=min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1]);
	            }
	
	    while(k>0)
	    {
	        int p=0;
	        if (st[3].size()) p=3;
	        else if (st[2].size()) p=2;
	        else if (st[1].size()) p=1;
	
	        if (p==1 && k<=2) break;
	        if (p==2 && k==1) break;
	        if (p)
	        {
	            pair<int,int> node = *st[p].begin();
	            st[p].erase(st[p].begin());
	            int xi=node.first;
	            int yi=node.second;
	
	            if (p==3)
	            {
	                if (!a[xi][yi-1] && cnt[xi][yi-1]==3) continue;
	                if (!a[xi][yi+1] && cnt[xi][yi+1]==3) continue;
	                if (!a[xi-1][yi] && cnt[xi-1][yi]==3) continue;
	                if (!a[xi+1][yi] && cnt[xi+1][yi]==3) continue;
	            }
	
	            if (!a[xi][yi-1]) ogradi(xi,yi-1);
	            if (!a[xi][yi+1]) ogradi(xi,yi+1);
	            if (!a[xi-1][yi]) ogradi(xi-1,yi);
	            if (!a[xi+1][yi]) ogradi(xi+1,yi);
	        } else
	            k--;
	    }
	
	    ispisi();
	
	    return 0;
	}

	```
