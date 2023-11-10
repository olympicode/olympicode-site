﻿У овом задатку је потребно  наћи чврст број који се на најмање места разликује од задатог броја. Број је чврст ако су сва појављивања неке цифре узастопна.

Нека је у свим подзадацима $M$ број цифара броја $N$, а $d$ број различитих цифара.
### Подзадатак 1: $N\le10^6$
Простим проласком кроз све бројеве са шест или мање цифара можемо да видимо за сваки да ли је чврст и, уколико јесте, на колико се позиција разликује од почетног броја.

### Подзадатак 2: Све цифре су $0$ или $1$
За сваки префикс и суфикс је могуће једним проласком кроз низ да одредимо број потеза да би све цифре постале $0$ или $1$, па онда за сваку позицију преламања можемо да видимо колико нам треба потеза (постоји само $2M$ чврстих бројева са само јединицима и нулама, проверимо који од њих је оптималан).

### Подзадатак 3: $N\le 10^{100}$

Овај подзатак служи да се на њему освоје поени које користе идеје у наредна два, али нису довољно брза за већа ограниченја (нпр. $O(M^2\cdot d\cdot2^d)$ или $O(M\cdot d^2\cdot2^d)$)
### Подзадатак 4:  $N\le10^{10.000}$
Овај задатак ћемо урадити путем **динамичким програмирањем по битмаскама**. Нека је $dp[i][c][mask]$ најбоље решење за првих $i$ цифара, тако да је последња цифра $c$ и у $mask$ су на $1$ постављене цифре које одговарају цифрама које смо већ искористили (укључујући $c$).  Имаћемо и помоћни низ $aux[i][mask]$ који нам каже највећу вредност $dp[i][c][mask]$ за неко $0\le c\le 9$. Сада лако можемо рачунати вредност $dp[i][c][mask]$ као максимум од $dp[i-1][c][mask]$ и $aux[i-1][mask \text{ xor } 2^c]$ и на то додамо $1$ ако тренутна цифра није $c$. Тако свако стање $dp[i][c][mask]$ рачунамо у $O(1)$ и сваку од вредности $aux[i][mask]$ у $O(d)$, што нам даје решење у $O(M\cdot d\cdot 2^d)$.

### Подзадатак 5:  100 поена

У овом подзадатку за све поене ћемо променити перспективу. Уместо што тражимо најмањи број промена, тражићемо највећи број цифара да не мењамо. Да бисмо то постигли, чуваћемо два низа $a[c][mask]$, који је пандан низу $dp$ из претходног решења (кад обрадимо $i$-ту цифру ту ће се налазити најбоље решење за првих $i$ цифара) и низ $max[mask]$ који је пандан претходном низу $aux$. Главна разлика је што се већина ових низова сада неће мењати и онда можемо само да их пустимо да наследе вредности из претходне итерације. На пример: $a[c][mask]$ има смисла поново рачунати за тренутну цифру ($a[c][mask]$ постане максимум од $a[c][mask]+1$ и $max[mask\text{ xor } 2^c]+1$), и при томе променити $max[mask]$. Ово нам доста смањи број операција, тако да нам је сложеност сада $O(M\cdot2^d)$ што лако пролази за $100$ поена.