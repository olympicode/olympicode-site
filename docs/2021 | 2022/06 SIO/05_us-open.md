# 5 - US Open

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Mladen Puzić | Tadija Šebez |

Prva stvar koju je potrebno da primetimo jeste   kako da dodelimo vreme trajanja nekom konkretnim meču. Primetimo da nam se uvek isplati da to bude vreme trajanja prvog meča pobednika. Takav meč još uvek ima potencijal da bude interesantan, a ne ograničavamo se za buduće mečeve više nego što moramo. Sada je potrebno samo odrediti pobednika svakog meča dok zamišljamo da se njegovo vreme *propagira* na sledeće kolo.

## Rešenje kada $N \leq 4$
Pošto ima $16$ preostalih igrača, postojaće još ukupno $15$ mečeva. Za svaki meč možemo da odaberemo da li pobeđuje levi ili desni igrač, jer postoji samo $2^{15} = 32768$ kombinacija.

Vremenska složenost je $O(2^ {2^N})$, a memorijska $O(2^N)$.

## Rešenje kada $A[i] \leq 2$
Jasno je po gornjoj obzervaciji da će svaki meč trajati ili $1$ ili $2$ minuta (mora da igra Đoković). Numerišemo sve mečeve od $1$ do $2^{N+1}-1$. Sada, možemo raditi dinamičko programiranje oblika: 

$$
dp[i][1/2] = \text{optimalno rešenje ako meč }i\text{ traje 1, odnosno 2 minuta}
$$

Bazni slučajevi su očigledno mečevi prvog kola, za koje znamo koliko su trajali (i onda na jedan slučaj tih mečeva stavljamo $0$, a na drugi $-\infty$). 

Posmatrajmo neki fiksni meč $i$ koji nije meč prvog kola. Neka je $l$ meč iz kojeg je došao pobednik leve strane žreba, a $d$ meč iz kojeg je došao pobednik leve strane žreba.

Važe sledeće rekurentne veze: 

$$
dp[i][1] = \max(dp[l][1]+dp[r][1]+1, dp[l][1]+dp[r][2]+1, dp[l][2]+dp[r][1])
$$
$$
dp[i][2] = \max(dp[l][2]+dp[r][2]+1, dp[l][1]+dp[r][2]+1, dp[l][2]+dp[r][1])
$$ 

Dakle, svaka kombinacija, sem kada je meč $l$ trajao $2$ minuta, a meč $r$ trajao $1$ minut, daje jedan novi interesantan meč. Krajnji rezultat, ako je finale numerisano brojem $f$, je $\max(dp[f][1], dp[f][2])$.

Vremenska i memorijska složenost je $O(2^N)$.

## Rešenje kada $N \leq 17$ i $A[i] \leq 100$
Slično prethodnom podzadatku, radićemo dinamičko programiranje nad numerisanim mečevima:

$$
dp[i][j] = \text{optimalno rešenje ako meč }i\text{ traje } j \text{ minuta}
$$

Ponovo imamo tri slučaja:
- Prvi slučaj je ako ne želimo da trenutni meč bude interesantan. Onda jedan meč (levi ili desni) mora trajati $j$ minuta, za drugi možemo uzeti bilo koju vrednost, pa ćemo uzeti onu koja daje najviše interesantnih mečeva. 
- Drugi slučaj je da želimo da meč $i$ bude interesantan, a da **levi** meč traje $j$ minuta. Zato, desni meč mora trajati makar toliko, da bismo dobili novi interesantan meč. Uzećemo naravno optimalnu dužinu desnog meča.
- Treći slučaj je takođe da želimo da meč $i$ bude interesantan, a da **desni** meč traje $j$ minuta. Levi meč onda mora trajati najviše toliko. Ponovo uzimamo optimalnu dužinu levog meča.

Sve ovo možemo efikasno implementirati čuvajući prefiksne, odnosno sufiksne maksimume nad dinamičkim programiranjem za svaki meč.

Vremenska i memorijska složenost je $O(2^N\cdot maxA)$.

## Rešenje kada $N \leq 17$
Zadatak ponovo radimo dinamičkim programiranjem, mada ovaj put numerišemo i mečeve i igrače:

$$
dp[i][j] = \text{optimalno rešenje ako je pobednik meča }i\text{ igrač } j
$$

Ovde na prvi pogled ima $O(2^N\cdot 2^N)$ stanja, ali to nije tačno - broj igrača koji mogu biti pobednici nekog meča (koji su u tom delu žreba) dosta varira. U zbiru, zato, postoji samo $O(2^N \cdot N)$ stanja, jer svaki igrač može biti pobednik u samo $N$ različitih mečeva. Dinamičko programiranje možemo raditi kolo po kolo, krenuvši od drugog kola (prvo je već odigrano).

Sada, slično prethodnom podzadatku, ako nam je pobednik sa leve strane žreba i želimo interesantan meč, desno moramo odabrati igrača kojem je prvi meč trajao makar koliko prvi meč pobednika. Analogno radimo i ako želimo da pobednik bude iz desne strane žreba.

Kako bismo to efikasno uradili, moramo u obe polovine imati igrače sortirane po dužini prvog meča. Nakon doga, poput prethodnog zadatka možemo koristeći prefiksne/sufiksne maksimume nad nizom dinamičkog programiranja, kao i tehniku dva pokazivača ili binarnu pretragu, možemo naći odgovarajuće vrednosti. Sve ovo možemo jednostavno implementirati rekurzijom.

Vremenska složenost je $O(2^N \cdot N^2)$, a memorijska $O(2^N)$ (ako pamtimo uvek samo rezultate prethodnog kola).

## Glavno rešenje
Slično prethodnom podzadatku, samo što umesto da koristimo sortiranje na svakom nivou rekurzije, mi održavamo sortirani niz i spajamo ih tehnikom dva pokazivača, poput algoritma *merge sort*. Time smanjujemo vremensku složenost za $N$ faktor.

Vremenska složenost je $O(2^N\cdot N)$, a memorijska $O(2^N)$.

