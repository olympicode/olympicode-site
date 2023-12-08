---
hide:
  - toc
---

# B2 - XOR fabrika

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	U deonici za razvrstavanje delova u kutije poznate kragujevačke fabrike automobila, odlučeno je da se zbog povoljnosti XOR-robota, oni ubace na mesto nekih standardnih robota dodavača. XOR-roboti dodaju deo u kutiju ako se u njoj nalazi paran broj delova, a uzimaju deo iz nje ukoliko se u njoj nalazi neparan broj delova, dok standardni roboti dodavači uvek dodaju deo u kutiju. Kao što to obično biva u fabrikama automobila, ovi roboti se nalaze duž pokretne trake, ima ih $N$ i numerisani su redom od $1$ do $N$. Kutije se na pokretnu traku ubacuju i skidaju sa nje na proizvoljnim mestima i sa proizvoljnim brojem delova koji su već u njoj. Pre zamene nekih od starih robota sa novim robotima, bilo je lako predvideti sa koliko delova će kutija izaći sa trake ako je ubacimo na poziciji $L$ a skinemo nakon pozicije $R$, ali sada to nije toliko lako, što upravnicima fabrike predstavlja značajan problem, pa su vas zamolili da napišete program koji rešava njigov problem.
	
	## Opis ulaza
	U prvom redu se unose brojevi $N$ i $Q$, broj robota na pokretnoj traci kao i broj upita. U sledećem redu se unosi niz $s$ od $N$ karaktera. U ovom nizu se nalaze isključivo karakteri '+' i '^', koji redom predstavljaju robote dodavače i XOR-robote. U narednih $Q$ redova se nalaze po tri broja: $L$, $R$ i $X$, koji predstavljaju upit sledećeg tipa: ako stavimo kutiju koja inicijalno ima $X$ delova u sebi na poziciju pre robota numerisanog sa $L$, a skinemo je nakon robota numerisanog sa $R$ (dakle kutija će proći pored $R - L + 1$ robota), koliko delova će biti u njoj nakon toga?
	
	## Opis izlaza
	Ispisati $Q$ brojeva koji predstavljaju odgovore na zadate upite.
	
	## Primer 1
	### Ulaz
	```
	11 3
	^^++^+^+++^
	2 3 5
	2 3 6
	1 11 3
	```
	### Izlaz
	```
	5
	8
	6
	```
	
	## Ograničenja
	
	- $N, Q \le 2 \times 10^5$.
	- $1 \le L \le R \le N$.
	- $X \le 10^9$.
	
	Test primeri su podeljeni u pet disjunktnih grupa:
	
	- U test primerima vrednim $10$ poena, na pokretnoj traci se nalaze samo roboti dodavači (u nizu se nalaze samo karakteri '+').
	- U test primerima vrednim $10$ poena, $N, Q \le 2000$.
	- U test primerima vrednim $20$ poena, na pokretnoj traci se nalaze samo XOR-roboti (u nizu se nalaze samo karakteri '^').
	- U test primerima vrednim $30$ poena, Na pokretnoj traci se nalazi najviše $500$ XOR-robota.
	- U test primerima vrednim $30$ poena nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Marko Šišović | Pavle Martinović | Igor Pavlović |
	
	##  Rešenje kada su sve operacije +
	U ovom podzadatku važi da je svaka operacija $+1$, tako da će sve što će se desiti $+1$ tačno $R-L+1$ puta, odnosno potrebno je ispisati $X+R-L+1$
	
	## Rešenje kada $N,Q\leq 2000$
	U ovom podzadatku naprosto možemo da idemo redom za svaki upit i izsimuliramo sve operacije za složenost $O(NQ)$
	
	## Rešenje kada su sve operacije ^
	U ovom podzadatku rešavamo slično kao prvi podzadatak. Primetimo da svaka operacija broj ksoruje sa $1$, a dva ksora se poništavaju, tako da je bitna samo parnost $R-L+1$: ako je parno onda ispišemo $X$, a u suprotnom $X\text{ xor }1$.
	
	## Rešenje kada ima najviše $500$ operacija ^
	Podelimo naš interval na (najviše $500$) intervala sa svim operacijama +. Svaki od njih simuliramo po prvom podzadatku, i onda samo primenimo po jednu operaciju ^. Složenost $O(500Q)$
	
	## Glavno rešenje
	Primetimo da nam se u svakom potezu zapravo menja parnost. Tako da će svaka operacija biti $+1$ osim nekih ^ operacija koja će biti $-1$ ako je tada broj na kom vršimo inicijalne poteze neparan. Međutim, ono što treba primetiti da nam je onda samo potreban broj ^ na mestima određene parnosti  (ta određena parnost zavisi od $L$ i $X$: ako je $X$ parno onda iste parnost kao $L$ nam treba, a u suprotnom suprotna parnost). Zato je dovoljno samo zapamtiti dva niza parcijalnih suma: za parne i neparne pozicije broj operacija ^, i onda klasičnim oduzimanjem desnog kraja od levog nađemo koliko ih je u intervalu. Složenost $O(N+Q)$ 
	
	``` cpp title="02_xor_fabrika.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	#define MAXN 200005
	
	int ps[MAXN][2];
	
	int n, q;
	
	int main(){
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cin >> n >> q;
	    string s;
	    cin >> s;
	    for(int i = 1; i <= n; i++){
	        if(s[i-1] == '+'){
	            ps[i][0] = ps[i-1][0] + 1;
	            ps[i][1] = ps[i-1][1] + 1;
	        }
	        else if(s[i-1] == '^'){
	            ps[i][0] = ps[i-1][0] + (i % 2 == 1 ? 1 : -1);
	            ps[i][1] = ps[i-1][1] + (i % 2 == 0 ? 1 : -1);
	        }
	    }
	    while(q--){
	        int l, r, x;
	        cin >> l >> r >> x;
	        int pr = (x + l + 1) % 2;
	        cout << x + ps[r][pr] - ps[l-1][pr] << "\n";
	    }
	    return 0;
	}

	```
