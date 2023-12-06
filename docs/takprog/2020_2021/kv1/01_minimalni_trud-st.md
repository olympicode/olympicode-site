﻿Мика је одлучио да неодговорно приступи квалификацијама, и да се потруди што је мање могуће око првог круга, а да се ипак квалификује
за окружно такмичење. Отишао је код врачаре и гледањем у пасуљ сазнао колико ће бодова имати у другом и трећем кругу квалификација. Пошто
покушава да избегне што више посла, Мика је одлучио да вас пита колики је **минималан број бодова** које мора да освоји у првом кругу да би се квалификовао?

Подсећамо да се на окружно такмичење квалификују сви такмичари који
**на два најбоља круга квалификација имају укупно барем 256 бодова**.

## Опис улаза
У првом реду се налазе два цела броја $B$ и $C$: бројеви бодова које
ће Мика освојити у другом и трећем кругу квалификација.

## Опис излаза
Исписати најмањи број бодова који Мика мора да освоји у првом кругу,
тако да се квалификује на окружно такмичење.

## Ограничења
* $0 \leq B, C \leq 500$

Тест примери су подељени у три дисјунктне групе:

* У тест примерима вредним 20 поена: $B + C < 256$.
* У тест примерима вредним 30 поена: $C = 0$.
* У тест примерима вредним 50 поена нема додатних ограничења.

## Примери
### Пример 1
#### Улаз
```
100 150
```

#### Излаз
```
106
```

#### Објашњење
Ако Мика освоји 106 бодова у првом кругу, најбоља два круга ће бити први и трећи, и у збиру ће на њима имати тачно потребних 256 бодова.

### Пример 2
#### Улаз
```
300 0
```

#### Излаз
```
0
```

#### Објашњење
Мики нису потребни додатни бодови, јер ће их освојити довољно у другом кругу.