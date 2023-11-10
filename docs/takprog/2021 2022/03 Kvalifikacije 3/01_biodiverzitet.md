# 1 - Biodiverzitet

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Tadija Šebez | Aleksa Milojević | Vladimir Milovanović | Vladimir Milovanović |

## Glavno rešenje
Kako je cilj odrediti broj različitih bioloških predaka vrsta koje trenutno žive, a budući da su u zadatku dati indeksi vrsta koje trenutno žive, najpre je potrebno pristupiti izračunavanju indeksa bioloških predaka. To se čini tako što se indeks vrste $i$ celobrojno podeli sa $K$ i to za sve indekse $i_1, i_2, \ldots, i_N$ u zadatom nizu. Time se dobija novi niz koji zapravo predstavlja niz bioloških predaka. Treba primetiti da se u opštem slučaju vrednosti unutar niza biloških predaka mogu ponavljati. Najzad da bi se odredio broj različitih predaka potrebno je prebrojati jedinstvene članove niza koji sadrži i duplikate. Postoji više načina na koji je moguće izračunati broj jedinstvenih članova niza, a jedan od njih je da se članovi niza bioloških predaka sortiraju i onda u jednom prolazu kroz niz izbroje različite vrednosti.

U rešenju, pored operacija prolaza kroz niz u kojima se izvršava celobrojno deljenje ili prebrajanje jedinstvenih članova, a koje su linearne složenosti $\mathcal{O}(N)$, takođe imamo i operaciju sortiranja koja je dominantne složenosti. Koristeći se efikasnim algoritmima niz je moguće sortirati u loglinearnoj vremenskoj složenosti $\mathcal{O}(N\log N)$, iako je za maksimalan broj poena to bilo dovoljno učiniti i u kvadratnoj, odnosno $\mathcal{O}(N^2)$ složenosti.
