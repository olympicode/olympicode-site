# 3 - Nadvlačenje konopca

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović  | Aleksa Milisavljević | Pavle Martinović  | Pavle Martinović |

## Rešenje kada $N \leq 20$
Za svaki meč ima ukupno $2$ načina da se izabere pobednik tako da ima ukupno $2^N$  ukupno načina da se izaberu pobednici. Naprosto prođemo kroz sve te kombinacije (npr iteriranjem brojeva od $0$ do $2^N-1$ i gledajući njihov binarni zapis) i vidimo da li u svakoj od njih se desi da ima jednu pobedi. Složenost $O(2^N)$.

## Rešenje kada svaki takmičar učestvuje u 2 meča
Posmatrajmo graf čiji su čvorovi takmičari i postoji grana između dva takmičara ako igraju meč međusobno. Sada nam je zadatak ekvivalentan sa time da se orijentišu grane tako da svaki čvor ima izlazni stepen tačno $1$ (ovakvi grafovi se inače zovu *funkcionalni grafovi*).

U ovom podzadatku svaki čvor je stepena tačno $2$. Za takav graf znamo da je svaka povezana komponenta ciklus (dokažite!). U ciklusu očito imamo samo $2$ načina da orijentišemo grane (neformalno rečeno u smeru kazaljke na satu i suprotno). Tako da je u ovom slučaju odgovor $2^{\text{broj komponenti}}$. Složenost $O(N)$.

## Glavno rešenje

Zapravo je glavno rešenje mala modifikacija prethonog. Naime, očito nam je potreban uslov da u svakoj komponenti ima isto čvorova i grana (da bi mogao savko da pobedi barem jednom). Ispostavlja se da ako je ovaj uslov ispunjen, odgovor je opet $2^{\text{broj komponenti}}$ (a u suprotnom je $0$).
Dokaz ovoga možemo da vidimo na sledeći način: ako postoji čvor stepena $1$ znamo da on mora da pobedi taj meč tako da nam je to jedinstveno određeno i možemo da skinemo taj čvor i granu i opet dobijemo graf sa isto čvorova i grana, i to za $1$ manje. Nastavljamo ovaj proces, i kad nema nijedan čvor stepena $1$, tada svi imaju stepen $2$, što po prethodnom podzadatku znamo da imamo tačno $2$ načina da orijentišemo.
