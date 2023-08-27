# 1 - Nesusedni

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Vladimir Milovanović |

Kako imamo tačno 2 različita slova, jedini način da string ne sadrži dva ista susedna slova je da se slova pojavljuju naizmenično u stringu tj. $c_1c_2c_1c_2\ldots$ ili $c_2c_1c_2c_1\ldots$. Ovo je moguće ako i samo ako je $|a_1 - a_2| \leq 1$. Zaista, ako je $|a_1 - a_2| > 1$, "istrošićemo" jedno slovo u naizmeničnom pojavljivanju pre kraja stringa. Sa druge strane, ako je $a_1 = a_2$, imamo 2 moguća rešenja (bilo koje slovo može biti prvo), a ako je $|a_1 - a_2|=1$, rešenje je jedinstveno jer moramo početi (i završiti) slovom koje se pojavljuje više puta.

Složenost algoritma je $O(a_1 + a_2)$, zbog ispisa.
