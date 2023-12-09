---
hide:
  - toc
---

# 3 - Igrica

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2500ms | 256MB |
	
	
	Glavna tema o kojoj se ovih dana priča u Bajtoviji je najnovija video igrica. Cilj ove igre je borba protiv YY čudovišta. Ovo stvorenje je dobilo svoje ime po tome što ne živi u XY koordinatnom sistemu kao sva ostala čudovišta, već u YY koordinatnom sistemu.
	
	Ova igrica ima $N$ nivoa, i poznato je da za $i$-ti nivo, igrač može da nanese štetu od $A_i$ poena YY čudovištu, koristeći jednu jedinicu energije. Junakinja naše priče, Jovana, planira da narednih $Q$ dana igra ovu igricu. Za svaki dan poznata je vrednost $T_i$. 
	
	Ako je $T_i = 1$, Jovana $i$-tog dana prelazi nivoe $L_i$, $L_{i+1}$, $\dots$, $R_i$ tim redom i svaki nivo započinje sa $S_i$ energije. Kako svi vole ovu igricu, svaki put kada Jovana započne neki nivo još jedan stanovnik Bajtovije se uključi kao njen saigrač, tako da na nivou $L_i$ ona ima jednog saigrača, na nivou $L_{i+1}$ dva saigrača, i tako dalje, pa na kraju na nivou $R_i$ ima $R_i - L_i + 1$ saigrača. Na svakom nivou ona potroši najveći broj jedinica energije na pomaganje saigračima, tako da na svakog od njih potroši isti ceo broj energije, a ostatak energije potroši da nanese štetu YY čudovištu.
	
	Formalno, ukupna šteta je $\Sigma_{m=1}^{R_i - L_i + 1} A_{L_i + m - 1} \cdot (S_i$ $mod$ $m)$, gde $x$ $mod$ $y$ predstavlja ostatak broja $x$ pri deljenju brojem $y$.
	
	Ako je $T_i = 2$, $i$-tog dana se igrica ažurira tako da se $A_{L_i}$ promeni na $R_i$. Ažuriranje traje ceo dan i tako da nije moguće igrati igricu.
	
	Za svaki dan kada Jovana igra igricu, odredite ukupnu štetu koju će da nanese YY čudovištu.
	
	## Primer
	
	Neka su $N = 5$ i $Q = 5$, i neka su nizovi $A = \{7, 2, 3, 9, 4\}$, $T = \{1, 1, 2, 1, 1\}$, $L = \{3, 1, 3, 1, 1\}$, $R = \{5, 5, 5, 5, 3\}$ i $S = \{7, 100, \varnothing, 100, 1\}$.
	
	- Odgovor za prvi dan je $3 \cdot (7$ $mod$ $1)$ $+$ $9 \cdot (7$ $mod$ $2)$ $+$ $4 \cdot (7$ $mod$ $3)$ $=$ $0 + 9 + 4$ $=$ $13$.
	- Odgovor za drugi dan je $7 \cdot (100$ $mod$ $1)$ $+$ $2 \cdot (100$ $mod$ $2)$ $+$ $3 \cdot (100$ $mod$ $3)$ $+$ $9 \cdot (100$ $mod$ $4)$ $+$ $4 \cdot (100$ $mod$ $5)$ $=$ $0 + 0 + 3 + 0 + 0$ $=$ $3$.
	- Trećeg dana vrednost $A_3$ postaje $5$.
	- Odgovor za četvrti dan je $7 \cdot (100$ $mod$ $1)$ $+$ $2 \cdot (100$ $mod$ $2)$ $+$ $5 \cdot (100$ $mod$ $3)$ $+$ $9 \cdot (100$ $mod$ $4)$ $+$ $4 \cdot (100$ $mod$ $5)$ $=$ $0 + 0 + 5 + 0 + 0$ $=$ $5$.
	- Odgovor za peti dan je $7 \cdot (1$ $mod$ $1)$ $+$ $2 \cdot (1$ $mod$ $2)$ $+$ $5 \cdot(1$ $mod$ $3)$ $=$ $0 + 2 + 5$ $=$ $7$.
	
	Nakon poziva vaše funkcije niz $O$ treba da bude jednak $\{13, 3, \varnothing, 5, 7\}$.
	
	## Opis funkcije
	
	Potrebno je da implementirate funkciju
	
	* $Resi(N, A[\ldots], Q, T[\ldots], L[\ldots], R[\ldots], S[\ldots], O[\ldots])$
	
	gde je $N$ broj nivoa video igrice, a $Q$ broj dana. Nizovi $T$, $L$, $R$ i $S$ opisuju događaje u narednih $Q$ dana. U niz $O$ potebno je upisati odgovore na pitanja za sve dane kada je $T_i = 1$. Nije potrebno ništa upisivati kao vrednosti za ostale članove niza $O$ (kada je $T_i = 2$).
	
	**Svi nizovi su indeksirani od 1.**
	
	## Ograničenja
	
	- $1 \leq N, Q, A_i \leq 10^5$
	- Za $T_i = 1$ važi $1 \leq L_i \leq R_i \leq N$, $1 \leq S_i \leq 10^5$
	- Za $T_i = 2$ važi $1 \leq L_i \leq N$, $1 \leq R_i \leq 10^5$
	
	## Podzadaci
	
	- **[8 poena]:** $N, Q \leq 1000$
	- **[12 poena]:** Za $T_i = 1$ važi $S_i \leq 10$
	- **[24 poena]:** $A_i = 1$ za sve $1 \leq i \leq N$ i $T_i = 1$ za sve dane
	- **[20 poena]:** $T_i = 1$ za sve dane
	- **[36 poena]:** Bez dodatnih ograničenja
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može da sadrži i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int* A, int Q, int* T, int* L, int* R, int* S, long long* O);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova, ali ne smeju da pristupaju van njihovih granica.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Obaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu broj $N$.
	* U drugom redu niz $A$ od $N$ brojeva.
	* U trećem redu broj $Q$.
	* U narednih $Q$ redova po 3 ili 4 broja koji predstavljaju upite.
	
	Zatim ovaj program poziva vašu funkciju i štampa, u zasebnim redovima, odgovore na upite prvog tipa koje je vaša funkcija upisala u niz $O$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Tadija Šebez | Tadija Šebez | Nikola Milosavljević |
	
	## Rešenje kada je $N, Q \leq 1000$
	
	Na upite za ovaj podzadatak moguće je odgovoriti direktnim izračunavanjem tražene sume.
	
	## Rešenje kada je $S_i \leq 10$
	
	Upite možemo da rešavamo iz dva dela. Prvih $S_i$ članova sume možemo da uračunamo direktno po formuli kao u prošlom podzadatku, a za ostale članove znamo da je $m > S_i$ pa je $S_i$ $mod$ $m = S_i$, te je dovoljno naći njihovu sumu i pomnožiti je sa $S_i$. Za brze upite o sumi na podnizu možemo da koristimo strukturu podataka **binarno indeksirano stablo** ili **segmentno stablo**. Ove strukture podržavaju izmenu članova niza, tako da lako možemo da podržimo i ažuriranja igrice. Vremenska složenost je $O((N+Q)logN)$.
	
	## Rešenje kada je $A_i = 1$ i $T_i = 1$
	
	U ovom podzadatku upiti se svode na izračunavanje sume $\Sigma_{m=1}^{R_i - L_i + 1} (S_i$ $mod$ $m)$. Primetimo da je $S_i$ $mod$ $m = S_i - \lfloor \frac{S_i}{m} \rfloor \cdot m$, pa možemo sumu da rastavimo po minusu. Prvi deo je $S_i \cdot (R_i - L_i + 1)$ i od njega oduzimamo drugi deo koji računamo iz više delova. Prvih $\sqrt{S_i}$ članova sume računamo direktno po formuli. Za ostale članove postoji najviše $\sqrt{S_i}$ različitih vrednosti za $\lfloor \frac{S_i}{m} \rfloor$ i možemo da odredimo levu i desnu granicu za svaku vrednost tako da možemo da izračunamo $\Sigma_{m=l}^{r} \lfloor \frac{S_i}{m} \rfloor \cdot m$ kao $\lfloor \frac{S_i}{m} \rfloor \Sigma_{m=l}^{r} m$ primenom formule za zbir uzastopnih prirodnih brojeva ili prekalkulisanjem ovih suma. Vremenska složenost je $O(Q \sqrt{S})$.
	
	## Rešenje kada je $T_i = 1$
	
	Upite rešavamo na sličan način kao u prethodnom podzadatku, ali su formule malo komplikovanije. Prekalkulisaćemo prefiksne sume niza $A_i$ i niza $A_i \cdot i$. Pronalazimo grupe kao u prošlom podzadatku i umesto zbira uzastopnih celih brojeva, koristićemo prekalkulisane vrednosti. $\Sigma_{m=l}^{r} A_{L_i + m - 1} \cdot \lfloor \frac{S_i}{m} \rfloor \cdot m$ se svodi na izračunavanje $\Sigma_{m=l}^{r} A_{L_i + m - 1} \cdot m$ pošto je vrednost $\lfloor \frac{S_i}{m} \rfloor$ fiksna za svaku grupu. Izračunavanje pomenute sume moguće je preko suma podniza niza $A_i$ i $A_i \cdot i$. vremenska složenost je $O(Q \sqrt(S))$
	
	## Rešenje za sve bodove
	
	Za celo rešenje potrebno je još podržati operacije izmene niza. Dovoljno je umesto prekalkulisanih prefiksnih suma koristiti **binarno indeksirano stablo** za održavanje suma na podnizu. Vremenska složenost ovog rešenja je $O(Q \sqrt{S} log N)$
	
	``` cpp title="03_igrica.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	#define ll long long
	
	const int N=100050;
	
	struct BIT {
		ll sum[N];
		void init() {
			for (int i = 0; i < N; ++i)
				sum[i] = 0;
		}
		BIT() { init(); }
		ll Get(int i) {
			ll ans = 0;
			for (; i > 0; i -= i & -i)
				ans += sum[i];
			return ans;
		}
		ll Get(int l, int r) {
			return Get(r) - Get(l - 1);
		}
		void Add(int i, ll x) {
			for(; i < N; i += i & -i)
				sum[i] += x;
		}
	} BT1, BTi;
	
	void Resi(int n, int *a, int q, int *t, int *l, int *r, int *s, ll *o) {
		for (int i = 1; i <= n; ++i) {
			BT1.Add(i, a[i]);
			BTi.Add(i, (ll)a[i] * i);
		}
		for (int i = 1; i <= q; ++i) {
			if (t[i] == 1) {
				o[i] = 0;
				int sq = ceil(sqrt(s[i]));
				for (int j = l[i]; j <= min(r[i], l[i] + sq); ++j)
					o[i] += (ll)a[j] * (s[i] % (j - l[i] + 1));
				int ptr = l[i] + sq + 1;
				while (ptr <= r[i]) {
					int m = ptr - l[i] + 1;
					int x = s[i] / m;
					int L = ptr, mR, R;
					if (x == 0) {
						R = r[i];
					} else {
						mR = s[i] / x;
						R = l[i] + mR - 1;
					}
					R = min(R, r[i]);
	
					ll sum = BT1.Get(L, R);
					ll sumi = BTi.Get(L, R);
					sumi -= sum * (l[i] - 1);
	
					o[i] += sum * s[i];
					o[i] -= sumi * x;
					ptr = R + 1;
				}
			} else {
				BT1.Add(l[i], r[i] - a[l[i]]);
				BTi.Add(l[i], (ll)(r[i] - a[l[i]]) * l[i]);
				a[l[i]] = r[i];
			}
		}
	}

	```
