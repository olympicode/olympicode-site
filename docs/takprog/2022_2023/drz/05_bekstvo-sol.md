## Analiza
Primena $K$ operacija se zapravo može uraditi odjednom: izbrišemo najviše $K$ grana, i dodamo nove tako da nam graf ponovo postane stablo.  Primetimo da je optimalno da nove grane dodajemo na krajeve dijametara "izrezanih" stabala (stabla na koja smo podelili originalno stablo kada smo izbrisali neke grane) tako da od njih napravimo put. Tada će, u optimalnom rešenju, krajnji dijametar stabla biti jednak sumi dijametara izrezanih stabala plus broj dodatih grana.

Slučaj $K=N$ je ekvivalentan sa $K=N-1$, pa ćemo razmatrati samo $0 \leq K < N$.

## Rešenje prvog i drugog podzadatka
Biraćemo grane koje brišemo i za sva stabla koja nam ostanu izračunati dijametre, i te dijametre ćemo sumirati. Mogućih podela u najgorem slučaju ima $2^{N-1}$ (svaku granu ili brišemo ili ne brišemo), a dijametar stabla možemo naći u $O(N)$ - pustimo pretragu iz nasumičnog čvora, obeležimo najdalji čvor od njega kao prvi kraj dijametra, pustimo pretragu iz tog čvora i obeležimo najdalji čvor kao drugi kraj dijametra. Ovaj algoritam radi jer je najdalji čvor od proizvoljnog čvora uvek kraj nekog dijametra, a najdalji čvor od kraja dijametra je drugi kraj tog dijametra.

Vremenska složenost ovog algoritma je $O(2^NTN)$, što prolazi prvi podzadatak. Međutim, ne moramo razmatrati svih $2^{N-1}$ podela - dovoljne su samo one gde brišemo tačno $K$ grana (ako smo izbrisali neki broj grana, nikad ne možemo dobiti lošije rešenje ako izbrišemo još neke). Ovako ćemo razmatrati samo ${N \choose K} \leq {N \choose N/2}$ podela, i rešenje nam lako prolazi drugi podzadatak.

## Rešenje četvrtog podzadatka
Pošto je $K = 0$, rešenje je samo dijametar početnog stabla. Ovde dijametar ne moramo ni tražiti $O(N)$ algoritmom: dovoljno je da iz svakog čvora pustimo po pretragu.

Vremenska složenost: $O(TN)$ ili $O(TN^2)$

## Rešenje petog podzadatka
Iteriraćemo kroz sve grane, i za svaku u $O(N)$ računati dijametre dva stabla koja dobijemo njenim brisanjem.

Vremenska složenost: $O(TN^2)$

## Rešenje trećeg podzadatka
Nije potrebno eksplicitno tražiti dijametre izrezanih stabala. Lakše nam je da uz svako izrezano stablo samo izaberemo neki put koje mu pripada - u optimalnom rešenju će se svakako ispostaviti da su to dijametri.

Definišimo $dp[u][k][x]$ kao najveću moguću sumu izabranih puteva u podstablu čvora $u$ ako smo u njemu primenili $k$ operacija, a $x$ je $0$, $1$, ili $2$ u zavisnosti od toga koliko još možemo da "dodajemo" na naš izabran put. Drugim rečima, ako je izabran put trenutnog podstabla samo čvor $u$, onda na njega možemo dodati puteve koji dolaze iz dva različita sina, pa je $x = 0$.  Ako se izabran put trenutnog podstabla završava u $u$, onda je $x=1$, a ako je put već u potpunosti izabran i ne dodajemo mu ništa, onda je $x=2$.

$dp[u][k][x]$ se nalazi dinamičkim programiranjem po stablu: iteriramo kroz sinove, neka je trenutni sin $v$. U $dp[u]$ imamo izračunat $dp$ za podstablo od $u$, a u $dp[u]$ imamo izračunat $dp$ za stablo sačinjeno od $u$ i podstabala svih sinova kroz koje smo do sada iterirali. Želimo da "spojimo" $dp$ vrednosti za $u$ i $v$, pa da u $dp[u]$ posle bude izračunat $dp$ za stablo kome je dodato i podstablo od $v$.

Spajanje $dp$-ova dva stabla se može uraditi u $O(N^2)$: iteriramo kroz broj grana koje ćemo brisati u prvom stablu ($i$), nakon toga kroz broj grana koje brišemo u drugom ($j$), i u neki novi $dp$ niz ažuriramo vrednosti za $i + j$ ili $i +j +1$ izbrisanih grana (u zavisnosti od toga da li brišemo granu od $u$ do $v$). Postoji nekoliko slučajeva: da brišemo granu od $u$ do $v$ i dodajemo dužine njihovih izabranih puteva,  da ne brišemo granu od $u$ do $v$ već na put koji se završava u $u$ dodajemo put koji se završava u $v$, ili da ne brišemo granu ali da izaberemo samo jedan od dva izabrana puta podstabala $u$ i $v$.

Krajnje rešenje će biti $max(dp[1][K][0], dp[1][K][1], dp[1][K][2]) + K$. Ako razmatramo da svako stanje u $dp[u][k][0]$ pripada i $dp[u][k][1]$, i da svako stanje u $dp[u][k][1]$ pripada i $dp[u][k][2]$ (što značajno olakšava implementaciju), rešenje je $dp[1][K][2] + K$.

Vremenska složenost: $O(TN^3)$

## Glavno rešenje
Glavno rešenje je isto kao za treći podzadatak, samo što tokom spajanja podstabala ne iteriramo kroz vrednosti koje su sigurno nemoguće. Drugim rečima, za sina ($v$) ćemo samo iterirati do veličine njegovog podstabla, a za koren podstabla ($u$) ćemo samo iterirati do veličine trenutnog stabla koje njegov $dp$ predstavlja (jer je nemoguće izbrisati više grana od toga).

Nije teško dokazati da složenost algoritma sada postaje $O(N^2)$. Kada spajamo $dp$-ove dva stabla, iteriramo do njihovih veličina - što možemo predstaviti kao da se svaki čvor koji pripada prvom stablu uparuje sa svakim iz drugog. Pošto će nakon toga svi ti čvorovi pripadati istom stablu, možemo primetiti da će svaka dva čvora da se upare tačno jednom - što daje ukupno $O(N^2)$ uparivanja.

Vremenska složenost: $O(TN^2)$

**Bonus**: Rešite zadatak u $O(TNlogN)$.