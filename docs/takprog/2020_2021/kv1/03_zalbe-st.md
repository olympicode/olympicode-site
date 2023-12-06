Врачара Миљана позната је по својим предсказањима о такмичењима из програмирања. Њена стручна област је погађање да ли ће Тајна Комисија прихватити неку такмичарску жалбу.

Миљана има своју луду теорију: да постоји природан број $X$ који не зна, такав да Комисија прихвата жалбе сваких $X$ година, тј. ако је Комисија прихватила жалбу у години $A$ прва следећа година када ће прихватити жалбу је $A+X$, а такође значи да је Комисија прихватила жалбу у години $A-X$.

Тачно $T$ такмичара је дошло да се посаветује са Миљаном. Она је од сваког појединачно тражила да прикупи информације о ранијим жалбама како би јој помогли да нађе $X$. Сваки такмичар је изнео неке гласине које је чуо на Алгори. За $N$ различитих година $A_1, A_2, ..., A_N$ такмичар тврди да је Тајна Комисија прихватала жалбе. За $M$ различитих година $B_1, B_2, ..., B_M$ тачмичар тврди да Тајна Комисија није прихватала жалбе.

Како не би губила време, Врачара Миљана је питала вас, такмичара који се неће жалити, да за сваког од $T$ такмичара одредите да ли постоји $X$ тако да су све гласине које је чуо тачне, односно да су жалбе прихваћене у годинама $A_1, A_2, ..., A_N$, а нису у годинама $B_1, B_2, ..., B_M$, пратећи Миљанину теорију да се жалбе прихватају сваких $X$ година.

## Опис улаза
У првој линији улаза налази се број $T$ -- број такмичара који су се јавили Врачари Миљани.

За сваког такмичара уносе се по још три линије: у првој линији се налазе $N$ и $M$ -- број гласина у којима су жалбе прихваћене и број гласина у којима су жалбе одбијене; у другој линији налази се $N$ целих бројева, низ $A_1, A_2, ..., A_N$ -- године у којима су, по гласинама, прихваћене жалбе; у трећој линији налази се $M$ целих бројева, низ $B_1, B_2, ..., B_M$ -- године у којима су, по гласинама, одбијене жалбе.

## Опис излаза
На стандардни излаз испишите $T$ бројева -- за сваког такмичара, у новом реду, исписати $1$ ако постоји $X$ које је у складу са његовим гласинама, односно исписати 0 у супротном.

## Ограничења
- $1 \leq T \leq 5$

За сваког од $T$ такмичара важи:

- $2 \leq N, M \leq 75000$
- $1 \leq A_i, B_i \leq 10^{18}$
- $A_i \neq A_j$, за $i \neq j$
- $B_i \neq B_j$, за $i \neq j$
- $A_i \neq B_j$, за свако $i, j$

Тест примери су подељени у 4 дисјунктних група:

-   У тест примерима вредним $10$ поена: $A_i, B_i, N, M \leq 3000$
-   У тест примерима вредним $10$ поена: $N = 2$
-   У тест примерима вредним $30$ поена: $A_i, B_i \leq 10^6$
-   У тест примерима вредним $50$ поена: Без додатних ограничења

## Примери
### Пример 1
#### Улаз
```
4
4 3
1 7 4 13
3 11 9
3 2
9 5 3
7 11
2 3
3 15
1 7 2
2 2
5643634654354 12346544323565
22341124534 7655867344
```

#### Излаз
```
1
0
1
1
```

#### Објашњење
За првог такмичара могуће је узети $X = 3$ тако да задовољи све гласине.
За другог такмичара немогуће је наћи $X$.
За трећег такмичара могуће је узети $X = 12$.