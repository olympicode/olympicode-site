---
hide:
  - toc
---

# A3 - Pariz

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	Pariz je poznat po brojnim atrakcijama i znamenitostima koje se mogu videti u tom gradu. U poslednjoj predizbornoj kampanji, gradski oci Pariza su izgradili nove, lepe i moderne, pešačke puteve između atrakcija. Kako bi dalje finansirali svoju kampanju, smislili su i način kako mogu prevariti nesmotrene građane i turiste - __pešačke puteve su napravili jednosmernim__, i svakome ko se kreće u suprotnom smeru biće napisana kazna. Za svaku atrakciju u gradu, napravljen je __tačno jedan pešački put koji vodi do nje__.
	
	Ana će ove godine prvi put ići u Pariz, i sa svime ovime je dobro upoznata. Ona jako želi da isplanira svoj obilazak i da uopšte ne gubi vreme tamo. Na internetu je istražila apsolutno sve atrakcije, i svakoj je dodelila ocenu koliko joj se sviđa. Ipak, pošto atrakcija ima mnogo, a Ana mora i da spakuje stvari, moli vas da joj pomognete u planiranju obilaska. 
	
	Ana vam daje novu mapu Pariza gde su upisani svi pešački putevi, od koje do koje atrakcije vode, i koliko vremena traje pešačenje tim putem. Takođe će vam dati svoje ocene atrakcija, i ukupno vreme koje će provesti u Parizu. Vaš zadatak je da joj kažete __kolika je najveća ukupna lepota atrakcija koje ona može da obiđe__ (ukupna lepota je suma ocena svake atrakcije koju obiđe), tako da se Ana kreće samo novim pešačkim putevima. Ana svoj obilazak može početi od bilo koje atrakcije.
	
	Imajte u vidu da Ana kada obilazi atrakcije ne gubi ni malo vremena razgledajući, njoj je dovoljno samo da se slika za Instagram i da ide dalje. Upravo zato, moguće je da neke atrakcije obiđe i po više puta, a da su joj i dalje isto lepe kao što su joj bile i na početku (odnosno, ukoliko više puta obiđe istu atrakciju, svaki put će se njena ocena dodati na ukupnu lepotu puta).
	
	## Opis ulaza
	U prvoj liniji se nalaze dva prirodna broja $N$ i $T$ - broj atrakcija, i vreme koje će Ana provesti u Parizu.
	U drugoj liniji se nalazi $N$ prirodnih brojeva - ocene koje je Ana dala atrakcijama.
	U trećoj liniji se nalazi $N$ prirodnih brojeva - niz $X_i$.
	U četvrtoj liniji se nalazi $N$ prirodnih brojeva - niz $D_i$.
	Nizovi $X$ i $D$ opisuju jednosmerne pešačke puteve - put koji vodi do atrakcije $i$ počinje od atrakcije $X_i$, i potrebno je $D_i$ vremena da se prepešači.
	Atrakcije su indeksirane brojevima od $1$ do $N$.
	
	## Opis izlaza
	U prvi i jedini red izlaza ispisati jedan broj - najveću ukupnu lepotu atrakcija koje Ana može da obiđe.
	
	## Primer 1
	
	### Ulaz
	
	~~~
	5 7
	7 3 1 4 8
	4 3 5 2 1
	3 2 4 1 7
	~~~
	
	### Izlaz
	
	~~~
	16
	~~~
	
	### Objašnjenje primera
	U ovom primeru postoji $5$ atrakcija, a pešački putevi koji postoje su $4 \rightarrow 1$ dužine $3$, $3 \rightarrow 2$ dužine $2$, $5 \rightarrow 3$ dužine $4$, $2 \rightarrow 4$ dužine $1$ i $1 \rightarrow 5$ dužine $7$.
	Vreme kojie će Ana provesti u Parizu je $7$, i za to vreme najveća ukupna lepota atrakcija koje može da obiđe je $16$ ako ide putem: $5 \rightarrow 3 \rightarrow 2 \rightarrow 4$.
	
	## Primer 2
	
	### Ulaz
	
	~~~
	6 200
	1 1 1 1 1 100
	3 1 2 5 4 5
	1 1 1 10 10 1
	~~~
	
	### Izlaz
	
	~~~
	201
	~~~
	
	
	### Objašnjenje primera
	Da bi ovde postigla najveću lepotu, Ana će se vrteti u krug između par atrakcija. Jedna mogućnost je da krene od $2$, a put bi bio $2 \rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow \ldots \rightarrow 1$
	
	## Ograničenja
	* $2 \leq N \leq 10^5$
	* $1 \leq T \leq 10^{12}$
	* $1 \leq A_i \leq 10^6$
	* $1 \leq D_i \leq 10^6$
	
	Postoje četiri podzadatka:
	
	* Podzadatak 1 [22 poena]: $N, T \leq 1000$.
	* Podzadatak 2 [17 poena]: $N \leq 1000$, i $T \leq 10^{12}$.
	* Podzadatak 3 [14 poena]: $D_i = 1$ za svako $i$, odnosno vreme potrebno da se svaki put prepešači je $1$.
	* Podzadatak 4 [23 poena]: Niz $X$ je permutacija brojeva od $1$ do $N$, odnosno iz svake atrakcije kreće tačno jedan put.
	* Podzadatak 5 [24 poena]: Nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dušan Zdravković | Dragan Urošević | Aleksa Milisavljević |
	
	## Analiza
	
	### Potproblem 1
	
	Pravolinijsko rešenje se dobija tako što se svaka atrakcija posmatra kao poslednja na turi koju je obišla Ana. Ako je fiksirana poslednja atrakcija, onda se kompletna tura dobija tako što se krene poslednje atrakcije i 'vraća unazad' pomerajući se svaki put do atrakcije od koje vodi jedini put do atrakcije u kojoj se trenutno nalazimo. Naravno, tokom pomeranja se sabiraju lepote atrakcija koje je Ana posetila. Postupak se prekida u trenutka kada bi se narednim korakom vraćanja premašilo ukupno vreme koje Ana ima na raspolaganju.
	
	### Potproblem 2
	
	Rešenje se dobija uz malu doradu rešenja za potproblem 1. Polazeći od atrakcije $A$ i vraćajući se duž puta koji vodi do trenutne atrakcije, pre ili kasnije ćemo zatvoriti petlju. Može se odrediti vreme da se obiđu sve atrakcije na petlji, a zatim i koliko puta se ta petlja može obići a da se ne premaši vreme $T$. Na kraju ako je ostalo vremena treba započeti još jedan prolaz kroz petlju i zaustaviti se u trenutku kada vreme premaši vreme $T$. Naravno, tokom postupka je određivana suma lepota atrakcija koje su obiđene.
	
	### Potproblem 3
	
	Ovaj potproblem se može rešiti kao i potproblem 2, pri čemu ne krećemo svaki put od atrakcije koja je na kraju ture, već koristimo rezultate od prethodnog obilaska. 
	
	
	### Potproblem 4
	
	Ako je niz $X$ permutacija brojeva od $1$ do $N$, onda svi putevi obrazuju kolekciju petlji (ciklusa). Za svaku petlju je dovoljno odrediti čvor od koga treba krenuti kako bi se dobila maksimalna suma lepota atrakcija koje su posećene. To se može obaviti i linearnom vremenu (linearnom po broju atrakcija na petlji), korišćenjem dva pokazivača (indeksa): jedan za početak ture, a drugi za kraj ture.
	
	### Potproblem 5
	
	 Maksimalni broj poena se dobija tako što se za svaku atrakciju $A$ odredi suma lepota atrakcija (kao i vreme potrebno da se obiđu te atrakcije) na turi koja se završava na atrakcija $A$ i čija je dužina $2^I$ ($I=0, 1, 2, ... \lfloor \log T\rfloor$). Dužina ture je jednaka broju atrakcija na turi. To se može obaviti u složenosti $O(N \times \log T)$. Naime, ako znamo sume atrakcija za ture dužine $2^{I-1}$, onda sumu za turu dužine $2^I$ koja se završava na atrakciji $A$ dobijamo tako što nadovežemo dve ture dužine $2^{I-1}$: turu koja se završava na atrakciji $A$ i turu koja se završava u čvoru od koga vodi put do početka ture dužine $2^{I-1}$ koja se završava na atrakciji $A$. 
	
	Kada smo  odredili opisane sume tura, onda je potrebno za svaku atrakciju odrediti turu maksimalne dužine koja se završava u toj atrakciji. To obavljamo tako što kombinujemo ture određene u prethodnom pasusu. Počinjemo sa turom dužine $2^{\lfloor\log T\rfloor}$. Ako je vreme potrebno za njen obilazak veće od dozvoljenog prepolovimo dužinu (tj. podelimo sa 2). Ako vreme nije veće, dodajemo tu turu na kompletnu turu, pomeramo se na atrakciju na kojoj ta tura počinje (tačnije na atrakciju koja prethodi atrakciji na kojoj ta tura počinje) i nastavljamo sa turom dvostruko kraćom od one koja je dodata. 
	
	   
	 
	
	``` cpp title="06_pariz.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	
	#define MAXN 111555
	#define MAXDEPTH 45
	
	long long a[MAXN], x[MAXN], d[MAXN];
	long long uka[MAXN][MAXDEPTH], ukd[MAXN][MAXDEPTH], sled[MAXN][MAXDEPTH], last[MAXN][MAXDEPTH];
	
	int main() {
	
	    int n;
	    long long t;
	
	    scanf("%d%lld", &n, &t);
	
	    for(int i=0; i<n; i++) {
	        for(int stp=1; stp<MAXDEPTH; stp++) {
	            ukd[i][stp] = -1;
	        }
	    }
	
	    for(int i=0; i<n; i++) {
	        scanf("%lld", &a[i]);
	        uka[i][0] = a[i];
	        ukd[i][0] = 0;
	    }
	
	    for(int i=0; i<n; i++) {
	        scanf("%lld", &x[i]);
	        x[i]--;
	        sled[i][0] = x[i];
	        last[i][0] = i;
	    }
	
	    for(int i=0; i<n; i++) {
	        scanf("%lld", &d[i]);
	    }
	
	    for(int stp=1; stp < MAXDEPTH; stp++) {
	        for(int i=0; i<n; i++) {
	
	            int j = sled[i][stp-1];
	            sled[i][stp] = sled[j][stp-1];
	            last[i][stp] = last[j][stp-1];
	
	            if (ukd[i][stp-1] == -1 || ukd[j][stp-1] == -1) continue;
	
	            long long td = ukd[i][stp-1] + ukd[j][stp-1] + d[ last[i][stp-1] ];
	            long long ta = uka[i][stp-1] + uka[j][stp-1];
	            if (td <= t) {
	                ukd[i][stp] = td;
	                uka[i][stp] = ta;
	            }
	        }
	    }
	
	    long long res = 0;
	    for(int i=0; i<n; i++) {
	        int stp = MAXDEPTH - 1;
	        int tr = i;
	        long long td = 0;
	        long long ta = 0;
	        while(stp >= 0) {
	            while(stp >= 0 && (ukd[tr][stp] == -1 || td + ukd[tr][stp]> t)) stp--;
	            if (stp < 0) break;  
	
	            ta += uka[tr][stp];
	            td += ukd[tr][stp]+d[last[tr][stp]];
	            tr = sled[tr][stp];
	
	            stp--;
	        }
	        
	        
	        res = max(res,ta);
	    }
	
	    printf("%lld\n", res);
	
	    return 0;
	}

	```
