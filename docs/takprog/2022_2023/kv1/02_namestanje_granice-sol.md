## Glavno rešenje
Pretpostavimo da je niz $A$ sortiran u neopadajućem poretku, da je ukupan broj elemenata niza $N$ i da su elementi niza indeksirani brojevima od $0$ do $N-1$. Tada je medijana niza element sa indeksom $N/2$ (pri čemu se računa celobrojni deo količnika). Neka je $B$ broj poena koji Markos želi kao granicu. Tada razlikujemo tri slučaja:

* Ako je $A[N/2] = B$, onda je medijana već jednaka broju $B$ i Markos glasa $0$ puta.

* Ako je $B$ $<$ $A[N/2]$ određujemo indeks $i$ poslednjeg elementa koji nije veći od $B$ (ako takav ne postoji, onda je $i=-1$). Tada postoji  $i+1$ elemenata koji su manji od ili jednaki $B$ i $N-i-1$ elemenata koji su veći od $B$, pri čemu je $i+1 \leq N-i-1$. Da bi obezbedili da $B$ bude medijana potrebno je da grupa manjih ili jednakih ima bar jedan element više od grupe većih, pa je potrebno ubaciti $N-i-1-(i+1)+1 = N-2i-1$ glasova.
* Ako je $B>A[N/2]$ određujemo indeks $i$ prvog elementa koji nije manji od $B$ ( ako takav ne postoji, onda je $i=N$). Tada postoji  $i$ elemenata koji su manji od $B$ i $N-i$ elemenata koji su veći od ili $B$, pri čemu je $i \geq N-i$. Da bi obezbedili da $B$ bude medijana potrebno je da grupa većih ili jednakih ima bar onoliko elementa koliko ima manjih, pa je potrebno ubaciti $i - (N - i) = 2i-N$ glasova.

Složenost algoritma je određena složenošću sortiranja (koja može biti $\Theta(N\log N)$) i složenošću pronalaženja poslednjeg elementa koji nije veći od $B$, odnosno prvog elementa koji nije manji od $B$. Ako ovo realizujemo kao sekvencijalno pretraživanje, složenost dela koji se odnosi na određivanje odgovora na pitanja će biti $\Theta(QN)$, pa će ukupna složenost biti $\Theta(N\log N + NQ)$. Ako pronalaženje opisanog elementa realizujemo korišćenjem binarne pretrage (koju svakako možemo koristiti, ako smo niz sortirali), onda je složenost određivanja odgovora na pitanja $\Theta(Q\log N)$, pa je složenost kompletnog algoritma $\Theta((N+Q)\log N)$.




