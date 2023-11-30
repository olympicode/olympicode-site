Сада, када је одрадио такмичење, Мирослав је схватио колико је програмирање напорно, те је одлучио да побегне на Марс. Он је на интернету наишао на наградну игру Минго у којој је главна награда пут на Марс.

Наградна игра се састоји у томе да сваки такмичар на листићу изабере тачно \$K\$ различитих природних бројева, где је сваки број из скупа \${1, 2, 3, ..., M}\$. Након тога се врши \$Q\$ извлачења, где свако извлачење подразумева насумичан одабир тачно \$K\$ различитих бројева из претходно поменутог скупа. Сваки листић важи за свих \$Q\$ извлачења, и такмичар који има листић са свим извученим бројевима у било ком од \$Q\$ извлачења добија пут на Марс.

Како би повећао своје шансе, Мирослав је попунио \$N\$ листића. Како је сада тешко пратити све те листиће, он је замолио вас да му помогнете.

Он жели да за свако извлачење у сваком тренутку зна колико листића има сваки до тада извучен број, тј. за свако извлачење посебно, након извученог \$i\$-тог броја он жели да зна колико његових листића садржи сваки од извучених \$i\$ бројева у том извлачењу.

## Опис улаза
У првој линији стандардног улаза се налазе бројеви \$N, K\$ и \$M\$, који редом означавају број листића које је Мирослав попунио, број разлитих бројева које је потребно обележити на листићу и највећи број који је могуће обележити.
Следећих \$N\$ редова описије листиће које је попунио Мирослав, где се у \$i\$-том реду налази \$K\$ бројева који означавају изабране бројеве на \$i\$-том листићу.
Након тога се налази један ред са бројем \$Q\$ који представља број извлачења.
У наредних \$Q\$ редова се налази опис свих извлачења. У \$i\$-том реду се налази \$K\$ бројева који представљају бројеве у редоследу у којем су били извлачени.

## Опис излаза
На стандарни излаз је потребно исписати \$Q\$ редова, где \$i\$-ти ред одговара решењу за \$i\$-то извлачење, тј. \$ј\$-ти број у \$i\$-том реду представља број листића који садрже сваки од извучених \$ј\$ бројева у \$i\$-том извлачењу.

## Пример 1
### Улаз
~~~
3 3 15
2 1 3
1 10 4
4 11 1
2
1 4 11 
4 3 11
~~~

### Излаз
~~~
3 2 1
2 0 0
~~~

## Пример 2
### Улаз
~~~
2 7 39
7 6 5 4 3 2 1
1 2 3 4 5 6 8
2
4 3 5 1 2 6 7
6 5 4 3 2 8 39
~~~

### Излаз
~~~
2 2 2 2 2 2 1
2 2 2 2 2 1 0
~~~

## Објашњење примера
У првом тест примеру код првог извлачења решење је "3 2 1" зато што број 1 Мирослав има на сва 3 листића. Након другог извученог броја имамо комбинацију "1 4" која се појављује на 2 листића. На крају трећег извлачења имамо комбинацију бројева "1 4 11" и једини листић који има сва 3 броја из комбинације јесте трећи листић те је одговор 1.
У другом извлачењу првог тест примера, број 4 садрже листићи 2 и 3. Док не постоје листићи који садрже све бројеве из комбинација "4 3" и "4 3 13".

## Ограничења
* \$1 \leq N \leq 10000\$
* \$1 \leq K \leq 8\$
* \$K \leq M \leq 500\$
* \$1 \leq Q \leq 20000\$

Тест примери су подељени у четири дисјунктне групе:

* У тест примерима који вреде 15 поена важи \$Q \leq 10\$.
* У тест примерима који вреде 15 поена важи \$K = 3, M < 100\$.
* У тест примерима који вреде 30 поена важи \$K \leq 5, M < 100\$.
* У тест примерима који вреде 40 поена нема додатних ограничења.