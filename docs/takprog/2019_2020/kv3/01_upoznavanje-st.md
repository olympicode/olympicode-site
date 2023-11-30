﻿
Милош се недавно преселио у једнодимензионални простор. Његова кућа се налази на $x$ метара од координатног почетка. Он такође зна да има $n$ комшија и зна координате њихових кућа.

Као и сваки пристојан становник једнодимензионалног простора, Милош би желео да се упозна са свим својим комшијама. Он зна да му је за пешачење једног метра потребна једна секунда.

Помозите Милошу и реците му колико му је најмање секунди потребно да обиђе све своје комшије.

## Опис улаза

У првом реду налазе се два цела броја $n$ и $x$, број комшија и позиција Милошеве куће. Други ред садржи $n$ целих бројева, $a_1, a_2, \dots, a_n$, где је $a_i$ позиција $i$-тог Милошевог комшије.

## Опис излаза

Исписати један цео број који представља минимално време потребно Милошу да обиђе све своје комшије.

## Пример 1

### Улаз

~~~
2 1
4 7
~~~

### Излаз

~~~
6
~~~

## Пример 2

### Улаз

~~~
3 4
3 7 9
~~~

### Излаз

~~~
7
~~~

## Објашњење примера

У првом примеру, Милош треба да се креће на десно све до куће са координатом $7$.

У другом примеру, Милош прво обилази левог комшију на позицији $3$, а након тога се креће на десно до комшије са координатом $9$.

## Ограничења


- $1\le n \le 10^6$
- $-10^8 \le x \le 10^8$
- $-10^8 \le a_i \le 10^8$


Тест примери су подељени у 4 дисјунктне групе:
- У тест примерима вредним 30 поена: $n \le 10$.
- У тест примерима вредним 15 поена: све комшије се налазе десно од Милоша.
- У тест примерима вредним 15 поена: све комшије се налазе лево од Милоша.
- У тест примерима вредним 40 поена: нема додатних ограничења.