# 3 - Igrica

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Nikola Milosavljević | Tadija Šebez | Tadija Šebez | Nikola Milosavljević |

## Rešenje kada je $N, Q \leq 1000$

Na upite za ovaj podzadatak moguće je odgovoriti direktnim izračunavanjem tražene sume.

## Rešenje kada je $S_i \leq 10$

Upite možemo da rešavamo iz dva dela. Prvih $S_i$ članova sume možemo da uračunamo direktno po formuli kao u prošlom podzadatku, a za ostale članove znamo da je $m > S_i$ pa je $S_i$ $mod$ $m = S_i$, te je dovoljno naći njihovu sumu i pomnožiti je sa $S_i$. Za brze upite o sumi na podnizu možemo da koristimo strukturu podataka **binarno indeksirano stablo** ili **segmentno stablo**. Ove strukture podržavaju izmenu članova niza, tako da lako možemo da podržimo i ažuriranja igrice. Vremenska složenost je $O((N+Q)logN)$.

## Rešenje kada je $A_i = 1$ i $T_i = 1$

U ovom podzadatku upiti se svode na izračunavanje sume $\Sigma_{m=1}^{R_i - L_i + 1} (S_i$ $mod$ $m)$. Primetimo da je $S_i$ $mod$ $m = S_i - \lfloor \frac{S_i}{m} \rfloor \cdot m$, pa možemo sumu da rastavimo po minusu. Prvi deo je $S_i \cdot (R_i - L_i + 1)$ i od njega oduzimamo drugi deo koji računamo iz više delova. Prvih $\sqrt{S_i}$ članova sume računamo direktno po formuli. Za ostale članove postoji najviše $\sqrt{S_i}$ različitih vrednosti za $\lfloor \frac{S_i}{m} \rfloor$ i možemo da odredimo levu i desnu granicu za svaku vrednost tako da možemo da izračunamo $\Sigma_{m=l}^{r} \lfloor \frac{S_i}{m} \rfloor \cdot m$ kao $\lfloor \frac{S_i}{m} \rfloor \Sigma_{m=l}^{r} m$ primenom formule za zbir uzastopnih prirodnih brojeva ili prekalkulisanjem ovih suma. Vremenska složenost je $O(Q \sqrt{S})$.

## Rešenje kada je $T_i = 1$

Upite rešavamo na sličan način kao u prethodnom podzadatku, ali su formule malo komplikovanije. Prekalkulisaćemo prefiksne sume niza $A_i$ i niza $A_i \cdot i$. Pronalazimo grupe kao u prošlom podzadatku i umesto zbira uzastopnih celih brojeva, koristićemo prekalkulisane vrednosti. $\Sigma_{m=l}^{r} A_{L_i + m - 1} \cdot \lfloor \frac{S_i}{m} \rfloor \cdot m$ se svodi na izračunavanje $\Sigma_{m=l}^{r} A_{L_i + m - 1} \cdot m$ pošto je vrednost $\lfloor \frac{S_i}{m} \rfloor$ fiksna za svaku grupu. Izračunavanje pomenute sume moguće je preko suma podniza niza $A_i$ i $A_i \cdot i$. vremenska složenost je $O(Q \sqrt(S))$

## Rešenje za sve bodove

Za celo rešenje potrebno je još podržati operacije izmene niza. Dovoljno je umesto prekalkulisanih prefiksnih suma koristiti **binarno indeksirano stablo** za održavanje suma na podnizu. Vremenska složenost ovog rešenja je $O(Q \sqrt{S} log N)$