---
hide:
  - toc
---

# A2 - Spec zadatak

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	
	Spec (skraćeno od specifična) vrednost niza se računa kao **proizvod** svih elemenata niza podeljen sa brojem elemenata tog niza. Npr. spec vrednost niza $[5, 9, 7]$ je $\frac{5 \cdot 9 \cdot 7}{3} = 105$.
	
	Spec X-0-1-transformacija niza transformiše niz tako što svaki element **koji nije $0$ ili $X$** postaje $1$. Npr. spec 3-0-1-transformacija niza $[4, 3, 2, 0, 3, 1, 0, 5]$ će transformisati ovaj niz u: $[1, 3, 1, 0, 3, 1, 0, 1]$.
	
	Spec L-R-odsecanje niza se radi tako što iz niza izbrišemo sve elemente čiji je **indeks** manji od $L$ ili veći od $R$ (računamo da indeksiranje počinje od $0$, i $L \leq R$). Npr. nakon spec 2-5-odsecanja niza $[3, 6, 2, 5, 3, 10, 0, 4]$ će ostati niz $[2, 5, 3, 10]$.
	
	Dat vam je niz $A$ koji se sastoji od $N$ celih brojeva. Potrebno je odgovoriti na $Q$ upita, gde se svaki upit sastoji od jednog broja $Q_i$. Za svaki upit je potrebno pronaći brojeve $L$ i $R$ za koje je spec vrednost niza **najveća moguća nakon** što se nad početnim datim nizom uradi spec $Q_i$-0-1-transformacija i spec L-R-odsecanje. Ukoliko postoji više mogućih rešenja, izabrati ono gde je $L$ najmanje, ukoliko i dalje postoji više rešenja izabrati ono gde je $R$ najmanje.
	
	
	## Opis ulaza
	
	Prva linija ulaza sadrži dva broja, broj elemenata niza $N$, i broj upita $Q$.
	Druga linija ulaza sadrži niz $A$ od $N$ brojeva.
	U narednih $Q$ linija ulaza se nalazi po jedan broj $Q_i$.
	
	## Opis izlaza
	
	Na standardni izlaz ispisati $Q$ linija, tako da u $i$-toj liniji budu ispisana dva broja, $L$ i $R$, odvojena razmakom, koji su odgovor na upit $Q_i$.
	
	## Primer 1
	
	### Ulaz
	
	```
	16 7
	4 1 4 5 2 2 3 3 2 3 5 0 5 4 4 2
	5
	3
	2
	1
	4
	6
	3
	```
	
	### Izlaz
	
	```
	3 3
	6 9
	4 4
	0 0
	13 14
	0 0
	6 9
	```
	## Objašnjenje primera
	
	Ukoliko posmatramo peti upit, gde je $Q_i = 4$, nakon spec 4-0-1-transformacije niz će nam biti $[4,1,4,1,1,1,1,1,1,1,1,0,1,4,4,1]$, pa je najbolje odraditi spec 13-14 odsecanje kako bi nam ostao niz $[4,4]$ čija je spec vrednost $8$ što je najveće moguće.
	Ukoliko posmatramo treći upit, gde je $Q_i = 2$, nakon spec 2-0-1-transformacije niz će nam biti $[1,1,1,1,2,2,1,1,2,1,1,0,1,1,1,2]$. Najveću spec vrednost koju možemo dobiti nakon odsecanja je 2 što se može dobiti sa više različitih odsecanja (npr. za $L=15$, $R=15$ ili $L=4$,$R=5$ ili $L=4$,$R=4$), ali po uslovima zadatka treba ispisati $L=4$ i $R=4$.
	U četvrtom i šestom upitu, gde je $Q_i = 1$ i $Q_i = 6$, nakon spec transformacije niz će biti $[1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1]$.
	
	
	## Ograničenja
	
	-   $1 \leq N,Q \leq 300.000$
	-   $0 \leq A_i, Q_i \leq 1.000.000$
	
	Test primeri su podeljeni u 5 podzadatka:
	
	-   **[11 poena]:** $A_i \in \{0, 1, 10^6\}$, odnosno niz se sastoji samo od elemenata $0$, $1$ i $10^6$
	-   **[12 poena]:** $N,Q \leq 200$
	-   **[20 poena]:** $N,Q \leq 1000$
	-   **[22 poena]:** $A_i > 0$, odnosno nema broja $0$ u nizu
	-   **[35 poena]:** Nema dodatnih ograničenja
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dušan Zdravković | Slobodan Mitrović | Aleksa Plavšić |
	
	
	## Analiza
	Najpre, primetimo da je spec vrednost podniza nula (što je i najmanja moguća) ako taj podniz sadrži nulu. Ovo takođe važi bez obzira koju transformaciju primenimo na niz. Tako da ćemo ulazni niz podeliti na maksimalne podnizove koji ne sadrže $0$. Svaki takav podniz ćemo zvati ne-nula.
	
	Neka je $A'$ jedan ne-nula podniz. Prvo ćemo za svako $X$ koje postoji u $A'$ napraviti niz $A_X = (i_1, i_2, \ldots, i_{n_X})$, gde je $i_k$ indeks $k$-tog pojavljivanja broja $X$ u $A'$, a $n_X$ je broj pojavljivanja $X$ u $A'$. Ove nizove ćemo čuvati u C++ map strukturi ili sortirane po $X$ tako da za dato $X$ odgovarajući niz možemo naći u $O(\log N)$ vremenu, npr, binarnom pretragom ako nizove čuvamo sortirane po $X$. Na isti način ćemo obraditi sve ne-nula podnizove. Dakle, C++ map struktura će za dato $X$ čuvati više različitih $A_X$, najviše jedno $A_X$ za dati ne-nula podniz.
	
	### Rešenje za dato $A_X$
	Najpre, ako je $X = 1$ ili ako $X$ ne postoji u ulaznom nizu, tada je rešenje trivijalno -- trebalo bi ispisati ``najlevlji'' podniz dužine $1$ koji sadrži ne-nula vrednost. Dakle, pretpostavimo da $X \ge 2$ i neka je $B_X$ neki podniz za $X$ sa najvećom spec vrednošću. Neka $K$ označava broj pojavljivanja $X$, a $P$ dužinu odgovarajućeg podniza. Lako je zapaziti da spec vrednost podniza raste vrlo brzo, tj., eksponencijalno, sa povećanjem $K$ dok raste linearno sa povećanjem $P$. Vrlo korisna posledica ovog zapažanja je da $B_X$ može da izostavi najviše $\lfloor \log_X N \rfloor$ pojavljivanja broja $X$ -- u suprotnom bi ceo odgovarajući ne-nula podniz $A'$ imao strogo veću spec vrednost nego $B_X$.
	
	Ova zapažanja sada lako vode do rešenja: za dato $X$ posmatrajmo sve podnizove od $A_X$ od indeksa $L$ do indeksa $R$ (indeksi kreću od $1$) tako da $L \le R$ i $(L - 1) + (|A_X| - R) \le \lfloor \log_X N \rfloor$; najbolji od tih podnizova je rešenje za $A_X$. Za dato $X$, ima najviše $(\lfloor \log_X N \rfloor + 1) \cdot (2 + \lfloor \log_X N \rfloor) / 2$ takvih indeksa $L$ i $R$.
	
	### Rešenje za dato $X$ među svim ne-nula podnizovima
	Za svako $A_X$ ćemo naći njegov najbolji podniz $R_X$, gde iteriramo po $A_X$ iz svakog ne-nula podniza. Među svim $R_X$ ćemo ispisati onaj koji imaj najveću spec vrednost; detalji kako da nađemo takav podniz su dati u nastavku.
	
	
	## Smernice za algoritam
	Za konačan algoritam su potrebna još dva detalja.
	
	Prvo, kad jednom izračunamo rešenje za $X = Q_i$, zapamtićemo ovo rešenje, na primer, u nizu veličine $1.000.000$. Cledeći put ako dobijemo upit $X = Q_j$ možemo da vratimo rešenje iz tog niza.
	
	Drugo, tokom obrade upita za dato $X$, iteriraćemo među podnizovima od $A_X$ (kao što je opisano iznad), i za svaki podniz ispisati par $(c, P)$. U ovom slučaju $c$ predstavlja broj pojavljivanja $X$ u datom podnizu od $A_X$, a $P$ predstavlja dužinu tog podniza. Pretpostavimo da $c_1 \ge c_2$ (suprotan slučaj se analogno rešava). Podniz sa $(c_1, P_1)$ ima veću spec vrednost od podniza sa $(c_2, P_2)$ akko $X^{c_1} / P_1 > X^{c_2} / P_2$, što povlači $X^{c_1 - c_2} \cdot P_2 > P_1$. Po konstrukciji imamo $c_1 - c_2 \le \lfloor \log_X N \rfloor$, što povlači da $X^{c_1 - c_2} \cdot P_2$ staje u tip long long.
	
	Koristeći istu ideju za dato $X$ možemo naći najbolji podniz među svim ne-nula podnizovima. Kada imamo više podnizova sa istom spec vrednošću, onda biramo onaj koji je ``levlji'', kao što je to opisano u postavci zadatka. Ovaj deo rešenja se jednostavno implementira.
	
	## Procena složenosti
	Za dato $X$ obrada upita zahteva vreme $(\lfloor \log_X N \rfloor + 1) \cdot (2 + \lfloor \log_X N \rfloor) / 2$ pomnoženo sa brojem ne-nula podnizova koji sadrže $X$ (zapravo, složenost je potencijalno manja jer nije obavezno da svi podnizovi sadrže bar $\lfloor \log_X N \rfloor$ pojavljivanja broja $X$). Imamo $(\lfloor \log_X N \rfloor + 1) \cdot (2 + \lfloor \log_X N \rfloor) / 2 \le 210$, gde se maksimum dostiže za $X = 2$. Za $X > 1000$ imamo $\lfloor \log_X N \rfloor \le 1$, što povlači da je $(\lfloor \log_X N \rfloor + 1) \cdot (2 + \lfloor \log_X N \rfloor) / 2 \le 3$ za većinu vrednosti koja se može naći na ulazu.
	
	Broj svih nepraznih podnizova $A_X$, za sve vrednosti $X$, je najviše $N$. To nam sada daje konačnu složenost od $210 \cdot N$ koja je dovoljno mala za vremensko ograničenje. Kao što je navedeno, razmatranjem nekoliko slučajeva se može pokazati da se ova složenost nikad ne dostiže nego da je bar nekoliko puta manja.
	
	
	``` cpp title="05_spec.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	
	#define MAXN 333555
	#define MAXQ 333555
	#define MAXA 1000333
	
	int n,q;
	long long nll;
	int a[MAXN];
	int resl[MAXA],resr[MAXA];
	
	vector< vector<int> > positions[MAXA];
	
	long long powll(long long x, long long st) {
	    long long r = 1;
	    for(int i=0; i<st; i++) {
	        r *= x;
	    }
	    
	    return r;
	}
	
	bool boljires(int bestK, int bestD, int tk, int td, int x, int stp) {
	
	    if (bestK == -1 || tk > bestK+stp) {
	        return true;
	    }
	
	    if (bestK == tk) {
	        if (td < bestD) return true;
	    }
	
	    if (tk > bestK) {
	        if (powll((long long)x, tk-bestK) * (long long)bestD > (long long)td) {
	            return true;
	        }
	    }
	
	    if (td < bestD) {
	
	        if (bestK - tk > stp) return false;
	
	        if ((long long)bestD > (long long)td * powll((long long)x, bestK-tk)) {
	            return true;
	        }
	    }
	
	    return false;
	}
	
	int main() {
	
	    scanf("%d%d", &n, &q);
	    nll = n;
	
	    int last0 = -1;
	    int firstNon0 = -1;
	    for(int i=0; i<n; i++) {
	        scanf("%d", &a[i]);
	
	        if (a[i] == 0) {
	            last0 = i;
	            continue;
	        }
	
	        if (firstNon0 == -1) firstNon0 = i;
	
	        if (a[i] > 1) {
	            if (positions[a[i]].empty() || last0 > positions[a[i]].back().back()) {
	                vector<int> vec;
	                vec.push_back(i);
	                positions[a[i]].push_back(vec);
	            } else {
	                positions[a[i]].back().push_back(i);
	            }
	        }
	
	    }
	    if (firstNon0 == -1) firstNon0 = 0;
	
	    for(int i=0; i<q; i++) {
	
	        int x;
	        scanf("%d", &x);
	
	        if (resl[x] == 0) {
	            
	            if (positions[x].empty()) {
	                resl[x] = firstNon0;
	                resr[x] = firstNon0;
	            } else {
	
	                int bestK = -1;
	                int bestD = -1;
	
	                int stp = 2;
	                long long t = x;
	                while(t < nll) {
	                    t*=x;
	                    stp++;
	                }
	
	                for(int j=0; j<positions[x].size(); j++) {
	
	                    int cnt = positions[x][j].size();
	                    for(int pl = 0; pl<cnt; pl++) {
	                        for(int pr = max(pl,cnt-stp+pl); pr<cnt; pr++) {
	
	                            int posl = positions[x][j][pl];
	                            int posr = positions[x][j][pr];
	                            
	                            int tk = pr-pl + 1;
	                            int td = posr-posl + 1;
	
	                            if (boljires(bestK,bestD,tk,td,x,stp)) {
	                                bestK = tk;
	                                bestD = td;
	
	                                resl[x] = posl;
	                                resr[x] = posr;
	                            }
	                        }
	                    }
	
	                }
	            }
	
	            resl[x]++;
	            resr[x]++;
	        }
	
	        printf("%d %d\n", resl[x]-1, resr[x]-1);
	    }
	
	
	    return 0;
	}
	```
