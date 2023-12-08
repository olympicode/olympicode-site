---
hide:
  - toc
---

# 3 - Najslabija karika

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3500ms | 512MB |
	
	Svet nije mesto za slabiće, već samo najjači opstaju. Potkrepio bih ovakav argument nekim primerima, ali, nažalost, to u ovom trenutku nije moguće (razmislite zašto?). Moraćete naprosto da mi verujete na reč, samo najjači opstaju.
	
	No dobro, i u ovom zadatku samo najjači opstaju. Naime, na datom nizu različitih pozitivnih celih brojeva $A$ smemo da vršimo sledeću operaciju: ako je neki broj u nizu manji od svih svojih suseda, onda ga možemo izbaciti (slabić). Na primer u nizu $2,3,1,4,5$ možemo izbaciti broj $2$ ili broj $1$. Označimo sa $D(A)$ broj različitih nizova (moguće čak i praznih) koje je moguće dobiti primenom nekog broja ovakvih operacija krenuvši od niza $A$.
	
	Vama je data permutacija $A$ brojeva od $1$ do $N$. Neka sa $A[L\ldots R]$ označimo podniz ove permutacije koji sadrži elemente $A[L],A[L+1],\ldots,A[R]$. Zadatak za najjače među takmičarima je da odgovore na $Q$ upita koji traže da sračunate $D(A[L\ldots R])$. Naravno, kako ovaj broj može biti prevelik, potrebno ga je sračunati po modulu $10^9+7$.
	
	## Opisi funkcija
	Potrebno je da implementirate funkcije
	
	-   $Init(N,  A[\ldots])$
	-   $Query(L, R)$
	
	Funkcija $Init$ se poziva samo jednom na početku ivršavanja programa njegovi argumenti su $N$ i $A[\ldots]$, gde je $A[\ldots]$ permutacija brojeva od $1$ do $N$.   **Niz je indeksiran od 1.**
	
	Zatim se funkcija $Query$ poziva $Q$ puta. Ona treba da vrati $D(A[L\ldots R])$.
	
	## Primer
	Neka je $N=5$,  $A=\{2,3,1,4,5\}$. Ako bismo hteli da sračunamo   $D(A[1\ldots3])$, odnosno $D(\{2,3,1\})$, odgovor bi bio $5$, jer su nizovi koje bismo dobili $\{\}$, $\{3\}$, $\{2,3\}$, $\{3,1\}$, $\{2,3,1\}$. Ako bi tražili $D(A[1\ldots5])$, odnosno $D(\{2,3,1,4,5\})$ , odgovor bi bio $7$ sa nizovima $\{\},$ $\{5\}$, $\{4,5\}$, $\{3,4,5\}$, $\{2,3,4,5\}$, $\{3,1,4,5\}$, $\{2,3,1,4,5\}$.
	
	## Ograničenja
	
	-   $1 \leq N,Q \leq 500.000$
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[6 poena]:** $N\le10$, $Q\le 100$
	-   **[9 poena]:** $N,Q\le500$
	-   **[13 poena]:** $N,Q\le5000$
	-   **[14 poena]:** Broj $N$ se u nizu $A$ nalazi između $L$ i $R$ u svakom upitu
	-   **[20 poena]:** Sa jednakom verovatnoćom je izabrana jedna od mogućih permutacija
	-   **[38 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl  `samo_najjaci_opstaju.cpp`  koji implementira pomenute funkcije. Osim traženih funkcija, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaše funkcije moraju biti sledećeg oblika:
	
	`void Init(int N, int* A);`
	`int Query(int L, int R);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojevi $N$ i $Q$.
	-   U narednom redu $N$ brojeva: $A[i]$.
	-   U narednih $Q$ redova po $2$ broja: $L$ i $R$.
	
	Zatim ovaj program zove vašu funkciju i ispisuje rezultat koji vaša funkcija vrati.
	
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |
	
	## Rešenje kada $N \leq 10$, $Q\leq100$
	Primetimo da svaki niz koji dobijemo na kraju je podsekvenca početnog, pa za dati niz postoji najviše $2^N$ mogućih podsekvenci i za svaku možemo gramzivim algoritmom da proverimo da li se zaista može dobiti opisanim operacijama. $O(Q2^NN)$ 
	
	## Rešenje kada $N,Q \leq 500$
	Za svaki podzadatak nadalje ćemo morati da se udubimo u koncept *Dekartovog stabla* niza. Naime, to je binarno stablo koje se konstruiše rekurzivno (u kvadratnom vremenu) na sledeći način: neka je $i$ indeks maksimuma u našem nizu, onda je čvor $i$ koren našeg stabla. Zatim, podelimo niz na dva niza $1$,$2$,$\cdots$,$i-1$ i $i+1,i+2,\cdots,N$ i nađemo Dekartovo stablo od ova dva podniza, čijim kačanjem na koren $i$ kao levo i desno dete, redom, ćemo dobiti Dekartovo stablo celog niza. Sada može se primetiti da je moguće ukloniti neki član niza akko smo već uklonili celo njegovo podstablo u Dekartovom stablu. Stoga je zadatak zapravo ekvivalentan sa traženjem broja načina kako možemo da izaberemo nekoliko disjunktnih podstabala Dekartovog stabla datog niza. Ovo se rešava prostim dinamičkim programiranjem na stablu. Ako su $l$ i $r$ deca čvora $u$, onda možemo da sračunamo $dp[u]=dp[l]\cdot dp[r]+1$. $O(QN^2)$
	
	## Rešenje kada $N,Q \leq 500$
	Ovaj podzadatak se radi slično kao i prethodni, samo je potrebno da se brže izgradi Dekartovo stablo. Ovo može da se uradi, na primer, tako što se za svaki element niza nađe prvi element levo i desno veći od njega (preko takozvane "stek fore"), i onda je njegov roditelj u Dekartovom stablu upravo manji od ta dva broja. $O(NQ)$
	
	## Rešenje kada svaki upit sadrži maksimum
	Nadalje je jasno da je ključni problem kako brzo nalaziti Dekartovo stablo za podniz ili bar dovoljno informacija o tom Dekartovom podstablu. Ako interval sadrži $M$ čiji je indeks $i$ onda je jasno da je dovoljno rešiti zadatak samo za $[L,i]$ i $[i,R]$ odvojeno, nakon čega lako nalazimo rešenje ukupno. Sada ćemo računati odgovor za svaki interval oblika $[i,R]$ nekom vrstom dinamičkog programiranja, gde ćemo se pozivati na vrednosti koje smo sračunali dinamičkog programiranja za ceo niz (ako bismo prvo rešili zadatak za ceo niz kao u prethodnom podzadatku). Naime neka je $last[R]$ najveći indeks broja većeg od onog na poziciji $R$. Ako je $last[R]=i$, potrebno nam je samo rešenje za interval $[i+1,R-1]$. Ukoliko nije, onda je rešenje jednako rešenju za $last[R]$, ali treba da mu dodamo još proizvod rešenja za $[last[R]+1,R-1]$,$\cdots$, $[last^k[R]+1, last^{k-1}[R]-1]$ (u kasnijim podzadacima ćemo videti tačan razlog ovome). Međutim, sva ova rešenja potproblema koja nam trebaju su zapravo već izračunati u Dekartovom stablu, tako da već za te intervale znamo da rešimo problem i kombinovanjem svega toga možemo rešiti ovaj podzadatak. 
	
	## Rešenje kada je permutacija nasumična
	Inspirisani prethodnim podzadatkom, jasno je da se nekako sve vrti oko maksimuma na intervalu $L,R$, tako da bi bilo lepo kada bismo našli vezu maksimuma na intervalu i Dekartovog stabla. Nije teško uveriti se da je najmanji zajednički predak od $L$ i $R$ zaista maksimum na intervalu $[L,R]$. Međutim, sada dolazi pitanje, kako tačno izgleda to Dekartovo stablo podniza, i da li možemo da ga izrazimo preko Dekartovog stabla početnog niza. Ispostavlja se da možemo, i to na sledeći način: krenimo od čvora $L$ i njegovog desnog podstabla. Sada idemo putem od $L$ do $LCA(L,R)$: ako dođemo u neki čvor iz levog deteta, onda taj čvor izbacujemo, a čvor iz kog smo došli prespojimo sa njegovim dedom. Ovo isto radimo sa $R$, samo zamenimo reči "levo" i "desno". Uverite se sami da ovakva konstrukcija radi!! Kako je permutacija random generisana, zapravo možemo da tvrdimo da je Dekartovo stablo dubine reda veličine $O(\log N)$, pa ovakvu simulaciju možemo da vršimo u $O(Q\log N)$, kao i onda preračunavanje vrednosti dinamičkog programiranja za tih $O(\log N)$ novih vrednosti po upitu.
	
	## Glavno rešenje
	Sada treba nekako izbeći ručnu simulaciju pravljenja novog Dekartovog stabla, kada ne znamo da je ono plitko. Ovo ćemo raditi, naravno, putem **sparse tabela*. Naime za svaki čvor ćemo primetiti da nam je operacija koja se primeni na trenutnu vrednost $dp$ biti oblika linearna oblika $dp$ $->dp\cdot x+c$. Šta mislimo pod ovime? Pa ako imamo vrednost $dp[l]$, onda nalazimo vrednost za $dp[u]=dp[l]\cdot dp[r]+1$, znači transformaciju od $dp[l]$ u $dp[u]$ imamo po gornjoj formuli za $k=dp[r]$, $c=1$. Međutim, ono što je važno primetiti je da je kompozicija dve operacije ovog tipa opet operacija tog tipa (kompozivcija dve linearne funkcije je opet linearna). Tako da mi u sparse tabeli možemo naći kako izgleda formula za $dp[2^k\text{-ti predak od }u]$ preko $dp[u]$. Ono što još važi je da je $x\cdot1+0$, neutral za operaciju kompozicije funkcije. Onda nalazimo rešenje na sledeći način: imamo dve tabele, jedna koja kad idemo na gore od nekog čvora kad uđemo sleva množi rezultat sa vrednosti $dp$ od desnog deteta i dodaje $1$, a ako ulazi sdesna onda ne radi ništa i druga koja radi obrnuto. Nije teško videti da se na ovaj način ako krenemo od $L$ do $LCA(L,R)$ upravo računa rešenje problema za taj podinterval, a takve operacije su sve linearne, pa svaku od njih možemo pretvoriti u spars tabelu, koja nam dozvoljava brzo računanje rešenja za taj podinterval. Zatim radimo to za desnu stranu i spajamo rešenja kao u podzadatku $4$. Složenost $O(Q\log N)$. 
	
	``` cpp title="03_samo_najjaci_opstaju.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 500007
	#define MAXL 20
	#define MOD 1000000007
	using namespace std;
	int a[MAXN],lg[MAXN],rg[MAXN],l[MAXN],r[MAXN],in[MAXN],out[MAXN],p[MAXL][MAXN],t;
	long long dp[MAXN],mul[2][MAXL][MAXN],pls[2][MAXL][MAXN];
	void dfs(int s)
	{
	    in[s]=t++;
	    if(l[s]) dfs(l[s]);
	    if(r[s]) dfs(r[s]);
	    if(l[s] || r[s]) dp[s]=(dp[l[s]]*dp[r[s]]+1)%MOD;
	    else dp[s]=2;
	    out[s]=t++;
	}
	bool insub(int u,int v) {return in[u]>=in[v] && out[u]<=out[v];}
	int LCA(int u,int v)
	{
	    if(insub(v,u)) return u;
	    if(insub(u,v)) return v;
	    for(int j=MAXL-1;j>=0;j--) if(!insub(v,p[j][u])) u=p[j][u];
	    return p[0][u];
	}
	void Init(int N, int* A)
	{
	    a[0]=N+2;
	    a[N+1]=N+1;
	    stack<int> st; st.push(0);
	    for(int i=1;i<=N;i++) a[i]=A[i];
	    for(int i=1;i<=N;i++)
	    {
	        while(a[st.top()]<a[i]) st.pop();
	        lg[i]=st.top();
	        st.push(i);
	    }
	    while(!st.empty()) st.pop();
	    st.push(N+1);
	    for(int i=N;i>=1;i--)
	    {
	        while(a[st.top()]<a[i]) st.pop();
	        rg[i]=st.top();
	        st.push(i);
	    }
	    for(int i=1;i<=N;i++) l[i]=r[i]=0;
	    for(int i=1;i<=N;i++)
	    {
	        if(a[lg[i]]<a[rg[i]])
	        {
	            p[0][i]=lg[i];
	            r[lg[i]]=i;
	        }
	        else
	        {
	            p[0][i]=rg[i];
	            l[rg[i]]=i;
	        }
	    }
	    dp[0]=1;
	    dfs(N+1);
	    p[0][N+1]=N+1;
	    for(int i=1;i<=N;i++)
	    {
	        if(A[i]==N) continue;
	        if(a[lg[i]]<a[rg[i]])
	        {
	            mul[0][0][i]=1;
	            pls[0][0][i]=0;
	            mul[1][0][i]=dp[l[p[0][i]]];
	            pls[1][0][i]=1;
	        }
	        else
	        {
	            mul[0][0][i]=dp[r[p[0][i]]];
	            pls[0][0][i]=1;
	            mul[1][0][i]=1;
	            pls[1][0][i]=0;
	        }
	    }
	    for(int j=1;j<MAXL;j++) for(int i=1;i<=N+1;i++)
	    {
	        p[j][i]=p[j-1][p[j-1][i]];
	        for(int k=0;k<2;k++)
	        {
	            mul[k][j][i]=(mul[k][j-1][i]*mul[k][j-1][p[j-1][i]])%MOD;
	            pls[k][j][i]=(mul[k][j-1][p[j-1][i]]*pls[k][j-1][i]+pls[k][j-1][p[j-1][i]])%MOD;
	        }
	    }
	}
	int Query(int L,int R)
	{
	    int w=LCA(L,R);
	    long long pl=0,ml=dp[r[L]]+1,pd=0,md=dp[l[R]]+1;
	    if(L==w) ml=1;
	    else
	    {
	        for(int j=MAXL-1;j>=0;j--) if(!insub(w,p[j][L]))
	        {
	            ml=(ml*mul[0][j][L])%MOD;
	            pl=(pl*mul[0][j][L]+pls[0][j][L])%MOD;
	            L=p[j][L];
	        }
	    }
	    if(R==w) md=1;
	    else
	    {
	        for(int j=MAXL-1;j>=0;j--) if(!insub(w,p[j][R]))
	        {
	            md=(md*mul[1][j][R])%MOD;
	            pd=(pd*mul[1][j][R]+pls[1][j][R])%MOD;
	            R=p[j][R];
	        }
	    }
	    return ((ml+pl)*(md+pd)+1)%MOD;
	}

	```
