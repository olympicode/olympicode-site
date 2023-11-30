﻿У ери брзих и драматичних дешавања у васиони се десила експлозија огромних размера. Она је изазвала померање огромног броја метеора. Научници покушавају да измоделирају дешавања у васиони. Положаје метеора представљају њиховим координатама у равни. Иако је за очекивати да се метеори крећу у огромном броју различитих праваца, сваки од њих се креће у једном од четири правца: на горе, на доле, удесно или улево. Сви се крећу константном брзином од једног метра по секунди.

За објашњавање догађања, научници су закључили да им треба конвексни омотач за скуп тачака које одговарају позицијама метеора по истеку $10^{1000}$ секунди од експлозије. За то им треба ваша помоћ.

## Описи функција

Потребно је имплементирати функцију

$$KonveksniOmotac(N, x[…],y[…],d[…])$$

где је $N$ - број метеора, а $x$, $y$ и $d$ низови који описују метеоре: $i$-ти метеор се налази на позицији $(x_i, y_i)$ и, уколико је $d[i]=0$, он се креће на горе, уколико је $d[i]=1$, он се креће удесно, уколико је $d[i]=2$, он се креће на доле, а уколико је $d[i]=3$ он се креће улево. Сви низови су индексирани од 0. Ова функција мора да врати један цео број – број темена на конвексном омотачу скупа тачака које представљају позиције метеора у тој далекој будућности. Оне тачке из тог скупа, које нису темена конвексног омотача, већ се налазе на страницама полигона се не рачунају.

## Пример:

Нека $N=6$, $x=[1, 12, 7, 3, 5, 4]$, $y=[1, 2, 10, 4, 7, 8]$ и $d=[0, 2,1,2,3,0]$. Ови подаци означавају да имамо 6 метеора: први је на позицији 1,1 и иде на горе, други је на позицији (12,2) и иде на доле, трећи је на позицији (7,10) и иде удесно, четврти на позицији (3,4) иде на доле, пети на позицији (5,7) иде улево и шести на позицји (4,8) иде на горе. Оба метеора која иду на доле ће бити на конвексном омотачу. Метеор који креће са позиције (1,1) ће бити унутар омотача. Метеори који иду удесно и улево (по један) ће бити на конвексном омотачу. Тако је одговор 5.

## Ограничења

-   $4≤N≤100.000$
    
-   За свако $i=[0,N-1]$ важи $-10^9≤x_i, y_i \leq 10^9$ и $d[i] \in \{0, 1, 2, 3\}$
    
-   Све координате су цели бројеви
    

## Подзадаци и бодовање

-   ПОДЗАДАТАК 1 [9 ПОЕНА]: $N≤1.000$.
    
-   ПОДЗАДАТАК 2 [24 ПОЕНА]: Сви метеори се крећу на горе или на доле (али бар по један у сваком од та два смера) тј. $d[i]=0$ или $d[i]=2$ за свако [i].
    
-   ПОДЗАДАТАК 3 [18 ПОЕНА]: Координате метеора су бројеви између -5000 и 5000.
    
-   ПОДЗАДАТАК 4 [49 ПОЕНА]: Нема додатних ограничења.
    

## Детаљи имплементације

Потребно је да пошаљете тачно један фајл, под називом meteori.c, meteori.cpp или meteori.pas, који имплементира горе поменуту функцију. Осим тражене функције, ваш фајл може садржати и додатне глобалне променљиве, помоћне функције и додатне библиотеке.

Зависно од програмског језика који користите, ваша функција/процедура мора бити следећег облика:

C/C++

int KonveksniOmotac(int N, int* x, int* y, int* d);

Pascal

function KonveksniOmotac(N : longint; var x, y, s : array of longint) : longint;

  

Уколико радите у C/C++ -у, потребно је на почетку фајла ставити #include “meteori.h” а уколико радите у Pascal -у, потребно је на почетку фајла ставити Unit meteori; (ово је већ додато у фајловима који су вам обезбеђени).

## Тестирање и експериментисање

Уз задатак, обезбеђени су вам “template” фајлови (meteori.c, meteori.cpp, meteori.pas) које можете користити и мењати по потреби. Такође су вам обезбеђени програми (grader.c, grader.cpp, grader.pas) који служе да лакше тестирате кодове. Ови програми учитавају са стандардног улаза следеће податке:

-   У првом реду број $N$
    
-   У следећих $N$ редова бројеве $x_i$, $y_i$, $d[i]$, редом, раздвојене размаком
    

а затим позивају вашу функцију KonveksniOmotac из одговарајућег фајла (meteori.c, meteori.cpp, meteori.pas) са учитаним параметрима и на крају вредност коју ваша функција враћа исписују на стандардни излаз. Kодове ових програма можете мењати по потреби.