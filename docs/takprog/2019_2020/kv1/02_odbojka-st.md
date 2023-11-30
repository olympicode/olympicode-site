﻿Павле и Живко су два другара која много воле да играју одбојку. Пошто не могу да играју сами, направили су два тима. Капитен првог тима је Павле, а капитен другог тима је Живко. 

Организовали су велики одбојкашки меч. Одбојкашки меч се игра по правилу "у три добијена сета", односно први тим који освоји три сета је победник и меч се тада завршава. Да би се освојио један сет потребно је освојити бар $A$ поена у том сету. Игра се "на разлику", па се сет не може завршити уколико је разлика у поенима мања од $2$. Сет се завршава чим неки од тимова има $A$ или више поена, при чему је разлика бар $2$. Број поена у једном сету није ограничен.

На пример, за $A=50$ неки од могућих резултата на крају сета су: $50:45$, $48:50$, $125:123$, $49:51$, $50:0$, док неки од резултата који нису могући на крају сета су: $50:49$, $61:60$, $50:50$, $45:43$, $60:50$, $50:53$, $63:20$. 

Новинар једног дневног листа је дошао на стадион баш на крају меча и није знао који је био крајњи резултат. Питао је капитене за резултат како би могао да напише чланак о овом несвакидашњем мечу. Павле и Живко нису хтели да му кажу тачан резултат, јер су били љути на новинара због кашњења, али су му ипак рекли колики је био укупан број поена током целог меча. Новинару је јако важно да напише вест о мечу, чак и по цену да она није тачна. Једино му је битно да се укупан број поена поклапа са оним бројем који су му рекли капитени и да је меч био валидан. Помозите новинару и напишите програм који ће за укупан број поена на мечу и минималан број поена који је потребан да се освоји један сет одредити да ли постоји такав меч и наћи резултат на крају меча. Уколико има више могућих решења, исписати било које.

## Опис улаза

На стаднардном улазу су дата два природна броја $N$ и $A$. Број $N$ представља укупан број поена на мечу. Број $A$ представља минималан број поена који је потребан да би се освојио један сет. 

## Опис излаза

Уколико тражени меч не постоји, на излазу само исписати `-1`. Ако такав меч постоји, исписати било који могући меч тако што се испишу резултати по сетовима у редоследу у ком су сетови играни. Резултат сваког сета приказати у засебном реду, исписивањем два броја која представљају поене које су у том сету освојили тимови Павла и Живка, тим редом.

Водити рачуна да се игра на $3$ добијена сета, па је најмањи могући број сетова $3$, а највећи $5$.

## Пример 1

### Улаз

~~~
92 10
~~~

### Излаз

~~~
10 7
3 10
12 10
13 15
10 2
~~~

## Пример 2

### Улаз

~~~
20 20
~~~

### Излаз

~~~
-1
~~~

## Пример 3

### Улаз

~~~
163 25
~~~

### Излаз

~~~
25 17
12 25
25 23
25 11
~~~

## Ограничења
* $2 \leq N,A \leq 10^{9}$

Тест примери су подељени у три дисјунктне групе:

* У тест примерима вредним 30 поена: $N,A \leq 20$.
* У тест примерима вредним 40 поена: $A=25$.
* У тест примерима вредним 30 поена: Нема додатних ограничења.