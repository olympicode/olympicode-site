Миладин просто не може да верује колико се угојио. Није веровао својој ваги, па је купио нову. Али онда није веровао ни новој ваги, па је купио још једну. Овај процес се наставио док коначно није имао $N$ вага у свом поседу. Тада је одлучио да мора на објективан начин проверити да ли су у праву његове ваге или он.

Поређао је све своје ваге у један низ, тако да за вагу која је $i$-та слева кажемо да има индекс $i$. Након тога, за сваку вагу сазнао је које тежине она може да измери. Прецизније, за свако $i$, сазнао је да вага са индексом $i$ може да измери тежине између $d_i$ и $u_i$, укључујући и њих (за остале тежине избацује грешку).

За своје даље прорачуне, потребни су му одговори на $M$ питања облика: 

- За дато $l$, $r$ и $x$, колико вага са индексима од $l$ до $r$ (рачунајући и та два) може да измери тежину $x$?

Помозите Миладину са овим прорачунима како би се што пре пребацио на салате. 

## Опис улаза
У првом реду стандардног улаза налазе се два цела броја $N$ и $M$ - број ваги које је прикупио и број питања на које му је потребан одговор. 

Линија $i$ од наредних $N$ линија садржи $2$ цела броја $d_i$ и $u_i$ - доњу и горњу тежинску границу коју може да измери вага са индексом $i$. 

Наредних $M$ линија садрже по три цела броја $l_i$, $r_i$ и $x_i$, тим редом - описе питања. 

## Опис излаза
На стандардни излаз исписати одговоре на питања истим редом као што су дата, сваки у свом реду.

## Пример 1
### Улаз
```
3 4
21 34
100 100
56 78
2 3 25
1 2 100
1 3 50
2 3 70
```

### Излаз
```
0
1
0
1
```

## Пример 2
### Улаз
```
8 5
1 2
4 7
7 12
1 8
7 7
4 6
6 9
9 10
2 6 6
4 6 7
5 8 12
1 8 10
2 7 7
```

### Излаз
```
3
2
0
2
5
```


## Објашњење primera
Prvi primer:

- Прво питање: Ниједна вага са индексом од $1$ do $2$ не може да измери тежину $25$.
- Друго питање: Вага $2$ може да измери тежину $100$.
- Треће питање: Ниједна вага са индексом од $1$ do $3$ не може да измери тежину $50$.
- Четврто питање: Вага $3$ може да измери тежину $70$.

Drugi primer:

- Прво питање: између индекса $2$ и $6$ ваге са индексима $2$, $4$ и $6$ могу да измере тежину $6$.
- Друго питање: између индекса $4$ и $6$ ваге са индексима $4$ и $5$ могу да измере тежину $7$.
- Треће питање: између индекса $5$ и $8$ ниједна вага не може да измери тежину $12$.
- Четврто питање: између индекса $1$ и $8$ ваге са индексима $3$ и $8$ могу да измере тежину $10$.
- Пето питање: између индекса $2$ и $7$ ваге са индексима $2$, $3$, $4$, $5$ и $7$ могу да измере тежину $7$.

## Ограничења

- $1 \leq N, M \leq 2 \cdot 10^5$.
- $0 \leq d_i \leq u_i \leq 10^9$, за $1 \leq i \leq N$.
- $1 \leq l_i \leq r_i \leq N$, за $1 \leq i \leq M$.
- $0 \leq x_i \leq 10^9$, за $1 \leq i \leq M$.

Тест примери су подељени у пет дисјунктних група:

- У тестовима вредним 15 поена: $N, M \leq 1000$.
- У тестовима вредним 15 поена: $d_i = u_i$, за $1 \leq i \leq N$.
- У тестовима вредним 20 поена: Не постоји $x$ које могу да измере две различите ваге.
- У тестовима вредним 20 поена: $u_i \leq 20$,  за $1 \leq i \leq N$.
- У тестовима вредним 30 поена: Без додатних ограничења.