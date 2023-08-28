# A1 - Koncert

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Nikola Milosavljević | Nikola Milosavljević | Nikola Milosavljević | Igor Pavlović |

Kako nije dozvoljeno ponavljanje polja na putu, u svakom redu se ide samo u jednom smeru (ulevo ili udesno) ili direktno na gore. Promena strkture reda guranjem ne utiče na dalji deo puta jer nije dozvoljeno vraćanje unazad.

U **Podzadatku 1** je dovoljno koristiti klasično dinamičko programiranje za računanje broja odgovarajućih puteva u $O(nm)$ ili primeniti malo kombinatorike: za svaki od $n$ redova možemo na $m$ načina izabrati polje u koje dolazimo iz prethodnog reda (za poslednji red, to je polje iz koga počinjemo) a nakon toga je put jedinstveno određen. Dakle, odgovor je $m^n$ mod $(10^9 + 7)$. Za **Podzadatak 2** je dovoljno isprobati sve moguće puteve, najednostavnije koristeći rekurziju/bektrek u složenosti $O(m\cdot m^n)$.

Zadatak je najprirodnije rešavati **dinamičkim programiranjem**. Definišimo $d[i][j] =$ broj (validnih) puteva koji se završavaju u polju $(i,j)$ date matrice $a$ pri čemu je poslednji potez "nagore". Konačno rešenje je $\sum_{1 \leq j \leq m, \  a[1][j]=0} d[1][j]$ a početne vrednosti su $d[n][j] = a[n][j]$ za $j=1,2,\ldots,m$. Rekurentna veza je data sa $d[i][j] =\sum_x d[i+1][x]$, gde se sumiranje vrši po svim indeksima $x$ takvih da je (guranjem) u $(i+1)$-om redu moguće doći od pozicije $x$ (koja treba biti prazno polje) do pozicije $j$ (koja ne mora nužno biti prazno polje). Najjednostavniji način je ispitati svaku poziciju $x$ iz $(i+1)$-og reda; ako je $x_L$ pozicija $(k+1)$-ve osobe levo  u odnosu na poziciju $x$ a $x_R$ pozicija $(k+1)$-ve osobe desno  u odnosu na poziciju $x$, tada, sa pozicije $x$ možemo guranjem doći do bilo koje koje (i samo te) pozicije iz segmenta $[x_L+(k+1), x_R-k]$. Vrednosti $x_L$ i $x_R$ za svako $x$ možemo odrediti u svega dva prolaza kroz $(i+1)$-vi red (sleva udesno i sdesna ulevo) npr. ubacivajući pozicije jedinica na koje naiđemo u neki pomoćni vektor. Ovo daje rešenje složenosti $O(nm^2)$ što je dovoljno za **Podzadatak 4**.

U **Podzadatku 3** nema guranja pa se rekurentna veza može uprostiti uvođenjem pomoćnih matrica, npr. $L[i][j]=$ broj puteva koji se završavaju u polju $(i,j)$ pri čemu je poslednji potez "ulevo" i analogno za $R[i][j]$ i "udesno". Sada se sve ove matrice mogu paraleno izračunati, $d[i][j] = d[i+1][j]+L[i+1][j]+R[i+1][j]$, $L[i][j] = L[i][j+1]+d[i][j+1]$, $R[i][j] = R[i][j-1]+d[i][j-1]$ (u odgovarajućem redosledu i proveru zauzetosti polja). To je $O(1)$ po polju tj. $O(nm)$ ukupno.

Za konačno rešenje, treba ubrzati $O(nm^2)$ algoritam. Iz tog rešenja, znamo da će za svako polje $(i+1,x)$, vrednost $d[i+1][x]$ učestvovati u formuli za računanje vrednosti $d[i][j]$ za svako $j\in[x_L+(k+1),x_R-k]$ (uz proveru $d[i][j]=0$ i granice za segment). Zato možemo, nakon obrade $(i+1)$-og reda, za svako $x$ povećati sve $d[i][j]$ iz reda iznad koji su u odgovarajućem segmentu za $d[i+1][x]$. Naravno, direktna implementacija ovoga ne bi smanjila složenost ali možemo koristiti poznati trik; dovoljno je dodati elementu na početku segmenta $+d[i+1][x]$ i dodati elementu nakon kraja segmenta $-d[i+1][x]$ (za svako $x$) i na kraju će tražene vrednosti u novom redu biti prefiksne sume trenutnih vrednosti. Ovo daje algoritam složenosti $O(nm)$.

Alternativno (i nešto jednostavnije rešenje) je definisati $d[i][j]=$broj puteva koji *počinju* iz polja $(i,j)$. Tada vrednosti možemo računati odozgo nadole i, na osnovu prethodne diskusije, važi $d[i][j] = \sum_{j_L + k + 1 \leq x \leq j_R - k} d[i-1][x]$, gde se vrednosti $j_L$ i $j_R$ odnose na trenutni, $i$-ti red. Koristeći prefiksne sume, prethodnu sumu možemo izračunati u $O(1)$ (preciznije, jedan red matrice $d$ računamo u $O(m)$) pa dobijamo algoritam složenosti $O(nm)$.





