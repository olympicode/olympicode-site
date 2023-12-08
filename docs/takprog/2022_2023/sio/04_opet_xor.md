---
hide:
  - toc
---

# 4 - Opet XOR

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 4000ms | 512MB |
	
	Čuli smo da ovogodišnjim takmičenjima nije bilo dovoljno zadataka u kojima se pominje XOR. SIO je pravo mesto da se ovaj previd ispravi.
	
	Kažemo da je niz $X_1, X_2, \dots, X_k$ **ksortastičan** ako je moguće preurediti ga tako da XOR-ovi svih prefiksa preuređenog niza budu strogo rastući. Formalnije, niz je ksortastičan ako postoji permutacija $\pi_1, \pi_2, \dots, \pi_k$ brojeva od $1$ do $k$ takva da za vrednosti $Y_1, Y_2, \dots, Y_k$ definisane sa 
	
	$$Y_i = X_{\pi_1} \oplus X_{\pi_2} \oplus \dots \oplus X_{\pi_i}$$ 
	
	važi $Y_1 < Y_2 < \dots < Y_k$ (gde je $\oplus$ XOR).
	
	Dat je niz $A_1, A_2, \dots, A_n$ dužine $n$. Vaš program treba da odgovori na dve vrste upita:
	
	* $1$ $i$ $x$: postavi vrednost $A_i$ na $x$.
	* $2$ $i$ $k$: da li je podniz dužine $k$ koji počinje sa $A_i$ ksortastičan?
	
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	* $Resi(N, A[\dots], Q, T[\dots], I[\dots], X[\dots], O[\dots])$
	
	Funkcija $Resi$ se poziva samo jednom na početku ivršavanja programa, a njeni parametri su:
	
	* $N$: dužina niza $A$.
	* $A[\dots]$: početne vrednosti niza nad kojim se vrše upiti, dužine $N$, **indeksiran od 1**.
	* $Q$: broj upita.
	* $T[\dots]$, $I[\dots]$, $X[\dots]$: nizovi dužine $Q$, **indeksirani od 1**, koji opisuju upite, čiji odgovori se upisuju u $O[\dots]$. $i$-ti upit može biti:
	    * Ako je $T[i] = 1$: postavi $A_{I[i]}$ na $X[i]$.
	    * Ako je $T[i] = 2$: program treba da u $O[i]$ upiše `true` ako je niz $A_{I[i]}, A_{I[i]+1}, \dots, A_{I[i]+X[i]-1}$ (dužine $X[i]$) ksortastičan, i `false` u suprotnom.
	
	
	## Primer
	Neka je $N=5$, $A=[1, 1, 3, 3, 3]$, $Q=3$, $T = [2,1,2]$, $I = [1, 3, 1]$, $X = [3, 2, 3]$. Na prvi upit tipa $2$, odgovor je `true`, jer se niz $[1, 1, 3]$ može preurediti kao $[1, 3, 1]$ tako da XOR-ovi prefiksa budu $[1, 2, 3]$. Na drugi upit tipa $2$, odgovor je `false`, jer nijedna permutacija niza $[1, 3, 2]$ nema ovu osobinu.
	
	
	## Ograničenja
	
	* $1 \leq N, Q \leq 3 \cdot 10^5$.
	* $0 \leq A[i] < 2^{30}$.
	    * Ovo će važiti i nakon svakog upita tipa $1$.
	* Svi indeksi i podnizovi u upitima su u granicama niza $A$.
	
	## Podzadaci
	Test primeri su podeljeni u $6$ podzadataka:
	
	* **[8 poena]:** $Q \leq 10$, $X[i] \leq 10$ za upite tipa $2$.
	* **[15 poena]:** $N, Q \leq 200$.
	* **[17 poena]:** $N, Q \leq 5000$.
	* **[18 poena]:** $T[i] = 2$ (nema upita tipa $1$).
	* **[13 poena]:** $A[i] < 64$ (u svakom trenutku).
	* **[29 poena]:** Nema dodatnih ograničenja
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `opet_xor.cpp` koji implementira pomenutu funkcije. Osim traženih funkcija, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	Vaša funkcija mora biti sledećeg oblika:
	
	`void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O);`
	
	**Vašim programima je dozvoljeno da menjaju sadržaj nizova ali ne smeju da pristupaju van granica datih nizova.**
	
	Uz zadatak, obezbeđen vam je "template" fajl `code.cpp` koje možete koristiti i menjati po potrebi. Takođe vam je obezbeđen program `grader.cpp` koji služi da lakše testirate kodove. Ovaj program učitava sa standardnog ulaza sledeće podatke:
	
	* U prvom redu brojevi $N$ i $Q$.
	* U narednom redu $N$ brojeva: $A_i$.
	* U narednih $Q$ redova: $T[i], I[i], X[i]$.
	
	Zatim ovaj program zove vašu funkciju i ispisuje odgovore na upite tipa $2$ koje ona vrati.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Pavle Martinović | Dimitrije Erdeljan | Aleksa Milisavljević | Pavle Martinović |
	
	## Rešenje kada je $Q \leq 10$, $X[i] \leq 10$ za upite tipa $2$
	U ovom podzadatku možemo testirati sve moguće permutacije i proveriti da li su XOR-ovi svih prefiksa rastući. Složenost ovog rešenja $O(Q\cdot N!)$.
	
	## Rešenje kada je $N, Q \leq 200$
	Za ovaj podzadatak neophodno je da razmotrimo detaljnije kada je niz *ksortastičan*. Za početak, možemo da primetimo dodavanje elementa sa vrednošću $0$ na proizvoljnu poziciju ne utiče na monotonost prefiksnih XOR-eva, pa te elemente možemo da zanemarimo. Dodatno ćemo, zarad jasnije notacije, u objašnjenju ovog podzadatka pretpostaviti da je dat samo jedan upit na koji treba odgovoriti. Razmatraćemo sledeće gramzivo rešenje: iterativno gradimo permutaciju tako da naredni izabrani element prouzrokuje najmanji mogući prefiksni XOR, i da taj naredni prefiksni XOR još uvek bude veći od trenutnog. Neka je trenutni prefiksni XOR jednak $x$. Označimo sa $B_i$ poziciju vodećeg bita broja $A_i$. Neka je baš $A_i$ naredni odabrani elment. Da bi naredni XOR bio veći, u binarnom zapisu broja $x$ mora da stoji $0$ na poziciji $B_i$. Od svih narednih elementa koji zadovoljavaju ovaj uslov, dovoljno je da odaberemo onaj koji će što slabiju $0$ broja $x$ promeniti u $1$. Jedna od strategija koja rezultuje u ovakvom načinu biranja elemenata je upravo odabir elementa koji će što manje da poveća prefiksni XOR. Na intuitivnom nivou, možemo shvatiti da ovim izborom što manje većih pozicija na kojima su $0$ menjamo u $1$. Ova strategija će uvek proizvesti niz rastućih prefiksnih XOR-eva kad god je niz *ksortastičan*. Pretpostavimo da postoji rešenje u kojem na poziciji $j$ u permutaciji nije odabran element kojim se najslabija $0$ transformiše u $1$ i označimo tu poziciju na kojoj je najslabija $0$ sa $p$. Posmatrajmo u tom rešenju prvu poziciju $k > j$ u permutaciji nakon trenutne na kojoj se nalazi element $A_l$, takav da je $B_l = p$. Tada možemo da modifikujemo permutaciju tako što na poziciju $j$ postavimo $A_l$, a sve ostale elemente pomerimo za jedno mesto desno. Nakon toga, potrebno je još da razrešimo probleme koji su mogli nastati sa elementima $A_m$ koji su u permutaciji bili između $j$ i $k$ i takvim da $B_m < p$. Nakon ovog tehničkog detalja kojeg ostavljamo čitaocu, dobija se permutacija koja ima neopadajući niz prefiksnih XOR-eva, a element $A_l$ na poziciji $j$. Složenost ovog rešenja je $O(Q\cdot N^2)$.
	
	## Rešenje kada $N, Q \leq 5000$
	U prethodnom podzadatku smo primetili da je dovoljno odabrati element koji što slabiju $0$ trenutnog prefiksnog XOR-a transformiše u $1$. Dovoljno je da elemente čuvamo prema njihovom najjačem bitu i da iteracijom kroz sve pozicije na kojima su $0$ (počevši od najslabije) u binarnom zapisu trenutnog prefiksnog XOR-a odaberemo proizvoljan element koji ima $1$ kao najjači bit na toj poziciji. Složenost ovog rešenja je $O(Q\cdot N \cdot \log_2 \max_i A_i)$.
	
	## Rešenje kada $A[i] < 64$.
	Primetimo da su u ovom slučaju i prefiksni XOR-evi do $64$. Ukoliko niz iz upita ima više od $64$ pozitivne vrednost, odgovor je `false`. U suprotnom možemo da primenimo rešenje iz prethodnog opisanog podzadatka. Složenost ovog rešenja je $O(Q\cdot \max_i A_i \cdot \log_2 \max_i A_i)$.
	
	## Rešenje kada $T[i] = 2$
	Za ovaj podzadatak je neophodno da dalje optimizujemo proveru uslova iz gramzivog rešenja. Primetili smo da je bilo dovoljno birati proizvoljan broj koji ima najveći bit postavljen na poziciji što slabije $0$ iz trenutnog prefiksnog XOR-a. Sada je potrebno da vidimo kada ćemo uspeti da odaberemo sve takve brojeve. Odabirom tog broja se $0$ na toj poziciji promenila u $1$ u narednim prefiksnim XOR-evima. Da bi opet odabrali broj koji ima $1$ na toj poziciji, potrebno je da se ponovo u prefiksnom XOR-u nađe $0$. Dakle, za svako (osim poslednjeg) postavljanje tog bita na $1$ u aktuelnom prefiksnom XOR-u, potrebno je da ga kasnije resetujemo, postavljanjem na $0$. Označimo sa $p_i$ broj elemenata u kojima je bit na poziciji $i$ najjači, a sa $q_i$ broj elemenata u kojima je taj bit postavljen, ali ne kao najjači. Potreban i dovoljan uslov je da $q_i \geq p_i + 1$. Vrednosti $p_i$ i $q_i$ u nekom podnizu možemo pronaći korišćenjem prefiksnih suma. Složenost ovog rešenja je $O(Q \cdot \log_2 \max_i A_i)$.
	
	## Glavno rešenje
	Za glavno rešenje bi bilo neophodno i da vršimo ažuriranje tih prefiksnih suma. Ovo zahteva da koristimo fenvikovo stablo (tj. `bit`). U fenvikovom stablu za svako $i$ pamtimo i ažuriramo koliko elemenata u odgovarajućem intervalu ima $1$ kao najjači bit na poziciji $i$, a koliko njih ima $1$, ali ne kao najjači bit. Složenost ovog rešenja je $O(Q \cdot \log_2 \max_i A_i \cdot \log_2 N)$.
	
	``` cpp title="04_opet_xor.cpp" linenums="1"
	#include <cstring>
	#include <cstdio>
	
	const int N = 1 << 19, B = 30;
	
	struct segtree {
	    int a[2*N];
	
	    void init() {
	        memset(a, 0, sizeof(a));
	    }
	
	    void set(int pos, int val) {
	        pos += N;
	        if(a[pos] == val) return;
	        a[pos] = val;
	        for(pos /= 2; pos; pos /= 2) {
	            a[pos] = a[2*pos] + a[2*pos + 1];
	        }
	    }
	
	    int query(int left, int right) {
	        left += N; right += N;
	        if(left > right) return 0;
	        if(left == right) return a[left];
	        int res = a[left] + a[right];
	        while(left / 2 != right / 2) {
	            if(left % 2 == 0) res += a[left + 1];
	            if(right % 2 == 1) res += a[right - 1];
	            left /= 2; right /= 2;
	        }
	        return res;
	    }
	} ;
	
	segtree bitcount[B];
	
	
	void set_value(int pos, int val) {
	    for(int i = 0; i < B; i++) {
	        if(val & (1 << i)) {
	            val ^= 1 << i;
	            // 1: highest bit, -1: not the highest
	            bitcount[i].set(pos, val ? -1 : 1);
	        } else {
	            bitcount[i].set(pos, 0);
	        }
	    }
	}
	
	
	bool query(int left, int n) {
	    int right = left + n - 1;
	    for(int i = 0; i < B; i++) {
	        // For each bit i, let a[i] = number of values where it is the
	        // highest bit, and b[i] = the number of values where it is
	        // set but not the highest. Pass only if a[i] <= b[i] + 1. We
	        // keep track of Q = a[i] - b[i], so we need Q <= 1.
	
	        // printf(" %d -> %d\n", i, bitcount[i].query(left, right));
	        // printf("    ");
	        // for(int j = 1; j <= 7; j++) printf("%3d", bitcount[i].a[j+N]);
	        // printf("\n");
	
	        if(bitcount[i].query(left, right) > 1) {
	            return false;
	        }
	    }
	    return true;
	}
	
	
	void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O) {
	    for(int i = 0; i < B; i++) bitcount[i].init();
	
	    for(int i = 1; i <= N; i++) set_value(i, A[i]);
	    for(int i = 1; i <= Q; i++) {
	        if(T[i] == 1) {
	            int pos = I[i], val = X[i];
	            A[pos] = val;
	            set_value(pos, A[pos]);
	        } else {
	            O[i] = query(I[i], X[i]);
	        }
	    }
	}

	```
