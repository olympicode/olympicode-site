# B3 - Kirbi

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Marko Milenković | Marko Milenković | Marko Milenković | Dimitrije Erdeljan |

## Rešenje kada $1 \leq N,M,P \leq 5$
U ovom podzadatku koristimo to da su sve vrednosti male brojke. Možemo izbrisati svako prljavo polje i zatim isprobati sve putanje da vidimo koja sadrži najveći broj uprljanih polja i da li se to razlikuje od početnog maksimalnog broja polja koje Kirbi može da očisti. Vremenska složenost je $O(TP2^{N+M})$.

## Rešenje kada $N = 2$ ili $M = 2$
Posmatraćemo slučaj $N=2$, jer se drugi slučaj analogno rešava. Primetimo da će se Kirbi tačno jednom spustiti u drugi red. Pamtimo prefiksni niz prljvih polja za prvi red i pamtimo sufiksni niz prljavih polja za drugi red. Maksimalan broj polja koje Kirbi može da očisti je $S = \max_{1 \leq i \leq M}\{pref_i + suf_i\}$. Neka je $i_{min}$ prva kolona u kojoj izraz $pref_{i_{min}} + suf_{i_{min}}$ dostiže vrednost $S$ i neka je $i_{max}$ poslednja kolona u kojoj izraz $pref_{i_{max}} + suf_{i_{max}}$ dostiže vrednost $S$. Traženo rešenje je $pref_{i_{min}} + suf_{i_{max}}$. Vremenska složenost je $O(T(P+M))$.

## Rešenje kada $1 \leq N,M,P \leq 100$
Neka je $S$ ponovo maksimalan broj polja koje Kirbi može da očisti u startu. To možemo izračunati standardnim dinamičkim programiranjem. Stanje $dp_{i,j}$ predstavlja maksimalan broj polja koje Kirbi može da očisti krećući sa polja $(1,1)$ do polja $(i,j)$. Krenemo "redom" da obilazimo matricu po redovima, pa po kolonama (kao u ulazu) i vršimo prelaz $dp_{i,j} = \max(dp_{i-1,j}, dp_{i,j-1}) + a_{i,j}$, gde je $a_{i,j}$ binarni indikator da li je polje $(i,j)$ urljano ($1$ ako jeste, $0$ ako nije). Sada možemo da izbacujemo jedno po jedno uprljano polje i računamo iznova celu $dp$ matricu i vidimo kada je vrednost $dp_{N,M} < S$. Vremenska složenost $O(TPNM)$.
   
## Glavno rešenje
Možemo primetiti da kada posmatramo redom polja koja je Kirbi očistio, njihove kolone formiraju neopadajući niz. Odnosno, ukoliko sortiramo uprljana polja po redovima, maksimalan broj polja koja Kirbi može da očisti je najduži neopadajući podniz kolona ovog niza. Dati problem je ekvivalentan nalaženju najdužeg rastućeg podniza (\emph{Longest increasing subsequence}, ili skraćeno LIS), što je poznat problem i može se rešiti/implementirati u vremenskoj složenosti $O(P\log P)$. Ono što nama treba jesu prefiksni i sufiksni LIS nizovi. Formalno, $pref_i$ predstavlja $LIS$ od početka niza do $i$-tog elementa, ali tako da on zasigurno figuriše u $LIS$-u. Slično, $suf_i$ predstavlja $LIS$ niza od $i$-tog elementa do kraja niza, tako da $i$-ti element učestvuje u $LIS$-u. Za $i$-ti element niza uprljanih polja važi da je deo nekog od putanja koje sadrže najveći broj uprljanih polja ako i samo ako je $pref_i + suf_i - 1 = S$. Sa druge strane, element niza pripada svim takvim putanjama ako i samo ako dodatno važi i da je vrednost $pref_i$ jedinstvena među svim prefiksnim $LIS$-ovima. Potrebno je samo ispisati broj takvih polja. Vremenska složenost je $O(TP\log P)$. 