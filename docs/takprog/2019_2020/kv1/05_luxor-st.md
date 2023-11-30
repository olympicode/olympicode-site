﻿
У недавној посети храму у Луксору наишли сте на интересантну, древну загонетку. Наиме, староегипатски мудраци су волели да множе и да рачунају XOR-вредност парова природних бројева. Наишли сте на таблу на којој је исписано $T$ парова ненегативних целих бројева $A_i, B_i$. Интересантно је да је код свих ових парова број $A_i$ непаран. Ваш задатак је да за сваки од тих парова пронађете два природна броја $X_i, Y_i$ таква да важи $A_i = X_iY_i$ и $B_i = X_i \text{ xor } Y_i$. Могуће је да такав пар не постоји, уколико је то случај, испишите $-1$.

## Опис улаза

У првој линији стандардног улаза налази се природан број $T$. У наредних $T$ линија налазе се по два ненегативна цела броја одвојена размаком, $A_i$ и $B_i$.

## Опис излаза

У $T$ редова, по један за сваки упит, исписати тражени пар $X_i, Y_i$, одвојен размаком. Уколико такав пар не постоји, исписати $-1$. Уколико има више решења, исписати било које.

## Пример 1

### Улаз

~~~
4
21 4
2795079079011879151 119681854
9 0
9 2
~~~

### Излаз

~~~
3 7
1679133257 1664596343
3 3
-1
~~~

## Ограничења

- $1 \leq T \leq 10.000$
- $0 \leq A_i, B_i < 2^{62}$
- $A_i$ је непаран.

Тест примери су подељени у 3 дисјунктне групе:

- У тест примерима вредним 20 поена: $T \leq 10$ и $A_i, B_i \leq 10^{13}$.
- У тест примерима вредним 20 поена: $T \leq 500$.
- У тест примерима вредним 60 поена: Без додатних ограничења.

## Напомена

Оператор XOR, односно ексклузивну дисјункцију у C++ записујемо помоћу симбола `^`. Ова операција $x\ \text{xor} \ y$ се за ненегативне целе бројеве $x,y$ дефинише на следећи начин. Прво се бројеви запишу у бинарном запису. Уколико један број има мање цифара од другог, дописују му се водеће нуле све док не буду имали исти број бинарних цифара. Тако се добијају два низа бинарних цифара, означимо их са $a_1, \ldots, a_k$ и $b_1, \ldots b_k$. Затим се за сваку позицију $i \in \{1, \ldots, k \}$ рачуна $c_i$ помоћу следећих правила:

* За $a_{i} = 0, b_{i} = 0$ важи $c_{i} = 0$
* За $a_{i} = 0, b_{i} = 1$ важи $c_{i} = 1$
* За $a_{i} = 1, b_{i} = 0$ важи $c_{i} = 1$
* За $a_{i} = 1, b_{i} = 1$ важи $c_{i} = 0$

Низ бинарних цифара $c_1, \ldots, c_k$ (који можда има водеће нуле) је бинарни запис резултата, односно броја $x \ \text{xor} \  y$.