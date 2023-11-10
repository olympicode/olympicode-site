# B2 - Turnir

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Andrej Ivašković | Aleksa Milisavljević | Andrej Ivašković | Vladimir Milenković |

## Rešenje prvog podzadatka

Ukoliko se igra sastoji od samo jedne runde, to znači da svih svojih $K$ žetona koristimo u toj rundi. Ukupan broj poena koji možemo da ostvarimo jednak je broju ostalih igrača koji imaju manje od $K$ žetona. Ovo rešenje radi u vremenskoj složenosti $O(M)$.

## Rešenje drugog podzadatka

Dovoljno je isprobati sve moguće načine da se $K$ predstavi kao zbir $N$ nenegativnih celih sabiraka, generisane _bektrekingom_, i da se za svaku od tih podela odredi broj poena koji možemo da ostvarimo. Broj načina da se $K$ razbije na $N$ sabiraka jednak je $N+K-1 \choose N-1$, a određivanje broja poena za datu podelu se radi u složenosti $O(MN)$. Bektreking rešenje ne mora da bude posebno efikasno da bi se u ovom podzadatku dobili svi poeni.

## Rešenje trećeg podzadatka

Za $M=1$ postoji samo jedan igrač protiv kog igramo, te je pitanje kako rasporediti žetone da ostvarimo najveći broj pobeda u rundama. Ukoliko je u $i$-toj rundi ovaj igrač postavio $a_{i,1}$ žetona, onda pobedu u ovoj rundi ostvarujemo postavljanjem $a_{i,1}+1$ žetona. Za ostvarivanje pobede u najvećem broju rundi, dovoljno je pobediti u onim rundama u kojima je naš protivnik stavio najmanje žetona. Ovo vodi ka jednostavnom gramzivom algoritmu: najpre se sortiraju runde po broju žetona saigrača (u rastućem poretku), nakon čega se “budžet” od $K$ žetona troši redom u ovim rundama sve dok nam ne ostane nijedan žeton. Vremenska složenost ovog rešenja je $O(N \log N)$.

## Rešenje četvrtog podzadatka

Ovaj podzadatak se rešava primenom _dinamičkog programiranja_. Definišimo trodimenzioni niz $S_{n,k}$, uz $0 \leq n \leq N$, $0 \leq k \leq K$:

* $S_{n,k}$: najveći broj poena koji se može ostvariti ukoliko je iskorišćeno $k$ žetona u prvih $n$ rundi

Trivijalno poznate vrednosti u ovom nizu su:

* $S_{0,k}=0$ za svako $k$

Neka je $[B]$ indikator nekog logičkog izraza: $1$ ukoliko $B$ važi i $0$ ukoliko ne važi. U slučajevima $n>0$ koristimo rekurentnu vezu:

* $S_{n,k} = \max_{1 \leq z \leq k} (S_{n-1,k-z} + \sum_{j=1}^{m} [a_{n,j} < z])$ (*)

Ova rekurentna veza može da se objasni na sledeći način: najbolji način da se $k$ žetona rasporedi u $n$ rundi može da se odredi ukoliko se razmotre svi mogući brojevi žetona $z$ u $n$-toj rundi, odredi koliko igrača ima manje od $z$ žetona u $n$-toj rundi i tako odredi broj poena, na to doda optimalna raspodela $k-z$ žetona u prethodnim rundama, i odredi najbolje takvo $z$. Tada je konačan odgovor na pitanje iz zadatka vrednost $S_{N,K}$, koja može da se odredi u vremenskoj složenosti $O(NMK^2)$.

## Rešenje petog podzadatka

Rešenje koje donosi sve poene je optimizacija rešenja četvrtog podzadatka.

Primetimo da su jedini značajni brojevi žetona u $n$-toj rundi $0, a_{n,1}+1, a_{n,2}+1, \ldots, a_{n,M}+1$, odnosno brojevi žetona pri kojima se ostvaruju različiti brojevi poena. U okviru jedne runde je nebitno koji igrač je stavio koliko žetona, bitni su samo brojevi. Stoga ne gubimo nikakve informacije sortiranjem brojeva žetona različitih igrača u okviru jedne runde.

Primetimo i da je $S_{n,k}$ za fiksirano $k$ rastuće u $n$, odnosno $S_{n,k} \leq S_{n',k}$ za $n < n’$.

Uz ova dva koraka, primetimo da nije neophodno ispitati sve moguće $z$ u formuli (*). Samim tim računanje $S_{n,k}$, koje se u prethodnom podzadatku radilo u vremenskoj složenosti $O(MK)$, može da se uradi u $O(M)$. Ukupna vremenska složenost je $O(NMK)$.

Za one koji žele da znaju više: ovaj zadatak je inspirisan igrom Blotto.
