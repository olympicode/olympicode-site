# 6 - Metropole

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Plavšić |

## Rešenje kada $N \leq 20$

Ovo je klasičan zadatak iz dinamičkog programiranja sa bitmaskama - traženje najdužeg puta u grafu. Imamo dinamičko programiranje $dp[i][mask]$, gde je  $i$ predstavlja čvora do kog smo stigli, a $mask$ je bitmaska koja predstavlja koje smo čvorove posetili do sad.
Složenost $O(N^2\cdot2^N)$ 

## Rešenje kada nema tura

U ovom slučaju, dati graf je stablo, a rešenje u tom slučaju je poznato: možemo ili raditi dinamičkim programiranjem, ili naprosto krenemo od proizvoljnog čvora i nađemo od njega najdalji, a zatim od tog najdaljeg nađemo najdalji, što će nam dati najduži put.

## Kako dalje?

Sada treba da nađemo neku ozbiljnu strategiju kako da tražimo najduži put. U tu svrhu ćemo pronaći blokove našeg grafa. To su maksimalni podskupovi čvorova tako da u tim skupovima nema artikulacionih tačaka. Za ovo postoji generalni algoritam, ali u našem slučaju to može da se uradi lakše. Naime, pustimo pretragu po dubili (DFS) u našem grafu, i za svaku granu van stabla uzmemo put na stablu koji spaja njene krajeve (koji je dužine $3$ zbog uslova sa dužinama ciklusa) i utrvdimo da su te $4$ grane u istom bloku (svaka grana je najviše u jednom bloku). Kada tako nađemo sve moguće četvorke, tranzitivno zatvorimo relaciju "u istom bloku" (u prevodu, napravimo graf nad granama i u njemu nađemo povezane komponente - čvorovi koje one obuhvataju nam predstavljaju blokove grafa). Sporije implementacije ovog dela su obuhvaćena podzadatkom $N\le2500$.

Sada, u proizvoljnom grafu možemo uvesti pojam *block-cut* stabla tako što izbacimo sve grane koje su deo nekog bloka i onda za svaki blok napravimo novi čvor koji je povezan sa svim čvorovima u tom bloku. Ovo je interesantno, jer ako je početni graf povezan, onda nam je block-cut stablo zaista stablo (ako nije povezan onda je u pitanju šuma). Svaki put u ovom grafu može da se preslika u put na block-cut stablu, samo svaki fragment puta koji predstavlja kretanje unutar jednog bloka zamenimo sa putem od početnog do čvora koji predstavlja taj blok, i onda od tog do završnog.

Sada nam je cilj da  modifikujemo block-cut stablo. Za svaki blok želimo da pronađemo stablo tako da su nam čvorovi bloka listovi, i da je najduži put od $u$ do $v$ unutar bloka jednak dužini puta od $u$ do $v$ u našem stablu. Ako svaki blok čvor u block-cut stablu zamenimo sa ovom mrežom koja enkodira optimizaciju traženja najdužeg puta na onom fragmentu puta koji se nalazi unutar stabla, onda nam se zadatak samo svodi na prethodni podzadatak - traženje najdužeg puta na stablu (ovde konkretno na tom našem modifikovanom block-cut stablu), jer svaki put u stablu možemo na isti način da preslikamo na put na modifikovanom block-cut stablu, a po konstrukciji će se najduži put preslikati u put iste dužine.

Sada nam treba detaljan opis blokova našeg grafa. Za to nam treba sledeća lema:
*Lema: Svaki blok u našem grafu je kompletan bipatritivan graf gde je jedna particija veličine $2$*.
**Dokaz:** Pošto svaki ciklus parne dužine, graf je bipartitivan - neka je u našem bloku $b$ belih i $c$ crnih. Moguće je dokazati da unutar bloka, za svake dve grane postoji ciklus koji ih sadrži. Pretpostavimo da postoje crni čvor $u$ i beli čvor $v$ koji nisu spojeni granom, i neka iz njih izlaze grane $ua$ i $vb$. Po prethodno navedenom, postoji ciklus koji sadrži, a to jedino može biti ciklus $u-a-b-v$, tako da su $u$ i $v$ ipak povezani granom, pa je graf kompletan i bipartitivan. Najzad, onda trivijalno postoji ciklus dužine $2\min(b,c)=4$, pa je zaista u jednoj particiji samo $2$ čvora.  

Sada smo već blizu kraja. Za konstrukciju naših stabala razlikujemo dva slučaja (i to baš oni iz podzataka!!)

## Svaka grana se nalazi u najviše jednom ciklusu
U ovom slučaju su  nam blokovi samo $K_{2,2}$ to jest ciklusi dužine $4$. Posmatrajmo ciklus $a-b-c-d$, tu suprotni na ciklusu treba da budu na distanci $2$, a susedni na ciklusu treba da budu na distanci $3$. Dodajmo čvorove $e$ i $f$ i povežemo parove $a-e$, $c-e$, $b-f$, $d-f$ i $e-f$. Lako se proverava da je ova konstrukcija baš ono što smo tražili.

## Svaka grana koja se nalazi u jednom ciklusu se nalazi u barem dva ciklusa
U ovom slučaju su  nam blokovi samo $K_{2,t}$ sa $t\ge3$, neka su nam ova $2$ čvora bela, a ostalih $t$ crni. Možemo da vidimo da najduža putanja između $2$ crna čvora dužine $4$, između crnog i belog dužine $3$ i između dva dela dužine $2$. Zato je dovoljno da uzmemo jedan novi čvor koji spojimo sa svim belima direktno granom, a sa svim crnima putem dužine $2$.

## Glavno rešenje
Naprosto spojimo konstrukcije iz predhotna dva slučaja, i onda na dobijenom stablu nađemo najduži put.
Složenost $O(N)$.
