---
hide:
  - toc
---

# 4 - Bombonice

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 512MB |
	
	Mala Duca mnogo voli da jede bombonice. Ona je od svoje mame dobila beskonačno bombonica i sada želi da ih rasporedi u kutije.
	Uzela je $N$ praznih kutija, napisala na njima brojeve od $1$ do $N$, i postavila ih redom **u krug** oko sebe. Kutiji sa rednim brojem $N$ susedne kutije su sa rednim brojevima $N-1$ i $1$. 
	
	Sada će stavljati bombonice u kutije na sledeći način: Izabraće dva broja, $P$ i $K$, i onda će u kutiju broj $P$ dodati tačno $K^2$ bombinca (zato što voli brojeve koji su potpuni kvadrati), zatim će u sledeću kutiju redom u krugu dodati $(K-1)^2$ bombonica, zatim u sledeću $(K-2)^2$, itd. redom dok ne prođe $K$ kutija i u poslednju stavi jednu ($1^2$) bombonicu. 
	Ovakav postupak, počev od ponovnog izbora novih brojeva $P$ i $K$, će potencijalno ponavljati više puta, sve dok joj ne dosadi.
	
	Duca želi da održava određeni balans bombonica u nekim kutijama, tako da će se povremeno zapitati koliko je ukupno bombonica ubacila u nekih $T$ uzastopnih kutija, počev od kutije broj $X$. Kako to može biti jako veliki broj za računanje, moli vas za pomoć da joj svaki put odgovorite na ovakvo pitanje, i za uzvrat će vam dati nekoliko bombonica. Ukoliko svi odgovori budu tačni, pomoći će vam i da osvojite neki poen na takmičenju.
	
	## Opisi funkcija
	Potrebno je da implementirate sledeće funkcije:
	
	* $Pocetak(N)$
	
	koja se poziva tačno jednom na početku izvršavanja programa, i saopštava da Duca ima $N$ kutija postavljenih u krug.
	
	* $DodajBombonice(P,K)$
	
	koja označava da Duca dodaje bombonice u $K$ kutija, počev od kutije broj $P$, na način koji je opisan u zadatku.
	
	* $Prebroji(X,T)$
	
	koja treba da vrati koliko se trenutno ukupno bombonica nalazi u $T$ uzastpnih kutija, počev od kutije broj $X$.
	**Pošto ovaj broj može biti veliki, vratiti ostatak pri deljenju broja bombonica sa $10^9 + 7 = 1000000007$.**
	
	## Primer 1
	
	| Pozivi funkcija  | Objašnjenje                                                         | 
	| --------------------- | --------------------------------------------------------------------------------------|
	| Pocetak(7)       | Imamo 7 kutija koje su na početku prazne. Broj bombonica u njima možemo |
	|| predstaviti kao niz indeksiran od 1:  [0,0,0,0,0,0,0]|
	| DodajBombonice(2,3)| Dodajemo $9=3^2$ bombonica u drugu kutiju, $4=2^2$ bombonica u treću |
	|| kutiju i $1=1^2$ bombonicu u četvrtu kutiju. Sada je stanje: [0,9,4,1,0,0,0] |
	| DodajBombonice(4,2)| Dodajemo $4$ bombonice u četvrtu i $1$ bombonicu u petu kutiju. |
	|| Trenutno stanje: [0,9,4,5,1,0,0]  |
	| DodajBombonice(5,4)| Dodajemo $16$ bombonica u petu, zatim $9$ u šestu, $4$ u sedmu, i $1$ u prvu kutiju. |
	|| Trenutno stanje: [1,9,4,5,17,9,4]|
	| Prebroji(1,5)| Brojimo koliko ima bombonica u 5 uzastopnih kutija počev od prve. |
	|| [**1,9,4,5,17**,9,4] Ovaj poziv funkcije treba da vrati rezultat 36.|
	| Prebroji(5,1)| Brojimo koliko ima bombonica u 1 uzastopnoj kutiji počev od pete.   |
	|| [1,9,4,5,**17**,9,4] Ovaj poziv funkcije treba da vrati rezultat 17.|
	| DodajBombonice(7,2)| Dodajemo $4$ bombonice u sedmu i $1$ bombonicu u prvu kutiju. |
	|| Dobijamo stanje: [2,9,4,5,17,9,8]  |
	| Prebroji(6,4)| Brojimo koliko ima bombonica u $3$ uzastopne kutije počev od šeste.|
	|| [**2,9**,4,5,17,**9,8**]Ovaj poziv funkcije treba da vrati rezultat 28.|
	
	
	## Ograničenja
	
	+ Neka je $Q$ ukupan broj poziva funkcija $DodajBombonice$ i $Prebroji$.
	+ $1 \leq N, Q \leq 250000$
	+ $1 \leq P,K,X,T \leq N$
	
	## Podzadaci
	
	+ Podzadatak 1 [11 poena]: $N, Q \leq 1000$.
	+ Podzadatak 2 [18 poena]: $K \leq 3$.
	+ Podzadatak 3 [19 poena]: $T \leq 3$.
	+ Podzadatak 4 [20 poena]: Prvo će se izvršavati samo pozivi funkcije $DodajBombonice$, potom nakon njih samo pozivi funkcije $Prebroji$
	+ Podzadatak 5 [32 poena]: Nema dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `bombonice.cpp` ili `bombonice.pas`, koji implementira pomenute funkcije. Osim traženih funkcija, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	U zavisnosti od programskog jezika koji koristite, vaše funkcije/procedure moraju biti sledećeg oblika:
	
	| Jezik   | Deklaracija funkcije                              | 
	| ------- | ------------------------------------------------- |
	| C++     | `void Pocetak(int N);`     |
	|  | `void DodajBombonice(int P, int K);`  | 
	|  | `int Prebroji(int X, int T);`  |
	| Pascal  | `procedure Pocetak(N: longint);`  |
	|  |`procedure DodajBombonice(P,K : longint);`  |
	|  | `function Prebroji(N,T : longint) : longint;`  |
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam "template" fajlovi `code.cpp` i `code.pas` koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi `grader.cpp`, `grader.pas` koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu učitava brojeve $N$ i $Q$
	+ Poziva funkciju $Pocetak(N)$
	+ U narednih $Q$ redova čita po 3 broja
	+ + Prvi broj je tip upita (1 - dodavanje bombonica, 2 - prebrojavanje)
	+ + U prvom slučaju, preostala dva broja su $P$ i $K$, i poziva se funkcija $DodajBombonice(P,K)$
	+ + U drugom slučaju, preostala dva broja su $X$ i $T$, i poziva se funkcija $Prebroji(X,T)$, i ispisuje se njen rezultat, svaki u posebnom redu.
	
	Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Ivan Stošić | Aleksa Plavšić |
	
	Lako se zaključuje da se pri dodavanju bombonica, one dodaju u kutije $P, P+1, P+2, ..., P+K-1$. Za nijansu je jednostavniji slučaja kada je  $P+K-1\leq N$. Ako uvedemo oѕnaku $R=P+K$, onda će u kutiju broj $I$ ($P\leq I\leq P+K-1=R-1$) biti dodato $(R-I)^2$ bombonica, Ako uzmemo u obzir da je $(R-I)^2 = R^2 - 2R\times I + I^2$, to broj dodatih kuglica možemo baš posmatrati kao tri zasebna sabirka (koji će formirati tokom trajanja tri zasebna zbira). Da bi efikasno mogli da efikasno ažuriramo zbirove (po pojedinačnim kutijama) i efikasno određuejmo zbirove blokova uzastopnih kutija, formiramo tri segmentna stabla. Jedno koje zbraja fiksni sabirak u operaciji dodavanja ($R^2$), drugo koje broji koliko smo puta sadržaj $I$-te kutije uvećali za $I$ (u gornjem primeru to je $-2R$) i treće koje broji koliko smo puta sadržaj $I$-te kutuje uvećali za $I^2$ (u gornjem primeru to je $1$). Ako ta segemntna stabla formiramo na taj način, onda ćemo kasnije moći efikasno da prebrojimo ukupan broj bombonica u blokovima uzastopnih kutija. 
	
	Ako je  $P+K-1> N$, onda dodavanje bombonica razdvajamo u dva dodavanja: u prvom dodavanju je $P1=P$ $K1=N-P+1$, a u drugom je $P2 = 1$ i $K2=K-K1$.
	
	Slično se prebrajanje bombonica razdvaja na dva slučaja. Ako je $X+T-1\leq N$, onda je dovoljan jedno sabiranje po segmentnom stablu za blok (interval) $X,X+T-1]$. Ako je $X+T-1.>N$, onda su potrebna dva upita/zbira: ѕa intervale $X, N]$ i $[1,T-(N+1-X)]$.
	
	``` cpp title="04_bombonice.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	
	#define MAXN 3555333
	#define mmod 1000000007
	
	int n;
	long long bombonice[MAXN];
	
	int bigrand() {
	    return (rand() << 15) | (rand());
	}
	
	void fmod(long long &x) {
	    if (x>=mmod) x%=mmod;
	    if (x<0) x = ((x%mmod) + mmod) % mmod;
	}
	
	void PocetakBF(int N) {
	    n = N;
	    for(int i=0; i<=N; i++) bombonice[i] = 0;
	}
	
	void DodajBomboniceBF(int P, int K) {
	    for(long long k = K; k>0; k--) {
	        bombonice[P] += k*k;
	        fmod(bombonice[P]);
	        P++;
	        if (P>n) P=1;
	    }
	}
	
	int PrebrojiBF(int X, int T) {
	    long long s = 0;
	    for(int i=0; i<T; i++) {
	        s += bombonice[X];
	        fmod(s);
	        X++;
	        if (X>n) X=1;
	    }
	    return s;
	}
	
	long long sum[MAXN], lazy0[MAXN], lazy1[MAXN], lazy2[MAXN];
	long long part_sum0[MAXN], part_sum1[MAXN], part_sum2[MAXN];
	
	void Pocetak(int N) {
	    n = N;
	
	    part_sum0[0] = 0;
	    part_sum1[0] = 0;
	    part_sum2[0] = 0;
	    for(long long i=1; i<=N; i++) {
	        part_sum0[i] = part_sum0[i-1] + 1;   fmod(part_sum0[i]);
	        part_sum1[i] = part_sum1[i-1] + i;   fmod(part_sum1[i]);
	        part_sum2[i] = part_sum2[i-1] + i*i; fmod(part_sum2[i]);
	    }
	
	    int m = min(MAXN,5*N);
	    for(long long i=0; i<m; i++) {
	        sum[i] = 0;
	        lazy0[i] = 0;
	        lazy1[i] = 0;
	        lazy2[i] = 0;
	    }
	}
	
	long long lazypartsum(int l, int r, long long s2, long long s1, long long s0) {
	    long long s = 0;
	    fmod(s2); fmod(s1); fmod(s0);
	    s += s2*(part_sum2[r] - part_sum2[l-1]); fmod(s);
	    s += s1*(part_sum1[r] - part_sum1[l-1]); fmod(s);
	    s += s0*(part_sum0[r] - part_sum0[l-1]); fmod(s);
	    return s;
	}
	
	void addseg(int x, int l, int r, int L, int R, long long s2, long long s1, long long s0) {
	
	    if (r < L) return;
	    if (l > R) return;
	
	    if (l >= L && r <= R) {
	
	        lazy2[x] += s2; fmod(lazy2[x]);
	        lazy1[x] += s1; fmod(lazy1[x]);
	        lazy0[x] += s0; fmod(lazy0[x]);
	
	        sum[x] += lazypartsum(l,r,s2,s1,s0); fmod(sum[x]);
	
	        /*sum[x] += s2*(part_sum2[r] - part_sum2[l-1]); fmod(sum[x]);
	        sum[x] += s1*(part_sum1[r] - part_sum1[l-1]); fmod(sum[x]);
	        sum[x] += s0*(part_sum0[r] - part_sum0[l-1]); fmod(sum[x]);*/
	
	        //printf("add %d %d %d (%d %d)   %lld %lld %lld    -> %lld\n", x,l,r,L,R,s2,s1,s0,sum[x]);
	
	    } else {
	        int m = (l+r)/2;
	        addseg(x*2,l,m, L,R, s2,s1,s0);
	        addseg(x*2+1,m+1,r, L,R, s2,s1,s0);
	        sum[x] = sum[x*2] + sum[x*2+1];
	        fmod(sum[x]);
	        sum[x] += lazypartsum(l,r,lazy2[x],lazy1[x],lazy0[x]);
	        fmod(sum[x]);
	        //printf("trsum %d (%d %d) -> %lld\n", x,l,r, sum[x]);
	    }
	}
	
	long long sumseg(int x, int l, int r, int L, int R, long long s2, long long s1, long long s0) {
	
	    if (r < L) return 0;
	    if (l > R) return 0;
	
	    if (l >= L && r <= R) {
	
	        long long res = sum[x] + lazypartsum(l,r,s2,s1,s0);
	        fmod(res);
	
	        /*res += s2*(part_sum2[r] - part_sum2[l-1]); fmod(res);
	        res += s1*(part_sum1[r] - part_sum1[l-1]); fmod(res);
	        res += s0*(part_sum0[r] - part_sum0[l-1]); fmod(res);*/
	
	        return res;
	
	    } else {
	
	        int m = (l+r)/2;
	        long long res = sumseg(x*2,l,m, L,R, s2+lazy2[x],s1+lazy1[x],s0+lazy0[x]);
	        res += sumseg(x*2+1,m+1,r, L,R, s2+lazy2[x],s1+lazy1[x],s0+lazy0[x]);
	        fmod(res);
	
	        return res;
	    }
	}
	
	void DodajBombonice(int P, int K) {
	    if (P+K-1 > n) {
	        long long R = P+K;
	        addseg(1,1,n, P,n, 1, -2LL*R,R*R);
	
	        DodajBombonice(1, K-(n-P+1));
	    } else {
	        long long R = P+K;
	        addseg(1,1,n, P,R-1, 1,-2LL*R,R*R);
	    }
	}
	
	int Prebroji(int X, int T) {
	    if (X+T-1 > n) {
	        long long sum = Prebroji(X, n-X+1);
	        sum += Prebroji(1, T-(n-X+1));
	        fmod(sum);
	        return sum;
	    } else {
	        long long sum = sumseg(1,1,n, X,X+T-1, 0,0,0);
	        return sum;
	    }
	}

	```
