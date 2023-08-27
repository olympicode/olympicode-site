# A2 - Ćivas

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Mladen Puzić | Tadija Šebez |

## Rešenje kada $N, Q \leq 500$
Za svaku promenu niza, izračunamo niz $b$ i na njemu probamo svaku moguću periodu, od kojih uzimamo najmanju. 

Vremenska složenost je $O(QN^2)$,  a memorijska složenost $O(N)$.  

## Rešenje kada $Q \leq 25$
Primetimo da su jedine moguće periode delioci broja $N$. Sada primenjujemo prethodno rešenje, samo što isprobavamo samo te delioce.

Vremenska složenost je $O(QNd(N))$, gde je $d(N)$ broj delioca $N$, a memorijska složenost $O(N)$.

## Rešenje kada $Q \leq 3000$ 
Možemo primetiti da za svako $d$ i $x$ važi: 
$$
a_i \text{ xor } a_{i+d} = b_i \text{ xor } b_{i+1} \text{ xor } \ldots b_{i+d-1}
$$

Analogno, važi i:
$$
a_{i+d} \text{ xor } a_{i+2d} = b_{i+d} \text{ xor } b_{i+d+1} \text{ xor } \ldots b_{i+2d-1}
$$

Ako za $d$ uzmemo periodu niza $b$, važi da su desne strane ovih jednačina jednake, pa važi i da su leve strane jednake. Odatle zaključujemo, da za takvo $d$ i proizvoljno $x$ važi $a_i = a_{i+2d}$,  što nam govori da je $2d$ perioda niza $a$. 

Pošto nam je poznato da je perioda niza $a$ baš $n$, onda imamo dva slučaja. Ukoliko je $n$ neparno, perioda niza $b$ je uvek $n$, u suprotnom, perioda može biti i $\frac{N}{2}$, a ako nije, onda mora biti $n$. Zato, nakon svake promene, dovoljno je proveriti da li je u novom nizu $\frac{N}{2}$ perioda. 

Vremenska složenost $O(NQ)$, a memorijska složenost $O(N)$.

## Glavno rešenje
Poput prethodnog rešenja, dovoljno je proveriti periodu $\frac{N}{2}$, samo ćemo ovde to uraditi na brži način. Pre svih promena, odradimo proveru u $O(N)$, pamteći u koliko odgovarajućih parova su isti elementi. Nakon svake promene, dovoljno je proveriti samo da li se neki od dva para na koje promena utiče *popravio* ili *pokvario*, tj. ažurirati broj parova u kojima su elementi isti. Kad god je broj takvih parova tačno $\frac{N}{2}$, perioda je $\frac{N}{2}$, u suprotnom, perioda je $N$. 

Vremenska složenost je $O(N+Q)$, a memorijska složenost $O(N)$.

