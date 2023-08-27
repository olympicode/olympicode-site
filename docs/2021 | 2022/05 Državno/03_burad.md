# B3 - Burad

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Mladen Puzić | Mladen Puzić | Mladen Puzić | Aleksa Plavšić |

## Rešenje kada $l_i = r_i$
Pošto će kiša svakog dana padati nad tačno jednim buretom, možemo svako bure gledati zasebno. Izbrojaćemo koliko litara je prognozirano da upadne u $i$-to bure, nazovimo taj broj $cnt_i$. Ukoliko $cnt_i > a_i$, znači da dolazi do prelivanja i moramo prekriti buriće $cnt_i - a_i$ dana. Uradimo to za svako $i$ i sumirajmo kako bismo dobili krajnje rešenje. Vremenska složenost je $O(N+M)$, a memorijska $O(N)$.

## Rešenje kada u svako bure pada najviše jedan litar kiše
Jedina mesta na kojima može doći do prelivanja jesu burad sa kapacitetom $0$, a pošto su svi intervali disjunktni, to znači da je ukupna dužina svih intervala do $N$, pa je dovoljno efikasno da za svaki dan prođemo kroz sve buriće u koje bi upala kiša i proverimo da li neki od njih ima kapacitet $0$. Vremenska složenost $O(N+M)$, a memorijska $O(N)$.

## Rešenje kada $a_i \in \{0, 10^9\}$
Jedina mesta na kojima može doći do prelivanja jesu burad sa kapacitetom $0$, u koje ne sme upasti ni litar kiše. Zato, Marko mora prekriti sve buriće na dane kada bi u makar jedno bure kapaciteta $0$ upala kiša, što je ekvivalentno sa proverom da li u intervalu nizu postoji $0$. Ovo možemo proveriti npr. binarnom pretragom nad indeksima gde se pojavljuje $0$ ili prefiksnim sumama kojim brojimo nule na prefiksu. Vremenska složenost $O(N+M)$ ili $O(N+MlogN)$, a memorijska $O(N)$.

## Rešenje kada $N, M \leq 2000$
Prvo je potrebno da odredimo koliko litara kiše je prognozirano za svako bure. To možemo jednostavno uraditi tako što za svaki dan prolazimo kroz sve buriće i uvećamo broj litara za jedan. Nazovimo taj broj litara za $i$-to bure $cnt_i$. Sada je potrebno da posmatramo isključivo buriće za koje važi $cnt_i > a_i$, odnosno one koji bi se prelili kada ništa ne bismo učinili. 

Sada, idemo sleva nadesno i svaki put kada naiđemo na takvo bure, znamo da moramo da pokrijemo buriće na makar $cnt_i - a_i$ novih dana. Čuvajmo u nekom nizu sve dane za koje nismo odredili da li ćemo prekriti buriće taj dan (zvaćemo ih *neobrisani intervali*). Kad god moramo da obrišemo novi interval, obrisaćemo onaj interval koji sadrži $i$, a proseže se što je moguće dalje u desno. Ovo je optimalno, jer su tako najveće šanse da ćemo tim brisanjem smanjiti $cnt_j$ drugih *kritičnih* burića. Kada odaberemo takav interval, brišemo ga iz niza, i smanjujemo odgovarajuće elemente $cnt$ niza. Nastavljamo desno dok ne obradimo ceo niz. 

Vremenska složenost je $O(NM)$, a memorijska $O(N+M)$.

## Glavno rešenje
Ideja iza ovog rešenja ista je kao za prethodno, samo je potrebno da sve uradimo efikasnije. Prvi deo, pronalaženje niza $cnt_i$, uradićemo konstrukcijom novog niza, $b$. Na početku, on će biti ispunjen nulama. Za svaki dan $i$, mi ćemo povećati $b_{l_i}$ za jedan, a smanjiti $b_{r_i+1}$ isto za jedan. Niz $cnt$ dobijamo kao niz prefiksnih suma nad nizom $b$.

Drugi deo ćemo raditi slično kao u prethodnom rešenju, samo što ćemo umesto niza neobrisanih intervala, čuvaćemo skup (*std::multiset*), sortiran po desnom kraju intervala. Čuvaćemo samo one intervale koji sadrže trenutni element, dakle dodaćemo interval $j$ tek kad važi $l_j = i$, a izbaciti tek kad je obrisan ili kada $r_j = i$. Svaki put kada treba da obrišemo interval, obrisaćemo najveći u skupu. Slično se može uraditi i sa prioritetnim redom (*std::priority_queue*), sa malo dodatne analize.

Vremenska složenost je $O(N+MlogN)$, a memorijska $O(N+M)$.
