## Rešenje kad $M \leq 18$
U ovom slučaju možemo isprobati svako razapinjujuće stablo (biranjem svakog podskupa grana), naći sva minimalna i za svaki par čvorova (kojih isto ima malo jer je graf povezan) naći i dodati rešenje. 
Tada je složenost $O(N^2 2^M)$

## Rešenje kad $M = K, N \leq 50$
Uočimo da će težina svake grane biti 1. Dakle, MST je svako razapinjujuće stablo, a kako je i broj čvorova manji, možemo da izračunamo rešenje za svaki par na tzv. pohlepan način.
Ovde je potrebno uraditi analizu slučajeva, prebrojimo sve čvorove sa direktnim vezama do ona dva koje posmatramo, oduzimajući one koji su zajednički (s tim da se s jednim
mogu oba povezati ukoliko ne postoji grana između njih).
Složenost će biti $O(N^2(N+M))$.

## Rešenje kad je $N \leq 100, M \leq 200$
Možemo ponovo rešavati za svaka dva čvora, s tim što puštamo simulaciju nalaženja MST sa optimalnim biranjem grana tako da se maksimizuju one koje uključuju neki od dva odabrana čvora.
Složenost je u ovom slučaju $O(N^2 M\log{M})$.

## Rešenje kad $K \leq 6$
Za ovo rešenje potrebno je preći na drugačiji način prebrojavanja (koji se koristi i u celon rešenju) - grupišemo grane sa jednakim težinama (kažemo da je čvor u grupi ako
postoji grana u grupi koja ga sadrži) i brojimo koliko puta grane
iz date grupe "figurišu" u konačnom zbiru (dakle bar jedan od selektovanih čvorova je neki iz grupe).
Pošto Kruskalov algoritam dodaje grane u sortiranom redosledu, možemo računati da kada posmatramo grupu težine $W$ su čvorovi već povezani
u komponente koje formiraju grane težina ispod $W$. Da bi se formirao MST svakako se u njega dodaje neki podskup novih grana, a kako je broj $K$ mali,
možemo ručno probati svaki podskup i videti koliko grane doprinose zbiru (za svaka dva čvora koja se pojavljuju u grupi kao krajevi veza). Kako ima $\frac{M}{K}$ grupa,
a $O(K)$ i čvorova i grana u grupi, složenost je $O(2^K MK)$.

## Rešenje za pun broj poena
Moguće je izvršiti prebrojavanje pojavljivanja grana u maks stepeninma čvorova iz grupe i brže, tako da ne postoji dodatni faktor osim kvadratnog po $K$. Posmatrajmo
veze čvorova iz grupe sa već formiranim komponentama.
Fiksiramo 2 čvora u grupi i za njih dodajemo broj komponenti s kojima su povezani, oduzimajući broj s kojim su oba povezana, sa obraćanjem pažnje na specijalne
slučajeve (neki od dva čvora povezan je sa komponentom od ovog drugog, u istoj su komponenti, ili postoji direktna veza između dva selektovana čvora).
Ovde se radi nešto donekle slično kao u drugom podzadatku, s tim što je (uslovno rečeno) tada jedina grupa bio skup svih čvorova, sada treba dodati i doprinos grana u 
trenutnoj grupi na zbir stepena kad selektovan par uključuje jedan čvor koji se ne pojavljuje u grupi, mada ovo se računa samo kao broj komponenti s kojim je povezan
onaj čvor koji jeste u grupi (naravno onoliko puta koliko ima čvorova van grupe). Nakon ovog procesa, ažuriramo komponente i prelazimo na narednu grupu.
Ukupna složenost je (istim rezonom kao i pre) $O(MK)$.