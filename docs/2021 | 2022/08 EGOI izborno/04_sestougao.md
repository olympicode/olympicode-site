# 4 - Šestougao

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Nikola Milosavljević | Aleksa Milisavljević | Aleksa Milisavljević | Pavle Martinović |

Prva stvar koju treba da primetimo je da uslov da je figura šestogao i da ima stranice paralelne ivicama matrice zapravo znači da je u pitanju figura koja se dobija tako što iz pravougaonika izbacimo manji pravougaonik koji je takav da im se tačno jedan ćošak poklapa.

## Rešenje kada $N \leq 5$
  
U ovom podzadatku možemo da fiksiramo svaki šestougao, proverimo da li je on lep i preračunamo odgovor za svaku podmatricu. Različitih šestouglova ima $O(N^6)$, dok različitih podmatrica ima $O(N^4)$. Zbog toga, ovo rešenje radi u vremenskoj složenosti $O(N^{10})$.

Vremenska složenost je $O(N^{10})$, a memorijska $O(N^4)$.

## Rešenje kada $A = 8, Q \leq 10$

Primetimo da su šestouglovi sa obimom $8$ upravo kvadrati dimenzija $2  \times  2$ iz kojih je izbačen jedan ćošak. Takvih šestouglova ima $O(N^2)$ u matrici. U svakom upitu možemo da iteriramo kroz celu podmatricu i izračunamo zbir brojeva u svakom lepom šestouglu.

Vremenska složenost je $O(Q \cdot N^2)$, a memorijska je $O(N^2)$.

## Rešenje kada $N \leq 50, Q \leq 10$

Za rešavanje ovog podzadatka moramo detaljnije da razmotrimo kada tačno izbacivanjem manjeg pravougaonika iz većeg nastaje lep šestougao.

Pretpostavimo da smo imali pravougaonik dimenzija $w \times h$ i da smo iz jednog njegovog ćoška izbacili pravougaonik dimenzija $p \times q$. Posmatrajmo dva slučaja:

- Prvi slučaj: $w \neq h$, tj. orginalni pravougaonik nije kvadrat. Bez umanjenja opštosti, pretpostavimo da $w > h$. Šestougao koji nastaje brisanjem pravougaonika ima stranice dužina $w$, $h$, $w-p$, $q$, $p$, $h-q$. Kako $w \neq h$ i kako u šestouglu, da bi bio lep, svaka dužina mora da se javlja barem dva puta , to mora da važi $w = w-p$ ili $w = q$ ili $w = p$ ili $w = h-q$. Međutim, kako važi $p, w-p < w$ i $q, h-q < h < w$ , to ovaj slučaj nije moguć, tj. šestougao mora biti kvadarat.
- Drugi slučaj: $w = h$. Uvedimo $a = w = h$. Šestougao koji nastaje brisanjem pravougaonika ima stranice dužina $a$, $a$, $a-p$, $q$, $p$, $a-q$. Kako svaka dužina mora da se javlja barem dva puta, to razlikujemo sledeća dva slučaja: $p = q$ i $p = a - q$. Dodatno, primetimo da je obim ovog šestougla upravo $a + a + a - p + q + p + a - q = 4a$, tj. $a = \frac{A}{4}$.

Dakle, da bi šestougao bio lep, on mora da nastane tako što se iz kvadrata stranice $a = \frac{A}{4}$ izbaci pravougaonik dimenzija $p \times q$, za koje važi $p = q$ ili $p + q = a$. Primetimo da u početnoj matrici kvadrata stranice $a$ ima $(N-a+1)^2$, a za svaki od njih postoji $4(a-1)$ pravougaonika koje možemo da izbacimo da bi dobili lep šestougao. Dakle, ukupno postoji $O(N^3)$ lepih šestouglova u matrici.

Koristeći ovu informaciju, lako možemo da rešimo podzadatak. U svakom upitu, prođemo kroz sve lepe šestouglove. Ovo je najlakše uraditi tako što prvo fiksiramo gornji levi ćošak kvadrata iz kojeg brišemo pravougaonik, zatim stranice pravougaonika i konačno jedan od četiri ćoška kvadrata koji se poklapa sa pravougaonikom.

Vremenska složenost je $O(Q N^3)$, a memorijska je $O(N^2)$.

## Rešenje kada $N \leq 50$

Ovaj zadatak zahteva da malo popravimo rešenje iz prethodnog. Ključno je primetiti da za svaki gornji levi ćošak kvadrata iz kojeg izbacujemo pravougaonik možemo da izračunamo lep šestougao koji nastaje sa najvećim zbirom. Ovo zapamtimo za svako polje. Potom u svakom upitu prođemo kroz sva polja koja su kandidati za gornji levi ćošak pravougaonika i na taj način pronađemo lep šestougao sa najvećim zbirom koji se potpuno nalazi u podmatrici iz upita.

Vremenska složenost je $O(Q N^2)$, a memorijska je $O(N^2)$.

## Rešenje kada $A = 8$ 

Za rešenja ovog podzadatka je neophodna tehnika sparse tabela.

Prvo u pomoćnoj matrici $b[i][j]$ zapamtimo lep šestougao sa najvećim zbirom koji je nastao tako što smo kvadratu kome je gornje levo polje upravo $(i,j)$ sklonili jedan ćošak.

U pomoćnoj matrici $sparse[i][j][k]$, preračunamo maksimume svih lepih šestouglova koji nastaju od kvadrata dimenzija $2 \times 2$ kojima je gornji levi ćošak na nekom od polja iz skupa $\{(i,j),(i,j+1),...,(i,j+2^k-1)\}$. Za ovu matricu je lako naću rekurzivnu formulu:

$$
sparse[i][j][0] = b[i][j],
$$ 

$$
sparse[i][j][k] = max(sparse[i][j][k-1],sparse[i][j+2^(k-1)][k-1])
$$

Na osnovu ove matrice, možemo da odgovaramo na upite u vremenskoj složenosti $O(N)$. Neka je $k$ najveći broj takav da je $2^k \leq r-l$. Da bi odgovorili na upit, prođemo kroz svaki red $i$ u intervalu $[u,d-1]$ i za svaki od njih izračunamo vrednost $max(b[i][l][k],b[i][r-2^k][k])$ (na ovaj način smo uzeli maksimum svih lepih šestouglova kojima je gornji levi ćošak u redu $i$). Maksimum od svih tih vrednosti je odgovr na upit.

Vremenska složenost je $O(N^2 \log N + Q N)$, a memorijska $O(N^2 \log N)$ (ako pamtimo uvek samo rezultate prethodnog kola).

## Glavno rešenje

Za glavno rešenje, neophodno je generalizovati ideju iz prethodnog podzadatka, korišćenjem opservacije o tome kakav pravougaonik moramo da izbacimo da bi dobili lep šestougao. U matrici $b[i][j]$ zapamtimo maksimum svih lepih šestouglova koji su nastali tako što smo izbacili neki pravougaonik iz kvadrata kojem je gornje levo polje $(i,j)$. Potom računamo i koristimo tabelu na sličan način kao u prethodnom podzadatku.
  
Vremenska složenost je $O(N^3 + Q N)$, a memorijska $O(N^2 \log N)$.

Zadatak je bilo moguće rešiti i u boljoj vremenskoj složenosti $O(N^3 + N^2 \log^2 N + Q)$, korišćenjem dvodimenzionalnih tabela, ali to nije bilo potrebno za maksimalne poene.