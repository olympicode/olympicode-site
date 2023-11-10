# 2 - TSM

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Mladen Puzić | Mladen Puzić | Mladen Puzić | Tadija Šebez |

## Rešenje kada $M \leq 9$
Prvo nađimo neko minimalno razapinjuće stablo grafa koji dobijemo kada kao grane dodamo svaki metro plan (u daljem tekstu MST). Za to možemo koristiti neki poznati algoritam, poput Kruskalovog ili Primovog. Nakon toga, za svaki mogući poredak proverimo da li nam daje MST i od takvih uzimamo leksikografski najveći.

Vremenska složenost je $O(M! \cdot M \cdot \alpha(M))$, a memorijska $O(M)$.

## Rešenje kada se svaki plan linije nalazi u najviše jednom ciklusu
Ovakav graf se zove *kaktus graf*. Možemo lako zaključiti da je u kaktus grafu, da bismo dobili MST, potrebno da u svakom ciklusu u grafu izbacimo najskuplju granu. Što znači, da se najskuplja grana mora naći u poretku nakon svih drugih grana u tom ciklusu.

Pošto je u pitanju kaktus graf, lako možemo *DFS* algoritmom naći sve cikluse (npr. posmatranjem svih povratnih grana), i tako svesti problem na spajanje $K$ nizova na leksikografski najveći način, što je poznat problem koji se može rešiti primenom prioritetnog reda (*std::priority_queue*).

Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.

## Rešenje kada je MST put i $N,M \leq 5000$
Pošto su cene svih grana različite, MST je jedinstven. Dakle, nađimo MST i znamo da će on biti put. Postavimo njegove grane redom u niz tako da je jedan kraj puta indeksiran sa $1$, a drugi sa $N-1$.

Sada, za svaku granu koja nije u MST, recimo da povezuje stanice $x$ i $y$, mora da važi da se nalazi u permutaciji nakon svih grana na putu između $x$ i $y$ u MST. Ako to ne važi, dodali bismo skuplju granu, a kasnije ne bismo mogli da dodamo jeftiniju, što znači da ne bismo dobili MST. Taj put odgovara nekom intervalu u našem nizu.

Sada možemo konstruisati novi, usmereni, graf, gde su planirane metro linije čvorovi, a grana od čvora $u$ do čvora $v$ postoji isključivo ako linija $u$ mora da se nađe pre linije $v$ u krajnjem poretku. Ove grane možemo lako naći prolaskom kroz niz za svaku granu van MST.

Sada se problem svodi na leksikografski najveće topološko sortiranje, koje je moguće jer svi čvorovi imaju različite cene. Možemo ga uraditi prioritetnim redom.

Vremenska složenost: $O(M^2\log M$), a memorijski $O(M^2)$.

## Rešenje kada je MST put
Slično prethodnom podzadatku, nalazimo MST i za svaku granu van njega znamo da sve grane na tom putu se moraju nalaziti pre nje. Ono što je potrebno da primetimo jeste da ćemo grane na tom putu dodavati opadajuće po ceni, tj. ako želimo leksikografski najveći poredak, nema razloga da dodamo manju granu MST-a pre veće.

Zato, umesto da konstruišemo sve grane usmerenog grafa, dovoljno je konstruisati granu između najjeftinije grane na određenom intervalu i grane koju posmatramo. To je dovoljno ograničava, jer znamo da po tranzitivnosti onda neće se javiti pre nijedne grane na putu.

Sada možemo raditi topološko sortiranje kao u prethodnom podzadatku, samo što ovaj put imamo mnogo manje grana. Takođe, možemo primetiti da je moguće i raditi leksikografsko spajanje $K$ nizova kao u drugom zadatku.

Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.

## Rešenje kada $N, M \leq 5000$
Slično podzadatku u kome je MST put, samo kako bismo našli grane usmerenog grafa, potrebno je da prođemo kroz put na MST, umesto kroz interval niza. Ovo možemo uraditi tako što korenujemo stablo u nekom čvoru, pa pamtimo roditelja za svaki čvor.

Vremenska složenost: $O(M^2\log M$), a memorijski $O(M^2)$.

## Glavno rešenje
Slično podzadatku u kome je MST put, samo kako bismo našli grane usmerenog grafa, potrebno je da efikasno nađemo najmanju granu na putu MST, umesto na intervalu niza. Ovo možemo uraditi preko tehnike binarnog podizanja (*binary lifting*). Korenujemo MST u proizvoljnom čvoru, nađemo pretka svakog čvora (za pretka korena stavimo samog sebe). Nakon toga, za svaki čvor i za svako $l$ od $0$ do $\log N$ pamtimo najmanju granu ako se $2^l$ grana penjemo na gore. To nam može pomoći da u $O(\log N)$ nađemo minimum na bilo kom putu (slično algoritmu traženja minimalnog zajedničkog pretka).

Vremenska složenost je $O(MlogN)$, a memorijska $O(M)$.
