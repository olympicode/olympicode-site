---
hide:
  - toc
---

# A3 - Turizam

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2500ms | 512MB |
	
	Državno takmičenje iz informatike, lokalni bendovi, kao i Vaše legendarno bekstvo, doprineli su tome da Vam Kragujevac ostane u vrlo lepom sećanju. Zbog toga ste odlučili da ostanete tu još $Q$ dana, kako bi ste u potpunosti iskusili svaki deo grada.
	
	Ovog puta se, zbog mnogobrojnih radova na sporednim ulicama, Kragujevac može predstaviti kao niz od $N$ polja. Nekim danima ćete krenuti iz jednog od polja i odatle šetati po gradu. Međutim, opasnost vreba iza svakog ćoška! Kao što ste mogli da pretpostavite, u svakom polju održava generalnu probu po jedan strašni kragujevački bend, koji neće u potpunosti da toleriše vaše prisustvo. Preciznije, svaka bend ima svoj *nivo tolerancije*, gde je nivo tolerancije $i$-tog benda jednak $A_i$.
	
	Tokom svakog od narednih $Q$ dana desi se jedan od sledeća dva događaja:
	
	 - `1 x y`: Nivo tolerancije $x$-te benda, $A_x$, postaje $y$.
	 - `2 x`: Započinjete put iz polja $x$, sa nivoom radoznalosti (skraćeno NR) jednakim $A_x$. U jednom koraku iz polja $i$ možete preći ili na polje $i - 1$ ili na $i + 1$, pod uslovom da je polje u koje prelazite u okviru niza. Kada uđete u polje $i$ sa nivoom radoznalosti $X$, Vaš NR se menja u $X \ \text{and} \ A_i$, tj. bitovsku konjunkciju brojeva $X$ i $A_i$. Ovo radite sve dok NR ne postane nula.
	
	Pošto biste hteli da se pripremite za najnepovoljniji slučaj, interesuje Vas za svaki događaj drugog tipa **minimalan** broj koraka potreban da nivo radoznalosti (NR) postane nula.
	
	## Opis ulaza
	Prvi red standardnog ulaza sadrži ceo broj $N$, broj polja u Kragujevcu. 
	
	U narednom redu se nalazi $N$ celih brojeva koji predstavljaju niz $A_i$.
	
	Naredni red sadrži ceo broj $Q$, broj dana.
	
	Svaki od narednih $Q$ redova sadrži dva ili tri broja: $1, x_i, y_i$ ili  $2, x_i$, odvojena razmakom, koji opisuju $i$-ti događaj.
	 
	Garantuje se da postoji barem jedan događaj drugog tipa.
	
	## Opis izlaza
	Za svaki događaj drugog tipa potrebno je ispisati jedan ceo broj — ukoliko je moguće da NR postane nula, ispisati minimalan broj potrebnih koraka, uostalom ispisati `-1`. 
	
	## Primer 1
	### Ulaz
	```
	7
	7 2 2 7 5 4 4
	10
	2 4
	1 4 6
	2 1
	1 7 4
	2 7
	1 2 4
	1 3 4
	2 5
	1 5 0
	2 5
	```
	
	### Izlaz
	```
	3
	4
	4
	-1
	0
	```
	
	## Objašnjenje primera
	Prvog dana započinjete put iz polja $4$ sa nivoom radoznalosti jednakim $7$. Potrebno je najmanje $3$ koraka da NR postane nula, a jedan od mogućih puteva je $4 \rightarrow 3 \rightarrow 4 \rightarrow 5$. 
	
	Drugog dana nivo tolerancije četvrtog benda postaje 6, pa niz $A$ postaje $[7, 2, 2, 6, 5, 4, 4]$.
	
	Trećeg dana počinjete put iz polja 1 sa nivoom radoznalosti jednakim 7. Potrebno je najmanje $4$ koraka da NR postane nula, što se dostiže putem $1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 5$.
	
	Četvrtog dana nivo tolerancije sedmog benda postaje $4$ (kao što je i ranije bio), pa niz $A$ ostaje $[7, 2, 2, 6, 5, 4, 4]$.
	
	Petog dana počinjete put iz polja 7 sa nivoom radoznalosti jednakim 4. Potrebno je najmanje $4$ koraka da NR postane nula, što se dostiže putem $7 \rightarrow 6 \rightarrow 5 \rightarrow 4 \rightarrow 3$.
	
	Nakon događaja šestog i sedmog dana, niz će biti $[7, 4, 4, 6, 5, 4, 4]$.
	
	Osmog dana počinjete put iz polja 5 sa nivoom radoznalosti jednakim 5. Može se pokazati da nijedan niz koraka ne može smanjiti NR na nulu.
	Devetog dana niz postaje $[7, 4, 4, 6, 0, 4, 4]$.
	
	Desetog dana počinjete put iz polja 5 sa nivoom radoznalosti jednakim 0. Kako je NR već 0, nije potrebno napraviti nijedan korak.
	
	## Ograničenja
	
	- $1 \leq N, Q \leq 10^5$.
	- $0 \leq A_i < 2^{20}$ za $1 \leq i \leq N$.
	- $T_i \in \{1, 2\}$ za $1 \leq i \leq Q$.
	- $1 \leq X_i \leq N$ za $1 \leq i \leq Q$.
	- $0 \leq Y_i < 2^{20}$ za $1 \leq i \leq Q$ i $T_i = 1$. 
	
	Test primeri su podeljeni u šest disjunktnih grupa:
	
	- U test primerima vrednim $4$ poena, $N, Q \leq 100$.
	- U test primerima vrednim $11$ poena, $N, Q \leq 500$.
	- U test primerima vrednim $14$ poena, sve vrednosti $A_i$ i $Y_i$ će biti $0$, $1$, $2$ ili $3$.
	- U test primerima vrednim $15$ poena, $N,Q \leq 5000$.
	- U test primerima vrednim $19$ poena, svi događaji su drugog tipa.
	- U test primerima vrednim $37$ poena nema dodatnih ograničenja.
	
	## Napomena
	Operator konjunkcije u Pascal-u je označen sa `and`, dok u C++ ga zapisujemo pomoću simbola `&`. Ova operacija $x\ \text{and} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 1$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{and} \  y$.
	
	Bitovska konjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{and} \ x_{2}  \ \text{and} \  ...  \ \text{and} \  x_{n} = (...(((x_{1}  \ \text{and} \  x_{2})  \ \text{and} \  x_{3}) \ \text{and} \ x_{4})...)  \ \text{and} \  x_{n}$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Jovan Bengin | Jovan Bengin | Jovan Bengin | Igor Pavlović |
	
	## Analiza
	Prvo, primetimo da ćemo uvek posetiti neki podniz koji sadrži početno polje $x$. Ako je podniz koji posetimo $[L, R]$, NR na kraju će biti $A_L \ \text{and} \ A_{L+1} \ \text{and} \ \ldots{} \ \text{and} \ A_R$ (zapisaćemo kao $f(L, R)$), a minimalan broj koraka da se poseti je $R - L + min(x - L, R - x)$ (tako što iz početka odemo do leve granice, pa do desne, ili obrnuto).
	
	## Rešenje prvog podzadatka
	U ovom podzadatku možemo iterirati kroz svaku moguću levu i desnu granicu, i ukupnu $\text{and}$ vrednost računati jednim prolaskom kroz podniz.
	
	Ukupna složenost: ${\mathcal O}(QN^3)$
	
	## Rešenje drugog podzadatka
	Isto ćemo iterirati kroz svaku moguću levu i desnu granicu, ali ćemo čuvati vrednosti $f(L, x)$ i $f(x, R)$ i ažurirati ih tokom iteracija. Sada ne moramo da iteriramo kroz ceo podniz da bismo našli $f(L, R)$, već ga dobijemo iz sačuvane dve vrednosti.
	 
	Ukupna složenost: ${\mathcal O}(QN^2)$
	
	## Rešenje trećeg podzadatka
	Za naredne podzadatke potrebna nam je još jedna ključna opservacija: optimalni podniz će uvek imati levu i desnu granicu u poljima gde se ukupan NR menja, tj. u $L$ i $R$ takvim da važi $f(L, x) \neq f(L + 1, x)$ (ili $L = x$) i $f(x, R) \neq f(x, R - 1)$ (ili $R = x$). Ovo je tačno jer, ako je na granici polje koje ne menja NR, možemo ga samo izbaciti iz podniza.
	
	U ovom podzadatku je, dakle, moguće samo nekoliko slučajeva: da direktno idemo iz $x$ u najbližu nulu, da idemo iz $x$ do najbliže leve jedinice i do najbliže desne dvojke (ili obrnuto), ili da, ako su željena jedinica i dvojka sa iste strane, odemo iz $x$ do dalje od njih.
	
	Pozicije najbliže leve i desne nule, jedinice i dvojke možemo naći preko strukture *std::set* i njene funkcije *upper_bound*.
	
	Ukupna složenost: ${\mathcal O}(QlogN)$
	
	## Rešenje četvrtog podzadatka
	Pozicije koje menjaju NR su zapravo one za koje važi da postoji neki bit koji se ne nalazi u njenom elementu, ali se nalazi u elementima na svim pozicijama od nje do $x$.
	
	Za svaki bit možemo jednim prolaskom kroz niz naći najbližu levu i desnu poziciju čiji element ne sadrži taj bit, neka su za $i$-ti bi te dve pozicije $l_i$ i $r_i$, a naš interval mora da sadrži ili jednu ili drugu. Drugim rečima, uslov možemo da formulišemo kao: ako je leva granica veća od $l_i$, onda je desna granica veća jednaka $r_i$.
	Zato možemo da iteriramo kroz sortiran niz potencijalnih levih granica (kojih ima $log(A_i)$) i da održavamo trenutnu minimalnu desnu granicu, i tako nalazimo minimalno rešenje.
	
	Složenost ovog algoritma je  ${\mathcal O}(QNlog(A_i))$, što bi uz pokoju optimizaciju prošlo. Međutim, nalaženje levih i desnih granica može da se uradi u ${\mathcal O}(N + log(A_i))$ umesto ${\mathcal O}(Nlog(A_i))$, tako što počnemo iz $x$ i krećemo se levo ili desno (u zavisnosti od toga koju granicu nalazimo), čuvajući trenutnu $\text{and}$ vrednost tog intervala. Kada se ta vrednost promeni, iteriramo kroz one bitove gde se promenila i za njih određujemo da im je granica na toj poziciji.
	
	Ukupna složenost: ${\mathcal O}(Q(N + log(A_i)))$
	
	## Rešenje petog podzadatka
	U ovom podzadatku ćemo brže nalaziti pozicije nula: za svaki bit čuvamo niz pozicija čiji elementi nemaju taj bit. Sada možemo binarnom pretragom da brzo nađemo željene elemente.
	
	Ukupna složenost: ${\mathcal O}(Qlog(N)log(A_i))$
	
	## Glavno rešenje
	Glavno rešenje se radi na isti način kao peti podzadatak, samo što se umesto niza pozicija koristi struktura *std::set*, koja se lako može ažurirati u slučaju događaja prvog tipa.
	
	Ukupna složenost: ${\mathcal O}(Qlog(N)log(A_i))$
	
	``` cpp title="06_turizam.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	using ll = long long;
	using ld = long double;
	
	const int N = 200000;
	
	int a[N+5];
	set <int> nule[20];
	
	int calc(int l, int p, int r){
	    return r - l + min(p - l, r - p);
	}
	
	int main(){
	    ios_base::sync_with_stdio(false), cin.tie(0);
	    cout.precision(10);
	    cout << fixed;
	
	    int n;
	    cin >> n;
	    for(int i=1; i<=n; i++){
	        cin >> a[i];
	        for(int j=0; j<20; j++){
	            if(!((1 << j) & a[i])) nule[j].insert(i);
	        }
	    }
	    int q;
	    cin >> q;
	    while(q--){
	        int typ;
	        cin >> typ;
	        if(typ == 1){
	            int x, y;
	            cin >> x >> y;
	            for(int j=0; j<20; j++){
	                bool pre = ((1 << j) & a[x]);
	                bool posle = ((1 << j) & y);
	                if(pre && !posle) nule[j].insert(x);
	                if(!pre && posle) nule[j].erase(x);
	            }
	            a[x] = y;
	        }
	        else{
	            int id;
	            cin >> id;
	            vector <pair <int, int>> vec;
	            int res = 2*n;
	            bool bad = 0;
	            for(int j=0; j<20; j++){
	                if(!((1 << j) & a[id])) continue;
	                if(!nule[j].size()){
	                    bad = 1;
	                    break;
	                }
	                auto x = nule[j].upper_bound(id);
	                if(x == nule[j].begin()){
	                    vec.push_back({0, *x});
	                    continue;
	                }
	                auto p = x;
	                p--;
	                if(x == nule[j].end()){
	                    vec.push_back({*p, n + 1});
	                }
	                else{
	                    assert(*p <= id);
	                    vec.push_back({*p, *x});
	                }
	            }
	            if(bad){
	                cout << "-1\n";
	                continue;
	            }
	            int mxd = id;
	            sort(vec.begin(), vec.end());
	            for(auto c : vec){
	                if(c.first >= 1 && mxd <= n) res = min(res, calc(c.first, id, mxd));
	                mxd = max(mxd, c.second);
	            }
	            if(mxd <= n){
	                res = min(res, calc(id, id, mxd));
	            }
	            cout << res << "\n";
	        }
	    }
	    return 0;
	}

	```
