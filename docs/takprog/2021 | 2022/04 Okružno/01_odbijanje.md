# B1 - Odbijanje

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Andrej Ivašković | Dimitrije Erdeljan | Andrej Ivašković | Andrej Ivašković |

## Rešenje za 30 poena

Dovoljna je prosta simulacija ovog kretanja: dok god kuglica ima apsolutnu vrednost svoje pozicije ne veću od 100, svaka sekunda kretanja se simulira. Vodi se računa o trenutnoj poziciji $x$, vremenu od početka $t$, brzini $\mathit{dx}$ (koja je ili $1$ ili $-1$) i trenutku najskorijeg sudara $T$. U svakom koraku se ažurira pozicija ($x := x + \mathit{dx}$) i proveri da li pozicija odgovara nekoj od prepreka – a u tom slučaju se ažuriraju otpornost prepreke, brzina i vreme najskorijeg sudara. Ovo rešenje daje tačan odgovor u vremenskoj složenosti $O(N \cdot \max_i S_i \cdot \max_i |X_i|)$.

## Rešenje za 50 poena

Reč je o jednostavnoj optimizacija prethodnog pristupa. Umesto da se u svakom koraku pozicija promeni za 1, dovoljno je voditi računa o narednoj udarenoj prepreci sa leve i sa desne strane. Vreme između dva sudara je tada jednako apsolutnoj vrednosti razlike između pozicija te dve prepreke. Najpre treba podeliti prepreke u dva niza: prepreke sa negativnom pozicijom i prepreke sa pozitivnom pozicijom. U ta dva niza se zatim odrede prepreke najbliže kuglici i vrši se simulacija kretanja. Kada otpornost neke prepreke postane jednaka nuli, tada se ta prepreka označi kao nepostojeća i bira se najbliža prepreka sa nenultom otpornosti. Vremenska složenost ovog pristupa je $O(N \cdot \max_i S_i \cdot \max_i |X_i|)$.

## Rešenja za 70 i 100 poena

Ova dva rešenja su maltene identična i razlikuju se po tome što koriste različite algoritme sortiranja: $O(N^2)$ vremenske složenosti i $O(N \log N)$ vremenske složenosti. Najpre se, kao u prethodnom rešenju, razdvoje nizovi prepreka levo od nule i prepreka desno od nule. Zatim se ti nizovi sortiraju po apsolutnoj vrednosti pozicije i tako se određuje redosled kojim se kuglica sudara sa preprekama. Da li je poslednje odbijanje sa nekim levim zidom ili desnim zidom se određuje poređenjem ukupnih otpornosti desnih zidova i levih zidova:
* ako je ukupna otpornost desnih zidova $r$ manja ili jednaka ukupnoj otpornosti levih $l$, tada sa leve strane imamo $l$ odbijanja, a sa desne $l+1$ odbijanje;
* u suprotnom, sa leve strane i desne strane imamo po $r$ odbijanja.
Na osnovu ukupnog broja odbijanja sa obe strane je moguće odrediti za svaku “deonicu” (prostor između dve uzastopne prepreke) koliko je puta pređena. Na primer, ako je došlo do $m$ odbijanja sa leve strane, tada je prva deonica (od 0 do prvog zida) pređena $2m$ puta, druga $2(m-\mathit{otp\_levih}[0])$ puta itd, dokle god preostali broj odbijanja ne postane negativan. Neophodno je posvetiti pažnju poslednjem sudaru i oduzeti $1$ od broja prelazaka poslednje deonice.
