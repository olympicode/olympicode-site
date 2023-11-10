# B3 - Okram

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Mladen Puzić | Momčilo Tošić |

## Rešenje kada $N, M \leq 5, A_i \leq 1$
Pošto su dimenzije matrice male, a jedine moguće vrednosti u matrici $0$ i $1$, postoji dosta malo stanja u kojima se može naći matrica. Simuliramo proces sekundu po sekundu, dok se ne desi da smo već videli dato stanje. Pošto znamo da ćemo na dalje da se vrtimo u krug, znamo da će rešenje biti jedno od datih stanja. Koje tačno stanje će to biti možemo dobiti koristećenjem formula.

## Rešenje kada $K \leq 5$
Pošto je $K \leq 5$, znači da nam je bitno samo ponašanje matrice u prvih $2^5 = 32$ sekundi. Pre svih pitanja, izračunaćemo sve matrice, i onda za svako pitanje možemo samo ispisati traženo polje odgovarajuće matrice.

Vremenska složenost je $O(2^KNM + Q)$, a memorijska $O(2^KNM)$. 

## Rešenje kada $K \leq 200$ 
Ponovo ćemo čuvati matrice za svako $K$, ali ovaj put ćemo ih računati na način koji će biti opisan u sledeća dva rešenja. 

## Rešenje kada su sve početne vrednosti $0$, sem jedne koja je $1$
Posmatranjem kako se ova jedinica ponaša kroz vreme u beskonačnoj matrici možemo zaključiti da će nakon $2^K$ sekundi da se nalazi na pozicijama $(x+2^K, y)$, $(x-2^K, y)$, $(x, y+2^K)$ i $(x, y-2^K)$. Ovo možemo i jednostavno dokazati indukcijom. Za bazu $K = 0$ ovo je očigledno tačno. Ako pretpostavimo da je tačno za neko $K$, i primenimo induktivnu hipotezu na $4$ tako dobijene tačke, videćemo da se dešava nešto zanimljivo - sva polja sem ona $4$ koja su nam potrebna se skrate (xor je inverz sam sebi), pa smo dokazali tvrđenje. 

Sada, za svako pitanje je dovoljno proveriti da li je u pitanju jedno od najviše četiri polja koji sadrže jedinicu. Pošto ova matrica nije beskonačna, moramo koristeći formule da dobijemo tačne koordinate jedinica u njoj. 

Vremenska složenost je $O(NM+M+K)$, a memorijska $O(NM+K)$. 

## Glavno rešenje
Primetimo da će sva polja u matrici biti xor nekih polja početne matrice. Koristeći prethodno rešenje, za svako polje početne matrice možemo pronaći u xor-u kojih polja matrice će se nalaziti nakon $2^K$ sekundi. Tako možemo zaključiti da će vrednost polja $(x, y)$ nakon $2^K$ sekundi biti xor vrednosti polja $(x+2^K, y)$, $(x-2^K, y)$, $(x, y+2^K)$ i $(x, y-2^K)$ u početnoj matrici. 

Vremenska složenost je $O(NM+M+K)$, a memorijska $O(NM+K)$. matrici. 

