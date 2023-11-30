﻿
## Анализа
На почетку је потребно проверити да ли је један интервал подинтервал другог и у том случају решење је 1. Уколико су у питању два иста интервала, тада је решење 0. Након што смо разрешили два специјална случаја, можемо се упустити у генералнију дискусију.

Након тога, претпоставимо без губитка општости да тражимо најкраћи пут од интервала чији је почетак лево у односу на почетак другог интервала. Најбитнија ствар коју је потребно приметити овде јесте да је увек довољно да се крећемо (у десно) ка подинтервалу чији је почетак најудаљенији или ка надинтервалу чији је крај најудаљенији. Ако смо у првом кораку кренули ка подинтервалу, тада у наредном кораку идемо ка надинтервалу. Овај процес се наставља све док не стигнемо до траженог интервала или не можемо учинити наредни корак. Подстичемо такмичаре да докажу коректност овог приступа.

## Решење у $O(N \cdot Q)$
Горе описано кретање по интервалима можемо имплементирати у линеарној сложености, тако да за сваки од $Q$ упита имамо највише $N$ корака.

## Решење за све поене
У овом случају, кретање по интервалима је потребно имплементирати у логаритамској сложености, користећи такозвани "binary lifting". Наиме, за сваки интервал чувамо интервале који се налазе на растојању $2^0, 2^1, 2^2,... 2^{\lfloor \log_2 N \rfloor}$.

## Решење у $O(N^3)$
У овом случају експлицитно конструишемо граф где су чворови интервали а ивице постоје између суседних интервала. Након тога, можемо одредити све парове најкраћих путева користећи БФС или Флојдов алгоритам. Пошто имамо $N$ чворова и $O(N^2)$ ивица, сложеност овог приступа је $O(N^3)$, што је довољно за случај када је $N \leq 500$.

## Решење за случај када су интервали или дисјунктни или је један подинтервал другог
У овом случају није тешко видети да је решење увек -1, 0, 1 или 2 (зашто?). Пошто смо разрешили случајеве када је решење 0 или 1, потребно је проверити да ли је решење -1 или 2. За сваки интервал, чувамо најшири интервал који га садржи. Уколико се најшири интервал који садржи почетни поклапа са најширим интервалом који садржи крајњи, тада је решење 2. У супротном је решење -1.