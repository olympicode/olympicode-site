Neka je L[i] = optimalna zarada za prvih i zgrada ukoliko postavljamo samo uređaje okrenute ulevo i poslednji postavljeni uređaj je na i-toj zgradi. Analgo se definiše R[i] za desne uređaje i nije teško zaključiti da je rešenje zadatka max {L[i] + R[i]} i da se ova dva niza računaju simetrično pa nadalje gledamo samo za L[i]. Neka su h[], v[] i c[] visine, zarade i cene rušenja, redom. Zadatak rešavamo dinamičkim programiranjem. Važi

(1) L[i] = v[i] + maximum { L[j] - suma {c[k] | j < k < i, h[k] > h[i]} | j < i, h[j] < h[i] }

(sa desne strane je maximum po svim zgradama j < i koje su niže od i; to je kandidat za pretposlednju zgradu, a moramo srušiti sve zgrade između j i i koje su više od h[i] dok će cena preostaih rušenja zgrada viših od h[i] a levo od j biti uračunata u L[j] jer je h[j] < h[i]). U cilju nalaženja boljeg rešenja od O(n^2), jedan od načina je da se dinamika radi po visinama a ne redom s leva udesno; to ujedno omogućava da ne moramo da proveravamo uslov h[j] < h[i] u (1). Za dato i treba nam indeks j < i za koji je vrednost

L[j] - suma {c[k] | j < k < i, h[k] > h[i]} (*)

maksimalna. Međutim, primetimo da (*) dostiže maksimum u indeksu j ako i smo ako izraz

L[j] - suma {c[k] | j < k, h[k] > h[i]} (**)

dostiže maksimum maksimum u indeksu j (ostatak sume ne zavisi od j). Ovim smo izbacili parametar i iz granica pa sada možemo prebaciti priču na segmentno stablo i računanje nekih upita.

Neka su na početku svi L[i] = -INF. Posmatrajmo niz A dužine n koji je u i-tom koraku dinamike (idemo od najmanje do najveće zgrade) definisan sa (uzimamo da je h[0] = 0)

(2) A[j] = L[j] - suma {c[k] | j < k, h[k] > h[i]}

(dakle, na početku za sve j važi A[j] = -INF - suma {c[k] | j < k}). Kako računamo vrednosti L[i] redom po visinama zgrada, treba odraditi n koraka i u i-tom koraku:

a) Odrediti L[i] kao L[i] = v[i] + max(A[1],A[2],…,A[i]) + suma { c[k] | i < k, h[k] > h[i]};
b) Update-ovati niz A, tj. povećati A[i] za (L[i] + INF) i za sve j < i povećati A[j] za c[i].

Formula iz a) je tačna jer zamenom A[i] iz (2) dobijamo (1) (do tada su izračunati svi A[j] za h[j] < h[i]). Deo “+ suma…” je tu da bismo nadoknadili razliku između (*) i (**). Kod dela b), menja se više еlemenata niza A na osnovu definicije (2). Obe ove operacije možemo raditi u složenosti O(log n) - dovoljno nam je segmetno stablo nad nizom A koje podržava “vrati maximum na segmentu” i “povećaj sve elemente iz datog segmenta za dati broj” a to je max-segmento sa lazy propagation-om.
Za upit U(i) = suma { c[k] | i < k, h[k] > h[i]} možemo koristiti (drugo) suma-segmentno stablo nad nizom c[] pri čemu u i-tom koraku vraćamo sumu na segmentu [i, n] a zatim izbacujemo element c[i] (tj. postavljamo c[i] = 0) jer dinamiku radimo po visinama i za svaki naredni upit j važi h[j] > h[i] pa vrednsot c[i] ne učestvuje u sumi. Ukupna složenost je O(n log n).

Podzadaci uključuju slučajeve kada prolazi dinamičko programiranje u složenosti O(n^2) tj. direktno dinamičko iz formule (1), slučajeve gde se ne isplati rušiti zgrade (tada je rešenje jedinstveno - postaviti levi urđaj na prvu zgradu, zatim na prvu narednu koja nije zaklonjena prvom, zatim na prvu narednu koja nije zaklonjena drugom izabranom itd. do najviše zgrade i sl. za desne uređaje) kao i slučajeve gde su cena zgrada 0 što značajno pojednostavljuje formulu (1) na L[i] = v[i] + maximum { L[j] | j < i, h[j] < h[i] } pa ovo možemo rešavati slično kao LIS konstrukcijom max-segmentnog nad nizom L[i] (koje je indeksirano visinama ako računamo vrednosti L[i] od 1 do n ili je indeksirano pozicijama ako računamo vrednosti L[i] po visinama).
