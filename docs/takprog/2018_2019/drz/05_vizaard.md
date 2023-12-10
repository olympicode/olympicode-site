---
hide:
  - toc
---

# A2 - Vizaard

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	
	Odavno se zna za mistična svojstva nizova kojima je i bitovska konjunkcija svih elemenata veća od nule i bitovska ekskluzivna disjunkcija veća od nule. Čarobnjak Vizaard je dobio jedan ovakav niz sa $N$ elemenata. Da bi on dobio mistična svojstva, Vizaard na svakom od njegovih elemenata može da primeni jednu od sledeće dve operacije:
	
	 * Ukoliko je $A_{i} > 0$, može da smanji vrednost elementu sa indeksom $i$. Ovom operacijom vrednost $i$-tog elementa se pretvara u $A_{i}-1$.
	 * Može da poveća vrednost elementu sa indeksom $i$. Ovom operacijom vrednost $i$-tog elementa se pretvara u $A_{i}+1$.
	
	Vizaarda interesuje koliko najmanje operacija mora da primeni tako da niz dobije mistična svojstva, tj. da mu bitovska konjunkcija svih elemenata bude veća od nule i da mu bitovska ekskluzivna disjunkcija svih elemenata bude veća od nule.
	
	## Opis ulaza
	U prvoj liniji nalazi se jedan broj $N$, dužina niza. U narednoj liniji nalazi se niz od $N$ elemenata.
	
	## Opis izlaza
	
	Ispisati najmanji broj operacija potrebnih da i bitovska konjunkcija i bitovska ekskluzivna disjunkcija svih elemenata bude veća od $0$.
	
	## Primer
	
	### Ulaz
	
	~~~
	4
	5 2 3 3
	~~~
	
	### Izlaz
	
	~~~
	1
	~~~
	
	
	## Objašnjenje primera
	Primetimo da je $5 \ \text{and} \ 2 \ \text{and} \ 3 \ \text{and} \ 3  = 0$.
	Međutim primetimo da ukoliko drugi element smanjimo za jedan, dobijamo niz $[5,1, 3, 3]$, za koji važi $5 \ \text{and} \ 1 \ \text{and} \ 3 \ \text{and} \ 3  = 1$ i $5 \ \text{xor} \ 1 \ \text{xor} \ 3 \ \text{xor} \ 3  = 4$.
	
	## Ograničenja
	* $2 \leq N \leq 5 \cdot 10^5$
	* $0 \leq A_{i} \leq 10^{18}$
	
	Postoje četiri podzadatka:
	
	* Podzadatak 1 [14 poena]: $N, A_{i} \leq 16$.
	* Podzadatak 2 [20 poena]: $N \leq 10^3$, $A_{i} \leq 10^9$.
	* Podzadatak 3 [29 poena]: $N \leq 3\cdot 10^4$, $A_{i} \leq 10^9$.
	* Podzadatak 4 [37 poena]: Nema dodatnih ograničenja.
	
	## Napomena
	Operator konjunkcije u Pascal-u je označen sa `and`, dok u C++ ga zapisujemo pomoću simbola `&`. Ova operacija $x\ \text{and} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 1$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{and} \  y$.
	
	Bitovska konjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{and} \ x_{2}  \ \text{and} \  ...  \ \text{and} \  x_{n} = (...(((x_{1}  \ \text{and} \  x_{2})  \ \text{and} \  x_{3}) \ \text{and} \ x_{4})...)  \ \text{and} \  x_{n}$.
	
	Operator ekskluzivne disjunkcije u Pascal-u je označen sa `xor`, dok u C++ ga zapisujemo pomoću simbola `^`. Ova operacija $x\ \text{xor} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 0$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{xor} \  y$.
	
	Bitovska ekskluzivna disjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{xor} \ x_{2}  \ \text{xor} \  ...  \ \text{xor} \  x_{n} = (...(((x_{1}  \ \text{xor} \  x_{2})  \ \text{xor} \  x_{3}) \ \text{xor} \ x_{4})...)  \ \text{xor} \  x_{n}$.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Aleksa Milisavljević | Vladimir Milenković | Momčilo Topalović |
	
	## Analiza
	
	Na početku, konstatujmo da ni u jednom optimalnom rešenju nećemo primenjivati oba tipa operacija na isti broj – ili ćemo samo povećavati, ili samo smanjivati taj broj. 
	
	Primetimo da, ukoliko želimo da je and svih elemanata veći od 0, mora postojati jedna pozicija na kojoj svi brojevi imaju binarnu cifru 1. Ukoliko fiksiramo tu poziciju t, možemo izračunati za svaki broj u konstantnom vremenu najmanji broj dodavanja broj 1 na njega tako da u tom broju cifra na poziciji t postane 1. Takođe, možemo izračunati i najmanji broj oduzimanja potreban za istu stvar. Optimalno nam je da izaberemo onu opciju za koju treba manje operacija, ali je takođe korisno da sačuvamo da li je za neki broj bilo moguće da uzmemo bilo koju opciju (ukoliko je broj dodavanja i oduzimanja isti).
	
	Kako smo ispunili prvi uslov (za fiksno t), prva sledeća stvar koju treba proveriti je da li je xor svih ovako dobijenih brojeva 0 – ako jeste, našli smo najmanji broj operacija za izabranu poziciju. Ukoliko nije, a postojala je druga opcija za neki broj, iskoristićemo nju i ona će promeniti xor, tako da nije potrebno dodatnih operacija, ukoliko nije postojala, trebaće nam još 2 ili 1 operacija, u zavisnosti od toga da li je t izabrana pozicija najdesnija ili nije.
	
	Uradivši ovo za svako t od 0 do 60 (maksimalni broj bitova), sve što nam je preostalo je da uzmemo minimum dobijenih brojeva operacija.
	
	Vremenska složenost: $O(NlogMAX)$, gde je MAX maksimalan broj u ulazu (10^18).
	
	``` cpp title="05_vizaard.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 600000
	using namespace std;
	long long n;
	long long a[maxn];
	long long b[maxn];
	long long r=-1;
	int main()
	{
		scanf("%lld",&n);
		for(long long i=0;i<n;i++) scanf("%lld",&a[i]);
		long long s=0;
		long long mask=0;
		for(long long i=0;i<60;i++) { //fiksiramo bit
			s=0;
			if(i!=0) {
				for(long long j=0;j<n;j++) {
					if((a[j]&(1ll<<i))==0) {
						if(a[j]<(1ll<<i)) {
							s+=((1ll<<i)-a[j]);
							b[j]=a[j]+((1ll<<i)-a[j]);
						}
						else {
							if((a[j]&mask)+1ll<((1ll<<i)-(a[j]&mask))) {
								s+=((a[j]&mask)+1ll);
								b[j]=a[j]-((a[j]&mask)+1ll);
							}
							else {
								s+=((1ll<<i)-(a[j]&mask));
								b[j]=a[j]+((1ll<<i)-(a[j]&mask));
							}
						}
					}
					else b[j]=a[j];
					if(s>r) break;
				}
				long long x=0;
				for(int j=0;j<n;j++) x^=b[j];
				s+=(x==0);
			}
			else {
				bool fixable=false;
				s=0;
				for(int j=0;j<n;j++) {
					if((a[j]&1ll) == 0) {
						s++;
						b[j]=a[j]+1ll;
						if(a[j]>0) fixable=true;
					}
					else b[j]=a[j];
				}
				if(!fixable) {
					long long x=0;
					for(int j=0;j<n;j++) x^=b[j];
					if(x==0) s+=2ll;
				}
			}
			if(r==-1 || s<r) r=s;
			mask=(mask<<1ll)+1ll;
		}
		printf("%lld",r);
		return 0;
	}

	```
