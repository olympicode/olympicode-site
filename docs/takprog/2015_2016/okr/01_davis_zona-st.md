﻿У старим временима, монголски владар Петар Кан jе владао Таjном Комисиjом са чврстом песницом. Предани узурпатор Давис jе по сваку цену решен да га збаци са трона. Опште jе познато да Давис добиjа надљудске моћи када уђе у његову зону—зато jе Петар решен да по сваку цену спречи Дависа да уђе у зону.

Дависова зона се налази унутар таjне просториjе (коjа jе потпуно окружена зидовима) облика правоугаоника страница $a$ и $b$. Просториjа jе подељена на $a · b$ квадратних поља димензиjа 1 × 1. Поља су нумерисана од (1, 1) (горње-лево) до (a, b) (доње-десно). Зона jе правоугаоник димензиjа c и d, са горњим левим пољем $(x, y)$ (оваj правоугаоник jе потпуно садржан у просториjи). 

Давис креће са поља $(dx, dy)$, и у сваком кораку ће се померити за $∆x$ поља надоле, односно $∆y$ поља удесно. Уколико би Давис тим померањем ударио у зид, одбиће се под истим углом под коjим jе ударио у њега. Ако Давис удари у зид више од k пута без да уђе у зону, одустаће овога пута.

Петра сада занима да ли ће Давис икада бити у зони, и ако хоће, занима га поље на коме ће
бити када први пут буде у зони, да би знао да на њега постави стражаре.

## Opis ulaza
У првом реду стандардног улаза налазе се два природна броjа a и b, коjи представљаjу
броj редова и колона просториjе, редом. У другом реду налазе се два природна броjа $c$ и $d$, коjи представљаjу броj редова и колона Дависове зоне, редом. У трећем реду налазе се два природна броjа $x$ и $y$, коjи представљаjу ред и колону горњег левог поља зоне, редом. У четвртом реду налазе се два природна броjа $dx$ и $dy$, коjи представљаjу ред и колону поља са кога Давис креће. У петом реду налазе се три цела броjа $∆x$, $∆y$ и $k$, коjи представљаjу броj поља надоле и удесно за колико ће се Давис померити у сваком кораку, као и ограничење за броj удара у зид.

## Opis izlaza
У првом и jедином реду стандардног излаза потребно jе исписати два природна броjа hx
и hy, коjи представљаjу ред и колону поља на коме ће Давис бити први пут када се нађе у зони, редом. Уколико Давис не успе да уђе у зону, потребно jе исписати “NE” (без наводника).

## Пример 1
### Улаз
```
5 4
1 2
2 3
5 2
-1 -1 1
```

### Излаз
```
2 3
```


## Објашњења примера
На сликама испод налази се опис тест примера; на свакоj слици Дависова позициjа
означена jе словом Д, поља зоне су затамњена, а стрелица означава поље на коjе ће Давис отићи у следећем кораку. Давис наjпре удара у зид у пољу (4, 1); два корака након тога успешно улази у зону, и то у пољу (2, 3). Притом ниjе ударио у зид више од jедном, тако да jе ово коначно решење коjе треба исписати.

## Ограничења

* $1 ≤ a, b, c, d ≤ 1000$;
* $1 ≤ c, x, dx ≤ a$;
* $1 ≤ d, y, dy ≤ b$;
* $0 ≤ k ≤ 1000$;
* $∆x, ∆y ∈ \{−1, 0, 1\}$;
* Дависова зона ће увек бити обухваћена просториjом.

## Напомена
* У тест примерима вредним 20 поена важиће $∆x = 0$ или $∆y = 0$.
* У тест примерима вредним 20 поена важиће $k = 0$.
* У тест примерима вредним 60 поена нема додатних ограничења.
