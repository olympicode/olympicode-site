﻿Задатак решавамо у сложености $O(n)$, те се одмах осврћемо на главно решење. Спорије имплементације могу решити подзадатке.

## Главно решење:
Можемо посматрати прелажење професора у следећу слободну учионицу као претварање сваког појављивања подниске $10$ у $01$. Штавише, можемо посматрати и као "прелажење кеца удесно" или "прелажење нуле улево". Ова два задатка су аналогна, те можемо унапред одредити онај који решавамо. Испоставља се да је једноставније решавати задатак за карактер ($0$ или $1$) који се мање пута појављује у задатој ниски (ако се оба појављују исти број пута, узимамо било који).

Нека је без умањења општости тај карактер $1$, што значи да се он појављује највише $\lfloor \frac{n}{2} \rfloor$ пута. Надаље симулирамо процес у што је мање операција могуће. Најпре, корисно је партиционисати кружну школу у три врсте партиција:
1. Узастопни кечеви: $111\ldots 111$
2. Узастопне нуле:  $000\ldots 000$
3. Наизменични кечеви и нуле, с тим да партиција увек почиње кецом и завршава се нулом: $1010\ldots 10$

Постављамо приоритет да се прво искористе партиције треће врсте, а тек онда остале. Овим се партиција друге врсте неће наћи након партиције прве врсте. Даље посматрамо величину сваке партиције и односе између партиција различитих врста током процеса. Наводимо све могуће случајеве:
1. *прва-трећа*: прва се смањује за $1$, а трећа повећава за $2$.
2. *друга-прва*: друга се смањује за $1$, а прва остаје непромењена.
3. *друга-трећа*: друга се повећава за $1$, трећа остаје непромењена.
4. *трећа-прва*: трећа се смањује за $2$, а прва се повећава за $1$.
5.  *трећа-друга*: трећа остаје непромењена, а друга се смањује за $1$.

Читав процес је могуће симулирати преко *кружне листе*. То је двоструко повезана листа у којој повезујемо почетак и крај. За сваки елемент те листе рачунамо колико се у једном тренутку смањи или повећа величина партиције коју представља на основу односа са суседима, као и када ће та величина пасти на $0$. Када се то деси бришемо елемент из листе што је могуће учинити у $O(1)$. У ствари, за сваки елемент памтимо тренутак у коме ће  он бити избрисан. То је могуће учинити употребом помоћног низа величине $n$, у коме за сваки могући тренутак памтимо које елементе треба обрисати баш тад.

Испоставља се да након одређеног времена, управо зато што смо претпоставили да кечева има мање од нула, остају само партиције врсте $2$ и $3$, тј. да се цела школа ротира одједном. У ствари, након $n$ тренутака ово ће бити случај. Уколико је $k-n>0$, коначно стање листе рачунамо једноставном модуларном аритметиком. Зато ред величине вредности $k$ није од важности.

 Пажљива имплементација доводи до решења укупне сложености $O(n)$. Као што је раније напоменуто, спорије имплементације могу решити подзадатке.