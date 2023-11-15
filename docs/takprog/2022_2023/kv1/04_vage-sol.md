## Rešenje kada $N, M \leq 1000$
Za svako pitanje možemo jednostavno proći kroz sve bitne vage i proveriti da li mogu izmeriti trenutno $x_i$. 

Vremenska složenost je $O(NM)$, a memorijska $O(N)$.

## Rešenje kada $d_i=u_i$
U ovom slučaju potrebno je odrediti, za svako pitanje, koliko vaga kojima je $d_i$ jednako $x_i$ ima indeks od $l_i$ do $r_i$. Pošto nam nisu bitne konkretne vrednosti $d_i$, $u_i$ i $x_i$, već samo da li su jednaki, ove vrednosti možemo kompresovati, na primer koristeći *std::map*, tako da sve budu najviše $N$. Kada to uradimo, možemo za svaki različit element u nizu $d_i$ da napravimo novi niz, koji sadrži, sortirano rastuće, sve indekse vaga kojima odgovara ta vrednost $d_i$. 

Sada, kad je potrebno da odgovorimo na pitanje, možemo koristeći binarnu pretragu da nađemo koliko elemenata u nizu indeksa koji odgovara vrednosti $x_i$ se nalazi na intervalu $[l_i, r_i]$.

Vremenska složenost je $O((N+M)logN)$, a memorijska $O(N)$.

## Rešenje kada ne postoji $x$ koje mogu da izmere dve različite vage
Ovaj uslov se drugačije može napisati da su intervali $[d_i, u_i]$ disjunktni. Sortirajmo intervale po levoj granici, takođe čuvajući indeks svakog intervala. Nakon toga rešavamo pitanja jedno po jedno, tako što binarnom pretragom tražimo poslednji interval kome je leva granica manja od trenutnog $x_i$.  

Ukoliko se $x_i$ ne nalazi u tom intervalu ili se indeks tog intervala ne nalazi u intervalu $[l_i, r_i]$, rezultat za trenutno pitanje je $0$. U suprotnom, rezultat je $1$.

Vremenska složenost je $O((N+M)logN)$, a memorijska $O(N)$.

## Rešenje kada $u_i \leq 20$
Ovaj slučaj se rešava slično slučaju kada važi $d_i = u_i$, s tim što, umesto da ubacimo svaki indeks u niz indeksa samo za vrednost $d_i$, mi ćemo ga ubaciti u niz indeksa za svaku vrednost u intervalu $[d_i, u_i]$. Nakon toga, odgovor na pitanje nalazimo na isti način kao ranije. Potrebno je posebno paziti za slučaj kada $x_i > 20$. 

Vremenska složenost je $O(N\cdot max(u_i) + MlogN)$, a memorijska $O(N)$.

## Glavno rešenje
Kako bismo rešili zadatak za sve bodove, potrebno je da na pitanja odgovaramo *offline*, odnosno u drugačijem redosledu nego što su data, pa ćemo ih na kraju ispisati u tačnom redosledu. Na pitanja ćemo odgovarati u redosledu rastuće po $x_i$ (ukoliko više pitanja ima isto $x_i$, nije bitno na koje odgovaramo prvo). 

Znamo da nam je vaga $j$ bitna samo ako važi $d_j \leq x_i \leq u_j$. Dakle, kako idemo kroz pitanja rastuće po $x_i$, postoje dve vrste događaja: 

- Vaga $j$ postaje bitna prvi put kada postavljamo pitanje za koje važi $x_i \geq d_j$;
- Vaga $j$ prestaje da bude bitna pri put kada postavljamo pitanje za koje važi $x_i \geq u_j+1$.

Ubacimo svih $2N$ događaja u jedan niz i sortirajmo ga rastuće po njihovim granicama za $x_i$. Sada možemo zajedno prolaziti kroz niz pitanja i niz događaja metodom dva pokazivača i održavati niz nula i jedinica dužine $N$ koji na $i$-toj poziciji sadrži $1$ ako i samo ako je vaga sa indeksom $i$ trenutno bitna. Naravno, ovaj niz ćemo menjati svaki put kada na red dođe neki novi događaj.

Kako bismo efikasno odgovorili na pitanje, potrebno je da efikasno nađemo zbir na intervalu $[l_i, r_i]$ ovog niza, u trenutku kada smo obradili sve događaje koji dolaze pre ovog pitanja. Za ovo možemo koristiti segmentno ili Fenvikovo stablo kako bismo ostvarili dobru složenost.

Vremenska složenost je $O((N+M)logN)$, a memorijska $O(N)$.
