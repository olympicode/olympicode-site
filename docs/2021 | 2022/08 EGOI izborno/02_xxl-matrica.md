# 2 - XXL Matrica

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Marko Savić | Aleksa Milisavljević | Dragan Urošević | Vladimir Milovanović |

Neka je $N$ broj vrsta i neka je $M$ broj kolona. Pretpostavimo da su vrste numerisane brojevima od $0$ do $N-1$, a kolone brojevima od $0$ do $M-1$. 

Primetimo da ne mora za svaki izbor ulaznih podataka postojati rešenje. Naime ako je $0\leqslant a_i < M$, onda to znači da se na polju sa koordinatama $(i,a_i)$ nalazi crno polje. Zbog toga broj belih polja kojima počinje kolona $a_i$ nije veći od $a_i$, pa je $b_{a_i} \leqslant i$. Odnosno, ako je $0\leqslant a_i < M$ i $b_{a_i} > i$ za neko $i$, onda ne postoji matrica koja zadovoljava uslove opisane nizovima $a$ i $b$. Slično, ako je $0\leqslant b_j < N$, onda je polje sa koordinatama $(b_j, j)$ crno, pa vrsta $b_j$ počinje sa ne više od $j$ belih polja i zbog toga je $a_{b_j} \leqslant j$. Dakle ako za neko $j$ ($0\leqslant j < M$) važi da je $0\leqslant b_j < N$ i $a_{b_j}>j$, onda ne postoji matrica koja zadovoljva uslove opisane nizovima $a$ i $b$.

Pretpostavimo da postoji matrica opisana nizovima $a$ i $b$. Tada za svako $i$ za koje je $0\leqslant a_i < M$ važi da je polje sa koordinatama $(i,a_i)$ crno. Slično, ako za neko $j$ važi da je $0\leqslant b_j < N$, onda je polje sa koordinatama $(b_j,j)$ crno.  I to je minimalni skup crnih polja. Prema tome, broj crnih polja ćemo odrediti tako što izbrojimo koliko ima različitih polja u uniji skupova
$$
A=\{(i,a_i)|0\leqslant i < N, 0\leqslant a_i < M\}
\quad \text{i} \quad
B=\{(b_j,j)|0\leqslant j < M, 0\leqslant b_j < N\}.
$$

Pretpostavimo da postoji matrica koja zadovoljava uslove opisane nizovima $a$ i $b$. Tada mogu biti crna sva polja $(i,j)$ ($0\leqslant i < N$, $0\leqslant j < M$) koja zadovoljavaju i sledeća dva uslova:
$$
a_i \leqslant j < M
\quad \text{i}\quad
b_j \leqslant i < N.
$$

## Rešenje kad je $N,M \leq 4$
U ovom slučaju se mogu ispitati sve matrice dimenzija $N\times M$ čija su polja bela ili crna (tj, za svaku od njih se može proveriti da li zadovoljava uslove opisane nizovima $a$ i $b$). Naime matrica ima $2^{N M} \leqslant 2^{16} = 65536$. Nakon toga se lako odredi broj crnih polja u matrici koja ima najmanji i/ili najveći broj crnih polja.

## Rešenje kad je $N,M \leq 1.000$

U ovom slučaju se za svako polje matrice određuje da li je crno, za varijantu kada treba da odredimo najmanji broj crnih polja i/ili za varijantu kada treba da odredimo najveći broj crnih polja. Za određivanje boje koristimo gore navedene uslove. Složenost ovog rešenja je $\Theta(NM)$.

## Rešenje kad je $N, M \leq 100.000$

Opišimo kako određujemo maksimalni broj crnih polja (opet ćemo pretpostaviti da postoji matrica koja zadovoljava uslove problema). Maksimalan broj crnih polja određujemo tako što određujemo maksimalan broj crnih polja u vrstama polazeći od nulte vrste i obrađujući ih redom. Ako trenutno obrađujemo vrstu sa rednim brojem $i$, onda mogu biti crna sva polja $(i,j)$ koja zadovoljavaju uslove $j\geqslant a_i$ i $b_j \leqslant i$. Jedan od načina da to uradimo je da definišemo pomoćni niz $c$ dužine $M$ čiji elementi na početku imaju vrednost $0$, a ako se trenutno obrađuje vrsta broj $i$, onda će vrednosti elemenata niza $c$ biti
$$
c_j = \begin{cases}
1,\quad &\text{ako je }b_j\leqslant i\\
0,\quad &\text{ako je }b_j > i.
\end{cases}
$$
Tada će najveći broj crnih polja u vrsti broj $i$ biti
$$
c_{a_i} + c_{a_i+1} + c_{a_i+2} + \dotsb + c_{M-1}.
$$
Ove zbirove ćemo najefikasnije odrediti koristeći Fenvikovo stablo (Fenwick tree) ili segmentno stablo. Primetimo da se niz $c$ (potencijalno) menja pri obradi svake vrste, pa u skladu sa tim treba ažurirati i odgovarajuće stablo. Složenost ovog rešenja je $\Theta(N\log M)$.

Minimalni broj crnih polja možemo odrediti tako što formiramo skup sastavljen od parova $(i,a_i)$ ($0\leqslant i < N$, $a_i < M$) i $(b_j,j)$ ($0\leqslant j < M$, $b_j < N$), a zatim izbrojimo koliko u tom skupu ima elemenata. 

