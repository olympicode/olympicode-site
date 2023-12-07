---
hide:
  - toc
---

# B1 - Lek

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 2000ms | 256MB |
	
	
	U ovo vreme globalne epidemije virusa, naš poznati naučnik Miloš je, kao jedini dovoljno kvalifikovani naučnik za ovaj posao, dobio zadatak da analizira genetsku strukturu virusa u svojoj labaratoriji. Ako njegova analiza bude uspešna, ona će zagarantovati pronalaženje leka i oslobođenje sveta od virusa.
	
	Genetska struktura virusa $G$ se može predstaviti kao permutacija brojeva od $1$ do $N$, to jest, niz brojeva od $1$ do $N$ dužine $N$ gde se svaki broj pojavljuje tačno jednom.
	
	Kako bi Miloš mogao da uradi svoju analizu, genetska struktura mora da bude sortirana. Za soritranje genetske strukture, Miloš koristi veoma specijalnu mašinu. Ova mašina mu dozvoljava da uzme neki segment niza i obrne ga. Tačnije, može da odabere dva indeksa $l$ i $r$ tako da važi $l\leq r$, i obrne podniz od  $l$-te do $r$-te pozicije u nizu (zameni mesta elementima $G_l$ i $G_r$, $G_{l+1}$ i $G_{r-1}$, $\ldots$ ).
	Miloš takođe zna da su geni veoma osetljivi i da će se oštetiti ako upotrebi mašinu više puta na isti gen (Miloš može da upotrebi mašinu proizvoljan broj puta, ali intervali indeksa koje odabere moraju biti disjunktni).
	
	Kako Miloš nema iskustva sa korišćenjem ove mašine, potrebna mu je vaša pomoć! Kažite mu da li je moguće uz pomoć ove mašine sortirati genetsku strukturu bez oštećenja gena ili ne. Ako je sortiranje genetske strukture moguće, takoće mu je potrebna i sekvenca operacija koju treba primeniti radi uspešnog sortiranja. Zbog toga što je mašina spora, a Miloš hoće da lek bude gotov što pre, potrebno je i da sekvenca operacija bude najkraća moguća (ukoliko postoji više najkraćih sekvenci, ispisati bilo koju).
	
	## Opis ulaza
	
	Prva linija standardnog ulaza sadrži broj $N$, dužinu genetske strukture. 
	Druga linija standardnog ulaza sadrži niz $G$, genetsku strukturu.
	
	## Opis izlaza
	
	Ukoliko je sortiranje genetske strukture moguće, u prvoj liniji standardnog izlaza ispisati "Svet je spasen", u drugoj liniji standardnog izlaza ispisati dužinu najkraće moguće sekvence operacija $K$.  U svakoj od narednih $K$ linija ispisati dva broja $l_i$ i $r_i$, indekse koje Miloš treba da odabere za $i$-tu operaciju. 
	Ukoliko sortiranje genetske strukture nije moguće, u prvoj i jedinoj liniji standardnog izlaza ispisati "Nema spasa"
	
	## Primer 1
	
	### Ulaz
	
	```
	8
	2 1 4 3 5 6 7 8
	```
	
	### Izlaz
	
	```
	Svet je spasen
	2
	1 2
	3 4
	```
	
	## Primer 2
	
	### Ulaz
	
	```
	8
	1 6 7 3 2 5 4 8
	```
	
	### Izlaz
	
	```
	Nema spasa
	```
	
	## Ograničenja
	
	- $1\leq N\leq10^6$
	- $1\leq G_i\leq N$
	- Svaki broj od $1$ do $N$ se pojavljuje tačno jednom u $G$.
	
	Test primeri su podeljeni u 5 podzadatka:
	
	-   **[10 poena]:** $N \leq 3$
	-   **[20 poena]:** $N \leq 20$
	-   **[30 poena]:** Ako postoji, najkraća sekvenca operacija je dužine $0$ ili $1$, $N \leq 500$
	-   **[20 poena]:** $N \leq 500$
	-   **[20 poena]:** Nema dodatnih ograničenja
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Pešić | Dimitrije Erdeljan | Aleksandar Zlateski |
	
	
	Pošto svaki element može biti deo najviše jednog intervala koji
	okrećemo, znamo da važi sledeće:
	
	* Ako $A_i = i$, taj element se ne pomera, tako da ne sme biti deo
	  nijednog intervala.
	* Ako $A_i \neq i$, taj element mora biti deo intervala koji ga dovodi
	  na poziciju $A_i$.
	  
	Ako za neko $i$ imamo $A_i \neq i$ i $A_{i-1} = i-1$ (ili $i=1$),
	jedan interval mora počinjati na poziciji $i$ (jer ne sme da obuhvati
	$i-1$) i imati dužinu takvu da $A_i$ postavi na ispravnu poziciju:
	$A_i - i + 1$.
	
	Dakle, da bi odredili pozicije svih intervala, dovoljno je da prođemo
	kroz ceo niz i svaki put kada naiđemo na neko $A_i \neq i$, obrnemo
	interval dužine $A_i - i + 1$ i nastavimo od prve pozicije nakon tog
	intervala (jer elemente koje smo ovime pomerili ne smemo da ponovo
	pomerimo). Kada dođemo do kraja niza, u drugom prolazu možemo
	proveriti da li je sortiran: ako jeste, našli smo (jedino moguće)
	rešenje, a ako nije rešenje ne postoji.
	
	Algoritam prolazi kroz niz dva puta, i u okretanju intervala svaki
	element posmatra najviše jednom (jer se intervali ne seku), tako da je
	ukupna složenost $\mathcal{O}(N)$.
	
	``` cpp title="01_lek.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	int n;
	void rev(int l,int r,vector<int> &p){
		for(int j=l;r-j+l>j;j++)
	  	swap(p[j],p[r-j+l]);
	}
	bool ok(vector<int> &p){
		for(int i=0;i<p.size();i++)
			if(p[i]!=i)
				return 0;
		return 1;
	}
	int main(){
		scanf("%i",&n);
	  vector<int> perm(n+2);
	  for(int i=1;i<=n;i++)
	  	scanf("%i",&perm[i]);
	  perm[n+1]=n+1;
	  vector<pair<int,int> > sol;
	  int lst=-1;
	  for(int i=1;i<=n+1;i++){
	  	if(perm[i]>perm[i-1]){
	  		if(lst!=-1){
	  			rev(lst,i-1,perm);
	  			sol.push_back({lst,i-1});
	  			lst=-1;
	  		}
	  	}
	  	else{
	  		if(lst==-1)
	  			lst=i-1;
	  	}
	  }
	  if(!ok(perm)){
	  	printf("Nema spasa\n");
	  	return 0;
	  }
	  printf("Svet je spasen\n%i\n",sol.size());
	  for(auto p:sol)
	  	printf("%i %i\n",p.first,p.second);
	  return 0;
	}

	```
