---
hide:
  - toc
---

# 6 - Odabir

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 256MB |
	
	Kao i uvek što se dešava, svi članovi komisije imaju pametnija posla od odabira zadataka. Pošto je to dosadan posao, oni su našli savršenu formulu za odabir zadatak, međutim problem je što njih mrzi da napišu program koji će na osnovu predloga odabrati zadatke.
	
	Oni već imaju pripremljenih $N$ predloga zadataka za koje smatraju da su dovoljno kvalitetni da budu na takmičenju, međutim niko iz komisije neće da se potrudi da od tih N predloga odabere zadatke za takmičenje, te je na vama ostalo da to uradite.
	
	Zadaci su numerisani brojevima **od $0$ do $N-1$** i svakom zadatku je dodeljen jedan broj $T_i$ koji predstavlja težinu zadatka (što je veći broj $T_i$ to je po njima teže rešiti taj zadatak). 
	
	Zadaci se biraju tako što se nasumično odrede dva broja $L$ i $R$ ($L\leq R$) koji predstavljaju interval $[L,R]$ odakle se zadaci moraju izabrati, tj. ne može se izabrati nijedan zadatak koji je numerisan brojem manjim od $L$ ili većim od $R$ (posmatraju se zadaci na pozicijama $L,L+1,L+2,\ldots,R$ sa težinama $T[L],T[L+1],T[L+2],\ldots,T[R]$). Postupak za odabir zadataka je takav da se odredi broj $X$ iz intervala $[L,R]$ ($L\leq X\leq R$) i na takmičenju se daju svi zadaci numerisani brojevima od $L$ do $X$, tj. svi zadaci numerisani brojevima $L,L+1,L+2,\ldots,X$.
	
	Članovi tajne komisije su osmislili savršen način da ocene težinu takmičenja na osnovu zadataka koje su odabrali. Težina takmičenja se računa tako što se od odabranih zadataka (zadaci numerisani brojevima od $L$ do $X$) saberu težine **najlakšeg** i **najtežeg** zadatka.
	
	Kako je ipak ovo Srpska Informatička Olimpijada, oni hoće da takmičenje bude što teže, te za dati interval $[L,R]$ potrebno je da pronađete **najteže** takmičenje. Preciznije, ako sa $F(X)$ označimo težinu takmičenja gde su dati zadaci sa težinama $T[L],T[L+1],\ldots,T[X]$, tj.
	
	$$
	F(X)=\min(T[L],T[L+1],\ldots,T[X])+\max(T[L],T[L+1],\ldots,T[X])
	$$
	
	potrebno je da pronađete maksimalno $F(X)$ za $L\leq X\leq R$, tj. $\max(F(L),F(L+1),\ldots,F(R))$.
	
	Tajna komisija će napraviti tačno $Q$ kombinacija odabira zadataka za takmičenje, te će na početku takmičenja odabrati kombinaciju zadataka koju će takmičari dobiti da rešavaju. 
	
	Vaš zadatak je da za svaku kombinaciju gde su vam dati brojevi $L$ i $R$ pronađete odgovarajuće $\max(F(L),F(L+1),\ldots,F(R))$.
	
	## Opisi funkcija
	Potrebno je implementirati funkciju
	
	* $Odaberi(N,T,Q,L,R,F)$
	
	gde je $N$ – broj predloženih zadataka, $T$ – niz brojeva dužine $N$ gde $T[i]$ predstavlja težinu $i$-tog predloženog zadatka, $Q$- broj kombinacija koje će se praviti za takmičenje, $L$ i $R$ nizovi brojeva dužine $N$ gde su $L[i]$ i $R[i]$ opisani brojevi za $i$-tu kombinaciju odabira zadataka.
	
	$F$ je prazan niz dužine $Q$ koji vaša funkcija treba da popuni odgovarajućim brojevima, tj. na mesto $i$ u nizu $F$ potrebno je da se postavi težina najtežeg takmičenja iz intervala $[L[i],R[i]]$.
	
	**Svi nizovi su numerisani od nule.**
	
	## Primer
	Neka je vaša funkcija pozvana sa sledećim parametrima:
	
	```
	N=6
	T=[1000,1,1200,1300,1400,5000]
	Q=3
	L=[0,0,2]
	R=[4,5,4]
	```
	
	Prvi upit nad nizom $T$ je $[L[0],R[0]]=[0,4]$ što odgovara delu niza $[1000,1,1200,1300,1400]$ te je za $X$ u ovom slučaju najbolje odabrati broj $0$, tj. odabrao bi se samo prvi zadataka sa težinom $1000$ te bi težina takmičenja bila $F=1000+1000=2000$.
	
	U drugom upitu na nizom $T$ je $[L[1],R[1]]=[0,5]$ što odgovara celom nizu $T$, te u ovom slučaju je potrebno odabrati ceo niz, tj. $X=5$ i težina takmičenja u tom slučaju je $F=1+5000=5001$.
	
	U poslednjem upitu je $[L[2],R[2]]=[2,4]$ se posmatra niz $[1200,1300,1400]$ i najbolje rešenje se dobija za $X=4$, a težina takmičenja u tom slučaju je $F=1400+1200=2600$.
	
	Funkcija na kraju izvršavanja treba da popuni niz $F$ tako da je $F[0]=2000$, $F[1]=5001$, $F[2]=2600$.
	
	## Ograničenja
	* $1\leq N,Q\leq 3*10^5$
	* $1\leq T[i]\leq 10^9$
	* $0\leq L[i]\leq R[i]\leq N-1$
	
	## Podzadaci i bodovanje
	* PODZADATAK 1 [7 POENA]: $N,Q\leq 1000$
	* PODZADATAK 2 [20 POENA]: $Q\leq 10.000$, $T[i]\leq 1000$, $N\leq 10^5$
	* PODZADATAK 3 [13 POENA]: $T[i]\leq 1000$, $N,Q\leq 10^5$
	* PODZADATAK 4 [41 POENA]: $N,Q\leq 10^5$
	* PODZADATAK 5 [19 POENA]: Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl, pod nazivom odabir.c, odabir.cpp ili odabir.pas, koji implementira gore pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Zavisno od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	```
	C/C++
	    void Odabir(int N, int *T, int Q, int *L, int *R, int *F);
	Pascal
	    procedure Odabir(N: longint; var T: array of longint; Q: longint; var L, R, F : array of longint);
	```
	
	Ukoliko radite u C/C++-u, potrebno je na početku fajla staviti `#include odabir.h”` a ukoliko radite u Pascal-u, potrebno je na početku fajla staviti `Unit odabir;` (**ovo je već dodato u fajlovima koji su vam obezbeđeni**).
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam “template” fajlovi (odabir.c, odabir.cpp, odabir.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (grader.c, grader.cpp, grader.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	* U prvom redu se učitava broj $N$
	* U drugom redu se učitava $N$ brojeva, tj. niz $T$
	* U trećem redu se učitava broj $Q$
	* U svakom od sledećih $Q$ redova se nalaze dva broja koji $L[i]$ i $R[i]$
	
	a zatim pozivaju vašu funkciju Odabir iz odgovarajućeg fajla (odabir.c, odabir.cpp, odabir.pas) sa učitanim parametrima i na kraju vrednost koju vaša funkcija vraća ispisuju na standardni izlaz. Kodove ovih programa možete menjati po potrebi.
	
	U nastavku je dat primer učitavanja sa konzole za test primer sa papira.
	
	```
	6
	1000 1 1200 1300 1400 5000
	3
	0 4
	0 5
	2 4
	```
	
	Ispis na konzolu je sledeći:
	
	```
	2000 5001 2600
	```
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Demjan Grubić | Aleksandar Višnjić | Dimitrije Dimić |
	
	## Prvi podzadatak:
	Zadatak rešavamo grubom silom: prolazimo po svakom $X$ od $L$ do $R$ i računamo prefiksni minimum i maksimum. Složenost je $O(N\cdot Q)$.
	
	## Drugi i treći podzadatak:
	Zadatak rešavamo **offline**, tj. prvo učitamo sve upite, sortiramo ih po $L$ vrednosti, a zatim prolazimo kroz niz $T$ od kraja ka početku. Dok to radimo, pamtimo niz $pos_i$ koji nam govori informaciju o prvom sledećem indeksu pojavljivanja člana $i$ u nizu $T$. Taj niz ima veličinu $1000$, jer je to maksimalna vrednost $T_i$ u ovom podzadatku. Sada za svaki upit znamo interesantne pozicije: Potrebno je samo po njima proći i izračunati zbir maksimuma i minimuma. Složenost ovog algoritma je $O(Q\cdot maxT_i \cdot logN)$ ili $O(Q\cdot maxT_i)$ u zavisnosti od implementacije.
	
	## Glavno rešenje:
	Slično kao ranije, zadatak rešavamo **offline**. Kada idemo od kraja ka početku, potrebno je održavati i lenjo segmentno stablo nad nizom $T$. Njime pamtimo maksimum na segmentu, a ažuriramo ga tako što dodajemo (ili oduzimamo) određen broj na rasponu. Ono nam govori informaciju o rešenju zadatka za svako $X$ između $L$ i $N$. 
	
	Preciznije, interesantnih pozicija sada ima mnogo i nije moguće uvek proći po njima za svaki upit. Zato pamtimo dva **stack-a** parova koji nam govore informacije o sledećem manjem/većem elementu u nizu $T$. Kada vršimo upite raspona na našem segmentnom stablu, brišemo element iz jednog od *stack*-ova. To znači da ukupna složenost ostaje $O(N+QlogN)$, Pošto u naše *stack*-ove dodajemo najviše jedan element po prolasku kroz niz $T$, a ne možemo obrisati više nego što smo dodali.
	
	``` cpp title="06_odabir.cpp" linenums="1"
	#include "odabir.h"
	#include <iostream>
	#include <algorithm>
	#include <vector>
	
	using namespace std;
	
	const int MAX_N = 1 << 19;
	const int MAX_NUM = 1000000005;
	
	int tree[2 * MAX_N];
	int save[2 * MAX_N];
	
	int prevBigger[MAX_N];
	int prevSmaller[MAX_N];
	int nextBigger[MAX_N];
	int nextSmaller[MAX_N];
	vector<int> smaller[MAX_N];
	vector<int> bigger[MAX_N];
	int size;
	int stk[MAX_N];
	
	int f[MAX_N];
	int* L;
	int* R;
	
	bool mycmp(int a, int b) {
	    return L[a] < L[b];
	}
	
	void update(int node, int left, int right, int nleft, int nright, int amount) {
	    if (nright < left || nleft > right) return;
	    if (left >= nleft && right <= nright) {
	        tree[node] += amount;
	        save[node] += amount;
	        return;
	    }
	    int mid = (left + right) / 2;
	    tree[node * 2 + 1] += save[node];
	    tree[node * 2 + 2] += save[node];
	    save[node * 2 + 1] += save[node];
	    save[node * 2 + 2] += save[node];
	    save[node] = 0;
	    update(node * 2 + 1, left, mid, nleft, nright, amount);
	    update(node * 2 + 2, mid + 1, right, nleft, nright, amount);
	    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
	}
	
	int findMax(int node, int left, int right, int nleft, int nright) {
	    if (nright < left || nleft > right) return 0;
	    if (left >= nleft && right <= nright) {
	        return tree[node];
	    }
	    int mid = (left + right) / 2;
	    tree[node * 2 + 1] += save[node];
	    tree[node * 2 + 2] += save[node];
	    save[node * 2 + 1] += save[node];
	    save[node * 2 + 2] += save[node];
	    save[node] = 0;
	    int res = 0;
	    res = max(res, findMax(node * 2 + 1, left, mid, nleft, nright));
	    res = max(res, findMax(node * 2 + 2, mid + 1, right, nleft, nright));
	    return res;
	}
	
	void Odaberi(int N, int *T, int Q, int *tmpL, int *tmpR, int *X) {
	    L = tmpL;
	    R = tmpR;
	
	    int minVal = T[0];
	    int maxVal = T[0];
	    for (int i = 0; i < N; ++i) {
	        minVal = min(minVal, T[i]);
	        maxVal = max(maxVal, T[i]);
	        save[i + MAX_N - 1] = 0;
	        tree[i + MAX_N - 1] = minVal + maxVal;
	    }
	    for (int i = MAX_N - 2; i >= 0; --i) {
	        save[i] = 0;
	        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
	    }
	
	    for (int i = 0; i < Q; ++i) f[i] = i;
	    sort(f, f + Q, mycmp);
	
	    for (int i = 0; i < N; ++i) {
	        smaller[i].clear();
	        bigger[i].clear();
	    }
	    size = 0;
	    for (int i = N - 1; i >= 0; --i) {
	        while (size >= 1 && T[stk[size - 1]] < T[i]) --size;
	        stk[size++] = i;
	        nextBigger[i] = (size >= 2?stk[size - 2]:N);
	    }
	    size = 0;
	    for (int i = N - 1; i >= 0; --i) {
	        while (size >= 1 && T[stk[size - 1]] > T[i]) --size;
	        stk[size++] = i;
	        nextSmaller[i] = (size >= 2?stk[size - 2]:N);
	    }
	    size = 0;
	    for (int i = 0; i < N; ++i) {
	        while (size >= 1 && T[stk[size - 1]] <= T[i]) --size;
	        stk[size++] = i;
	        prevBigger[i] = (size >= 2?stk[size - 2]:-1);
	        if (prevBigger[i] > -1) 
	            bigger[prevBigger[i]].push_back(i);
	    }
	    size = 0;
	    for (int i = 0; i < N; ++i) {
	        while (size >= 1 && T[stk[size - 1]] >= T[i]) --size;
	        stk[size++] = i;
	        prevSmaller[i] = (size >= 2?stk[size - 2]:-1);
	        if (prevSmaller[i] > -1)
	            smaller[prevSmaller[i]].push_back(i);
	    }
	
	    int last = 0;
	    for (int testId = 0; testId < Q; ++testId) {
	        int left = L[f[testId]];
	        int right = R[f[testId]];
	
	        while (last < left) {
	            for (int i = 1; i < smaller[last].size(); ++i) {
	                int p1 = smaller[last][i - 1];
	                int p2 = smaller[last][i] - 1;
	
	                update(0, 0, MAX_N - 1, p1, p2, T[p1] - T[last]);
	            }
	            if (smaller[last].size() > 0) {
	                int lastP = smaller[last][smaller[last].size() - 1];
	                update(0, 0, MAX_N - 1, lastP, nextSmaller[last] - 1, T[lastP] - T[last]);
	            }
	            for (int i = 1; i < bigger[last].size(); ++i) {
	                int p1 = bigger[last][i - 1];
	                int p2 = bigger[last][i] - 1;
	
	                update(0, 0, MAX_N - 1, p1, p2, T[p1] - T[last]);
	            }
	            if (bigger[last].size() > 0) {
	                int lastP = bigger[last][bigger[last].size() - 1];
	                update(0, 0, MAX_N - 1, lastP, nextBigger[last] - 1, T[lastP] - T[last]);
	            }
	
	            ++last;
	        }
	
	        X[f[testId]] = findMax(0, 0, MAX_N - 1, left, right);
	    }
	}

	```
