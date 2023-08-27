# A3 - Turizam

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Jovan Bengin | Jovan Bengin | Jovan Bengin | Igor Pavlović |

## Analiza
Prvo, primetimo da ćemo uvek posetiti neki podniz koji sadrži početno polje $x$. Ako je podniz koji posetimo $[L, R]$, NR na kraju će biti $A_L \ \text{and} \ A_{L+1} \ \text{and} \ \ldots{} \ \text{and} \ A_R$ (zapisaćemo kao $f(L, R)$), a minimalan broj koraka da se poseti je $R - L + min(x - L, R - x)$ (tako što iz početka odemo do leve granice, pa do desne, ili obrnuto).

## Rešenje prvog podzadatka

U ovom podzadatku možemo iterirati kroz svaku moguću levu i desnu granicu, i ukupnu $\text{and}$ vrednost računati jednim prolaskom kroz podniz.

Ukupna složenost: ${\mathcal O}(QN^3)$

## Rešenje drugog podzadatka
 
 Isto ćemo iterirati kroz svaku moguću levu i desnu granicu, ali ćemo čuvati vrednosti $f(L, x)$ i $f(x, R)$ i ažurirati ih tokom iteracija. Sada ne moramo da iteriramo kroz ceo podniz da bismo našli $f(L, R)$, već ga dobijemo iz sačuvane dve vrednosti.
 
 Ukupna složenost: ${\mathcal O}(QN^2)$

## Rešenje trećeg podzadatka
Za naredne podzadatke potrebna nam je još jedna ključna opservacija: optimalni podniz će uvek imati levu i desnu granicu u poljima gde se ukupan NR menja, tj. u $L$ i $R$ takvim da važi $f(L, x) \neq f(L + 1, x)$ (ili $L = x$) i $f(x, R) \neq f(x, R - 1)$ (ili $R = x$). Ovo je tačno jer, ako je na granici polje koje ne menja NR, možemo ga samo izbaciti iz podniza.

U ovom podzadatku je, dakle, moguće samo nekoliko slučajeva: da direktno idemo iz $x$ u najbližu nulu, da idemo iz $x$ do najbliže leve jedinice i do najbliže desne dvojke (ili obrnuto), ili da, ako su željena jedinica i dvojka sa iste strane, odemo iz $x$ do dalje od njih.

Pozicije najbliže leve i desne nule, jedinice i dvojke možemo naći preko strukture *std::set* i njene funkcije *upper_bound*.

Ukupna složenost: ${\mathcal O}(QlogN)$

## Rešenje četvrtog podzadatka

Pozicije koje menjaju NR su zapravo one za koje važi da postoji neki bit koji se ne nalazi u njenom elementu, ali se nalazi u elementima na svim pozicijama od nje do $x$.

Za svaki bit možemo jednim prolaskom kroz niz naći najbližu levu i desnu poziciju čiji element ne sadrži taj bit, neka su za $i$-ti bi te dve pozicije $l_i$ i $r_i$, a naš interval mora da sadrži ili jednu ili drugu. Drugim rečima, uslov možemo da formulišemo kao: ako je leva granica veća od $l_i$, onda je desna granica veća jednaka $r_i$.
Zato možemo da iteriramo kroz sortiran niz potencijalnih levih granica (kojih ima $log(A_i)$) i da održavamo trenutnu minimalnu desnu granicu, i tako nalazimo minimalno rešenje.

Složenost ovog algoritma je  ${\mathcal O}(QNlog(A_i))$, što bi uz pokoju optimizaciju prošlo. Međutim, nalaženje levih i desnih granica može da se uradi u ${\mathcal O}(N + log(A_i))$ umesto ${\mathcal O}(Nlog(A_i))$, tako što počnemo iz $x$ i krećemo se levo ili desno (u zavisnosti od toga koju granicu nalazimo), čuvajući trenutnu $\text{and}$ vrednost tog intervala. Kada se ta vrednost promeni, iteriramo kroz one bitove gde se promenila i za njih određujemo da im je granica na toj poziciji.

Ukupna složenost: ${\mathcal O}(Q(N + log(A_i)))$

## Rešenje petog podzadatka

U ovom podzadatku ćemo brže nalaziti pozicije nula: za svaki bit čuvamo niz pozicija čiji elementi nemaju taj bit. Sada možemo binarnom pretragom da brzo nađemo željene elemente.

Ukupna složenost: ${\mathcal O}(Qlog(N)log(A_i))$

## Glavno rešenje

Glavno rešenje se radi na isti način kao peti podzadatak, samo što se umesto niza pozicija koristi struktura *std::set*, koja se lako može ažurirati u slučaju događaja prvog tipa.

Ukupna složenost: ${\mathcal O}(Qlog(N)log(A_i))$