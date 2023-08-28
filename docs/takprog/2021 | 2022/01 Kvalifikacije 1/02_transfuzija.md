# 2 - Transfuzija krvi

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Andrej Ivašković | Dimitrije Erdeljan | Dimitrije Erdeljan | Andrej Ivašković |

Za početak, pacijenti O grupe su jednostavni: mogu da prime samo krv O
grupe, tako da kod njih nemamo nikakvih odluka. U prvom prolazu kroz
pacijente, možemo njima dodeliti odgovarajuće količine O krvi, i
zatim u sledećem prolazu razmatrati samo pacijente A, B i AB grupe.

U sledećem prolazu možemo dodeliti krv pacijentima A grupe. Kod njih
imamo izbor između A i O, ali je odluka jednostavna: sada kada nema
više pacijenata O grupe, krv A grupe je strogo "manje korisna" od O,
jer svi koji mogu da je prime mogu da prime i krv O grupe. Dakle, ako
možemo, bolje je da dodeljujemo krv A grupe i čuvamo O, koju ćemo
koristiti samo ako više uopšte nema krvi A grupe.

Dalje, dodeljivanje krvi pacijentima B grupe možemo uraditi na isti način
kao za A. Na kraju, ostaju samo pacijenti AB-grupe, tako da više nije
bitno koju krvnu grupu koristimo i možemo im dodeliti proizvoljnu koje
je preostalo u zalihama.

Ako je u bilo kom trenutku u zalihama nedovoljno krvi za nekog
pacijenta, prekidamo program i ispisujemo "`nemoguce`". U suprotnom,
potrebno je da za svakog pacijenta sačuvamo dodeljene jedinice krvi
(npr. u nizu) i ispišemo ih na kraju.
