﻿Зли дух Милојица је решио да уништи велики град Пајазитово. Пајазитово је занимљив град, састоји се само од зграда. Укупно се налази $n$ зграда у Пајазитову, висина $i$-те зграде износи $A_i$. Како је уништење једног тако комплексног града веома тешко, Милојица је у поход позвао и његових $m$ деце. Свако дете има способност да једним струјним ударом смањи висину зграде у одређеном интервалу за $1$. Дете са редним бројем $i$ може смањити висине зграда у интервалу [$L_i, R_i$]. Мали духови јако слабашна створења, они могу ограничен број пута да искористе струјни удар. Дете са редним бројем $i$ може искористити не више од $K_i$ струјних удара, након тога трајно губи ту моћ. Једну зграду може напасти више духова, и сваки дух може напасти више зграда.

Како Милојица није тако добар са математиком, замолио вас је да испитате да ли његових $m$ деце могу уништити Пајазитово у потпуности. Пајазитово се сматра уништеним у потпуности ако све зграде имају висину $0$.

Шта више Милојица није сигуран који град је тачно Пајазитово(духови са толико деце знају понекад да помешају градове), тако да жели да сакупи информације о могућем уништењу $t$ различитих градова.

## Опис улаза
У првој линији стандардног улаза налази се природан број $t$, број градова за које је потребно испитати да ли је могуће уништење.

Сваки од $t$ градова је описан са $5$ линија:

У првој линији се налазе природни бројеви $n$, $m$, број зграда у Пајазитову и број Милојичине деце.

У другој линији се налази низ $A$ од $n$ бројева, $A_1$, $A_2$, $\dots$, $A_n$, висине сваке од $n$ зграда редом.

У трећој линији се налази низ $L$ од $m$ бројева, $L_1$, $L_2$, $\dots$, $L_m$, леви крајеви интервала за свако дете.

У четвртој линији се налази низ $R$ од $m$ бројева, $R_1$, $R_2$, $\dots$, $R_m$, десни крајеви интервала за свако дете.

У петој линији се налази низ $К$ од $m$ бројева, $K_1$, $K_2$, $\dots$, $K_m$, максимални број струјних удара за свако дете.

## Опис излаза
На стандардном излазу у $t$ линија исписати решење задатка. У $i$-тој линији исписати `DA` уколико Милојичина деца могу уништити $i$-ти град, у супротном исписати `NE`.

## Пример 1
### Улаз
```
2
3 2
1 4 2
1 2
3 3
3 4
1 1
10
1
1
6
```

### Излаз
```
DA
NE
```

## Објашњење примера
Желимо да сазнамо информације за $2$ града.

У првом граду постоје три зграде висина редом ($1, 4, 2$), Милојица води $2$ детета. Прво дете може нападати било коју зграду у интервалу [$1, 3$] и може да изврши највише $3$ струјна удара. Друго дете може нападати зграде у интервалу [$2, 3$] и укупно може извршити $4$ струјна удара. Деца могу уништити зграде у потпуности, један од могућих редоследа операција:

- прво дете изврши $1$ струјни удар на првој згради и уништи прву зграду
- друго дете изврши $4$ струјна удара на другој згради и уништи другу зграду 
- прво дете изврши преостала $2$ струјна удара на трећој згради и уништи трећу зграду

У другом граду постоји само једна зграда висине $10$ и Милојица има једно дете које може смањити висину зграде највише за $6$. Није могуће уништити зграду у потпуности.

## Ограничења и подзадаци

* $1 \leq t \leq 7$.
* $1 \leq n,m \leq 10^5$.
* $1 \leq А_i, K_i \leq 10^9$.
* $1 \leq L_i \leq R_i \leq n$.

Постоје три подзадатка: 

* Подзадатак $1$ [$20$ поена]: $1 \leq n, m, A_i \leq 100$.
* Подзадатак $2$ [$30$ поена]: $1 \leq n, m \leq 10^3$.
* Подзадатак $3$ [$50$ пеона]: Нема додатних ограничења.