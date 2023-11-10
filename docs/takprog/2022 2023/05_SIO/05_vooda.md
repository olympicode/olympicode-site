# 5 - Majnkraft vOOda

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Igor Pavlović i Pavle Martinović | Igor Pavlović i Pavle Martinović | Igor Pavlović i Pavle Martinović |

## Koreni u korovima

Čak iako je inspiracija za zadatak zaista došla iz načina kako se propagiraju tzv. *source block*-ovi u igrici Majnkraft, pojedini učenici mogli su prepoznati vezu između ovog zadatka i takmičarskog zadatka iz folklora: Data je tabla $10\times10$ i $9$ polja su obrasla korovom. Ako je polje susedno dva polja obrasla korovom onda i ono postane obraslo korovom. Da li je moguće da cela tabla bude obrasla korovom? U ovom zadatku je odgovor NE, a razlog zašto je odgovor NE može nam poslužiti kao dobra vodilja za rešavanje ovakvog zadatka.

Naime obim figure na kom je obrasla korov nikad ne raste, može samo da se smanji. Ako se pojavi polje koje je susedno $3$ ili čak $4$ korova, onda nam se obim smanjuje. Kako je na početku obim najviše $36$, a na kraju treba biti $40$, odgovor na pitanje u zadatku je negativan.

Glavna heuristika koju možemo odmah poneti odavde je da nikad (ili barem da se trudimo da izbegnemo) ne poplavimo polje  koje je susedno već nekom poplavljenom polju.

## Analiza primera
Prvi primer je mali i može se uraditi manje više ručno. Ocena obima iz prvog dela nam daje da je $27$ optimalan odgovor.

Drugi primer je veći ali mu je svaka pozevazana komponenta pravougaonik. Za pravougaonike se problem može rešiti tačno, i da se dokaže tačnost ocenom gore.

Treći primer je mali, ali je verovatno teško rešiti ručno osim ako se uloži jako puno vremena, već je realnije da ga takmičar programom napravi nekako i onda ručno doradi ako treba. I ovde je nađena ocena optimalna.

Četvrti primer je kao komplikovana verzija drugog gde imamo pravougaonike, ali oni mogu i da se seku. Komisijsko rešenje ovde nalazi odgovor $16316$, dok nam obim daje granicu od $16315$, tako da smo ovaj primer rešili ili optimalno ili skoro optimalno.

Primeri $5-8$ su malo divljiji, i ocena koja je data u prvoj sekciji nije toliko blizu konstrukcija koja je našla komisija. Primeri $5$ i $7$ su crtani rukom, dok su $6$ i $8$ random šum, sa različitim gustinama. Primer $8$ je ogroman, tako da bilo šta malo sporije može jako dugo da se izvršava. Sa njim moramo biti posebno pažljivi

## Autorsko rešenje 1 (86 poena, rešava 4. primer)

Svaki put kad postavimo novu vodu lako možemo da simuliramo kako se voda dalje kreće pomoću nekog algoritma nalik flood-fill algoritma. Prvo postavimo vodu u polja koja imaju maks jednog prohodnog suseda. Dalje svakom polje dodelimo neku težinu sa kojom ga treba izabrati. Ako je već susedan nekom poplavljenom polju, štetićemo obimu, tako da mu na težinu dodajemo $-10000$. Za svako susedno polje koje će postati poplavljeno ako dodamo vode na to polje dodamo $1000$. Bolje je stavljati u ćoškove nego na otvoreno empirijki, pa dodamo na težinu $100\cdot(4-\deg)$. Najzad (i ovo se ispostavlja kao ključno za nalaženja rešenja u priemru $4$) dodamo malu random težinu, do $10$ na primer. U svakom trenutku biramo polje sa najvećom težinu i njega poplavimo i ispropagiramo sve. Za svako plavljenje moramo da ažuriramo težine $12$ polja koji su na distanci najviše $2$ od poplavljenog polja, pa ceo algoritam radi jako brzo. Na primer, osmi primer rešava u roku od jednog minuta.

## Autorsko rešenje 2 (98 poena, rešava sve osim 4-og primera)

Anlogno prethodnom rešenju možemo prvo postaviti vodu u ona polja koja imaju tačno jednog slobodnog suseda a zatim simulirati dodavanje novih blokova primenom nekog algoritma za obilazak grafa. Ključna razlika ovog rešenja u odnosu na prethodno je što za naredno poplavljeno polje biramo ono polje koje će poplaviti najveći broj polja ukoliko na njega postavimo blok sa vodom. Za pronalaženje takvog polja neophodno je simulirati poplavu za svakog kandidata koji može poplaviti više od jednog polja, to jest ima bar jednog suseda koji je susedan sa tačno jednim poplavljenim poljem. Primetimo da je složenost jedne iteracije ograničena odozgo sa brojem kandidata u toj iteraciji puta broj poplavljenih polja nakon te iteracije. Na osnovu toga možemo zaključiti da složenost ovog rešenja nije veća od $O(N^2M^2)$. Međutim u priloženim primerima je broj kandidata u svakoj iteraciji značajno manji od $NM$ pa je i složenost ovog rešenja značajno manja i može se primeniti na primerima od 1 do 7. Za rešenje primera 8 u vremenskom periodu prikladnom za dužinu trajanja takmičenja neophodno je izdeliti celu tablu na manje table dimenzija 300x300 i rešiti ih zasebno a zatim spojiti u jedno rešenje. Da bismo osvojili poslednjih par poena na ovom zadatku potrebno je primetiti da rešenje zavisi od polja koje izaberemo između onih polja sa jednakim rezultatom simulacije. Kako bismo dodatno poboljšali skor moguće je primeniti isti algoritam na razlicite izometrijske transformacije ulaza i izabrati najbolje rešenje.