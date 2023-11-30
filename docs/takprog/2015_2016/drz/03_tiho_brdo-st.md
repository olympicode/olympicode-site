﻿
У средњевековном добу, у малом градићу Тихом Брду живело jе чудовиште под називом Глутон, коjе jе волело да терорише становнике овог града. Многи витезови су покушавали да убиjу Глутона, али ни jедан ниjе успео да преживи таj сусрет.

Jедног дана, храбри архитекта Давис jе одлучио да нападне Глутона. Сазнао jе да се Глутон заправо састоjи из гомиле делова, коjи су међусобно споjени на таj начин да сваки део може контролисати неке друге делове. Глутон има тачно jедан део коjи представља његов мозак, и таj део ниjе контролисан од стране иjедног другог дела. Такође, Глутон може имати jедан или више делова коjи не контролишу ни jедан други део; ови делови представљаjу његове канџе. За сваку канџу постоjи тачно jедан скуп споjева коjим jе мозак (директно или индиректно) контролише. Уколико Давис успешно одсече мозак од контролисања свих канџи, онда Глутон остаjе потпуно безопасан.

Давис jе употребио своjе проjектне способности и закључио да jе сваком од Глутонових споjева x → y могуће приписати снагу w неопходну да би се таj споj уништио. Дависова жеља jе да уложи минимално снаге за одсецање мозга од канџи, па га занима коjе споjеве, слева на десно, треба да пресече да би то постигао. Уколико постоjи више тачних решења, Давис би волео да уложена снага на почетку буде што jе мања могућа, тj. тражи се лексикографски наjмање решење од свих тачних решења.

За дата два низа, a и b, величина n и m, кажемо да jе a лексикографски мањи од b уколико или постоjи нека позициjа i тако да jе су до те позициjе низови исти, а низ a jе по i-том члану мањи, тj.
$$(ai < bi) ∧ (∀j < i. aj = bj )$$

или се низови $a$ и $b$ поклапаjу на свим компатибилним позициjама, с тим да jе низ a краћи, тj.

$$(n < m) ∧ (∀j ≤ n. aj = bj )$$	
Примери: {1, 2, 3} < {2, 2, 3}; {1, 2, 3, 4} < {1, 2, 4, 4}; {1, 2, 3} < {1, 2, 3, 4}.
Заслепљен славом коjу би стекао и покличима “Хвала храбри Дависе!” од становника уколико би онеспособио Глутона, Давис нема довољно стрпљења да израчуна решење. Замолио вас jе за помоћ.


## Опис улаза
У првом реду стандардног улаза налази се природан броj $n$, коjи представља броj Глуто-
нових делова. Део са индексом 1 увек представља мозак. Затим следе описи делова, од мозга до дела са индексом $n$, редом, на следећи начин: у првом реду се налази цео броj $m_i$, коjи представља броj делова коjи су под директном контролом текућег дела. Уколико важи $m_i$ = 0, онда jе текући део канџа. У супротном, у другом реду се налази низ a од $m_i$ природних броjева, коjи представља, слева на десно, индексе делова под директном контролом текућег дела. У трећем реду се налази низ $w$ од $m_i$ природних броjева, тако да $j$-ти члан низа $w$, $w_j$ , oзначава снагу неопходну за уништење споjа коjим текући део контролише $j$-тог члана низа $a$, $a_j$ .

## Опис излаза
У првом реду стандардног излаза потребно jе исписати минималну укупну снагу неопходну
да би Давис онеспособио Глутона. У наредном реду неопходно jе исписати лексикографски наjмањи низ снага коjе ће требати Давису да би одсекао све неопходне споjеве, слева на десно, редом. Чланове низа треба одвоjити размаком.

## Пример 1
### Улаз
```
7
2
2 5
4 7
2
3 4
2 3
0
0
2
6 7
1 6
0
0
```

### Излаз
```
11
4 1 6
```

## Објашњења примера
На сликама испод налази се опис тест примера; лева слика представља почетно стање Глутона, а десна представља оптимално решење. Мозак jе означен црном позадином, а канџе црвеном боjом. Прецртани и испрекидани споjеви представљаjу оне споjеве коjе Давис треба да уништи. Постоjе два решења коjа захтеваjу минималну укупну снагу 11; та решења су, слева на десно, {4, 7} и {4, 1, 6}. Од та два решења, бирамо лексикографски мање.

## Ограничења

* $2 ≤ n ≤ 10^5$;
* $1 ≤ w_j ≤ 10^9$;
* Укупан броj споjева ће увек бити $n − 1$, и увек ће за сваку канџу постоjати тачно jедан скуп споjева коjи jе повезуjу са мозгом.

## Подзадаци и бодовање
Тест примери су подељени у четири подзадатка, у коjима важе следећа
додатна ограничења:
* Подзадатак 1 [10 поена]: Сви споjеви ће имати исту потребну снагу за уништење;
* Подзадатак 2 [10 поена]: Jедино мозак може директно контролисати више од jедног дела Глутона;
* Подзадатак 3 [30 поена]: $n ≤ 1000$;
* Подзадатак 4 [50 поена]: Нема додатних ограничења.
Уколико на свим тест примерима jедног подзадатка израчунате тачну укупну снагу, добиjате 60% поена за таj подзадатак. Уколико коректно одредите лексикографски минимално решење на свим тест примерима jедног подзадатка, добиjате 40% поена за таj подзадатак.
