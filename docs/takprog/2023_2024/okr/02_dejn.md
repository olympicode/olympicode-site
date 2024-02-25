---
hide:
  - toc
---

# B2 - Dejn

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Policajac Dejn važi za vrlo strogog šefa u policijskoj stanici. Ipak, jedno je održavati autoritet u stanici, a drugo u kući sa nestašnim sinom tinejdžerom Petrućijem. Dejnu najviše smeta kada mu sin u pola noću ulazi u stan i probudi ga, pa on ne može da se uspava po drugi put. U pokušaju da zavede red u sopstvenom domu, Dejn je instalirao senzor koji beleži kada je neko ušao u stan ili izašao iz stana.
	
	Dejn uključuje senzor uveče, dok je Petrući još uvek u stanu, a isključuje ujutru pred posao, kada mu sin uveliko spava u sobi. Po isključenju, senzor mu daje niz $t$ od $n$ brojeva. Član $t_i$ tog niza je negativan ukoliko je reč o ulasku u stan, a pozitivan ukoliko je reč o izlasku iz stana. Apsolutna vrednost člana $t_i$ označava trenutak u kom se akcija ulaska ili izlaska desila.
	
	Petrući je opasan programer-haker i redovno upada u vezu sa senzorom i pokušava da omete Dejnovu akciju! Naime, pre nego što Dejn preuzme niz, njegov sin izmeša taj niz. Vaš zadatak je da pomognete Dejnu da ustanovi da li je niz koji dobio ispravan niz ulazaka i izlazaka iz stana u nekom poretku, i ukoliko jeste, da izračunate koliko dugo je Dejnov sin bio van stana.
	
	Pretpostavimo da postoji raspored članova niza $t$ tako da on predstavlja ispravnu sekvencu ulazaka i izlazaka Petrućija iz stana. Ako je Petrući napustio stan u trenutku $t_1$, i vratio se u stan u trenutku $t_2$, onda Dejn računa da je Petrući proveo $t_2 - t_1$ trenutaka van stana.
	
	## Opis ulaza
	
	U prvoj liniji ulaza nalazi se prirodan broj $T$ – broj test primera.
	
	Svaki test primer je u sledećem formatu:
	
	U prvoj liniji test primera nalazi se prirodan broj $n$ – dužina niza $t$.
	
	U drugoj liniji test primera se nalazi niz od $n$ celih brojeva $t$ – gde ceo broj $t_i$ predstavlja Petrućijev izlazak iz stana u trenutku $t_i$ ukoliko je $t_i > 0$, odnosno Petrućijev ulazak u stan u trenutku $-t_i$, ukoliko je $t_i < 0$.
	
	
	## Opis izlaza
	
	Za svaki od $T$ test primera ispisati po jednu liniju izlaza u sledećem formatu:
	
	Ukoliko postoji raspored elemenata niza $t$ tako da on predstavlja ispravnu sekvencu Petrućijevih ulazaka i izlazaka iz stana, ispisati koliko trenutaka je Dejnov sin proveo van stana. U suprotnom, ispisati `-1`.
	
	
	## Primer 1
	
	
	### Ulaz
	
	
	```
	1
	6
	10 3 -5 7 -8 -15
	```
	
	
	
	### Izlaz
	
	
	```
	8
	```
	
	
	### Objašnjenje
	
	Senzor detektuje izlaske u trenucima: $3$, $7$ i $10$, a ulaske u trenucima $5$, $8$ i $15$. Postoji ispravna sekvenca ulazaka i izlazaka iz stana u toku noći. Petrući je prvo izašao iz stana u trenutku $3$, zatim se vratio u stan u trenutku $5$. Ponovo je izašao iz stana u trenutku $7$ i vratio se u trenutku $8$. Na kraju, izašao je u trenutku $10$ i ušao u stan u trenutku $15$. Ukupno je van stana proveo $(5-3) + (8-7) + (15-10) = 8$ trenutaka.
	
	## Primer 2
	
	
	### Ulaz
	
	
	```
	1
	4
	8 -2 -15 17
	```
	
	
	
	### Izlaz
	
	
	```
	-1
	```
	
	### Objašnjenje
	
	Iz postavke zadatka znamo da je Petrući na početku večeri, kada Dejn uključi senzor, u svojoj sobi u stanu. Nije moguće da se Petrući vrati u stan u trenutku $2$, jer prethodno ga nije ni napuštao.
	
	## Primer 3
	
	
	### Ulaz
	
	
	```
	2
	5
	10 -11 5 -6 15
	8
	12 -14 15 -15 15 -15 20 -21
	```
	
	
	
	### Izlaz
	
	
	```
	-1
	3
	```
	
	### Objašnjenje
	
	U prvom test primeru, iz postavke zadatka znamo da je Petrući ujutru, kada Dejn isključi senzor, u svojoj sobi u stanu. Nije moguće da Petrući u trenutku $15$ napusti stan, jer se nikad kasnije ne vraća u njega.
	
	U drugom test primeru, Petrući izlazi iz stana u trenutku $12$ i vraća se u stan u trenutku $14$, pa je ukupno bio $2$ trenutka van stana. Zatim je ulazio i izlazio u trenutku $15$ po dva puta i tu je ukupno bio $0$ trenutaka van stana. Na kraju, Petrući je izašao iz stana u trenutku $20$ i vratio se u stan u trenutku $21$, što znači da je bio van stana jedan trenutak. Kada sve saberemo, Petrući je van stana ukupno bio $2+0+1=3$ trenutaka.
	
	## Ograničenja
	* $1 \leq T \leq 5$
	* $1 \leq n \leq 10^5$
	* $1 \leq \mid t_i \mid \leq 10^9$, za $1 \leq i \leq n$
	  
	
	Test primeri su podeljeni u tri disjunktne grupe:
	
	* U test primerima vrednim 30 poena: $1 \leq n \leq 1000$;
	* U test primerima vrednim 30 poena: $1 \leq \mid t_i \mid \leq 10^5$;
	* U test primerima vrednim 40 poena: Bez dodatnih ograničenja.
	
	## Napomena
	
	
	Primetite da je moguće da Petrući u istom trenutku više puta ulazi i izlazi iz stana (desi se da je zaboravio novčanik, parfem, ...). 
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Andrej Ivašković | Marko Milenković | Vladimir Milovanović | Andrej Ivašković |
	
	## Glavno rešenje
	
	Pošto je već dat celobrojni niz $t$ u kome članovi niza $t_i$ ako su strogo pozitivni, $t_i>0$, predstavljaju izlazak, a ukoliko su negativni, $t_i<0$ ulazak, to je najsvrsishodnije najpre ispitati da li je broj izlazaka jednak broju ulazaka i ispisati `-1` ako se utvrdi da broj strogo pozitivnih članova ne odgovara broju negativnih članova niza. Ovo prebrajanje pozitivnih i negativnih članova moguće je izvesti jednim prolaskom kroz sve članove niza, odnosno u vremenskoj složenosti $\mathcal{O}(n)$, gde je $n$ broj članova niza.
	
	Da bi se olakšalo dalje ispitivanje zadati niz $t$ se može zatim sortirati po apsolutnoj vrednosti bez mutiranja istog tako da se dobije monotono rastući niz, tačnije monotono neopadajući niz prema apsolutnoj vrednosti jer se vrednosti u nizu mogu ponavljati. Sortiranje je moguće izvršti u vremenskoj složenosti $\mathcal{O}(n \log n)$ koristeći se nekim od efikasnih algoritama ili bibliotečkim funkcijama koje ih koriste.
	
	Kada je niz sortiran, na jednostavan način moguće je dovršiti proveru da li je on zaista i ispravan. Naime, svi jedinstveni članovi niza na parnim indeksima (uključujući i prvi) moraju biti pozitivni, a na neparnim (uključujući i poslednji) negativni, poštujući konvenciju da prvi član niza ima nulti indeks. Primetiti da svi ispravni nizovi imaju parnu dužinu (na osnovu uslova da broj pozitivnih članova mora biti jednak broju negativnih), odnosno da je $n$ deljivo sa dva. Stoga, ako su se prvi izlazak i poslednji ulazak desili u jedinstvenim vremenskim trenucima to je prvi član sortiranog niza pozitivan, a poslednji negativan.
	
	Pri proveri ispravnosti niza, neophodno je u obzir uzeti i slučajeve u kojima se izlasci i ulasci dešavaju u istom vremenskom trenutku jer prilikom sortiranja ovih trenutaka po apsolutnoj vrednosti u opštem slučaju ne dobijamo podniz alternirajućih znakovnih vrednosti. Kada se konačno utvrdi ispravnost niza, ukupno vreme se računa tako što se sukcesivno od svakog trenutka ulaska oduzme njemu odgovarajući, to jest njemu prethodeći trenutak izlaska i napravi zbir svih ovakvih razlika. Traženu sumu razlika apsolutnih vrednosti svih uzastopnih neparnih i parnih članova već sortiranog niza takođe je moguće pronaći u linearnoj vremenskoj složenosti $\mathcal{O}(n)$, baš kao i proveru ispravnosti tog niza.
	
	Konačno, kako je najsloženija operacija u prethodno opisanom rešenju zapravo algoritam sortiranja, to $\mathcal{O}(n \log n)$ predstavlja ukupnu vremensku složenost rešenja ovog zadatka koja je loglinearna po dužini ulaznog niza. Iako je zadatak bilo moguće rešiti i bez upotrebe sortiranja u linearnoj vremenskoj složenosti $\mathcal{O}(n)$ koristeći se nekim malo naprednijim strukturama podataka, ovo rešenje se nije zahtevalo za maksimalan broj poena na ovom nivou takmičenja.
	
	
	``` cpp title="02_dejn.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	#define int ll
	typedef long long ll;
	typedef long double ld;
	typedef pair<int, int> pi;
	typedef pair<ll, ll> pl;
	typedef vector<int> vi;
	typedef vector<ll> vl;
	typedef vector<double> vd;
	typedef vector<bool> vb;
	typedef vector<char> vc;
	typedef vector<string> vs;
	typedef vector<pi> vp;
	typedef vector<pl> vpl;
	
	bool cmp(int a, int b){
		return abs(a) < abs(b);
	}
	
	signed main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(nullptr); 
		cout.tie(nullptr); 
		cerr.tie(nullptr);	
	
		int t;
		cin >> t;
	
		for (int e = 0; e < t; ++e){
			int n;
			cin >> n;
	
			map<int, int> m;
			for (int i = 0; i < n; ++i){
				int x;
				cin >> x;
	
				if (m[-1 * x] > 0){
					--m[-1 * x];
				} else {
					m[x]++;
				}
			}
	
			bool ok = 1;
			vi a;
			for (auto& i : m){
				if (i.second > 1){
					ok = 0; break;
				}
	
				if (i.second == 0) continue;
				a.push_back(i.first);
			}
	
			sort(a.begin(), a.end(), cmp);
			n = a.size();
	
			if (n % 2 || !ok){
				cout << "-1\n";
				continue;
			}
	
			int sol = 0;
			for (int i = 0; i < n; ++i){
				if (i % 2 && a[i] > 0){
					ok = 0; break;
				}
	
				if (i % 2 == 0 && a[i] < 0){
					ok = 0; break;
				}
	
				if (i % 2){
					sol += -1 * a[i] -a[i-1];
				}
			}
	
			if (!ok) sol = -1;
			cout << sol << '\n';
		}
	}
	```
