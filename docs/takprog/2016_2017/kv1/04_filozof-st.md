﻿Мали Стојан од свих предмета највише воли филозофију (заправо, пре би
се могло рећи да воли расправљање и филозофирање). Након што је
изгубио пола часа на расправу са Стојаном, професор филозофије му је
поставио следећи задатак, у нади да ће га то окупирати бар на неко
време:

Стари грчки филозоф Миле из Талеса је у својој башти гајио
правоугаонике - сваког дана би посадио један. Правоугаоници су
необичне биљке и трају само \$K\$ дана, тако да би Миле сваког дана
такође уклонио правоугаоник који је посадио пре \$K\$ дана. Пошто се
Миле придржавао старогрчких начела баштованства, све правоугаонике је
садио тако да су им странице паралелне координатним осама.

Да би их заштитио од сунца, Миле је у башти имао један правоугаони
заклон, који је сваког дана померао тако да у потпуности прекрива све
правоугаонике. Због већ поменутих начела, овај заклон је такође увек
морао бити паралелан осама и окренут на исту страну (није се смео
ротирати).

Из Милетових бележака, познате су позиције и димензије свих
правоугаоника које је посадио током \$N\$ дана, колико се укупно бавио
баштованством. На Стојану је сада да пронађе димензије најмањег
заклона који би увек могао да их заштити од сунца. Помозите му да
одреди ово, да би се што пре вратио расправљању и филозофирању.

## Опис улаза
Пошто су тест примери потенцијално веома велики, да би се избегло
учитавање целих примера, ваш програм треба да генерише примере на
следећи начин:

На првом и једином реду стандардног улаза налази се шест бројева:
\$N\$, \$K\$, \$M\$, \$А\$, \$B\$ и \$S\$. Низови \$X\$, \$Y\$, \$XX\$
и \$YY\$, где \$(X_i, Y_i)\$ и \$(XX_i, YY_i)\$ представљају
координате доњег левог, односно горњег десног правоугаоника који је
Миле засадио i-тог дана, се генеришу на следећи начин (у псеудокоду
доле, низови су индексирани од 1):

    for i from 1 to N:
        if i == 1
            X[i] = (A * S + B) mod M
        else
            X[i] = (A * YY[i-1] + B) mod M
        Y[i] = (A * X[i] + B) mod M
        XX[i] = (A * Y[i] + B) mod M
        YY[i] = (A * XX[i] + B) mod M

        if X[i] == XX[i]
            XX[i] = XX[i] + 1
        if X[i] > XX[i]:
            swap(X[i], XX[i])

        if Y[i] == YY[i]
            YY[i] = YY[i] + 1
        if Y[i] > YY[i]
            swap(Y[i], YY[i])

На пример, за улаз

    2 3 100000007 19997 31 73

генерисане вредности су (сваки ред одговара вредностима \$X_i\$,
\$Y_i\$, \$XX_i\$, \$YY_i\$ редом):

    1459812 29119072 95455781 91858558
    94042061 29119072 95455781 58962213

## Опис излаза
У првом и једином реду стандардног излаза исписати два цела броја -
тражену минималну ширину и висину заклона.

## Примери
<div class="col-md-12">
    <div class="panel panel-default">
        <div class="panel-heading">
            <span class="pull-left" style="width: 48%;">Ulaz</span>
            <span style="padding-left: 15px;">Izlaz</span>
        </div>
        <div class="panel-body">
            <span class="pull-left exampleinput">
                4 2 13 2 5 2
            </span>
            <span class="exampleoutput">
                7 9
            </span>
        </div>
    </div>
</div>

<div class="col-md-12">
    <div class="panel panel-default">
        <div class="panel-heading">
            <span class="pull-left" style="width: 48%;">Ulaz</span>
            <span style="padding-left: 15px;">Izlaz</span>
        </div>
        <div class="panel-body">
            <span class="pull-left exampleinput">
                7 3 37 5 0 3
            </span>
            <span class="exampleoutput">
                30 32
            </span>
        </div>
    </div>
</div>

## Објашњење примера
Први пример одговара следећим вредностима координата правоугаоника
(редом \$X_i\$, \$Y_i\$, \$XX_i\$, \$YY_i\$):

    9 3 12 10
    11 1 12 3
    7 1 11 6
    4 0 5 2

Првог дана, Миле може да заклони први правоугаоник тако што постави
заклон тако да му је доњи леви угао у \$(9,3)\$. Другог дана га
помера на \$(9,1)\$. Трећег дана, Миле уклања први правоугаоник,
тако да заклон тада може да стоји на пример у \$(7,-2)\$. Након што
уклони други и дода четврти правоугаоник, помера заклон у \$(4,0)\$.

## Ограничења
* \$1 \leq N, K\$
* \$1 \leq M \lt 10^9\$
* \$0 \leq A, B, S \leq 10^9\$

Ограничења за \$M\$, \$A\$, \$B\$ и \$S\$ гарантују да ће се све координате
налазити у интервалу \$[0, 10^9]\$. Међурезултати при генерисању улаза
могу бити изван овог интервала, тако да се препоручује коришћење
64-битних типова за њих (long long у C/C++, int64 у Паскалу).

Тест примери су подељени у три дисјунктне групе:
* У тест примерима који вреде 20 поена важи \$N, К \leq 1000\$
* У тест примерима који вреде 50 поена важи \$N, К \leq 10^5\$
* У тест примерима који вреде 30 поена важи \$N, K \leq 2 * 10^6\$