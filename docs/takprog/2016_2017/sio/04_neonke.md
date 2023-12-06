---
hide:
  - toc
---

# 4 - Neonke

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| - | - |
	
	Kao što ste već videli, za uspešno održavanje drugog dana SIO bilo je potrebno otići u Komisijski tajni podrum i precizno aktivirati mašinu koja će zameniti zadatke između dva dana. Pošto ste prethodnog dana uspešno odredili način na koji je ovo potrebno uraditi, članovi Komisije su uspeli da aktiviraju mašinu, i drugi dan SIO može biti održan.
	
	Međutim, ova aktivacija mašine nije bila bez posledica. Naime, Komisijski podrum je izuzetno loše osvetljen, tako da je navigacija bila jako teška, i određeni članovi Komisije su bili povređeni. Kako se uskoro očekuje poseta IZS (Inspekcije za održavanje Zdravlja i Sigurnosti™), Komisija je odlučila da prikladno osvetli podrum neonskim sijalicama (*"neonkama"*). 
	
	Podrum je predstavljen kao matrica od $N \times M$ polja. Neonka postavljena na poziciji $(x_n, y_n)$ je u mogućnosti da osvetli polja $(x, y)$ za koja važi $x_n - R \leq x \leq x_n + R$ i $y_n - R \leq y \leq y_n + R$, gde je $R$ jačina svetlosti neonke. Za ovo polje takođe mora važiti da unutar pravougaonika određenog koordinatama $(x, y)$ i $(x_n, y_n)$ **nema ni jednog zida**! 
	
	Na primer, ako je $R = 3$, polja označena sa `'S'` bi bila osvetljena neonkom postavljenom na poziciju označenu sa `'N'`:
	
	```
	.#...SSS........
	.#...SSS#.......
	.####SSS#.......
	....#SSNSSS.....
	....#SSSSSS.....
	....#SSS#.......
	....#SSS#.......
	```
	
	Zbog umanjenja brojnosti Komisije, angažovana je pomoć malog Perice, koji je bio odsutan jureći naučne konferencije tokom celog ovogodišnjeg ciklusa takmičenja. Kako Perica nema vremena da se angažuje, čak ni kada je to najpotrebnije, odlučio je da naplati postavljanje svake neonke sa $C$ dinara, i ručno paljenje svake neonke sa $P$ dinara. Na sreću, nije neophodno ručno upaliti svaku neonku -- ukoliko svetlost od jedne neonke zahvati drugu, ona se onda sama pali. Možete smatrati da će Perica paliti neonke tako da je broj ručnih paljenja minimalan.
	
	Na vama je da odredite na koje pozicije u podrumu treba postaviti neonke, tako da se osvetli što više njegovih polja. Komisija je odvojila ograničen budžet za malog Pericu -- ovaj budžet ne sme da se premaši!
	
	## Napomena
	Ovo je zadatak sa poznatim ulazom (*output-only* zadatak). Vama su dati ulazni fajlovi (`case-01.in`, `case-02.in`, `case-03.in`, `case-04.in`), dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`case-01.out`, `case-02.out`, `case-03.out`, `case-04.out`).
	
	## Opis ulaza
	U prvom redu ulaznih fajlova nalaze se tri prirodna broja $N$, $M$ i $R$ - visina i širina plana podruma, i jačina svetlosti svake neonke, redom. U drugom redu nalaze se tri prirodna broja $C$, $P$ i $B$: cena jedne neonke, cena ručnog paljenja jedne neonke, i ukupan budžet dostupan Komisiji, redom. U preostalih $N$ redova nalazi se po $M$ karaktera, koji predstavljaju plan podruma, ${\bf Z}$, jedan po jedan red, redom. Svaki karakter može biti `'.'`, `'#'` ili `'-'`, tako da `'.'` predstavlja slobodno polje, dok preostala dva karaktera predstavljaju zidove.
	
	## Opis izlaza
	Vaši izlazni fajlovi treba da sadrže pozicije svih neonki koje Komisija treba da kupi: za svaku neonku, potrebno je u zasebnom redu izlaza priložiti dva cela broja $X_i$ i $Y_i$, koji predstavljaju poziciju $i$-te neonke koju Komisija treba da kupi. Obavezno mora da važi $1 \leq X_i \leq N$, $1 \leq Y_i \leq M$, i ${\bf Z}_{X_i, Y_i} = \text{'.'}$.
	
	## Primer 1
	### Ulaz
	```
	8 22 3
	1 100 220
	--########--########--
	-#########--#########-
	-#......######......#-
	-#..................#-
	-#..................#-
	-#..................#-
	-####################-
	--##################--
	```
	
	### Izlaz
	```
	4 7 
	4 10
	```
	
	### Objašnjenje primera
	Ukoliko postavimo neonke na date dve pozicije, onda će osvetljenost podruma biti sledeća (sa `'N'` obeležavamo pozicije neonki, a sa `'S'` pozicije koje su osvetljene):
	
	```
	--########--########--
	-#########--#########-
	-#.SSSSS######......#-
	-#.SSSNSSNSSS.......#-
	-#.SSSSSSSSSS.......#-
	-#.SSSSSSSSSS.......#-
	-####################-
	--##################--
	```
	
	Dovoljno je ručno upaliti samo jednu od ove dve neonke da bi se obe upalile. Stoga je ukupna utrošena cena za ovo rešenje $2 \times C + 1 \times P = 102$, što je unutar našeg budžeta, tako da je rešenje korektno. Ovo rešenje ukupno osvetljava $35$ polja (i **ne predstavlja** optimalno rešenje!).
	
	## Bodovanje
	Vaše rešenje za neki od ulaza će se smatrati nevažećim ukoliko je ispunjen bar jedan od sledećih uslova:
	- izlazni fajl sadrži neparan broj celih brojeva;
	- izlazni fajl sadrži poziciju koja je izvan ograničenja datog plana;
	- izlazni fajl sadrži poziciju na kojoj se nalazi zid;
	- izlazni fajl sadrži dve iste pozicije;
	- ukupna cena postavljanja i ručnog paljenja neonki premašuje zadati budžet.
	
	U suprotnom, neka je $k$ ukupan broj polja koje vaše rešenje osvetljava. Za svaki ulaz definisane su konstante $A$ i $B$ tako da:
	- Ukoliko važi $k \geq B$, osvajate 25 poena za taj ulaz;
	- Ukoliko važi $k \leq A$, osvajate 0 poena za taj ulaz;
	- Inače, osvajate $\lfloor 25 \times \frac{k - A}{B - A}\rfloor$ poena za taj ulaz.
	
	## Testiranje i eksperimentisanje
	Na korišćenje vam je dat program sa kojim možete lakše da testirate svoje rešenje (`Neonke.jar`). 
	
	Pokretanjem ovog programa iz direktorijuma u kome se nalaze i odgovarajući `case-??.in` i `case-??.out` fajlovi, moći ćete da vizuelizujete vaše rešenje za date ulaze, kao i informacije poput količine polja koje ste osvetlili i ukupne cene koju ste potrošili.
	
	Sve neonke koje se upale kao posledica jednog ručnog paljenja će unutar programa biti prikazane istom bojom.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Petar Veličković | Petar Veličković | Petar Veličković | Marko Savić |
	
	Prvi zadatak sa drugog dana Srpske Informatičke Olimpijade predstavlja challenge tip problema, tj. problema u kome najoptimalnije rešenje nije neophodno poznato. Stoga, cilj je bio maksimizovati pogodnost rešenja, sa parcijalnim nagrađivanjem za rešenja koja su između određenih graničnih vrednosti. Zadatak je uključivao pravilno raspoređivanje resursa, tako da se maksimizira prekrivanje prostorije neonskim sijalicama. Određene uštede su bile moguće ukoliko se sijalice “nadovezuju” jedne na drugu (tj. ukoliko jedna sijalica upada u svetlost druge), što može značajno umanjiti ukupnu cenu, ali i broj pokrivenih polja. Dodatne probleme izaziva relativno neoptimalan efekat blizine zidovima.
	
	Generalno najbolji način da se “napadne” ovakav problem i njemu slični je da se napravi neka “osnovna” strategija za postavljanje neonki, sa svom neophodnom infrastrukturom (pomoćnim metodama itd.), pa da se nakon toga isprobavaju razne varijacije osnovnog algoritma, koje više uzimaju u obzir različite aspekte problema—uzimajući za svaki test primer onaj algoritam koji daje najbolje rezultate.
	
	Verovatno najvažniji deo izgradnje rešenja je metoda koja određuje efekte postavljanja nove neonke na neko polje (na potencijalno već parcijalno osvetljenom podrumu). Ovo je izuzetno korisno iako je takmičarima bio dat na korišćenje detaljan vizualizator, i predstavlja glavni algoritamski izazov ovog zadatka, jer čini inkrementalno pravljenje rešenja izuzetno praktičnim. Ova metoda zahteva preračunavanje broja osvojenih polja, kao i spajanje nove neonke sa nekim drugim povezanim komponentama neonki, ukoliko je ovo primenljivo. Pošto su jačine neonki u test primerima bile relativno male, bilo je prikladno direktno ispitati sva polja u kvadratu oko potencijalne nove neonke. Za jednostavno održavanje povezanih komponenti moguće je bilo koristiti bilo koju strukturu za održavanje disjunktnih skupova.
	
	Nakon što je ova metoda u mestu, moguće je bilo definisati neke osnovne strategije (Komisijske konstante za ocenjivanje su određivane na osnovu najboljeg i najgoreg učinka ovih strategija na test primerima):
	
	Gramzivo (greedy) rešenje fokusirano na pokrivenost: u svakom koraku, odabrati polje koje pokriva najviše nepokrivenih polja. Ovo rešenje je izuzetno neefikasno ukoliko je konstanta P velika, jer će rezultovati velikim brojem komponenti koje moraju da se odvojeno pale!
	1-“zmija” rešenje, gde se prvo polje bira gramzivo, a sva naredna polja određuju tako da sve neonke konstantno ostaju u jednoj komponenti. Ovo rešenje je jako efektivno ako je cena dodavanja nove neonke značajno manja od cene paljenja jedne neonke, i ukoliko je moguće identifikovati povezanu komponentu u test primeru koja sadrži većinu slobodnih polja.
	nepovezano k-“zmija” rešenje, koje predstavlja korekciju prethodnog algoritma za višestruke odvojene povezane komponente slobodnih polja—krenuti ne od jednog nego od k gramzivo odabranih polja u odvojenim povezanim komponentama, i onda se od njih širiti tako da broj komponenti ne raste.
	nasumično k-“zmija” rešenje, gotovo identično kao prethodno, s tim da se početna polja ne biraju tako da budu u odvojenim komponentama, nego potpuno nasumično. Ovo može biti vrlo efektivno ako ima dosta prostora u podrumu, uz naznaku da će potencijalno u nekom momentu neke komponente da se spoje.
	Nakon pravljenja osnovnog rešenja, moguće je dodatno ga poboljšati stohastičnom hill-climber strategijom (ova strategija nije bila korišćenja pri računanju gornjih granica), gde se pozicije neonki nasumično pomeraju za neku malu vrednost, ili se neonke potpuno izbacuju i postavljaju ponovo na neko drugo mesto. Tokom ove procedure, sve vreme pamtimo do sada najbolje dobijeno rešenje.
	
	Test primeri (čije matrice su povučene sa finala Google-ovog Hash Code 2017 takmičenja, koje je i služilo kao glavna inspiracija za ovaj problem) su bili direktno dostupni takmičarima, tako da o njima ne moramo dodatno raspravljati. Prvi test primer je dizajniran da bude jednostavno maksimalno rešiv (dokle god je korišćenja k-“zmijska” strategija ili neka njena varijanta), dok su parametri ostalih test primera birani da pokriju širok spektar scenarija, poput:
	
	Veliki prostor, izuzetno mali poluprečnik, jeftino pravljenje novih komponenti;
	Veliki prostor, izuzetno veliki poluprečnik;
	Skučeni prostor (sa mnogo odvojenih sitnih komponenti).
	Zadovoljstvo nam je da vidimo da je značajan broj takmičara pokušao da se oproba u rešavanju bar jednog test primera. Posebne čestitke Dušanu Živanoviću za osvojenih 98 poena na ovom zadatku! U prilogu možete videti vizuelizaciju njegovih poslatih rešenja za sva četiri test primera. Nadam se da vam se zadatak svideo! 
	
	``` cpp title="04_neonke.cpp" linenums="1"
	#include <iostream>
	#include <string>
	#include <vector>
	#include <map>
	
	using namespace std;
	
	long long numComponents;
	
	struct Node
	{
	    int parent;
	    int rank;
	};
	Node DSU[10000001];
	
	inline void MakeSet(int x)
	{
	    DSU[x].parent = x;
	    DSU[x].rank = 0;
	    numComponents++;
	}
	
	inline int Find(int x)
	{
	    if (DSU[x].parent == x) return x;
	    DSU[x].parent = Find(DSU[x].parent);
	    return DSU[x].parent;
	}
	
	inline void Union(int x, int y)
	{
	    int xRoot = Find(x);
	    int yRoot = Find(y);
	    if (xRoot == yRoot) return;
	    numComponents--;
	    if (DSU[xRoot].rank < DSU[yRoot].rank)
	    {
	        DSU[xRoot].parent = yRoot;
	    }
	    else if (DSU[xRoot].rank > DSU[yRoot].rank)
	    {
	        DSU[yRoot].parent = xRoot;
	    }
	    else
	    {
	        DSU[yRoot].parent = xRoot;
	        DSU[xRoot].rank++;
	    }
	}
	
	int n, m, r;
	int c, p, b;
	
	vector<string> board;
	bool mark[1001][1001];
	int poz[1001][1001];
	
	int placetest(int x, int y, int nid, bool doit)
	{
	    if (doit) MakeSet(nid);
	
	    int total = 0;
	
	    int ly = -1;
	    int ry = m;
	
	    for (int dx=0;dx>=-r;dx--)
	    {
	        int xt = x + dx;
	        if (xt < 0) break;
	        if (board[xt][y] != '.') break;
	
	        // top-left
	        for (int dy=0;dy>=-r;dy--)
	        {
	            int yt = y + dy;
	            if (yt <= ly) break;
	            if (board[xt][yt] != '.')
	            {
	                ly = max(ly, yt);
	                break; // no need to go on
	            }
	
	            // If field is unoccupied, occupy it
	            if (!mark[xt][yt])
	            {
	                if (doit) mark[xt][yt] = true;
	                total++;
	            }
	            // If there is someone else here, union it
	            if (doit && poz[xt][yt])
	            {
	                Union(nid, poz[xt][yt]);
	            }
	        }
	
	        // top-right
	        for (int dy=0;dy<=r;dy++)
	        {
	            int yt = y + dy;
	            if (yt >= ry) break;
	            if (board[xt][yt] != '.')
	            {
	                ry = min(ry, yt);
	                break;
	            }
	
	            // If field is unoccupied, occupy it
	            if (!mark[xt][yt])
	            {
	                if (doit) mark[xt][yt] = true;
	                total++;
	            }
	            // If there is someone else here, union it
	            if (doit && poz[xt][yt])
	            {
	                Union(nid, poz[xt][yt]);
	            }
	        }
	    }
	
	    ly = -1;
	    ry = m;
	
	    // now expand down
	    for (int dx=0;dx<=r;dx++)
	    {
	        int xt = x + dx;
	        if (xt > n - 1) break;
	        if (board[xt][y] != '.') break;
	
	        // bottom-left
	        for (int dy=0;dy>=-r;dy--)
	        {
	            int yt = y + dy;
	            if (yt <= ly) break;
	            if (board[xt][yt] != '.')
	            {
	                ly = max(ly, yt);
	                break; // no need to go on
	            }
	
	            // If field is unoccupied, occupy it
	            if (!mark[xt][yt])
	            {
	                if (doit) mark[xt][yt] = true;
	                total++;
	            }
	            // If there is someone else here, union it
	            if (doit && poz[xt][yt])
	            {
	                Union(nid, poz[xt][yt]);
	            }
	        }
	
	        // top-right
	        for (int dy=0;dy<=r;dy++)
	        {
	            int yt = y + dy;
	            if (yt >= ry) break;
	            if (board[xt][yt] != '.')
	            {
	                ry = min(ry, yt);
	                break;
	            }
	
	            // If field is unoccupied, occupy it
	            if (!mark[xt][yt])
	            {
	                if (doit) mark[xt][yt] = true;
	                total++;
	            }
	            // If there is someone else here, union it
	            if (doit && poz[xt][yt])
	            {
	                Union(nid, poz[xt][yt]);
	            }
	        }
	    }
	
	    return total;
	}
	
	int cntflds()
	{
	    int ret = 0;
	    for (int i=0;i<n;i++)
	    {
	        for (int j=0;j<m;j++)
	        {
	            if (mark[i][j]) ret++;
	        }
	    }
	    return ret;
	}
	
	int main()
	{
	    cin >> n >> m >> r;
	    cin >> c >> p >> b;
	
	    board.resize(n);
	    for (int i=0;i<n;i++) cin >> board[i];
	
	    int numRs = 0;
	
	    // Overly conservative because why not
	    while ((numRs + 1) * c + (numComponents + 1) * p <= b)
	    {
	        int best = -1;
	        int bx = -1, by = -1;
	        for (int i=0;i<n;i++)
	        {
	            for (int j=0;j<m;j++)
	            {
	                if (!poz[i][j] && board[i][j] == '.' && ((1 +numRs) % 3 != 0 || mark[i][j]))
	                {
	                    int cur = placetest(i, j, numRs + 1, false);
	                    if (cur > best)
	                    {
	                        best = cur;
	                        bx = i, by = j;
	                    }
	                }
	            }
	        }
	
	        // No need to update stuff if done
	        if (best == 0) break;
	
	        placetest(bx, by, ++numRs, true);
	        poz[bx][by] = numRs;
	        cout << bx + 1 << " " << by + 1 << endl;
			cerr << "Fields covered: " << cntflds() << endl;
	    }
	
	    cerr << "Fields covered: " << cntflds() << endl;
	    cerr << "Cost spent: " << (numRs * c + numComponents * p) << endl;
	
	    return 0;
	}

	```
