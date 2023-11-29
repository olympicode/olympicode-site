Označimo sa dist(i,j) menhetn rastojanje izmedju i-tog i j-tog polja a sa h[i] visinu i-tog polja.

Lema: Skup od n polja sa visinama u matrici je konzistentan (u smislu da postoji opisana matrica koja sadrži ova polja) ako i samo ako važe sledeća dva uslova
(1) Svi parni h[i]-ovi su na poljima čiji je zbir koordinata paran, a svi neparni h[i]-ovi na poljima čiji je zbir koordinata neparan ili obrnuto
(2) Za svaka dva polja i i j vazi |h[i] - h[j]| <= dist(i,j)

Ovo su očigledno potrebni uslovi, dok je za obrnut smer dovoljno pokazati da ako ovi uslovi važe, tada za bilo koje polje (x,y) postoji vrednost h koju možemo upisati u njega tako da ova dva uslova važe i za novi skup polja sa ovim poljem (to bi značilo da mozemo da popunimo celu matricu i da važe ova dva uslova, ali onda je ta matrica ok na osnovu primene tih uslova na susedna polja). Ideja dokaza je: u novo poolje (označimo ga sa n+1) možemo upisati konzistentnu vrednost (u smislu (2)) akko je pesek svih segmenata (na realnoj pravoj) [h[i] - dist(i,n+1), h[i] + dist(i,n+1)] neparazn (tada upisujemo odgovarajuću vrednost iz preseka vodeći računa i o (1)) a ovo se pokazuje koristeći već pretpostavljene uslove za prvih n polja i nejednakost trougla.

Uslov (1) se može trivijalno proveravati nezavisno od uslova (2) pa se koncentrišemo isključivo na uslov (2). Nazovimo par polja (i, j) “loš” ukoliko ne zadovoljava uslov (2) tj. ukoliko važi
() |h[i] - h[j]| > |x[i] - x[j]| + |y[i] - y[j]|
Koristeći oznake
Vpp(i) = L[i] + x[i] + y[i], Vpm(i) = h[i] + x[i] - y[i], Vmp(i) = h[i] - x[i] + y[i], Vmm(i) = h[i] - x[i] - y[i]
možemo se osloboditi apsolutnih vrednosti iz () razlikovanjem slučajeva. Tačnije, važi:

Za polje i postoji polje j za koje je (i,j) loš par ako i samo ako je tačno bar jedno od sledećih tvrđenja

j je “gore-levo” od i i važi Vmm(i) > Vmm(j)
j je “gore-levo” od i i važi Vpp(i) < Vpp(j)
… (ukupno 8 slučaja koja zavise od položaja gore/dole-levo/desno i odnosa h[i] i h[j])
Ovo možemo rešavati 2D segmentnim stablom - za svako novo polje postavljamo 8 upita “vrati min/max iz date 2D oblasti” i ubacujemo ga u strukturu posle upita. Međutim, ovde je problem memorijsko ograničenje - čak i implicitno (dinamičko) stablo uz kompresiju koordinata zauzima n * log^2(n) memorije što je praktično nemoguće uklopiti u zadata ograničenja.

Bolji pristup je korišćenje binarne pretrage po rešenju - tada problem postaje “da li postoji loš par među prvih m polja” i više nije bitno da vratimo najmanji indeks tj. da na prethodne upite odgovaramo redom. Koristimo “offline” pristup - sortiramo sva polja npr. po y-koordinati a zatim ih redom ubacujemo u obično segmentno stablo (indeksirano po x-koordinatama) uz upite “min/max na segmentu” (potrebno je 2 puta proći kroz stablo, po jednom u svakom smeru). Vremenska složenost ovog pristupa je O(n * log^2(n)) a memorijska je O(n) i nosi maksimalan broj poena.

Podzadaci uključuju slučajeve kada prolazi rešenje složenosti O(n^2) (što je jedan od načina za “proveru” leme za vreme takmičenja), 1D slučaj (novo polje je dovoljno uporediti sa njegovim susedima), slučajeve u kojima su visine polja mali brojevi (na osnovu (*) za svako polje je dovoljno proveriti samo ona koja su na rastojanju ne većem od MaxH a njih ima O(MaxH^2)) kao i slučaj gde prolazi 2D segmentno.
