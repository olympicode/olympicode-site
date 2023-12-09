---
hide:
  - toc
---

# A1 - Koncert

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 256MB |
	
	
	Važno obaveštenje: održava se koncert najpoznatijih izvođača rok muzike na kome učestvuju Riblja Čorba, Bajaga, Rokeri s Moravu, Dejan Cukić i Rijana! Organi reda su dobili informaciju da su neki učesnici Državnog takmičenja iz informatike (ujedno i ljubitelji turbo-folka) odlučili da se infiltriraju među publikom i prave nerede pevajući pesme Dragane Mirković, Šemse Suljakovića i Tejlor Svift.
	
	Prostor na kome je publika možemo zamisliti kao matricu sa $n$ redova (numerisanih od $1$ do $n$ odozgo nadole) i $m$ kolona gde je red broj $1$ prvi red, neposredno ispred izvođača, a red broj $n$ je poslednji red. Svako polje matrice je ili slobodno (označeno znakom '$0$') ili zauzeto od strane neke osobe (označeno znakom '$1$'). Kada takmičar dođe na koncert **on izabere neko slobodno polje u poslednjem redu i stane tamo** (ako takvih polja nema, ide kući). Nakon toga, u jednom potezu može uraditi jednu od sledeće 2 stvari:
	
	 - Pomeri se za jedno polje iznad (u red ispred) **ukoliko je to polje slobodno**; ili
	 - Pomeri se za jedno polje ulevo ili udesno (u istom redu). **Prilikom pomeranja ulevo/udesno takmičar može gurati jednu ili više osoba u odgovarajućem smeru (ili se samo pomeriti na odgovarajuće polje ako je slobodno)**; preciznije, ako je snaga takmičara $k$, tada, ukoliko se neposredno levo od takmičara nalazi uzastopna grupa od $a$ ($a \geq 0$) osoba nakon koje postoji bar jedno slobodno polje, moguće je pomeriti se ulevo za jedno polje, pri čemu se cela grupa od $a$ osoba takođe pomera za po jedno polje ulevo, ako i samo ako je $a \leq k$. Isto važi i za pomeranje udesno. **Nije dozvoljeno gurati ljude van matrice**.
	
	**Takmičar želi da nekim nizom poteza dođe do nekog polja u prvom redu ali tako da nijedno polje ne poseti više od jednom**. Čim prvi put dođe do nekog polja u prvom redu, **on više ne pravi poteze** već kreće da brejk-densuje i peva "Cvetak zanovetak"; njegov cilj je ostvaren.
	
	Odrediti na koliko načina takmičar može ostvariti svoj cilj i ispisati taj broj po modulu $10^9+7$.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza nalaze se celi brojevi $n$, $m$ i $k$, redom, gde su $n$ i $m$ dimenzije matrice a $k$ snaga takmičara. U narednih $n$ redova, nalazi se po $m$ karaktera, **bez razmaka**, od kojih je svaki '$0$' ili '$1$' - opis prostora na kome je publika.
	
	## Opis izlaza
	
	U jedinom redu standardnog izlaza ispisati broj načina na koje takmičar može ostvariti svoj cilj po modulu $10^9+7$.
	
	## Ograničenja
	- $2 \leq n, m \leq 2000$
	- $0 \leq k \leq m$
	- Svi karakteri matrice iz ulaza će biti '$0$' ili '$1$'.
	
	## Podzadaci
	
	1. (7 poena) Nema ljudi u publici, tj. svi karakteri ulazne matrice će biti '$0$'.
	2. (11 poena) $n,m \leq 7$.
	3. (15 poena) $k = 0$.
	4. (22 poena) $n, m \leq 400$
	5. (45 poena) Bez dodatnih ograničenja.
	
	## Primeri
	
	### Primer 1
	
	### Ulaz
	
	```
	3 9 3
	010001100
	101011010
	011101110
	```
	
	### Izlaz
	
	```
	7
	```
	### Objašnjenje
	Imamo 3 reda i u svakom redu po 9 polja; snaga takmičara je 3. Označimo sa 'U' potez nagore, sa 'L'  potez ulevo i sa 'R'  potez udesno. Ako se krene iz polja (3,1), svi načini su: RURU i RURRU; ako se krene iz polja (3,5), svi načini su: LUU, LULU, LURU; ako se krene iz polja (3, 9), svi načini su: UU i ULU. Ovo je ukupno $7$ mod $(10^9 + 7) = 7$ načina. Primetimo npr da kretanja RUU i RURRRU iz polja (3,1) nisu validna - prvo jer u trećem potezu nije moguće ići nagore kada je polje iznad zauzeto a drugo jer u petom potezu takmičar ne može gurati 4 osobe jer mu je snaga 3.
	
	### Primer 2
	
	### Ulaz
	
	```
	4 5 1
	11000
	00110
	01001
	10001
	```
	
	### Izlaz
	
	```
	0
	```
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Igor Pavlović |
	
	Kako nije dozvoljeno ponavljanje polja na putu, u svakom redu se ide samo u jednom smeru (ulevo ili udesno) ili direktno na gore. Promena strkture reda guranjem ne utiče na dalji deo puta jer nije dozvoljeno vraćanje unazad.
	
	U **Podzadatku 1** je dovoljno koristiti klasično dinamičko programiranje za računanje broja odgovarajućih puteva u $O(nm)$ ili primeniti malo kombinatorike: za svaki od $n$ redova možemo na $m$ načina izabrati polje u koje dolazimo iz prethodnog reda (za poslednji red, to je polje iz koga počinjemo) a nakon toga je put jedinstveno određen. Dakle, odgovor je $m^n$ mod $(10^9 + 7)$. Za **Podzadatak 2** je dovoljno isprobati sve moguće puteve, najednostavnije koristeći rekurziju/bektrek u složenosti $O(m\cdot m^n)$.
	
	Zadatak je najprirodnije rešavati **dinamičkim programiranjem**. Definišimo $d[i][j] =$ broj (validnih) puteva koji se završavaju u polju $(i,j)$ date matrice $a$ pri čemu je poslednji potez "nagore". Konačno rešenje je $\sum_{1 \leq j \leq m, \  a[1][j]=0} d[1][j]$ a početne vrednosti su $d[n][j] = a[n][j]$ za $j=1,2,\ldots,m$. Rekurentna veza je data sa $d[i][j] =\sum_x d[i+1][x]$, gde se sumiranje vrši po svim indeksima $x$ takvih da je (guranjem) u $(i+1)$-om redu moguće doći od pozicije $x$ (koja treba biti prazno polje) do pozicije $j$ (koja ne mora nužno biti prazno polje). Najjednostavniji način je ispitati svaku poziciju $x$ iz $(i+1)$-og reda; ako je $x_L$ pozicija $(k+1)$-ve osobe levo  u odnosu na poziciju $x$ a $x_R$ pozicija $(k+1)$-ve osobe desno  u odnosu na poziciju $x$, tada, sa pozicije $x$ možemo guranjem doći do bilo koje koje (i samo te) pozicije iz segmenta $[x_L+(k+1), x_R-k]$. Vrednosti $x_L$ i $x_R$ za svako $x$ možemo odrediti u svega dva prolaza kroz $(i+1)$-vi red (sleva udesno i sdesna ulevo) npr. ubacivajući pozicije jedinica na koje naiđemo u neki pomoćni vektor. Ovo daje rešenje složenosti $O(nm^2)$ što je dovoljno za **Podzadatak 4**.
	
	U **Podzadatku 3** nema guranja pa se rekurentna veza može uprostiti uvođenjem pomoćnih matrica, npr. $L[i][j]=$ broj puteva koji se završavaju u polju $(i,j)$ pri čemu je poslednji potez "ulevo" i analogno za $R[i][j]$ i "udesno". Sada se sve ove matrice mogu paraleno izračunati, $d[i][j] = d[i+1][j]+L[i+1][j]+R[i+1][j]$, $L[i][j] = L[i][j+1]+d[i][j+1]$, $R[i][j] = R[i][j-1]+d[i][j-1]$ (u odgovarajućem redosledu i proveru zauzetosti polja). To je $O(1)$ po polju tj. $O(nm)$ ukupno.
	
	Za konačno rešenje, treba ubrzati $O(nm^2)$ algoritam. Iz tog rešenja, znamo da će za svako polje $(i+1,x)$, vrednost $d[i+1][x]$ učestvovati u formuli za računanje vrednosti $d[i][j]$ za svako $j\in[x_L+(k+1),x_R-k]$ (uz proveru $d[i][j]=0$ i granice za segment). Zato možemo, nakon obrade $(i+1)$-og reda, za svako $x$ povećati sve $d[i][j]$ iz reda iznad koji su u odgovarajućem segmentu za $d[i+1][x]$. Naravno, direktna implementacija ovoga ne bi smanjila složenost ali možemo koristiti poznati trik; dovoljno je dodati elementu na početku segmenta $+d[i+1][x]$ i dodati elementu nakon kraja segmenta $-d[i+1][x]$ (za svako $x$) i na kraju će tražene vrednosti u novom redu biti prefiksne sume trenutnih vrednosti. Ovo daje algoritam složenosti $O(nm)$.
	
	Alternativno (i nešto jednostavnije rešenje) je definisati $d[i][j]=$broj puteva koji *počinju* iz polja $(i,j)$. Tada vrednosti možemo računati odozgo nadole i, na osnovu prethodne diskusije, važi $d[i][j] = \sum_{j_L + k + 1 \leq x \leq j_R - k} d[i-1][x]$, gde se vrednosti $j_L$ i $j_R$ odnose na trenutni, $i$-ti red. Koristeći prefiksne sume, prethodnu sumu možemo izračunati u $O(1)$ (preciznije, jedan red matrice $d$ računamo u $O(m)$) pa dobijamo algoritam složenosti $O(nm)$.
	
	
	
	
	
	
	``` cpp title="04_koncert.cpp" linenums="1"
	#include<cstdlib>
	#include<cstdio>
	#include<vector>
	
	using namespace std;
	
	const int MOD = 1000000007;
	const int MAX_N = 2000;
	
	int n, m, k;
	char a[MAX_N + 10][MAX_N + 10];
	int dp[MAX_N + 10][2];
	vector<int> v;
	
	int main()
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", a[i] + 1);
		}
	
		int curr = 0;
		for (int j = 1; j <= m; j++)
			if (a[n][j] == '0')
				dp[j][curr] = 1;
			else
				dp[j][curr] = 0;
	
		for (int i = n; i > 1; i--)
		{
			curr = 1 - curr;
			for (int j = 0; j <= m; j++)
				dp[j][curr] = 0;
	
			// left
			v.clear();
			for (int j = 1; j <= m; j++)
			{
				if (a[i][j] == '1')
					v.push_back(j);
				else
				{
					int left = 0;
					if ((int)v.size() > k)
						left = v[v.size() - (k + 1)] + (k + 1);
					else
						left = v.size() + 1;
					dp[left][curr] = (dp[left][curr] + dp[j][1 - curr]) % MOD;
					dp[j][curr] = (dp[j][curr] - dp[j][1 - curr]) % MOD;
				}
			}
	
			// right
			v.clear();
			for (int j = m; j >= 1; j--)
			{
				if (a[i][j] == '1')
					v.push_back(j);
				else
				{
					int right = 0;
					if ((int)v.size() > k)
						right = v[v.size() - (k + 1)] - (k + 1);
					else
						right = m - v.size();
					dp[j][curr] = (dp[j][curr] + dp[j][1 - curr]) % MOD;
					dp[right + 1][curr] = (dp[right + 1][curr] - dp[j][1 - curr]) % MOD;
				}
			}
	
			for (int j = 1; j <= m; j++)
				dp[j][curr] = (dp[j][curr] + dp[j - 1][curr]) % MOD;
			for (int j = 1; j <= m; j++)
				if (a[i - 1][j] == '1') dp[j][curr] = 0;
		}
	
		int sol = 0;
		for (int j = 1; j <= m; j++)
			sol = (sol + dp[j][curr]) % MOD;
		if (sol < 0)
			sol = sol + MOD;
		printf("%d\n", sol);
	
		return 0;
	}
	```
