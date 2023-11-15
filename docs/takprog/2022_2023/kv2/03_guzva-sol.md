Dalje u rešenjima ćemo reći da se krećemo *na dole* ukoliko se pomeramo sa polja $(i, j)$ na polje $(i+1, j)$, u suprotnom se krećemo *udesno*.

## Rešenje kada $N = 2$
Na tačno jednoj poziciji ćemo se pomeriti na dole, svi ostali potezi biće udesno. Označimo sa $d_i$ broj navijača koje sretnemo ukoliko se u koloni $i$ pomerimo na dole. Ovaj niz možemo izračunati koristeći prefiksni zbir nad gornjim redom i sufiksni zbir nad donjim redom.

Ukoliko je blokirano neko polje u prvom redu, npr. $(1, i)$, onda se moramo pomeriti na dole pre $i$-te kolone, pa je rešenje $\min(d_1, d_2, \ldots d_{i-1})$. Ukoliko je blokirano neko polje u drugom redu, npr. $(2, j)$, onda se moramo pomeriti na dole posle $i$-te kolone, pa je rešenje $\min(d_{i+1}, d_{i+2}, d_M)$.

Vremenska složenost je $O(M+Q)$, a memorijska $O(M)$.

## Rešenje kada $Q \leq 100$, $N, M \leq 7$
Rešenje možemo dobiti *brute force* metodom, odnosno isprobavanjem svih mogućih puteva od prvog do poslednjeg polja, za svako blokirano polje. Takvih puteva postoji ${N+M-2 \choose N-1}$ (imamo ukupno $N+M-2$ koraka, od kojih biramo $N-1$ da budu usmereni na dole). Sve puteve možemo proveriti rekurzijom. 

Vremenska složenost je $O(Q\cdot{N+M-2 \choose N-1})$, a memorijska $O(NM)$.

## Rešenje kada $Q \leq 2000$, $N \cdot M \leq 2000$
Za svako blokirano polje, koristićemo dinamičko programiranje - izračunaćemo $dp_{i, j}$, najmanji broj navijača koje moramo da sretnemo na putu od $(1, 1)$ do $(i, j)$, ako ne posetimo trenutno blokirano polje. Jasno je da važi $dp_{1, 1} = a_{1, 1}$ i $dp_{i, j} = dp_{i-1, j} + dp_{i, j-1}$, s tim što prilikom računanja uvek preskačemo polja koja su van matrice i trenutno blokirano polje. Rešenje se onda nalazi u $dp_{N, M}$. 

Vremenska složenost je $O(QNM)$, a memorijska $O(NM)$.

## Rešenje kada $Q \leq 10^4$
Kao u prethodnom rešenju, izračunajmo niz $A_{i, j}$ - najmanji broj navijača koje moramo da sretnemo na putu od $(1, 1)$ do $(i, j)$, i slično $B_{i, j}$ - najmanji broj navijača koje moramo da sretnemo na putu od $(i, j)$ do $(N, M)$. 

Recimo da blokiramo polje $(x, y)$. Posmatrajmo sva polja $(x', y')$ za koja važi $x+y = x' + y'$. Možemo videti da se zapravo sva ova polja nalaze na istoj dijagonali, kao i da na svakom putu od $(1, 1)$ do $(N, M)$ prolazimo kroz tačno jedno od ovih polja. 

Ovo nam govori da, kako bismo garantovali da ne prolazimo kroz polje $(x, y)$, dovoljno je da garantujemo da prolazimo kroz neko drugo polje na ovoj dijagonali. Možemo naći put sa najmanje navijača koji prolazi kroz polje $(i, j)$ sa $A_{i, j} + B_{i, j} - a_{i, j}$. 

Možemo, dakle, proći kroz sva polja na dijagonali blokiranog polja i videti za koje dobijamo najmanji put. Bitno je primetiti da je broj polja na toj dijagonali najviše $\min(N, M)$, što je manje od $\sqrt{NM}$.

Vremenska složenost je $O(Q\cdot \sqrt{N M} + NM)$, a memorijska $O(NM)$.

## Glavno rešenje
Uradimo sve isto kao u prethodnom rešenju, sem što ćemo efikasnije naći minimum na dijagonali bez jednog polja. To ćemo uraditi tako što ćemo čuvati prefiksni i sufiksni minimum za svaku dijagonalu. Za blokirano $(x, y)$ uzećemo minimum od prefiksa do $(x-1, y+1)$ i sufiksa od $(x+1, y-1)$.

Vremenska složenost je $O(Q + NM)$, a memorijska $O(NM)$.
