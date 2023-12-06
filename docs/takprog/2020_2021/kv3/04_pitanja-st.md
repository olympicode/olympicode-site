Познато је да професори програмирања не воле да одговарају на питања студентима. Они од својих студената очекују да сами направе разумну претпоставку о свему што није јасно дефинисано у задатку који су добили, па су зато одлучили да одговоре само на она питања студената која пристигну оним данима када за то буду имали времена.

Професори су због тога одлучили да ослободе свој распоред сваког $k$-тог дана почев од дана $x$ па све до дана $y$. Да би изабрали ове бројеве потребно је да за $Q$ упита облика $x$, $y$ и $k$ одреде на колико питања треба одговорити у том случају. Пошто су због превише посла професори заборавили колико дана има у години ови бројеви могу бити јако велики.

Због тога су овај задатак оставили вама како би имали довољно времена да одговоре на питања студената.

## Опис улаза
У првој линији улаза налази се број $N$ - број дана када студенти могу постављати питања. У другој линији налази се $N$ целих бројева, низ $A_{1},A_{2},\ldots,A_{N}$ - очекивани број питања сваког дана. У трећој линији налази се цео број $Q$ - број упита на које треба одговорити. У наредних $Q$ линија следе бројеви $x_{i}$, $y_{i}$ и $k_{i}$ - границе интервала и корак тог упита, (при чему $k_{i}$ увек дели $y_{i}-x_{i}$).

## Опис излаза
На стандардни излаз исписати $Q$ целих бројева - за сваки упит, у новом
реду, исписати укупан број питња на које ће бити одговорено.

## Ограничења
-   $1 \leq N \leq 200000$
-   $1 \leq Q \leq 200000$
-   $1 \leq A_{i} \leq 5*10^{10}$
-   $1 \leq k_{i} \leq N$
-   $1 \leq x_{i} \leq y_{i} \leq N$
-   $k_{i}$ дели $y_{i}-x_{i}$

Тест примери су подељени у $4$ дисјунктне групе:

-   У тест примерима вредним $8$ поена: $A_{i}=i$
-   У тест примерима вредним $12$ поена: $A_{i}=i^2$
-   У тест примерима вредним $20$ поена: $N,Q \leq 10000$
-   У тест примерима вредним $60$ поена: Без додатних ограничења

## Примери
### Пример 1
#### Улаз
```
6
17 31 14 23 9 27
5
2 6 2
2 5 3
3 5 1
3 3 5
1 3 2
```

#### Излаз
```
81
40
46
14
31
```

#### Објашњење
$A_2 + A_4 + A_6 = 81$
$A_2 + A_5 = 40$
$A_ 3 + A_4 + A_5 = 46$
$A_3 = 14$
$A_1 + A_3 = 31$

### Пример 2
#### Улаз
```
10
1 2 3 4 5 6 7 8 9 10
5
2 8 3
4 9 1
1 9 2
5 10 5
1 9 8
```

#### Излаз
```
15
39
25
15
10
```