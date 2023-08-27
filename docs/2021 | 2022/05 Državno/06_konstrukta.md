# A3 - Konstrukta

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Aleksa Plavšić | Aleksa Plavšić | Aleksa Milisavljević | Aleksa Plavšić |

Zadatak možemo modelovati kao neusmereno stablo, gde čvorovi predstavljaju države, dok grane predstavljaju autobuske linije.

## Prvi podzadatak

Uvek možemo postići da najudaljeniji čvor bude na udaljenosti $D = \frac{N}{4} + 1$. Ako čvorove na putu indeksiramo sa $x_1, x_2, \dots, x_N$ postavićemo granu između čvorova $x_{D + 1}$ i $x_{N - D + 1}$ i Evroviziju ćemo održati u prvom od njih. Lako se može pokazati da ne možemo postići bolje rešenje za graf koji je put. Potrebno je biti pažljiv za puteve dužine $4$ i $5$.

## Drugi podzadatak

Fiksiraćemo čvorove između kojih ćemo dodati granu ($O(N^2)$ mogućnosti) i fiksiraćemo čvor u kome će biti održana Evrovizija ($O(N)$ mogućnosti). Potrebno je naći najkraći put od čvora u kome će biti održana Evrovizija do ostalih čvorova, što možemo uraditi algoritmom pretrage u širinu (BFS). Možemo iskoristiti i određene modifikacije pretrage u dubinu (DFS), pošto graf sadrži tačno jedan ciklus. Vremenska složenost ovog algoritma iznosi $O(N^4)$, dok memorijska iznosi $O(N)$ ili $O(N^2)$ zavisno od reprezentacije grafa.

## Treći podzatak

**Obzervacija 1**: Evroviziju uvek treba održati u jednom od krajeva grane koje dodajemo. Ovo ne povlači da u nekim drugim čvorovima ne možemo održati Evroviziju, već da je jedan od krajeva grane uvek među optimalnim izborima. Primetimo da specijalan slučaj predstavljaju grafovi koji imaju dijametar (najduži put) dužine 2, u tom slučaju dodavanje nove grane ne poboljšava rešenje.

Ovo nam pruža podlogu za algoritam vremenske složenosti $O(N^3)$, pošto za fiksnu granu treba da proverimo samo dve mogućnosti za mesto održavanja Evrovizije. U slučaju da je dijametar dužine $2$, možemo ispisati bilo koju granu. 

## Kompletno rešenje

**Obzervacija 2**: Grana koju dodajemo uvek će povezivati dva čvora na dijametru stabla (ako imamo više dijametara, možemo izabrati proizvoljan).

Neka niz čvorova $x_1, x_2, \dots, x_d$ predstavlja dijametar stabla. Primetimo da je maksimalna udaljenost nekog od čvorova binarno pretraživa i da ne može iznositi više od $\frac{d}{2}$ (ako se Evrovizija održava u čvoru $x_{\frac{d + 1}{2}}$). Pretpostavimo da trenutno proveravamo u binarnoj pretrazi da li može maksimalna udaljenost biti manja ili jednaka od $c$. U tom slučaju optimalno je postaviti granu između čvorova $x_{c + 1}$ i $x_{d - c + 1} i održati Evroviziju u prvom od njih ili između čvorova $x_c$ i $x_{d - c}$ i održati Evroviziju u drugom od njih. Kada znamo između koja dva čvora ćemo postaviti granu i da jedan od njih mora biti mesto održavanja Evrovizije, ostalo je samo proveriti da li neki od njih zadovoljava uslov da nakon postavljanja grane svi ostali čvorovi budu udaljeni ne više od $c$. To možemo ponovo uraditi nekim od algoritama za pronalazak najkraćeg puta u grafu. Ukupna vremenska složenost $O(N log N)$ i memorijska $O(N)$.

Bonus: Rešite zadatak u vremenskoj složenosti $O(N)$.
