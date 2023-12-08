---
hide:
  - toc
---

# 2 - Kompresovani niz

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 256MB |
	
	Članovi komisije su odlučili da takmičarima olakšaju čitanje tekstova, te je tekst ovog zadatka napisan formalno:
	
	Dat je niz $A$ sa $N$ elemenata i broj $K$. Na nizu se primenjuju operacije sledećeg tipa, **sve dok je to moguće**:
	
	 - Izabere se podniz uzastopnih elemenata između pozicija $L$ i $R$ (uključujući i te dve pozicije), **dužine tačno $K$** (dakle $K  = R-L+1$) i ceo podniz se zameni jednim elementom, koji ima vrednost $A_L \ \text{or} \  A_{L+1} \ \text{or} \ ... \ \text{or} \ A_{R-1} \ \text{or} \  A_{R}$. Operacija $x \ \text{or} \  y$ označava operaciju bitovske disjunkcije. Detaljnije informacije možete pročitati u napomeni.
	 
	 Formalno, označimo sa $B$ niz dobijen posle primene jedne operacije na nizu $A$ sa $N$ elemenata. Niz $B$ ima $N-(K-1)$ elemenata i to sa sledećim vrednostima:
	 
	 - $B_i = A_i$ za $1 \leq i < L$.
	 - $B_L = A_L \ \text{or} \  A_{L+1} \ \text{or} \ ... \ \text{or} \ A_{R-1} \ \text{or} \  A_{R}$.
	 - $B_i = A_{i+(K-1)}$ za $L < i \leq N-(K-1)$.
	
	Nakon što u nizu ostane manje od $K$ elemenata, posmatramo sumu elemenata koji su preostali. Cilj je da **minimizujete sumu** elemenata koji preostanu na kraju. 
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	-   $Resi(N,  A[\ldots], K)$
	
	Funkcija $Resi$ se poziva samo jednom na početku ivršavanja programa, a njeni parametri su $N$, $A[\ldots]$ i $K$. Povratna vrednost funkcije reši je minimalna suma elemenata, nakon primene najvećeg mogućeg broja operacija. **Niz A je indeksiran od 1**.
	
	## Primer
	Neka je $N=4$,  $A=[2,6,12,5]$, $K=3$. Nakon primene operacije na poslednja tri elementa originalnog niza $A$, dobija se niz $[2,6 \ \text{or} \  12 \ \text{or} \  5] = [2,15]$ sa sumom $17$. Lako se utvrđuje da je ovo najmanja moguća suma, te je potrebno vratiti vrednost $17$.
	
	## Ograničenja
	
	- $2 \leq K \leq N \leq 400.000$.
	- $0 \leq A_i \leq 1.000.000.000$.
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadatka:
	
	-   **[7 poena]:** $N \le 10$.
	-   **[9 poena]:** $K \le 3$ i $N \le 100.000$.
	-   **[15 poena]:** Sve vrednosti u nizu $A$ su $1$ ili $2$ i $N \le 100.000$.
	-   **[22 poena]:** $N \le 3.000$.
	-   **[29 poena]:** $N \le 100.000$.
	-   **[18 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl  `kompresovani_niz.cpp`  koji implementira pomenute funkcije. Osim traženih funkcija, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija moraju biti sledećeg oblika:
	
	`long long Resi(int N, int* A, int K);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl  `code.cpp`  koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program  `grader.cpp`  koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	-   U prvom redu brojevi $N$ i $K$.
	-   U narednom redu $N$ brojeva: $A_i$.
	
	Zatim ovaj program zove vašu funkciju i ispisuje rezultate koje ona vrati.
	
	
	## Napomena
	Operator disjunkcije je u  C++ zapisan pomoću simbola `|`. Ova operacija $x\ \text{or} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 1$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{or} \  y$.
	
	Bitovska disjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{or} \ x_{2}  \ \text{or} \  ...  \ \text{or} \  x_{n} = (...(((x_{1}  \ \text{or} \  x_{2})  \ \text{or} \  x_{3}) \ \text{or} \ x_{4})...)  \ \text{or} \  x_{n}$.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Aleksa Milisavljević | Vladimir Milenković |
	
	## Rešenje kada $N \leq 10$
	U ovom podzadatku možemo testirati svaki mogući niz primene operacija. Za dato $K$ imamo $N-K+1 = (N - (K-1))$ opcija za primenu prve operacije. Posle prvog koraka, broj elemenata se smanji za $K-1$, pa u drugom koraku imamo $N-2\cdot(K-1)$ opcija. Ukupno, postoji $(N-(K-1)) \cdot (N-2\cdot(K-1)) \cdot ... \cdot ( (K-1) + (N\mod(K-1)))$ različitih sekvenci operacija koje rezultuju nizom dužine manje od $K$. Prethodni proizvod je ograničen sa $(N-1)!$, pa je složenost ovog rešenja $O(N!)$.
	
	## Rešenje kada $K \leq 3$ i  $N \leq 100.000$
	Za naredne podzadatke moramo malo detaljnije analizirati kako primene operacija utiču na niz. Za ovaj podzadatak, dovoljno je primetiti da su elementi krajnjeg niza zapravo kompresovani blokovi uzastopnih elemenata u početnom nizu. Ti blokovi uzastopnih elemenata imaju dužinu $1 \mod (K-1)$, što je lako pokazati. Naime, u početnom nizu blokovi imaju dužinu $1$. Svakom daljom kompresijom se $K$ takvih blokova spaja u jedan blok, koji po modulu $K-1$ ima dužinu $K \cdot 1 = K = 1 \mod (K-1)$. Konačno, za ovaj podzadatak možemo da analiziramo dva slučaja:
	
	 * $K=2$ - tada krajnji niz ima dužinu $1$, a vrednost tog elementa je $\textbf{or}$ vrednosti svih elemenata u početnom nizu
	 * $K=3$ - tada krajnji niz ima dužinu $1$ ukoliko je $N$ neparno i $2$, ukoliko je $N$ parno. Ukoliko je $N$ neparno, tada je vrednost jedinog elementa $\textbf{or}$ vrednosti svih elemenata u početnom nizu. Konačno, ukoliko je $N$ parno, možemo da iteriramo po završetku prvog bloka, koji se završava na nekom neparnom indeksu u početnom nizu i da posmatramo prefiksni i sufiksni $\textbf{or}$ elemenata početnog niza. Rešenje zadatka je minimum njihove sume.
	
	## Rešenje kada $N \le 3.000$
	Ovaj i naredne podzadatke rešavamo dinamičkim programiranjem. Vrednost $dp[i]$ će predstavljati minimalnu vrednost sume ukoliko se ograničimo isključivo na prvih $i$ elemenata niza. Prvo moramo primetiti da je uslov da se operacije primenjuju sve dok niz ima dovoljno elemenata suštinski nevažan. Naime, primenom operacije se suma elemenata niza ne može povećati, te je svakako uvek bolje primeniti što više operacija. Za svaku poziciju $i$, iteriramo po završnoj poziciji prethodnog bloka. Rekurentna formula za naše dinamičko programiranje je $\min_j (dp[j] + A[j+1] \textbf{ or } A[j+2] \textbf{ or } ... \textbf{ or } A[i])$, gde je $i - j = 1 \mod (K-1)$ (jer prema opservaciji iz prethodnog podzadatak važi da je dužina svakog bloka $1 \mod (K-1)$). Ukoliko održavamo vrednost $A[j+1] \textbf{ or } A[j+2] \textbf{ or } ... \textbf{ or } A[i]$, dok iteriramo po $j$, dobijamo rešenje složenosti $O(N^2)$.
	
	## Rešenje kada su sve vrednosti u nizu $A$ su $1$ ili $2$ i $N \le 100.000$
	I u ovom podzadatku ponovo posmatramo blokove. Svaki blok ima vrednost $1$, $2$ ili $3$. Međutim, blok koji se završava na nekoj poziciji $i$ može da ima samo dve vrednosti, a to su $A[i]$ i $3$ (npr. ukoliko $i$-ti element ima vrednost $1$, blok koji se završava na poziciji $i$ nikako ne može da ima vrednost $2$ i obrnuto). Za svaku krajnju poziciju, fiksiramo jednu od te dve moguće vrednosti poslednjeg bloka i posmatramo sve moguće startne pozicije trenutnog bloka. Za njih možemo da održavamo minimum koristeći neku strukturu podataka, na primer `set`.
	
	## Rešenje kada $N \le 100.000$
	Rešenje ovog podzadatka predstavlja nadogradnju na rešenje podzadatka u kojem su sve vrednosti u nizu $A$ jednake $1$ ili $2$. Možemo da primetimo da postoji najviše $\log_2 \max_i A[i] \leq 30$ mogućih različitih vrednosti bloka koji se završava na poziciji $i$ za svako $i$. Sada možemo da fiksiramo jednu od tih vrednosti i pronađemo najraniju poziciju (označimo tu poziciju sa $j$) na kojoj je trenutni blok mogao da počne da bi imao tu vrednost. Zatim, koristeći neku strukturu, npr. `set` pronađemo minimum vrednosti $dp$-ova prethodnog bloka od pozicije $j$ pa do $i$. Ovo možemo da realizujemo koristeći `set` na sledeći način. Možemo da čuvamo $K-1$ `set`-ova, jedan za svaku krajnju pozicija moduo $K-1$. U svakom od njih možemo da čuvamo vrednosti $dp$-ova sortirano po indeksu. Konačno kada ubacujemo $dp[i]$ u `set` koji odgovara modulu $i \mod (K-1)$, treba da izbacimo sve one koje koji se pojavljuju pre njega, a imaju veću vrednost od $dp[i]$. Kada tražimo minimum od pozicije $j$ do pozicije $i$, možemo da pozovemo ugrađenu funkciju `lower_bound`, da bi pronašli prvi indeks veći od $j$ koji postoji u odgovarajućem `set`-u. Složenost ovog rešenja je $O(N \log N \log \max_i A[i])$.
	
	## Glavno rešenje
	Za glavno rešenje i poslednji podzadatak, dovoljno je optimizovati složenost na $O(N \log \max_i A[i])$. Ovo se može postići na primer tako što zamenimo `set` sa spars tabelom. 
	
	``` cpp title="02_kompresovani_niz.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define maxn 400005
	#define maxl 31
	using namespace std;
	int l;
	long long dp[maxn];
	long long prev_bit[maxl];
	long long sprs[maxn][21];
	int val[maxn];
	int bit[2][maxl];
	int pos[2][maxl];
	pair<int,int> v[2][maxl];
	inline long long query(int p,int q) {
	    int k=val[q-p];
	    return min(sprs[q][k],sprs[p+((1<<k)-1)*l][k]);
	}
	long long Resi(int N, int* A, int K)
	{
	    l=K-1;
	    int c=0;
	    for(int j=1;j*l<maxn;j++) {
	        if(2*(1<<c)<=j) c++;
	        val[j*l]=c;
	    }
	    for(int j=0;j<maxl;j++) bit[0][j]=bit[1][j]=j;
	    int g=0;
	    for(int i=1;i<=N;i++) {
	        int c=0;
	        for(int j=0;j<maxl;j++) {
	            if(A[i]&(1<<bit[g][j])) {
	                pos[g^1][c]=i;
	                bit[g^1][c]=bit[g][j];
	                c++;
	            }
	        }
	        for(int j=0;j<maxl;j++) {
	            if(!(A[i]&(1<<bit[g][j]))) {
	                pos[g^1][c]=pos[g][j];
	                bit[g^1][c]=bit[g][j];
	                c++;
	            }
	        }
	        g^=1;
	        dp[i]=A[i]+dp[i-1];
	        int o=0;
	        c=(i-1);
	        int fst=c-l*(c/l);
	        for(int j=0;j<maxl;j++) {
	            if(pos[g][j]==0) break;
	            if(pos[g][j]==i) {
	                o|=(1<<bit[g][j]);
	                continue;
	            }
	            if(j!=0 && pos[g][j]==pos[g][j-1]) {
	                o|=(1<<bit[g][j]);
	                continue;
	            }
	            int rm=c%l;
	            int start=c-l*((c-(pos[g][j]))/l);
	            dp[i]=min(dp[i],query(start,c)+o);
	            o|=(1<<bit[g][j]);
	            if(query(fst,start)+o>dp[i]) break;
	        }
	        int rm=c%l;
	        dp[i]=min(dp[i],query(fst,c)+o);
	        sprs[i][0]=dp[i];
	        for(int j=1;i-((1<<j)-1)*l>=0;j++) {
	            sprs[i][j]=min(sprs[i][j-1],sprs[i-((1<<(j-1)))*l][j-1]);
	        }
	    }
	    return dp[N];
	}

	```
