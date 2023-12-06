---
hide:
  - toc
---

# 5 - Voćnjak

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 128MB |
	
	Petar ima ogroman voćnjak šljiva koji je idealno organizovao tako da su šljive poređane u $N$ redova (vrsta) i $N$ kolona. Visine svih stabala su pozitivni celi brojevi. **Ne postoje dva stabla iste visine**. Pri tome je stabla tako oblikovao tako da za svaku vrstu važi da visine stabala sleva nadesno obrazuju rastući ili opadajući niz (mogu postojati vrste poređane u rastućem, ali isto tako i vrste poređane u opadajućem poretku, na potpuno slučajan način poređane). Slično za svaku kolonu važi da visine stabala od prvog prema poslednjem obrazuju rastući ili opadajući niz (mogu postojati kolone u kojima su poređane u rastućem poretku i kolone u kojima su poređane u opadajućem poretku, ali poredak vama nije poznat). Vrste su numerisane brojevima od $1$ do $N$, a kolone brojevima od $1$ do $N$. Na raspolaganju imate funkciju (kasnije će biti detaljno opisana) kojom možete dobiti visinu stabla koje se nalazi u određenoj vrsti i koloni (zvaćemo tu funkciju upit). Potrebno je da sa što manje upita odredite da li u voćnjaku postoji stablo zadate visine i poziciju tog stabla, ako postoji (redni broj vrste i redni broj kolone). Zato će biti zadat prirodan broj $K$. Ako vaš program u ne više od $K$ upita odgovori tačno smatra se da je vaš program korektno rešio taj test primer, u suprotnom, smatra se da je rešenje primera netačno.
	
	## Opisi funkcija
	Potrebno je da implementirate funkciju
	
	*  $Resi(N, K, V, I, J)$
	
	koja treba da odredi da li se u voćnjaku sa $N$ vrsta i $N$ kolona nalazi stablo visine $V$ i ako se nalazi odredi redni broj vrste i redni broj kolone u kome se nalazi stablo visine $V$. Ako stablo ne postoji, onda vrednosti za redni broj vrste i redni broj kolone treba da budu 0. $K$ je predviđeni broj upita.
	
	Na raspolaganju imate funkciju 
	
	 *  $DajVisinu(I, J)$
	
	koja treba da vrati visinu stabla koje se nalazi u vrsti $I$ i kooni $J$. Ako koordinate $I$ i $J$ nisu u dozvoljenim granicama, funkcija vraća vrednost $-1$.
	
	## Primer 1
	Neka je $N = 4, K = 16, V = 9$, a matrica sa visinama stabala:
	
	```
	3 6 10 15
	5 9 13 18
	31 27 23 20
	45 28 32 25
	```
	
	Ako je  prvi upit bio za polje $(2, 4)$ odgovor bi bio $18$. Ako je drugi upit za polje $(2,1)$ odgovor bi bio $5$. Konačno, ako je treći upit za polje $(2,2)$ odgovor bi bio 9, pa bi vaša funkcija mogla da vrati rešenje $I=2$, $J=2$.
	
	## Ograničenja
	
	+ $N \leq 1000$.
	+ $K \leq 10000$.
	+ Visine stabala si između $1$ i $100.000.000$.
	
	## Podzadaci
	
	 + Podzadatak 1 [8 poena]: $N \leq 100$, $K = N \times N$.
	 + Podzadatak 2 [14 poena]: $N \leq 1.000$, $K = 10.000$.
	 + Podzadatak 3 [24 poena]: $N \leq 1.000$, $K = 6.000$.
	 + Podzadatak 4 [54 poena]: $N \leq 1.000$, $K = 4.000$.
	
	## Detalji implementacije
	Potrebno je da pošaljete tačno jedan fajl `vocnjak.cpp` ili `vocnjak.pas`, koji implementira pomenutu funkciju. Osim tražene funkcije, vaš fajl može sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke.
	
	U zavisnosti od programskog jezika koji koristite, vaša funkcija/procedura mora biti sledećeg oblika:
	
	| Jezik   | Deklaracija funkcije                                                                                    | 
	| ------- | ------------------------------------------------------------------------------------------------------- |
	| C++     | `void Resi(int N, int K, int V, int *I, int *J);`   |
	| Pascal  | `procedure Resi(N, K, V: longint; var I, J: longint);`   |
	
	U zavisnosti od programskog jezika koji koristite,  vaša funkcija/procedura može koristiti fuknciju:
	
	| Jezik   | Deklaracija funkcije                                                                                    | 
	| ------- | ------------------------------------------------------------------------------------------------------- |
	| C++     | `int DajVisinu(int I, int J);`   |
	| Pascal  | `function DajVisinu(I, J: longint): longint;`   |
	
	## Testiranje i eksperimentisanje
	Uz zadatak, obezbeđeni su vam "template" fajlovi `code.cpp` i `code.pas` koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi `grader.cpp`, `grader.pas` koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza sledeće podatke:
	
	+ U prvom redu brojeve $N, K, V$,
	+ U narednih $N$ redova po $N$ brojeva, brojevi koji predstavljaju visine stabala po redovima u voćnjaku.
	
	Zatim ovaj program zove vašu funkciju i štampa brojeve $I$, $J$ i $T$. $I, J$ su redni broj vrste i kolone koje je vratila vaša funkcija, a $T$ je broj poziva funkcije $DajVisinu$. Kodove ovih programa možete menjati po potrebi, ali će za testiranje biti korišćena originalna verzija ovih programa.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Nikola Milosavljević | Dragan Urošević | Bhuvnesh Jain | Nikola Spasić |
	
	Možete pročitati editorijal na engleskom (CodeChef je koristio naš zadatak za Challenge rundu): [Link](https://discuss.codechef.com/t/inmat-editorial/19792)
	
	``` cpp title="05_vocnjak.cpp" linenums="1"
	# include <stdio.h>
	# include "code.h"
	
	# define MAXN 1010
	int smv[MAXN], smk[MAXN];
	int npv, npk;
	int a[MAXN][MAXN];
	
	
	
	void Nadji(int i1, int j1, int i2, int j2, int vv, int *ii, int *jj) {
		int i, j;
		if (smv[i1] == 1) {
			if (smk[j2] == 1) {
				i = i1; j = j2;
				while (i <= i2) {
	//				printf("cc %d %d\n", i, j);
					if (a[i][j] == 0)
						a[i][j] = DajVisinu(i, j);
					if (a[i][j] == vv) {
						*ii = i; *jj = j; return;
					}
					if (vv < a[i][j]) {
						j--;
						if (j < j1) return; // j < j1
					} else {
						if (j < j2) j++;
						if (++i > i2) return;
					}
				}						
			} else {
				i = i2; j = j2;
				while (i >= i1) {
	//				printf("cc %d %d\n", i, j);
					if (a[i][j] == 0)
						a[i][j] = DajVisinu(i, j);
					if (a[i][j] == vv) {
						*ii = i; *jj = j; return;
					}
					if (vv < a[i][j]) {
						j--;	
						if (j < j1) return; // j < j1
					} else {
						if (j < j2) j++;
						if (--i < i1) return;
					}
				}						
			}
		} else {
			if (smk[j2] == 1) {
				i = i1; j = j1;
				while (i <= i2) {
	//				printf("cc %d %d\n", i, j);
					if (a[i][j] == 0)
					if (a[i][j] == 0)
						a[i][j] = DajVisinu(i, j);
					if (a[i][j] == vv) {
						*ii = i; *jj = j; return;
					}
					if (vv < a[i][j]) {
						j++; 
						if (j > j2) return;
					} else {
						if (j > j1) j--;
						if (++i > i2) return;
					}
				}						
			} else {
				i = i2; j = j1;
				while (i >= i1) {
	//				printf("cc %d %d\n", i, j);
					if (a[i][j] == 0)
						a[i][j] = DajVisinu(i, j);
					if (a[i][j] == vv) {
						*ii = i; *jj = j; return;
					}
					if (vv < a[i][j]) {
						j++;
						if (j > j2) return;	
					} else {
						if (j > j1) j--;
						if (--i < 1) return;
					}
				}						
			}
		}
	}
	
	
	
	
	
	void Resi2x2AA(int n, int i1, int j1, int vv, int *ii, int *jj) {
		int i, j;
		int radi[2][2] = {{1,1},{1,1}};
	//	printf("Ovde %d %d %d %d\n", i1, j1, a[i1-1][j1-1], a[i1][j1]);
		if (vv > a[i1-1][j1-1]) {
			radi[0][0] = 0;
		} else {
			radi[0][1] = radi[1][0] = 0;
		}
		if (vv > a[i1][j1]) {
			radi[1][1] = 0;
		} else {
			radi[0][1] = radi[1][0] = 0;
		}
	//	printf("%d\n", radi[0][1]);
		if (radi[0][0]) {
			Nadji(1, 1, i1-1, j1-1, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[0][1]) {
			Nadji(1, j1, i1-1, n, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[1][0]) {
			Nadji(i1, 1, n, j1-1, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[1][1]) {
			Nadji(i1, j1, n, n, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}	
	}
	
	
	void Resi2x2BB(int n, int i1, int j1, int vv, int *ii, int *jj) {
		int i, j;
		int radi[2][2] = {{1,1},{1,1}};
	//	printf("Ovde %d %d %d %d\n", i1, j1, a[i1-1][j1-1], a[i1][j1]);
		if (vv < a[i1-1][j1-1]) {
			radi[0][0] = 0;
		} else {
			radi[0][1] = radi[1][0] = 0;
		}
		if (vv < a[i1][j1]) {
			radi[1][1] = 0;
		} else {
			radi[0][1] = radi[1][0] = 0;
		}
	//	printf("%d\n", radi[0][1]);
		if (radi[0][0]) {
			Nadji(1, 1, i1-1, j1-1, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[0][1]) {
			Nadji(1, j1, i1-1, n, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[1][0]) {
			Nadji(i1, 1, n, j1-1, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}
		if (radi[1][1]) {
			Nadji(i1, j1, n, n, vv, ii, jj);
			if ((*ii != 0) && (*jj != 0)) return;
		}	
	}
	
	
	
	
	void Resi2x2(int n, int vv, int *ii, int *jj) {
		int i, j, i1, j1, i2, j2;
		i1 = 1; j1 = 1;
		*ii = *jj = 0;
		while (smv[i1] == smv[1]) i1++;
		while (smk[j1] == smk[1]) j1++;
		a[i1-1][j1-1] = DajVisinu(i1-1, j1-1);	
		a[i1-1][j1] = DajVisinu(i1-1, j1);	
		a[i1][j1-1] = DajVisinu(i1, j1-1);	
		a[i1][j1] = DajVisinu(i1, j1);	
		if (a[i1-1][j1-1] == vv) {
			*ii = i1-1; *jj = j1-1; return; 
		}
		if (a[i1-1][j1] == vv) {
			*ii = i1-1; *jj = j1; return; 
		}
		if (a[i1][j1-1] == vv) {
			*ii = i1; *jj = j1-1; return; 
		}
		if (a[i1][j1] == vv) {
			*ii = i1; *jj = j1; return; 
		}
		if ((smv[1] == 1) && (smk[1] == 1)) {
			Resi2x2AA(n, i1, j1, vv, ii, jj);
			return;	
		}
		if ((smv[1] == -1) && (smk[1] == -1)) {
			Resi2x2BB(n, i1, j1, vv, ii, jj);
			return;	
		}
	
	}
	
	
	void ResiV(int n, int vv, int *ii, int *jj) {
	
		int nadjen = 0;
		int i, j, i1, i2;
		i2 = 1;
		*ii = *jj = 0;
		while (i2 <= n) {
			i1 = i2;
			while ((i2 <= n) && (smv[i2] == smv[i1])) i2++;
	//		printf("AA %d %d %d\n", i1, i2, vv);
			if (smk[1] == 1) {
				if (smv[i1] == -1) {
					a[i2-1][1] = DajVisinu(i2-1, 1);
					if (vv <= a[i2-1][1]) {
						nadjen = 1; break;
					}
				} else {
					a[i2-1][n] = DajVisinu(i2-1, n);
					if (vv <= a[i2-1][n]) {
						nadjen = 1; break;
					}
				}
			} else {
				if (smv[i1] == -1) {
					a[i2-1][n] = DajVisinu(i2-1, n);
					if (vv >= a[i2-1][n]) {
						nadjen = 1; break;
					}
				} else {
					a[i2-1][1] = DajVisinu(i2-1, 1);
					if (vv >= a[i2-1][1]) {
						nadjen = 1; break;
					}
				}
			}
		}
	//	printf("BB %d %d\n", i2, a[i2-1][n]);
		if (!nadjen) {
			*ii = *jj = 0;
			return;
		}
		i2--;
		Nadji(i1, 1, i2, n, vv, ii, jj);
	
	
	}
	
	void ResiK(int n, int vv, int *ii, int *jj) {
		int nadjen = 0;
		int i, j, j1, j2;
		j2 = 1;
		*ii = *jj = 0;
		while (j2 <= n) {
			j1 = j2;
			while ((j2 <= n) && (smk[j2] == smk[j1])) j2++;
	//		printf("AA %d %d %d\n", j1, j2, vv);
			if (smv[1] == 1) {
				if (smk[j1] == -1) {
					a[1][j2-1] = DajVisinu(1, j2-1);
					if (vv <= a[1][j2-1]) {
						nadjen = 1; break;
					}
				} else {
					a[n][j2-1] = DajVisinu(n, j2-1);
					if (vv <= a[n][j2-1]) {
						nadjen = 1; break;
					}
				}
			} else {
				if (smk[j1] == -1) {
					a[n][j2-1] = DajVisinu(n, j2-1);
					if (vv >= a[n][j2-1]) {
						nadjen = 1; break;
					}
				} else {
					a[1][j2-1] = DajVisinu(1, j2-1);
					if (vv >= a[1][j2-1]) {
						nadjen = 1; break;
					}
				}
			}
		}
	//	printf("BB %d %d\n", j2, a[n][j2-1]);
		if (!nadjen) {
			*ii = *jj = 0;
			return;
		}
		j2--;
		Nadji(1, j1, n, j2, vv, ii, jj);
	}
	
	
	void Resi(int n, int k, int vv, int *ii, int *jj) {
		int i, j;
		a[1][1] = DajVisinu(1, 1);
		a[1][2] = DajVisinu(1, 2);
		if (a[1][1] < a[1][2]) smv[1] = 1; else smv[1] = -1;
		for (i = 2; i < n; i++) {
			a[i][i] = DajVisinu(i, i);
			a[i][i+1] = DajVisinu(i, i+1);
			if (a[i][i] < a[i][i+1]) smv[i] = 1; else smv[i] = -1;
			if (a[i-1][i] < a[i][i]) smk[i] = 1; else smk[i] = -1;
		}
		a[n][n] = DajVisinu(n, n);
		a[n][1] = DajVisinu(n, 1);
		if (a[n][1] < a[n][n])	smv[n] = 1; else smv[n] = -1;
		if (a[1][1] < a[n][1])	smk[1] = 1; else smk[1] = -1;
		if (a[n-1][n] < a[n][n]) smk[n] = 1; else smk[n] = -1;
		npv = npk = 1;
		for (i = 2; i <= n; i++) {
			if (smv[i-1] != smv[i]) npv++;
			if (smk[i-1] != smk[i]) npk++;
		}	
		  
	//	printf("%d %d\n", npv, npk);
	
		if (npv == 1) {
			ResiK(n, vv, ii, jj);
			return;
		}
		if (npk == 1) {
			ResiV(n, vv, ii, jj);
			return;
		}
		Resi2x2(n, vv, ii, jj);
	}

	```
