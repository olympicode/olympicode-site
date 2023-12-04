---
hide:
  - toc
---

# 1 - Mađarski krug

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 32MB |
	
	Erno Rubik je poznati mađarski izumitelj i arhitekta, najpoznatiji po tzv. Rubikovoj kocki. Međutim, malo je poznato da je on takođe izumeo krug, koji ćemo zvati “mađarski krug”. To je logička zagonetka u kojoj treba odrediti udaljenost između dve najbliže i dve najdalje tačke na kružnici i to uraditi u što manjem broju pogleda na krug.
	
	Igrač ove zagonetke u jednom pogledu na krug može da sazna rastojanje između neke dve tačke na krugu - rastojanje se definiše kao dužina najkraćeg puta od jedne do druge tačke, pri čemu je dozvoljeno samo kretanje po obimu kruga. Sve tačke se, naravno, nalaze na obimu i nikoje dve tačke nisu na istoj poziciji.
	
	## Opisi funkcija
	Potrebno je implementirati funkciju $Resi(N, L, H)$ gde je $N$ broj tačaka u zagonetki, $L$ adresa promenljive u koju treba upisati traženo minimalno rastojanje i $H$ adresa promenljive u koju treba upisati traženo maksimalno rastojanje. Na raspolaganju vam je i funkcija $Rastojanje(u, v)$ koja vraća rastojanje između tačaka sa indeksima $u$ i $v$. Tačke su indeksirane brojevima od 0 do $N − 1$.
	
	## Primer
	Neka je $N = 4$. Neka je rastojanje od tačke 2 do tačaka 0, 1 jednako 2 a rastojanje od tačke 3 do tačaka 0, 1 jednako 10. Može se zaključiti da su tačke 2 i 3 na različitim stranama u odnosu na pravu koja spaja 0 i 1, kao i da je tetiva 2 − 3 prečnik kruga. Najveća udaljenost je onda jednaka polovini obima, odnosno 12 a najmanja je 2.
	
	## Ograničenja
	* $2 ≤ N ≤ 100,000$
	* Obim kruga je najviše $10^9$
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u dva podzadatka, u kojima važe sledeća dodatna ograničenja
	
	* PODZADATAK 1 [30 POENA]: $N ≤ 1000$
	* PODZADATAK 2 [70 POENA]: Nema dodatnih ograničenja
	U zavisnosti od broja poziva funkciji Rastojanje (označimo ovaj broj sa $K$), za svaki podzadatak dobija se sledeći procenat poena:
	* [100 %]: Ako je u svakom test primeru $K ≤ 2N$
	* [60 %]: Ako je u svakom test primeru $K ≤ 4N$
	* [30 %]: Ako je u svakom test primeru $K ≤ 30N$
	* [10 %]: Ukoliko nijedno od prethodnih ograničenja nije ispoštovano
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom krug.c, krug.cpp ili krug.pas, koji
	implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	C/C++ void $Resi$(int $N$, int* $L$, int* $H$)
	Pascal procedure $Resi$($N$ : longint; var $L, H$ : longint);
	
	Funkcija Rastojanje biće sledećeg oblika:
	C/C++ int $Rastojanje$(int $u$, int $v$)
	Pascal function $Rastojanje$($u, v$ : longint) : longint
	
	Ukoliko radite u C/C++ -u, potrebno je na početku fajla staviti #include “krug.h” a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti Unit krug; (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam template fajlovi (krug.c, krug.cpp, krug.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza broj $N$, zatim pozivaju vašu funkciju $Resi$. Svaki put kada se pozove funkcija $Rastojanje$ na standardni izlaz ispišu se parametri $u, v$ poziva te funkcije, a nakon toga na standardni ulaz treba uneti traženo rastojanje. Po izlasku iz funkcije $Resi$ ispisuju se vrednosti $L, H$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković i Ivan Stošić | Ivan Stošić | Mladen Puzić | - |
	
	## Rešenje
	Koristeći $N-1$ poziv funkciji nađimo rastojanje od tačke $0$ do svih ostalih tačaka. Tačka koja je najbliža tački $0$ mora joj biti susedna, bez umanjenja opštosti, reći ćemo da je to tačka $1$. Koristeći još $N-2$ poziva funkciji nađimo rastojanje svih tačaka (sem $0$ i $1$) od tačke $1$. 
	
	Sada krug možemo podeliti u dve grupe: na one tačke koje su bliže tački $0$ i one koje su bliže tački $1$. Te tačke sada možemo sortirati po rastojanju od svoje odgovarajuće tačke, i samim tim, naći redosled tačaka na krugu. Takođe, znamo rastojanje svake dve susedne tačke, sem za jedan par: tačku iz prve grupe koja je najdalja od tačke $1$ (nazovimo ovu tačku $A$ za dalje potrebe) i tačku iz druge grupe koja je najdalja od tačke $1$ (nazovimo ovu tačku $B$ za dalje potrebe). Za taj par ćemo iskoristiti još jedan poziv funkciji, tako da smo ukupno iskoristili $2N-2$ poziva. 
	
	Najmanje rastojanje će sigurno biti jedno od rastojanja susednih tačaka, tako da to već možemo da izračunamo. Za najveće rastojanje nam je potrebno još obzervacija. Potrebno je da nađemo obim kruga. 
	
	Ukoliko se tačke ne nalaze sve na istom polukrugu, obim je jednak $Rastojanje(0, 1)$+$Rastojanje(0, A)$+$Rastojanje(1, A)$+$Rastojanje(A, B)$ (za ovo ne moramo pozivati funkciju, sva ova rastojanja već imamo). Ukoliko se nalaze, možemo pretpostaviti da je $Rastojanje(A, B)$ poluobim, čime ne kvarimo nijedno rastojanje (ovo nije neophodno, ostatak rešenja možemo posmatrati kroz dva slučaja, ali je ovako lakše za implementaciju).  
	
	Sada kada imamo obim, možemo da nađemo rastojanje između bilo koje dve tačke bez da pozivamo našu funkciju. Za svaku tačku iz prve grupe možemo binarnom ili ternarnom pretragom naći najdalju tačku u složenosti $O(logN)$,  i za kraj uzmemo najdalji par. 
	
	
	``` cpp title="01_madjarski_krug.cpp" linenums="1"
	#include "krug.h"
	#include <algorithm>
	using namespace std;
	
	int d0[100005], dx[100005], p[200005];
	
	void Resi(int N, int* L, int* H){
		for (int i=1; i<N; i++) d0[i] = Rastojanje(0, i);
		int m=1;
		for (int i=1; i<N; i++) if (d0[i] < d0[m]) m = i;
		for (int i=1; i<N; i++) if (i!=m) dx[i] = Rastojanje(m, i);
		p[0] = 0;
		p[m] = d0[m];
		int lm = 0, rm = m;
		for (int i=1; i<N; i++) if (i!=m){
			if (d0[i] < dx[i]){
				p[i] = -d0[i];
				if (p[i] < p[lm]) lm = i;
			} else {
				p[i] = dx[i] + d0[m];
				if (p[i] > p[rm]) rm = i;
			}
		}
		
		int obim = p[rm] - p[lm] + Rastojanje(lm, rm);
		sort(p, p+N);
		for (int i=0; i<N; i++) p[i+N] = p[i] + obim;
		*L = obim;
		*H = 0;
		for (int i=0; i<N; i++) if (p[i+1] - p[i] < *L) *L = p[i+1] - p[i];
		int j = 0;
		for (int i=0; i<N; i++){
			while (p[j+1] - p[i] <= obim/2) j++;
			if (p[j] - p[i] > *H) *H = p[j] - p[i];
		}
	}

	```
