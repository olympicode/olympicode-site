# 5 - Noćna vožnja

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Mladen Puzić | Mladen Puzić i Pavle Martinović | Tadija Šebez | Tadija Šebez |

## Podzadatak kada je $N, Q \leq 4000$

Možemo da održavamo trenutni redosled naselja u nizu. Operacija zamene se svodi na jednostavno zamenjivanje dva člana niza, dok je odgovaranje na drugi tip događaja malo komplikovanije. Možemo da pustimo **DFS** ili **BFS** algoritam iz naselja $x$ kako bismo našli udaljenosti od istog do svakog drugog naselja. Nakon što smo našli i sačuvali udaljenosti možemo da prođemo kroz deo niza od $l$ do $r$ i nađemo najveću udaljenost. Vremenska složenost ovog rešenja je $O(QN)$.

## Podzadatak kada je svako naselje susedno sa najviše dva druga naselja

U ovom slučaju naselja zapravo formiraju lanac i možemo da ih poređamo u niz počevši od jednog kraja. Za svako naselje zapamtimo njegovu poziciju u ovom nizu. Kada tražimo najveću udaljenost od naselja $x$ do skupa naselja od $l$ do $r$ bitna su nam samo dva naselja iz tog skupa, naselje sa najmanjom i naselje sa najvećom pozicijom (udaljenošću od kraja lanca). Ovo možemo efikasno da implementiramo korišćenjem neke strukture podataka koja podržava upite za minimum/maksimum na podnizu i promenu člana niza. Na primer možemo da koristimo **segmentno stablo** i dobijemo vremensku složenost $O(N + QlogN)$.

## Podzadatak kada je u svakom događaju $x = 1$ i $p_a, p_b \neq 1$

Kako se u svakom pitanju traži najveća udaljenost od naselja 1, na početku pustimo **DFS** ili **BFS** algoritam iz ovog naselja i nađimo uzaljenosti do svakog drugog naselja. Čuvajmo niz gde je $i$-ti član udaljenost od naselja 1 do naselja $p_i$. Pitanja se svode na traženje maksimuma na podnizu ovog niza. Možemo i ovde da iskoristimo **segmentno stablo** za efikasne operacije traženja maksimuma i promene u nizu nakon događaja prvog tipa. Vremensa složenost je $O(N + QlogN)$.

## Rešenje bez dodatnih ograničenja

Slično kao kod rešenja za lanac za svako pitanje možemo da nađemo dva naselja od kojih će uvek jedno biti najdalje bez obzira na odabir naselja $x$. Za ovo rešenje treba nam malo teorije vezane za stabla. Prečnik stabla je najveća udaljenost između dva čvora, a krajevi prečnika su čvorovi koji su na toj najvećoj udaljenosti. Korisna osobina prečnika stabla je to da je najdalji čvor od proizvoljnog čvora uvek jedan od krajeva prečnika. Naselja koja ćemo tražiti su krajevi prečnika podstabla koje obuhvata naselja $p_l, p_{l+1}, \dots, p_r$. I u ovom rešenju možemo koristiti segmentno stablo. Za svaki segment čuvajmo krajeve prečnika, a prečnik za dva spojena segmenta tražimo tako što nađemo najveću udaljenost između 2 od 4 čvora koji su krajevi prečnika levog i desnog segmenta. Ostaje još da nađemo način kako efikasno da nađemo udaljenost između dva čvora. Možemo da postavimo čvor 1 kao koren i izračunamo dubinu svakog čvora $depth(x)$. Distanca između dva čvora $x$ i $y$ je $depth(x) + depth(y) - 2 depth(LCA(x, y))$, gde je $LCA(x, y)$ najmanji zajednički predak čvorova $x$ i $y$, odnosno čvor na kom se put od $x$ do korena i put od $y$ do korena sreću. Najmanji zajednički predak može se naći u $O(logN)$ sa **binary lifting** tehnikom ili u $O(1)$ sa **sparse tabelom** nad Ojlerovim putem. Preprocesiranje za obe opcije je vremenske i memorijeske složenosti $O(NlogN)$, a celo rešenje vermenske složenosti $O(NlogN + Q log^2 N)$ ili $O(NlogN + QlogN)$ u zavisnosti od odabrane tehnike.
