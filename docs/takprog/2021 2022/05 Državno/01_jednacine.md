# B1 - Jednačine

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Nikola Milosavljević | Vladimir Milenković | Dragan Urošević | Aleksandar Zlateski |

## Rešenje podzadatka 1
Primetimo da je u ovom slučaju jedina moguća vrednost za $n$ broj
$$
n = A\cdot S(n) + B = 0 \cdot S(n) + B = B.
$$
Zbog toga je dovoljno samo proveriti da li je broj $n=B$ između $X$ i $Y$ i ako jeste ispisati taj broj, u suprotnom ispisati vrednost $-1$. Složenost ovog rešenja je $O(1)$.

## Rešenje podzadatka 2
Kako je $n\leq Y \leq 10^6$, dovoljno je za svako $n$ iz intervala $[X,Y]$ odrediti zbir cifara (uzastopnim deljenjem tog broja sa $10$ i sabiranjem ostataka), a nakon toga proveriti da li zadovoljava jednačinu . Naravno, nakon pronalaska prve takve vrednosti za broj $n$ ispisuje se ta vrednost i prekida izvršavanje programa. Ako nijedan broj iz intervala $[X,Y]$ ne zadovoljava jednačinu, ispisuje se vrednost $-1$. Složenost ovog rešenja je $O(Y\log Y)$.

## Rešenje podzadataka 3 i 4
Primetimo da ako je $1\leq X \leq n \leq Y \leq 10^{18}$, onda je $1 \leq S(n) \leq 18 \cdot 9 = 162$. Samim tim je skup mogućih vrednost za izraz $A\cdot S(n) +B$ zapravo skup
$$
U = \{A\cdot T + B|T = 1, 2, \dots, 162\}
$$
i to je skup mogućih vrednosti za broj $n$.

Prema tome, dovoljno je za elemente $n\in U$, proveriti da li zadovoljavaju jednačinu 
$$
S(n) = S(A\cdot T + B) = T
$$
i ako neki od njih zadovoljava ispisati njegovu vrednost, u suprotnom ispisati broj $-1$. Broj elemenata skupa $U$ je $O(\log Y)$, a provera da li neki element $n$ skupa $U$ zadovoljava gornju jednakost ima složenost $O(\log n)=O(\log Y)$, pa je složenost celog algoritma $O(\log^2 Y)$. 

Pri rešavanju podzadatka 4 treba voditi računa da pri računanju vrednosti $A\cdot T + B$ može doći do prekoračenja.  
