# 5 - Zlatnici 3

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Marko Šišović | Pavle Martinović | Pavle Martinović |

##  Rešenje u $O(QN^2)$
Pokušajmo da pronađemo za svaki čvor $u$ koliko treba poteza da bismo sve zlatnike preneli u njega. Ovo je suma $\sum_{i=1}^nd(u,i)\cdot w_i$, gde $w_i$ broj zlatnika u $i$, a $d(u,v)$ dužina puta između čvorova $u$ i $v$. Ovo se lako može izračunati puštanjem DFS iz svakog čvora.

##  Rešenje u $O(QN)$
Potrebno je da malo dublje analiziramo koji čvor će biti odgovor. Neka sa $V_v$ označavamo broj poteza koji je potreban da bi svi zlatnici stigli u čvor $v$. Potrebno je naći čvor tako da je $V_u=\sum_{i=1}^nd(u,i)\cdot w_i$ minimalno. Posmatrajmo vrednost $V_u-V_v$ za neku granu $uv$. Iz gorenavedene formule vidimo da je ovo zapravo jednako razlici suma težina u dva stabla koja dobijemo kada isečemo granu $uv$ (uverite se!). Kada smo u optimalnom čvoru, ova vrednost treba da bude negativna za sve grane, što je ekvivalentno sa tim da kad isečemo taj čvor, u svakom od dobijenih stabala je najviše pola od ukupne težine (ovakav čvor se zove centroidom stabla). Sada lako se vidi da je ovakav čvor jedinstven, ili ih je dva koja su spojena granom sa razlikom renjenja od $0$ (a u tom slulaju su oba validno rešenje). Stoga, sveli smo zadatak na traženje šta je centroid u ovom stablu, što može da se uradi DFS i čuvaju se veličine svih podstabala, a zatim se uradi jednostavna provera.

## Rešenje kada je stablo put
U ovom slučaju je rešenje ternarno pretraživo po putu, i sve dist funkcije se mogu izračunati lako. Moguće je uraditi tad u zadatak $O(N\log N + Q\log^2 N)$, za jednu tačku pretrage u ternarnoj nam treba samo sume po prefiksima i sufiksima, a promeni tih možemo da pratimo u segmentnom stablu. 

## Rešenje kada je stablo kompletno binarno
Nastavljamo na rešenje iz drugog podzadatka. Ono što treba primetiti je da je vrednost $V_v-V_u$ moguće izračunati brzo za neku granu. Zaista ako smestimo čvorove u niz po ulaznom ili izlaznom poretku DFS, i imamo segmentno stablo nad tim nizom, pošto će svi čvorovi u nekom stablu formirati interval. Nama je potrebna samo težina u dva stabla koja dobihemo kad isečemo ovu granu, a jedno od tih stabala će morati da bude podtablo ukorenjenog stabla. Težinu u drugom možemo izračunati kao ukupna težina minus to što smo izračunali. Stoga, promenu rezultata prolaskom iz jednog čvora u drugi, (to jest da li je bolje ako pređemo) možemo izračunati u $O(\log N)$.

Sada kad dodamo novi čvor, novo rešenje će se nalaziti na putu od trenutnog rešenja do tog novog na koji smo dodali zlatnike. Stoga, na tom putu će promene rezultata biti pozitivne, pa negativne. Da bismo rešili zadatak potrebno je samo iterirati kroz put i naći sve grane kroz koje kad prođemo poboljšavamo rezultat. Pošto su na ovom stablu svi putevi kratki, nalazimo rešenje u $O(N\log N + Q\log^2 N)$.

## Glavno rešenje
Konačno rešenje je mala nadogradnja prethodnog. Naime, umesto da idemo redom po putu između starog i novog čvora, uraidmo binarnu pretragu na tom putu da bismo pronašli poslednju granu koja nam daje pozitivan skor na rezultat. Po svemu opisanom u prethodnom podzadatku, ovo će zaista biti binarno pretraživo i stoga će ovo rešenje raditi u $O(N\log N + Q\log^2 N)$.
