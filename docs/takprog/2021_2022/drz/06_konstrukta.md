---
hide:
  - toc
---

# A3 - Konstrukta

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1600ms | 256MB |
	
	
	Verovatno ste svi čuli za Evroviziju, jedno od najpoznatijih svetskih muzičkih takmičenja. Ove godine, na Evroviziji će učestvovati tačno $N$ država. Prošlogodišnji pobednik takmičenja, Svanzibarija, je odustao iz nepoznatih razloga. Kako se finalno takmičenje približava, potrbeno je odlučiti se koja od $N$ država učesnica će orgainzovati finale. Između ovih $N$ država postoji tačno $N-1$ direktnih autobuskih linija, koje povezuju pojedine parove država. Linije koja povezuje dve države ne prolaze kroz neku od ostalih države. Garantuje se da su linije tako konstruisane da je moguće otputovati od bilo koje države do bilo koje druge određenim podskupom linija. Ne zaboravite, ove $26101997$. godine avioni su prestali da lete i jedino prevozno sredstvo su autobusi.
	
	Organizatori žele najbolje moguće uslove za sve takmičare, oni su odlučili da organizuju takmičenje u državi u kojoj svi takmičari mogu stići što je brže moguće. Ovo podrazumeva da maksimalan broj linija koje moraju predstavnici jedne države da promene da bi došli do mesta finala bude što je manji moguć.
	
	Naravno, to nije sve! Da bi dodatno olakšali put, organizatori su rešili da konstruišu tačno još jednu direktnu autobusku liniju između dve različite države između koje ona do sada nije postojala. Na taj način, broj linija koji će predstavnici pojedinih država promeniti da bi došli do finala može da se smanji.
	
	Pomozite organizatorima da odluče između koje dve države će konstruisati direktnu autobusku liniju i gde će se održati finale Evrovizije.
	
	**Napomena**: Vaša odluka se smatra ispravnom ako ne postoji neki drugi način za konstruisanje dodatne autobuske linije i biranje mesta održavanja finala koji dovodi do toga da broj linija koji pređu predstavnici najudaljenije države bude manji.
	
	## Opis Ulaza
	
	Prvi red standardnog ulaza sadrži prirodan broj $N$, broj država koje učestvuju na Evroviziji. Svaki od narednih $N - 1$ redova sadrži po dva prirodna broja $u$, $v$, indekse država koje su povezane direktnom autobuskom linijom.
	
	## Opis Izlaza
	
	U prvom redu standardnog izlaza ispisati redne brojeve država između kojih će se konstruisati dodatna autobuska linija. U drugom redu izlaza ispisati državu u kojoj će biti organizovana Evrovizija.
	
	## Ograničenja
	
	* $3\leq N \leq 2 \cdot 10^5$
	* $1\leq u \neq v \leq N$
	
	## Podzadaci
	
	1. (16 poena) Svaki grad je povezan sa najviše dva druga grada direktnom linijom.
	2. (13 poena) $N \leq 100$
	3. (12 poena) $N \leq 400$
	4. (26 poena) $N \leq 2000$
	5. (33 poena) Bez dodatnih ograničenja
	
	
	## Primer 1
	
	### Ulaz
	```
	5
	1 2
	1 3
	1 4
	1 5
	```
	
	### Izlaz
	```
	2 3
	1
	```
	
	### Objašnjenje primera
	
	Dodatna autobusku liniju možemo sagraditi između država sa indeksima $2$ i $3$ i za mesto održavanja Evrovizije biramo državu sa indeksom $1$. Predstavnici države sa indeksima $2$, $3$, $4$ i $5$ moraju promeniti jednu autobusku liniju, dok predstavnici organizatora ne moraju koristi autobus. U ovom primeru postoje i druge mogućnosti za konstruisanje dodatne autobuske linije koje dovode do optimalnog rešenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Aleksa Plavšić | Aleksa Milisavljević | Aleksa Plavšić |
	
	
	Zadatak možemo modelovati kao neusmereno stablo, gde čvorovi predstavljaju države, dok grane predstavljaju autobuske linije.
	
	## Prvi podzadatak:
	
	Uvek možemo postići da najudaljeniji čvor bude na udaljenosti $D = \frac{N}{4} + 1$. Ako čvorove na putu indeksiramo sa $x_1, x_2, \dots, x_N$ postavićemo granu između čvorova $x_{D + 1}$ i x_{N - D + 1} i Evroviziju ćemo održati u prvom od njih. Lako se može pokazati da ne možemo postići bolje rešenje za graf koji je put. Potrebno je biti pažljiv za puteve dužine $4$ i $5$.
	
	## Drugi podzadatak:
	
	Fiksiraćemo čvorove između kojih ćemo dodati granu ($O(N^2)$ mogućnosti) i fiksiraćemo čvor u kome će biti održana Evrovizija ($O(N)$ mogućnosti). Potrebno je naći najkraći put od čvora u kome će biti održana Evrovizija do ostalih čvorova, što možemo uraditi algoritmom pretrage u širinu (BFS). Možemo iskoristiti i određene modifikacije pretrage u dubinu (DFS), pošto graf sadrži tačno jedan ciklus. Vremenska složenost ovog algoritma iznosi $O(N^4)$, dok memorijska iznosi $O(N)$ ili $O(N^2)$ zavisno od reprezentacije grafa.
	
	## Treći podzatak:
	
	**Obzervacija 1**: Evroviziju uvek treba održati u jednom od krajeva grane koje dodajemo. Ovo ne povlači da u nekim drugim čvorovima ne možemo održati Evroviziju, već da je jedan od krajeva grane uvek među optimalnim izborima. Primetimo da specijalan slučaj predstavljaju grafovi koji imaju dijametar (najduži put) dužine 2, u tom slučaju dodavanje nove grane ne poboljšava rešenje.
	
	Ovo nam pruža podlogu za algoritam vremenske složenosti $O(N^3)$, pošto za fiksnu granu treba da proverimo samo dve mogućnosti za mesto održavanja Evrovizije. U slučaju da je dijametar dužine $2$, možemo ispisati bilo koju granu. 
	
	## Kompletno rešenje:
	
	**Obzervacija 2**: Grana koju dodajemo uvek će povezivati dva čvora na dijametru stabla (ako imamo više dijametara, možemo izabrati proizvoljan).
	
	Neka niz čvorova $x_1, x_2, \dots, x_d$ predstavlja dijametar stabla. Primetimo da je maksimalna udaljenost nekog od čvorova binarno pretraživa i da ne može iznositi više od $\frac{d}{2}$ (ako se Evrovizija održava u čvoru $x_{\frac{d + 1}{2}}$). Pretpostavimo da trenutno proveravamo u binarnoj pretrazi da li može maksimalna udaljenost biti manja ili jednaka od $c$. U tom slučaju optimalno je postaviti granu između čvorova $x_{c + 1}$ i $x_{d - c + 1} i održati Evroviziju u prvom od njih ili između čvorova $x_c$ i $x_{d - c}$ i održati Evroviziju u drugom od njih. Kada znamo između koja dva čvora ćemo postaviti granu i da jedan od njih mora biti mesto održavanja Evrovizije, ostalo je samo proveriti da li neki od njih zadovoljava uslov da nakon postavljanja grane svi ostali čvorovi budu udaljeni ne više od $c$. To možemo ponovo uraditi nekim od algoritama za pronalazak najkraćeg puta u grafu. Ukupna vremenska složenost $O(N log N)$ i memorijska $O(N)$.
	
	Bonus: Rešite zadatak u vremenskoj složenosti $O(N)$.
	
	``` cpp title="06_konstrukta.cpp" linenums="1"
	#include<bits/stdc++.h>
	
	using namespace std;
	
	#define pii pair<int, int>
	
	const int maxN = 2e5 + 10;
	
	int N, furthestNode, maxDist, dist[maxN];
	vector<int> v[maxN], diametarPath;
	map<pii, int> edges;
	
	
	void bfs(int startNode) {
	    dist[startNode] = 0;
	    queue<int> q;
	    q.push(startNode);
	
	    while(!q.empty()) {
	        int currentNode = q.front();
	        q.pop();
	
	        for (int node: v[currentNode]) {
	            if (dist[node] == -1) {
	                dist[node] = dist[currentNode] + 1;
	                q.push(node);
	            }
	        }
	    }
	}
	
	int findBiggestDistanceFromNode(int startNode, int newLineEndpointA, int newLineEndpointB) {
	    v[newLineEndpointA].push_back(newLineEndpointB);
	    v[newLineEndpointB].push_back(newLineEndpointA);
	
	    for (int i = 1; i <= N ;i++) {
	        dist[i] = -1;
	    }
	
	    bfs(startNode);
	    
	    int biggestDistance = 0;
	    for (int i = 1; i <= N; i++) {
	        biggestDistance = max(biggestDistance, dist[i]);
	    }
	    
	    v[newLineEndpointA].pop_back();
	    v[newLineEndpointB].pop_back();
	
	    return biggestDistance;
	}
	
	void findDiameterEnd(int node, int dist, int parent) {
	    if (dist > maxDist) {
	        maxDist = dist;
	        furthestNode = node;
	    }
	
	    for (int i: v[node]) {
	        if (i != parent) {
	            findDiameterEnd(i, dist + 1, node);
	        }
	    }
	}
	
	void getDiameterPath(int currentNode, int targetNode, int par, vector<int> &currentPath) {
	    currentPath.push_back(currentNode);
	
	    if (currentNode == targetNode) {
	        diametarPath = currentPath;
	    }
	
	    for (int i: v[currentNode]) {
	        if (i != par) {
	            getDiameterPath(i, targetNode, currentNode, currentPath);
	        }
	    }
	
	    currentPath.pop_back();
	}
	
	pii findPairOfNonConnectedNodes() {
	    for (int node = 1; node <= N; node++) {
	        int nextNode = node == N ? 1 : node + 1;
	        if (edges.find({node, nextNode}) == edges.end()) {
	            return {node, nextNode};
	        }
	    }
	    
	    return {-1, 1};
	}
	
	int main() {
	    
	    scanf("%d", &N);
	
	    for (int i = 1; i < N; i++) {
	        int x, y;
	        scanf("%d%d", &x, &y);
	        edges[{x, y}] = true;
	        edges[{y, x}] = true;
	        v[x].push_back(y);
	        v[y].push_back(x);
	    }
	
	    maxDist = -1;
	    findDiameterEnd(1, 0, 0);
	    int firstDiameterEndpoint = furthestNode;
	    
	    maxDist = -1;
	    findDiameterEnd(firstDiameterEndpoint, 0, 0);
	    int secondDiameterEndpoint = furthestNode;
	    
	    vector<int> path;    
	    getDiameterPath(firstDiameterEndpoint, secondDiameterEndpoint, 0, path);
	
	    int diamLen = diametarPath.size();
	    int lo = 0;
	    int ro = diamLen/2;
	
	    while (lo < ro - 1) {
	        int mid = lo + ro >> 1;
	        maxDist = findBiggestDistanceFromNode(diametarPath[mid], diametarPath[mid], diametarPath[diamLen - mid]);
	        maxDist = min(maxDist, findBiggestDistanceFromNode(diametarPath[diamLen - mid - 1], diametarPath[mid - 1], diametarPath[diamLen - mid - 1]));
	
	        if (maxDist <= mid) {
	            ro = mid;
	        } else {
	            lo = mid;
	        }
	    }
	
	    int eurosongFinalNode, newLineEndpointA, newLineEndpointB;
	    
	    if (findBiggestDistanceFromNode(diametarPath[ro], diametarPath[ro], diametarPath[diamLen - ro]) <
	                                    findBiggestDistanceFromNode(diametarPath[diamLen - ro - 1], diametarPath[ro - 1], diametarPath[diamLen - ro - 1])) {
	        eurosongFinalNode = diametarPath[ro];
	        newLineEndpointA = diametarPath[ro];
	        newLineEndpointB = diametarPath[diamLen - ro];
	    } else {
	        eurosongFinalNode = diametarPath[diamLen - ro - 1];
	        newLineEndpointA = diametarPath[diamLen - ro  - 1];
	        newLineEndpointB = diametarPath[ro - 1];
	    }
	        
	    if (newLineEndpointA == newLineEndpointB || edges.find({newLineEndpointA, newLineEndpointB}) != edges.end()) { // new path is irrelevant
	        pii nonConnectedNodes = findPairOfNonConnectedNodes();
	        newLineEndpointA = nonConnectedNodes.first;
	        newLineEndpointB = nonConnectedNodes.second; 
	    } 
	    
	    printf("%d %d\n", newLineEndpointA, newLineEndpointB);
	    printf("%d\n", eurosongFinalNode);
	
	    return 0;
	}

	```
