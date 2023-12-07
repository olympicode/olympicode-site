---
hide:
  - toc
---

# B2 - Veštica

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	
	Denino brdo, inače najveće brdo na svetu, prepuno je veštica. Za održavanje javnog reda i mira na Deninom brdu zadužena je glavna i najškolovanija veštica Anđelija. Ona je upravo odbranila doktorsku disertaciju pod nazivom "Laki leteći objekti" na FCM-u (Fakultet za crnu magiju u Crnoj Reci).
	
	Tajna svake uspešne veštice je u neprestanoj vežbi i ponavljanju različitih magičnih trikova. Anđelija je odlučila da danas vežba sa lebdećim kutijama u svojoj kući. Ona je postavila određeni broj kutija uz zid i svaku podigla na neku visinu. Zid je visok $N$ metara i širok $M$ metara (formalnije, može se predstaviti kao matrica dimenzije $N \times M$), dok je svaka kutija visoka $1$ metar i široka $1$ metar (formalnije, može se predstaviti kao jedno polje u matrici koja označava zid). Na svakoj visini se nalazi određeni broj kutija koje lebde i taj broj je strogo veći od $0$ za svaku visinu. Kutije na nekoj visini su poređane jedna do druge, tako da se mogu označiti jednim intervalom. $[L_i, R_i]$. Za svaku visinu $i$  su nam data dva broja $L_i$, $R_i$, koji označavaju da je prva kutija na toj visini na koordinati $(i, L_i)$, a poslednja na koordinati $(i, R_i)$.
	
	Normalno, Denino brdo naseljavaju i skroz obični ljudi, koji i ne slute da su oko njih veštice. Zato Anđelija želi da ostane neupadljiva, a kutije koje lebde to sigurno nisu. Odlučila je da poređa kutije tako da izgleda da one stoje jedna na drugoj (grade neku figuru koja po malo liči na piramidu). Za ovaj poduhvat je potrebno da interval kutija na određenoj visini bude podinterval kutija na nižoj visni (formalnije, da važe sledeći uslovi:  $L_{i-1} \leq L_i$ i $R_i \leq R_{i-1}$ za $2 \leq i \leq N$).
	
	U jednom potezu Anđelija može da pomeri sve kutije na određenoj visini za $1$ metar levo ili desno. Kutije ne mogu otići van granica zida, odnosno da poseduju koordinatu po širini manju od $1$ i veću $M$. Takođe, nije dozvoljeno menjati visine kutija. Da li možete pomoći Anđeliji da odredi minimalan broj poteza da svoje kutije dovede u red. 
	
	## Opis ulaza
	
	Prva linija standardnog ulaza sadrži dva broja, $N$ i $M$, visinu i širinu zida redom.
	
	Svaka od narednih $N$ linija sadrži po dva cela broja, $L_i$ i $R_i$, početak i kraj intervala kutija koje lebde na visini od $i$ metara.
	
	## Opis izlaza
	
	U jedinoj liniji standardnog izlaza ispisati minimalan broj poteza koji Anđelija treba da napravi.
	
	## Primer 1
	
	### Ulaz
	
	```
	4 8
	1 4
	4 7
	4 5
	3 3
	```
	### Izlaz
	
	```
	4
	```
	
	## Primer 2
	
	### Ulaz
	
	```
	3 3
	1 1
	2 2
	3 3
	```
	
	### Izlaz
	
	```
	2
	```
	
	## Objašnjenje primera
	
	Rešenje prvog primera je predstavljeno na slici ispod.
	
	![](https://petljamediastorage.blob.core.windows.net/competitions/Primer1.PNG)
	
	U drugom primeru je optimalno pomeriti kutiju na visini $1$ za jedan metar u desno, dok kutiju na visini $3$ za jedan metar u levo.
	
	## Ograničenja
	
	-   $1 \leq N,M \leq 10.000$
	-   $1 \leq L_i \leq R_i \leq M$
	-  **Garantuje se da su primeri takvi da uvek postoji rešenje.**
	
	Test primeri su podeljeni u 5 podzadatka:
	
	-   **[13 poena]:** $N,M\leq 5$
	-   **[12 poena]:** Svi intervali kutija su iste dužine ($R_i - L_i + 1 = c$, za $1\leq i \leq N$, i neku celobrojnu konstantu $c$)
	-   **[33 poena]:** $N, M \leq 500$
	-   **[23 poena]:** $N, M \leq 2.000$
	-   **[19 poena]:** Nema dodatnih ograničenja
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksa Plavšić | Slobodan Mitrović | Pavle Martinović |
	
	
	## Analiza
	Počećemo od DP rešenja za ovaj problem. Definisaćemo $DP[row][pos]$ na sledeći način:
	
	$DP[row][pos] =$ najmanji broj poteza koji treba napraviti tako da polica u redu $row$ počinje na poziciji $pos$.
	
	Neka $W_i$ predstavlja dužinu $i$-tog reda, tj., $W_i = R_i - L_i + 1$. Tada za $row > 1$ i $1 \le pos \le M - W_{row} + 1$, $DP[row][pos]$ može da se izračuna na sledeći način:
	
	$$
	DP[row][pos] = |pos - L_i| + \min_{offset = 0 \ldots W_{row} - W_{row - 1}} DP[row - 1][pos + offset]
	$$
	
	Za $row = 1$ imamo $DP[1][pos] = |pos - L_1|$.
	
	Rešenje problema je $\min_{pos = 1 \ldots N - W_N + 1} DP[N][pos]$.
	
	## Analiza složenosti
	Lako je videti da gore opisani način za računanje $DP[row][pos]$ zahteva najviše $O(N \cdot M \cdot M)$ koraka -- za svako od $N \cdot M$ vrednosti $(row, pos)$ treba $W_{row} - W_{row - 1} + 1 \le M$ koraka. $N \cdot M \cdot M$ koraka je presporo za ograničenja u ovom zadatku.
	
	Jedna opcija je da izračunamo $\min$ u definiciji $DP[row][pos]$ efikasnije nego da posetimo svako od $W_{row} - W_{row - 1} + 1$ vrednost u $DP[row - 1]$. Za to postoje bar dva načina.
	
	-- Na primer, ako $DP[row - 1]$ čuvamo u segmentnom stablu onda možemo da nađemo $\min$ datog intervala u $O(\log M)$ vremenu.
	
	-- Ili, računanje $DP[row][pos + 1]$ u odnosu na $DP[row][pos]$ se razlikuje u tome što se ``prozor'' od $W_{row} - W_{row - 1} + 1$ elemenata koji nam trebaju iz $DP[row - 1]$ pomeri za $1$. To znači da ako bismo primenili Metod 3 sa https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/, onda bismo mogli da izračunamo $DP[row][pos + 1]$ u $O(1)$ vremenu, pod pretpostavkom da računamo u redosledu $DP[row][1], DP[row][2], \ldots, DP[row][M - W_{row} + 1]$. Ovo bi bilo dovoljno za rešenje koje radi efikasno na svim primerima.
	
	Druga opcija, ona koju ćemo mi primeniti, jeste da prvo preciznije odredimo složenost gore navedenog pristupa, pa tek onda ako je potrebno da optimizujemo.
	
	## Preciznija analiza složenosti
	Da bismo izračunali $DP[row][pos]$ za \textbf{sve validne} vrednosti $pos$ direktno koristeći formulu iznad treba nam $(M - W_{row} + 1) \cdot (W_{row} - W_{row - 1} + 2)$ operacija -- $(W_{row} - W_{row - 1} + 1)$ dolazi od $\min$, a dodatna operacija od $|pos - L_i|$. Kada sumiramo za sve $row \ge 2$, dobijemo
	
	$$
	\sum_{row = 2}^N (M - W_{row} + 1) \cdot (W_{row} - W_{row - 1} + 2) \le \sum_{row = 2}^N (M + 1) \cdot (W_{row} - W_{row - 1} + 2) = 2 (N - 1) (M + 1) + (M + 1) \sum_{row = 2}^M (W_{row} - W_{row - 1}).
	$$
	
	Svi elementi sem $W_N$ i $W_1$ se zgodno skrate u poslednjoj sumi, te dobijemo
	
	$$
	\sum_{row = 2}^N (M - W_{row} + 1) \cdot (W_{row} - W_{row - 1} + 2) \le 2 (N - 1) (M + 1) + (M + 1) (W_N - W_1) \le 3 (N - 1) (M + 1).
	$$
	
	Drugim rečima, direktna implementcija gore date $DP$ definicije, i verovatno najjednostavnije rešenje ovog problema, je dovoljno efikasna za sve test primere.
	
	## Optimizacija potrošnje memorije
	$DP$ ne možemo deklarisati sa $10000 \times 10000$ polja jer to zauzima više memorije nego što je dozvoljeno. Umesto toga, dovoljno je da u memoriji čuvamo samo $DP[row]$ i $DP[row - 1]$, gde je $row$ red koji se trenutno obrađuje. To nam omogućava da znatno uštedimo na memoriji.
	
	``` cpp title="02_vestica.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAXN 10007
	using namespace std;
	int n,m,dp[MAXN],dpl[MAXN],l[MAXN],r[MAXN],d[MAXN];
	int main()
	{
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>l[i]>>r[i];
		for(int i=0;i<n;i++) d[i]=r[i]-l[i];
		fill(dpl,dpl+MAXN,1000000000);
		for(int i=1;i+d[0]<=m;i++) dpl[i]=abs(i-l[0]);
		for(int i=1;i<n;i++)
		{
			fill(dp,dp+MAXN,1000000000);
			for(int j=1;j+d[i]<=m;j++) for(int k=j;k>=max(0,j+d[i]-d[i-1]);k--) dp[j]=min(dp[j],dpl[k]+abs(j-l[i]));
			for(int j=1;j<=m;j++) dpl[j]=dp[j];
		}
		int res=100000000; for(int i=0;i<MAXN;i++) res=min(res,dp[i]);
		cout<<res;
	}

	```
