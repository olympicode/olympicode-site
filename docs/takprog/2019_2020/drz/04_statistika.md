---
hide:
  - toc
---

# A1 - Statistika

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1500ms | 256MB |
	
	Dobili ste pristup bazi podataka o rasprostranjenosti virusa u vašem gradu, iz koje se može zaključiti puno korisnih podataka o širenju bolesti. Grad je podeljen na polja koja čine matricu sa $N$ redova i $M$ kolona, i vrednost $A_{i,j}$ u bazi predstavlja broj slučajeva virusa u polju $(i, j)$.
	
	Odlučili ste da pronađete broj najzdravijih polja, odnosno polja koja sadrže **manji ili jednak broj slučajeva od svakog polja u matrici**. Da bi učinili analizu zanimljivijom, palo vam je na pamet da je ponovite $Q$ puta, i da svaki put odaberete neki pravougaoni deo grada koji ćete **ignorisati**.
	
	## Opis ulaza
	
	Prva linija standardnog ulaza sadrži tri prirodna broja: broj redova i kolona u gradu $N$ i $M$, kao i broj upita $Q$.
	
	Narednih $N$ linija sadrže po $M$ brojeva $A_{i,j}$ koji čine matricu brojeva slučajeva virusa.
	
	Narednih $Q$ linija sadrže po četiri broja $i$, $j$, $h$ i $w$, koji opisuju deo grada koji treba ignorisati kada tražite najzdravija polja u tom upitu: gornje levo polje je u $i$-toj vrsti i $j$-toj koloni (gde $(1,1)$ odgovara gornjem levom uglu grada), $h$ je visina dela (broj vrsta) a $w$ širina (broj kolona).
	
	## Opis izlaza
	
	Na standardni izlaz ispisati $Q$ linija sa po jednim prirodnim brojem, gde $i$-ta linija sadrži broj najzdravijih polja u gradu bez dela opisanog u $i$-tom upitu.
	
	## Primer 1
	
	
	### Ulaz
	
	```
	3 3 3
	1 2 3
	1 1 2
	3 3 3
	1 1 1 1
	1 1 2 2
	2 2 1 1
	```
	
	### Izlaz
	
	```
	2
	1
	2
	```
	
	## Primer 2
	
	### Ulaz
	
	```
	3 3 1
	1 2 3
	2 1 3
	1 9 1
	2 2 1 1
	```
	
	### Izlaz
	
	```
	3
	```
	
	### Objašnjenje primera
	
	U prvom primeru, u prvom upitu posmatramo ceo grad osim gornjeg levog polja. Najzdravija polja su u ovom slučaju ona koja imaju samo jedan slučaj, i takvih ima dva (osim ignorisanog). U drugom upitu posmatramo samo kranju desnu kolonu i poslednji red, gde je najzdravije jedino polje sa dva slučaja. U poslednjem upitu ignorišemo centralno polje, i ostaju dva sa po jednim slučajem.
	
	## Napomene
	
	Zbog velikog ulaza, nije preporučljivo koristiti sporije metode učitavanja podataka, kao što su cin/cout bez sinhronizacije u C++-u.
	
	## Ograničenja
	
	- $N, M \leq 1000$
	- $Q \leq 10^5$
	- $0 \leq A_{i,j} \leq 10^9$ za sve $1 \leq i \leq N, 1 \leq j \leq M$
	- Ni u jednom upitu neće biti ignorisan ceo grad.
	
	Test primeri su podeljeni u pet podzadataka:
	
	- **[20 poena]:** $N, M, Q \leq 100$
	- **[15 poena]:** $N, M \leq 300, Q \leq 2 \cdot 10^4$
	- **[15 poena]:** $A_{i,j} \in \{0, 1\}$ za sve $1 \leq i \leq N, 1 \leq j \leq M$
	- **[20 poena]:** $h, w \leq 10$ za sve zadate podmatrice.
	- **[30 poena]:** bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Dimitrije Erdeljan | Dimitrije Erdeljan | Ivan Stošić |
	
	
	Možemo podeliti grad na tri dela: deo koji ignorišemo (u primeru dole
	obeležen sa `?`), gornji levi (`A`) i donji desni "trougao" (`b`):
	
	```
	AAAAAAAA
	AA???bbb
	AA???bbb
	AAbbbbbb
	AAbbbbbb
	```
	
	Za oba trougla ćemo izračunati par $(m, n)$, gde je $m$ broj slučajeva
	u najzdravijem polju, a $n$ broj takvih polja. Ako smo dobili $(m_a,
	n_a)$ za gornji levi, a $(m_b, n_b)$ za donji desni, ukupno rešenje
	možemo odrediti kao:
	
	* $(m_a, n_a)$, ako $m_a < m_b$
	* $(m_b, n_b)$, ako $m_a > m_b$
	* $(m_a, n_a + n_b)$, ako $m_a = m_b$
	
	Gornji levi trougao možemo posmatrati kao dva preklopljena pravougaonika
	sa jednim temenom u gornjem levom uglu table -- na slici, `A` i `a`
	(preklapanje obeleženo sa `@`):
	
	```
	@@aaaaaa
	AA???...
	AA???...
	AA......
	AA......
	```
	
	Kao i ranije, možemo odrediti broj slučajeva u najzdravijem polju i
	broj takvih polja u trouglu "sabiranjem" ovih rešenja za dva
	pravougaonika. U dobijenom rezultatu će polja obeležena sa `@` biti
	uračunata dva puta i moramo eliminsati jedno od pojavljivanja -- neka je
	$(m,n)$ "zbir" pravougaonika $A$ i $a$, a $(m', n')$ obuhvata samo
	`@`. Tada je ukupno rešenje za trougao:
	
	* $(m, n-n')$, ako $m = m'$ (neka od najzdravijih polja jesu u `@`)
	* $(m, n)$, ako $m \neq m'$ (nijedno od tih polja nije u `@`, tako da
	  ništa nismo brojali dva puta).
	
	Sada je samo potrebno da pre upita odredimo ove parove za svaki
	pravougaonik sa temenom u gornjem levom uglu matrice. Ovo možemo
	uraditi u $\mathcal{O}(N^2)$: svaki pravougaonik možemo posmatrati kao
	uniju donjeg desnog polja i "trougla", vrednost za trougao odrediti kao
	što je gore opisano (iz prethodno izračunatih vrednosti za manje
	pravougaonike) i dodati joj donje desno polje.
	
	Isti postupak ćemo koristiti za donji desni "trougao", gde unapred
	određujemo rešenja za pravougaonike sa temenom u donjem desnom uglu.
	Ukupna složenost je $\mathcal{O}(N^2)$ za izračunavanje ovih vrednosti,
	i $\mathcal{O}(1)$ po upitu, odnosno $\mathcal{O}(N^2 + Q)$ za ceo
	zadatak.
	
	``` cpp title="04_statistika.cpp" linenums="1"
	#include <cstdio>
	#include <cassert>
	
	struct entry { int min, count; } ;
	const entry ZERO = {1<<30, 0};
	bool operator==(const entry a, const entry b) { return a.min == b.min && a.count == b.count; }
	entry operator+(const entry a, const entry b)
	{
	    if(a.min < b.min) return a;
	    else if(a.min > b.min) return b;
	    else return {a.min, a.count + b.count};
	}
	entry operator-(const entry a, const entry b)
	{
	    // only called if a has double-counted entries in b, so this
	    // should hold
	    assert(a.min != b.min || (a == ZERO && b == ZERO) || a.count > b.count);
	    return {a.min, a.min == b.min ? (a.count - b.count) : a.count};
	}
	const int N = 1000;
	int city[N][N];
	entry sum_up[N][N], sum_down[N][N];
	int n, m;
	
	inline entry get_up(int i, int j)
	{
	    assert(i < n && j < m);
	    return i >= 0 && j >= 0 ? sum_up[i][j] : ZERO;
	}
	inline entry get_down(int i, int j)
	{
	    assert(i >= 0 && j >= 0);
	    return i < n && j < m ? sum_down[i][j] : ZERO;
	}
	
	int main()
	{
	    int q;
	    scanf("%d %d %d", &n, &m, &q);
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++)
	            scanf("%d", &city[i][j]);
	
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++)
	            sum_up[i][j] = (entry){city[i][j], 1} + get_up(i-1, j) + get_up(i, j-1) - get_up(i-1, j-1);
	
	    for(int i = n - 1; i >= 0; i--)
	        for(int j = m - 1; j >= 0; j--)
	            sum_down[i][j] = (entry){city[i][j], 1} + get_down(i+1, j) + get_down(i, j+1) - get_down(i+1, j+1);
	
	    while(q--)
	    {
	        int i, j, h, w;
	        scanf("%d %d %d %d", &i, &j, &h, &w);
	        i--; j--;  // 0-indexing
	        int ii = i + h - 1, jj = j + w - 1;  // bottom-right
	        entry topleft = get_up(n-1, j-1) + get_up(i-1, m-1) - get_up(i-1, j-1);
	        entry botright = get_down(i, jj+1) + get_down(ii+1, j) - get_down(ii+1, jj+1);
	        entry res = topleft + botright;
	        printf("%d\n", res.count);
	    }
	
	    return 0;
	}

	```
