# 1 - Mađioničar

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Pavle Martinović | Vladimir Milovanović | Vladimir Milovanović |

## Glavno rešenje
Pošto je u zadatku poznata karta (odnosno njena vrednost $K$) koja se nalazi direktno iznad tražene karte, ako se špil karata posmatra kao niz pozitivnih celobrojnih vrednosti, to će drugim rečima značiti, da je postavkom zadatka data vrednost u nizu pod indeksom za jedan manjim u odnosu na indeks zahtevane vrednosti. Stoga je u prvom koraku potrebno pronaći indeks $i$ u nizu pod kojim je zapisana data vrednost $K$, a zatim u narednim koraku ispisati vrednost pod indeksom $i+1$. Kako bi se osvojili svi poeni, neophodno je obratiti pažnju na jedan specijalan slučaj, koji je objašnjen u drugom javnom primeru u postavci zadatka, a to je kada je $i=N$. U ovom slučaju indeks tražene karte nije $i+1$, odnosno $N+1$, iz razloga što on ne postoji, već je to prva karta u špilu, odnosno vrednost pod indeksom $i=1$, uz pretpostavku da indekse računamo počevši od jedinice, a ne od nule. Elegantan način da se pokrije ovaj izuzetak jeste uzeti $i+1$ i pronaći ostatak pri deljenju sa $N$, to jest indeks tražene vrednosti će biti $(i+1) \mod N$ i sve što treba uraditi u zadatku nakon učitavanja odgovarajućih podataka je ispis vrednosti pod pomenutim indeksom.

Kako se u najgorem slučaju vrednost niza $K$ može nalaziti pod indeksom $N$, neophodno je u gore opisanom prvom koraku proći kroz čitav niz da bi se to utvrdilo, pa je asimptotska vremenska složenost algoritma $\mathcal{O}(N)$, odnosno linearna po dužini niza.
