## Glavno rešenje
Primetimo da su operacije razdvajanja i spajanja uzajamno inverzne
(tj. iverzne jedna drugoj), tako da ako neka dva dela spojimo, nikad ih više nećemo razdvajati.
U poslednjem potezu znamo da moramo da spojimo dva dela koji imaju jednake dužine, ili dva dela od kojih je levi za jedan kraći od desnog (tj. dužine delova su $\left\lfloor\frac{S}{2}\right\rfloor$ i $\left\lceil\frac{S}{2}\right\rceil$, gde je $S$ ukupna dužina gliste). Zbog toga treba da postoji indeks $k$, tako da je suma dužina prvih $k$ delova jednaka $\left\lfloor\frac{S}{2}\right\rfloor$, a suma dužina  preostalih delova iznosi $\left\lceil\frac{S}{2}\right\rceil$. Ako ne postoji takav indeks $k$, onda se određuje indeks $k$ tako da je

$$
\sum_{i=1}^{k-1} a_i< \left\lfloor\frac{S}{2}\right\rfloor
\quad \text{i}
\quad
\sum_{i=1}^{k} a_i >  \left\lceil\frac{S}{2}\right\rceil.
$$

Nakon toga se deo sa indeksom $k$ deli sve dok se ne dobije niz u kome postoji indeks $l$, takav da je

$$
\sum_{i=1}^{l} a_i = \left\lfloor\frac{S}{2}\right\rfloor.
$$

To postižemo tako što svaki put delimo deo sa indeksom  $k'$
za koji važi

$$
\sum_{i=1}^{k'-1} a_i < \left\lfloor\frac{S}{2}\right\rfloor
\quad \text{i}
\quad
\sum_{i=1}^{k'} a_i > \left\lceil\frac{S}{2}\right\rceil.
$$

Kada dobijemo niz delova (koji ima $n'$ delova) za koji postoji indeks $l$ takav da je

$$
\sum_{i=1}^{l} a_i = \left\lfloor\frac{S}{2}\right\rfloor.
$$,

onda raekrzivno pozivamo funkciju koja određuje minimalni broj operacija potreban da se spoje prvih $l$ delova u jedan deo i funciju koja određuje minimalan broj operacija potreban da se spoji poslednjih $n'-l$ delova  u jedan deo. Na kraju dva tako dobijena dela ćemo spojiti u jedan deo. Ukupan broj operacija je jednak zbiru broja operacija deljenja na početku funkcije, broju operacija za spajanje leve polovine, broja operacija za spajanje desne polovine i broja 1 za spajanje dva dobijena dela (polovine).

Znači, za rešavanje zadatka smo iskoristili tehniku podeli pa vladaj ($divide\ and\ conquer$). Primetimo da je složenost jednog rekurzivnog poziva (odnosno pripreme za rekrzivne pozive tokom izvršavanja tog rekurzivnog poziva) ${\mathcal O}(S)$, a da se rekurzivno poziva funkcija za nizove u kojima je suma dužina delova $\frac{S}{2}$, pa je po master teoremi složenost kompletnog funkcije ${\mathcal O}(S\log S)$.
 

