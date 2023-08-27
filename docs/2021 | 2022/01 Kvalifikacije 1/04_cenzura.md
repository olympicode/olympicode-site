# 4 - Cen*ura

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović  | Pavle Martinović  | Aleksa Plavšić |

## Zabranjena reč je 'a'
U ovom podzadatku je očito dovoljno samo cenzurisati sva pojavljivanja slova 'a', što možemo da uradimo tako što linearno prođemo kroz $T$ i nađemo svuda gde se pojavljuje to slovo, zamenimo sa *, i izbrojimo koliko se puta pojavio.

##  Sva slova zabranjene reči su 'a'
Isto je rešenje kao u prethodnom podzadatku, samo preskočimo prvih $M-1$ pojavljivanja slova 'a'.

## Da li je jedna reč podsekvenca druge?
Da bismo umeli da pristupimo ovom problemu potrebno je analizirati algoritam kako proveravamo da li je jedna reč podsekvenca druge. 
Ovo se vrši pohlepnim algoritmom. Naime, neka proveravamo da li je reč $S$ podsekvenca reči $T$. Onda prolazimo linearno kroz reč $T$ dok pamtimo najduži prefiks $S$ koji nam se pojavljuje do sad kao podsekvenca.  Sada, kada sledeći put naiđemo na sledeće slovo koje bi nam trebalo da bismo povećali dužinu tog najvećeg prefiksa (to jest sledeće slovo u $S$), znamo da nam je optimalno da  ga iskoristimo u konstrukiciji $S$ kao podsekvence. To znači da u tom slučaju možemo da povećamo dužinu tog najdužeg prefiksa, dok on u suprotnom ostaje isti. Na kraju vidimo da li je najduži prefiks $S$ koji je podsekvenca $T$ upravo ceo $S$ u tom slučaju je odgovor "DA", a u suprotnom "NE".

## Glavno rešenje
Sada kada smo proučili taj algoritam, možemo da rešimo ceo zadatak.
Rešenje ćemo vršiti dinamičkim programiranjem, najsličnije DP rešenju za najdužu zajedničku podsekvencu dve niske. Naime neka je $DP[n][k]$ vrednost "koliko najmanje karaktera treba cenzurisati u prvih $n$ slova $T$ da bi najduži prefiks $S$ koji je podsekvenca tih prvih $n$ karaktera dužine tačno $k$". Sada ove vrednosti u dinamičkom programiranju se lako računaju: ako ne želimo da povećamo vrednost $k$, onda kad naiđemo na slovo koje bi nam ga povećalo, moramo da cenzurišemo, a u suprotnom samo povećamo vrednost $k$. Kako stanja ima $MN$ i svako ima konstantno prelaza, dobijamo ukupno vremensku i memorijsku složenost $O(MN)$. 