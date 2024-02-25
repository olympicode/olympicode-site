---
hide:
  - toc
---

# A2 - Monopol

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 700ms | 64MB |
	
	
	Godina je 3024 i ljudska rasa kolonizovala je veći deo Sunčevog sistema. Međuplanetarna trgovina cveta, a najvrednija roba su bitovi. Sanja je ambiciozna mlada prodavačica bitova, koja ima plan da zavlada tržištem bitova na najvećoj planeti Sunčevog sistema, Jupiteru. 
	
	Na Jupiteru postoji $N$ gradova, numerisanih brojevima od $1$ do $N$. Ovi gradovi su povezani putevima tako da je grad $i$ povezan sa gradom $i+1$ za sve $i=1, \dots,  N-1$. Takođe, gradovi $1$ i $N$ su povezani. Svi putevi su iste dužine.
	
	Kako su bitovi nasušna potreba svakog stanovnika Jupitera, postoji $K$ prodavnica bitova, koje se nalaze u gradovima $A_1, \dots,  A_K$. Stanovnici Jupitera ne vole preterano da putuju, pa biraju da svakog jutra kupe bitove u prodavnici koja je najbliža gradu u kojem žive. Ukoliko je grad $i$ podjednako udaljen od dve prodavnice bitova, pola stanovnika tog grada kupovaće bitove u jednoj, a pola u drugoj prodavnici.
	
	Sanja je odlučila da izgradi $M$ novih prodavnica bitova, s ciljem da preuzme monopol nad tržištem, to jest da više od pola stanovnika Jupitera kupuje bitove u njenim prodavnicama. Zato je napravila detaljnu analizu tržišta i saznala da u gradu $i$ živi tačno $X_i$ stanovnika.
	
	Naravno, Sanja bi htela da uštedi i zato planira da izgradi minimalan broj prodavnica. Zato Vas je zamolila da joj pomognete i odredite minimalan broj prodavnica koje treba da izgradi tako da postigne monopol na tržištu ili da prijavite da to nije moguće. Pri tome, morate poštovati zakone Jupitera koji propisuju da se dve prodavnice bitova ne smeju nalaziti u istom gradu.
	
	## Opis ulaza
	
	Na prvoj liniji standardnog ulaza dati su brojevi $N$ i $K$, koji predstavljaju broj gradova i broj prodavnica bitova na Jupiteru.
	
	U drugoj liniji standardnog ulaza dato je $K$ različitih brojeva $A_1, \dots,  A_K$, koji predstavljaju lokacije prodavnica na Jupiteru.
	
	U trećoj liniji standardnog ulaza dato je $N$ parnih brojeva $X_1, \dots, X_N$.
	
	## Opis izlaza
	
	Na standardni izlaz ispisati jedan ceo broj - minimalan broj prodavnica koji Sanja treba da izgradi da bi preuzela monopol. Ukoliko Sanja ne može preuzeti monopol, ispisati -1.
	
	
	## Primer 1
	
	### Ulaz
	
	```
	5 2
	2 5
	2 2 2 2 2
	```
	
	### Izlaz
	
	```
	3
	```
	
	
	### Objašnjenje
	
	
	
	Postoji samo jedan način da Sanja preuzme više od pola kupaca - da izgradi po jednu prodavnicu u gradovima 1, 3, 5. Stoga, Sanja mora da izgradi barem tri prodavnice. Tada će Sanja imati šestoro kupaca.
	
	
	
	## Primer 2
	
	### Ulaz
	
	
	
	```
	4 2
	1 4
	2 2 8 4
	```
	
	
	
	### Izlaz
	
	
	
	```
	1
	```
	
	
	
	### Objašnjenje
	
	
	
	Sanja može da postigne monopol pomoću samo jedne prodavnice u gradu broj 3. U tom slučaju, Sanja će imati 9 kupaca, jednog iz grada 2 i osmoro iz grada 3.
	
	
	
	## Ograničenja
	
	- $2 \leq K \leq N \leq 500\,000$
	- $0 \leq X_i \leq 10^9$ za sve $i=1, \dots, N$.
	- Brojevi $X_i$ su parni
	- $1 \leq A_i \leq N$ za sve $i=1, \dots, K$.
	
	Test primeri su podeljeni u četiri disjunktne grupe:
	
	- U test primerima vrednim 10 poena: $N \leq 10$;
	- U test primerima vrednim 20 poena: U svakom gradu živi jednak broj ljudi;
	- U test primerima vrednim 20 poena: $N \leq 3000$;
	- U test primerima vrednim 50 poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Bogdan Petrović | Aleksa Milojević | Aleksa Milisavljević | Aleksa Milisavljević |
	
	## Rešenje kada $N \leq 10$
	
	U ovom podzadatku možemo da simuliramo svih $2^N$ mogućnosti građenja prodavnica i potom za svaki grad pronađemo najbližu prodavnicu u $O(N)$. Ukupna vremenska složenost je $O(2^N \cdot N^2)$. 
	
	## Rešenje kada u svakom gradu stanuje isti broj ljudi
	
	Neka je broj stanovnika svakog grada $g$. Posmatrajmo dve postojeće uzastopne prodavnice. Neka su one u gradovima $i$ i $j$ i neka između te dve prodavnice postoji barem jedan grad. Primetimo da sa gradnjom dve dodatne prodavnice, jednom u $i+1$ a drugom u $j-1$, Sanja može da preuzme mušterije iz svih gradova iz (cikličnog) intervala $[i+1,j-1]$. Dakle, ako gradimo dve prodavnice u (cikličnom) intervalu $[i+1,j-1]$, preuzećemo sve mušterije iz tog intervala. Ako gradimo samo jednu, preuzećemo pola mušterija, tačnije: $g \cdot ( \frac{j-i-2}{2} + 1 )$ mušterija. Zadatak rešavamo _greedy_ algoritmom. U svakom koraku biramo interval u kome je optimalno izgraditi novu prodavnicu. Primetimo da, ako je to prva prodavnica iz intervala, postavljanjem nje dobijamo $g \cdot ( \frac{j-i-2}{2} + 1 )$ novih mušterija, dok za drugu dobijamo $g \cdot ( \frac{j-i-2}{2}  )$ novih mušterija. Dakle, dovoljno je da sortiramo svih $2K$ dobitaka opadajuće i odaberemo prefiks najmanje dužine tako da je njegova suma strogo veća od polovine ukupnog broja stanovnika. Ovo rešenje radi u vremenskoj složenosti $O(K \log K)$.
	
	## Rešenje kada $N \leq 3\,000$
	
	Za ovo rešenje je dovoljno da modifikujemo prethodno rešenje, tako što za svaki ciklični interval tražimo optimalnu poziciju za prvu prodavnicu koja će biti izgrađena u njemu. Ovo možemo postići u složenosti $O(N^2)$, proverom koliko nam svaki odabir donosi mušterija.
	
	Primetite da je neophodan uslov da bi _greedy_ radio taj da prva prodavnica izgrađena u intervalu donosi barem onoliko mušterija koliko će doneti i druga (Zašto?). Primetimo i da je taj uslov ovde ispunjen, jer će prva prodavnica preuzeti barem polovinu mušterija iz intervala. Naime, primetite da gradnjom na poziciji $i+1$ preuzimamo celu prvu polovinu intervala, dok gradnjom na poziciji $j-1$ preuzimamo celu drugu polovinu intervala. Jedna od ove dve vrednosti je barem polovina sume celog intervala. 
	
	## Glavno rešenje
	
	Za glavno rešenje, dovoljno je optimizovati rešenje prethodnog podzadatka. Korišćenjem prefiksnih suma, moguće je u $O(N)$ proveriti koliko će mušterija iz odgovarajućeg intervala preuzeri prva prodavnica izgrađena u njemu.
	
	
	``` cpp title="05_monopol.cpp" linenums="1"
	#include <bits/stdc++.h>
	#define MAX_N 500000
	#define MAX_K 500000
	
	using namespace std;
	
	int N, K;
	int A[MAX_K];
	
	long long X[2*MAX_N];
	long long gain[MAX_K+1][3];
	long long psum[2*MAX_N];
	int ind[2*MAX_K];
	
	
	long long compute_gain(int a){
		if(a<K)
			return gain[a][1];
		else
			return gain[a-K][2]-gain[a-K][1];
	}
	
	bool compare(int a, int b){
	    return compute_gain(a)>compute_gain(b);
	}
	
	
	int main(){
		ios::sync_with_stdio(false);
		cin>>N>>K;
		
		for(int i=0; i<K; i++){
			cin>>A[i];
			A[i]-=1;
		}
		sort(A, A+K);
		A[K]=A[0]+N;
		
		for(int i=0; i<N; i++){
			cin>>X[i];
			X[i+N]=X[i];
		}
		
		psum[0]=X[0];
		for(int i=1; i<2*N; i++){
			psum[i]+=psum[i-1]+X[i];
		}
		
		
		for(int i=0; i<K; i++){
			if(A[i+1]==A[i]+2){
				gain[i][2]=0;
				continue;
			
			}
			gain[i][2]=psum[A[i+1]-1]-psum[A[i]];
		}
		
		for(int i=0; i<K; i++){
			if(A[i+1]==A[i]+1){
				gain[i][1]=0;
				continue;
			}
			long long max=0, imax=-1;
			for(int t=A[i]+1; t<A[i+1]; t++){
				long long gaint=psum[ (t+A[i+1]+1)/2 -1] - psum[ (t+A[i])/2 ];
				if(t%2==A[i]%2){
					gaint+=X[ (t+A[i])/2 ]/2;
				}
				if(t%2==A[i+1]%2){
					gaint+=X[ (t+A[i+1])/2 ]/2;
				}
				
				if(gaint>max){
					max=gaint;
					imax=t;
				}
			}
			gain[i][1]=max;
		}
		
		for(int i=0; i<K; i++){
			ind[i]=i;
			ind[K+i]=K+i;
		}
		
		sort(ind, ind+2*K, compare);
		
		long long sum=0, m=0;
		for(int i=0; i<2*K; i++){
			sum+=compute_gain(ind[i]);
			m++;
			if(sum>psum[N-1]/2){
				break;
			}
		}
		
		if(sum>psum[N-1]/2)
			cout<<m;
		else
			cout<<-1;
		return 0;
	}

	```
