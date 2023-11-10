# B2 - Štale

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Momčilo Tošić | Momčilo Tošić | Vladimir Milovanović | Andrej Ivašković |

Prema postavci zadatka, konj se, iz proizvoljne tačke, može kretati horizontalno, vertikalno, kao i (anti-)dijagonalno. Dodatno ograničenje je da se konj, polazeći iz neke tačke, isključivo kreće po dvodimenzionalnoj rešetki puteva, odnosno mreži tačaka koje su međusobno udaljene $s$ jedna od druge. Nije teško uvideti da iz određene tačke u kojoj se trenutno nalazi, konj može proći kroz bilo koju drugu tačku koja se nalazi na pomenutoj rešetki puteva.

## Kvadratno rešenje za 65 poena

Dovoljno je u dve ugnežđene petlje proći po svim štalama i ispitati da li je moguće doći od jedne do druge, računajući da se od $i$-te do $j$-te štale (naravno, samo za indekse $i \neq j$) može doći ako im se poklapaju horizontalne ($x$) ili vertikalne ($y$) koordinate ili se pak poklapa razlika ili zbir vertikalnih i horizonalnih koordinata (to jest nalaze se dijagonalno/antidijagonalno jedna od druge), pri čemu se 4 pomenutih jednakosti (jednake vrednosti $x$, $y$, $x-y$, $x+y$) računaju po modulu $c$ uz uslov da moduo bude pozitivan. Kako se u svakoj od dve petlje prolazi kroz sve štale i čuva maksimum, ovo rešenje ima kvadratnu vremensku složenost, odnosno $\mathcal{O}(n^2)$, gde $n$ predstavlja broj štala.

## Glavno rešenje u linearnoj složenosti

Da bi se zadatak uradio na efikasan način, svrsishodno je makar prividno preslikati dvodimenzionalnu ravan $(x, y)$ na matricu dimenzija $c \times s$. Preslikavanje se vrši tako što se polje u $i$-toj vrsti i $j$-oj koloni pomenute matrice popunjava sa onoliko štala koliko ih se nalazi na koordinatama $x \mod c = i$ i $y \mod c = j$. Sve što je tada potrebno učiniti jeste pronaći polje u matrici sa najvećim zbirom ostalih elemenata koji se nalaze u istoj vrsti i koloni, kao i na istoj dijagonali i antidijagonali, tačnije sam zbir pomenutih elemenata sa trenutnim poljem koji zapravo predstavlja traženo rešenje zadatka. Prilikom prolaska kroz matricu treba biti pažljiv i obratiti pažnju da se samo polje kroz koje se prolazi ne uračuna više puta, kao i to da se, za parno $c$, polja na (produženoj) dijagonali i antidijagonali mogu poklapati, odnosno da se (produžene) dijagonale mogu seći. Kako je sama operacija preslikavanja ravni na matricu linearna po $n$, to jest $\mathcal{O}(n)$, a prolazak kroz matricu u opštem slučaju kvadratan po njenim dimenzijama, preciznije $\mathcal{O}(c^2)$, jasno je iz postavke zadatka u kojoj se kaže da je $n\leq200'000$, a $c\leq100$, pa je $n>c^2$, prvi član dominantan, te je i ukupna vremenska složenost rešenja, pod ovakvim pretpostavkama, linearna po broju štala.

## Alternativno rešenje

Kako je uslov da se iz tačke $(x_1,y_1)$ tačka $(x_2, y_2)$ može obići: $x_1 = x_2 \lor y_1 = y_2 \lor x_1-y_1 = x_2-y_2 \lor x_1+y_1 = x_2+y_2$, gde je jednakost po modulu $c$, to možemo za svaku tačku tražiti broj tačaka za koji važi ovaj uslov kao broj elemenata unije 4 skupa (skup svih sa određenom $x$ ili $y$ koordinatom, ili određenom razlikom/zbirom dveju koordinata). Ovo se može rešiti formulom uključenja-isključenja za 4 skupa, gde veličine preseka brojimo višedimenzionalnim matricama (ukupna memorijska složenost je $\mathcal{O}(c^4)$, što je u praksi i dosta manje od $512$ MB, dok je vremenska linearna jer svaku štalu ubacujemo u konstantan broj skupova koji služe za prebrojavanje).
