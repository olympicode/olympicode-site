## Rešenje kada $N=M, a_i \leq c_i \leq b_i \leq d_i$
U ovom podzadatku je dovoljno duž dijagonale posaditi $b_i$ krompira.

## Rešenje kada $a_i = b_i, c_i = d_i$
Za rešavanje ovog podzadatka možemo primeniti tehniku dva pokazivača. Pokazivač $i$ iterira po redovima, a pokazivač $j$ iterira po kolonama.
Ako je $b_i=0$ ili $d_i=0$ tada uvećamo $i$ to jest $j$ za 1. Ako je $b_i \neq 0$ i $d_j \neq 0$ posadi $min(b_i,d_j)$ krompira na polje $i, j$ i smanji $b_i$ i $d_j$ za $min(b_i,d_j)$.

## Rešenje kada $a_i = b_i$
Ovaj podzadatak možemo rešiti analogno prethodnom. U ovom podzadatku je potrebno iterirati po kolonama 2 puta. Prvi put postavljamo broj krompira u svakoj koloni na donju granicu, a drugi put na gornju i ažuriramo broj krompira u svakoj koloni. Kada završimo sa iteracijom po redovima tada prekidamo iteraciju po kolonama takođe. Nakon što smo odredili broj krompira u svakoj koloni možemo primeniti rešenje iz prethodnog podzadatka.

## Rešenje kada $N = 1$
U slučaju da važi $\sum_{i=1}^{M} d_i \leq b_1$ dovoljno je samo u $i$-toj koloni posaditi $d_i$ krompira.

U suprotnom se rešenje ovog podzadatka svodi na rešenje prethodnog kada donju granicu postavimo da bude jednaka gornjoj (jer je neophodno posaditi $b_i$ krompira u prvom redu kako bismo maksimizovali prinos).

## Rešenje kada $a_i = c_i = 0$
Ovaj podzadatak možemo rešiti gramzivom metodom i tehnikom 2 pokazivača. Pokazivač $i$ iterira po redovima, a pokazivač $j$ iterira po kolonama.
Ako je $b_i=0$ ili $d_i=0$ tada uvećamo $i$ to jest $j$ za 1. Ako je $b_i \neq 0$ i $d_j \neq 0$ posadi $min(b_i,d_j)$ krompira na polje $i, j$ i smanji $b_i$ i $d_j$ za $min(b_i,d_j)$. Primetimo da je ovo rešenje identično podzadatku 2 samo što je u ovom slučaju neophono završiti iteraciju po kolonama čim se završi iteracija po vrstama i obrnuto. U podzadatku 2 se ove dve iteracije zaršavaju istovremeno s obirom da rešenje mora postojati.

## Glavno rešenje
Primetimo prvo da nije moguće posaditi više od $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ krompira ukupno. Dakle ukoliko konstruišemo rešenje sa tačno $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ krompira onda smo takođe dostigli maksimalan mogući prinos.

Bez umanjenja opštosti pretpostavimo da važi $\sum_{i=1}^{N} b_i \leq \sum_{j=1}^{M} d_i$. Da bismo maksimizovali prinos potrebno je u svakom redu posaditi $b_i$ krompira. Pošto nam je poznat broj krompira koji je potrebno posaditi u svakom redu sada se rešenje zadatka svodi na rešenje podzadatka 3. Primetimo takođe da ukuliko postoji neko rešenje tada važi $\sum_{j=1}^{M} c_i \leq \sum_{i=1}^{N} b_i$, odakle sledi da moguće konstruisati rešenje sa tačno $min(\sum_{i=1}^{N} b_i,\sum_{j=1}^{M} d_i)$ primenom algoritma iz podzadatka 3.
