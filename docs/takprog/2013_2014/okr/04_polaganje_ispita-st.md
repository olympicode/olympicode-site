Анитица је овог викенда полагала испит из Опште-народне медицине и уметности. Принцип полагања овог испита је другачији од осталих: **на испиту студент извлачи $N$ питања, одговара на свако од њих**, а крајњи број бодова се добија сумом бодова најбољих $K$ питања. Свако питање вреди исти број бодова. Како је ово јако битан испит, уколико студент почне да “лупа глупости” може освојити и негативан број бодова на  неком од питања. 

Анитица је успешно положила испит али није задовољна својим бројем бодова. Ово је њој јако битно, јер није успела да добије оцену потребну да у факултетској посластичари освоји бесплатне чварке и кавурму као награду. Зато је решила да нађе други начин оцењивања како би добила већи број бодова. Начин који је одабрала је да уместо $K$ најбољих одговора, **може да изабере било којих  $K$ при чему је укупан број бодова једнак производу бодова освојених на изабраних $K$ питања**.

Помозите Анитици да утврди који је највећи број бодова који она може да освоји преко свог начина бодовања испита.

## Ulaz
У првом реду стандардног улаза налазе се два природна броја, одвојена једним знаком размака, $N$ и $K$, који означавају укупан број питања и број питања који улазе у рачунање броја бодова за испит. Други ред улаза садржи $N$ целих бројева, одвојених по једним знаком размака, који представљају број бодова за свако од извучених питања.

## Izlaz
Први и једини ред стандардног излаза треба да садржи $K$ целих бројева – вредности питања које треба изабрати за рачунање броја бодова по методи Анитице. Питања штампати у произвољном редоследу. Уколико има више решења, штампати било које.

## Primer 1
### Ulaz
```
7 5
-1 4 2 3 1 5 -3
```

### Izlaz
```
-1 4 3 5 -3
```

## Objašnjenje primera
Производ изабраних питања је $180 = (-1)\cdot 4\cdot 3\cdot 5\cdot (-3)$. Ово је максимални производ који дају пет одговора датог низа питања. 

## Ograničenja

* $1 \leq K \leq N \leq 5.000$.
* Елементи низа су из сегмента $[-1.000.000, 1.000.000]$.

Тест примери су подељени у dve дисјунктне групе:

* У тест примерима вредним $20$ поена важи $1\leq N\leq 15$ i elementi niza su iz segmenta $[-3, 3]$.
* У тест примерима вредним $80$ поена нема додатних ограничења.