# 2 - Ekskurzija

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Aleksa Plavšić | Aleksa Plavšić | Dragan Urošević | Aleksa Milisavljević |

## Rešenje kad $N = 3$
U ovom slučaju, broj grupa ne može biti veći od $3$. Prema tome, potrebno je samo odrediti minimalni broj bananica za sve tri vrednosti za broj grupa. Ako je $K=1$, onda u toj grupi ima 3 učenika, minimalni broj bananica je $1+2+3=6$. Ako je  $K=2$, onda u jednoj grupi moraju biti dva učenika (i minimalan broj bananica je $1+2=3$), a u drugoj grupi 1 učenik (i minimalan broj bananica je $1$), pa je ukupan minimalan broj bananica $4$. Ako je $K=3$, onda je u svakoj grupi $1$ učenik, pa je ukupan minimalan broj bananica $3$.

## Rešenje kad $K = 1$
U ovom slučaju, svi učenici su u istoj grupi i minimalan broj bananica je
$$
1+2+3+\dotsb + N = \frac{N\cdot(N+1)}{2}.
$$
Potrebno je voditi računa da poslednji proizvod može biti vrlo veliki broj.

## Rešenje kad $N, M \leq 10$
U ovom slučaju, do rešenja se može doći primenom pretrage sa vraćanjem (bektrek).

## Rešenje kad $N \leq 2000$
U ovom slučaju se primenjuje glavno rešenje u kojem ne primetimo sve formule, već primenjujemo neke manje efikasne metode (npr. prolazak kroz sve grupe).

## Glavno rešenje
Potrebno je primetiti da grupe treba da budu približno jednake veličine. Naime, ako je $c_1$ broj učenika u jednoj grupi, $c_2$ broj učenika u drugoj grupi i pri tome važi $c_2 \geq c_1 + 2$, onda je minimalni broj bananica za te dve grupe
$$
B_1 = \frac{c_1\cdot(c_1+1)}{2} + \frac{c_2\cdot (c_2+1)}{2} =
\frac{c_1^2+c_2^2+c_1+c_2}{2}.
$$
Ako jednog učenika prebacimo iz druge grupe u prvu grupu, onda je minimalni broj bananica u te dve grupe
 $$
B_2 = \frac{(c_1+1)\cdot(c_1+2)}{2} + \frac{(c_2-1)\cdot c_2}{2} =
\frac{c_1^2+c_2^2+3c_1-c_2+2}{2}.
$$
Razlika dva poslednja broja je
$$
B_1 - B_2 = \frac{2c_2 - 2c_1 - 2}{2} = c_2 - c_1 -1 > 0,
$$
tj. minimalan broj bananica se smanjio.

Prema tome, sve grupe treba da imaju približno jednako elemenata. Ako je broj učenika deljiv brojem grupa, onda bi svaka grupa imala $N/K$ učenika. Ako broj učenika nije deljiv brojem grupa onda će jedan deo grupa imati $N_1 = \lfloor N/K \rfloor$,  a drugi deo grupa $N_2 = N_1 + 1$. Broj grupa $K_2$ koje imaju $N_2$ učenika je
$$
K_2 = N - K \cdot \lfloor N/K\rfloor = N \text{ mod } K,
$$
gde je $N \text{ mod } K$ ostatak pri deljenju broja $N$ brojem $K$.
Konačno, minimalan ukupan broj bananica je
$$
(K-K_2) \cdot \frac{N_1\cdot (N_1+1)}{2} + K_2 \cdot \frac{N_2\cdot (N_2+1)}{2}.
$$

Složenost algoritma je $O(1)$.