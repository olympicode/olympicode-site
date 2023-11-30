Уместо да учи за тест из програмирања, мали Алекса је читав дан вежбао трикове са картицама. Сада му није преостало ништа друго него да одушеви свог професора Драгана једним триком, и нада се да ће добити бољу оцену због тога.

Он поседује **за сваки број од $1$ до $N$ по две картице** на којој је исписан тај број, и $K$ џокер картица на којима је исписано слово $J$.

Трик се састоји у томе да ће Алекса промешати и распоредити картице тако да се између сваке две картице које имају исти **број** на себи, налази **тачно толико картица колики је тај број**. Нпр, између две картице са бројем 3 треба да се налазе тачно 3 картице.

Овакав распоред је тешко направити без знања програмирања, и зато вас мали Алекса моли за помоћ. За дато $N$ и $K$ испишите распоред картица којим ће Алекса одушевити професора.

## Опис улаза
У првој линији стандардног улаза налазе се два природана броја $N$ и $K$, која редом означавају до ког броја Алекса поседује картице, и број џокер картица.

## Опис излаза
У првом реду стандардног излаза исписати тачно $2 \cdot N + K$ ознака картица које представљају распоред тим редом. Ознака картице са бројем је тај број, док је ознака џокер картице слово "Ј". Уколико постоји више решења, можете исписати било које.

## Примери
### Улаз 1
```
3 4
```

### Излаз 1
```
1 Ј 1 2 Ј 3 2 Ј Ј 3
```

### Улаз 2
```
7 5
```

### Излаз 2
```
3 7 4 6 3 5 J 4 J 7 6 5 J J 2 J 1 2 1
```

## Објашњење примера
У првом примеру имамо 3 пара картица са бројевима 1 до 3, и 4 џокера. Један могући излаз је: 1 Ј 1 2 Ј 3 2 Ј Ј 3 због тога што се између две картице са бројем 1 налази тачно једна картица (Ј), између две картице са бројем 2 се налазе тачно две картице (Ј 3), између две картице са бројем 3 се налазе тачно три картице (2 Ј Ј).

## Ограничења и подзадаци

* $2 \leq N, K \leq 222222$.

Постоји пет подзадатка:

* Подзадатак $1$ [$3$ поена]: $N, K \leq 4$.
* Подзадатак $2$ [$5$ поена]: $N \leq 8, K = 128$.
* Подзадатак $3$ [$32$ поена]: $N, K \leq 64$.
* Подзадатак $4$ [$22$ поена]: $K = 22$.
* Подзадатак $5$ [$38$ поена]: $K = 2$.