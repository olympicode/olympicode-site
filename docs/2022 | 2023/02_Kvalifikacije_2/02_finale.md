# 2 - Finale

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Marko Milenković | Marko Šišović | Jovan Bengin | Vladimir Milovanović |

## Glavno rešenje

Ako posmatramo puteve na rubu matrice, vidimo da i sva polja na rubu (tj. prvi i poslednji red i kolona) moraju imati redara. Ako je $N \leq 2$ ili $M \leq 2$, to znači da će sva polja u matrici imati redara, pa je u tom slučaju rešenje $N \times M$.

Nadalje pretpostavljamo da važi $N, M \geq 3$. Posmatrajmo matricu dobijenu brisanjem prvog i poslednjeg reda i kolone - u ovoj novoj $(N-2) \times (M-2)$ matrici ćemo tražiti maksimalan broj polja gde ne moramo postaviti redare, ako znamo da su svi putevi na rubu već pokriveni. 
Za svaka dva susedna polja važi da barem jedno od njih ima redara, jer inače put koji ih razdvaja ne bi bio pokriven. Ovaj uslov je i dovoljan, jer će tada i svi putevi biti pokriveni.

Dakle, potrebno je naći najveći skup polja u kome ne postoje dva susedna. Ovo je poznat zadatak: obojimo matricu šahovski crno-belo i uzmemo sva polja one boje koja se više puta pojavljuje. Pošto se broj polja crne i bele boje razlikuje za najviše jedan, biće $\lceil \frac{(N-2) \cdot (M-2)}{2} \rceil$ polja jedne, i $\lfloor \frac{(N-2) \cdot (M-2)}{2} \rfloor$ polja druge boje. To znači da možemo imati maksimalno $\lceil \frac{(N-2) \cdot (M-2)}{2} \rceil$ polja bez redara, pa je minimalan broj redara $N \cdot M - \lceil \frac{(N-2) \cdot (M-2)}{2} \rceil$.