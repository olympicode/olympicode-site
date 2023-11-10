<petljaMeta>
	  <petljaProblemCode>2016_KV1_06_cmyk</petljaProblemCode>
	  <petljaDate>2017-01-30-22-00</petljaDate>
	  <petljaTitle>CMYK</petljaTitle>
	  <petljaProblemAuthor>Petar Veličković</petljaProblemAuthor>
	  <petljaSolutionAuthor>Nikola Jovanović</petljaSolutionAuthor>
	  <petljaSourceCode>cmyk.cpp</petljaSourceCode>
</petljaMeta>

##Motivacija
Teorijsku osnovu ovog zadatka predstavlja problem **parsiranja kontekstno-slobodnih gramatika** (eng. [context-free grammars](https://en.wikipedia.org/wiki/Context-free_grammar)). Konkretno, gramatika data u zadatku je predstavljena u **Čomski normalnoj formi** (eng. [Chomsky normal form](https://en.wikipedia.org/wiki/Chomsky_normal_form)) pa je parsiranje moguće (uz male modifikacije) izvršiti algoritmom [Cocke–Younger–Kasami (CYK)](https://en.wikipedia.org/wiki/CYK_algorithm), čije ime se krije u naslovu zadatka. Iako čine teorijsku osnovu ovog zadatka, uvođenje pomenutih pojmova iz oblasti formalnih jezika nije neophodno, budući da je za razumevanje CYK algoritma sa potrebnim modifikacijama i kompletno rešavanje ovog zadatka potrebno samo poznavanje dinamičkog programiranja. Stoga ćemo taj deo zaobići, i kako bi rešenje bilo jasnije i razumljivo takmičarima koji nisu upućeni u pomenutu teoriju u nastavku analize ćemo odstupati od formalne terminologije.

##Optimalno rešenje

Kao što je već pomenuto, predviđeno rešenje za ovaj zadatak se bazira na **CYK** algoritmu. Iako ovaj algoritam ,,ima ime'' očekuje se da bi takmičari koji imaju iskustva sa dinamičkim programiranjem trebalo da budu u stanju da samostalno dođu do rešenja, bez obzira na to što se nisu ranije susreli sa konkretnim algoritmom. CYK algoritam u svojoj osnovnoj formi kao ulaz uzima niz pravila nalik onima u zadatku (tj. konteksno-slobodnu gramatiku u Čomski normalnoj formi), string `S`, i startni simbol (u našem slučaju to je simbol `W`) i proverava da li je moguće konačnom primenom pravila doći od stringa `S` do startnog simbola (tj. da li `S` pripada jeziku koji gramatika definiše). Složenost ovog algoritma je $\mathcal{O}(n^3 * m)$, gde je `n` dužina stringa `S` a `m` broj pravila. U našem slučaju, algoritam može da odredi da li se uneti niz boja može svesti na **jednu** belu boju, što nije dovoljno, budući da treba proveriti da li se ulazni niz boja može svesti na niz belih boja proizvoljne dužine. U nastavku ćemo ovaj problem, koji onemogućava direktno korišćenje CYK algoritma, zvati **problem niza** i pomenućemo dva pristupa koja ga uspešno rešavaju. Pre toga, objasnimo osnovnu verziju CYK algoritma primenjenu na ovaj zadatak.

###CYK algoritam

Najvažnije svojstvo koje CYK koristi je da su sva pravila oblika $XY \to Z$. Znajući ovo, glavna ideja algoritma je  da istraži sve moguće načine da se string `S` podeli na dva dela i pokuša da primeni jedno od pravila na simbole dobijene transformacijom tih delova. Međurezultati se čuvaju u trodimenzionalnom nizu `boolean` vrednosti `DP`, gde `DP[i][j][k]` ima vrednost `true` ako je moguće podstring dužine `i` koji počinje na indeksu `j` konačnom primenom pravila svesti na simbol `k`. U prvom koraku se postave vrednosti za sve podnizove dužine `1` (tj. `DP[1][j][k]` ima vrednost `true` akko je `s[j] = k`). Nakon toga, algoritam obrađuje podstringove redom, rastuće po njihovim dužinama, i pokušava da svaki podstring podeli na dva disjunktna podstringa `L` i `R`, nakon čega proverava da li postoji pravilo tipa $AB \to C$ takvo da je se `L` može transformisati u simbol `A` i da se `R` može transformisati u simbol `B` (ove vrednosti se mogu naći u tabeli). Ako takvo pravilo postoji, u tabelu se upisuje da je trenutni podstring moguće transformisati u simbol `C`. Kada algoritam obradi sve podstringove, uključujući i kompletan string `S`, informaciju o tome da li se se `S` može transformisati u simbol `W` čitamo iz `DP[n][1][W]` (ako je string indeksiran od pozicije `1`).

###Problem niza

Sada dolazimo do pomenutog ,,problema niza''. Kako modifikovati/nadograditi ovaj algoritam tako da testira transfomaciju u niz simbola `W` umesto u pojedinačni simbol? Tvorci zadatka su došli do dva rešenja za ovaj problem:

* **CYK_start**: Dodavanjem novog simbola `^` na početak stringa i pravila $\verb|^|W \to \verb|^|$ u skup pravila omogućavamo da se nizovi belih boja na početku stringa (nakon `^`), uslovno rečeno, ,,sažmu'' tj. da se niz simbola `W` (string oblika `^W..W`) može transformisati u jedan simbol `^`. Sada se naš uslov menja, i ako CYK dokaže da se modifikovani startni string može dovesti do simbola `^`, znamo da je odgovor `YES`.
* **CYK_tiles**: Ovoga puta ne menjamo skup pravila i string već iz CYK tabele trivijalno izvlačimo sve podstringove koji se mogu transformisati u `W` i rešavamo potproblem: da li je moguće tim podstringovima ,,popločati'' ceo string `S` (tj. da li je moguće odabrati skup disjunktnih podstringova čija je unija ceo string `S` takav da se svaki od njih može transformisati u `W`)? Jasno je da je rešenje ovog problema ekvivalentno rešenju zadatka, a ovaj problem se rešava još jednom primenom dinamičkog programiranja, korišćenjem `boolean` niza `T` i rekurentne veze $T[i] = T[i - l_1] \lor \dots \lor T[i - l_k]$, gde su $l_1 \dots l_k$ dužine podstringova koji se završavaju na poziciji `i` i koji se mogu transformisati u `W`. Dakle, `T[i]` se odnosi na popločavanje prvih `i` karaktera stringa, pa se rešenje nalazi u `T[n]`.

###Ilustracija

Pogledajmo ilustraciju rada CYK algoritma sa **start** modifikacijom na primeru. Neka imamo pravila $RG \to B$ i $BB \to W$ i neka je string `S = "RGB"`.

Modifikovan skup pravila:
$ RG \to B$
$BB \to W$
$\verb|^|W \to \verb|^|$

Modifikovan string `S`:
$\verb|^|RGB$

Prikaz tabele DP na ovom primeru (kako nije zgodno crtati trodimenzione tabele, u ovoj ilustraciji se u `DP[i][j]` nalaze svi simboli za koje je `DP[i][j][k] = true` ili `/` ukoliko ne postoji nijedan takav simbol): 

<center>
|i\j|1|2|3|4|
|--|--|--|--|--|
|**1**|*^*|R|G|B|
|**2**|/|B|/| |
|**3**|/|W| | |
|**4**|^| | | |
</center>

Simbol `^` se nalazi u `DP[4][1]` iz čega zaključujemo da je odgovor `YES`.

## Suboptimalna rešenja

Sada kada znamo optimalno rešenje zadatka, osvrnimo se na neka suboptimalna rešenja:

* **Brute-force pristup**, koji u ovom slučaju podrazumeva da pokušamo da primenimo sve moguće sekvence pravila za mešanje boja. Standardna implementacija ovog pristupa bi rekurzivno na trenutni niz boja primenjivala sva pravila koja je moguće primeniti. Složenost ovog pristupa je $\mathcal{O}((nm)^n)$ i očekivan broj poena koji bi ovaj pristup doneo je $20-40$.
* **Greedy pristupi**, koji podrazumevaju da u svakom trenutku primenjujemo pravila na dve krajnje leve tj. krajnje desne boje. Složenost ovog pristupa je $\mathcal{O}(nm)$ i iako nije u potpunosti korektan doneo bi $20-40$ poena.
* **Nedeterministički pristupi i heuristike**, tj. primena nasumičnih pravila kako bi se došlo do traženog niza belih boja i korišćenje određenih pretpostavki i algoritama koji ne moraju biti uvek tačni ali se pretpostavlja da pokrivaju određeni broj slučajeva. Složenost i uspeh ovakvih pristupa varira, a implementacije autora ovog zadatka ne uspevaju da ostvare više poena od **Brute-force** pristupa.
* **,,Kompresija''**: Rešenje koje koristi CYK algoritam ali kao modifikaciju dodaje pravilo $WW \to W$. Ovo rešenje, iako na prvi pogled deluje kao da rešava problem niza i radi za veliki broj nasumičnih test primera, nije ispravno. Najprostiji primer na kome se vidi neispravnost ovog pristupa je:

	```
	2
	AW -> X
	XB -> W
	1
	4
	AWWB
	```

	Primetimo da ovde svođenje na niz belih boja nije moguće iako bi ,kompresija'' to uspešno uradila:
	$ AWWB \to AWB \to XB \to W$
	Ovo rešenje osvaja $25$ poena.
