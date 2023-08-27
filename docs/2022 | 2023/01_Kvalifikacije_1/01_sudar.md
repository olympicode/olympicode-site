# 1 - Sudar brojeva

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Vladimir Milovanović | Vladimir Milovanović | Vladimir Milovanović | Igor Pavlović |

## Glavno rešenje

Zadatak je najlakše rešiti posmatrajući date prirodne brojeve $X$ i $Y$ kao niske. Naime, u jednoj petlji treba porediti znakove (karaktere) niski $X$ i $Y$, koji zapravo predstavljaju cifre brojeva na odgovarajućim indeksima. Krećući se unazad, počevši od cifara najmanje težine i idući ka cifrma najveće težine, ideja je dodavati veću od njih u neku novostvorenu nisku. Ukoliko se pak desi da su cifre odgovarajuće težine jednake, neophodno ih je obe dodati u pomenutu novoformiranu nisku, to jest tu jednu cifru dva puta. Nisku napravljenu u prethodnom postupku na kraju zadatka potrebno je ispisati. Slučajevi kada su zadati ulazni brojevi različitih dužina rešava se tako da kada se tokom prolaska kroz opisanu petlju broj cifara jednog od brojeva iscrpi, rezultujuću nisku samo treba dopuniti preostalim ciframa većeg broja koje nisu bile iskorišćene u poređenju.

Pod pretpostavkom da se zadat broj $X$ sastoji iz $M$ cifara, dok zadati broj $Y$ sadrži $N$ cifara, složenost opisanog algoritma je $\mathcal{O}(M+N)$, odnosno linearna po broju cifara.
