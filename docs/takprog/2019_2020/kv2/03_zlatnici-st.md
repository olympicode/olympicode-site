﻿
Краљ Мида је познат по свом дару да све што дотакне постане златно. Међутим, прекасно је схватио да неопрезним коришћењем свог дара може себи озбиљно да нашкоди. Наиме, он је целу своју колекцију новчића од бакра, сребра и гвожђа, претворио у бескорисне златнике! Изгубивши то што му је некада било најдраже, одлучио је да све своје време проводи на најбезбеднији могући начин, играјући следећу игру.

Пред собом има таблу са $N$ колона и $N$ врста, и на тој табли стоје $N$ од његових многобројних златника. Сваки златник заузима тачно једно поље табле, и није могуће да два златника буду на истом пољу. Мида у једној секудни може да узме један златник и премести га на неко поље које дели страницу са пољем на коме се тај златник тренутно налази, при чему не сме да премести златник на поље које је већ заузето. Миди је циљ да се у свакој колони и у свакој врсти нађе тачно један златник.

Мида је већ поприлично вешт у овој игри, али га интересује да ли успева да постигне свој циљ у најмањем могућем времену. Међутим, како не жели да позлати своју тастатуру, он је вас замолио да ви то израчунате. Од вас тражи да, за дати почетан распоред златника, одредите најмање могуће време за које он може да победи.
## Опис улаза
Прва линија стандардног улаза садржи један број, $N$: број врста, колона и златника.
Наредних $N$ линија садрже по два природна броја $r_i$ и $c_i$, који означавају да се на почетку $i$-ти златник налази у пресеку врсте $r_i$ и колоне $c_i$.

## Опис излаза
У прву и једину линију стандардног излаза исписати један број: најмањи број секунди потребан Миди да победи за задати распоред златника.
## Пример 1

### Улаз

```
3
2 1
2 2
2 3
```

### Излаз

```
2
```

## Пример 2

### Улаз

```
3
1 2
3 1
2 3
```

### Излаз

```
0
```

## Објашњење примера
За први пример, очито Миди треба бар две секунде да не би било два златника у другој врсти, а може да победи у два потеза тако што златник на пољу $(2,2)$ премести на поље $(1,2)$, а златник на пољу $(2,1)$ премести на поље $(3,1)$.

У другом примеру Мида не мора ништа да уради да би победио.


## Ограничења
-   $1 \leq n \leq 2\cdot 10^5$
-   $1\leq r_i,c_i\leq N$

Тест примери су подељени у 4 дисјунктних група:

-   У тест примерима вредним $10$ поена: $n \leq 2$.
-   У тест примерима вредним $20$ поена: $n \leq 7$.
-   У тест примерима вредним $30$ поена: $n \leq 1000$.
-   У тест примерима вредним $40$ поена: Без додатних ограничења.