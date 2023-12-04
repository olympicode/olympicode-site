---
hide:
  - toc
---

# B3 - Tiho Brdo

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	U srednjevekovnom dobu, u malom gradiću Tihom Brdu živelo je čudovište pod nazivom Gluton, koje je volelo da teroriše stanovnike ovog grada. Mnogi vitezovi su pokušavali da ubiju Glutona, ali ni jedan nije uspeo da preživi taj susret.
	
	Jednog dana, hrabri arhitekta Davis je odlučio da napadne Glutona. Saznao je da se Gluton zapravo sastoji iz gomile delova, koji su međusobno spojeni na taj način da svaki deo može kontrolisati neke druge delove. Gluton ima tačno jedan deo koji predstavlja njegov mozak, i taj deo nije kontrolisan od strane ijednog drugog dela. Takođe, Gluton može imati jedan ili više delova koji ne kontrolišu ni jedan drugi deo; ovi delovi predstavljaju njegove kandže. Za svaku kandžu postoji tačno jedan skup spojeva kojim je mozak (direktno ili indirektno) kontroliše. Ukoliko Davis uspešno odseče mozak od kontrolisanja svih kandži, onda Gluton ostaje potpuno bezopasan.
	
	Davis je upotrebio svoje projektne sposobnosti i zaključio da je svakom od Glutonovih spojeva x → y moguće pripisati snagu w neophodnu da bi se taj spoj uništio. Davisova želja je da uloži minimalno snage za odsecanje mozga od kandži, pa ga zanima koje spojeve, sleva na desno, treba da preseče da bi to postigao. Ukoliko postoji više tačnih rešenja, Davis bi voleo da uložena snaga na početku bude što je manja moguća, tj. traži se leksikografski najmanje rešenje od svih tačnih rešenja.
	
	Za data dva niza, a i b, veličina n i m, kažemo da je a leksikografski manji od b ukoliko ili postoji neka pozicija i tako da je su do te pozicije nizovi isti, a niz a je po i-tom članu manji, tj.
	
	$$
	(ai < bi) ∧ (∀j < i. aj = bj )
	$$
	
	ili se nizovi $a$ i $b$ poklapaju na svim kompatibilnim pozicijama, s tim da je niz a kraći, tj.
	
	$$
	(n < m) ∧ (∀j ≤ n. aj = bj )
	$$
	
	Primeri: {1, 2, 3} < {2, 2, 3}; {1, 2, 3, 4} < {1, 2, 4, 4}; {1, 2, 3} < {1, 2, 3, 4}.
	Zaslepljen slavom koju bi stekao i pokličima “Hvala hrabri Davise!” od stanovnika ukoliko bi onesposobio Glutona, Davis nema dovoljno strpljenja da izračuna rešenje. Zamolio vas je za pomoć.
	
	
	## Opis ulaza
	U prvom redu standardnog ulaza nalazi se prirodan broj $n$, koji predstavlja broj Gluto-
	novih delova. Deo sa indeksom 1 uvek predstavlja mozak. Zatim slede opisi delova, od mozga do dela sa indeksom $n$, redom, na sledeći način: u prvom redu se nalazi ceo broj $m_i$, koji predstavlja broj delova koji su pod direktnom kontrolom tekućeg dela. Ukoliko važi $m_i$ = 0, onda je tekući deo kandža. U suprotnom, u drugom redu se nalazi niz a od $m_i$ prirodnih brojeva, koji predstavlja, sleva na desno, indekse delova pod direktnom kontrolom tekućeg dela. U trećem redu se nalazi niz $w$ od $m_i$ prirodnih brojeva, tako da $j$-ti član niza $w$, $w_j$ , označava snagu neophodnu za uništenje spoja kojim tekući deo kontroliše $j$-tog člana niza $a$, $a_j$ .
	
	## Opis izlaza
	U prvom redu standardnog izlaza potrebno je ispisati minimalnu ukupnu snagu neophodnu
	da bi Davis onesposobio Glutona. U narednom redu neophodno je ispisati leksikografski najmanji niz snaga koje će trebati Davisu da bi odsekao sve neophodne spojeve, sleva na desno, redom. Članove niza treba odvojiti razmakom.
	
	## Primer 1
	### Ulaz
	```
	7
	2
	2 5
	4 7
	2
	3 4
	2 3
	0
	0
	2
	6 7
	1 6
	0
	0
	```
	
	### Izlaz
	```
	11
	4 1 6
	```
	
	## Objašnjenja primera
	Na slikama ispod nalazi se opis test primera; leva slika predstavlja početno stanje Glutona, a desna predstavlja optimalno rešenje. Mozak je označen crnom pozadinom, a kandže crvenom bojom. Precrtani i isprekidani spojevi predstavljaju one spojeve koje Davis treba da uništi. Postoje dva rešenja koja zahtevaju minimalnu ukupnu snagu 11; ta rešenja su, sleva na desno, {4, 7} i {4, 1, 6}. Od ta dva rešenja, biramo leksikografski manje.
	
	## Ograničenja
	
	* $2 ≤ n ≤ 10^5$;
	* $1 ≤ w_j ≤ 10^9$;
	* Ukupan broj spojeva će uvek biti $n − 1$, i uvek će za svaku kandžu postojati tačno jedan skup spojeva koji je povezuju sa mozgom.
	
	## Podzadaci i bodovanje
	Test primeri su podeljeni u četiri podzadatka, u kojima važe sledeća
	dodatna ograničenja:
	
	* Podzadatak 1 [10 poena]: Svi spojevi će imati istu potrebnu snagu za uništenje;
	* Podzadatak 2 [10 poena]: Jedino mozak može direktno kontrolisati više od jednog dela Glutona;
	* Podzadatak 3 [30 poena]: $n ≤ 1000$;
	* Podzadatak 4 [50 poena]: Nema dodatnih ograničenja.
	
	Ukoliko na svim test primerima jednog podzadatka izračunate tačnu ukupnu snagu, dobijate 60% poena za taj podzadatak. Ukoliko korektno odredite leksikografski minimalno rešenje na svim test primerima jednog podzadatka, dobijate 40% poena za taj podzadatak.
	
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Petar Veličković | Petar Veličković | Bogdan Petrović | Andrej Ivašković |
	
	
	Primetimo da je Gluton stablo sa korenom u čvoru $1$. Operacija uništenja spoja predstavlja uklanjanje te grane u grafu. Da bismo pobedili Glutona potrebno je ukloniti neke grane tako da koren stabla ne bude povezan ni sa jednim listom. Rešenje zadatka su težine grana sa najmanjom sumom težina koje zadovoljavaju prethodni uslov.
	Ukoliko postoji više rešenja, potrebno je ispisati leksikografski najmanje. Više o tome u analizi po podzadacima.
	
	## Prvi podzadatak
	Pošto svi spojevi imaju istu potrebnu snagu za uništenje, do rešenja dolazimo brisanjem minimalnog broja grana u grafu tako da koren ne bude povezan sa listovima. To najjednostavnije postižemo brisanjem svih grana koje povezuju koren stabla sa njegovom decom. Neka je $d = deg(1)$ i $w$ težina grane, potrebno je ispisati $d\cdot   w$, a zatim $d$ puta ispisati $w$.
	Vremenska i memorijska složenost je $O(N)$.
	
	## Drugi podzadatak
	Primetimo da stablo u ovom podzadatku izgleda kao $deg(1)$ lanaca kojima je čvor $1$ jedan od krajeva. U ovakvom stablu imamo $deg(1)$ listova, po jedan u svakom lancu. Da bismo prekinuli vezu između lista i korena potrebno je da uklonimo granu na putu od tog lista do korena, odnosno potrebno je ukloniti granu na svakom lancu. Do rešenja dolazimo uklanjanjem grane sa najmanjom težinom iz svakog lanca.
	Vremenska i memorijska složenost je $O(N)$.
	
	## Treći podzadatak
	Označimo sa $s_i$ minimalnu sumu težina grana koje treba da uklonimo iz podstabla čvora $i$ tako da čvor $i$ ne bude povezan sa listovima svog podstabla, i sa $k_i$ neku strukturu koja čuva pojedinačne težine tih grana. Da bismo izračunali vrednosti  $s_i$ i $k_i$, koristićemo vrednosti $s_j$ i $k_j$, za svako $j$ čiji je roditelj čvor $i$.
	
	$$
	s_i=\sum_{j}min(s_j, w_{i,j})
	$$
	
	U $k_i$ ćemo dodati  $w_{i,j}$ ukoliko je $w_{i,j}<s_j$, u suprotnom dodajemo $k_j$.
	Napomena: bitno je da je $w_{i,j}<s_j$, a ne $w_{i,j}≤s_j$ u gornjem uslovu da bismo ispunili uslov zadatka koji nam traži leksikografsku minimalnost.
	Za listove ćemo postaviti vrednost $s$ na $\infty$, jer je nemoguće da izbrišemo neke grane tako da razdvojimo taj čvor od samog sebe.
	Rešenje zadatka su $s_1$ i $k_1$. 
	Ovaj način je moguće implementirati algoritmom pretrage u dubinu, naivnim pozivanjem funkcije pretrage u dubinu.
	Vremenska složenost je $O(N^2)$ , a memorijska $O(N)$, jer se težina svake grane čuva na najviše $2$ mesta, u $k_i$ i $k_j$.
	
	## Glavno rešenje
	Koristićemo slično rešenje kao u prethodnom podzadatku. Jedina razlika je što ćemo koristiti memoizaciju kao tehniku da ubrzamo pretragu u dubinu, tj. da za svaki čvor $i$ računamo vrednosti $s_i$ i $k_i$ jedanput.
	Vremenska i memorijska složenost je $O(N)$.
	
	
	``` cpp title="03_tiho_brdo.cpp" linenums="1"
	/*
	 Author: Petar 'PetarV' Velickovic
	 Task: Tiho Brdo
	*/
	
	#include <stdio.h>
	#include <queue>
	#include <vector>
	
	#define MAX_N 1000005
	
	using namespace std;
	typedef long long lld;
	
	int n;
	
	struct node
	{
	    int par; int w_par;
	    vector<int> adj;
	};
	node tree[MAX_N];
	
	lld dp[MAX_N];
	
	inline void compute_dp()
	{
	    queue<int> bfs_q;
	    for (int i=1;i<=n;i++)
	    {
	        if (tree[i].adj.empty()) bfs_q.push(i);
	    }
	    
	    while (!bfs_q.empty())
	    {
	        int xt = bfs_q.front();
	        bfs_q.pop();
	        
	        if (tree[xt].par == -1) continue;
	        
	        dp[xt] = tree[xt].w_par;
	        if (!tree[xt].adj.empty())
	        {
	            lld s_1 = 0;
	            for (int i=0;i<tree[xt].adj.size();i++)
	            {
	                s_1 += dp[tree[xt].adj[i]];
	            }
	            dp[xt] = min(dp[xt], s_1);
	        }
	        
	        bfs_q.push(tree[xt].par);
	    }
	}
	
	void extract_seq(int x, vector<int> &ret)
	{
	    if (tree[x].adj.size() == 0)
	    {
	        ret.push_back(tree[x].w_par);
	        return;
	    }
	    
	    lld opt_2 = 0;
	    for (int i=0;i<tree[x].adj.size();i++)
	    {
	        opt_2 += dp[tree[x].adj[i]];
	    }
	    
	    if (tree[x].w_par < opt_2)
	    {
	        ret.push_back(tree[x].w_par);
	        return;
	    }
	    
	    for (int i=0;i<tree[x].adj.size();i++)
	    {
	        extract_seq(tree[x].adj[i], ret);
	    }
	}
	
	inline pair<lld, vector<int> > solve()
	{
	    compute_dp();
	    
	    lld ret = 0;
	    vector<int> seq;
	    
	    for (int i=0;i<tree[1].adj.size();i++)
	    {
	        ret += dp[tree[1].adj[i]];
	        extract_seq(tree[1].adj[i], seq);
	    }
	    
	    return {ret, seq};
	}
	
	int main()
	{
	    scanf("%d", &n);
	    for (int i=1;i<=n;i++)
	    {
	        int len;
	        scanf("%d", &len);
	        tree[i].adj.resize(len);
	        for (int j=0;j<len;j++)
	        {
	            scanf("%d", &tree[i].adj[j]);
	            tree[tree[i].adj[j]].par = i;
	        }
	        for (int j=0;j<len;j++)
	        {
	            scanf("%d", &tree[tree[i].adj[j]].w_par);
	        }
	    }
	    
	    tree[1].par = tree[1].w_par = -1;
	    
	    auto ret = solve();
	    printf("%lld\n", ret.first);
	    for (int j=0;j<ret.second.size();j++)
	    {
	        printf("%d ", ret.second[j]);
	    }
	    printf("\n");
	    
	    return 0;
	}
	```
