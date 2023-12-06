---
hide:
  - toc
---

# 5 - Virus

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	Sunce ponovo sija, Beograd je ozeleneo i rascvetao se, topli dani su se vratili i kao što se može pretpostaviti članovi komisije iznenada više nemaju vremena za SIO. Međutim, da bi olakšali sebi posao tajno su zaposlili jednog mladog člana da napravi zadatke za njih. Ono što nisu znali jeste da je on skovao podmukli plan sa ciljem da upropasti SIO i preuzme posao komisije. Nazvaćemo našeg zlikovca Nikola.
	
	Nikola je instalirao virus na $N$ računara namenjenih takmičarima. Sasvim slučajno se desilo da je tih $N$ računara povezano pomoću $N-1$ kablova (jedan kabal spaja dva računara) tako da računari formiraju stablo.
	
	Komisija je morala da se ponovo aktivira i sanira novonastali problem. 'Antivirus', koji su napravili u te svrhe, funkcioniše tako što komisija bira dva računara $a$ i $b$, a zatim pokreće svoj program koji sa svakog računara na putu od $a$ do $b$, uključujući i njih, briše virus ako postoji. 
	
	Pomozite komisiji da spasi sve zaražene računare i to pomoću minimalnog broja pokretanja antivirusa tako što ćete odrediti taj broj i navesti im parove računara za koje treba da pozovu program.
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se jedan prirodni broj $N$ - broj računara zaraženih virusom. U narednih $N-1$ redova nalaze se po dva prirodna broja $a$ i $b$ koja označavaju da su računari $a$ i $b$ povezani.
	
	## Opis izlaza
	Opis izlaznih podataka.
	
	## Primer 1
	### Ulaz
	```
	5
	1 3
	1 4
	2 3
	3 5
	```
	
	### Izlaz
	```
	2
	1 4
	2 5
	```
	
	## Ograničenja
	Postoje $3$ podzadatka u kojima dodatno važi:
	
	* Podzadatak 1 [20 poena]: $n \leq 20$. 
	* Podzadatak 2 [35 poena]: $n \leq 5000$. 
	* Podzadatak 3 [45 poena]: $n \leq 200000$.
	
	## Napomena
	Može da postoji više načina na koje se mogu povezati računari kako bi se dobilo optimalno rešenje. Potrebno je ispisati samo jedan, proizvoljan način kao rešenje zadatka.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Aleksa Plavšić | Nenad Bauk | Nenad Bauk | Nikola Spasić |
	
	Zadatak se svodi na: za dato stablo sa N čvorova, izabrati minimalan broj parova čvorova (neka je taj broj P) tako da se svaki čvor stabla nalazi na bar jednom od P puteva čiji su krajevi izbaranih P parova čvorova. Drugim recima, unija tih P puteva treba da ‘prekrije’ ceo graf.
	
	Prvo treba uočiti da je uvek optimalno da se povežu dva lista u grafu. Jedini način da se neki list ‘prekrije’ je da taj list bude jedan od čvorova iz skupa odabranih P parova. Prema tome, donja granica rešenja je P = floor((L+1)/2) gde L broj listova u stablu, a floor je funkcija koja vraća donji ceo deo.
	
	Uzmimo proizvoljan čvor X koj nije list. Kad bismo izabrali P parova čvorova tako da svaki par čine neka dva lista i da put između ta dva lista prolazi kroz X, ceo graf bi bio prekriven. Zaista, ovim smo prekrili put od svakog lista do X, a to je celo stablo. Uslov da putevi između listova svakog para prolaze kroz X je ekvivalentan sa uslovim da listovi svakog para pripadaju različitim podstablima sinova čvora X.
	
	Umesto da proizvoljno biramo čvor X, možemo izabrati čvor za koji važi da podstablo svakog njegovog sina sadrzi najvise L / 2 listova (nije teško pokazati da takav čvor uvek postoji a možemo ga pronaći uz pomoć jednog DFS obilaska grafa i računanjem broja listova u svakom podstablu). Koristeći ovu osobinu čvora X, mozemo da povežemo floor((L+1)/2) parova listova tako da svaki od pomenutih puteva prolazi kroz čvor X, npr. za svako i <= L/2, možemo upariti i-ti i (i + L/2)-ti čvor (redni brojevi na osnovu DFS obilaska).
	
	Slozenost: O(n)
	
	``` cpp title="05_virus.cpp" linenums="1"
	/* kod koji prolazi sve test primere */
	
	#include <iostream>
	#include <vector>
	using namespace std;
	
	#define MAXN 200010
	
	int N;
	
	vector<int> graph[MAXN];
	
	int leavesBelow[MAXN];
	int maxLeaves[MAXN];
	
	int countLeavesBelow(int node, int par)
	{
	    if (graph[node].size() == 1)
	    {
	        leavesBelow[node] =  1;
	    }
	
	    for (int i = 0; i < graph[node].size(); i++)
	    {
	        int target = graph[node][i];
	
	        if (target != par)
	        {
	            leavesBelow[node] += countLeavesBelow(target, node);
	        }
	    }
	
	    return leavesBelow[node];
	}
	
	
	int countMaxLeaves(int node, int par, int leavesAbove)
	{
	    maxLeaves[node] = leavesAbove;
	
	    for (int i = 0; i < graph[node].size(); i++)
	    {
	        int target = graph[node][i];
	
	        if (target == par) continue;
	
	        // Update max at current node
	        maxLeaves[node] = max(maxLeaves[node], leavesBelow[target]);
	
	        countMaxLeaves(target, node, leavesAbove + leavesBelow[node] - leavesBelow[target]);
	    }
	}
	
	int getCentroid()
	{
	    int centroid = 1;
	
	    for (int i = 2; i <= N; i++)
	    {
	        if (graph[i].size() > 1 && maxLeaves[i] <= maxLeaves[centroid])
	            centroid = i;
	    }
	
	    return centroid;
	}
	
	vector<int> leaves;
	
	void getLeavesBelow(int node, int par)
	{
	    if (graph[node].size() == 1)
	        leaves.push_back(node);
	
	    for (int i = 0; i < graph[node].size(); i++)
	    {
	        int target = graph[node][i];
	
	        if (target != par)
	            getLeavesBelow(target, node);
	    }
	}
	
	
	vector<pair<int,int>> solution;
	
	int main() {
	   
	    //freopen("./input/case17.in", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	
	    cin >> N;
	
	    for (int i = 0; i < N - 1; i++)
	    {
	        int a, b;
	        cin >> a >> b;
	
	        graph[a].push_back(b);
	        graph[b].push_back(a);
	    }
	
	    // Special case
	    if (N <=  2)
	    {
	        cout << 1 << endl;
	        cout << min(1,N) << ' ' << max(1, N) << endl;
	        return 0;
	    }
	
	
	    countLeavesBelow(1, -1);
	    countMaxLeaves(1, -1, 0);
	
	    /*
	    for (int i = 1; i <= N; i++)
	    {
	        cout << leavesBelow[i] << ' ' << maxLeaves[i] << endl;
	    }
	    */
	
	    int centroid = getCentroid();
	
	    // cout << centroid << endl;
	
	    for (int i = 0; i < graph[centroid].size(); i++)
	    {
	        int target = graph[centroid][i];
	        
	        getLeavesBelow(target, centroid);
	    }
	
	    int totalLeaves = leaves.size();
	
	    if (totalLeaves % 2)
	    {
	        leaves.push_back(centroid);
	    }
	
	    // Output solution
	    cout << leaves.size() / 2 << endl;
	
	
	    for (int i = 0; i < leaves.size() / 2; i++)
	    {
	        cout << leaves[i] << ' ' << leaves[i + leaves.size() / 2] << endl;
	    }
	
	    return 0;
	}
	```
