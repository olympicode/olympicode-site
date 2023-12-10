---
hide:
  - toc
---

# 5 - Planine

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Drevni programer Cep Lu Splus provodi dane mrzeći žalbe i mrzeći provođenje dana u mržnji. Povremeno mu dolaze sećanja na drevna vremena kada je bio član Komisije i odbijao žalbe najbolje od svih. Jednom, u ta vremena, dobio je izuzetno neosnovanu žalbu i dok je hodao drevnom planinom u potrazi za znakom da li da je prvo pročita ili prvo odbije -- žalba mu je ispala iz ranca i bi zauvek izgubljena. Od tada ga ovo mrsko sećanje neprestano progoni i zbog toga ne može da spava.
	
	Ali sada ste došli vi, zaštitnici takmičara koji se žale, i odlučili da pronađete planinu na kojoj je izgubljena žalba. Poznato je da je Cep tog sudbonosnog dana bio u oblasti koja liči na **kvadratnu matricu dimenzija** $N \times N$ čije svako polje predstavlja neku planinu određene visine. Kako Cep mrzi niske planine i kolone, **planina na kojoj je on bio tog dana je strogo viša od svih ostalih planina iz svoje vrste.** Analogno, kako Cep mrzi slanu plazmu i radne subote, **ta planina je ujedno i strogo niža od svih ostalih planina iz svoje kolone**.
	
	Loša vest je što vi ne znate visine planina a još gora što Cep zna. No, njegova mržnja prema mrskim sećanjima i nesanici je blago jača od mržnje prema vama i **on će vam iskreno odgovarati na pitanja oblika "kolika je visina planine koja se nalazi u $i$-toj vrsti i $j$-toj koloni?"**. Jasno, Cep mrzi drevni broj $K$ i ne želite da znate šta će se desiti ukoliko mu postavite više od $K$ pitanja.
	
	**Pronađite bar jednu planinu na kojoj je mogla biti izgubljena žalba ili konstatujte da takva planina ne postoji postavljajući ne više od $K$ pitanja.**  Neka izgubljena žalba konačno bude i formalno odbijena...
	
	## Opisi funkcija
	
	Potrebno je da implementirate funkciju
	
	* $Nadji(N, K)$
	
	koja treba da odredi da li se u matrici planina sa $N$ vrsta i $N$ kolona nalazi planina koja je strogo veća od svih ostalih planina iz svoje vrste i strogo manja od svih ostalih planina iz svoje kolone. **Ova funkcija mora da vrati niz (vektor) dužine 2 koji sadrži, redom, brojeve $i$ i $j$ koji označavaju da je tražena planina u preseku $i$-te vrste i $j$-te kolone**. Vrste i kolone su indeksirane od 1. **Ukoliko ima više rešenja, vratiti bilo koje; ukoliko nema rešenja vratiti niz sa dve nule.**
	
	Na raspolaganju imate funkciju 
	
	 *  $Pitaj(i, j)$
	
	**koju smete pozvati najviše $K$ puta.** Ova funkcija vraća visinu planine u preseku $i$-te vrste i $j$-te kolone. Ukoliko su koordinate $i$ i $j$ van opsega, funkcija će vratiti $-1$. 
	
	## Primer
	
	Neka je $N = 3$, $K = 9$ i neka su visine planina u matrici:
	
	~~~
	3 9 9
	2 2 7
	7 5 8
	~~~
	
	Za npr. upit $Pitaj(2, 1)$, odgovor bi bio $2$; za upit $Pitaj(2, 3)$ odgovor bi bio $7$; za upit $Pitaj(3, 3)$ odgovor bi bio $8$ itd. Jedino rešenje za ovaj primer je planina u preseku druge vrste i treće kolone (visina 7) i vaša funkcija mora da vrati niz $(2, 3)$ koristeći ne više od $9$ upita.
	
	## Ograničenja
	
	+ Visine svih planina su prirodni brojevi iz segmenta $[1, 10^9]$.
	
	## Podzadaci
	
	+ Podzadatak 1 [4 poena]: $N = 100$, $K = 10.000$
	+ Podzadatak 2 [9 poena]: $N = 1.000$, $K = 1.000.000$
	+ Podzadatak 3 [12 poena]: $N = 1.000$, $K = 5.000$, visine planina su $1$, $2$ ili $3$
	+ Podzadatak 4 [18 poena]: $N = 1.000$, $K = 501.500$
	+ Podzadatak 5 [19 poena]: $N = 2.048$, $K = 360.000$
	+ Podzadatak 6 [14 poena]: $N = 3.000$, $K = 12.000$
	+ Podzadatak 7 [24 poena]: $N = 100.000$, $K = 400.000$
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno jedan fajl `planine.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`std::vector<int> Nadji(int N, int K);`
	
	Vaša funkcija može koristiti funkciju
	
	`int Pitaj(int i, int j);`
	
	Da bi funkcija `Pitaj` bila "vidljiva" vašoj funkciji `Nadji`, potrebno je dodati liniju `#include "code.h"` na početku fajla koji sadrži implementaciju funkcije `Nadji`.
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđeni program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu brojeve $N$ i $K$
	+ U narednih $N$ redova po $N$ brojeva koji predstavljaju visine planina
	
	a zatim poziva vašu funkciju sa učitanim parametrima $N$ i $K$. Na kraju, na standardni izlaz štampa, redom, brojeve $x$, $y$ i $T$, gde su $x$ i $y$ redni broj vrste i kolone koje je vratila vaša funkcija a $T$ broj poziva funkciji  `Pitaj`. Kodove ovih programa možete menjati po potrebi. Ne garantuje se da će za testiranje biti korišćena baš ova verzija programa `grader.cpp`.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Aleksandar Zlateski |
	
	## Analiza
	
	Potrebno je u kvadratnoj matrici $A$ pronaći element koji je strogo najveći u svojoj vrsti i strogo najmanji u svojoj koloni -- nazovimo takav element (ukoliko postoji) **sedlo** (to je, inače, standarni termin). Za početak primetimo da ukoliko sedlo postoji, onda je jedinstveno; zaista, pretpostavimo da su $A_{i,j}$ i $A_{k,l}$ sedla. Očigledno, $i \neq k$ i $j \neq l$. Ukoliko je $A_{i,j} \leq A_{k,l}$, tada, zbog definicije sedla, $A_{i,j} > A_{i,l} > A_{k,l}$ što je kontradikcija; za $A_{i,j} > A_{k,l}$ ponovo dobijamo kontradikciju preko $A_{i,j} < A_{k,j} < A_{k,l}$ pa je nemoguće da postoje dva ili više sedla.
	
	Iz prethodnog razmatranja sledi: ukoliko su nam poznate vrednosti neka dva polja (npr. $A_{i,j}$ i $A_{k,l}$), možemo eliminasti bar jedno od njih kao potencijalnog kandidata za sedlo upitom nad najviše jednim dodatnim poljem ($A_{i,l}$ ili $A_{k,j}$). Dakle, proizvoljnih $M$ potencijalnih kandidata za sedlo (za koje znamo vrednosti) možemo svesti na samo $1$ uz ne više od $M-1$ pitanja koriteći ovaj metod koji ćemo jednostavno zvati *Eliminacija*.
	
	**Podzadaci 1 i 2:** Ovde je $K = N^2$ pa jednostavno možemo pitati za vrednosti svih polja i naći sedlo u poznatoj matrici u složenosti $O(N^3)$ ukoliko za svako polje prolazimo celu njegovu vrstu i kolonu ili u složenosti $O(N^2)$ ukoliko prekalkulišemo maksimume po vrstama i minimume po kolonama.
	
	**Podzadatak 3:** Kako su vrednosti iz skupa $\{1,2,3\}$, jasno je da element $A_{i,j}$ može biti sedlo ako i samo ako je $A_{i,j} = 2$, svi ostali elementi u njegovoj vrsti su $1$ i svi ostali elementi u njegovoj koloni su $3$. Prema tome, ukoliko upitamo za vrednost $A_{i,j}$ i dobijemo vrednost $1$, eliminisali smo celu $j$-tu kolonu (tamo ne može biti sedlo), ako dobijemo vrednost $3$ -- eliminisali smo celu $i$-tu vrstu, a ako dobijemo vrednost $2$ - eliminisali smo celu $i$-tu vrstu i $j$-tu kolonu osim potencijalno baš elementa $A_{i,j}$. Upite možemo postavljati tako da u svakom upitu eliminišemo bar jednu vrstu ili kolonu pa ćemo nakon najviše $2N$ upita eliminisati sve vrste i kolone i ostaće nam najviše $N$ polja koja mogu biti potencijalna sedla. Sada primenimo *Eliminaciju* (najviše još $N$ upita) i još najviše $2N$ upita za proveru da li je preostali element zaista sedlo (može se pokazati da je za ovaj metod gornja granica za broj upita zapravo $4N$ umesto $5N$).
	
	**Podzadatak 4:** Postavimo upite za sve elemente sa glavne dijagonale i **permutujmo vrste i kolone tako da važi** $A_{1,1} \leq A_{2,2} \leq \ldots \leq A_{N,N}$ (ovo nije problem, dovoljno je samo zapamtiti te permutacije i za svako naredno $Pitaj(i,j)$ zapravo postavljati $Pitaj(row[i], col[j])$). U novodobijenoj matrici, nijedan element ispod glavne dijagonale ne može biti sedlo (nemoguće da za $i > j$ važi $A_{i,j} > A_{i,i}$ i $A_{i,j} < A_{j,j}$ jer $A_{j,j} \leq A_{i,i}$) pa sedlo možemo tražiti samo na glavnoj dijagonali i iznad, pitajući za vrednosti sve kandidate (njih $\frac{N(N+1)}{2}$) i primenjujući *Eliminaciju* (pokazati da nam prilikom *Eliminacije* nikada neće trebati vrednosti elemenata ispod glavne dijagonale jer možemo koristiti poredak na njoj!). Ovaj deo možemo i jednostavnije, nalazeći sedlo kao u Podzadatku 2 ne koristeći elemente ispod glavne dijagonale (pokazati da ćemo i u slučaju "polu-matrice" sa soritranom dijagonalom dobiti najviše jednog kandidata!). Kada dobijemo jedinstvenog kandidata, dovoljno je još $N-1$ upita za proveru jer je najviše toliko polja iz njegove vrste i kolone (od njih $2N-1$) ispod glavne dijagonale. Dakle, treba nam $\frac{N(N+1)}{2} + N - 1$ upita, što se uklapa u ograničenja.
	
	**Podzadatak 5:** U prethodnom podzadatku, umesto da pitamo za sva polja iznad glavne dijagonale, možemo npr. rekurzivno primeniti logiku za gornji-desni kvadrat (i opet pitati samo oko polovinu svih elemenata u njemu). Preciznije, radimo sledeće
	 - Ukoliko je trenutni kvadrat dimenzija $1 \times 1$ pitamo i vratimo to polje kao potencijalnog kandidata; inače
	 - Pitamo za sve elemente glavne dijagonale trenutnog kvadrata i permutujemo vrste/kolone tako da važi poredak kao u prethodnom podzadatku
	 - Rekurzivno ponovimo postupak za gornji-levi, donji-desni i gornji-desni podkvadrat (za prva dva postavimo marker da ne moramo pitati/sortirati dijagonalu jer je već sortirana kao deo originalne) i od 3 dobijena kandidata *Eliminacijom* vratimo samo jedan.
	
	Ako je $T(N)$ broj poziva $Pitaj$ ovog algoritma za kvadrat dimenzije $N \times N$, nije teško zaključiti da važi $T(1) = 1$ i $T(N) = 3T(\lceil \frac{N}{2} \rceil)$ za $N > 1$ (kako ima puno "preklapanja" dijagonala, možemo zamisliti da zapravo ne pitamo za polja osim ako je kvadrat $1 \times 1$) pa je $T(N) = 3^{\log_2 N} = N^{\log_2 3}$ (polja koja pitamo obrazuju neku vrstu fraktala a implementacija je blago zgodnija jer je $N$ stepen dvojke). Za *Eliminaciju* nam u najgorem slučaju treba još toliko upita (a u praksi mnogo manje zbog preklapanja) i računajući konačnu proveru to je najviše $2\cdot N^{\log_2 3} + 2N$ upita, što se uklapa u ograničenja.
	
	**Podzadaci 6 i 7:** Nazovimo skup polja $S$ (matrice) *dobrim* ukoliko nikoja dva polja iz $S$ nisu u istoj vrsti ili koloni i ukoliko se sedlo (ukoliko postoji) cele matrice nalazi u preseku vrste u kojoj je neki element iz $S$ i kolone u kojoj je neki element iz $S$. Npr. jedan dobar skup je $D = \{(1,1), (2,2), \ldots, (N,N)\}$. 
	
	$(*)$ Primetimo da ako je $S$ dobar skup, tada sedlo ne sme biti veće od najvećeg elementa iz $S$ i ne sme biti manje od najmanjeg elementa iz $S$. Zaista, kako sedlo pripada nekoj koloni iz $S$, ono je manje ili jednako od bar jednog elementa iz $S$ pa i od maksimuma; slično i za minimum.
	
	Neka je $S$ proizvoljan dobar skup i neka je $(i, j) \in S$ takvo da je $A_{i,j}$ najmanja vrednost od svih vrednosti iz $S$ a $(k, l) \in S$ takvo da je $A_{k,l}$ najveća vrednost od svih vrednosti iz $S$. Od dobrog skupa $S$ možemo dobiti dobar skup sa jednim elementom manje na sledeći način: pitamo za vrednost elementa $A_{i,l}$ i razlikujemo 3 slučaja:
	
	 - $A_{i,l} \leq A_{i,j}$: Ako je sedlo u koloni $l$ onda je ono manje od $A_{i,l}$ a samim tim i od $A_{i,j}$ tj. od svih elemenata skupa $S$ što je nemoguće zbog $(*)$ . Dakle, u koloni $l$ nema sedla. Sa druge strane, u vrsti $k$ je jedini kandidat za sedlo $A_{k,l}$ (inače bi sedlo moralo biti veće od svih elemenata iz $S$ što je nemoguće zbog $(*)$ ) ali već smo zaključili da u koloni $l$ nema sedla pa sedlo nije ni u vrsti $k$. Dakle, izbacivanjem elementa $(k, l)$ iz $S$ opet dobijamo dobar skup.
	 - $A_{k,l} \leq A_{i,l}$: Analognim razmatranjem kao u prethodnom slučaju, dobijamo da se izbacivanjem elementa $(i, j)$ iz $S$ opet dobija dobar skup.
	 - $A_{i,j} < A_{i,l} < A_{k,l}$: Koristeći $(*)$ kao u prethodnim slučajevima, dobijamo da je $A_{i,j}$ jedini kandidat za sedlo u koloni $j$ i da je $A_{k,l}$ jedini kandidat za sedlo u vrsti $k$. Međutim, $A_{i,j}$ i $A_{k,l}$ ne mogu biti sedla zbog, redom, $A_{i,j} < A_{i,l}$ i $A_{i,l} < A_{k,l}$ pa sledi da sedlo nije ni u vrsti $k$ ni u koloni $j$. Ovu vrstu i kolonu možemo izbaciti tako što iz skupa $S$ izbacimo elemente $(i, j)$ i $(k, l)$ ali ubacimo element $(i, l)$ (jer moramo zadržati $i$-tu vrstu i $l$-tu kolonu). Novodobijeni skup je dobar i sadrži element manje.
	
	Kada dobijemo dobar skup sa jednim elementom, on je jedini kandidat za sedlo. Dakle, algoritam je sledeći: krenemo od npr. dobrog skupa sa dijagonalnim elementima $D$ (N upita), svedemo ga na dobar skup sa jednim elementom pomoću dodatnih $N-1$ upita i na kraju potrošimo još najviše $2N$ upita za proveru. U zavisnosti da li minimum/maksimum u svakom koraku tražimo u $O(N)$ (trivijalno) ili u $O(\log N)$ (uz pomoć neke strukture), ovo prolazi za prvih 6 ili za svih 7 podzadataka.
	
	**Rešenje sa očekivanim brojem upita reda $O(N)$:** Primetimo da ukoliko znamo vrednosti neka dva polja (npr. $A_{i,j}$ i $A_{k,l}$) možemo eliminisati bar jedno od polja $A_{i,j}, A_{k,l}, A_{i, l}, A_{k,j}$ kao potencijalnog kandidata za sedlo bez ikakvih dodatnih upita (npr. ako je $A_{i,j} \leq A_{k,l}$, možemo zaključiti da $A_{j,k}$  ne može biti sedlo iako mu možda ne znamo vrednost). Prema tome, ukoliko smo postavili $X$ upita, teoretski možemo eliminisati $\frac{X(X-1)}{2}$ polja gledajući svaki par upita. Naravno, ovde može doći do puno preklapanja (različiti parovi upita eliminišu isto polje) ali se može pokazati (a i intuitivno je jasno) da je očekivani broj upita (ako ih postavljamo random) potreban za eliminaciju svih $N^2$ polja (osim eventualno jednog) reda veličine $O(N)$. Dodatno, upiti ne moraju biti postavljani bilo kako već u svakom koraku pitati samo neko trenutno ne-eliminisano polje (i pomoću njega i prethodnih upita raditi pomenutu elminaciju); ukoliko ostane $O(N)$ ne-eliminisanih polja u nekom trenutku, možda je bolje prebaciti se na standardnu *Eliminaciju* itd.
	
	Ovaj pristup, uz eventualnu randomizaciju ili bolje odabrani redosled upita, prolazi za Podzadatke 1, 2, 4 i 5 a često i za 3 (zbog specifičnih vrednosti i malo veće konstante za dozvoljeni broj upita u odnosu na Podzadatke 6 i 7). Sa druge strane ovo (verovatno) ne može rešiti Podzadatak 6 (zbog strožeg ograničenja u broju upita i eventualno memorijskog ograničenja) kao ni Podzadatak 7 (jer je složenost $O(N^2)$). 
	
	
	
	``` cpp title="05_planine.cpp" linenums="1"
	#include "code.h"
	#include <set>
	
	struct field
	{
		int i, j, val;
		field(int _i, int _j, int _val)
		{
			i = _i; j = _j; val = _val;
		}
	};
	
	struct cmp
	{
		bool operator () (const field& A, const field& B)
		{
			if (A.val != B.val)
				return (A.val < B.val);
			if (A.i != B.i)
				return (A.i < B.i);
			return (A.j < B.j);
		}
	};
	
	std::set<field, cmp> heap;
	
	std::vector<int> Nadji(int N, int K)
	{
		heap.clear();
		for (int i = 1; i <= N; i++)
		{
			int val = Pitaj(i, i);
			heap.insert(field(i, i, val));
		}
	
		while (heap.size() > 1)
		{
			field minF = *heap.begin();
			field maxF = *(--heap.end());
	
			int i = minF.i;
			int j = minF.j;
			int k = maxF.i;
			int l = maxF.j;
	
			int val = Pitaj(i, l);
	
			if (val <= minF.val)
			{
				heap.erase(--heap.end());
			}
			else if (val >= maxF.val)
			{
				heap.erase(heap.begin());
			}
			else
			{
				heap.erase(--heap.end());
				heap.erase(heap.begin());
				heap.insert(field(i, l, val));
			}
		}
	
		field saddle = *heap.begin();
	
		int I = saddle.i;
		int J = saddle.j;
		for (int i = 1; i <= N && I != 0 && J != 0; i++)
		{
			if (i != I && Pitaj(i, J) <= saddle.val)
			{
				I = 0; J = 0;
			}
		}
		for (int j = 1; j <= N && I != 0 && J != 0; j++)
		{
			if (j != J && Pitaj(I, j) >= saddle.val)
			{
				I = 0; J = 0;
			}
		}
	
		std::vector<int> out;
		out.push_back(I);
		out.push_back(J);
		return out;
	}

	```
