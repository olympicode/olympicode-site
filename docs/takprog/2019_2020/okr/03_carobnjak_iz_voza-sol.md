﻿
# Анализа

Намеће да ће чаробњаци потрошити мање времена на успављивање Јетија ако користе више снаге. Поред тога, без обзира што се специјална магија користи на крају (после бацања обичних чаролија), можемо већ на почетку "урачунати" специјалну магију (ако је већа од обичне магије).
Због тога формирамо низ са свим могућим чаролијама и магијама. Наиме, ако су $S_i$ и $M_i$ почетна јачина обичне чаролије и јачина специјалне магије чаробњака број $i$, онда у низ $a$ са свим (могућим) магијама додајемо следеће јачине:
$$
M_i, S_i, \frac{S_i}{2^1}, \frac{S_i}{2^2}, \frac{S_i}{2^3}, ..., \frac{S_i}{2^k}, 
$$
где је $k$ број са особином да је 
$$
\frac{S_i}{2^k}\geqslant 1 \ \ \ \ \text{и}\ \ \ \ \ \frac{S_i}{2^{k+1}} < 1.
$$
По формирању низа $a$, соритрамо га у нерастућем поретку, а затим одређујемо најмањи број $m$ такав да је
$$
a_1 + a_2 + a_3 + \dotsb + a_m \geqslant E.
$$

Како су све моћи мање од или једнаке броју $10^6$, то ће и елементи низа $a$ бити између $1$ и милион, па се тај низ може сортирати применом сортирања пребрајањем (counting sort). Број елемената у низу је $О(N\log\max\{S_i, M_i|i=1, 2, ..., N\}) = O(N\log N)$. Сложеност сортирања је такође $О(N\log N)$ . Одређивање броја $m$ који представља број дана потребних да се успава Јети има сложеност $О(\max\{S_i,M_i\})$.


Низ $a$ се може сортирати применом неког брзог алгоритма за сортирање (нпр. quick sort)  и тада  је сложеност самог сортирања $O(N\log N\log(N\log N))$.

Задатак можемо решити и без сортирања низа са магијама. Наиме, магије можемо сместити у приоритетни ред, а затим из реда брисати редом магије од највеће смањијући сваки пут Јетијеву моћ за износ те чаролије (магије) све док се Јети не успава.