---
hide:
  - toc
---

# A1 - I/Ili

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Dobili ste jedan niz od $N$ brojeva na poklon! Poznato Vam je da se na ovom nizu može raditi sledeća operacija: izaberi 2 broja $1 \leq i \leq N$ i $1 \leq j \leq N$,
	i elemente niza $A_i$ i $A_j$ zameni sa $A_i\text{ and }A_j$ i $A_i\text{ or }A_j$, gde su $and$ i $or$ operacije logičko "i", odnosno logičko "ili" (ove operacije vrše logičko "i"/"ili" na svakom od bitova u binarnom zapisu dveju brojeva).
	
	Uz niz dolazi i mašina koja zadaje $Q$ komandi. Svaka komanda je oblika
	
	  - $T_i$ $K_i$
	  - $T_i$ $K_i$ $X_i$
	
	Ukoliko je $T_i = 0$ (komanda tipa $0$), to znači da treba odgovoriti na pitanje **Koji je $K_i$-ti broj u leksikografski najvećem nizu koji je moguće dobiti primenom proizvoljno mnogo operacija opisanih gore, na niz koji imate**.
	
	Ukoliko je $T_i = 1$ (komanda tipa $1$), to znači da je potrebno promeniti niz koji imate tako da element na poziciji $K_i$ postaje $X_i$.
	
	**Komande tipa $0$ ne menjaju niz. odnosno ne formira se leksikografski najveći niz, već se Vaš niz isključivo menja komandama tipa $1$.**
	
	## Opis ulaza
	
	- U prvoj liniji ulaza nalazi se broj $N$, broj elemenata u nizu.
	- U sledećoj liniji nalazi se $N$ celih brojeva $A_i$, razdvojenih razmakom, koji predstavljaju vrednosti niza.
	- U trećoj liniji nalazi se $Q$, broj komandi.
	- U svakoj od narednih $Q$ linija data je komanda u obliku opisanom gore, brojevi su razdvojeni razmakom.
	
	## Opis izlaza
	
	Za svaku komandu tipa $0$ $K_i$, potrebno je ispisati u novom redu $K_i$-ti član leksikografski najvećeg niza koji se može dobiti primenom opisanih operacija nad nizom.
	
	## Primer 1
	
	### Ulaz
	
	```
	4
	0 1 2 3
	3
	0 1
	0 2
	0 3
	```
	
	### Izlaz
	
	```
	3
	3
	0
	```
	
	### Objašnjenje
	
	Traženi niz je $3$, $3$, $0$, $0$, te je prvi element 3, drugi 3, a treći 0.
	
	## Primer 2
	
	### Ulaz
	
	```
	5
	2 4 8 2 0
	3
	0 2
	1 4 0
	0 2
	```
	
	### Izlaz
	
	```
	2
	0
	```
	
	## Ograničenja
	
	- $N, Q \leq 10^5$
	- $T_i \in \{ 0, 1 \}$
	- $1 \leq K_i \leq N$
	- $0 \leq X_i, A_i \leq 10^9$
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	- U testovima vrednim 7 poena: $N, Q, A_i \leq 5$;
	- U testovima vrednim 21 poen: $N, Q \leq 100$;
	- U testovima vrednim 22 poena: $N, Q \leq 5000$
	- U testovima vrednim 13 poena: $A_i, X_i \in \{ 0, 1 \}$
	- U testovima vrednim 37 poena: Bez dodatnih ograničenja
	
	
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksandar Višnjić | Momčilo Tošić | Aleksandar Višnjić | Aleksandar Višnjić |
	
	## Prvi podzadatak
	Rekurzivno isprobavanje svih mogućih primena operacija osvaja poene u ovom podzadatku. Bitno je optimizovati tu rekurziju i ne posetiti nijedan niz više od dvaput u istoj komandi. To se može ostvariti upotrebom skupa u kome čuvamo sve posećene nizove.
	  
	## Drugi podzadatak
	Primetimo da primena operacije $A_i = A_i\text{ or }A_{i+1}$, $A_{i+1} = A_i\text{ and }A_{i+1}$ ima tendenciju da "bitove pomera ulevo". Ponovljenom primenom ovog postupka, slično kao u algoritmu "bubble sort", možemo efektivno sortirati trenutni niz i naći $K$-ti po redu element. Doslovna gruba implementacija dovodi do rešenja drugog podzadatka. Vremenska loženost je $O(QN^2)$.
	
	## Treći podzadatak
	Fiksirajmo neko $0 \leq i < 30$. Primetimo da se nakon primene operacije ukupan broj elemenata niza koji sadrže "bit" $2^i$ ne menja. Uočimo postupak iz prethodnog podzadatka. Rezultat je taj da se svi "bitovi" nalaze "zbijeno levo". Tačnije, između svake dve jedinice se takođe nalaze sve jedinice na određenoj mesnoj vrednosti u binarnom zapisu.
	
	Sada je dovoljno izbrojati svaki "bit", i u zavisnosti od $K$ odrediti da li se on nalazi u $K$-tom elementu krajnjeg niza $A$ ili ne. Direktna simulacija komandi dovodi do vremenske složenosti $O(NQ\log M)$, gde je $M$ najveća vrednost niza $A$ .
	
	## Četvrti podzadatak
	Slično kao u prethodnim podzadacima, brojimo koliko se puta "bit" pojavljuje u nizu. U ovom slučaju je to jednostavnije jer su elementi niza $0$ i $1$. Dakle, brojimo samo broj jedinica. Za komandu tipa $1$, podešavamo brojač na novu odgovarajuću vrednost na osnovu promenjenog elementa niza. Za komandu tipa $0$, dajemo odgovor u zavisnosti od ažuriranog broja jedinica. Vremenska složenost je $O(N)$. 
	
	## Glavno rešenje
	Spajamo ideje iz trećeg i četvrtog podzadatka. Za svaki "bit" (od $0$ do $29$), brojimo koliko se puta pojavljuje u nizu. Za komandu tipa $1$, podešavamo brojače na odgovarajuće nove vrednosti. Za komandu tipa $0$, dajemo odgovor slično kao u trećem podzadatku. Kod svake komande prolazimo po najviše $30$ bitova. Ovo daje rešenje vremenske složenosti $O((N+Q)\log M)$, gde je $M$ najveća vrednost niza $A$.
	
	``` cpp title="04_i_ili.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	long long typedef ll;
	
	int cnt[30];
	
	void brisi(int x)
	{
	    for (int i=0;i<30;i++) if (x&(1<<i)) cnt[i]--;
	}
	
	void dodaj(int x)
	{
	    for (int i=0;i<30;i++) if (x&(1<<i)) cnt[i]++;
	}
	
	int main()
	{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0),cout.tie(0);
	
	    int n; cin>>n;
	    vector<int> a(n);
	    for (int i=0;i<n;i++) cin>>a[i],dodaj(a[i]);
	
	    int q; cin>>q;
	    while (q--)
	    {
	        int t; cin>>t;
	        if (t==0)
	        {
	            int k; cin>>k;
	            int ans=0;
	            for (int i=0;i<30;i++)
	            {
	                if (cnt[i]>=k) ans|=(1<<i);
	                else if (i==48 && k==n-1) ans|=(1<<i);
	            }
	            cout<<ans<<"\n";
	        }
	        else
	        {
	            int k,x; cin>>k>>x;
	            brisi(a[k-1]);
	            a[k-1]=x;
	            dodaj(a[k-1]);
	        }
	    }
	}

	```
