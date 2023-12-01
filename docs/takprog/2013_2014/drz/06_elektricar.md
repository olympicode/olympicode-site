---
hide:
  - toc
---

# A3 - Električar

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 500ms | 64MB |
	
	Sa početkom proleća, počinju i određeni problemi u gradovima širom Srbije. Naime, jaki prolećni vetrovi su oštetili kablove za struju između svih bandera i sprečili građane u standardnim prolećnim aktivnostima – gledanju TV-a i programiranju.
	
	Grad možemo zamisliti kao $x$-osu na kojoj se nalazi $n$ bandera i $m$ kuća zadatih svojim koordinatama. Za svaku banderu je poznata cena održavanja $c_i$ i svaka bandera može biti povezana kablom sa najviše jednom banderom i to samo ako su na rastojanju ne većem od $D$. Cena kabla po jediničnoj dužini je $S$. Za kuću kažemo da je snabdevena strujom ukoliko iznad nje prolazi kabl tj. ukoliko postoji bar jedan par bandera koji je povezan kablom i od kojih je jedna levo a druga desno u odnosu na pomenutu kuću.
	
	Cena proizvoljnog sistema povezivanja bandera jednaka je **(zbir cena održavanja svih bandera koje sadrže jedan kraj kabla) + (ukupna dužina kablova puta $S$)**. Poznati električar Raša je pozvan u pomoć da poveže neke bandere kablovima tako da je svaka kuća snabdevena strujom. On je izračunao cenu najjeftinijeg takvog sistema i ispostavilo se da je to $C$.  Međutim, on je izgubio papirče na kome je bila napisana cena kabla po jediničnoj dužini $S$. Pomozite mu da odredi tu cenu ako su vam poznati svi prethodni podaci i činjenica da je $S$ prirodan broj.
	
	## Ulaz
	U prvom redu standardnog ulaza nalaze se $4$ prirodna broja - $n$, $m$, $D$ i $C$, tim redom, koji predstavljaju odgovarajuće podatke iz teksta zadatka. U narednom redu nalaze se $n$ prirodnih brojeva; $i$-ti broj predstavlja cenu održavanja $i$-te bandere.  U narednom redu nalaze se još $n$ prirodnih brojeva u rastućem poretku; $i$-ti broj predstalja koordinatu $i$-te bandere na $x$-osi. U poslednjem redu nalazi se $m$ prirodnih brojeva koji predstavljaju koordinate kuća na $x$-osi. Sve koorinate na $x$-osi su različite.
	
	## Izlaz
	U prvom i jedinom redu standardnog izlaza ispisati prirodan broj $S$. Garantuje se da će rešenje uvek postojati. Ako postoji više rešenja, ispisati bilo koje.
	
	## Primer 1
	### Ulaz
	```
	4 2 12 32
	1 5 17 3
	1 5 15 17
	9 10
	```
	
	### Izlaz
	```
	2
	```
	
	## Objašnjenje primera
	Imamo $4$ bandere na koorinatama $1$, $5$, $15$, $17$ i cenama održavanja $1$, $5$, $17$, $3$, tim redom, kao i $2$ kuće na koordinatama $9$ i $10$. Bandere se mogu povezivati samo ako rastojanje između njih nije veće od $12$ i poznato je da je cena optimalnog sistema jednaka $32$. Primetimo da u optimalnom sistemu ne učestvuje prva bandera jer nju možemo povezati samo sa drugom (ostale su udaljene za više od $12$) a u tom slučaju nijednu kuću nije moguće snabdeti strujom (banderu možemo povezati sa najviše jednom banderom). Prema tome jedine dve mogućnosti za sistem u kome je svaka kuća snabdevena strujom je povezivanje $2.$ i $3.$ ili $2.$ i $4.$ bandere.
	
	U prvom slučaju ($2.$ i $3.$), ukupna cena je $c_2+c_3+|5-15|\cdot S = 22+10S = C = 32$ odakle dobijamo da je $S=1$. Međutim, ako je $S=1$, možemo povezati $2.$ i $4.$ banderu pri čemu dobijamo dobar sistem sa cenom $c_2+c_4+|5-17|\cdot S=20 < C$ što je nemoguće (cena najjeftinijeg sistema je $C$).
	
	U drugom slučaju ($2.$ i $4.$), ukupna cena je $c_2+c_4+|5-17|\cdot S=32$ odakle dobijamo $S=2$. Za ovu vrednost broja $S$ je $C$ zaista najjeftinija cena dobrog sistema (jeftinija od jedine preostale mogućnosti) pa $S=2$ zadovoljava uslove zadatka.
	
	## Ograničenja
	
	* $1\leq n, m \leq 300.000$.
	* Koordinate bandera i kuća i cene održavanja bandera su celi brojevi iz segmenta $[1, 10^9]$.
	* $1\leq D,C\leq 10^9$.
	
	Test primeri su podeljeni u pet disjunktnih grupa:
	
	* U test primerima vrednim $20$ poena važi $n, m, C\leq 100$.
	* U test primerima vrednim $20$ poena važi $n\leq 1.000$.
	* U test primerima vrednim $20$ poena važi $D=10^9$.
	* U test primerima vrednim $20$ poena važi $n\leq 50.000$.
	* U test primerima vrednim $20$ poena nema dodatnih ograničenja.
	

=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Nikola Milosavljević | Nemanja Majski | Marko Baković |
	
	## Opšta opažanja
	Recimo da nam je poznata vrednost $S$ i želimo da izračunamo $C$. Kasnije ćemo rešiti i obrnut problem.
	
	Prvo što treba da shvatimo je da nikada neće dva kabla ići jedan preko drugog. To možemo da dokažemo preko kontradikcije. Pretpostavimo suprotno, da je optimalno da na nekom mestu imamo dva kabla koji idu jedan preko drugog. Neka su njihovi počeci i krajevi redom ($a_1$,$b_1$) i ($a_2$,$b_2$). Cena održavanja tih kablova sigurno nije manja od cena održavanja kabla ($min(a_1,a_2)$, $max(b_1,b_2)$), a taj kabl prekriva sve kuće koje prekriva barem jedan od ova dva kabla.
	
	Takođe je važno uočiti da nikada nije optimalno imati kabl koji ne prelazi preko ni jedne kuće, pošto njegovo sklanjanje smanjuje cenu, a uslov je još uvek ispunjen.
	
	Neka grupa bandera predstavlja podniz uzastopnih bandera tako da između njih nema kuća, a direktno levo i direktno desno od nje je kuća, ili uopšte nema ni kuća ni bandera. Potrebani i dovoljni uslovi za pokrivanje svih kuća kablovima su:
	
	- Ne postoje dva kabla čiji se intervali presecaju.
	- U svakoj grupi bandera niti počinje, niti se završava neki kabl, ili počinje i završava se tačno jedan kabl.
	- Prva i poslednja grupa su izuzetak od prethodnog pravila, u njima počinje, odnosno završava tačno jedan kabl.
	
	Nakon što smo podelili bandere u grupe, nas je baš briga gde se nalaze kuće. Sada želimo da izračunamo vrednost $dp[i]$ što je minimalna cena da se uslov ispuni za prefiks bandera dužine $i$.
	
	Prvo ćemo shvatiti da $dp[i]$ ne može da bude veći od bilo kog $dp[j]$ gde je $j \le i$ i bandere sa indeksima $i$ i $j$ su u istoj grupi, pošto mi možemo samo kabl da spojimo sa banderom $j$ i bandere posle nje da ignorišemo.
	
	Sada ćemo pretpostaviti da je optimalno da banderu $i$ spajamo sa nekom banderom $j$. Važno je da te dve bandere nisu u istoj grupi, da $j$ nema kuću direktno sa leve strane i da $i$ nema kuću direktno sa desne strane, kao i da bandere $i$ i $j$ nisu na većoj udaljenoti od $D$. Ukoliko to važi, onda je $dp[i]= a_i \cdot S + c_i + dp[j-1] + c_j - a_j\cdot S$.
	
	Koristeću formulu gore možemo da izračunamo $dp[i]$ za sve vrednosti $i$, uz specijalan slučaj da je $dp$ u prvoj grupi jednako 0.
	
	Sada smo našli za $S$ vrednost $C$, kako obrunuto? Važno je shvatiti da važi $S \le C$ pošto postoji barem jedna kuća. To znači da mi možemo da tražimo vrednost $S$ takvu da je vrednost optimalnog postavljanja jednaka $C$.
	
	Predlažemo da se rešenja za podzadatke čitaju redom pošto je u pitanju samo optimizacija gore opisanog rešenja.
	
	## Rešenje za $n,m,C \le 100$
	U ovom podzadatku je dovoljno da implementiramo metod opisan gore. Razpoređivanje u grupe možemo da prekalkulišemo grubom silom, nakon toga možemo raditi linearnu pretragu po $S$ i koristiti $n^2$ dp. Vremenska složenost ovog rešenja je $O(MN + CN^2)$.
	
	## Rešenje za $n\le 1000$
	U ovom podzataku umesto da radimo grubu silu kako bismo rasporedili bandere u grupe, možemo da koristimo tehniku dva pokazivača.
	
	Takođe, primetimo da je funkcija $C(S)$ rastuća, tako da mi možemo binarno pretraživati vrednost $S$.
	
	Jedini spor deo ovog pristupa je samo dinamičko programiranje čija je složenost $O(n^2)$.
	
	Ukupna vremenska složenost je $O(m+n+n^2 log C)$.
	
	## Rešenje za $D=10^9$
	Neka niz $a_i$ označava poziciju $i$-te bandere na $x$ osi.
	
	U ovom podzataku ne moramo da se brinemo oko toga koliko je dugačak kabl. Definisaćemo $b[i]=dp[i-1] + c_i - a_i\cdot S$. Sada je formula za spajanje bandere $i$ sa banderom $j$: $$a_i\cdot S +c_i + b_j$$
	Sada samo za svako $i$ moramo da pamtimo najbolji prethodni $b_j$ (naravno, takav da važe prethodno pomenu ti uslovi). Pošto je dužina kabla neograničena, to možemo da čuvamo u jednoj promenljivoj maksimuma.
	
	Što se tiče najbolje vrednosti $dp$ u grupi, to isto možemo da radimo preko promenljive. Vremenska složenost je $O(M+N+Nlog C).$
	
	## Glavno rešenje
	
	Najmanje $j$ koje možemo uzeti možemo da čuvamo preko jednog pokazivača koji ćemo da pomeramo kako idemo kroz $i$. Sada na neki način moramo da dinamički ubacujemo i izbacujemo elemente od kojih tražimo minimum. Za to možemo koristiti strukturu podataka "set". Vremenska složenost je $O(N+M + N \cdot log N \cdot log C).$
	
	Rešenje koje umesto seta koristi korensku dekompoziciju je pokriveno podzadatkom gde je $N\le 50.000$.
	
	``` cpp title="06_elektricar.cpp" linenums="1"
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	#include <set>
	
	using namespace std;
	
	const int MaxN = 300300;
	const long long INF = 2000000000000000000LL;
	
	struct Pole
	{
		int x, c;
		bool hasHouseOnTheLeft;
		long long extraVal;
	
		Pole() {}
		Pole(int _x, int _c)
		{
			x = _x; c = _c;
		}
	};
	
	int n, m, C, D;
	Pole poles[MaxN];
	int hx[MaxN];
	long long sol[MaxN];
	long long deQueue[2 * MaxN];
	
	// vraca optimalnu cenu sistema za dato S
	long long solve(int S)
	{
		sol[0] = 0LL;
		int first = 0, last = -1;
		for (int i = 1; i <= n; i++)
		{
	
	// --------------- racunanje optimalnog uparivanja 100p ---------------------- */
			long long optimalPairVal = INF;
			
			while (first <= last && poles[i].x - poles[ deQueue[first] ].x > D)
			{
				first++;
			}
			
			if (first <= last)
			{
				optimalPairVal = poles[ deQueue[first] ].extraVal + (long long)(S) * (long long)(poles[i].x) + poles[i].c;
			}
	
			if (!poles[i].hasHouseOnTheLeft)
			{
				poles[i].extraVal = sol[i - 1] - (long long)(S) * (long long)(poles[i].x) + poles[i].c;
				while (first <= last && poles[i].extraVal <= poles[ deQueue[last] ].extraVal)
				{
					last--;
				}
				deQueue[++last] = i;
			}
	// --------------------------------------------------------------------------- */
	
			if (poles[i].hasHouseOnTheLeft) // ako je (odmah) levo od i-te bandere kuca, uparivanje sigurno posotji i moramo ga izvrsiti 
			{
				sol[i] = optimalPairVal;
			}
			else
			{
				sol[i] = min(sol[i - 1], optimalPairVal); // inace uzimamo bolju od varijante upariti ili ne upariti (ako ne postoji uparivanje, min(sol[i - 1], INF) = sol[i - 1])
			}
	
		}
	
		return sol[n];
	}
	
	int main()
	{
		scanf("%d%d%d%d", &n, &m, &D, &C);
		for (int i = 1; i <= n; i++)
			scanf("%d", &poles[i].c);
		for (int i = 1; i <= n; i++)
			scanf("%d", &poles[i].x);
		for (int i = 1; i <= m; i++)
			scanf("%d", &hx[i]);
	
		// prvo odredimo za svaku banderu da li je odmah levo od nje kuca
	
		int ind = 1;  // indeks trenutne kuce
		poles[1].hasHouseOnTheLeft = false;
		for (int i = 2; i <= n; i++)
		{
			poles[i].hasHouseOnTheLeft = (poles[i].x > hx[ind] && hx[ind] > poles[i - 1].x);
			while (ind < m && hx[ind] < poles[i].x) ind++;
		}
	
		// S nalazimo uz pomoc binarne pretrage
	
		int left = 1, right = C, mid;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			long long val = solve(mid);
			if (val == C)
			{
				printf("%d\n", mid);
				return 0;
			}
	
			if (val < C)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	
		return 0;
	}
	```
