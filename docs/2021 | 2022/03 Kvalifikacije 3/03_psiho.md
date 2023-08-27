# 3 - Psiho

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Mladen Puzić | Mladen Puzić | Mladen Puzić | Igor Pavlović |

## Rešenje za $N, M \leq 1000$
Ovde je moguće primeniti razna sporija rešenja, npr. možemo održavati skup *aktivnih* vizit karti, odnosno onih koje nisu još odbačene ili sačuvane od strane direktora. Svakog trenutka, sve aktivne vizit karte šaljemo nadređenom i onda simuliramo poređenje vizit karti. Vremenska složenost: $O(N\cdot M)$, memorijska složenost: $O(N+M)$.

## Rešenje za $p_i = i-1$
U ovom slučaju hijerarhija kompanije je linearna, tj. samo put od svakog zaposlenog do direktora. Najbitnija obzervacija u ovom zadatku jeste da možemo ignorisati sva susretanja vizit karti pre direktora. Ako su se dve karte susrele pre direktora, zajedno će i stići kod direktora, gde će se svakako porediti i odbaciti.

Ovo nam govori da je dovoljno da za svaki trenutak odredimo koliko vizit karti stiže kod direktora tad. Karta koja se pojavila u trenutku $t_i$ kod osobe $p_i$ će kod direktora stići u trenutku $t_i+p_i-1$, pa koristeći npr. strukturu *map* ili obično sortiranje, odrediti sve što nam je potrebno da izračunamo koliko karata će biti odbačeno (ukoliko u trenutku $t$ stiže $x$ karata kod direktora, tada on odbacuje $\lfloor \frac{x}{2} \rfloor \cdot 2$ vizit karti. Vremenska složenost: $O(N+MlogM)$, memorijska složenost: $O(N+M)$. 

## Rešenje za $t_i = 1$
Rešenje je slično glavnom rešenju, samo što je moguće izbeći mapu/sortiranje, i lakše je primetiti pogrebu za dubinama zaposlenih.

## Glavno rešenje:
Poput rešenja kada $p_i = i-1$, ignorišemo poređenja sem kod direktora. Jedina razlika je što ovaj put moramo drugačije da izračunamo u kom trenutku će se neka karta naći kod direktora. Potrebno je da izračunamo *dubinu* svakog zaposlenog, odnosno koliko je sekundi potrebno da vizit karta od osobe $i$ stigne do direktora (označimo to sa $d_i$). 

Za ovo je moguće koristiti grafovske algoritme, ali pošto važi $p_i < i$ to nije neophodno. Dovoljno je da to uradimo koristeći sledeće formule: $d_1 = 0$
 i $d_i = d_{p_i} + 1$. Kada to izračunamo, vreme kada će neka karta doći do direktora je $t_i + d_{v_i}$. Vremenska složenost: $O(N+MlogM)$, memorijska složenost: $O(N+M)$.

