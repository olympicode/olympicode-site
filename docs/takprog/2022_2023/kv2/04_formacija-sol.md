Za tri tačke $A, B$ i $C$ kažemo da trojka $(A, B, C)$ ima levi zaokret ukoliko ako se krećemo od $A$ do $C$ preko tačke $B$ moramo skrenuti u levo. Slično definišemo desni zaokret. Tačke $A, B$ i $C$ su kolinearne ukoliko postoji prava koja sadrži sve tri. Sve ovo možemo proveriti koristeći vektorski proizvod vektora $\overrightarrow{AB}$ i $\overrightarrow{BC}$.

## Rešenje kada $N = 3$
Za svaki podskup potrebno je proveriti posebno. Imamo tri podskupa sa dva igrača, gde je potrebno proveriti da li se Mesi nalazi na duži između ta dva igrača. To možemo tako što proverimo da li je kolinearan sa ta dva igrača, kao i da su mu $x$ i $y$ koordinate između njihovih.

Takođe je potrebno proveriti za podskup od sva tri fudbalera. Ako je Mesi u tački $M$, a tri date tačke $A, B$ i $C$, onda je potrebno da trojke $(A, B, M)$, $(B, C, M)$ i $(C, A, M)$ imaju isti zaokret, kako bi se $M$ nalazio u konveksnom omotaču tačaka $A, B$ i $C$.

Vremenska i memorijska složenost je $O(1)$.

## Rešenje kada $y_1 = 1$ i $y_k = -1$, za $1 < k \leq N$
Jasno je da ćemo igrača sa dresom broj $1$ morati da uključimo u podskup kako bi konveksni omotač sadržao tačku $(0, 0)$. 

Posmatrajmo tačku $(-x_1, -1)$. Postoji dva slučaja:

- Ukoliko postoji igrač koji se nalazi u toj tački, tada, ako ga uključimo u podskup, možemo uzeti bilo koji podskup ostalih igrača, kojih ima $2^{N-2}$. Sem toga, moramo dodati broj podskupova u kojima se ne nalazi taj igrač;
- Ukoliko ne postoji igrač u toj tački, nećemo dodati $2^{N-2}$ na rešenje.

Recimo da posmatramo broj podskupova koji ne sadrže igrača u tački $(-x_1, -1)$ (ako takav uopšte postoji). Jasno je da onda moramo uzeti makar jednog igrača levo (odnosno sa manjom $x$ koordinatom) od te tačke i makar jednog igrača desno (odnosno sa većom $x$ koordinatom). Ako sa $L$ označimo broj igrača levo, a sa $R$ broj igrača desno, onda je rešenje $(2^L-1)\cdot (2^R - 1)$ (na šta dodajemo $2^{N-2}$ ukoliko postoji igrač u tački $(-x_1, -1)$).

Vremenska složenost je $O(NlogN)$, a memorijska $O(N)$.

## Rešenje kada $y_k \in \{-1, 1\}$, za $1 \leq k \leq N$
Slično prethodnom rešenju, moramo da imamo makar po jednog igrača sa obe $y$ koordinate. Ako fiksiramo najlevlju i najdešnju tačku sa prave $y = 1$ iz podskupa koji biramo, onda ponovo nalazimo $L$ i $R$ i primenjujemo sličnu formulu kao u prethodnom rešenju. 

Ovo je presporo pa je potrebno da primetimo da $L$ zavisi samo od najlevlje odabrane tačke, a $R$ samo od najdešnje odabrane tačke. Ovo koristimo uz tehniku prefiksnih suma, da nađemo zbir svih podskupova za fiksiranu najlevlju tačku (a kroz sve moguće najdešnje). 

Vremenska složenost je $O(NlogN)$, a memorijska $O(N)$.


## Rešenje kada $N \leq 18$
Za svaki podskup tačaka, nađimo konveksni omotač nekim poznatim algoritmom (npr. monotoni lanac) i onda proverimo da li se tačka $(0, 0)$ nalazi u njemu. To možemo uraditi tako što idemo u krug kroz ivice omotača i proveravamo da li sve ivice imaju isti zaokret sa tačkom $(0, 0)$.

Vremenska složenost je $O(2^N \cdot N)$, a memorijska $O(N)$.

## Glavno rešenje
Umesto da računamo broj podskupova u čijem konveksnom omotaču se Mesi nalazi, od $2^N - 1$ oduzmimo broj podskupova u čijem konveksnom omotače se **ne nalazi** Mesi. To radimo zato što je lakše proveriti ovaj uslov - dovoljno je da postoji prava kroz $(0, 0)$, tako da su sve tačke podskupa sa iste strane ove prave.

Pretpostavićemo da nema kolinearnih tačaka (čak ni kad računamo Mesijevu poziciju). Rešanje kolinearnih tačaka svede se detalje implementacije. Krenuvši od pozitivne $x$ ose, sortirajmo tačke po polarnom uglu oko tačke $(0, 0)$, rastuće. Označimo sa $M$ tačku $(0, 0)$. 

Fiksirajmo svaku tačku $p_i$ i sa $cnt$ označimo broj drugih tačaka koje imaju levi zaokret sa vektorom od $p_i$ do $M$. Onda je broj podskupova u kojima je $p_i$ *najlevlja* tačka (tačka takva da nije zaokret $(M, x, p_i)$ nije nadesno, za svako $x$ u podskupu),  a da konveksni omotač ne sadrži tačku $M$ - $2^{cnt}$. Kada od $2^N - 1$ oduzmemo ovaj rezultat za svaku tačku $p_i$, dobijemo konačno rešenje. Broj $cnt$ možemo održavati tehnikom dva pokazivača.

Vremenska složenost je $O(NlogN)$, a memorijska $O(N)$.





