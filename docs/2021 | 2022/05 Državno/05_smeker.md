# A2 - Šmeker

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |

## Rešenje kada $N, M \leq 500$

U ovom slučaju, kao rešenje možemo da za svako dete samo izbrojimo koliko postoji dece u svakom od $4$ kvadranta. Za ovo naprosto iteriramo kroz svu decu posle svakog dodavanja, i sa par provera uslova nađemo šmekera. Složenost $O(N^3)$

## Rešenje kada tačke imaju iste $x$ i $y$ koordinate

U ovom slučaju, možemo da vidimo da je drugi uslov trivijalno ispunjen, pa samo treba da nađemo dete za koje važi da ima jednako dece gore desno i dole levo. Ovo je ekvivalentno sa time da ako posmatramo da su deca na pravoj, tražimo onog čija je pozicija medijana niza. Stoga nam je potrebna neka struktura koja nam omogućava održavanje medijane niza u kojem dodajemo nove elemente. Ovo može da se uradi nekim jakim strukturama kao `ordered statistic set`, ali najelementarnije rešenje bi bilo da održavamo dve `heap` strukture, jedan gde se čuva najvećih i drugi gde se čuva najmanjih pola elemenata. Kada dodajemo jedan element u niz, ubacimo ga u neki od njih, i onda najviše jednim prebacivanjem možemo da održimo traženu strukturu.

## Rešenje kada $N\leq 4000$

Primetimo da je uslov da je neko dete šmeker ekvivalentan sa time da je njegova $x$-koordinata medijana po svim $x$-koordinatama, i njegova $y$-koordinata medijana po svim $y$-koordinatama. Zaista, ako je gore levo $a_1$, gore desno $a_2$, dole desno $a_3$ i dole levo $a_4$ dece, uslov za medijane je $a_1+a_2=a_3+a_4$ i $a_1+a_4=a_2+a_3$, pa sabiranjem imamo $2a_1+a_2+a_4=a_2+2a_3+a_4\iff a_1=a_3$, iz čega zaključujemo i $a_2=a_4$, pa dete koje je po obe koordinate medijana je zaista šmeker. Obratno, ako je $a_1=a_3$ i $a_2=a_4$, uslovi $a_1+a_2=a_3+a_4$ i $a_1+a_4=a_2+a_3$ su trivijalno ispunjeni, pa smo dokazali traženu ekvivalenciju. 

Sada imamo vrlo lako rešenje u $O(N^2logN)$ tako što posle svakog dodavanja po obe koordinate nađemo medijanu u $O(NlogN)$, i u zavisnosti od toga jel pripada istom detetu smo našli šmekera ili našli da šmeker ne postoji.

## Glavno rešenje

Ovde je neophodno samo kombinovati ideje iz prethodna dva podzadatka. Kao u drugom podzadatku održavamo medijanu, ali zasebno za $x$- i za $y$-koordinatu u našoj omiljenoj strukturi. Onda posle svakog novog deteta, vidimo da li su deca koji odgovaraju tim medijanama jednaki. Ukupna složenost $O(NlogN)$.
