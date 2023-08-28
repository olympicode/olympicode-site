# 3 - Prepisivači

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Pavle Martinović | Aleksa Milojević | Momčilo Tošić | Vladimir Milenković |

Primetimo prvo da je udaljenost tačaka sa koordinatama $(x_A, y_A)$ i $(x_B, y_B)$ jednaka $\sqrt{(x_A-x_B)^2 + (y_B-y_A)^2}$, a provera da li su paralelne prave određena ovim dvema, i tačkama $(x_C, y_C)$ $(x_D, y_D)$ je provera jednakosti koeficijenta pravca ovih prava $\frac{y_A-y_B}{x_A-x_B}=\frac{y_C-y_D}{x_C-x_D}$, što kako bismo izbegli deljenje nulom možemo zapisati ovako: $(y_A-y_B)(x_C-x_D) = (x_A-x_B)(y_C-y_D)$.

## Rešenje kada $N \leq 4$
Ukoliko je $N$ manje od 4, jasno je da nema rešenja. Ukoliko je $N$ tačno 4, možemo pokušati da obeležimo unete tačke sa $A,B,C,D$ u svakom redosledu i da proverimo da li važi relacija data u zadatku (da su prave $AB$ i $CD$ paralelne i da je udaljenost između $A$ i $B$ dva puta manja od udaljenosti između $C$ i $D$ ili obratno).

## Rešenje kada $N \leq 100$
Možemo fiksirati bilo koje 4 tačke i proveriti da li važi relacija (prvu fiksiranu označimo sa $A$, drugu sa $B$ itd).

## Rešenje kada $N \leq 400$
Možemo primetiti da ako fiksiramo $A$, $B$, i $C$, tačka $D$ se nalazi na jedinstvenoj pravoj kroz C, i to na jedinstvenoj udaljenosti (dva puta manjoj od $\overline{CD}$), te treba posmatrati samo 2 mogućnosti za tačku $D$: tačka na toj pravoj na udaljenosti $\overline{AB}/2$ "levo" i "desno" od C. Ako dodamo te tačke u početni niz i sortiramo, svako dodatno pojavljivanje neke tačke $m$ puta znači da ta tačka može biti na kraćoj osnovici za $m$ trojki, te je rešenje zbir svih $m$ vrednosti za sve tačke, podeljeno sa 2 (jer smo uračunali obe tačke kraće osnovice).

## Glavno rešenje
Ako posmatramo primer sumnjivog četvorougla, može nam pasti na pamet da produžimo duž AC i BD, i dupliramo ih (inspiracija iz $AB=2\overline{CD})$, i tada ćemo zbog Talesove teoreme dobiti da je uslovu zadatka ekvivalentan uslov da se te dve duži seku u istoj tački (pokušajte da dokažete, zdravo je i zabavno). Ova tačka je slika tačke A u odnosu na C i tačke B u odnosu na D. Kako je $N<1500$, prirodno je razmišljati u smeru rešenja s kvadratnom složenošću, te i posmatranja svaka dva para tačaka. Ukoliko za svake dve tačke $X,Y$ pamtimo sve tačke koje se dobijaju kao slika X u odnosu na Y, vidimo da tačka koja se pojavljuje $k$ puta određuje $\binom{k}{2}$=$\frac{k*(k+1)}{2}$ sumnjivih četvorouglova, te za svaku upamćenu tačku treba sabrati ovu vrednost. Ovo je moguće implementirati sortiranjem slika tačaka predstavljenih kao par brojeva (koordinata) i brojanjem pojavljivanja svake.
