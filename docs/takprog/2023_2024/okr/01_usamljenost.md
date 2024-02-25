---
hide:
  - toc
---

# B1 - Usamljenost

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 300ms | 64MB |
	
	
	
	U godini $3024$ takmičenja iz matematike i fizike se i dalje rade na papiru, a postala su toliko slična da se sada održavaju na istom mestu.
	
	
	
	Ovogodišnje izglasano mesto održavanja je Kineski zid. Nakon završetka izrade zadataka, učenici takmičari ovih dveju oblasti okupili su se zajedno na zidu i poređali u ogroman red. Poznato je da se svaki učenik takmiči iz tačno jedne oblasti - ili matematike ili fizike. Takođe, njih je moguće numerisati prirodnim brojevima od $1$ do $N$, gde $N$ predstavlja ukupan broj takmičara. Za svakog od njih je, naravno, poznata oblast iz koje se takmiči.
	
	
	
	Profesor Vang odlučio je da slika svaku grupu od barem $3$ učenika. Tačnije, uslikaće sve segmente uzastopnih takmičara dužine barem $3$. Dakle, za svako $1 \leq L \leq R \leq N,\ R-L \geq 2$, on je uslikao učenike sa rednim brojevima $L,L+1,\ldots, R$.
	
	
	
	Nakon što je Vang ostavio slike na stolu, svi takmičari su navalili da ih pogledaju. Neki od njih su se možda osetili razočarano jer su se našli usamljeni na slici. To se dešava ukoliko je njegova oblast takmičenja (matematika ili fizika) drugačija od svih ostalih takmičara na slici. Potpuno revoltirani ovom katastrofom, takvi su pocepali sve slike na kojoj su ispali usamljeni.
	
	
	
	Ovo je zanemarljiva bol za profesora Vanga, ali velika tragedija za čovečanstvo. Pošto je on zauzet pregledanjem radova, upitao je Vas da mu kažete koliko je slika ukupno bilo pocepano.
	
	
	
	## Opis ulaza
	
	
	
	U prvom redu standardnog ulaza, nalazi se pozitivan ceo broj $N$ - ukupan broj takmičara.
	
	
	
	U drugom redu standardnog ulaza, nalazi se niska $S$ dužine $N$. Ona predstavlja, redom, oblasti iz koje se svaki takmičar takmiči. Slovo `M` predstavlja matematičara, a slovo `F` predstavlja fizičara.
	
	
	
	## Opis izlaza
	
	
	
	Na standardni izlaz ispisati jedan nenegativan ceo broj - broj pocepanih slika.
	
	
	
	
	## Primer 1
	
	
	
	### Ulaz
	
	```
	6
	MFMFMF
	```
	
	
	
	### Izlaz
	
	```
	4
	```
	
	
	
	### Objašnjenje
	
	
	
	Pocepane su slike koje odgovaraju segmentima učenika $[1,3]$, $[2,4]$, $[3,5]$ i $[4,6]$.
	
	
	
	## Primer 2
	
	
	
	### Ulaz
	
	```
	5
	MMMMF
	```
	
	
	
	### Izlaz
	
	```
	3
	```
	
	
	
	### Objašnjenje
	
	
	
	Pocepane su slike koje odgovaraju segmentima $[1,5]$, $[2,5]$ i $[3,5]$.
	
	
	
	## Ograničenja
	
	
	
	* $3 \leq N \leq 100\,000$
	* $|S| = N$, niska $S$ sastoji se od latiničnih slova `M` i `F` (isključivo velikih).
	
	
	
	Test primeri su podeljeni u tri disjunktne grupe:
	
	* U testovima vrednim 30 poena: $N \leq 100$;
	* U testovima vrednim 40 poena: $N \leq 5\,000$;
	* U testovima vrednim 30 poena: Bez dodatnih ograničenja.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Vladimir Milovanović | Aleksandar Višnjić | Aleksandar Višnjić | Aleksandar Višnjić |
	
	## Rešenje kada $N\leq 100$
	Prolazimo po podnizovima uzastopnih učenika preko dve ugnežđene petlje. Zatim za svaki podniz proveravamo da li je usamljen ili ne. Broj podnizova je $O(N^2)$, a složenost provere za svaki je $O(N)$. Stoga je ukupna vremenska složenost $O(N^3)$.
	
	## Rešenje kada $N\leq 5\,000$
	Ponavljamo ideju prethodnog podzadataka - prolazimo po svim podnizovima. Proveru je neophodno izvršiti efikasnije. Najjednostavnije je to učiniti narednim pseudo-kodom, u kome "usputno" računamo broj matematičara i fizičara:
	
	```
	for (i in [1,N]):
	br_mat=0
	br_fiz=0
	for (j in [i,N]):
	if S[i] is 'M':
	br_mat+=1
	if S[i] is 'F':
	br_fiz+=1
	```
	
	Vremenska složenost je $O(N^2)$.
	
	## Glavno rešenje
	Prethodnu iteraciju zamenjujemo matematičkom formulom. Za svakog učenika prebrojavamo broj slika koje je pocepao. Primetimo da ne postoji slika koja je pocepana od strane dva ili više učenika, pošto svaka slika dužine barem $3$ ima najviše jednog usamljenog učenika.
	
	Neka su $F_1 < F_2 < \ldots < F_K$ pozicije svih fizičara. Za $1 < i < K$ važi da je fizičar $i$ pocepao slike koje predstavljaju pod-intervale $[L,R] \subseteq [F_{i-1}+1,F_{i+1}-1]$ koji sadrže $i$. Tačnije, važi $F_{i+1}+1 \leq L \leq F_i$ i $F_i \leq R \leq F_{i+1}-1$. 
	
	* Za $L$ imamo $F_i - F_{i-1}$ opcija;
	* Za $R$ imamo $F_{i+1}-F_i$.
	
	Kako je izbor $L$ i $R$ nezavisan, ukupan broj izbora je $(F_i-F_{i-1}) \cdot (F_{i+1}-F_i) - 3$. Oduzimamo podnizove dužine manje od $3$ (njih ima tačno $3$). Ukoliko je vrednost izraza negativna, uzimamo $0$ (dešava se da učenik ne pocepa nijednu sliku).
	
	Prilikom računanja formule, u slučaju $i=1$ možemo uzeti $F_{i-1}=F_i$, a u slučaju $i=K$ možemo uzeti $F_{i+1}=F_i$.
	
	Sada znamo kako da za svakog fizičara izračunamo broj slika koje je pocepao. Isti postupak primenjujemo i za matematičare. Kada sve brojeve dobijene kao rezultate formula prosumiramo, dobijamo konačan odgovor. Složenost navedenog rešenja je $O(N)$.
	
	``` cpp title="01_usamljenost.cpp" linenums="1"
	#include <bits/stdc++.h>
	
	using namespace std;
	
	int main()
	{
	    int n; cin>>n;
	    string s; cin>>s;
	    vector<int> blokovi;
	    blokovi.push_back(1);
	    for (int i=1;i<(int)s.size();i++)
	    {
	        if (s[i]==s[i-1]) blokovi.back()++;
	        else blokovi.push_back(1);
	    }
	    
	    if ((int)blokovi.size()==1)
	    {
	        cout<<0<<endl;
	        return 0;
	    }
	    
	    long long odg=0;
	    odg+=blokovi[1]-1;
	    for (int i=1;i<(int)blokovi.size()-1;i++)
	    {
	        if (blokovi[i]==1)
	        {
	            odg+=(long long)(blokovi[i-1]+1)*(blokovi[i+1]+1)-3;
	        }
	        else
	        {
	            odg+=(blokovi[i-1]-1);
	            odg+=(blokovi[i+1]-1);
	        }
	    }
	    odg+=blokovi[(int)blokovi.size()-2]-1;
	    
	    cout<<odg<<endl;
	}
	```
