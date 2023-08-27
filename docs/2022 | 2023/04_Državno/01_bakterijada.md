# B1 - Bakterijada

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Marko Milenković | Marko Milenković | Marko Milenković | Dragan Urošević |

## Rešenje kada $T = 1$ i $N \leq 20$
U ovom podzadatku je dovoljno u svakom potezu generisati sve moguće podele bakterija, njih $2^N$. Svaka bakterija može da učestvuje u najviše $N$ merenja. Vremenska složenost je $O(N2^N)$.

## Rešenje kada sve bakterije imaju istu težinu
Možemo uočiti da je optimalno odvajati po jednu bakteriju u jednu grupu i preostale u drugu. Na ovaj način maksimizujemo ukupnu sumu (dokaz ostavljamo čitaocu za vežbu - pomoć: kada quick sort radi najsporije?). Suma će iznositi $X(N + N + N - 1 + N - 2 + \ldots + 3 + 2) = X\left(\frac{N(N+1)}{2} + N - 1\right)$, gde je $X$ težina bakterija. Vremenska složenost je $O(1)$.

## Rešenje kada $1 \leq N \leq 1000$
Slično, kao u prethodnom podzadatku, odvajaćemo po jednu bakteriju i to baš onu sa najmanjom težinom (dokaz sličan kao u prethodnom podzadatku). Posle svakog merenja nalazićemo najlakšu bakteriju i shodno tome računati sumu, a deljenja će biti tačno $N$. Vremenska složenost je $O(N^2)$.

## Rešenje bez dodatnih ograničenja
Umesto simulacije biranja u prethodnom podzadatku, lakše je izanalizirati da će se najlakša bakterija brojati dva puta, druga najlakša tri puta, ..., druga najteža $N$ puta i najteža $N$ puta. Vremenska složenost je $O(N)$.