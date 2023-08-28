# 2 - Mlađioničar

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Andrej Ivašković | Dimitrije Erdeljan | Dragan Urošević | Andrej Ivašković |

Označimo sa $r$, $g$ i $b$, redom broj crvenih, zelenih i plavih kuglica. Tada će u najnepovoljnijem slučaju crvenu kuglici izvući nakon što izvuče sve zelene i plave. Slično će zelenu kuglicu izvući najkasnije nakon izvlačenja svih crvenih i plavih, a plavu nakon što izvuče sve crvene i zelene. Prema tome, važiće sledeće nejednakosti
$$
A \leq g+b+1,\quad B \leq r+b+1, \quad C \leq r+g+1.
$$
Pored toga je ukupan broj kuglica jednak $N$, pa važi:
$$
r+g+b = N.
$$

## Rešenje kad je $N \leq 200$

U ovom slučaju, možemo za sve moguće vrednosti brojeva $r$, $g$ i $b$ (a to su prirodni brojevi između $1$ i $N$), proveriti da li zadovoljavaju tri nejednakosti i poslednju jednakost i prekinuti proveravanje onog trenutka kada su zadovoljene. Ako pomenute nejednakosti i jednakost nisu zadovoljeni ni za jednu kombinaciju vrednosti $r$, $g$ i $b$, ne postoji raspored kuglica koji odgovara vrednostima $A$, $B$ i $C$. Očigledno je složenost ovog rešenja $O(N^3)$. 

## Rešenje kad je $N \leq 2000$

Primetimo da za fiksirane vrednosti broja crvenih ($r$) i zelenih ($g$) kuglica možemo odrediti broj plavih kuglica po formuli $b=N-r-g$. Zbog toga je dovoljno za sve kombinacije vrednosti brojeva $r$ i $g$ (a to su brojevi između $1$ i $N$), odrediti vrednost broja $b$, a nakon toga proveriti da li su zadovoljene tri nejednakosti. 
Složenost ovog rešenja $O(N^2)$.

## Glavno rešenje

Kako u vreći treba da bude bar jedna crvena, zelena i plava, brojeve kuglica možemo prikazati kao
$$
r = 1 + r1,\quad g = 1+g1, \quad b = 1+b1,\quad r1,g1,b1\geq 0.
$$
Tada vaši sledeće:

$$
r1+g1+b1 = (r-1) + (g-1) + (b-1) = (r+g+b)-3 = N-3 = N1.
$$

Pored toga, polazne nejednakosti postaju:
$$
A\leq g+b+1 = (1+b1)+(1+b1)+1 = g1+b1+3,
$$
odnosno
$$
g1+b1 \geq A-3,
$$
ili preciznije
$$
g1+b1 \geq \max(A-3,0) = A1.
$$
Slično se dobija
$$
r1+b1 \geq \max(B-3,0)=B1
$$
i
$$
r1+g1 \geq \max(C-3,0) = C1.
$$
Sabiranjem poslednje tri nejednakosti dobijamo
$$
2r1+2g1+2b1=2N1\geq A1+B1+C1,
$$
i ovo je potreban uslov da bi postojalo rešenje.

Pokazuje se da je to i dovoljan uslov. Da bi odredili rešenje, primetimo da iz uslova
$$
r1+g1+b1 = N1\quad\text{i}\quad g1+b1\geq A1,
$$
dobijamo
$$
r1 = N1-(g1+b1) \leq N1-A1 = r1_{max},
$$
i slično:
$$
g1 \leq N1-B1= g1_{max}\quad\text{i}\quad b1 \leq N1-C1=b1_{max}.
$$
Za brojeve $r1$, $g1$ i $b1$ biramo najveće koji zadovoljavaju nejednakosti i u zbiru daju broj $N1$.
Primetimo da se mogu odabrati brojevi $r1$, $g1$ i $b1$ tako da zadovoljavaju gornje nejednakosti i zbir bude $N1$ zato što je zbir gornjih ograničenja 
$$
r1_{max}+g1_{max}+b1_{max} = (N1-A1)+(N1-B1)+(N1-C1) = 3N1 - (A1+B1+C1) \geq 3N1 - 2N1 = N1.
$$
Konačno, same vrednosti možemo izabrati na sledeći način:
$$
r1 = \min(N1,N1-A1),\quad
g1 = \min(N1-r1, N1-B1),\quad
b1=\min(N1-r1-g1,N-C1).
$$

Složenost ovog rešenja je $O(1)$.



