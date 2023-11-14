Данас је лоше време напољу и студент Срба је одлучио да неће излазити из куће, па тако неће отићи ни на факултет. Ипак, онда би изгубио битне бодове на предавањима, па је смислио нови начин како ће присуствовати њима. Направио је робота који ће отићи уместо њега, чак и записивати оно што прича професор.

Село у коме живи Срба је квадратног облика, и налази се на површини коју обухвата квадрат који има темена у координатама $(-K, K)$, $(K, K)$, $(K, -K)$, $(-K, K)$. Србина кућа се налази на координатама $(0,0)$, док се његов факултет налази на координатама $(X_f, Y_f)$.

Роботу, који је мали Срба направио, се могу задати следеће команде:

* `U` – Иди горе (uколико је био на координатама $(x, y)$ помериће се на $(x,  y+1)$);
* `D` – Иди доле (uколико је био на координатама $(x, y)$ помериће се на $(x,  y-1)$);
* `L` – Иди лево (uколико је био на координатама $(x, y)$ помериће се на $(x-1,  y)$);
* `R` – Иди десно (uколико је био на координатама $(x, y)$ помериће се на $(x+1,  y)$).

Студент Срба је роботу већ задао $N$ команди. Међутим, пошто он одавно није ишао на факултет, заборавио је тачан пут до њега, а робот је завршио у пивници. Сада роботу треба променити команде, и Срба вас моли да му помогнете. Пошто се већ довољно намучио правећи робота и пишући ове команде, он жели само да **обрише неки узастопни низ команди**, и то по могућству **најкраћи**. Нађите најкраћи такав низ уколико он постоји, или испишите $-1$ уколико не постоји.

Обратите пажњу да робот **ни у једном тренутку не сме прећи границе села** (не сме изаћи из квадрата који га представља), јер ће се изгубити. Прецизније, док се извршава коначан скуп команди након брисања, робот увек мора остати у квадрату (иако је можда током извршавања почетног низа команди, пре брисања, могао одлутати ван квадрата).

## Ulaz
У првом реду стандардног улаза се налазе $4$ броја – $N$, $K$, $X_f$, $Y_f$ који редом представљају број команди које је Срба задао роботу, границе села и координате факултета. У другом реду се налази $N$ карактера који представљају команде које је Срба задао роботу.

## Izlaz
У први и једини ред стандардног излаза исписати $2$ броја који, редом, представљају индекс почетне и крајње команде најкраћег низа команди који се може избрисати (команде су индексиране од $1$). Уколико не постоји такав низ, исписати $-1$. Уколико постоји више најкраћих низова, исписати било који.

## Primer 1
### Ulaz
```
11 100 2 3
UUURRDRDRUU
```

### Izlaz
```
7 10
```

## Primer 2
### Ulaz
```
8 2 1 2
RRRUULLL
```

### Izlaz
```
-1
```

## Objašnjenje primera
У првом примеру треба обрисати низ `RDRU` који се налази од $7$. до $10$. команде. Приметимо да се и брисањем низа `DRDRUU` od $6$. до $11$. позиције, на крају стиже у тражене координате $(2, 3)$, али је претходни низ краћи.

У другом примеру није могуће доћи у координате $(1,2)$ без изласка из села.

## Ograničenja

* $1\leq N\leq 10^6$.
* $1\leq К\leq 1000$.
* $-K\leq X_f,  Y_f \leq K$.

Тест примери су подељени у dve дисјунктне групе: 

* У тест примерима вредним $40$ поена важи $N\leq 1000$.
* У тест примерима вредним $60$ поена нема додатних ограничења.