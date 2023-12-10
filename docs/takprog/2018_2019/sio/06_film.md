---
hide:
  - toc
---

# 6 - Film

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Bio jednom jedan film. Vi stojite ispred bioskopa i pitali ste $N$ ljudi da vam ispričaju jednu scenu iz filma. Kako su pukom koincidencijom svi ti ljudi takođe odlični programeri kao i vi, svako od njih vam je ispričao jednu scenu, predstavljenu kao string malih slova engleske abecede, uz napomenu da se ta scena javlja u filmu **tačno jednom**. Vaš zadatak je da rekonstruišete film, tačnije, da pronađete string $S$ najkraće moguće dužine koji će svaku scenu sadržati tačno jednom, takav da se taj string sastoji samo od prvih $K$ malih slova engleske abecede.
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Resi(N, K, L[\ldots], A[\ldots][\ldots], S[\ldots])$
	
	koja treba da nađe string opisan u tekstu zadatka. $N$ označava broj ljudi koji su vam rekli jednu scenu iz filma. $K$ je broj koji označava koliko prvih malih slova engleske abecede možete koristiti za konstruisanje filma. $L$ je niz dužine $N$ koji sadrži dužine datih scena. $A$ je niz nizova, gde elementi $A[i][1], \ldots, A[i][L[i]]$ čine $i$-tu scenu. Svi ovi elementi su mala slova engleske abecede. Ukoliko takav string postoji, pronađeni string minimalne dužine smestite u niz $S$ počev od pozicije $1$, a njegovu dužinu vratite kao rezultat funkcije. Ukoliko takav string ne postoji, dovoljno je da iz funkcije vratite broj $-1$. Garantuje se da će za string $S$ biti rezervisano dovoljno memorije da ceo rezultujući string može da stane. **Svi nizovi su indeksirani od 1.**
	
	## Primeri
	
	#### Primer 1
	
	Neka je $N=6, K=26$, a stringovi su `ave`, `venge`, `ger`, `rs`, `r`, `av`. Rešenje je string `avengers`. Vaša funkcija treba da upiše ovaj string na pozicije $S[1], \ldots, S[8]$ i da vrati broj $8$.
	
	#### Primer 2
	
	Neka je $N=2, K=2$, a stringovi su `ababa`, `aba`. Rešenje ne postoji. U ovom slučaju dovoljno je da vaša funkcija vrati broj $-1$.
	
	## Ograničenja
	
	* $1 \leq N \leq 14$
	* $1 \leq K \leq 26$
	* $L_i \geq 1$
	* $\sum_{i=1}^N L_i \leq 150$
	
	## Podzadaci
	
	* Podzadatak 1 [14 poena]: $K = 2$, ukoliko rešenje postoji, tada je ono ne duže od $18$.
	* Podzadatak 2 [12 poena]: $N = 2$
	* Podzadatak 3 [23 poena]: $N = 3$
	* Podzadatak 4 [51 poen]: Bez dodatnih ograničenja.
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `film.cpp`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`int Resi(int N, int K, int* L, char** A, char* S);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova/matrica, ali ne smeju da pristupaju van granica datih nizova**.
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu brojeve $N, K$,
	+ U narednih $N$ redova po jedan string - $A_i$.
	
	Zatim ovaj program zove vašu funkciju. Neka je vaša funkcija vratila broj $X$. Ukoliko je $X < 0$, štampa se samo $X$. U suprotnom, štampa se $X$ i prvih $X$ karaktera niza $S$. Kodove ovih programa možete menjati po potrebi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Ivan Stošić | Ivan Stošić | Ivan Stošić | Aleksandar Zlateski |
	
	Prvi podzadatak se može rešiti generisanjem svih stringova dužine do $18$ a zatim proverom za svaki od njih da li se svaki dati string javlja tačno jednom. Treba biti pažljiv jer je moguće da dati stringovi sadrže slova koja nisu među prvih $K$ slova engleskog alfabeta.
	
	Drugi podzadatak se može rešiti generisanjem svih mogućih preklapanja data dva stringa, uključujući i situaciju kada se stringovi uopšte ne preklapaju.
	
	Na sličan način se može rešiti i treći podzadatak, samo je u slučaju kada imamo $N = 3$ stringa povećava se složenost generisanja preklapanja.
	
	Postoji i drugačije rešenje za ova dva podzadatka, čija ideja je jako važna za rešavanje zadatka za maksimalni broj poena. Recimo, za $N=3$, posmatrajmo jedno parcijalno rešenje, odnosno, prefiks nekog najkraćeg validnog stringa. Neka je $mask$ bit-maska sa $3$ bit-pozicije koja nam govori da li se $i$-ti string do sada već javio, i neka su $p_1,p_2,p_3$ dužine najdužeg stringa koji je sufiks trenutnog rešenja a ujedno i prefiks prvog, drugog i trećeg stringa, redom. Dodavanjem jednog slova mi možemo da proverimo koje su nove vrednosti najdužeg sufiksa za sva tri stringa. Ako je neka od tih dužina sufiksa postala jednaka dužini celog stringa, to je novo pojavljivanje tog stringa. Ako se taj string već javio, rešenje postale nevalidno, inače, u odgovarajući bit trenutne bit-maske treba upisati bit $1$. Korisno je unapred izračunati prelaze, tj. trojke $(l, x) \rightarrow l'$, gde je $l$ stara dužina prefiksa stringa, $x$ slovo koje se dodaje, $l'$ je nova dužina tog najdužeg prefiksa. Ovi prelazi se mogu izračunati $KMP$ algoritmom, ali i ne moraju, s obzirom da *brute-force* implementacija ima vremensku složenost $O(L_i^3)$. Nas onda samo zanima najkraći put (gledano po broju slova) od stanja $(mask=000_2, p_1=0, p_2=0, p_3=0)$ do nekog stanja gde je $mask=111_2$. Pored prelaza, ovo rešenje radi u složenosti $O(K \times L_1 \times L_2 \times L_3)$.
	
	Za maksimalni broj poena dovoljno je da primetimo da ne moramo da pamtimo najduži prefiks za svaki pojedinačni string, već je dovoljno da nam stanje bude najduži sufiks trenutnog parcijalnog rešenja koji je ujedno i prefiks **nekog od** datih stringova, tačnije, stanje će nam biti tačno o kom prefiksu se radi - ovih prefiksa može biti najviše $\sum L_i$. Prelaze možemo izračunati u linearnom vremenu pomoću *Aho-Corasick* algoritma ali, kao i ranije, ne moramo, jer ponovo *brute-force* nalaženje prelaza radi u vremenskoj složenosti $O((\sum L_i)^3)$ i može se implementirati elementarnim (i sporim) algoritmima pretrage stringova. Sada, konačno rešenje izgleda ovako: Napravimo graf čiji su čvorovi uređeni parovi $(mask, prefix)$ gde je $mask$ bit-maska sa $N$ pozicija koja nam govori o tome da li se $i$-ti string do sada javio, a grane su usmerene i od svakog čvora izlazi tačno $K$ grana, po jedna za svako slovo, dolazni čvor za svaku granu se može naći gore opisanim postupkom pomoću izračunatih prelaza. Sada je rešenje najkraći put u ovom grafu od čvora $(0, "")$ do nekog čvora čija se bit-maska sastoji samo od jedinica. Ovaj najkraći put možemo naći običnim $BFS$ algoritmom. Vremenska složenost je $O((\sum L_i)^3 + (\sum L_i) \times 2^N \times K)$.
	
	``` cpp title="06_film.cpp" linenums="1"
	#include <string>
	#include <vector>
	#include <cstring>
	#include <queue>
	#include <tuple>
	using namespace std;
	
	const int MAXTOTLEN = 200;
	const int MAXN = 15;
	
	struct node {
		int next[26], link[26], mask;
	} b[MAXTOTLEN]; int sz = 1;
	
	char hi;
	
	void trie_dodaj(const string& s) {
		int t = 0;
		for (char x : s) {
			int y = x - 'a';
			if (!b[t].next[y])
				t = b[t].next[y] = sz++;
			else
				t = b[t].next[y];
		}
	}
	
	int trie_trazi(const string& s) {
		int t = 0;
		for (char x : s) {
			int y = x - 'a';
			if (!b[t].next[y])
				return -1;
			else
				t = b[t].next[y];
		}
		return t;
	}
	
	void nadji_linkove(int t, string s) {
		for (char x='a'; x<=hi; x++) {
			string p = s + x;
			int y = -1;
			while ((y = trie_trazi(p)) == -1)
				p = p.substr(1);
			b[t].link[x - 'a'] = y;
		}
	
		for (char x='a'; x<='z'; x++) {
			int y = b[t].next[x-'a'];
			if (y)
				nadji_linkove(y, s+x);
		}
	}
	
	void nadji_maske(int t, string s, vector<string>& vs) {
		for (int i=0; i<(int)vs.size(); i++) {
			if (s.size() >= vs[i].size() && equal(vs[i].begin(), vs[i].end(),
				s.begin() + (s.size() - vs[i].size())))
			{
				b[t].mask |= 1 << i;
			}
		}	
	
		for (char x='a'; x<='z'; x++) {
			int y = b[t].next[x - 'a'];
			if (y)
				nadji_maske(y, s+x, vs);
		}
	}
	
	int dist[1 << MAXN][MAXTOTLEN];
	tuple<char, int, int> pre[1 << MAXN][MAXTOTLEN];
	
	int Resi(int N, int K, int* L, char** A, char* S) {
		hi = 'a' + K - 1;
		// konstruisi trie
		vector<string> vs(N);
		for (int i=1; i<=N; i++) {
			vs[i-1] = string(A[i]+1, A[i]+L[i]+1);
			trie_dodaj(vs[i-1]);
		}
		nadji_linkove(0, "");
		nadji_maske(0, "", vs);
		memset(dist, 255, sizeof(dist));
		dist[0][0] = 0;
		queue<pair<int, int>> q;
		q.push({0, 0});
		while (q.size()) {
			auto ee = q.front(); q.pop();
			int mask = ee.first;
			int cvor = ee.second;
			for (char x='a'; x<=hi; x++) {
				int tgt = b[cvor].link[x-'a'];
				int mask2 = b[tgt].mask;
				if (mask2 & mask)
					continue;
				mask2 |= mask;
				if (dist[mask2][tgt] == -1) {
					dist[mask2][tgt] = dist[mask][cvor] + 1;
					pre[mask2][tgt] = {x, mask, cvor};
					q.push({mask2, tgt});
				}
			}
		}
		int sol = 123123123, idx = -1;
		for (int i=0; i<MAXTOTLEN; i++) {
			int d = dist[(1<<N)-1][i];
			if (d != -1) {
				if (d < sol) {
					sol = d;
					idx = i;
				}
			}
		}
		if (sol == 123123123) {
			return -1;
		} else {
			int pos = sol;
			int mask = (1 << N) - 1;
			int cvor = idx;
			while (get<0>(pre[mask][idx])) {
				S[pos--] = get<0>(pre[mask][idx]);
				int mask_tmp = get<1>(pre[mask][idx]);
				int idx_tmp  = get<2>(pre[mask][idx]);
	
				mask = mask_tmp;
				idx = idx_tmp;
			}
			return sol;
		}
	}

	```
