---
hide:
  - toc
---

# 2 - Arhitekta

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 128MB |
	
	Kralj Bajtovije želi da poveže svojih $N$ gradova putevima. On trenutno razmatra $M$ puteva, od kojih $i$-ti povezuje gradove $u_i$ i $v_i$. Za svaki od tih $M$ puteva poznata je i vrednost $w_i$ - cena izgradnje $i$-tog puta. Kralj želi da poveže svoje gradove tako da je od bilo kog grada moguće stići do bilo kog drugog grada koristeći izgrađene puteve. Tu Vi stupate na scenu.
	
	
	Vi ste čuveni arhitekta Milivoje Felipe Sančo Gomez Rozario don Karlos, poznatiji pod imenom Milivoje Felipe Gomez Rozario don Karlos. Kada ste saslušali kralja, objasnili ste mu da je cena izgradnje nekog skupa puteva upravo bitovska disjunkcija cene izgradnje svih puteva iz tog skupa.
	
	
	Pomozite kralju i izaberite neke puteve tako da je moguće od bilo kog grada stići do bilo kog drugog grada i da je pritom cena najmanja moguća.
	
	## Opis ulaza
	
	U jedinom redu standardnog izlaza ispisati jedan ceo broj - minimalna cena izgradnje nekog skupa puteva tako da je od svakog grada moguće stići do svakog drugog grada koristeći neke od ovih puteva. Garantuje se da je uvek moguće ispuniti ovaj uslov.
	
	## Opis izlaza
	
	U jedinom redu standardnog izlaza ispisati jedan ceo broj - minimalna cena izgradnje nekog skupa puteva tako da je od svakog grada moguće stići do svakog drugog grada koristeći neke od ovih puteva. Garantuje se da je uvek moguće ispuniti ovaj uslov.
	
	## Ograničenja
	
	 * $1 \leq N \leq 10^5$.
	 * $1 \leq M \leq 2 \cdot 10^5$.
	 * $1 \leq u_i < v_i \leq N$ za svako $1 \leq i \leq M$.
	 * Za svake $1 \leq i \neq j \leq M$ važi $u_i \neq u_j$ ili $v_i \neq v_j$.
	 * $0 \leq w_i \leq 10^9$.
	 * Garantuje se da je uvek moguće stići od bilo kog grada do bilo kog drugog grada izgradnjom nekih od $M$ puteva.
	
	## Podzadaci
	
	 1. (6 poena) $M = N - 1$.
	 2. (14 poena) $N = M$ i važe ograničenja $u_i = i$ i $v_i = i + 1$ za svako $1 \leq i \leq M -  1$ i $u_M = 1$ i $v_M = N$.
	 3. (13 poena) $0 \leq w_i \leq 1$.
	 4. (26 poena) $1 \leq M \leq 10^3$ i $0 \leq w_i \leq 10^3$ za svako $1 \leq i \leq M$.
	 5. (41 poen) Nema dodatnih ograničenja.
	
	
	## Primeri
	
	### Primer 1
	
	#### Ulaz
	
	~~~
	4 4
	1 2 4
	1 3 6
	2 4 1
	1 4 2
	~~~
	
	#### Izlaz
	
	~~~
	6
	~~~
	
	#### Objašnjenje primera
	
	Izgradićemo puteve između gradova $1$ i $2$, gradova $1$ i $3$ i gradova $1$ i $4$. Cena izgradnje prvog puta je $4$, drugog je $6$, dok je cena izgradnje trećeg od navedenih puteva $2$. Bitovska disjunkcija ovih brojeva je upravo $6$. Može se proveriti da nije moguće izabrati puteve tako da svi gradovi budu povezani putevima, a da cena ukupne izgradnje puteva bude manja. 
	
	## Napomena
	
	Operator bitovske disjunkcije u Pascal-u je označen sa `or`, dok u C++ ga zapisujemo pomoću simbola `|`. Ova operacija $x\ \text{or} \ y$ se za nenegativne cele brojeve $x,y$ definiše na sledeći način. Prvo se brojevi zapišu u binarnom zapisu. Ukoliko jedan broj ima manje cifara od drugog, dopisuju mu se vodeće nule sve dok ne budu imali isti broj binarnih cifara. Tako se dobijaju dva niza binarnih cifara, označimo ih sa $a_1, \ldots, a_k$ i $b_1, \ldots b_k$. Zatim se za svaku poziciju $i \in \{1, \ldots, k \}$ računa $c_i$ pomoću sledećih pravila:
	
	* Za $a_{i} = 0, b_{i} = 0$ važi $c_{i} = 0$
	* Za $a_{i} = 0, b_{i} = 1$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 0$ važi $c_{i} = 1$
	* Za $a_{i} = 1, b_{i} = 1$ važi $c_{i} = 1$
	
	Niz binarnih cifara $c_1, \ldots, c_k$ (koji možda ima vodeće nule) je binarni zapis rezultata, odnosno broja $x \ \text{or} \  y$.
	
	Bitovska disjunkcija između $n$ elemenata $x_{1},x_{2},...,x_{n}$ definiše se kao $x_{1} \ \text{or} \ x_{2}  \ \text{or} \  ...  \ \text{or} \  x_{n} = (...(((x_{1}  \ \text{or} \  x_{2})  \ \text{or} \  x_{3}) \ \text{or} \ x_{4})...)  \ \text{or} \  x_{n}$.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Milisavljević | Aleksa Milisavljević | Mladen Puzić | Aleksa Plavšić |
	
	## Rešenje kada $M = N-1$
	U ovom podzadatku moramo odabrati sve putevi da bismo konstruisali odgovarajući plan. Nađimo bitovsku disjunkciju cena svih grana. Vremenska i memorijska složenost je $O(N)$.
	
	## Rešenje kada skup puteva pravi ciklus
	U ovom podzadatku, moramo odabrati sve puteve sem jednog, gde možemo bilo koji izostaviti. Možemo prebaciti ovaj graf u niz dužine $N$, gde čuvamo cene puteva redom. Da bismo efikasno našli bitovsku disjunkciju svih puteva sem jednog, čuvaćemo prefiksnu i sufiksnu bitovsku disjunkciju tog niza. Rešenje je onda bitovska disjunkcija odgovarajućeg prefiksa i sufiksa. Od svih mogućih opcija, biramo onu koja daje najjeftiniji plan. Vremenska i memorijska složenost je $O(N)$.
	
	## Rešenje kada $0 \leq w_i \leq 1$
	Bitovska disjunkcija brojeva iz skupa $\{0, 1\}$ može biti 0 samo ako su svi brojevi $0$. U suprotnom ona je $1$. Zato, proverimo da li kada uzmemo sve puteve cene $0$ dobijemo državu u kojoj je svaki grad povezan sa svakim drugim. Ukoliko da, rešenje je $0$, u suprotnom, rešenje je $1$. Ovo možemo proveriti na primer **DFS** algoritmom. Vremenska i memorijska složenost je $O(N+M)$.
	
	## Rešenje kada $1 \leq M, w_i \leq 10^3$
	Pošto su cene puteva do $1000$, onda je najveći mogući rezultat $1023$. Proverićemo sve moguće ukupne cene jednu po jednu od najmanje ka najvećoj. Recimo da proveravamo rezultat $x$. Prođimo redom kroz sve grane i dodajmo samo one koje možemo, tako da $x$ ostane moguć rezultat. U ovom slučaju, to znači da ni na jednoj poziciji u binarnom zapisu nema cifru $1$, a da je u broju $x$ ta cifra $0$. Kada dodamo sve te grane, kao u prethodnom podzadatku proverimo da li je moguće stići od svakog grada do svakog drugog koristeći te grane. Ako da, i to je najmanje takvo $x$, to je rešenje. Vremenska složenost je $O(M\cdot \max(w_i))$, a memorijska $O(N+M)$.
	
	## Glavno rešenje
	Umesto da fiksiramo mogući rezultat kao u prethodnom zadatku, gradićemo rezultat bit po bit, krenuvši od najvrednijeg bita. Pošto važi da je $2^{0} + 2^{1} + \ldots + 2^{i} \leq 2^{i+1}$, u interesu nam je da najvredniji bit bude što manji. Pokušajmo prvo da izbegnemo najvredniji bit. Dodajmo sve grane u čijim težinama je ta cifra $0$. Ukoliko možemo da napravimo plan samo sa tim granama, stavljamo $0$ na tu cifru rezultata, a izbacujemo iz skupa grana sve grane čijoj ceni je ta cifra $1$, jer su nepotrebne. Ukoliko ne možemo, onda stavljamo $1$ na tu cifru, ali održavamo isti skup grana (neophodne su nam obe vrste). U oba slučaja, prelazimo na sledeći bit na isti način. Na kraju, imaćemo konstruisani rezultat. Vremenska složenost je $O(M\log(w_i))$, a memorijska $O(N+M)$. 
	
	``` cpp title="02_arhitekta.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 300000
	using namespace std;
	struct edge
	{
	    int u, v, w;
	};
	
	int n, m;
	edge edges[maxn];
	vector<int> graph[maxn];
	bool vis[maxn];
	
	
	void clear()
	{
	
	    for(int u = 1; u <= n; u++) {
	
	        graph[u].clear();
	        vis[u] = false;
	
	    }
	
	}
	
	void construct_graph(int max_w)
	{
	
	    for(int i = 1; i <= m; i++) {
	
	        if( (max_w & edges[i].w) == edges[i].w) {
	
	            graph[edges[i].u].push_back(edges[i].v);
	            graph[edges[i].v].push_back(edges[i].u);
	
	        }
	
	    }
	
	}
	
	int dfs_tree_size(int u)
	{
	
	    vis[u] = true;
	    int ret = 1;
	
	    for(int v : graph[u]) {
	
	        if(!vis[v]) {
	
	            ret += dfs_tree_size(v);
	
	        }
	
	    }
	
	    return ret;
	
	}
	
	int main()
	{
	
	    scanf("%d %d", &n, &m);
	
	    for(int i = 1; i <= m; i++) {
	
	        int u, v, w;
	        scanf("%d %d %d", &u, &v, &w);
	        edges[i] = {u, v, w};
	
	    }
	
	    int ans = 0;
	    int bit = (1 << 30);
	
	    while(bit > 0) {
	
	        clear();
	        construct_graph(ans | (bit - 1) );
	
	        if(dfs_tree_size(1) != n) {
	
	            ans |= bit;
	
	        }
	
	        bit >>= 1;
	
	    }
	
	    printf("%d", ans);
	    return 0;
	
	}

	```
