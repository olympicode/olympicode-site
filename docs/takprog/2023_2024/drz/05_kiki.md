---
hide:
  - toc
---

# A2 - Kiki

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	Limeni je pokidao državno takmičenje iz programiranja i kao nagradu je dobio neobojeno stablo (povezan acikličan graf)! U pakovanju su takođe bile i dve beskonačno velike kantice sa bojama - plava i crvena. Stablo koje je dobio na poklon je malo specifično po tome što nisu svi čvorovi iste veličine, pa je i različita količina boje koja je potrebna da se oboje različiti čvorovi. Naime, da bi se $i$-ti čvor obojio, potrebno je $a_i$ količine boje iz jedna od kantica.
	
	Osim što je vrhunski programer, Limeni je i šaptač ptica, pa je istrenirao svog papagaja Kikija da igra jednu igru bojenja nad ovim stablom. Pravila igre su sledeća:
	
	* Limeni i Kiki igraju naizmenično, a Limeni igra prvi;
	* Igrač koji je na potezu bira jedan od neobojenih čvorova i boji ga proizvoljnom bojom (plavom ili crvenom), ali tako da nijedan od njegovih suseda nije obojen istom tom bojom;
	* Igra se završava kada više ne postoji čvor koji može biti obojen.
	
	Na kraju igre je pobednik Limeni ukoliko je svaki čvor stabla obojen, a u suprotnom Kiki.
	
	Kako je Kiki jako dobro istreniran i igra optimalno u svakom trenutku, dogovorili su se da Limeni može da u svom prvom potezu oboji proizvoljan broj čvorova proizvoljnim bojama (dakle, moguće je da nekoliko čvorova oboji crvenom bojom, a nekoliko drugih čvorova plavom). Kako bi igra bila što zanimljivija, interesuje ih koliko najmanje boje u svom prvom potezu Limeni mora da potroši tako da zagarantuje pobedu.
	
	Ukoliko postoji više rešenja, ispisati bilo koje.
	
	## Opis ulaza
	
	U prvoj liniji standardnog ulaza, nalazi se jedan prirodan broj $N$, koji predstavlja broj čvorova u stablu.
	
	U drugoj liniji standardnog ulaza, nalazi se $N$ prirodnih brojeva $a_1, a_2, \ldots, a_n$, koji predstavljaju kolika količina boje je potrebno da se čvorovi $1, 2, \ldots, N$ redom oboje.
	
	U narednih $N-1$ linija standardnog ulaza, nalaze se po $2$ prirodna broja. U $i$-tom od $N-1$ redova, data dva prirodna broja $u_i$ i $v_i$ označavaju da postoji grana između čvorova sa indeksima $u_i$ i $v_i$. 
	
	## Opis izlaza
	
	U prvoj liniji standardnog izlaza ispisati najmanju količinu boje $X$ koju Limeni mora da potroši u prvom potezu kako bi osigurao pobedu protiv Kikija.
	
	U drugoj liniji standardnog izlaza ispisati broj $R$ - koliko čvorova Limeni treba da oboji crvenom bojom u prvom potezu.
	U trećoj liniji standardnog izlaza ispisati $R$ prirodnih brojeva, koji predstavljaju skup čvorova koje Limeni treba da oboji crvenom bojom u prvom potezu.
	
	U četvrtoj liniji standardnog izlaza ispisati broj $B$ - koliko čvorova Limeni treba da oboji plavom bojom u prvom potezu.
	U petoj liniji standardnog izlaza ispisati $B$ prirodnih brojeva, koji predstavljaju skup čvorova koje Limeni treba da oboji plavom bojom u prvom potezu.
	
	Ukoliko postoji više rešenja, ispisati bilo koje.
	
	## Primer 1
	
	
	### Ulaz
	
	
	```
	5
	2 2 2 2 2
	1 2
	2 3
	3 4
	4 5
	```
	
	
	
	### Izlaz
	
	
	```
	4
	2
	2 4
	0
	```
	
	## Objašnjenje primera
	
	Jedno od mogućih rešenja jeste da Limeni oboji čvorove $2$ i $4$ crvenom bojom, što zahteva $4$ količine boje. Na ovaj način, u sledećim potezima i Kiki i Limeni su primorani da boje čvorove $1$, $3$ i $5$ plavom bojom, kako ne bi postojala dva susedna čvora iste boje. 
	
	## Primer 2
	
	
	### Ulaz
	
	
	```
	6
	1 2 3 4 5 6
	1 3
	3 5
	3 4
	5 2
	6 5
	```
	
	
	
	### Izlaz
	
	
	```
	8
	1
	3
	1
	5
	```
	
	## Objašnjenje primera
	
	U ovom primeru, optimalno je da Limeni oboji čvorove $3$ i $5$ redom crvenom i plavom i time potroši $8$ količine boje. Do kraja igre čvorovi $1$ i $4$ moraju biti obojeni plavom, a čvorovi $2$ i $6$ crvenom bojom.
	
	
	## Ograničenja
	
	
	* $4 \leq N  \leq 2\cdot 10^5$
	* $1 \leq a_i \leq 10^9$, za $i = 1, 2, \ldots, N$
	
	Test primeri su podeljeni u šest disjunktnih grupa:
	
	* U test primerima vrednim 10 poena: $4 \leq N \leq 20$;
	* U test primerima vrednim 5 poena: Čvor $1$ je povezan sa čvorovima $2, 3, \ldots, N$;
	* U test primerima vrednim 10 poena: Čvor $i$ je povezan sa čvorom $i+1$, za $i=1,2,\ldots,N-1$;
	* U test primerima vrednim 20 poena: $4 \leq N \leq 1000$
	* U test primerima vrednim 20 poena: Sve težine su jednake međusobno, odnosno $a_1 = a_2 = \ldots = a_N$
	* U test primerima vrednim 35 poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Marko Milenković | Marko Milenković | Marko Milenković | Dimitrije Erdeljan |
	
	## Početna zapažanja
	
	Pre svega, jasno je da moramo da koristimo $64$-bitni tip podataka, jer rešenje može biti drastično veće od $2\cdot10^9$.
	
	Zatim, kakvo stanje Limenom definitivno ne donosi pobedu? Primetimo da ukoliko je neki čvor obojen ili ima obojenog suseda, onda neće biti problematičan - u smislu da je isforsirano koja boja će morati da se pojavi na tom čvoru. I zapravo, vrlo lako možemo da pokažemo da ukoliko svi čvorovi ispunjavaju svojstvo da su ili obojeni (bilo kojom bojom) ili je neki od njihovih suseda obojeni (ponovo bilo kojom bojom), onda je to definitivno pobednička pozicija za Limenog. Naravno, lako se i pokazuje da ukoliko ovo ne važi, postoji način da Kiki pobedi (oboji jedan od čvorova koji ne zadovoljavaju svojstvo obrnuto od očekivane boje).
	
	Šta nam je očekivana boja? Jasno je da ukoliko imamo neko rešenje gde neke čvorove bojimo plavom, a neke druge crvenom bojom, takođe je i suprotno bojenje rešenje. Ako se pretvaramo da bojimo samo jednom bojom, onda možemo na kraju samo da vidimo kako da ih raspodelimo sa bojama, jedino je važno da ne postoje dva čvora iste boje na neparnom rastojanju. Npr, ne odgovara ako imamo sekvencu čvorova crveno-neobojeno-neobojeno-crveno, jer unutrašnji čvorovi moraju biti plavi a susedni su. Kada na kraju obojimo 'jednom bojom' stablo, možemo samo da pustimo pretragu u širinu/dubinu od proizvoljnog čvora i u odnosu na parnost dubine odlučujemo koja boja će biti dodeljena tom čvoru ukoliko je predviđeno da bude obojen (npr parne dubine crvenom, neparne plavom). 
	
	Usputno, skup čvorova koji tražimo se naziva [dominantan skup grafa/stabla](https://sr.wikipedia.org/wiki/%D0%94%D0%BE%D0%BC%D0%B8%D0%BD%D0%B0%D0%BD%D1%82%D0%BD%D0%B8_%D1%81%D0%BA%D1%83%D0%BF). Među svim takvim mi biramo minimalan.
	
	## $N \leq 20$
	
	U ovom podzadatku je dovoljno da isprobamo svih $2^N$ mogućih bojenja stabla i vidimo koje je zadovoljavajuće i ima najmanju zbirnu težinu. Vremenska složenost ovog rešenja je $\mathcal{O}(N\cdot 2^N)$.
	
	## Čvor $1$ je povezan sa čvorovima $2, 3, \ldots, N$
	
	Ovakav tip grafova se naziva [zvezda](https://en.wikipedia.org/wiki/Star_(graph_theory)). Jedna varijanta je da obojimo samo čvor $1$. Druga je da obojimo sve ostale čvorove. U oba ta slučaja dobijamo dominantan skup i potrebno je samo da izaberemo onaj čija je suma težina manja. U oba slučaja bojimo čvorove jednom bojom po izboru. Vremenska složenost ovog rešenja je $\mathcal{O}(N)$.
	
	## Čvor $i$ je povezan sa čvorom $i+1$, za $i=1,2,\ldots,N-1$
	
	Ovakav tip grafova se naziva [put](https://en.wikipedia.org/wiki/Path_graph). Sada zadatak praktično postaje: dat je niz i potrebno je da izaberemo elemente tako da je svaki element ili izabran ili neki njegov sused izabran, a tako da je suma tih elemenata minimalna. Ovo možemo rešiti na nekoliko načina, od kojih je najintuitivniji dinamičko programiranje.
	
	Jedno od mogućih stanja jeste $dp[i][0/1][0/1]$ - odnosno kolika je minimalna suma elemenata tako da je do $i$-tog validno izabrano, dok nam druga i treća koordinata označavaju da li su prethodna dva elementa obojena. U slučaju kada prethodna dva nisu obojena, primorani smo da obojimo trenutni, u svim ostalim slučajevima možemo da biramo. Na kraju nas interesuje stanje poslednjeg elementa. Vremenska složenost ovog rešenja je $\mathcal{O}(N)$.
	
	## Sve težine su jednake međusobno
	
	U ovom podzadatku moguće je koristiti greedy pristup. Primetimo da nam nikad nije optimalno da bojimo listove stabla, jer ukoliko njihove roditelje obojimo, veći broj čvorova relaksiramo i dodajemo u dominantni skup. Uz ovaj i slične argumente može se pokazati (dokaz ostavljamo čitaocu) da sledeća strategija funkcioniše:
	
	- Izaberimo čvor $X$ sa najvećim brojem suseda koji su listovi i obojimo taj čvor
	- Brišemo iz stabla čvor $X$ i sve njegove susede stepena manjeg ili jednakog $2$
	- Ponavljamo postupak rekurzivno dok ne budu obrisani svi čvorovi
	
	Podsetnik da bojimo u odgovarajuću boju na osnovu početnih zaključaka. Vremenska složenost ovog pristupa je $\mathcal{O}(N)$ ili $\mathcal{O}(N\log_2 N)$, u zavisnosti od implementacije.
	
	## Rešenje bez dodatnih ograničenja
	
	Za ceo zadatak je potrebno primeniti ponovo dinamičko programiranje. Za čvor kažemo da ima isforsiranu boju (odnosno da je isforsiran čvor) ukoliko je obojen on ili neki njegov sused. 
	
	Za početak ćemo korenovati stablo u proizvoljnom čvoru $r$. Stanje će nam biti $dp[i][0/1]$ - minimalna suma obojenih čvorova u podstablu čvora $i$ tako da je to optimalno bojenje, a pritom čvor $i$ jeste forsiran (ukoliko je druga koordinata $1$), odnosno *nije nužno* forsiran (ukoliko je druga koordinata $0$). 
	
	Preciznije koristimo tehniku bottom-up dinamičkog programiranja. Krećemo od listova stabla i računamo na gore stanja. U red dodajemo čvorove čija su sva deca već obiđena. Za listove postavljamo $dp[l][0] = 0$ i $dp[l][1] = 1$. 
	
	Kada računamo $dp[i][1]$ imamo dva izbora. Prvi jeste da obojimo čvor $i$ i onda deca ne moraju da imaju od ranije isforsiranu boju. Drugi jeste da jedno od dece bude obojeno, zatim deca tog deteta ne moraju da imaju isforsiranu boju, a sva ostala deca čvora $i$ takođe moraju da imaju isforsiranu boju. Po svoj deci tražimo minimmum. Matematički zapisano: $dp[i][1] = min(a[i] + \sum_{x \in deca[i]}dp[x][0], min_{x \in deca[i]}(a[x] + \sum_{y \in deca[x]}dp[y][0] + \sum_{z \in deca[i], z \neq x} dp[z][1]))$.  
	
	Kada računamo $dp[i][0]$ bitno nam je da sva deca čvora $i$ imaju isforsiranu boju, jer im čvor $i$ to neće omogućiti. Tako da je prelaz $dp[i][0] = min(\sum_{x \in deca[i]}dp[x][1], dp[i][1])$.
	
	Na kraju, rešenje je $dp[r][1]$. Vremenska složenost ovog rešenja je $\mathcal{O}(N)$ ili $\mathcal{O}(N \log(N))$, u zavisnosti od implementacije.
	
	## Napomena
	
	Podzadatak $N \leq 1000$ je izostavljen jer predstavlja samo sporiju implementaciju opšteg rešenja.
	
	``` cpp title="05_kiki.cpp" linenums="1"
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
	
	
	const int maxn = 2e5 + 10;
	vi e[maxn], a(maxn);
	vi p(maxn), sub(maxn);
	vector<vi> dp(maxn, vi(2, 0));
	
	void dfs(int x, int y = 0){
	
		p[x] = y;
	
		for (auto& i : e[x]){
			if (i == y) continue;
	
			dfs(i, x);
		}	
	}
	
	vi red, blue;
	
	void povrati(int x, int v, int par = 1){
		if (v == 0 && dp[x][0] < dp[x][1]){
			for (auto& i : e[x]){
				if (i == p[x]) continue;
	
				povrati(i, 1, 1-par);
			}
	
			return;
		}
	
		int s = 0;
		int suma = a[x];
		for (auto& i : e[x]){
			if (i == p[x]) continue;
			suma += dp[i][0];
			s += dp[i][1];
		}
	
		if (suma == dp[x][1]){
			if (par)
				red.push_back(x);
			else
				blue.push_back(x);
	
			for (auto& i : e[x]){
				if (i == p[x]) continue;
	
				povrati(i, 0, 1-par);
			}
	
			return;
		}	
	
		int ind;
		for (auto& i : e[x]){
			if (i == p[x]) continue;
	
			suma = sub[i] + a[i] + s - dp[i][1];
	
			if (suma == dp[x][1]){
				ind = i;
				break;
			}
		}
	
		for (auto& i : e[x]){
			if (i == p[x] || i == ind) continue;
	
			povrati(i, 1, 1-par);
		}
	
		if (par)
			blue.push_back(ind);
		else
			red.push_back(ind);
	
		for (auto& i : e[ind]){
			if (i == x) continue;
	
			povrati(i, 0, par);
		}
	}
	
	signed main()
	{
		int n;
		cin >> n;
	
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
	
			e[i].clear();
		}
	
		for (int i = 1; i < n; ++i){
			int u, v;
			cin >> u >> v;
	
			e[u].push_back(v);
			e[v].push_back(u);
		}
	
		dfs(1);
	
		vi d(n+1, 0);
		queue<int> q;
	
		for (int i = 2; i <= n; ++i){
			if ((int)e[i].size() == 1){
				q.push(i);
				dp[i][0] = 0;
				dp[i][1] = a[i];
			}
		}
	
		while(!q.empty()){
			int c = q.front();
			q.pop();
	
			++d[p[c]];
	
			if ((int)e[c].size() == 1 && c != 1){
	
				if (d[p[c]] == (int)e[p[c]].size() && p[c] == 1){
					q.push(1);
				}
	
				if (d[p[c]] + 1 == (int)e[p[c]].size() && p[c] != 1){
					q.push(p[c]);
				}
	
				continue;
			}
	
			dp[c][1] = a[c];
			int s = 0;
			for (auto& i : e[c]){
				if (i == p[c]) continue;
				dp[c][1] += dp[i][0];
				s += dp[i][1];
			}
	
			for (auto& i : e[c]){
				if (i == p[c]) continue;
	
				dp[c][1] = min(dp[c][1], sub[i] + a[i] + s - dp[i][1]);
				
			}
	
			dp[c][0] = s;
	
			dp[c][0] = min(dp[c][0], dp[c][1]);
	
			for (auto& i : e[c])
				if (i != p[c])
					sub[c] += dp[i][0];
	
	
			if (d[p[c]] == (int)e[p[c]].size() && p[c] == 1){
				q.push(1);
			}
	
			if (d[p[c]] + 1 == (int)e[p[c]].size() && p[c] != 1){
				q.push(p[c]);
			}			
		}
	
		povrati(1, 1);
	
	
		cout << dp[1][1] << '\n';
	
		cout << red.size() << '\n';
		for (int x : red)
			cout << x << ' ';
		cout << '\n';
	
		cout << blue.size() << '\n';
		for (int x : blue)
			cout << x << ' ';
		cout << '\n';
	}
	```
