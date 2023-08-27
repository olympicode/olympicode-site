# 4 - Dugmići

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Aleksa Milojević | Momčilo Tošić | Momčilo Tošić |

## Rešenje kada $T_i \leq 6$, i $Z_i \leq 6$ za $X_i = 1$:
U ovom slučaju treba razmatrati jedino kratke segmente $[L,R]$, jer ukoliko je odgovor DA, moraćemo u jednom trenutku da odemo od krajnjeg levog do krajnjeg desnog dugmeta, što bi ugasilo početni tajmer ukoliko je $T_L < (R-L)$. Na ovim segmentima možemo da pokušamo da idemo levo-desno par puta, menjajući na svakom koraku sve tajmere u segmentu.

## Rešenje kada $N,Q \leq 2000$:
Uočimo da, ukoliko postoji rešenje, ćemo do svakog dugmeta morati u nekom trenutku da dođemo do levog, kao i do desnog kraja segmenta, i nazad. Dakle, za trajanje svakog tajmera u traženom segmentu mora da važi $T_i \geq 2(i-L)$ (dugme-levi kraj-dugme) i $T_i \geq 2(R-i)$ (analogno za desni kraj). Obilazak 'levo-desno' nam upravo garantuje da uspevamo čak i ako važi $T_i = 2(i-L)$ i $T_i = 2(R-i)$. Ove nejednakosti možemo ručno da proverimo za svako dugme u segmentu. 

## Rešenje kada $X_i = 2$
Činjenica da nema promena u nizu implicira offline rešenje. Naime, potrebno je naći odgovore za sve segmente $[L,R]$ prolaskom kroz niz jednom. Primetimo da ako važi nejednakost $T_i \geq 2(i-L)$, za neko $L$, ona važi i za sve manje $L$. Shodno tome, obilazimo sve dugmiće od $1$ ka $N$ i na svakom dodajemo u neku strukturu sve leve krajeve segmenata koji u njemu počinju, dok brišemo redom (od manjih ka većim) sve leve početke za koje ne važi $T_i \geq 2(i-L)$ (što postižemo tako što npr. u multiset držimo vrednosti $2L$ i poređujemo ih sa $2i-T_i$), a potvrđujemo mogućnost rešenja za neki segment kad dođemo do dugmeta koje predstavlja njegov desni kraj. Ovo je potrebno uraditi i u drugom smeru (od kraja ka početku).

## Rešenje za pun broj poena
Kako u svim dugmićima segmenta treba da važi $T_i \geq 2(i-L), T_i \geq 2(R-i)$ (što je ekvivalentno sa $2L \geq 2i-T_i, 2R \leq T_i+2i$), to znači da nam je potreban način da odredimo da li postoji vrednost $2i-T_i \leq 2L$ i $2i+T_i \geq 2R$ za $i$ u segmentu $[L, R]$ (vrednost za koje ne važi nejednakost), kao i da promenimo vrednost na nekoj poziciji. Ovo nam omogućavaju dva segmentna stabla, gde čuvamo vrednosti $2i+T_i$ i $2i-T_i$ i poređujemo maksimum, odnosno minimum na traženim segmentima sa $2R$ i $2L$. 
