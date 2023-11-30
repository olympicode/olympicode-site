﻿Деда Видо, пољопривредник из села у околини Новог Пазара, већ дужи низ година одржава своје имање. Имање се може представити као матрица димензија $N \times M$, где једно поље у матрици означава $1$ метар квадратни имања. Видово земљиште је мало мочварно, тако да свако поље у матрици може садржати земљу или воду. Сви повезани делови воде праве једно језеро на имању. Два поља су повезана ако деле једну страницу у матрици. Приметимо да деда Видово имање тренутно може садржати више одвојених језера.

Данас у госте долази његов унук Лале који много воли да пеца. Лале је прилично несташан и никада се не задржава дуго на једном језеру. Када обиђе сва језера он се поново враћа у град и оставља свог деду усамљеног. 

Деда Видо силно жели да задржи унука што дуже на селу, тако да је набавио довољно материјала да највише $К$ метара квадратних ($К$ поља матрице) промени из воде у земљу. На овај начин он би преградио нека од постојећих језера и од једног језера добио више њих.

Ваш је задатак да помогнете деда Виду да распореди материјал тако да максимизује број добијених језера.

## Напомена
Ово је задатак са познатим улазом (*output-only* задатак). Вама су дати улазни фајлови (`01.in`, `02.in`, `03.in`, `04.in`, `05.in`), док ви треба да пошаљете само одговарајуће излазне фајлове за њих (`01.out`, `02.out`, `03.out`, `04.out`,  `05.out`).

## Опис улаза
У првом реду улазних фајлова налазе се три прородна броја  $N$, $M$ и $K$, дужина имања, ширина имања, број метара квадратних које можемо променити из воде у земљу.
У сваком од наредних $N$ редова налази се по $M$ карактера. Сваки карактер у матрици може представљати земљу или воду. Ако је карактер у пресеку $i$-те врсте и $j$-те колоне `x` (без наводника) онда се на том пољу налази земља, у супортном, карактер у пресеку $i$-те врсте и $j$-те колоне је `.` (без наводника) и означава воду.

## Опис излаза
Сваки ваш излазни фајл треба да садржи матрицу димензија $N \times M$. Свако поље у матрици може бити `x` (земља), `.` (вода), `o` (поље на коме се налазила вода и сада је промењено у земљиште).

## Пример 1
### Улаз
```
4 8 3
.x...x..
.x.x.x..
.x...xxx
.xxxxx..
```

### Излаз
```
.x...x..
.xoxox..
ox...xxx
.xxxxx..
```

### Објашњење примера
Имање је димензија  $4 \times 8$. Можемо променити највише $3$ поља на којима се налази вода у поља на којима се налази земља. У почетном тренутку на имању се налази $4$ језера. Променили смо поља са координатама $(3, 1), (2, 3), (2, 5)$. Након наведеног преграђивања на имању се налази $6$ језера.

## Напомена 1

- Сви фајлови морају бити у описаном формату, у фајловима се не сме налазити ниједан карактер осим `x`, `.` и `o`.
- У матрици се не сме налазити више од $K$ карактера `o`. 
- Сваки карактер `o` мора налазити на пољу где се претходно налазио карактер `.`.
- Ако се на неком пољу у финалној матрици налази карактер `x` или карактер `.`, онда се на том пољу морао налазити исти карактер и у почетној матрици.

## Бодовање
Дато вам је пет улазних фајлова.

- Први пример (`01.in`) вреди $10$ поена.
- Други пример (`02.in`) вреди $20$ поена.
- Трећи пример (`03.in`) вреди $20$ поена. 
- Четврти пример (`04.in`) вреди $25$ поена.
- Пети пример (`05.in`) вреди $25$ поена.

Ваша решења се бодују у односу на решење комисије. Решење комисије ће носити $100$ поена. За сваки проценат за који ваше решење буде горе од комисијског губите $10$ поена све до $0$ поена (то значи да решења која буду гора од комисијског за више од $10$% носе $0$ поена). Ако ваше решење за одређен унос буде боље од комисијског добићете $100$ поена.

Резултати комисије редом по фајловима, у односу на које се рачуна скор, су:

- Први фајл $18$ језера.
- Други фајл $1091$ језеро.
- Трећи фајл $1009$ језера.
- Четврти фајл $14566$ језера.
- Пети фајл $46103$ језера.