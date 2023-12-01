---
hide:
  - toc
---

# B3 - Branje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 64MB |
	
	Stiglo je proleće, visibabe su uveliko počele da rastu, a gazda Srba želi da to iskoristi i da profitira prodavajući visibabe ljudima u gradu koji nemaju dvorište, a žele da se raduju ovom prvom prolećnom cveću.
	
	U svom dvorištu Srba ima $N$ visibaba **poređanih u red**, i za svaku je odredio, gledajući njenu lepotu, **koliko dinara može da zaradi ako je proda**.
	
	Pošto ima mnogo visibaba, a Srba je malo lenj, on je kupio dve mašine (visibaboberače) koje će ih brati umesto njega. Ipak, mašine zahtevaju struju, i što je veća visibaba mašina zahteva više potrošnje. Srba je za svaku visibabu izračunao **koliko će u dinarima platiti struju** ako bi je mašina obrala. Da bi dodatno uštedeo, Srba neće da stalno gasi i pali mašine, već će ih samo jednom upaliti, pustiti svaku od njih da obere **neki broj uzastopnih visibaba**, i zatim ugasiti. Pri tome, **obe mašine moraju da budu uključene** za neku uzastopnu grupu visibaba (za barem jednu visibabu), a te grupe **ne smeju da sadrže nijednu istu visibabu**.
	
	Pomozite Srbi da ostvari **najveći profit**, računajući dobit od prodavanja visibaba i trošak na struju za branje.
	
	## Ulaz
	U prvom redu standardnog ulaza se nalazi broj $N$ koji predstavlja broj visibaba u Srbinom dvorištu. U drugom redu se nalazi niz od $N$ brojeva $Z_i$ gde $i$-ti broj predstavlja koliko će Srba zaraditi ako proda $i$-tu visibabu. U trećem redu se nalazi niz od $N$ brojeva $S_i$  u kome $i$-ti broj označava koliko će dinara potrošiti na struju ukoliko bere $i$-tu visibabu.
	
	## Izlaz
	U prvi i jedini red standardnog izlaza ispisati jedan broj – koliko Srba najviše može da zaradi. Obratite pažnju da ovo može biti i negativan broj, ukoliko će Srba u svakom slučaju više izgubiti na struju nego na prodaju.
	
	## Primer 1
	### Ulaz
	```
	11
	5 6 3 14 9 7 11 3 8 1 4
	1 5 11 4 6 4 4 5 4 8 2
	```
	
	### Izlaz
	```
	19
	```
	
	## Primer 2
	### Ulaz
	```
	2
	3 3
	5 2
	```
	
	### Izlaz
	```
	-1
	```
	
	## Objašnjenje primera
	U prvom primeru, jedno od rešenja gde dobijamo najveći profit je ako prvu mašinu pustimo da obere samo $4$. visibabu (profit je $10 = 14 – 4$), a drugu mašinu pustimo da obere od sedme do devete visibabe (profit je $9 = (11 + 3 + 8) – (4 + 5 + 4))$, pa je ukupan profit $9 + 10 = 19$.
	
	U drugom primeru nemamo izbora osim da prvu mašinu pustimo da obere prvu visibabu, a drugu mašinu da obere drugu, gde ćemo kod prve visibabe izgubiti $2$ dinara, a kod druge zaraditi $1$ dinar, pa je ukupna zarada $-1$.
	
	## Ograničenja
	
	* $2\leq N\leq 10^6$.
	* $0\leq Z_i\leq 10^9$.
	* $0\leq S_i\leq 10^9$.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	* U test primerima vrednim $20$ poena važi $N\leq 50$.
	* U test primerima vrednim $20$ poena važi $N\leq 500$.
	* U test primerima vrednim $20$ poena važi $N\leq 5000$.
	* U test primerima vrednim $40$ poena nema dodatnih ograničenja.
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dušan Zdravković | Nemanja Majski | Boris Grubić |
	
	## Uprošćavanje problema
	Recimo da smo sekli neku visibabu $i$. Primetimo da profit od njenog sečenja ne zavisi od toga koje visibabe sem nje smo odsekli, nego je uvek $Z_i-S_i$. Taj profit ćemo pamtiti u novom nizu $P_i=Z_i-S_i$.
	
	Sada je naš zadatak da podelimo niz $P$ u $K=2$ disjunktna uzastopna podniza tako da je zbir elemenata u njima maksimalan.
	
	## Rešenje za $N \le 50$
	U ovom podzadatku je dovoljno ručno proveriti sve moguće podele niza na podnize. Vremenska složenost je $O(N^4)$.
	
	## Rešenje za $N \le 500$
	U ovom podzadatku ćemo ići po desnoj granici levog podniza. Sada treba shvatiti da će leva granica levog podniza biti takva da je zbir brojeva u levom podnizu maksimalan. Nju možemo naći preko jedne petlje. Nakon toga radimo dvostruku petlju po svim mogućim desnim podnizovima. Vremenska složenost je  $O(N^3)$.
	
	## Rešenje za $N \le 5000$
	Za svaku poziciju u nizu ćemo prekalkulisati najveći mogući zbir podniza koji počinje $R_i$ i najveći mogući zbir podniza koji završava u toj poziciji $L_i$. To možemo da uradimo preko dvostruke petlje.
	
	Sada radimo dvostruku petlju po desnoj granici levog podniza i levoj granici desnog podniza. Ako smo izabrali granice $i$ i $j$ $(i <j)$, onda je najbolja moguća vrednost takvog izbora $L_i + R_j$.
	
	Vremenska složenost je  $O(N^2)$.
	
	## Rešenje za $K=1$
	Ovo nije podzadatak u originalom zadatku, ali je važno da ga razumemo kako bismo razumeli glavno rešenje. U ovom podzadatku nam je dat niz i treba da nađemo najveći mogući zbir nekog podniza.
	
	Možemo da održavamo $dp[i]$ niz, gde je $dp[i]$ najveća vrednost podniza koji se završava na $i$. Osnovni slučaj je $dp[0]=0$. Ako smo izračunali $dp[k-1]$, onda je $dp[k]=max(dp[k-1],0)+p[k]$, zato što možemo ili da nastavimo prethodni podniz, ili da započnemo novi.
	
	Rešenje zadatka je najveća vrednost nekog elementa u $dp$ nizu. Vremenska složenost je $O(N)$.
	
	## Glavno rešenje
	Korišćenjem rešenja za $K=1$ možemo da kreiramo $dp$ niz. Sada ćemo da imamo niz $L_i$ takav da je $L_i=max(dp_1, dp_2, dp_3, ... ,dp_{i-1}, dp_i)$. To znači da ako se desni kraj levog podniza nalazi negde pre ili na poziciji $i$, maksimalan zbir levog podniza je $L_i$.
	
	Slično možemo da odredimo $R_i$ za desni podniz. I sada samo treba da prođemo kroz svako $1\le i <N$ i nađemo najveće $L_i + R_{i+1}$. Vremenska složenost je $O(N)$.
	
	Bonus: Rešite ovaj zadatak kada je $K \le N$. Takav zadatak nije po programu državnog takmičenja, ali može da se pojavi na SIO.
	
	``` cpp title="03_branje.cpp" linenums="1"
	#include <vector>
	#include <list>
	#include <map>
	#include <set>
	#include <deque>
	#include <stack>
	#include <bitset>
	#include <algorithm>
	#include <functional>
	#include <numeric>
	#include <utility>
	#include <sstream>
	#include <iostream>
	#include <iomanip>
	#include <cstdio>
	#include <cmath>
	#include <cstdlib>
	#include <ctime>
	#include <queue>
	#include <cstring>
	
	using namespace std;
	
	#define sz size()
	#define pb push_back
	#define len length()
	#define clr clear()
	#define FOR(i,a,b) for(i=a;i<b;i++)
	#define FORR(i,n) for(i=0;i<n;i++)
	#define is_digit(c) ('0'<=(c) && (c)<='9')
	
	#define eps 0.0000001
	#define PI  3.14159265359
	#define infll 199988877733322255LL
	
	long long a[1000333],s[1000333],llevo[1000333],rlevo[1000333],res_levo[1000333];
	
	int main() {
	
	    freopen("input2.txt", "r", stdin);
	    //freopen("output9.txt", "w", stdout);
	
	    int n,k,i,j;
	    long long x,l1,r1,l2,r2,res,min_l,max_d,min_l_ind,max_d_ind;
	    bool bres;
	
	    scanf("%d", &n);
	
	    for(i=1; i<=n; i++) {
	        scanf("%lld", &a[i]);
	    }
	
	    for(i=1; i<=n; i++) {
	        scanf("%lld", &x);
	        a[i] -= x;
	    }
	
	    s[0] = 0;
	    for(i=1; i<=n; i++) {
	        s[i] = s[i-1] + a[i];
	    }
	
	    res_levo[1] = s[1] - s[0];
	    if (s[1] < s[0]) {
	        min_l = s[1];
	        min_l_ind = 1;
	    } else {
	        min_l = s[0];
	        min_l_ind = 0;
	    }
	
	    rlevo[1] = 1;
	    llevo[1] = 1;
	
	    for(i=2; i<=n; i++) {
	        res_levo[i] = res_levo[i-1];
	        rlevo[i] = rlevo[i-1];
	        llevo[i] = llevo[i-1];
	        if (s[i] - min_l > res_levo[i]) {
	            res_levo[i] = s[i] - min_l;
	            rlevo[i] = i;
	            llevo[i] = min_l_ind + 1;
	        }
	
	        if (s[i] < min_l) {
	            min_l = s[i];
	            min_l_ind = i;
	        }
	    }
	
	    max_d = s[n];
	    max_d_ind = n;
	    res = max_d - s[n-1] + res_levo[n-1];
	    if (s[n-1] > max_d) {
	        max_d = s[n-1];
	        max_d_ind = n-1;
	    }
	
	    for(i=n-2; i>0; i--) {
	       if (max_d - s[i] + res_levo[i] > res) {
	           res = max_d - s[i] + res_levo[i];
	           l1 = llevo[i];
	           r1 = rlevo[i];
	           l2 = i+1;
	           r2 = max_d_ind;
	       }
	       if (s[i] > max_d) {
	           max_d = s[i];
	           max_d_ind = i;
	       }
	    }
	
	    printf("%lld\n", res);
	    printf("-> %lld %lld %lld %lld\n", l1,r1,l2,r2);
	    printf("-> %lld\n", s[r1] - s[l1-1] + s[r2] - s[l2-1]);
	
	    return 0;
	}

	```
