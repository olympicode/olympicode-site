# 3 - Zagrade

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Mladen Puzić | Aleksa Milisavljević |

## Rešenje kada $N, Q \leq 50$
Nakon svake promene, prebacujmo jednu po jednu zagradu sa početka na kraj, dok ne naiđemo na prvi put kada imamo validan niz zagrada. Rešenje je broj prebačenih zagrada. Proveravamo da li je niz zagrada validan tako što idemo sleva nadesno i održavamo broj neuparenih otvorenih zagrada. Ukoliko naiđemo na otvorenu zagradu, povećavamo taj broj. Ukoliko naiđemo na zatvorenu zagradu, a broj neuparenih otvorenih zagrada je veći od $0$, onda uparujemo jednu otvorenu zagradu sa tom zatvorenom zagradom, pa smanjujemo taj broj. Ukoliko nemamo neuparenih otvorenih zagrada, a naiđemo na zatvorenu zagradu, niz zagrada nije validan. On takođe nije validan ako završimo proces sa neuparenim otvorenim zagradama. 

Vremenska složenost je $O(QN^2)$, a memorijska $O(N)$.

## Rešenje kada $N,Q \leq 5000$
U ovom podzadatku ćemo primeniti svaku promenu i pokušati da nađemo rešenje u $O(N)$. Posmatrajmo sledeći niz:

$$
p_0 = 0
$$

$$
\begin{equation}
p_i = \begin{cases}
  p_{i−1}+1, & i \text{-ta zagrada je otvorena} \\
  p_{i−1}−1, & i \text{-ta zagrada je zatvorena}
    \end{cases}
\end{equation}
$$

Primetimo da je uslov da niz zagrada bude validan da važi $p_i \leq 0$ za svako $1 \leq i \leq N$ i $p_N = 0$ (ovo je ekvivalentno tome da nijedan prefiks nema više zatvorenih nego otvorenih zagrada i da ukupno imamo jednako otvorenih i zatvorenih zagrada).

Posmatrajmo sad šta se desi kada prvih $i$ zagrada prebacimo na kraj. Možemo primetiti da će se prvih $i$ elemenata niza $p_i$ prebaciti na kraj i onda će se ceo niz povećati za $−p_i$. Pošto želimo da svi elementi budu veći ili jednaki $0$, onda moramo da ga povećamo za što više, što znači da ćemo uzeti što manje $p_i$. Dakle, rešenje je $i$ za koje je $p_i$ najmanje. Ukoliko ima izjednačenja, onda uzimamo najmanje takvo $i$. Nakon svake promene samo ponovo izračunamo niz $p_i$. 
 
 Vremenska složenost je $O(QN)$, a memorijska $O(N)$.

## Rešenje kada sve promene menjaju zatvorene zagrade u otvorene
Primetimo da, kako bi niz zagrada bio validan, moramo imati jednak broj otvorenih i zatvorenih zagrada. Recimo da na početku imamo $l$ otvorenih, a $r$ zatvorenih zagrada. Ukoliko $r < l$ onda očigledno nikad ne možemo dobiti validan niz zagrada. U suprotnom, moći ćemo da imamo validan niz zagrada samo nakon što $\frac{r − l}{2}$ zatvorenih zagrada pretvorimo u otvorene. Ukoliko $\frac{r − l}{2} > Q$, onda opet nikad nećemo imati rešenje. U suprotnom, dovoljno je da primenimo rešenje iz prethodnog podzadatka nakon $\frac{r − l}{2}$ promena (svi ostali rezultati su $−1$). 
 
Vremenska složenost je $O(N + Q)$, a memorijska $O(N)$.

## Glavno rešenje
Ovaj podzadatak se radi slično kao drugi podzadatak, samo zbog efikasne promene niza $p_i$ potrebno je da održavamo segmentno stablo sa lenjom propagacijom nad njim. Promena koja je potrebna je dodavanje $+1$ ili $−1$ na neki sufiks, i nalaženje minimuma celog niza. Da bismo uzeli najlevlji minimum celog niza, segmentno stablo gradimo nad nizom parova $\{p_i, i\}$, pa ćemo upitom minimuma dobiti onaj par sa najmanjim $p_i$, a najmanjim indeksom u slučaju izjednačenja. 
 
 Vremenska složenost je $O(QlogN)$, a memorijska $O(N)$.