# 1 - Laž

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Tadija Šebez | Pavle Martinović | Mladen Puzić |

## Rešenje kada $q = 2000$
Ovaj podzadatak je tu za takmičare koji na neoptimalan način iskucaju rešenje iz sledećeg podzadatka.

## Rešenje kada $q = 1000$
Možemo da saznamo da li je neko lažov ili istinoljubac sa samo jednim pitanjem. Ako osoba $x$ pitamo za skup $\{x, y\}$, gde je $y$ bilo koja druga osoba, saznaćemo da li je $y$ lažov ili istinoljubac (samo ukoliko kaže da u njemu ima neparno lažova, onda je osoba $y$ lažov). Ovo znamo, jer ako osoba $x$ govori istinu, onda odgovor zavisi samo od toga da li je $y$ lažov. Ako laže, i ako su obojica lažovi, $x$ će još uvek reći da je neparno lažova. U suprotnom, reći će da ima neparno lažova.

Sad možemo proći kroz niz i za svaku osobu saznati da li je istinoljubac ili lažov sa po jednim pitanjem.

## Rešenje kada $q = 30$ i postoji tačno jedan lažov

Koristeći ideju iz prethodnog podzadatka, odredimo da li je osoba $1$ istinoljubac ili lažov. Ukoliko je lažov, možemo vratiti njegov indeks, u suprotnom, možemo ga koristiti da saznamo informacije o ostalim ljudima.

Ako je istinoljubac, onda je lažov neka od osoba na intervalu $[2, N]$. Podelimo ovaj interval na pola. Lažov se mora nalaziti u jednoj od te dve polovine. Pitajmo osobu $1$ da li je lažov u prvoj polovini. Ukoliko jeste, dalje razmatramo samo nju, u suprotnom, razmatramo samo drugu polovinu.

Ovom metodom nalik na binarnu pretragu, možemo naći lažova sa još desetak pitanja.

## Rešenje kada $q = 30$ i postoji neparno lažova
Slično prethodnom podzadatku, prvo nalazimo informaciju o osobi $1$. Nakon toga, ponovo radimo binarnu pretragu na intervalu $[2, N]$. Ovaj put, umesto da održavamo samo jednog lažova, želimo da interval koji posmatramo uvek ima neparan broj lažova. Kada podelimo interval koji ima neparan broj lažova na dve polovine, jedna polovina imaće paran broj lažova, a druga neparan. Pretragu nastavljamo u onoj polovini koja ima neparan broj. Tako radimo dok ne dođemo do jednog lažova.

## Glavno rešenje
Poslednji podzadatak rešavamo kao prethodni, samo što je prvo potrebno da nađemo neki podskup ljudi u kojem ima neparno lažova. To možemo uraditi nasumičnim (randomiziranim) pristupom. 

Svaki element ubacujemo u naš podskup sa verovatnoćom $50\%$. Samim tim, verovatnoća da će taj podskup imati neparno lažova je takođe $50\%$. Ukoliko podskup koji smo dobili ima parno mnogo lažova, onda konstruišemo novi podskup, dok ne dobijemo neki koji nam odgovara. 

Verovatnoća da će nam za to trebati preko $19$ pokušaja je jako mala, $\frac{1}{2^{19}}$, pa je možemo zanemariti. Ostala pitanja možemo iskoristiti na drugi deo rešenja, gde opet radimo nešto nalik na binarnu pretragu, samo ovaj put delimo skup na dva, umesto interval. 
