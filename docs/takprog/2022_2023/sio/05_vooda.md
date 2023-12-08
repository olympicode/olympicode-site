---
hide:
  - toc
---

# 5 - Majnkraft vOOda

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| - | - |
	
	PAŽNjA! PAŽNjA! PAŽNjA!
	U neočekivanom trenutku između početka SIO i sad je izbio ogroman požar u prostorijama Računarskog fakulteta (u Majnkraftu). Komisija nije htela da prekida takmičenje i da ometa takmičare u radu, pa smo odlučili da vas obavestimo putem ovog zadatka. Ako želite da nam pomognemo da spasimo RAF, i da usput osvojite koji poneki poen na SIO, nastavite da čitate!
	
	Naime, u $8$ prostorija trenutno gori vatra. Svaku prostoriju možemo zamisliti kao $M\times N$ matricu, gde su neka polja prohodna, a ostala polja su zidovi. Vatra trenutno gori na svim prohodnim poljima. Komisija je blago ilegalnim metodama (u Majnkraftu) nabavila neizmerne zalihe vode. Vi možete da iskoristite jedan litar vode da biste poplavili jedno prohodno polje. **Međutim, kako se sve ovo dešava u Majnkraftu** (da, u Majnkraftu, definitivno u Majnkraftu), **ako je prohodno polje susedno dva poplavljena polja, onda i ono postaje poplavljeno.** Dva polja su susedna ako dele stranicu.
	
	Da biste ugasili svu vatru, treba da ikoristite nekoliko litara komisijske vode tako da sva prohodna polja budu poplavljena. Kako komisija ipak ne bi želela da koristi previše svoje (i)legalno nabavljene vode, da joj ne bi policija (u Majnkraftu) bila za vratom, molimo vas da pri rešavanju zadatka koristite što manje litara vode. Imate do kraja takmičenja da rešite ovaj zadatak, da ne bismo svi izgoreli (u stvarnosti (u Majnkraftu)).
	
	## Napomena
	Ovo je zadatak sa poznatim ulazom (_output-only_  zadatak). Vama su dati ulazni fajlovi (`1.in`,  `2.in`,  `3.in`,  `4.in`,  `5.in`,  `6.in`,  `7.in`,  `8.in`), dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`1.out`,  `2.out`,  `3.out`,  `4.out`,  `5.out`,  `6.out`,  `7.out`,  `8.out`). Takođe vam je data slika kako izgleda svaki ulazni fajl (`1.png`,  `2.png`,  `3.png`,  `4.png`,  `5.png`,  `6.png`,  `7.png`,  `8.png`).
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza se nalaze dva cela broja $N$ i $M$ - dimenzije matrice. Onda u svakom od narednih $N$ redova je data niska dužine $M$ gde stoji karakter `.` ako je polje prohodno, a u suprotnom `#`.
	
	## Opis izlaza
	Uprvoj liniji treba ispisati $L$ broj litara koji planirate da iskoristite za gašenje požara. Neka polju $(x,y)$ pripišemo broj $M\cdot(x-1)+y$. Formira se pomoćni niz $A$, gde je $A[0]=0$, a $A[1],A[2],\cdots,A[L]$ brojevi pripisani brojevima koje želite da poplavite. U drugom redu izlza se nalazi $L$ brojeva, od kojih svaki predstavlja razliku između susednih brojeva u nizu $A$ ($A[1]-A[0]$, $A[2]-A[1]$, $\cdots$, $A[L]-A[L-1]$).
	
	Međutim u zip arhivi koja vam je obezbeđena uz ovaj zadatak vam je takođe obezbeđen `compressor.cpp` koji iz sledećeg formata (koji je verovatno lakzi takmičarima za ispis, ali je nepraktičan zbog veličine određenih rešenja) u gorenavedeni traženi.
	
	Uprvoj liniji treba ispisati $L$ broj litara koji planirate da iskoristite za gašenje požara. Dalje, u svakoj  od narednih $L$ linija je potrebno ispisati dva cela broja, koja predstavljaju redni broj reda i kolone (indeksirani od $1$) koji poplavljujemo sa sledećim litrom vode. 
	
	## Primer 1
	### Ulaz
	```
	3 3
	#.#
	.##
	...
	```
	
	### Izlaz
	```
	4
	2 2 4 1
	```
	
	## Objašnjenje primera
	Polja koja su poplavljena u navedenom izlazu su $(1,2)$, $(2,1)$, $(3,2)$ i $(3,3)$ (njima su pripisani brojevi $2,4,8,9$, pa su napisane razlike $2-0=2$, $4-2=2$, $8-4=4$ i $9-8=1$). Nakon poplavljivanja polja koja su opisana u zadatku, jedino polje koje nismo poplavili ručno je $(3,1)$. Međutim, ono će postati poplavljeno jer je susedna sa dva  poplavljena polja ($(2,1)$ i $(3,2)$).
	
	## Ograničenja
	
	-   $1 \leq N,M \leq 3000$
	
	## Bodovanje
	U arhivi priloženoj uz ovaj zadatak možete naći za datoteku koji opisuje bodovanje za svaki primer. U prvoj liniji piše broj $P$ koliko ukupno nosi taj zadatak, dok u naredoj liniji se nalazi $P$ brojeva, gde $i$-ti predstavlja granicu koliko najviše litara vode da iskoristite ako želite $i$ poena.
	
	|Primer|N,M|Poena |
	|--|--|--|
	|1|10|6|
	|2|600|6|
	|3|20|12|
	|4|700|12|
	|5|100|16|
	|6|300|16|
	|7|1000|16|
	|8|1000|16|
	
	
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Igor Pavlović i Pavle Martinović | Igor Pavlović i Pavle Martinović | Igor Pavlović i Pavle Martinović |
	
	## Koreni u korovima
	Čak iako je inspiracija za zadatak zaista došla iz načina kako se propagiraju tzv. *source block*-ovi u igrici Majnkraft, pojedini učenici mogli su prepoznati vezu između ovog zadatka i takmičarskog zadatka iz folklora: Data je tabla $10\times10$ i $9$ polja su obrasla korovom. Ako je polje susedno dva polja obrasla korovom onda i ono postane obraslo korovom. Da li je moguće da cela tabla bude obrasla korovom? U ovom zadatku je odgovor NE, a razlog zašto je odgovor NE može nam poslužiti kao dobra vodilja za rešavanje ovakvog zadatka.
	
	Naime obim figure na kom je obrasla korov nikad ne raste, može samo da se smanji. Ako se pojavi polje koje je susedno $3$ ili čak $4$ korova, onda nam se obim smanjuje. Kako je na početku obim najviše $36$, a na kraju treba biti $40$, odgovor na pitanje u zadatku je negativan.
	
	Glavna heuristika koju možemo odmah poneti odavde je da nikad (ili barem da se trudimo da izbegnemo) ne poplavimo polje  koje je susedno već nekom poplavljenom polju.
	
	## Analiza primera
	Prvi primer je mali i može se uraditi manje više ručno. Ocena obima iz prvog dela nam daje da je $27$ optimalan odgovor.
	
	Drugi primer je veći ali mu je svaka pozevazana komponenta pravougaonik. Za pravougaonike se problem može rešiti tačno, i da se dokaže tačnost ocenom gore.
	
	Treći primer je mali, ali je verovatno teško rešiti ručno osim ako se uloži jako puno vremena, već je realnije da ga takmičar programom napravi nekako i onda ručno doradi ako treba. I ovde je nađena ocena optimalna.
	
	Četvrti primer je kao komplikovana verzija drugog gde imamo pravougaonike, ali oni mogu i da se seku. Komisijsko rešenje ovde nalazi odgovor $16316$, dok nam obim daje granicu od $16315$, tako da smo ovaj primer rešili ili optimalno ili skoro optimalno.
	
	Primeri $5-8$ su malo divljiji, i ocena koja je data u prvoj sekciji nije toliko blizu konstrukcija koja je našla komisija. Primeri $5$ i $7$ su crtani rukom, dok su $6$ i $8$ random šum, sa različitim gustinama. Primer $8$ je ogroman, tako da bilo šta malo sporije može jako dugo da se izvršava. Sa njim moramo biti posebno pažljivi
	
	## Autorsko rešenje 1 (86 poena, rešava 4. primer)
	Svaki put kad postavimo novu vodu lako možemo da simuliramo kako se voda dalje kreće pomoću nekog algoritma nalik flood-fill algoritma. Prvo postavimo vodu u polja koja imaju maks jednog prohodnog suseda. Dalje svakom polje dodelimo neku težinu sa kojom ga treba izabrati. Ako je već susedan nekom poplavljenom polju, štetićemo obimu, tako da mu na težinu dodajemo $-10000$. Za svako susedno polje koje će postati poplavljeno ako dodamo vode na to polje dodamo $1000$. Bolje je stavljati u ćoškove nego na otvoreno empirijki, pa dodamo na težinu $100\cdot(4-\deg)$. Najzad (i ovo se ispostavlja kao ključno za nalaženja rešenja u priemru $4$) dodamo malu random težinu, do $10$ na primer. U svakom trenutku biramo polje sa najvećom težinu i njega poplavimo i ispropagiramo sve. Za svako plavljenje moramo da ažuriramo težine $12$ polja koji su na distanci najviše $2$ od poplavljenog polja, pa ceo algoritam radi jako brzo. Na primer, osmi primer rešava u roku od jednog minuta.
	
	## Autorsko rešenje 2 (98 poena, rešava sve osim 4-og primera)
	Anlogno prethodnom rešenju možemo prvo postaviti vodu u ona polja koja imaju tačno jednog slobodnog suseda a zatim simulirati dodavanje novih blokova primenom nekog algoritma za obilazak grafa. Ključna razlika ovog rešenja u odnosu na prethodno je što za naredno poplavljeno polje biramo ono polje koje će poplaviti najveći broj polja ukoliko na njega postavimo blok sa vodom. Za pronalaženje takvog polja neophodno je simulirati poplavu za svakog kandidata koji može poplaviti više od jednog polja, to jest ima bar jednog suseda koji je susedan sa tačno jednim poplavljenim poljem. Primetimo da je složenost jedne iteracije ograničena odozgo sa brojem kandidata u toj iteraciji puta broj poplavljenih polja nakon te iteracije. Na osnovu toga možemo zaključiti da složenost ovog rešenja nije veća od $O(N^2M^2)$. Međutim u priloženim primerima je broj kandidata u svakoj iteraciji značajno manji od $NM$ pa je i složenost ovog rešenja značajno manja i može se primeniti na primerima od 1 do 7. Za rešenje primera 8 u vremenskom periodu prikladnom za dužinu trajanja takmičenja neophodno je izdeliti celu tablu na manje table dimenzija 300x300 i rešiti ih zasebno a zatim spojiti u jedno rešenje. Da bismo osvojili poslednjih par poena na ovom zadatku potrebno je primetiti da rešenje zavisi od polja koje izaberemo između onih polja sa jednakim rezultatom simulacije. Kako bismo dodatno poboljšali skor moguće je primeniti isti algoritam na razlicite izometrijske transformacije ulaza i izabrati najbolje rešenje.

	=== "Stupid"

		``` cpp title="05_vooda-stupid.cpp" linenums="1"
		#include<bits/stdc++.h>
		#define MAXN 5007
		using namespace std;
		priority_queue<pair<int,pair<int,int> > > pq;
		queue<pair<int,int> > q;
		vector<pair<int,int> > v,c;
		bool arr[MAXN][MAXN],fl[MAXN][MAXN];
		string s[MAXN];
		int broj[MAXN][MAXN],dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
		mt19937 rng(time(0));
		void dodajflood(int x,int y)
		{
			broj[x][y]++;
			if(broj[x][y]==2)
			{
				q.push({x,y});
				fl[x][y]=true;
			}
		}
		void poplavi(int x,int y)
		{
			fl[x][y]=true;
			for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) dodajflood(x+dx[i],y+dy[i]);
		}
		int main()
		{
			int t,rand;
			cin>>t>>rand;
			string st;
			if(t<10) st='0'+to_string(t);
			else st=to_string(t);
			ifstream in("testcases\\"+st+".in");
			ofstream out("sols-stupid\\"+st+".out");
			int n,m,br=0;
			in>>n>>m;
			for(int i=1;i<=n;i++)
			{
				in>>s[i];
				for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
			}
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(arr[i][j]) c.push_back({i,j});
			if(rand) shuffle(c.begin(),c.end(),rng);
			for(int i=0;i<c.size();i++) if(!fl[c[i].first][c[i].second])
			{
				br++;
				v.push_back(c[i]);
				q.push(c[i]);
				while(!q.empty())
				{
					poplavi(q.front().first,q.front().second);
					q.pop();
				}
			}
			cout<<br<<endl;
			out<<v.size()<<endl;
			for(int i=0;i<v.size();i++) out<<v[i].first<<" "<<v[i].second<<endl;
			//for(int i=1;i<=n;i++) cout<<s[i]<<endl;
		}

		```

	=== "Nasumični kandidati"

		``` cpp title="05_vooda-rnd-kandidati.cpp" linenums="1"
		#include <stdio.h>
		#include <iostream>
		#include <vector>
		#include <algorithm>
		#include <set>
		#include <cassert>
		#include <fstream>
		#include <random>
		#include <time.h>
		#include <chrono>

		#define maxN 5000
		#define maxM 5000

		using namespace std;
		using namespace std::chrono;

		int n, m, cnt[maxN][maxN], deg[maxN][maxM];
		string s[maxN],input[maxN];

		vector<pair<int, int>> ans, all;
		set<pair<int, int>> candidates;

		bool checkAndUpdate(int x, int y) {
			if (cnt[x][y] == 2) return false;
			cnt[x][y]++;
			if (cnt[x][y] == 2) return true;
			candidates.insert({ x,y });

			return false;
		}

		void add(int x, int y) {
			cnt[x][y] = 2;
			if (x > 0 && s[x - 1][y] == '.') {
				if (checkAndUpdate(x - 1, y)) add(x - 1, y);
			}
			if (x < n - 1 && s[x + 1][y] == '.') {
				if (checkAndUpdate(x + 1, y)) add(x + 1, y);
			}
			if (y > 0 && s[x][y - 1] == '.') {
				if (checkAndUpdate(x, y - 1)) add(x, y - 1);
			}
			if (y < m - 1 && s[x][y + 1] == '.') {
				if (checkAndUpdate(x, y + 1)) add(x, y + 1);
			}
		}

		int iter[maxN][maxN], cur_iter = 0;

		mt19937 rnd(time(NULL));

		int simulate(int x, int y) {
			return rnd();
		}

		void solve(){
			all.clear();
			ans.clear();
			candidates.clear();
			cur_iter=0;

			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					deg[i][j]=cnt[i][j]=iter[i][j]=0;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (s[i][j] == '#') continue;
					all.push_back({ i,j });
					if (i > 0 && s[i - 1][j] == '.') deg[i][j]++;
					if (i < n - 1 && s[i + 1][j] == '.') deg[i][j]++;
					if (j > 0 && s[i][j - 1] == '.') deg[i][j]++;
					if (j < m - 1 && s[i][j + 1] == '.') deg[i][j]++;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (deg[i][j] == 1) {
						ans.push_back({ i,j });
						add(i, j);
					}
				}
			}

			while (all.size()) {
				if (candidates.empty()) {
					pair<int, int> last = all.back();
					all.pop_back();
					int x = last.first, y = last.second;
					if (cnt[x][y] != 0) continue;
					ans.push_back({ x,y });
					add(x, y);
					continue;
				}

				int curMax = 0, bestX, bestY;
				cur_iter++;

				for (auto it = candidates.begin(); it != candidates.end();) {
					int x = (*it).first, y = (*it).second;
					if (cnt[x][y] != 1) {
						candidates.erase(it++);
						continue;
					}

					if (x > 0 && s[x - 1][y] == '.' && cnt[x - 1][y] != 2 && iter[x - 1][y] != cur_iter) {
						int tmp = simulate(x - 1, y);
						iter[x - 1][y] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x - 1; bestY = y;
						}
					}
					if (x < n - 1 && s[x + 1][y] == '.' && cnt[x + 1][y] != 2 && iter[x + 1][y] != cur_iter) {
						int tmp = simulate(x + 1, y);
						iter[x + 1][y] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x + 1; bestY = y;
						}
					}
					if (y > 0 && s[x][y - 1] == '.' && cnt[x][y - 1] != 2 && iter[x][y - 1] != cur_iter) {
						int tmp = simulate(x, y - 1);
						iter[x][y - 1] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x; bestY = y - 1;
						}
					}
					if (y < m - 1 && s[x][y + 1] == '.' && cnt[x][y + 1] != 2 && iter[x][y + 1] != cur_iter) {
						int tmp = simulate(x, y + 1);
						iter[x][y + 1] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x; bestY = y + 1;
						}
					}

					it++;
				}

				if (curMax != 0) {
					ans.push_back({ bestX,bestY });
					add(bestX, bestY);
				}
			}
		}

		pair<int,int>  pos[maxN][maxN];
		vector<pair<int,int>> bestAns;

		void flip() {
			for(int i=0;i<n;i++){
				reverse(s[i].begin(),s[i].end());
				reverse(pos[i],pos[i]+m);
			}
		}

		void transpose(){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<m;j++){
					swap(s[i][j],s[j][i]);
					swap(pos[i][j],pos[j][i]);
				}
			}
		}

		void rotate90(){
			transpose();
			flip();
		}

		void updateAns(){
			if(!bestAns.empty() && bestAns.size()<ans.size()) return;
			bestAns = ans;
		}

		int main() {
			std::ios_base::sync_with_stdio(false);
			int t,threshold;
			cin>>t;
			string st;
			if(t<10) st='0'+to_string(t);
			else st=to_string(t);
			ifstream in("testcases\\"+st+".in");
			ofstream out("sols-rnd-kandidati\\"+st+".out");

			in >> n >> m;

			for (int i = 0; i < n; i++) {
				in >> input[i];
			}

			if(t<=7){
				for (int i = 0; i < n; i++) {
					s[i]=input[i];
				}

				auto start = high_resolution_clock::now();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);

				while(duration.count()<300){
					solve();
					updateAns();
					stop = high_resolution_clock::now();
					duration = duration_cast<seconds>(stop - start);
				}
			}

			if(t==8){
				int l=10,k=300;
				n=m=k;

				for(int i=0;i<l;i++){
					for(int j=0;j<l;j++){
						for(int ii=i*k;ii<i*k+k;ii++){
							s[ii%k]="";
							for(int jj=j*k;jj<j*k+k;jj++) {
								s[ii%k]+=input[ii][jj];
								pos[ii%k][jj%k]={ii,jj};
							}
						}

						solve();
						for(int ii=0;ii<ans.size();ii++){
							bestAns.push_back(pos[ans[ii].first][ans[ii].second]);
						}
						cout<<i*l+j<<endl;
					}
				}
			}

			cout<<bestAns.size()<<endl;

			out << bestAns.size() << endl;
			sort(bestAns.begin(), bestAns.end());

			for (int i = 0; i < bestAns.size(); i++) {
				input[bestAns[i].first][bestAns[i].second] = 'V';
				out << bestAns[i].first + 1 << " " << bestAns[i].second + 1 << endl;
			}
			/*
			for (int i = 0; i < n; i++) {
				fout << s[i] << endl;
			}*/
			return 0;
		}
		```

	=== "Lowerbound"

		``` cpp title="05_vooda-lowerbound.cpp" linenums="1"
		#include<bits/stdc++.h>
		#define MAXN 5007
		using namespace std;
		priority_queue<pair<int,pair<int,int> > > pq;
		queue<pair<int,int> > q;
		vector<pair<int,int> > v;
		bool arr[MAXN][MAXN],vi[MAXN][MAXN];
		string s[MAXN];
		int cnt;
		int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
		mt19937 rng(time(0));
		void dfs(int x,int y)
		{
			vi[x][y]=true;
			for(int i=0;i<4;i++)
			{
				if(!arr[x+dx[i]][y+dy[i]])  cnt++;
				else if(!vi[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
			}
		}
		int main()
		{
			int t;
			cin>>t;
			string st;
			if(t<10) st='0'+to_string(t);
			else st=to_string(t);
			ifstream in("testcases\\"+st+".in");
			//ofstream out("sols\\"+st+".out");
			int n,m;
			int lw=0;
			in>>n>>m;
			for(int i=1;i<=n;i++)
			{
				in>>s[i];
				for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
			}
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vi[i][j] && arr[i][j])
			{
				cnt=0;
				dfs(i,j);
				lw+=(cnt+3)/4;
			}
			cout<<lw;
		}
		```

	=== "Greedy"

		``` cpp title="05_vooda-greedy.cpp" linenums="1"
		#include <stdio.h>
		#include <iostream>
		#include <vector>
		#include <algorithm>
		#include <set>
		#include <cassert>
		#include <fstream>

		#define maxN 5000
		#define maxM 5000

		using namespace std;

		int n, m, cnt[maxN][maxN], deg[maxN][maxM];
		string s[maxN],input[maxN];

		vector<pair<int, int>> ans, all;
		set<pair<int, int>> candidates;

		bool checkAndUpdate(int x, int y) {
			if (cnt[x][y] == 2) return false;
			cnt[x][y]++;
			if (cnt[x][y] == 2) return true;
			candidates.insert({ x,y });

			return false;
		}

		void add(int x, int y) {
			cnt[x][y] = 2;
			if (x > 0 && s[x - 1][y] == '.') {
				if (checkAndUpdate(x - 1, y)) add(x - 1, y);
			}
			if (x < n - 1 && s[x + 1][y] == '.') {
				if (checkAndUpdate(x + 1, y)) add(x + 1, y);
			}
			if (y > 0 && s[x][y - 1] == '.') {
				if (checkAndUpdate(x, y - 1)) add(x, y - 1);
			}
			if (y < m - 1 && s[x][y + 1] == '.') {
				if (checkAndUpdate(x, y + 1)) add(x, y + 1);
			}
		}

		vector<pair<int, int>> simulation;
		int cntSim[maxN][maxN];

		void addSimulation(int x, int y, int& count) {
			cntSim[x][y] = 2 - cnt[x][y];
			count++;
			if (x > 0 && s[x - 1][y] == '.') {
				cntSim[x - 1][y]++;
				simulation.push_back({ x - 1,y });
				if ((cntSim[x - 1][y] + cnt[x - 1][y]) == 2) addSimulation(x - 1, y, count);
			}
			if (x < n - 1 && s[x + 1][y] == '.') {
				cntSim[x + 1][y]++;
				simulation.push_back({ x + 1,y });
				if ((cntSim[x + 1][y] + cnt[x + 1][y]) == 2) addSimulation(x + 1, y, count);
			}
			if (y > 0 && s[x][y - 1] == '.') {
				cntSim[x][y - 1]++;
				simulation.push_back({ x,y - 1 });
				if ((cntSim[x][y - 1] + cnt[x][y - 1]) == 2) addSimulation(x, y - 1, count);
			}
			if (y < m - 1 && s[x][y + 1] == '.') {
				cntSim[x][y + 1]++;
				simulation.push_back({ x,y + 1 });
				if ((cntSim[x][y + 1] + cnt[x][y + 1]) == 2) addSimulation(x, y + 1, count);
			}
		}

		int iter[maxN][maxN], cur_iter = 0;

		int simulate(int x, int y) {
			int result = 0;
			simulation.push_back({ x ,y });
			addSimulation(x, y, result);
			for (int i = 0; i < simulation.size(); i++) {
				cntSim[simulation[i].first][simulation[i].second] = 0;
			}
			simulation.clear();
			return result;
		}

		void solve(){
			all.clear();
			ans.clear();
			simulation.clear();
			candidates.clear();
			cur_iter=0;

			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					deg[i][j]=cnt[i][j]=iter[i][j]=cntSim[i][j]=0;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (s[i][j] == '#') continue;
					all.push_back({ i,j });
					if (i > 0 && s[i - 1][j] == '.') deg[i][j]++;
					if (i < n - 1 && s[i + 1][j] == '.') deg[i][j]++;
					if (j > 0 && s[i][j - 1] == '.') deg[i][j]++;
					if (j < m - 1 && s[i][j + 1] == '.') deg[i][j]++;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (deg[i][j] == 1) {
						ans.push_back({ i,j });
						add(i, j);
					}
				}
			}

			while (all.size()) {
				if (candidates.empty()) {
					pair<int, int> last = all.back();
					all.pop_back();
					int x = last.first, y = last.second;
					if (cnt[x][y] != 0) continue;
					ans.push_back({ x,y });
					add(x, y);
					continue;
				}

				int curMax = 0, bestX, bestY;
				cur_iter++;

				for (auto it = candidates.begin(); it != candidates.end();) {
					int x = (*it).first, y = (*it).second;
					if (cnt[x][y] != 1) {
						candidates.erase(it++);
						continue;
					}

					if (x > 0 && s[x - 1][y] == '.' && cnt[x - 1][y] != 2 && iter[x - 1][y] != cur_iter) {
						int tmp = simulate(x - 1, y);
						iter[x - 1][y] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x - 1; bestY = y;
						}
					}
					if (x < n - 1 && s[x + 1][y] == '.' && cnt[x + 1][y] != 2 && iter[x + 1][y] != cur_iter) {
						int tmp = simulate(x + 1, y);
						iter[x + 1][y] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x + 1; bestY = y;
						}
					}
					if (y > 0 && s[x][y - 1] == '.' && cnt[x][y - 1] != 2 && iter[x][y - 1] != cur_iter) {
						int tmp = simulate(x, y - 1);
						iter[x][y - 1] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x; bestY = y - 1;
						}
					}
					if (y < m - 1 && s[x][y + 1] == '.' && cnt[x][y + 1] != 2 && iter[x][y + 1] != cur_iter) {
						int tmp = simulate(x, y + 1);
						iter[x][y + 1] = cur_iter;
						if (tmp > curMax) {
							curMax = tmp; bestX = x; bestY = y + 1;
						}
					}

					it++;
				}

				if (curMax != 0) {
					ans.push_back({ bestX,bestY });
					add(bestX, bestY);
				}
			}
		}

		pair<int,int>  pos[maxN][maxN];
		vector<pair<int,int>> bestAns;

		void flip() {
			for(int i=0;i<n;i++){
				reverse(s[i].begin(),s[i].end());
				reverse(pos[i],pos[i]+m);
			}
		}

		void transpose(){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<m;j++){
					swap(s[i][j],s[j][i]);
					swap(pos[i][j],pos[j][i]);
				}
			}
		}

		void rotate90(){
			transpose();
			flip();
		}

		void updateAns(){
			if(!bestAns.empty() && bestAns.size()<ans.size()) return;
			bestAns.clear();
			for(int i=0;i<ans.size();i++){
				bestAns.push_back(pos[ans[i].first][ans[i].second]);
			}
		}

		int main() {
			std::ios_base::sync_with_stdio(false);
			int t,threshold;
			cin>>t;
			string st;
			if(t<10) st='0'+to_string(t);
			else st=to_string(t);
			ifstream in("testcases\\"+st+".in");
			ofstream out("sols-gridi\\"+st+".out");

			in >> n >> m;

			for (int i = 0; i < n; i++) {
				in >> input[i];
			}

			if(t<=6){
				// Pokreni algoritam nad svim izometrijskim transformacijama ulaza i uzmi najbolji
				for (int i = 0; i < n; i++) {
					s[i]=input[i];
					for(int j=0;j<m;j++){
						pos[i][j] = {i,j};
					}
				}

				for(int i=0;i<4;i++){
					solve();
					cout<<ans.size()<<endl;
					updateAns();
					rotate90();
				}

				flip();

				for(int i=0;i<4;i++){
					solve();
					cout<<ans.size()<<endl;
					updateAns();
					rotate90();
				}
			}

			if(t==7){
				for (int i = 0; i < n; i++) {
					s[i]=input[i];
					for(int j=0;j<m;j++){
						pos[i][j] = {i,j};
					}
				}

				solve();
				updateAns();
			}

			if(t==8){
				int l=10,k=300;
				n=m=k;

				for(int i=0;i<l;i++){
					for(int j=0;j<l;j++){
						for(int ii=i*k;ii<i*k+k;ii++){
							s[ii%k]="";
							for(int jj=j*k;jj<j*k+k;jj++) {
								s[ii%k]+=input[ii][jj];
								pos[ii%k][jj%k]={ii,jj};
							}
						}

						solve();
						for(int ii=0;ii<ans.size();ii++){
							bestAns.push_back(pos[ans[ii].first][ans[ii].second]);
						}
						cout<<i*l+j<<endl;
					}
				}
			}

			cout<<bestAns.size()<<endl;

			out << bestAns.size() << endl;
			sort(bestAns.begin(), bestAns.end());

			for (int i = 0; i < bestAns.size(); i++) {
				input[bestAns[i].first][bestAns[i].second] = 'V';
				out << bestAns[i].first + 1 << " " << bestAns[i].second + 1 << endl;
			}
			/*
			for (int i = 0; i < n; i++) {
				fout << s[i] << endl;
			}*/
			return 0;
		}
		```
	=== "Dijagonalno"

		``` cpp title="05_vooda-dijagonalno.cpp" linenums="1"
		#include<bits/stdc++.h>
		#define MAXN 5007
		using namespace std;
		priority_queue<pair<int,pair<int,int> > > pq;
		queue<pair<int,int> > q;
		vector<pair<int,int> > v;
		bool arr[MAXN][MAXN],fl[MAXN][MAXN];
		string s[MAXN];
		int broj[MAXN][MAXN],rando[MAXN][MAXN];
		int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
		mt19937 rng(time(0));
		int brojsuseda(int x,int y)
		{
			int cnt=0;
			for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]])  cnt++;
			return cnt;
		}
		int skor(int x,int y)
		{
			int a=brojsuseda(x,y);
			int pre=0;
			for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]] && broj[x+dx[i]][y+dy[i]])  pre++;
			if(a<2) return 1000000000;
			return -100000*broj[x][y]+1000*pre+100*(4-a)+rando[x][y]%100;
		}
		void u_pq(int x,int y)
		{
			rando[x][y]=rng()%100;
			pq.push({skor(x,y),{x,y}});
		}
		void dodajflood(int x,int y)
		{
			broj[x][y]++;
			if(broj[x][y]==2)
			{
				q.push({x,y});
				fl[x][y]=true;
			}
			else
			{
				u_pq(x,y);
				for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) u_pq(x+dx[i],y+dy[i]);
			}

		}
		void poplavi(int x,int y)
		{
			fl[x][y]=true;
			for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) dodajflood(x+dx[i],y+dy[i]);
		}
		int main()
		{
			int t,threshold;
			cin>>t>>threshold;
			if(threshold==0) threshold=1000000000;
			string st;
			if(t<10) st='0'+to_string(t);
			else st=to_string(t);
			ifstream in("testcases\\"+st+".in");
			ofstream out("sols-dijagonalno\\"+st+".out");
			int n,m;
			int lw=0;
			in>>n>>m;
			for(int i=1;i<=n;i++)
			{
				in>>s[i];
				for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
			}
			while(true)
			{
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fl[i][j]=false;
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) broj[i][j]=0;
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) rando[i][j]=0;
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(arr[i][j]) u_pq(i,j);
				int br=0;
				while(!pq.empty())
				{
					pair<int,int> p=pq.top().second;
					int rez=pq.top().first;
					pq.pop();
					if(fl[p.first][p.second] || rez!=skor(p.first,p.second)) continue;
					q.push(p);
					//cout<<p.first<<" "<<p.second<<endl;
					v.push_back(p);
					br++;
					while(!q.empty())
					{
						pair<int,int> pr=q.front();
						q.pop();
						poplavi(pr.first,pr.second);
					}
				}
				cout<<br<<endl;
				if(br<threshold) break;
				v.clear();
			}
			out<<v.size()<<endl;
			for(int i=0;i<v.size();i++) out<<v[i].first<<" "<<v[i].second<<endl;
			//for(int i=1;i<=n;i++) cout<<s[i]<<endl;
		}
		```