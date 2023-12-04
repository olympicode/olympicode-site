---
hide:
  - toc
---

# 4 - ZiPV

=== "Zadatak"
	
	| Vremensko ograničenje | Memorijsko ograničenje |
	|:-:|:-:|
	| 1000ms | 512MB |
	
	
	Još u 1984. godini (kada Internet kakvim ga danas znamo nije ni postojao), Gramp (F.T. Grampp) i Moris (R.H. Morris) su dali čuveni citat: “Lako je imati bezbedan računarski sistem. Samo treba preseći sve veze sa drugim računarima, dozvoliti samo direktne žičane terminale između računara, staviti mašine u zabravljenu sobu, i postaviti čuvara ispred vrata.''
	
	Vođeni tim citatom, čelnici Ujedinjenih Komisijskih Država su do 2061. godine učinili da sve veze koje povezuju spoljni svet sa njihovim mašinama ne mogu da šalju više od trideset 64-bitnih celih brojeva odjednom, uz oglašavanje opšte uzbune ukoliko se pošalje više takvih paketa. Međutim, i pored toga su čuveni hakeri Perica i Davis uspeli da koordiniranim napadom zaposednu dve državne mašine.
	
	Perica je uspeo da, na mašini koju je zaposeo, dobije pristup nekim slikama (veličine 100 x 100, samo u nijansama sive - vrednost svakog piksela je ceo broj između 0 i 255) koje bi mogle da kriju skrivene šifre za lansiranje nuklearnih raketa u sebi. Želeo bi da pošalje slike Davisu, međutim zbog ograničenja prenosnih kanala, može poslati samo trideset 64-bitnih celih brojeva-tako da su mogući gubici pri slanju. Zamolio vas je za pomoć.
	
	## Opisi funkcija
	
	Potrebno je da implementirate dve funkcije:
	
	Encode(In[...][...], Code[...]),
	
	koja pretvara ulaznu sliku (predstavljenu kao 100 x 100 matricu 8-bitnih celih brojeva) u niz od trideset 64-bitnih celih brojeva;
	
	Decode(Code[...], Out[...][...]),
	
	koja na osnovu izračunatog niza treba da, što preciznije, rekonstruiše originalnu sliku.
	
	Jedini način na koji ove dve funkcije mogu razmeniti informacije je niz  Code!
	
	Pri popunjavanju, niz  Code  i matricu  Out  indeksirajte od 0!
	
	## Ograničenja
	
	-   Sve slike će biti predstavljene kao 100 x 100 matrice 8-bitnih vrednosti ([0, 255]);
	    
	-   Dužina koda je ograničena na trideset 64-bitnih celih brojeva.
	    
	
	## Podzadaci i bodovanje
	
	Test primeri su podeljeni u 4 podzadatka od po 25 poena, koji predstavljaju različite vrste slika. Za svaku sliku, ukupna greška se računa kao suma kvadratnih odstupanja ulazne od izlazne slike na svakoj poziciji:
	
	$$err=\sum\limits_{i=0}^{99}\sum\limits_{j=0}^{99}(In[i][j]-Out[i][j])^2$$
	
	Za svaku sliku definisane su konstante $A$ i $B$ tako da:
	
	-   Ukoliko važi $err≤A$, osvajate 25 poena za tu sliku;
	    
	-   Ukoliko važi $err≥B$, osvajate 0 poena za tu sliku;
	    
	-   Inače, osvajate $25×(\frac{B - err}{B-A})$ poena za tu sliku.
	    
	
	Broj osvojenih poena na jednom podzadatku je minimalan broj poena osvojenih na svim slikama unutar tog podzadatka.
	
	## Trening podaci
	
	Unutar svakog podzadatka, generisano je osam slika na sličan način. Od tog broja, tri slike su nasumično odabrane i direktno su vam dostupne u arhivi priloženoj uz zadatak. Preostalih pet slika će biti korišćene za testiranje unutar svakog podzadatka. Slike su date u dva formata: u Bitmap formatu (sa ekstenzijom .bmp), kao i tekstualni fajl (sa ekstenzijom .in) koji u sebi sadrži odgovarajuću 100 x 100 matricu vrednosti piksela. Na slici ispod se nalazi, za svaki podzadatak, po jedan primer od tri koja su vam data u arhivi.
	
	## ![](https://lh7-us.googleusercontent.com/ifkmFfDzE5-9MGQ6YvHfNXgDcU5DTYTiwDgBs47P5SyCur9mcYklJgY3xjukqgoAITwVzkIqqksFDCh6ihe9m8XGOr1eSW3RvPZv06eRnXuItcuhuXslsxdH9XKe0Wapgu4YCAodlQk6vgWXI3EjRg)
	
	## ![](https://lh7-us.googleusercontent.com/wjG_gpBtYUvAacIArNjZgrt8Z45UxgKx5L6-npgxwf60bYv5Y5JIADgpBrmZLTYi6-5oGNLpNYlmswuQ9XK-9wpdaqxhGNDbMamsMSBlFawS7ShrSwpeMdde591vUnhUGzC25J4R6kaeYuox6zbUkg)
	
	## ![](https://lh7-us.googleusercontent.com/wZHGQay0u6WcALSKEP8SQM0Gvf2zCzNFgUwlSeGbwBLS2p1hEe3bX98q-mx7r5P1IAlCEnqy5cIaRQiT1li7nzHSwTtE6hFHS-n97UkuuOVb-Z_vSf4doNVm230VoBnpuJkb2_uzcs11i-Wco-3G9A)
	
	## ![](https://lh7-us.googleusercontent.com/oteD5sleSfWal-rXy1eLOJhcGj6_dHFreHtMLix5JFLbW7s-O_mHMz4lhD2YlIwr-6eqowgaMWsteq9bn5mSxlM7lFM5YP0pP1g1IjgdUH3AEzdDEHLoCgo9iEUHTGSBrwhvuRlv0W8x3kz1p2-1Wg)
	
	## Detalji implementacije
	
	Potrebno je da pošaljete tačno dva fajla, pod nazivima [zipv_encode.c; zipv_decode.c], [zipv_encode.cpp; zipv_decode.cpp] ili [zipv_encode.pas; zipv_decode.pas], koji implementiraju dve gorepomenute funkcije. Osim traženih funkcija, vaši fajlovi mogu sadržati i dodatne globalne promenljive, pomoćne funkcije i dodatne biblioteke. Međutim, imajte na umu da će funkcije Encode i Decode da se pozivaju u odvojenim programima, tako da nećete moći da sačuvate ikakvu globalnu promenljivu koja nije konstantna između poziva ove dve funkcije!
	
	Zavisno od programskog jezika koji koristite, vaše funkcije/procedure moraju biti sledećeg oblika:
	
	C/C++
	
	void Encode(unsigned char **data_in, long long *code);
	
	void Decode(long long *code, unsigned char **data_out)
	
	Pascal
	
	type matrix = array[0..99] of array[0..99] of byte;
	
	procedure Encode(var data_in : matrix; var code : array of int64)
	
	procedure Decode(var code : array of int64; var data_out : matrix)
	
	Ukoliko radite u C/C++ -u, potrebno je na početku fajlova staviti #include "zipv_encode.h", odnosno #include "zipv_decode.h", a ukoliko radite u Pascal -u, potrebno je na početku fajla staviti Unit zipv_encode;, odnosno Unit zipv_decode;  (ovo je već dodato u fajlovima koji su vam obezbeđeni).
	
	## Testiranje i eksperimentisanje
	
	Uz zadatak, obezbeđeni su vam “template'' fajlovi (zipv_encode.c, zipv_decode.c, zipv_encode.cpp, zipv_decode.cpp, zipv_encode.pas, zipv_decode.pas) koje možete koristiti i menjati po potrebi. Takođe su vam obezbeđeni programi (manager.c, manager.cpp, manager.pas) koji služe da lakše testirate kodove. Ovi programi učitavaju sa standardnog ulaza matricu od 100 x 100 8-bitnih celih brojeva (između 0 i 255). Zatim pozivaju funkciju Encode nad tom matricom, a nakon toga pozivaju funkciju Decode nad dobijenim nizom, i konačno ispisuju na standardni izlaz dobijenu matricu.
	
=== "Rešenje"
	
	| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
	|:-:|:-:|:-:|:-:|
	| Petar Veličković | Petar Veličković | - | Andrej Ivašković i Dimitrije Erdeljan |
	
	
	
	``` cpp title="04_zipv.cpp" linenums="1"

	```
