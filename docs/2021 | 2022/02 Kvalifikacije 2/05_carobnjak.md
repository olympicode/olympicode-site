# 5 - Čarobnjak

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Aleksa Milisavljević | Aleksa Milisavljević | Aleksa Milisavljević | Pavle Martinović |

## Rešenje za $N \leq 10$

U ovom slučaju možemo za svaki odabir $K$ od $N$ elemenata isprobati sve moguće načine da izvršimo operacije. Vremenska složenost je $O({N \choose K} \cdot 2^K)$.

## Rešenje za $N \leq 200$

U ovom podzadatku do rešenja možemo doći primenom dinamičkog programiranja. Definišimo $dp[l][r][p][g][h]$ na sledeći način:

 - Za $g=0, h=0$ najveća vrednost tako da u nizu napitaka ostane napitak sa tom moći, pa onda napici iz intervala $[l,r]$ i da smo izvan intervala odabrali da zadržimo $p$ elemenata.
 - Za $g=0, h=1$ najmanja vrednost tako da u nizu napitaka ostane napitak sa tom moći, pa onda napici iz intervala $[l,r]$ i da smo izvan intervala odabrali da zadržimo $p$ elemenata.
 -  Za $g=1, h=0$ najveća vrednost tako da u nizu napitaka ostane napitak sa tom moći, pre njega napici iz intervala $[l,r]$ i da smo izvan intervala odabrali da zadržimo $p$ elemenata.
  - Za $g=1, h=1$ najmanja vrednost tako da u nizu napitaka ostane napitak sa tom moći, pre njega napici iz intervala $[l,r]$ i da smo izvan intervala odabrali da zadržimo $p$ elemenata.

Kako se operacijama isključivo oduzima vrednost jednog kraja od vrednosti drugog, to se pronalaženje maksimalne ili minimalne vrednosti na jednom kraju upravo svodi na pronalaženje minimalne odnosno maksimalne vrednosti na suprotnom i primenu jedne operacije. Ovo dinamičko programiranje je vremenske složenosti $O(N^3)$.

## Rešenje za $K = N$

Za rešavanje ovog podzadatka, neophodno je primetiti da su sve vrednosti moći napitka koji ostaje poslednji u nizu ili razlika nepraznog prefiksa i odgovarajućeg nepraznog sufiksa ili razlika nepraznog sufiksa i odgovarajućeg nepraznog prefiksa. Za početak, primetimo da moć napitka koji ostaje poslednji u nizu uvek možemo preslikati na niz $b$ koji sadrži $N$ vrednosti koje su isključivo $+$ ili $-$. Konkretno, ako moć nekog napitka iz početnog niza učestvuje sa znakom $+$ u moći napitka koji ostaje poslednji, na tu poziciju u nizu $b$ stavljamo $+$, a u suprotnom $-$. Posmatrajmo sada niz $b$. Želimo da ga svedemo na niz koji ima samo jedan element i taj element ima vrednost $+$, primenom operacija definisanih u tekstu. Primetimo da ukoliko prva i poslednja vrednost u nizu $b$ imaju isti znak, tada sigurno nije moguće izvršiti ni jednu operaciju, jer tada želimo da i prvi i poslednji element učestvuju sa istim znakom, a znamo da primenom bilo koje od dve operacije dovodimo do toga da u konačnoj sumi učestvuju sa različitim znakom. U suprotnom, možemo da izvršimo bilo koju od ove dve operacije. Na nizu $b$ ovo se održava brisanjem jednog od dva kraja. Dakle, ukoliko posle primene nekih operacija dođemo do niza koji ima više od jednog elementa i njegovi krajevi su različitog znaka, onda nas taj niz nikako ne može dovesti do niza koji sadrži samo jedan element $+$. Zbog toga nije moguće da u nizu $b$ postoji više od jednog para susednih pozicija koje imaju suprotan znak. Dakle, dovoljno je da uzmemo maksimum razlika svih nepraznih prefiksa i odgovarajućih nepraznih sufiksa, odnosno nepraznih sufiksa i odgovarajućih nepraznih prefiksa. Ovo je moguće uraditi u  vremenskoj složenosti $O(N)$.

## Rešenje kad $N \leq 1000$

Rešavanje ovog podzadatka se nadovezuje na rešavanje prethodnog. Fiksiraćemo svaku poziciju koja će predstavljati razliku između prefiksa i sufiksa (odnosno sufiksa i prefiksa) i potom izbaciti $N-K$ elemenata tako da se ta razlika maksimizuje i da ni prefiks ni sufiks ne ostanu prazni. Ovo je moguće postići sortiranjem celog niza sa promenjenim znakom elemenata u sufiksu, te izbacivanjem najmanjih $N-K$ elemenata. Neophodno je samo voditi računa da izbacivanje tih elemenata ne dovede do praznog prefiksa ili sufiksa. Ovakvo rešenje je vremenske složenosti $O(N^2 \log N)$.

## Glavno rešenje

Za rešenje celog zadatka, neophodno je optimizovati rešenje prethodnog podzadatka tako da ne moramo da za svaku poziciju sortiramo niz i ponovo biramo najmanje elemente. Glavna ideja u toj optimizaciji se zasniva na tome da se promenom pozicije koja razdvaja prefiks i sufiks za jedan menjaju tačno dve vrednosti iz niza koji sortiramo i iz kojeg biramo najmanjih $N-K$. Možemo koristiti strukturu `set` ili segmentno stablo da bi održavali taj niz. Rešenje kompletnog zadatka je vremenske složenosti $O(N \log N)$.
