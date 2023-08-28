# A3 - AdVenture Communist

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Igor Pavlović | Igor Pavlović | Igor Pavlović | Tadija Šebez |

## Rešenje za $N, T \leq 2000$

Ovde je dovoljno simulirati dešavanja trenutak po trenutak u složenosti $O(NT)$.

## Rešenje za $N\leq 200$

U ovom slučaju je potrebno primetiti da je opisana rekurenta veza zapravo linearna transformacija koja se može predstaviti u matričnom obliku kao
$$
A(t+1)=K \cdot A(t)
$$ gde je
$$
A(t) = [a_0(t), a_1(t), ..., a_n(t)]^T
$$
 $$
 K_{i,i} = C \text{  ,  } K_{i,i+1} = (i+1) \cdot K_{i+1}
 $$
 $$
 K_{ij}=0 \text{  za  } (j!=i) \wedge (j!=i+1)
 $$

Odavde se dobija sledeća jednakost:
$$
A(t)=K^t \cdot A(0)
$$
iz koje možemo odrediti vrednost $a_0(T)$ u složenosti $O(N^3\log T)$ brzim stepenovanjem matrica.


## Rešenje za $C = 1$

Primetimo prvo da se doprinos svake pojedinače fabrike može posmatrati odvojeno od ostalih zato što je opisana transformacija linearna. Ukupan broj krompira u trenutku $T$ dobijamo kao zbir doprinosa svake fabrike.

Za transformaciju
$$
a_i(t+1)=a_i(t)+(i+1) \cdot K_{i+1} \cdot  a_{i+1}(t)
$$
se može indukcijom dokazati da je doprinos $i$-te fabrike ukupnom broju krompira nakon $t$ sekundi zapravo:
$$
d_i = \prod_{j=1}^{i} K_j \cdot (t-j+1)
$$
Sumiranjem svih doprinosa dobijamo:
$$
a_0(T) = a_0(0) + \sum_{i=1}^{N} a_i(0) \cdot d_i = a_0(0) + \sum_{i=1}^{N} a_i(0) \cdot \prod_{j=1}^{i} K_j \cdot (T-j+1)
$$
Na osnovu ovog izraza možemo odrediti $a_0(T)$ u složenosti $O(N)$.

## Glavno rešenje

Primetimo da se zadata rekurentna veza može zapisati kao:
$$
a_i(t+1)=C \cdot a_i(t)+(i+1) \cdot K_{i+1} \cdot a_{i+1}(t)= C \cdot (a_i(t)+(i+1) \cdot \frac{K_{i+1}}{C} \cdot a_{i+1}(t))
$$
U matričnom obliku ova rekurentna veza može se zapisati kao kompozicija dve linearne transformacije na sledeći način:
$$
A(t+1)=C \cdot I \cdot K' \cdot A(t)
$$ gde je
$$
A(t) = [a_0(t), a_1(t), ..., a_n(t)]^T
$$
 $$
 K_{i,i} = 1 \text{  ,  } K_{i,i+1} = (i+1) \cdot \frac{K_{i+1}}{C}
 $$
 $$
 K_{ij}=0 \text{  za  } (j!=i) \wedge (j!=i+1)
 $$
 i matrica $I$ je jedinična matrica.

 Odavde se dobija sledeća jednakost:
$$
A(t)=C^t \cdot K'^{t} \cdot A(0)
$$
Pošto je matrica $K'$ ista kao u slučaju kada je $C=1$ možemo zaključiti da je doprinos $i$-te fabrike:
$$
d_i = C^t \prod_{j=1}^{i} \frac{K_j}{C} \cdot (t-j+1) = C^{t-i} \cdot \prod_{j=1}^{i} K_j \cdot (t-j+1)
$$
Sumiranjem svih doprinosa dobijamo:
$$
a_0(T) = a_0(0) + \sum_{i=1}^{N} a_i(0) \cdot d_i = a_0(0) + \sum_{i=1}^{N} a_i(0) \cdot C^{T-i} \cdot \prod_{j=1}^{i} K_j \cdot (T-j+1)
$$
Na osnovu ovog izraza možemo odrediti $a_0(T)$ u složenosti $O(N)$.
