---
hide:
  - toc
---

# 3 - Nadvlačenje konopca

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 64MB |
	
	
	Na državnom takmičenju iz nadvlačenja konopca učestvuje $N$ takmičara. Takmičenje ima $N$ rundi. U svakoj učestvuju tačno dva takmičara (neki takmičari mogu učestvovati i u više rundi, a neki ni u jednoj). U $i$-toj rundi učestvuju takmičari $a_i$ i $b_i$.  
	
	Državna komisija za nadvlačenje konopca je upravo Vas odabrala da budete sudija na $T$ ovakvih takmičenja! Na svakom od njih potrebno je odrediti pobednika svake runde, ali tako da, u cilju popularizacije takmičenja, svaki takmičar pobedi barem jednom.
	
	Vas na svakom takmičenju posebno interesuje na koliko načina je moguće odabrati pobednika u svakoj rundi, tako da ovaj uslov bude ispunjen? Pošto ovaj broj može da bude veoma veliki, ispisati ga po modulu `998244353`. Dva načina određivanja pobednika su različita, ukoliko postoji barem jedna runda u kojoj nije isti takmičar proglašen pobednikom.
	
	## Opis ulaza
	
	U prvom redu standardnog ulaza, dat je jedan ceo broj $T$, broj takmičenja na kojima ste pozvani da sudite. Potom slede opisi tih $T$ takmičenja. U prvom redu opisa svakog takmičenja, dat je jedan ceo broj $N$, broj takmičara i rundi. U narednih $N$ redova, data su po dva cela broja. U $i$-tom od tih redova, dati su brojevi $a_i$ i $b_i$, koji predstavljaju učesnike $i$-te runde.
	
	  
	
	## Opis izlaza
	
	U svakom od $T$ redova, potrebno je ispisati po jedan ceo broj - broj načina da se odaberu pobednici svake runde odgovarajućeg takmičenja, tako da svaki takmičar pobedi u barem jednoj rundi.
	
	  
	
	  
	
	## Ograničenja
	
	* $1  \leq T \leq  2 \cdot 10^5$
	
	* $3  \leq N \leq  2 \cdot 10^5$.
	
	* $1  \leq a_i \neq b_i \leq N$.
	
	* U nikoje dve runde istog takmičenja ne učestvuje isti par takmičara.
	
	* Suma svih $N$ ne prelazi $2 \cdot 10^5$ po jednom ulaznom fajlu.
	  
	
	## Podzadaci
	
	1. (10 poena) $N \leq  17$ i $T \leq 10$.
	2. (26 poena) $N \leq  2000$ i $T \leq 10$.
	3. (17 poena) Svaki takmičar učestvuje u tačno dve runde.
	4. (47 poena) Nema dodatnih ograničenja.
	
	  
	
	
	  
	
	## Primer 1
	
	  
	
	### Ulaz
	
	~~~
	2
	5
	1 2
	2 3
	1 3
	4 1
	5 4
	5
	1 2
	2 3
	3 4
	4 1
	1 3
	~~~
	
	  
	
	### Izlaz
	
	~~~
	2
	0
	~~~
	
	  
	
	### Objašnjenje primera
	
	Ukoliko su pobednici rundi prvog takmičenja redom $[1,2,3,4,5]$, ili $[2,3,1,4,5]$, tada je svaki takmičar pobedio u barem jednoj rundi. Proverom se može utvrditi da su ovo jedina dva načina na koja se mogu odrediti pobednici rundi, tako da uslovi budu ispunjeni. U drugom takmičenju, takmičar sa indeksom $5$ ne učestvuje ni u jednoj rundi, pa ne postoji način da se odrede pobednici, tako da svaki takmičar pobedi u barem jednoj rundi.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Aleksa Milisavljević | Pavle Martinović | Pavle Martinović |
	
	## Rešenje kada $N \leq 20$
	Za svaki meč ima ukupno $2$ načina da se izabere pobednik tako da ima ukupno $2^N$  ukupno načina da se izaberu pobednici. Naprosto prođemo kroz sve te kombinacije (npr iteriranjem brojeva od $0$ do $2^N-1$ i gledajući njihov binarni zapis) i vidimo da li u svakoj od njih se desi da ima jednu pobedi. Složenost $O(2^N)$
	## Rešenje kada svaki takmičar učestvuje u 2 meča
	Posmatrajmo graf čiji su čvorovi takmičari i postoji grana između dva takmičara ako igraju meč međusobno. Sada nam je zadatak ekvivalentan sa time da se orijentišu grane tako da svaki čvor ima izlazni stepen tačno $1$ (ovakvi grafovi se inače zovu *funkcionalni grafovi*).
	
	U ovom podzadatku svaki čvor je stepena tačno $2$. Za takav graf znamo da je svaka povezana komponenta ciklus (dokažite!). U ciklusu očito imamo samo $2$ načina da orijentišemo grane (neformalno rečeno u smeru kazaljke na satu i suprotno). Tako da je u ovom slučaju odgovor $2^{\text{broj komponenti}}$. Složenost $O(N)$.
	
	
	## Glavno rešenje
	
	Zapravo je glavno rešenje mala modifikacija prethonog. Naime, očito nam je potreban uslov da u svakoj komponenti ima isto čvorova i grana (da bi mogao savko da pobedi barem jednom). Ispostavlja se da ako je ovaj uslov ispunjen, odgovor je opet $2^{\text{broj komponenti}}$ (a u suprotnom je $0$).
	Dokaz ovoga možemo da vidimo na sledeći način: ako postoji čvor stepena $1$ znamo da on mora da pobedi taj meč tako da nam je to jedinstveno određeno i možemo da skinemo taj čvor i granu i opet dobijemo graf sa isto čvorova i grana, i to za $1$ manje. Nastavljamo ovaj proces, i kad nema nijedan čvor stepena $1$, tada svi imaju stepen $2$, što po prethodnom podzadatku znamo da imamo tačno $2$ načina da orijentišemo.
	
	``` cpp title="03_nadvlacenje_konopca.cpp" linenums="1"
	#include<bits/stdc++.h>
	#define maxn 300000
	using namespace std;
	int t;
	int n;
	vector<int> a[maxn];
	bool vis[maxn];
	const int mod=998244353;
	int dfs(int u) {
	    int ret=2;
	    vis[u]=true;
	    for(auto v:a[u]) {
	        ret--;
	        if(!vis[v]) ret+=dfs(v);
	    }
	    return ret;
	}
	int main() {
	    scanf("%d",&t);
	    while(t--) {
	        scanf("%d",&n);
	        for(int i=0;i<n;i++) {
	            int u,v;
	            scanf("%d %d",&u,&v);
	            a[u].push_back(v);
	            a[v].push_back(u);
	        }
	        int ans=1;
	        for(int i=1;i<=n;i++) {
	            if(!vis[i]) {
	                if(dfs(i)==0) {
	                    ans=ans*2;
	                    if(ans>=mod) ans-=mod;
	                }
	                else ans=0;
	            }
	        }
	        printf("%d\n",ans);
	        for(int i=1;i<=n;i++) {
	            a[i].clear();
	            vis[i]=false;
	        }
	    }
	    return 0;
	}

	```
