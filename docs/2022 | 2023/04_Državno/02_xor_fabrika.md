# B2 - XOR fabrika

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Marko Šišović | Pavle Martinović | Igor Pavlović |

##  Rešenje kada su sve operacije +
U ovom podzadatku važi da je svaka operacija $+1$, tako da će sve što će se desiti $+1$ tačno $R-L+1$ puta, odnosno potrebno je ispisati $X+R-L+1$

## Rešenje kada $N,Q\leq 2000$
U ovom podzadatku naprosto možemo da idemo redom za svaki upit i izsimuliramo sve operacije za složenost $O(NQ)$

## Rešenje kada su sve operacije ^
U ovom podzadatku rešavamo slično kao prvi podzadatak. Primetimo da svaka operacija broj ksoruje sa $1$, a dva ksora se poništavaju, tako da je bitna samo parnost $R-L+1$: ako je parno onda ispišemo $X$, a u suprotnom $X\text{ xor }1$.

## Rešenje kada ima najviše $500$ operaicja ^
Podelimo naš interval na (najviše $500$) intervala sa svim operacijama +. Svaki od njih simuliramo po prvom podzadatku, i onda samo primenimo po jednu operaciju ^. Složenost $O(500Q)$

## Glavno rešenje
Primetimo da nam se u svakom potezu zapravo menja parnost. Tako da će svaka operacija biti $+1$ osim nekih ^ operacija koja će biti $-1$ ako je tada broj na kom vršimo inicijalne poteze neparan. Međutim, ono što treba primetiti da nam je onda samo potreban broj ^ na mestima određene parnosti  (ta određena parnost zavisi od $L$ i $X$: ako je $X$ parno onda iste parnost kao $L$ nam treba, a u suprotnom suprotna parnost). Zato je dovoljno samo zapamtiti dva niza parcijalnih suma: za parne i neparne pozicije broj operacija ^, i onda klasičnim oduzimanjem desnog kraja od levog nađemo koliko ih je u intervalu. Složenost $O(N+Q)$ 