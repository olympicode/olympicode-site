## Glavno rešenje
Nije teško uočiti da na osnovu rezultata $a:b$ na kraju utakmice, kao i rezultata $x:y$ na poluvremenu, postoji četiri različita slučaja:

- $x = a$ i $y = b$, odnosno da je rezultat na kraju jednak rezultatu na poluvremenu, pa u nastavku neće biti golova;
- $x < a$ i $y < b$, što dalje znači da će obe ekipe postići gol, pa na osnovu rezultata nije moguće utvrditi koja će ekipa zabiti naredni;
- $x < a$ i $y = b$, što implicira da će prva ekipa postići naredni gol;
- $x = a$ i $y < b$, što znači da će druga ekipa postići naredni gol.

Jednostavnim postavljanjem ova četiri uslova i odgovarajućim ispisima dolazi se do traženog rešenja u konstantnoj vremenskoj složenosti $\mathcal{O}(1)$.
