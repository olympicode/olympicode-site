# B1 - Kuvar

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Vladimir Milovanović | Dimitrije Erdeljan | Dimitrije Erdeljan | Marko Šišović |

## Glavno rešenje

Prva dva podzadatka možemo jednostavno rešiti sa dve ugnježdene petlje koje isprobavaju svaki par $(i, j)$ i broje za koliko takvih parova je $X_i = Z_{Y_j}$. Vremenska složenost ovog algoritma je $\mathcal{O}(N^2)$, što neće biti dovoljno za preostale podzadatke.

Algoritam možemo poboljšati tako što razdvojimo ove dve petlje: prvo ćemo prebrojati koliko postoji epizoda za svako moguće jelo, odnosno izračunati niz $C$, gde je $C_i$ broj indeksa $j$ gde $X_j = i$. Pošto su sve vrednosti $X_i$ najviše $N$, ovaj niz staje u memoriju i možemo ga popuniti jednim prolazom kroz $X$.

Sada je dovoljno da prođemo kroz $Z$, i za svako $Z_i$ ukupnom broju dodamo $C_{Z_i}$ (broj elemenata u $X$ koji bi bili odgovarajući par). Vremenska složenost je sada $\mathcal{O}(N)$, sasvim dovoljno za $N \leq 10^5$.