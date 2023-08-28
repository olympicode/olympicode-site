---
hide:
  - toc
---

# 5 - US Open

=== "Zadatak"

    | Vremensko ograničenje | Memorijsko ograničenje | 
    |:-:|:-:|
    | 1s | 256MB | 

    U finalu ženske divizije prošlogodišnjeg Otvorenog prvenstva Sjedinjenih Američkih Država u tenisu (poznatijem u narodu kao *Ju Es Open*) sastale su se Ema Radukanu i Lejla Fernandez. Neki posvećeniji obožavatelji su primetili da je najduži meč koji je igrala Radukanu na putu do finala (97 minuta) bio kraći od najkraćeg meča koji je odigrala Fernandez na putu do finala (105 minuta).  Ceo teniski svet se složio da je ova činjenica *interesantna*.

    Vi trenutno organizujete svoj turnir sa $N+1$ kola, na kom se već odigralo prvo kolo. Ostalo je još $2^N$ igrača, koji su redom numerisani brojevima $1,2,3,\cdots,2^N$. Turnir je organizovan kao kompletno binarno stablo, a $i$-ti igrač se nalazi u $i$-tom listu tog stabla pri standardnom (levo-koren-desno) obilasku, i u svakom meču pobednik ide dalje, dok gubitnik otpada. Po ugledu na prethodno navedeno finale, vi ste odlučili da je meč *interesantan* ako je dužine barem kao najduži meč koji je do sada igrao igrač sa leve strane žreba (to jest onaj sa manjim indeksom), a dužine najviše najkraćeg meča koji je do sada igrao igrač sa desne strane žreba (to jest onaj sa većim indeksom).

    Poznate su vam dužine trajanja svih mečeva iz prvog kola, a baš cilj je da turnir bude što interesantiji. Za svaki meč potrebno je da izaberete pobednika i dužinu trajanja, tako da bude maksimalno moguće interesantnih mečeva. Igrači će se, naravno, složiti sa vašim predlogom o dužini meča i pobedniku. 

    ## Opisi funkcija

    Potrebno je da implementirate funkciju

    -   $Interesantnost(N,  A[\ldots])$

    gde je $N$ broj kola koje treba još odigrati,  a $A[\ldots]$ niz dužine $2^N$ koji predstavlja dužine trajanja mečeva prvog kola - prvi meč igrača $i$ je trajao $A[i]$ minuta.  **Niz je indeksiran od 1.**

    Funkcija treba da vrati najveći mogući broj interesantnih mečeva.
    ## Primer

    Neka je $N=2$,  $A=\{6,8,10,2\}$.  Prvi meč se igra između igrača čiji su mečevi u prvom kolu  trajali $6$ i $8$ minuta, tako da taj meč mora trajati barem $6$ a najviše $8$ minuta da bi bio interesantan - neka je na primer trajao $7$ minuta, i neka je pobedio igrač broj $2$. Drugi meč da bi bio interesantan, mora da traje barem $10$ a najviše $2$ minuta, tako da očito nikada neće biti interesantan, neka je na primer u njemu pobedio igrač broj $4$ i da je meč trajao $9$ minuta. Sada, u finalu će se sresti igrač $2$ sa leve strane žreba, čiji je najduži meč trajao $8$ minuta, i igrač $4$ sa desen strane žreba, čiji je najkraću meč trajao $9$ minuta. Ako finale traje $8$ minuta, onda će i ono biti interesantno tako da može biti najviše $2$ interesantna meča, pa funkcija treba da vrati $2$. 
    ## Ograničenja

    -   $1 \leq N \leq 20$
    -   $1 \leq A[i] \leq 10^9$

    ## Podzadaci

    Test primeri su podeljeni u $5$ podzadatka:

    -   **[10 poena]:** $N\le4$.
    -   **[17 poena]:** $A[i]\le2$. 
    -   **[18 poena]:** $N\le 17$ i $A[i]\le100$.  
    -   **[26 poena]:** $N\le17$.  
    -   **[29 poena]:** Nema dodatnih ograničenja.

    ## Detalji implementacije

    Potrebno je da pošaljete tačno jedan fajl  `us_open.cpp`  koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.

    Vaša funkcija mora biti sledećeg oblika:

    `int Interesantnost(int N, int* A);`

    **Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**

    Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:

    -   U prvom redu broj $N$.
    -   U narednom redu $2^N$ brojeva: $A[i]$.

    Zatim ovaj program zove vašu funkciju i ispisuje rezultat koji vaša funkcija vrati.

=== "Rešenje"

    | Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
    |:-:|:-:|:-:|:-:|
    | Pavle Martinović | Pavle Martinović | Mladen Puzić | Tadija Šebez |

    Prva stvar koju je potrebno da primetimo jeste   kako da dodelimo vreme trajanja nekom konkretnim meču. Primetimo da nam se uvek isplati da to bude vreme trajanja prvog meča pobednika. Takav meč još uvek ima potencijal da bude interesantan, a ne ograničavamo se za buduće mečeve više nego što moramo. Sada je potrebno samo odrediti pobednika svakog meča dok zamišljamo da se njegovo vreme *propagira* na sledeće kolo.

    ## Rešenje kada $N \leq 4$
    Pošto ima $16$ preostalih igrača, postojaće još ukupno $15$ mečeva. Za svaki meč možemo da odaberemo da li pobeđuje levi ili desni igrač, jer postoji samo $2^{15} = 32768$ kombinacija.

    Vremenska složenost je $O(2^ {2^N})$, a memorijska $O(2^N)$.

    ## Rešenje kada $A[i] \leq 2$
    Jasno je po gornjoj obzervaciji da će svaki meč trajati ili $1$ ili $2$ minuta (mora da igra Đoković). Numerišemo sve mečeve od $1$ do $2^{N+1}-1$. Sada, možemo raditi dinamičko programiranje oblika: 

    $$
    dp[i][1/2] = \text{optimalno rešenje ako meč }i\text{ traje 1, odnosno 2 minuta}
    $$

    Bazni slučajevi su očigledno mečevi prvog kola, za koje znamo koliko su trajali (i onda na jedan slučaj tih mečeva stavljamo $0$, a na drugi $-\infty$). 

    Posmatrajmo neki fiksni meč $i$ koji nije meč prvog kola. Neka je $l$ meč iz kojeg je došao pobednik leve strane žreba, a $d$ meč iz kojeg je došao pobednik leve strane žreba.

    Važe sledeće rekurentne veze: 

    $$
    dp[i][1] = \max(dp[l][1]+dp[r][1]+1, dp[l][1]+dp[r][2]+1, dp[l][2]+dp[r][1])
    $$

    $$
    dp[i][2] = \max(dp[l][2]+dp[r][2]+1, dp[l][1]+dp[r][2]+1, dp[l][2]+dp[r][1])
    $$ 

    Dakle, svaka kombinacija, sem kada je meč $l$ trajao $2$ minuta, a meč $r$ trajao $1$ minut, daje jedan novi interesantan meč. Krajnji rezultat, ako je finale numerisano brojem $f$, je $\max(dp[f][1], dp[f][2])$.

    Vremenska i memorijska složenost je $O(2^N)$.

    ## Rešenje kada $N \leq 17$ i $A[i] \leq 100$
    Slično prethodnom podzadatku, radićemo dinamičko programiranje nad numerisanim mečevima:

    $$
    dp[i][j] = \text{optimalno rešenje ako meč }i\text{ traje } j \text{ minuta}
    $$

    Ponovo imamo tri slučaja:
    - Prvi slučaj je ako ne želimo da trenutni meč bude interesantan. Onda jedan meč (levi ili desni) mora trajati $j$ minuta, za drugi možemo uzeti bilo koju vrednost, pa ćemo uzeti onu koja daje najviše interesantnih mečeva. 
    - Drugi slučaj je da želimo da meč $i$ bude interesantan, a da **levi** meč traje $j$ minuta. Zato, desni meč mora trajati makar toliko, da bismo dobili novi interesantan meč. Uzećemo naravno optimalnu dužinu desnog meča.
    - Treći slučaj je takođe da želimo da meč $i$ bude interesantan, a da **desni** meč traje $j$ minuta. Levi meč onda mora trajati najviše toliko. Ponovo uzimamo optimalnu dužinu levog meča.

    Sve ovo možemo efikasno implementirati čuvajući prefiksne, odnosno sufiksne maksimume nad dinamičkim programiranjem za svaki meč.

    Vremenska i memorijska složenost je $O(2^N\cdot maxA)$.

    ## Rešenje kada $N \leq 17$
    Zadatak ponovo radimo dinamičkim programiranjem, mada ovaj put numerišemo i mečeve i igrače:

    $$
    dp[i][j] = \text{optimalno rešenje ako je pobednik meča }i\text{ igrač } j
    $$

    Ovde na prvi pogled ima $O(2^N\cdot 2^N)$ stanja, ali to nije tačno - broj igrača koji mogu biti pobednici nekog meča (koji su u tom delu žreba) dosta varira. U zbiru, zato, postoji samo $O(2^N \cdot N)$ stanja, jer svaki igrač može biti pobednik u samo $N$ različitih mečeva. Dinamičko programiranje možemo raditi kolo po kolo, krenuvši od drugog kola (prvo je već odigrano).

    Sada, slično prethodnom podzadatku, ako nam je pobednik sa leve strane žreba i želimo interesantan meč, desno moramo odabrati igrača kojem je prvi meč trajao makar koliko prvi meč pobednika. Analogno radimo i ako želimo da pobednik bude iz desne strane žreba.

    Kako bismo to efikasno uradili, moramo u obe polovine imati igrače sortirane po dužini prvog meča. Nakon doga, poput prethodnog zadatka možemo koristeći prefiksne/sufiksne maksimume nad nizom dinamičkog programiranja, kao i tehniku dva pokazivača ili binarnu pretragu, možemo naći odgovarajuće vrednosti. Sve ovo možemo jednostavno implementirati rekurzijom.

    Vremenska složenost je $O(2^N \cdot N^2)$, a memorijska $O(2^N)$ (ako pamtimo uvek samo rezultate prethodnog kola).

    ## Glavno rešenje
    Slično prethodnom podzadatku, samo što umesto da koristimo sortiranje na svakom nivou rekurzije, mi održavamo sortirani niz i spajamo ih tehnikom dva pokazivača, poput algoritma *merge sort*. Time smanjujemo vremensku složenost za $N$ faktor.

    Vremenska složenost je $O(2^N\cdot N)$, a memorijska $O(2^N)$.

    ``` cpp title="us-open.cpp" linenums="1"
    #include <bits/stdc++.h>
    #define MAXN (1<<20)+7
    using namespace std;
    int a[MAXN],b[MAXN],dp[MAXN],aux[MAXN];
    void rek(int l,int r)
    {
        if(l==r) {dp[l]=0; return;}
        int s=(l+r)/2;
        rek(l,s); rek(s+1,r);
        int t1=l,t2=r;
        int mx=0,pmax=-500;
        for(int i=s+1;i<=r;i++) mx=max(mx,dp[i]);
        for(int i=s;i>=l;i--)
        {
            while(t2!=s && a[t2]>=a[i]) pmax=max(pmax,dp[t2--]);
            aux[i]=dp[i]+max(pmax+1,mx);
        }
        mx=0; pmax=-500;
        for(int i=l;i<=s;i++) mx=max(mx,dp[i]);
        for(int i=s+1;i<=r;i++)
        {
            while(t1!=s+1 && a[i]>=a[t1]) pmax=max(pmax,dp[t1++]);
            aux[i]=dp[i]+max(pmax+1,mx);
        }
        t1=l; t2=s+1;
        while(t1<=s || t2<=r)
        {
            if(t1==s+1) {b[t1+t2-s-1]=a[t2]; dp[t1+t2-s-1]=aux[t2]; t2++; continue;}
            if(t2==r+1) {b[t1+t2-s-1]=a[t1]; dp[t1+t2-s-1]=aux[t1]; t1++; continue;}
            if(a[t1]<a[t2]) {b[t1+t2-s-1]=a[t1]; dp[t1+t2-s-1]=aux[t1]; t1++; continue;}
            b[t1+t2-s-1]=a[t2]; dp[t1+t2-s-1]=aux[t2]; t2++;
        }
        for(int i=l;i<=r;i++) a[i]=b[i];
    }
    int Interesantnost(int N,int *A)
    {
        int n=1<<N;
        for(int i=1;i<=n;i++) a[i]=A[i];
        rek(1,n);
        int res=0;
        for(int i=0;i<n;i++) res=max(res,dp[i]);
        return res;
    }
    ```

