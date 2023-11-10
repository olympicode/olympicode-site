# A1 - Život u gradu

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Dragan Urošević | Aleksa Milisavljević |

## Rešenje prvog podzadatka
U ovom slučaju, zbog ograničenja na dužinu veličinu table moguće je u datom vremenskom ograničenju proveriti sve puteve i odrediti za svaki od njih koliko se koncerta održava na tom putu. Naime broj raznih putvea je $2^{N+M-2}\leq 2^{18}$. Naravno, ako je na nekom putu broj koncerta baš $K$, prekida se proveravanje puteva, ispisuje odgovor  "DA" i ako je potrebno ispisuje odgovarajući put. Ako ni na jednom putu nije bilo $K$ koncerta, ispisuje se odgovor "NE". Složenost opisanog rešenja je ${\mathcal O}(2^{N+M})$.

## Rešenje drugog i trećeg podzadatka
 Za početak je potrebno odrediti podmatricu koju čine polja na kojima se održavaju koncerti. Nakon toga treba diskutovati (razlikovati) nekoliko slučajeva, u zavisnosti od dimenzija i pozicije podmatrice i broja $K$. Mislimo da nema potrebe da izvodimo kompletnu diskusiju. Složenost opisanog rešenja je ${\mathcal O}(NM)$.

## Rešenje četvrtog i petog podzadatka
Ovi podzadaci se mogu rešiti primenom dinamičkog programiranja. Neka je $dp[i][j][l]=true$, ako postoji put od polja $(1,1)$ do polja $(i,j)$ na kome postoji $l$ polja na kojima se održava koncert i $dp[i][j][l]=false$ u suprotnom. Tada je $dp[N][M][K]$ odgovor na pitanje da li postoji traženi put ili ne. Niz $dp$ popunjavama (računamo) vrsta po vrsta:

- $dp[1][1][1]=true$, ako se na polju $(1,1)$ održava koncert i $dp[1][1][1]=false$, ako se na polju $(1,1)$ ne održava koncert.
- $dp[1][1][0]=true$, ako se na polju $(1,1)$ ne održava koncert i $dp[1][1][0]=false$, ako se na polju $(1,1)$ održava koncert.
- $dp[1][1][l]=false$, za $2\leq l \leq K$.
- Ako se na polju $(i,j)$  održava koncert, onda je $dp[i][j][l]=true$, ako i samo ako je $dp[i-1][j][l-1]=true$ ili $dp[i][j-1][l-1]=true$ (naravno, ako je $i \geq 2$ i $j \geq 2$, u suprotnom, odgovarajući element ne postoji). Primetimo takođe da je u ovom slučaju $dp[i][j][0]=false$.
- Ako se na polju $(i,j)$  ne održava koncert, onda je $dp[i][j][l]=true$, ako i samo ako je $dp[i-1][j][l]=true$ ili $dp[i][j-1][l]=true$ (naravno, ako je $i \geq 2$ i $j \geq 2$, u suprotnom, odgovarajući element ne postoji).

 Ako traženi put postoji, on se može rekonstrisati korišćenjem niza  $dp$. Naime, krećemo od polja $(N,M)$ i tražimo put na kome se održava $K$ koncerta. Ako se nalazimo na polju $(i,j)$ i tražimo put na kome se održava $l$ koncerta, onda mora biti $dp[i][j][l]=true$ i mogu nastupiti sledeća dva slučaja:

- Na polju $(i,j)$ se odžava koncert. Tada broj koncerata smanjujemo za jedan, tj. $l$ se smanjuje za jedan ($l \leftarrow l-1$) i pomeramo se na polje levo ili gore (ako postoji) za koje odgovarajući element niza $dp$ ($dp[i-1][j][l-1]$ ili $dp[i][j-1][l-1]$) ima vrednost $true$.
- Na polju $(i,j)$ se ne odžava koncerta. Tada broj kocerta ostaje nepromenjen, a pomeramo se na polje levo ili gore (ako postoji) za koje odgovarajući element niza $dp$ ($dp[i-1][j][l]$ ili $dp[i][j-1][l]$) ima vrednost $true$.
- Postupak prekidamo kada stignemo do polja $(1,1)$.

Složenost opisanog rešenja je određena složenošću popunjavanja niza $dp$ i iznosi ${\mathcal O}(NMK)$.

## Rešenje šestog podzadatka

U ovom slučaju možemo formirati graf u kome su čvorovi polja na koja je podeljen grad, a ivice postoje od polja do njegovih suseda levo i dole. Polja na kojima se održavaju koncerti su zabranjena i na njih se ne može stati. Traženi put postoji, ako postoji put u grafu (put zaobilazi zabranjena polja). Taj put možeo pronaći, na primer, primenom obilaska u širinu. Za svako polje možemo pamtiti odakle smo stigli i na taj način rekonstruisati rešenje. Složenost opisanog rešenja je  ${\mathcal O}(NM)$.

## Glavno rešenje
Neka je $dp_1[i][j]$ minimalni broj $l$ takav da postoji put od polja $(1,1)$ do polja $(i,j)$, na kome se održava $l$ koncerata. Neka je $dp_2[i][j]$ maksimalni broj $l$ takav da postoji put od polja $(1,1)$ do polja $(i,j)$, na kome se održava $l$ koncerata. Tada za svako polje $(i,j)$ važi da postoji put od polja $(1,1)$ do polja $(i,j)$ na kome se održava $l$ koncerta, gde je $l$ bilo koji broj između $dp_1[i][j]$ i $dp_2[i][j]$  ($dp_1[i][j]\leq l  \leq dp_2[i][j]$). Naime od bilo kog početnog puta između dva polja se može stići do bilo kog završnog, tako što se prelazi preko niza puteva od kojih se svaka dva uzastopna razlikuju u samo jednom polju. Kada se na putu promeni samo jedno polje i broj polja na kojima se održava koncert se može promeniti (smanjiti ili povećati) za najviše jedan (1). Ako krenemo od puta sa minimalnim brojem koncerta prema putu sa maksimalnim brojem koncerta, proći ćemo preko puteva na kojima je broj koncerta bilo koji broj između ta dva broja. 
Zbog toga, postoji put sa tačno $K$ koncerata, ako i samo ako je $dp_1[N][M]\leq K  \leq dp_2[N][M]$.
Nizove $dp_1$ i $dp_2$ računamo na sličan način kao niz $dp$ u četvrtom i petom podzadatku:

- Ako se na polju $(1,1)$ održava koncert, onda je $dp_1[1][1]=dp_2[1][1]=1$.
- Ako se na polju $(1,1)$ ne održava koncert, onda je $dp_1[1][1]=dp_2[1][1]=0$.
- Ako se na polju $(i,j)$ održava koncert, onda je $dp_1[i][j]=\min(dp_1[i-1][j],dp_1[i][j-1])+1$ i $dp_2[i][j]=\max(dp_2[i-1][j],dp_2[i][j-1])+1$.
- Ako se na polju $(i,j)$ ne održava koncert, onda je $dp_1[i][j]=\min(dp_1[i-1][j],dp_1[i][j-1])$ i $dp_2[i][j]=\max(dp_2[i-1][j],dp_2[i][j-1])$.

Ako postoji put sa tačno $K$ koncerata, onda se on rekonstruiše tako što se krene od polja $(N,M)$ i traži put koji ima $l=K$ koncerata. Ako se nalazimo na polju $(i,j)$ i tražimo put koji ima $l$ koncerata ($dp_1[i][j]\leq l \leq dp_2[i][j]$), onda mogu nastupiti dva slučaja:

- Ako se na polju $(i,j)$ održava koncert, onda treba smanjiti broj koncerata $l$ za jedan i preći na polje iznad ili polje levo, tako da broj koncerata bude između $dp_1$ i $dp_2$ za to novo polje.
- Ako se na polju $(i,j)$ ne održava koncert, onda se broj koncerata $l$ ne menja, a treba preći na polje iznad ili polje levo, tako da broj koncerata bude između $dp_1$ i $dp_2$ za to novo polje.
- Postupak prekidamo kada stignemo do polja $(1,1)$.

Složenost opisanog rešenja je određena složenošću popunjavanja nizova $dp_1$ i $dp_2$ i iznosi ${\mathcal O}(NM)$.