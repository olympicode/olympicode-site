# 2 - Arhitekta

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Aleksa Milisavljević | Aleksa Milisavljević | Mladen Puzić | Aleksa Plavšić |

## Rešenje kada $M=N−1$
U ovom podzadatku moramo odabrati sve putevi da bismo konstruisali odgovarajući plan. Nađimo bitovsku disjunkciju cena svih grana. 

Vremenska i memorijska složenost je $O(N)$.

## Rešenje kada skup puteva pravi ciklus
U ovom podzadatku, moramo odabrati sve puteve sem jednog, gde možemo bilo koji izostaviti. Možemo prebaciti ovaj graf u niz dužine $N$, gde čuvamo cene puteva redom. Da bismo efikasno našli bitovsku disjunkciju svih puteva sem jednog, čuvaćemo prefiksnu i sufiksnu bitovsku disjunkciju tog niza. Rešenje je onda bitovska disjunkcija odgovarajućeg prefiksa i sufiksa. Od svih mogućih opcija, biramo onu koja daje najjeftiniji plan. 

Vremenska i memorijska složenost je $O(N)$.

## Rešenje kada $0\leq w_i \leq 1$
Bitovska disjunkcija brojeva iz skupa $\{0,1\}$ može biti 0 samo ako su svi brojevi $0$. U suprotnom ona je $1$. Zato, proverimo da li kada uzmemo sve puteve cene $0$ dobijemo državu u kojoj je svaki grad povezan sa svakim drugim. Ukoliko da, rešenje je $0$, u suprotnom, rešenje je $1$. Ovo možemo proveriti na primer DFS algoritmom. 

Vremenska i memorijska složenost je $O(N+M)$.

## Rešenje kada $1 \leq M, w_i \leq 10^3$
Pošto su cene puteva do $1000$, onda je najveći mogući rezultat $1023$. Proverićemo sve moguće ukupne cene jednu po jednu od najmanje ka najvećoj. Recimo da proveravamo rezultat $x$. Prođimo redom kroz sve grane i dodajmo samo one koje možemo, tako da $x$ ostane moguć rezultat. U ovom slučaju, to znači da ni na jednoj poziciji u binarnom zapisu nema cifru $1$, a da je u broju $x$-ta cifra $0$. Kada dodamo sve te grane, kao u prethodnom podzadatku proverimo da li je moguće stići od svakog grada do svakog drugog koristeći te grane. Ako da, i to je najmanje takvo $x$, to je rešenje. 

Vremenska složenost je $O(M\cdot \max(w_i))$, a memorijska $O(N+M)$.

## Glavno rešenje
Umesto da fiksiramo mogući rezultat kao u prethodnom zadatku, gradićemo rezultat bit po bit, krenuvši od najvrednijeg bita. Pošto važi da je $2^0+2^1+\ldots+2^i\leq 2^{i+1}$, u interesu nam je da najvredniji bit bude što manji. Pokušajmo prvo da izbegnemo najvredniji bit. Dodajmo sve grane u čijim težinama je ta cifra $0$. Ukoliko možemo da napravimo plan samo sa tim granama, stavljamo $0$ na tu cifru rezultata, a izbacujemo iz skupa grana sve grane čijoj ceni je ta cifra $1$, jer su nepotrebne. Ukoliko ne možemo, onda stavljamo $1$ na tu cifru, ali održavamo isti skup grana (neophodne su nam obe vrste). U oba slučaja, prelazimo na sledeći bit na isti način. Na kraju, imaćemo konstruisani rezultat. 

Vremenska složenost je $O(M\log(w_i))$, a memorijska $O(N+M)$.