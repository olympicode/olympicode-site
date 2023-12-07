---
hide:
  - toc
---

# 1 - Brojorb

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 1024MB |
	
	
	Brojorb je pozitivan ceo broj koji u svom binarnom zapisu ima tačno onoliko **različitih** potpalindroma koliko i cifara.
	
	Potpalindrom je niz uzastopnih cifara u binarnom zapisu koje se čitaju isto i od napred i od nazad.
	
	Npr. $155 = (10011011)$<sub>2</sub> je brojorb zato što ima tačno 8 različitih potpalindroma: ([1]0011011), ([1001]1011), (1[0]011011), (1[00]11011), (10[0110]11), (100[11]011), (100[11011]), (1001[101]1). Dok recimo $203 = (11001011)$<sub>2</sub> nije brojorb zbog toga što ima 7 različitih potpalindroma.
	
	Potrebno je da odgovorite na pitanje koliko ima brojorba koji su manji od $N$?
	
	## Napomena
	
	Ovo je zadatak sa poznatim ulazom (*output-only* zadatak). Vama su dati ulazni fajlovi (`2.in`, `3.in`, ... `16.in`) kao i opis u tabeli ispod, dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`2.out`, `3.out`, ... `16.out`).
	
	**Vaš izvorni kod kojim ste generisali izlazne fajlove i izračunali rešenja potrebno je da pošaljete kao rešenje prvog primera (gde piše ”učitaj izlaz broj 01")**
	
	## Opis ulaza
	
	U prvom i jedinom redu ulaznih fajlova nalazi se nalazi broj $N$.
	
	## Opis izlaza
	
	U prvom i jedinom redu ispišite koliko ima brojorba koji su manji od $N$.
	
	## Primer 1
	
	### Ulaz
	
	```
	212
	```
	
	### Izlaz
	
	```
	209
	```
	
	### Objašnjenje primera
	
	Jedini brojevi manji od 212 koji nisu brojorbi su 203 i 211.
	
	## Bodovanje
	
	U tabeli ispod su dati ulazni brojevi za koje treba izračunati rešenje i broj poena koji donose.
	
	
	|         Primer        |       | Broj poena | | | | |      Primer        |  | Broj poena |
	|:-----------------:| :-------------------------: |:-------------:|:-:|:-:|:-:|:-:|:-----------------------:|:--------------:|:-------------------------:|
	|          01  | Pošaljite vaš kod | 0 | | | | | 09  | N = 35802962412 | 6 |
	|          02  | N = 1748063  | 5 | | | | | 10  | N = 146900865525 | 7 |
	|          03  | N = 13497742 | 5 | | | | | 11  | N = 287835581101 | 7 |
	|         04  | N = 39374969 | 5 | | | | | 12 | N = 681224605882 | 7 |
	|          05  | N = 375466538 | 6 | | | | | 13 | N = 1119584485997 | 8 |
	|         06  | N = 1809756849 | 6 | | | | | 14  | N = 2199024540265 | 8 |
	|         07  | N = 7676048889 | 6 | | | | | 15  | N = 4398047597508 | 9 |
	|         08  | N = 24323337576 | 6 | | | | | 16 | N = 8796093532561 | 9 |
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Dušan Zdravković | Dušan Zdravković | Ivan Stošić | Ivan Stošić |
	
	
	
	Za početak, dokažimo da je broj različitih potpalindroma nekog stringa manji ili jednak dužini stringa. Dokaz indukcijom po dužini stringa. Za stringove dužine $1$ tvrđenje očigledno važi. Neka je $S$ string dužine $n = |S| > 1$ i neka je $S' = S_1S_2\ldots S_{n-1}$. Posmatrajmo sve sufikse od $S$ koji su palindromi. Svi osim najdužeg sufiksa se sigurno javljaju i u $S'$ jer su oni ujedno pravi prefiksi najdužeg sufiks palindroma. Odavde sledi da $S$ ima najviše $1$ potpalindrom više od $S'$ što dokazuje tvrđenje. Stringove koji zadovoljavaju jednakost ove teoreme zvaćemo **punim**.
	
	Korisno je primetiti da, ukoliko je $S$ pun string, tada je i svaki njegov prefiks takođe pun string, što nam omogućava da ovakve stringove generišemo rekurzivno, tako što na trenutni pun string dodajemo karakter $0$ ili $1$, sve dok vrednost ovog broja ne dostigne gornju granicu, kada izlazimo iz rekurzije. Ovu rekurziju možemo ubrzati na sledeći način:
	
	* Umesto sa stringovima, raditi sa bit maskama. Sve potrebne operacije sa stringovima mogu se implementirati kao bitovske operacije na brojevima.
	* Tokom rekurzije čuvati skup potpalindroma za trenutni broj. Unutar jednog koraka rekurzije ovaj skup će se promeniti za tačno jedan element.
	* Proveravamo samo najduži sufiks palindrom novogenerisanog broja. Iz dokaza teoreme znamo da je dovoljno posmatrati samo njega.
	* Pored samog broja, čuvati i obrnut zapis tog broja u rekurziji kako bi se izbeglo njegovo obrtanje pri traženju najdužeg sufiks palindroma.
	
	Sa ovim opservacijama, složenost rekurzivne funkcije može se spustiti na $O(m)$ po pozivu, gde je $m$ najveća dužina binarnog zapisa brojeva. Ukupna složenost celog algoritma je onda $O(mk)$, gde je $k$ broj pronađenih punih stringova. Kako je $k < 10^{10}$ čak i za poslednji, najveći primer, vreme izvršenja celog programa je nekoliko desetina minuta.
	
	``` cpp title="01_brojorb.cpp" linenums="1"
	#include<bits/stdc++.h>
	using namespace std;
	
	#define MAXN 100
	#define MAXMEM 1200555333
	
	int N;
	long long res;
	long long resN[MAXN];
	long long maxV = 8796093532561LL;
	
	int brP = 16;
	long long primeri[] = {-1, -1, 1748063LL, 13497742LL, 39374969LL, 375466538LL, 1809756849LL, 7676048889LL, 24323337576LL, 
	35802962412LL, 146900865525LL, 287835581101LL, 681224605882LL, 1119584485997LL, 2199024540265LL, 4398047597508LL, 8796093532561LL};
	int trres = 2;
	long long resP[MAXN];
	
	int startTime, endTime;
	
	void printTime(int time)
	{
	    printf("time = %02d:%02d\n", time % 3600 / 60, time % 60);
	}
	
	int s[MAXN];
	
	long long palt[MAXN];
	
	char iskorisceni[MAXMEM];
	
	void popLast(int p) {
	    iskorisceni[palt[p]] = 0;
	}
	
	bool proveriDalImaIUbaci(int p, long long t, int l) {
	    long long pt = (t<<1LL) + (l&1);
	
	    if (!iskorisceni[pt]) {
	        iskorisceni[pt] = 1;
	        palt[p] = pt;
	        return true;
	    } else {
	        return false;
	    }
	}
	
	int brp[MAXN];
	int plens[MAXN][MAXN];
	long long plensT[MAXN][MAXN];
	
	bool addLast(int p) {
	
	    int sp = s[p];
	
	    brp[p] = 1;
	    plens[p][1] = 1;
	    
	    long long t = 2LL + sp;
	
	    plensT[p][1] = t;
	
	    bool bb = false;
	
	    if (proveriDalImaIUbaci(p,t,1)) {
	        return true;
	    }
	
	    if (p>0) {
	
	        if (sp == s[p-1]) {
	            plens[p][++brp[p]] = 2;
	            plensT[p][brp[p]] = t;
	            if (proveriDalImaIUbaci(p,t,2)) {
	                return true;
	            }
	        }
	
	        for(int i=1; i<=brp[p-1]; i++) {
	
	            int l = plens[p-1][i];
	
	            if (p - l - 1 >= 0 && sp == s[p-l-1]) {
	
	                t = (plensT[p-1][i]<<1LL) + sp;
	
	                plens[p][++brp[p]] = l+2;
	                plensT[p][brp[p]] = t;
	
	                if (proveriDalImaIUbaci(p,t,l+2)) {
	                    return true;
	                }
	            }
	        }
	    }
	
	    return bb;
	}
	
	void printbin(long long v) {
	    if (v/2 != 0) printbin(v/2);
	    printf("%lld", v % 2);
	}
	
	void idar(int p, long long v, int tp) {
	
	    if (v >= maxV) return;
	
	    for(int b=0; b<2; b++) {
	        if (p==0 && b==0) continue;
	        long long pv = (v<<1LL) + b;
	
	        if (pv >= maxV) continue;
	
	        s[p] = b;
	        if (addLast(p)) {
	            
	            //trres = upper_bound(primeri, primeri+brP, pv) - primeri;
	            while(pv >= primeri[tp]) tp++;
	            
	            res++;
	            resP[tp]++;
	            idar(p+1, pv, tp);
	            popLast(p);  
	        }
	    }
	}
	
	void ispisiRes() {
	    char pathin[555], pathout[555];
	
	    long long ressum = 0;
	
	    for(int i=2; i<=brP; i++) {
	        sprintf(pathin, "testcases/%d.in", i);
	        sprintf(pathout, "testcases/%d.out", i);
	
	        FILE *fin = fopen(pathin, "w"), *fout = fopen(pathout, "w");
	
	        ressum += resP[i];
	
	        fprintf(fin,"%lld\n", primeri[i]);
	        fprintf(fout,"%lld\n", ressum);
	        fclose(fin); fclose(fout);
	    }
	}
	
	
	int main() {
	
	    startTime = time(0);
	
	    res = 0;
	
	    idar(0,0,2);
	
	    printf("%lld\n", res);
	    //printf("%lld\n", resN[N]);
	
	    ispisiRes();
	
	    endTime = time(0);
	    printTime(endTime - startTime);
	
	    return 0;
	}

	```
