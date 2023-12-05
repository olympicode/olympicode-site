Миле је видео $N$ тачака у равни, од којих $i$-та има координате $(x_i,y_i)$. Одмах је себи поставио најприродније питање: "На колико начина се могу изабрати две различите тачке, тако да прва буде доње лево теме, а друга горње десно теме неког квадрата са страницама паралелним координатним осама?". 

При томе се под доњим левим теменом квадрата сматра оно теме које има најмању $x$ координату и најмању $y$ координату, а под горњим десним теменом оно теме које има највећу $x$ и највећу $y$ координату.

Међутим, тачака има пуно и Миле је брзо одустао. Помозите му и одговорите на питање уместо њега.

## Опис улаза
У првом реду стандардног улаза налази се цео број $N$, број тачака у равни. У наредних $N$ редова, налазе се по два цела броја, $x_i$ и $y_i$, који представљају координате $i$-те тачке. 

## Опис излаза
У једини ред стандардног излаза исписати један број - колико различитих парова тачака можемо изабрати, тако да прва буде доње лево теме, а друга горње десно теме неког квадрата са страницама паралелним координатним осама.

## Ограничења
-   $1 \leq N \leq 100.000$
-   $0 \leq x_i, y_i \leq 1.000.000.000$, за свако $1 \leq i \leq N$
-   Гарантује се да важи $x_i \neq x_j$ или $y_i \neq y_j$ за свако $i \neq j$

## Подзадаци
1. (18 поена) $x_i = y_i$, за свако $1 \leq i \leq N$, $1 \leq N \leq 20.000$.
2. (16 поена) $1 \leq N \leq 1.000$.
3. (29 поена) $0 \leq x_i, y_i \leq 1.000$, за свако $1 \leq i \leq N$.
3. (37 поена) Без додатних ограничења.

## Примери
### Пример 1
#### Улаз
```
4
0 0
2 3
5 6
4 4
```

#### Излаз
```
2
```

#### Објашњење
Уколико изаберемо прву и четврту тачку, постоји квадрат странице дужине $4$, којем је доње лево теме баш прва тачка, а горње десно баш четврта тачка.  Слично, уколико изаберемо другу и трећу тачку, постоји квадрат странице дужине $3$, којем је доње лево теме баш друга тачка, а горње десно баш трећа тачка. Дакле, одговор је $2$. 

### Пример 2
#### Улаз
```
3
0 0
0 2
2 0
```

#### Излаз
```
0
```

#### Објашњење
Које год две тачке да изаберемо, не постоји квадрат којем је доње лево теме прва од тих тачака, а горње десно теме друга од тих тачака. Због тога је одговор $0$.