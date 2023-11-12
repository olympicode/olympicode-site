Мали Срба прави нову верзију игрице “Flappy Bird”. Одлучио је да препреке више не буду цеви, већ троуглови који ће лебдеди у ваздуху.

Одлучио је да ће троуглове цртати тако што ће на почетку изабрати $N$ различитих тачака у равни. Свака препрека ће бити троугао који има темена у неке три од изабраних тачака. Након што се препрека пређе, прави се нова препрека која није иста као ни једна претходна (две препреке су  различите ако одговарајући троуглови имају бар једно различито теме).  

Да би игра изгледала лепше, он ће бирати **само троуглове чији су сви углови оштри**.

Малог Србу занима када одабере почетне тачке, колико ће игра бити дуга, односно, колико ће највише препрека постојати у игри?

## Ulaz
У првом реду стандардног улаза се налази један цео број $N$ који представља број тачака које је мали Срба изабрао. У следећих $N$ редова се налазе по два реална броја $X_i$ и $Y_i$ који представљају координате тачака. Координате ће бити записане са највише $3$ децимале.

## Izlaz
У првом и једином реду стандардног излаза исписати број различитих препрека које ће постојати у новој игри.

## Primer 1
### Ulaz
```
5
0.0 0.0
1.1 0.0
3.0 0.0
1.1 2.0
2.1 2.0
```

### Izlaz
```
3
```

## Objašnjenje primera
Мали Срба може направити $3$ различита оштроугла троугла, и то су троуглови које чине тачке:

* $(0.0, 0.0)$, $(3.0, 0.0)$ и $(1.1, 2.0)$;
* $(0.0, 0.0)$, $(3.0, 0.0)$ и $(2.1, 2.0)$;
* $(1.0, 0.0)$, $(3.0, 0.0)$ и $(2.1, 2.0)$.

## Ograničenja

* $1\leq N \leq 1000$.
* $-10^6 \leq X_i, Y_i \leq 10^6$.

Тест примери су подељени у dve дисјунктне групе:

* У тест примерима вредним $50$ поена важи $1\leq N\leq 100$.
* У тест примерима вредним $50$ поена нема додатних ограничења.
