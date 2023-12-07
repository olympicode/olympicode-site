---
hide:
  - toc
---

# 3 - Tačke

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	Dat vam je niz $A$ od $N$ tačaka u koordinatnoj ravni. Data je i tačka $P$. Potrebno je da odgovorite na $Q$ upita. Svaki upit je opisan sa po dva broja $L$ i $R$. Neka je $S$ skup tačaka $\{A_L, A_{L+1}, \dots A_R\}$. Dozvoljeno je primenjivati sledeću operaciju proizvoljan broj puta: uzeti dve tačke $H$ i $K$ iz skupa $S$ i u skup dodati jednu od tačaka koje se nalaze na duži $HK$. Odgovor na upit je `Da` ako tačka $P$ može da se nađe u skupu $S$ nakon nula ili više poteza, ili `Ne` u suprotnom.
	
	**Obratite pažnju na to da se koordinate tačaka u nizu $A$ mogu poklapati kao i da se koordinate tačke $P$ mogu poklapati sa koordinatama tačkaka iz niza $A$.**
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $\text{Resi}(N, Px, Py, X[\dots], Y[\dots], Q, L[\dots], R[\dots], O[\dots])$
	
	gde je:
	
	* $N$ broj tačaka u nizu.
	* $Px$ i $Py$ koordinate tačke $P$.
	* $X$ i $Y$ nizovi koji opisuju tačke iz niza $A$: $i$-ta tačka ima koordinate $X_i$ i $Y_i$.
	* $Q$ broj upita.
	* $L$ i $R$ nizovi koji opisuju upite.
	* $O$ niz `boolean` vrednosti u koji za svaki upit treba upisati `true` ako je odgovor `Da`, i `false` ako je odgovor `Ne`.
	
	**Svi nizovi su indeksirani od 1.**
	
	## Ograničenja
	* $1 \leq N, Q \leq 3 \times 10^5$
	* $1 \leq L_i \leq R_i \leq N$
	* Sve koordinate su celi brojevi iz intervala $[-10^9, 10^9]$
	
	## Podzadaci
	Test primeri su podeljeni u 7 podzadataka:
	
	* **[9 poena]:** $N, Q \leq 100$.
	* **[14 poena]:** $N, Q \leq 2500$.
	* **[12 poena]:** $N, Q \leq 10^5$, sve tačke su na X osi, odnosno, $Y_i = 0$, $Py = 0$.
	* **[16 poena]:** $N, Q \leq 10^5$, postoje dve prave tako da se svaka tačka iz niza $A$ nalazi na bar jednoj od njih.
	* **[17 poena]:** $N, Q \leq 6 \times 10^4$, sve koordinate su celi brojevi iz intervala $[-500, 500]$.
	* **[11 poena]:** $N, Q \leq 6 \times 10^4$.
	* **[21 poena]:** Bez dodatnih ograničenja.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `tacke.cpp` koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int Px, int Py, int *X, int *Y, int Q, int *L, int *R, bool *O);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova, ali ne smeju da pristupaju van njihovih granica.**
	
	Uz zadatak obezbeđen vam je "template" fajl `code.cpp` koji možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojeve $N$, $Px$ i $Py$.
	* U narednih $N$ redova po dva broja. U $i$-tom redu nalaze se brojevi $X_i$ i $Y_i$.
	* U narednom redu nalazi se broj $Q$.
	* U narednih $Q$ redova nalazi se po dva broja: $L_i$ i $R_i$.
	
	Zatim ovaj program poziva vašu funkciju i štampa odgovore na upite na standardni izlaz, po jedan u svakom redu. Ako je vaša funkcija upisala `true` kao vrednost $O_i$, u $i$-tom redu će se odštampati `Da`, a u suprotnom, u $i$-tom redu će se odštampati `Ne`.
	
	### Primer
	#### Ulaz
	```
	5 1 2
	0 0
	0 3
	3 3
	3 0
	0 0
	4
	1 3
	3 5
	2 4
	1 5
	```
	
	#### Izlaz
	```
	Da
	Ne
	Da
	Da
	```
	
	#### Objašnjenje
	1. upit: Počinjemo od skupa $S=\{(0, 0), (0, 3), (3, 3)\}$. Možemo da dodamo tačku $(1.5, 1.5)$ koja se nalazi na duži $HK$ za $H=(0, 0)$ i $K=(3, 3)$. Nakon toga možemo da dodamo tačku $P(1, 2)$ koja se nalazi na duži $HK$ za $H=(1.5, 1.5)$ i $K=(0, 3)$, pa je odgovor `Da`.
	2. upit: Počinjemo od skupa $S=\{(3, 3), (3, 0), (0, 0)\}$. Nikako nije moguće dodati tačku $P$, pa je odgovor `Ne`.
	3. upit: Počinjemo od skupa $S=\{(0, 3), (3, 3), (3, 0)\}$. Tačka $P(1, 2)$ se nalazi na duži $HK$ za $H=(0, 3)$ i $K=(3, 0)$, pa je odgovor `Da`.
	4. upit: Možemo dodati tačku $P$ na isti način kao kod prvog upita, pa je odgovor `Da`.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Tadija Šebez | Tadija Šebez | Tadija Šebez | Aleksa Milisavljević |
	
	Odgovor na upit je `Da` ako se tačka $P$ nalazi u unutrašnjosti ili na konveksnom omotaču podniza tačaka od $L$ do $R$ (sa specijalnim slučajem kada su sve tačke kolinearne i konveksni omotač je zapravo duž ili jedna tačka).
	
	## Rešenje kada je $N, Q \leq 100$
	Za svaki upit možemo u $O(N^2)$ da nađemo konveksni omotač i proverimo da li se tačka $P$ nalazi unutar ili na omotaču. Vremenska složenost je $O(QN^2)$.
	
	## Rešenje kada je $N, Q \leq 2500$
	Rešenje je isto kao za prošli podzadatak samo što je potreban efikasniji algoritam za nalaženje konveksnog omotača. Sa algoritmom u $O(NlogN)$ dobijamo vremensku složenost $O(QNlogN)$.
	
	## Rešenje kada je $N, Q \leq 10^5$ i sve tačke su na X osi.
	Konveksni omotač je zapravo duž na $X$ osi pa su nam bitne tačka sa najmanjom i tačka sa najvećom X koordinatom za svaki upit. Ako za pronalaženje minimuma i maksimuma koristimo segmentno stablo dobijamo vremensku složenost $O(QlogN)$.
	
	## Rešenje kada je $N, Q \leq 10^5$ i postoje dve prave tako da se svaka tačka iz niza $A$ nalazi na bar jednoj od njih
	Uzmimo 3 različite tačke. Bar jedan od 3 para ovih tačaka se sigurno nalazi na istoj pravoj. Isprobajmo sva tri para i proverimo da li su sve tačke koje nisu kolinearne sa trenutnim parom međusobno kolinearne. Na ovaj način ćemo naći dve prave koje sadrže sve tačke iz niza. Za svaki upit bitne su nam samo ekstremen tačke na ovim pravama i njih možemo brzo da nađemo za svaki upit uz pomoć segmentnog stabla. Na ovaj način dobijamo konveksni omotač sa najviše 4 tačke i jednostavno možemo da proverimo da li se tačka $P$ nalazi u njemu. Vremenska složenost ovog algoritma je $O(QlogN)$.
	
	## Rešenje kada je $N, Q \leq 6 \times 10^4$ i sve koordinate su celi brojevi iz intervala $[-500, 500]$
	Za skup tačaka sa celobrojnim koordinatama u kvadratu dimenzija $M \times M$ najveći broj tačaka na konveksnom omotaču je oko $M^{2/3}$. Rešenje za ovaj podzadatak je da čuvamo konveksne omotače u svakom čvoru segmentnog stabla i radimo njihova spajanja. Vremenska složenost je $O(QlogNM^{2/3})$. Ovo rešenje takođe prolazi i sve prethodne podzadatke.
	
	## Rešenje za 100 poena
	Za sako $i$ nađimo najmanju granicu $G_i$ tako da se tačka $P$ nalazi u konveksnom omotaču podniza od $i$ do $G_i$. Ako ne postoji takav podniz uzećemo $G_i=N+1$. Primetimo da je niz $G_i$ neopadajući, pa ga možemo naći primenom **two pointers** tehnike. Potrebna nam je još struktura podataka koja podržava operacije ubacivanja i izbacivanja tačaka i odgovara na pitanje da li je tačka $P$ unutar konveksnog omotača. Posmatrajmo slučaj kada se tačka $P$ nalazi u konveksnom omotaču nekog skupa tačaka. Za svaku pravu koja prolazi kroz $P$, postoje dve tačke koje su sa različitih strana te prave, ili postoji tačka koja je na toj pravoj. Postmatrajmo sada slčaj kada tačka $P$ nije u konveksnom omotaču nekog skupa tačaka. U ovom slučaju postoji prava koja prolazi kroz $P$ takva da su sve tačke iz skupa sa jedne njene strane. Posmatrajmo tačke iz ovog skupa sortirane kružno po uglu oko $P$. Ako postoji prava takva da su sve tačke sa jedne njene strane postoji ugao veći od 180 stepeni između dve susedne tačke, a u suprotnom ne postoji. Sada možemo da odgovaramo na pitanja da li se tačka $P$ nalazi u konveksnom omotaču skupa tačaka i da podržimo ubaivanje i izbacivanje tačaka tako što držimo tačke u $\text{std::set}$-u sortirane po uglu. Tačke možemo da poredimo po uglu ako gledamo u kojem kvadrantu se nalaze i ako gledamo znak vektorskog proizvoda za tačke u istom kvadrantu. Kada ubacujemo tačku dve tačke prestaju da budu susedne i dobijamo nova dva para susednih tačaka pa treba da ažuriramo informaciju o tome da li postoji ugao veći od 180 stepeni. Slično tako kod izbacivanja tačke izbacujemo dva para iz razmatranja i ubacujemo jedan. Jedan izuzetak na koji treba paziti je slučaj kada se neka tačka poklapa sa $P$ i možemo da čuvamo informaciju o broju takvih tačaka i da ih ne ubacujemo u $\text{std::set}$. Kada uz pomoć ove strukture uradimo **two pointers** i nađemo granice $G_i$, na upite lako možemo odgovoriti upoređivanjem $G_{L_i}$ i $R_i$. Vremenska složenost ovog rešenja je $O(NlogN)$
	
	``` cpp title="03_tacke.cpp" linenums="1"
	#include <bits/stdc++.h>
	using namespace std;
	
	#define ll long long
	#define mp make_pair
	
	struct pt{
		ll x,y;
		pt(){}
		pt(ll a,ll b):x(a),y(b){}
	};
	
	pt operator - (pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
	ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
	int part(pt a){return (a.y>0||(a.y==0&&a.x>0))?0:1;}
	bool operator < (pt a,pt b){
		return mp(part(a),(ll)0)<mp(part(b),cross(a,b));
	}
	bool operator == (pt a,pt b){return mp(a.x,a.y)==mp(b.x,b.y);}
	
	map<pt,int> pts;
	int cntZero=0,badAngles=0;
	
	bool bad(pt a,pt b){
		ll c=cross(a,b);
		if(c<0)return true;
		//if(c==0&&part(a)==part(b)){
		//	if(b<a)return true;
		//}
		return false;
	}
	
	void Add(pt a,pt b){
		//printf("Add (%lld %lld) (%lld %lld)\n",a.x,a.y,b.x,b.y);
		if(bad(a,b))badAngles++;
	}
	
	void Del(pt a,pt b){
		//printf("Del (%lld %lld) (%lld %lld)\n",a.x,a.y,b.x,b.y);
		if(bad(a,b))badAngles--;
	}
	
	void Add(pair<pt,int> a,pair<pt,int> b){
		Add(a.first,b.first);
	}
	
	void Del(pair<pt,int> a,pair<pt,int> b){
		Del(a.first,b.first);
	}
	
	map<pt,int>::iterator getPrev(map<pt,int>::iterator it){
		if(it==pts.begin())return prev(pts.end());
		else return prev(it);
	}
	
	map<pt,int>::iterator getNext(map<pt,int>::iterator it){
		if(next(it)==pts.end())return pts.begin();
		else return next(it);
	}
	
	void AddPoint(pt a){
		//printf("AddPt (%lld %lld)\n",a.x,a.y);
		if(a==pt(0,0)){
			cntZero++;
			return;
		}
		pts[a]++;
		auto it=pts.find(a);
		if(pts[a]==1){
			if(pts.size()>2)Del(*getPrev(it),*getNext(it));
			if(pts.size()>1)Add(*getPrev(it),*it);
			if(pts.size()>1)Add(*it,*getNext(it));
		}
	}
	
	void DelPoint(pt a){
		//printf("DelPt (%lld %lld)\n",a.x,a.y);
		if(a==pt(0,0)){
			cntZero--;
			return;
		}
		pts[a]--;
		auto it=pts.find(a);
		if(pts[a]==0){
			if(pts.size()>1)Del(*getPrev(it),*it);
			if(pts.size()>1)Del(*it,*getNext(it));
			if(pts.size()>2)Add(*getPrev(it),*getNext(it));
			pts.erase(it);
		}
	}
	
	bool IsOk(){
		return cntZero==0&&(pts.size()<=1||badAngles>0);
	}
	
	void Resi(int N, int Px, int Py, int *X, int *Y, int Q, int *L, int *R, bool *O){
		assert(1<=N && N<=300000);
		assert(1<=Q && Q<=300000);
		assert(-1000000000<=Px && Px<=1000000000);
		assert(-1000000000<=Py && Py<=1000000000);
		for(int i=1;i<=N;i++){
			assert(-1000000000<=X[i] && X[i]<=1000000000);
			assert(-1000000000<=Y[i] && Y[i]<=1000000000);
		}
		for(int i=1;i<=Q;i++){
			assert(1<=L[i] && L[i]<=R[i] && R[i]<=N);
		}
		pt P(Px,Py);
		vector<int> ptr(N+1,0);
		for(int i=1;i<=N;i++){
			int j=ptr[i-1];
			while(j<=N&&IsOk()){
				j++;
				if(j<=N)AddPoint(pt(X[j],Y[j])-P);
			}
			ptr[i]=j;
			//printf("%i %i badAngles:%i cntZero:%i : ",i,j,badAngles,cntZero);
			//for(auto p:pts)printf("(%lld %lld) ",p.x,p.y);printf("\n");
			DelPoint(pt(X[i],Y[i])-P);
		}
		for(int i=1;i<=Q;i++){
			//printf("%i: %i %i\n",i,ptr[L[i]],R[i]);
			if(ptr[L[i]]<=R[i])O[i]=true;
			else O[i]=false;
		}
	}

	```
