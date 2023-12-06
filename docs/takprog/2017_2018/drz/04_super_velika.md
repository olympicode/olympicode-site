---
hide:
  - toc
---

# A1 - Super velika matrica

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 3000ms | 64MB |
	
	Zli duh Milojica je rešio da uništi veliki grad Pajazitovo. Pajazitovo je zanimljiv grad, sastoji se samo od zgrada. Ukupno se nalazi $n$ zgrada u Pajazitovu, visina $i$-te zgrade iznosi $A_i$. Kako je uništenje jednog tako kompleksnog grada veoma teško, Milojica je u pohod pozvao i njegovih $m$ dece. Svako dete ima sposobnost da jednim strujnim udarom smanji visinu zgrade u određenom intervalu za $1$. Dete sa rednim brojem $i$ može smanjiti visine zgrada u intervalu [$L_i, R_i$]. Mali duhovi jako slabašna stvorenja, oni mogu ograničen broj puta da iskoriste strujni udar. Dete sa rednim brojem $i$ može iskoristiti ne više od $K_i$ strujnih udara, nakon toga trajno gubi tu moć. Jednu zgradu može napasti više duhova, i svaki duh može napasti više zgrada.
	
	Kako Milojica nije tako dobar sa matematikom, zamolio vas je da ispitate da li njegovih $m$ dece mogu uništiti Pajazitovo u potpunosti. Pajazitovo se smatra uništenim u potpunosti ako sve zgrade imaju visinu $0$.
	
	Šta više Milojica nije siguran koji grad je tačno Pajazitovo(duhovi sa toliko dece znaju ponekad da pomešaju gradove), tako da želi da sakupi informacije o mogućem uništenju $t$ različitih gradova.
	
	## Opis ulaza
	U prvoj liniji standardnog ulaza nalazi se prirodan broj $t$, broj gradova za koje je potrebno ispitati da li je moguće uništenje.
	
	Svaki od $t$ gradova je opisan sa $5$ linija:
	
	U prvoj liniji se nalaze prirodni brojevi $n$, $m$, broj zgrada u Pajazitovu i broj Milojičine dece.
	
	U drugoj liniji se nalazi niz $A$ od $n$ brojeva, $A_1$, $A_2$, $\dots$, $A_n$, visine svake od $n$ zgrada redom.
	
	U trećoj liniji se nalazi niz $L$ od $m$ brojeva, $L_1$, $L_2$, $\dots$, $L_m$, levi krajevi intervala za svako dete.
	
	U četvrtoj liniji se nalazi niz $R$ od $m$ brojeva, $R_1$, $R_2$, $\dots$, $R_m$, desni krajevi intervala za svako dete.
	
	U petoj liniji se nalazi niz $K$ od $m$ brojeva, $K_1$, $K_2$, $\dots$, $K_m$, maksimalni broj strujnih udara za svako dete.
	
	## Opis izlaza
	Na standardnom izlazu u $t$ linija ispisati rešenje zadatka. U $i$-toj liniji ispisati `DA` ukoliko Milojičina deca mogu uništiti $i$-ti grad, u suprotnom ispisati `NE`.
	
	## Primer 1
	### Ulaz
	```
	2
	3 2
	1 4 2
	1 2
	3 3
	3 4
	1 1
	10
	1
	1
	6
	```
	
	### Izlaz
	```
	DA
	NE
	```
	
	## Objašnjenje primera
	Želimo da saznamo informacije za $2$ grada.
	
	U prvom gradu postoje tri zgrade visina redom ($1, 4, 2$), Milojica vodi $2$ deteta. Prvo dete može napadati bilo koju zgradu u intervalu [$1, 3$] i može da izvrši najviše $3$ strujna udara. Drugo dete može napadati zgrade u intervalu [$2, 3$] i ukupno može izvršiti $4$ strujna udara. Deca mogu uništiti zgrade u potpunosti, jedan od mogućih redosleda operacija:
	
	- prvo dete izvrši $1$ strujni udar na prvoj zgradi i uništi prvu zgradu
	- drugo dete izvrši $4$ strujna udara na drugoj zgradi i uništi drugu zgradu 
	- prvo dete izvrši preostala $2$ strujna udara na trećoj zgradi i uništi treću zgradu
	
	U drugom gradu postoji samo jedna zgrada visine $10$ i Milojica ima jedno dete koje može smanjiti visinu zgrade najviše za $6$. Nije moguće uništiti zgradu u potpunosti.
	
	## Ograničenja i podzadaci
	
	* $1 \leq t \leq 7$.
	* $1 \leq n,m \leq 10^5$.
	* $1 \leq A_i, K_i \leq 10^9$.
	* $1 \leq L_i \leq R_i \leq n$.
	
	Postoje tri podzadatka: 
	
	* Podzadatak $1$ [$20$ poena]: $1 \leq n, m, A_i \leq 100$.
	* Podzadatak $2$ [$30$ poena]: $1 \leq n, m \leq 10^3$.
	* Podzadatak $3$ [$50$ peona]: Nema dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Dragan Urošević | Dragan Urošević | Ivan Stošić |
	
	Ovaj problem se može rešiti korišćenjem pohlepnog algoritma. Rušimo redom zgrade počevši od prve. Ako trenutno rušimo $i$-tu zgradu onda možemo odrediti skup dece $\{j_1, j_2, ..., j_p\}$ koji mogu da učestvuju u rušenju te zgrade (tj. broj $i$ pripada intervalima zgrada koje mogu rušiti ta deca-duhovi). Ako ne postoji nijedno dete koje može rušiti tu zgradu, onda grad ne može biti uništen. Ako postoji bar jedno dete koje može rušiti tu zgradu, onda biramo ono dete iz skupa $\{j_1, j_2, ..., j_p\}$ koje ima najmanju vrednost za $R$, odnosno čiji interval zgrada koje može rušiti se najranije završava. 
	
	Ako je broj preostalih spratova manji od broja strujnih udara koje ima na raspolaganju to dete, onda uništimo zgradu, notiramo da se broj strujnih udara tog deteta smanjio za broj porušenih spratova i prelazimo na sledeću zgradu. 
	
	Ako je broj strujnih udara manji ili jednak od visine te zgrade, onda primenimo sve strujne udare tog deteta i smanjimo visinu zgrade za broj primenjenih strujnih udara. Kako je to dete već potrošilo svoju moć, izbacujemo ga iz skupa dece koju možemo koristiti za rušenje. Ako je visina zgrade postala nula, onda je ona porušena i prelazimo na sledeći zgradu. 
	
	Pri prelasku na sledeću zgradu, moramo ažurirati skup dece koja mogu biti korišćena za rušenje: izbacuju se ona deca kod kojih je desni kraj intervala manji od trenutne zgrade i dodaju deca čiji je levi kraj jednak indeksu te zgrade. 
	
	Da bi ubrzali taj postupak dodavanja dece koju možemo koristiti za rušenje, deca se na početku sortiraju po levim krajevima intervala. 
	
	Kako bi efikasno birali dete koje će rušiti zgradu (tj. dete koje ima najmanji desni kraj), decu koja mogu rušiti trenutnu zgradu držimo u prioritetnom redu.
	Složenost dela za sortiranje dece je $O(n\log n)$, a složenost rušenja će biti $O((n+m)\log n)$
	
	``` cpp title="04_super_velika.cpp" linenums="1"
	#include<bits/stdc++.h>
	
	using namespace std;
	
	const int maxi=5e5+5;
	
	priority_queue<pair<int,int>> pq;
	int l[maxi],r[maxi],k[maxi],a[maxi];
	int n,m;
	vector<int> v[maxi];
	
	void clear()
	{
	    for (int i=1;i<=n+1;i++)
	        v[i].clear();
	
	    while(!pq.empty())
	        pq.pop();
	}
	void solve()
	{
	  scanf("%d%d",&n,&m);
	  clear();
	
	  for (int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	
	  for (int i=1;i<=m;i++)
	  {
	      scanf("%d",&l[i]);
	      v[l[i]].push_back(i);
	  }
	  for (int i=1;i<=m;i++)
	      scanf("%d",&r[i]);
	
	  for (int i=1;i<=m;i++)
	      scanf("%d",&k[i]);
	
	  for (int i=1;i<=n;i++)
	  {
	      for (int j:v[i])
	      pq.push({-r[j],j});
	
	      while(a[i]>0 && !pq.empty())
	      {
	          pair<int,int> value=pq.top();
	          int idx= value.second;
	          pq.pop();
	          if (r[idx]>=i)
	          {
	              int sub=min(k[idx],a[i]);
	              k[idx]-=sub;
	              a[i]-=sub;
	              if (k[idx]>0) pq.push({-r[idx],idx});
	          }
	      }
	
	      if (a[i]>0)
	      {
	          printf("NE\n");
	          return;
	      }
	  }
	
	  printf("DA\n");
	  return;
	}
	
	int main()
	{
	    int t;
	    cin>>t;
	
	    while(t--)
	        solve();
	
	  return 0;
	}

	```
