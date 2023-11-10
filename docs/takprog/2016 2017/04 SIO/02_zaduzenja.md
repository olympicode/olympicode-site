Označimo optimalnu stazu (ciklus u grafu) sa C a njenu ukupnu dužinu sa w©. Jasno je da će tada traženo vreme biti

a * w© + b * minimalno_rastojanje(neki član komisije, ciklus C)

pa ovaj izraz treba minimizovati po C. Izraz se može uprostiti ako za svaki čvor unapred izračunamo A(u) - rastojanje od čvora u do njemu najbližeg člana komisije pomnoženo brojem b (nazovimo ovo “težina čvora”). Za ovo nam je dovoljan Floyd-Warshall ili puštanje Dijkstre iz svakog člana komisije (složenost je O(n^3) ili O(kmlog(n))). Dakle, potrebno je pronaći ciklus C za koji važi da je a*w© + min{A(u) | u iz C} minimalno.

Problem možemo posmatrati i iz drugog ugla: za čvor u, označimo sa MinCyc(u) dužinu najkraćeg ciklusa kome je čvor u čvor minimalne težine (dakle, NE najkraći od SVIH ciklusa koji sadrže u). Tada je
minimum po ciklusima C (a*w© + min{A(u) | u iz C}) = min po čvorovima u (MinCyc(u) + A(u))
pa je za svaki čvor dovoljno izračunati vrednost MinCyc.

Najtrivijalniji način je: za svaki čvor u, izbaciti iz grafa sve čvorove težine ne veće od u (uključujući i sam čvor u), naći sva najkraća rastojanja d[x][y] između čvorova novog grafa i staviti MinCyc(u) = minimum (w(u,x) + w(u,y) + d[x][y]) gde su x i y susedi čvora u koji su ostali u novom grafu. Složenost ovog pristupa je O(n^4) ili O(n^2 * m * log(n)).

Ukoliko sortiramo čvorove opadajuće po vrednosti A(u), tada važi MinCyc(u) = najkraći od SVIH ciklusa na skupu čvorova {1, 2, …, u} koji sadrži čvor u. Sada možemo vrednosti MinCyc računati modifikovanim Floyd-Warshall algoritmom: ovaj algoritam ima osobinu da neposredno pre k-tog koraka (spoljašnja od 3 ugnježdene for petlje) ima izračunate vrednosti d[u][v] - najkraće rastojanje od u do v preko prvih k-1 čvorova. Prema tome, za trenutni čvor k važi MinCyc(k) = minimum (w(k,u) + w(k,v) + d[u][v]) po svim susedima u,v čvora k za koje je u < k, v < k i d[u][v] != INF. Ako ovaj minimum računamo na početku svake spoljašnje for petlje, složenost Floyd-Warshalla ostaje O(n^3) i imamo vrednosti svih MinCyc(u) što je dovoljno za rešenje zadatka.

Podzadaci uključuju slučajeve za čije je rešavanje dovoljan pristup složenosti O(n^4) poput gore pomenutog, slučajeve gde je a = 0 (tada je rešenje min A(u) među svim čvorovima u koji pripadaju bar jednom ciklusu) i slučajeve gde je b = 0 (klasično traženje najkraćeg ciklusa u grafu). Zadatak se može uraditi i puštanjem Dijkstre iz svih čvorova sa komisijama (istovremeno) i fiksiranjem čvora koji će biti “ulaz” u kružnu stazu a zatim za njega računati najkraći ciklus koji ga sadrži i sastavljen je od čvorova “ispod njega” u Dijkstra-stablu (ovo je suštinski ista ideja kao i u gore pomenutom rešenju jer je redosled obilaska Dijsktrom rastući po vrednostima A).