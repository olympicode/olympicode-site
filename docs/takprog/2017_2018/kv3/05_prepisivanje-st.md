Година је $3018$. Такмичења из програмирања у Србији су никад већа, имамо стотине хиљада такмичара, и стотине хиљада рунди квалификација, а такмичари још увек преписују једни од других, и не поштују правилник.

Комисија је спремна као и увек, и унајмила је стотине хиљада чланова који ће надгледати преписивање. Сваки члан Комисије има задужену рунду од које ће почети надгледање, и норму коју треба да испуни - **тј. број различитих такмичара које треба да ухвати у преписивању.** Члан комисије врши надгледање у свим рундама почев од задате почетне рунде, док год не испуни задату норму.

За сваког такмичара су дате рунде у којима је прекршио правилник, а вас молимо да помогнете Комисији и за сваког члана одговорите колико најмање рунди заредом треба да посматра да би испунио норму (норма ће увек бити таква да се може испунити).

Сваки члан комисије ће ухватити све такмичаре који су преписивали у рунди коју надгледа. Такође, више чланова комисије могу ухватити истог такмичара у истој рунди.

Комисија је одлучила и да вам отежа посао тако што ће вам информацију о задужењу сваког члана дати у зависности од решења (минималног броја посматраних рунди) за претходног члана - обратите пажњу на опис улаза и појашњења примера у овом задатку.

## Опис улаза
У првој линији стандардног улаза налазе се два броја $N$ и $R$ одвојена размаком - број такмичара и број рунди квалификација.
У свакој од следећих $N$ линија се налази прво број $P_i$ - број рунди у којима је $i$-ти такмичар преписивао, па затим $P_i$ различитих бројева одвојених размаком који означавају рунде у којима је $i$-ти такмичар преписивао.
Затим, у следећем реду се налази број $K$ - број унајмљених чланова комисије.
У следећих $K$ редова се налазе по два броја одвојена размаком - $T_i$ и $S_i$ који означавају задужење $i$-тог члана комисије на следећи начин:

> Ако је $MP_i$ минималан број рунди који $i$-ти члан комисије треба да посматра, онда ће $Start_i = T_i + MP_{i-1}$ бити рунда у којој $i$-ти члан треба започети надгледање. $S_i$ означава норму $i$-тог члана. Узима се да је $MP_0 = 0$, док индексирање за чланове комисије почиње од 1. Обратите пажњу да $T_i$ може бити и негативан број, али ће добијени $Start_i$ увек бити од $1$ до $R$.

## Опис излаза
На стандардни излаз исписати $K$ линија - у свакој линији редом бројеве $MP_i$ - који означавају минималан број рунди које $i$-ти члан комисије треба да посматра.

## Пример 1
### Улаз
```
6 12
3 1 2 5
2 3 4
3 1 2 7
2 3 6
0
3 3 11 12
3
1 2
0 5
1 5
```

### Излаз
```
1
3
8
```

## Пример 2
### Улаз
```
5 5
1 2
1 3
1 4
1 5
2 1 2
3
1 5
-2 3
-1 2
```

### Излаз
```
5
3
1
```

## Objašnjenje primera
U prvom primeru, pрви члан комисије започиње надгледање од прве рунде, треба да испуни норму $2$, и одмах у првој рунди хвата два такмичара ($1$. и $3$.), што значи да надгледа само $1$ рунду. Други члан комисије почиње надгледање такође од прве рунде $(Start_2 = T_2 + MP_1 \implies Start_2 = 0 + 1 = 1)$, и потребно је да ухвати $5$ такмичара у преписивању. За то је довољно да надгледа $3$ рунде (такмичари $1$ и $3$ преписују у првој, док такмичари $2$, $4$ и $6$ преписују у трећој рунди). Трећи члан комисије започиње надгледање од четврте рунде, и потребно је да ухвати $5$ такмичара у преписивању. За то је потребно да надгледа све рунде до једанаесте.

U drugom primeru, oбратите пажњу да $T_i$ може бити негативан број на улазу, али узимајући у обзир решења за претходне чланове комисије, други члан комисије ће надгледање почети од $3$. рунде, док ће трећи члан комисије надгледање започети од $2$. рунде.

## Ограничења

* $1 \leq N,R,K \leq 300 000$.
* $1 \leq \sum_{i=1}^n P_i \leq 300 000$.

Тест примери су подељени у четири дисјунктне групе:

* У тест примерима који вреде $25$ поена важи $1 \leq N,R,K,\sum_{i=1}^n P_i \leq 10^4$.
* У тест примерима који вреде $25$ поена важи $1 \leq N,R,K,\sum_{i=1}^n P_i \leq 10^5$.
* У тест примерима који вреде $25$ поена важи $S_i = S_j,  \forall(i,j | 1 \leq i,j \leq K)$, тј. сви чланови комисије имају исту норму.
* У тест примерима који вреде $25$ поена нема додатних ограничења.