# 5 - Opklada

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Pavle Martinović | Aleksa Milisavljević |

## Rešenje kada je $l_{i,j}=u_{i,j}$
Neka je $c_i$ broj operacija koje smo primenili na $i$-tu kolonu, a $r_i$ broj operacija koje smo primenili na $i$-ti red. Preimtimo da je onda $m_{i,j}=r_{i}-c_{j}$. iz ovoga možemo da zaključimo da je $m_{i,j}=r_{i}-c_{j}=r_{i}+r_{1}-c_{j}-c_{1}-m_{1,1}=(r_i-c_1)+(r_1-c_j)+m_{1,1}=m_{i,1}+m_{1,j}-m_{1,1}$. Može se bez većih poteškoća dokazati da je ovaj uslov potreban i dovoljan uslov za Momirovu krajnju tabelu (suštinski rešavanjem sistema jednačina za $r_i$ i $c_i$). Tako da je potrebno samo proveriti uslov i nalazimo rešenje u $O(TNM)$.

## Rešenje kada je $l_{i,j}=u_{i,j}$ u prvom redu i koloni
Iz prethodnog podzadatka možemo da vidimo zapravo da pošto su nam fiksirani prvi red i kolona da nam je ostatak tabele fiksrian. Onda samo izračunamo koje vrednosti moraju da se nalaze na kraju u svakom polju i proverimo da li je u traženom intervalu. Složenost:  $O(TNM)$.

## Rešenje kada je $u_{i,j}-l_{i,j}\leq1$ i $N,M<=10$
U ovom podzadatku, koristimo rešenje prethodnog. Naime primetimo da za vrednosti u prvom redu i koloni imamo najviše $2^{M+N-1}$ opcija. Fiksiramo svaku od tih opcija i probamo algoritmom sličan onome u prethodnom podzadatku (sa potencijalno nekim odsecanjem zbog ubrzanja). Složenost:  $O(T2^{M+N}NM)$

## Rešenje kada je $l_{i,j}=u_{i,j}$ u svim belim poljima
Vratimo se na interpretaciju $m_{i,j}=r_{i}-c_{j}$. Vidimo da nam polje gde je $l_{i,j}=u_{i,j}$ daje jedinstvenu vezu između $r_{i}$ i $c_{j}$. Zbog uslova ovog zadatka, sve vrednosti $r_i$ i $c_i$ ćemo moći da izrazimo samo preko $r_1$ ili samo preko $r_2$. Kada se te veze ispune i ubace u nejednačine ostalih polja, onda će sva preostala polja da nam daju neke nejednačine oblika $a\le r_1-r_2\le b$. Kombinujući ove nejednakosti po svim poljima, nalazimo u kom intervalu  $r_1-r_2$ zaista treba da bude (kao presek svih gorenavedenih intervala), i odatle možemo da uzmemo proizvoljnu vrednosti. Na kraju pustimo algoritam iz trećeg podzadatka (drugom u ovom tekstualnom rešenju), da bismo videli da li je validno rešenje to koje smo našli.

## Rešenje bez dodatnih ograničenja
Primetimo da nam se uslovi u suštini svode na $l_{i,j}\leq r_i-c_j\leq u_{i,j}$. Prezapišimo ovo kao $r_i-c_j\leq u_{i,j}$ i $c_j-r_i\leq-l_{i,j}$. Sada smo sveli zadatak: na rešavanje sistema nejednačina po promenljivima $x_1,x_2\cdots,x_{M+N}$ gde je svaka nejednačina oblika $x_i-x_j\leq c$. Postoji generalni način na koji se ovo rešava koji ćemo prezentovati ovde.

Napravimo graf čiji čvorovi odgovaraju promenljivima našeg sistema nejednačina. Napravimo za svaku nejednačinu oblika $x_i-x_j\leq c$ granu od čvora $j$ do čvora $i$ sa težinom $c$. Pustićemo algoritam Belman-Ford, da bismo našli distancu od $1$ do svakog drugog čvora u ovom grafu. Tvrdimo da ukoliko u našem grafu postoji negativan ciklus, odgovor je da rešenje ne postoji, dok ako ne postoji negativan ciklus, rešenje uvek postoji i nalatimo ga kao $x_i=dist(1,i)$. Ukoliko postoji negativan ciklus, onda neka je to ciklus $a_1,a_2,\cdots,a_k$. Tada za njih imamo neke nejednakosti oblika $x_{a_i}-x_{a_{i+1}}\leq c_{i}$ (indeksi uzeti po modulu $k$). Sada kad saberemo ove jednačine, svaki od promenljivih nam se skrati i dobijamo $0\leq c_1+c_2+\cdots+c_k<0$ (jer je u pitanju negativan ciklus). Iz ovoga zaključujemo da kad ima negativan ciklus, rešenje zaista ne postoji. Sada pretpostavimo da negativan ciklus ne postoji. Dokažimo da je $x_i=dist(1,i)$ zaista rešenje. Treba da se uverimo da je $dist(1,i)-dist(1,j)\leq c$, odnosno $dist(1,j)+c\geq dist(1,i)$, što je svakako tačno jer je desna strana najkraći put od $1$ do $i$, dok leva strana predstavlja neki put od $1$ do $i$, gde prvo idemo do $j$ a onda od $j$ do $i$ direktnom granom težine $c$. Ovime smo se uverili da je ovo zaista rešenje.

Najzad da bismo finiširali zadatak, potrebno je dati dve fusnote na prethodni algoritam. Prva je da su neke vrednosti promenljivih možda negativne, a nama trebaju samo pozitivne vrednosti. Ovo, međutim, nije problem jer možemo svim promenljivama da dodamo neko $k$ da bi smo dobili opet validno rešenje sistema, gde su sve promeljive veće za $k$, pa za dovoljno veliko $k$ i pozitivne. Druga bitna stvar je da rešenje ovakvog sistema jednačina, u generalnom slučaju, ne mora biti samo od celih brojeva. Međutim, zbog načina koji smo našli rešenja, to jest kao najkraći put u nekom grafu gde su težine svih grana cele, onda će ovo rešenje koje smo detektovali u gornjem algoritmu ipak biti validno.

Ovime smo rešili zadatak u $O(TNM(N+M))$.
