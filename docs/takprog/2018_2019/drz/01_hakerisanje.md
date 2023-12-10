---
hide:
  - toc
---

# B1 - Hakerisanje

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	Mladi haker Žak je odlučio da po svaku cenu dođe do šifre naloga svoga profesora. Otkrio je da je ta šifra tačno jednaka odgovoru na $Q$ upita nad profesorovim nizom. Profesorov niz $A_{i}$ ima $N$ elemenata, a upiti su tipa $L$ $R$. Odgovor na upit je vrednost bitovske konjunkcije elemenata niza između indeksa $L$ i $R$ (uključujući i njih). Pomozite Žaku da otkrije šifru.
	
	## Opis ulaza
	
	U prvom redu nalaze se brojevi $N$, dužina niza i $Q$ najveći broj upita nad nizom. U drugom redu nalazi se niz od $N$ elemenata. U narednih $Q$ redova nalaze se upiti opisanog formata.
	
	## Opis izlaza
	
	Za svaki od $Q$ upita ispisati vrednost bitovske konjunkcije elemenata između indeksa $L$ i $R$.
	
	## Primer
	
	### Ulaz
	
	~~~
	5 4
	1 5 4 3 2
	1 3
	4 5
	2 5
	2 3
	
	~~~
	
	### Izlaz
	
	~~~
	0
	2
	0
	4
	~~~
	
	## Objašnjenje primera
	
	Odgovor na prvi upit je: $1 \ \text{and} \ 5 \ \text{and} \ 4 = 0$.
	Odgovor na drugi upit je: $3 \ \text{and} \ 2 = 2$.
	Odgovor na treći upit je: $5 \ \text{and} \ 4 \ \text{and} \ 3 \ \text{and} \ 2 = 0$.
	Odgovor na četvrti upit je: $5 \ \text{and} \ 4 = 4$.
	
	## Ograničenja
	* $1 \leq Q, N \leq 2 \cdot 10^5$
	* $0 \leq A_{i} \leq 10^6$
	
	Postoje tri podzadatka:
	
	* Podzadatak 1 [15 poena]: $N, Q \leq 10^3$.
	* Podzadatak 2 [33 poena]: $A_{i} \leq 1$.
	* Podzadatak 3 [52 poena]: Nema dodatnih ograničenja.
	
	
	## Napomena
	Operator konjunkcije u Pascal-u je označen sa `and`, dok u C++ ga zapisujemo pomoću simbola `&`. Ova operacija $x\ \text{and} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 1$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{and} \  y$.
	
	Bitovska konjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{and} \ x_{2}  \ \text{and} \  ...  \ \text{and} \  x_{n} = (...(((x_{1}  \ \text{and} \  x_{2})  \ \text{and} \  x_{3}) \ \text{and} \ x_{4})...)  \ \text{and} \  x_{n}$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Aleksa Milisavljević | Momčilo Topalović |
	
	
	## Podzadatak 1
	
	U prvom podzadatku, za svaki upit prođemo kroz podniz za koji se traži odgovor i izvršimo bitovsku konjunkciju svih elemenata. Vremenska složenost je $O(NQ)$.
	
	## Podzadatak 2
	
	U drugom podzadatku u nizu su samo jedinice i nule.  Primetimo da je odgovor na upit ili $0$ ili $1$. U ovom podzadatku napravimo prefiksne sume, tj. proverimo koliko puta se pojavljuje $1$ do nekog indeksa $i$. Neka je ovaj broj $p_{i}$. Uslov da odgovor bude $1$ je da između indeksa $l$ i $r$ budu sve jedinice, tj. da važi $p_{r}-p_{l-1}=r-l+1$. Vremenska složenost je $O(N)$.
	
	## Podzadatak 3  (kompletno rešenje)
	
	Za kompletno rešenje neophodno je da zamislimo naše brojeve u binarnom sistemu i da primetimo da bitove ovde možemo da posmatramo nezavisno. Sada radimo sličan postupak kao i u prethodnom podzadatku, za svaki bit $k$, nađemo u koliko brojeva do indeksa $i$ je on $1$. Neka je ovaj broj $p_{k,i}$. Da bi taj bit bio $1$ kada izvršimo konjunkciju svih elemenata, potrebno je da važi $p_{k,r}-p_{k,l-1}=r-l+1$. Tada je odgovor na upit od $l$ do $r$ jednak $\sum 2^k$, za sve $k$ za koje važi $p_{k,r}-p_{k,l-1}=r-l+1$. Vremenska složenost je $O(N\log A_{i})$.
	
	``` cpp title="01_hakerisanje.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define MAXN 1000010
	#define MAXB 21
	int n,q,x,a[MAXN];
	int pref[MAXB][MAXN];
	int main()
	{
		scanf("%d %d",&n,&q);
		int l,r,m,k;
		bool p;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<MAXB;j++) {
				pref[j][i]=pref[j][i-1];
				if(a[i]&(1<<j)) pref[j][i]++;
			}
		}
		while(q--) {
			scanf("%d %d",&l,&r);
			m=r-l+1;
			int res=0;
			for(int j=0;j<MAXB;j++) {
				if(pref[j][r]-pref[j][l-1]==r-l+1) res+=(1<<j);
			}
			printf("%d\n",res);
		}
		return 0;
	}

	```
