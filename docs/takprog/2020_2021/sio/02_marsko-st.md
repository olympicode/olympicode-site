Као што сви знамо, људи су одавно колонизовали Марс и на њему изградили $N$ градова и $M$ путева. Како до површине Марса допире велика доза јонизујућег зрачења из свемира, око градова и путева изграђене су заштитне куполе. Међутим, нису сви путеви направљени и одржавани по прописима (као и на Земљи). Познато је да је количина зрачења коју пропушта заштита пута $i$ једнака $W_i$. Возила која се користе на Марсу имају додатну заштиту од зрачења. Возилом које има заштиту $A$, безбедно је возити се по путу $i$ ако је $W_i \leq A$. У сваком граду налази се по једно возило. Возило које се налази у $i$-том граду има заштиту $A_i$. Јунак нашег задатка, Марско, планира да се пресели на Марс, али још увек није одлучио у који град. Како би донео одлуку, за сваки град $i$ занима га до колико градова може безбедно да стигне ако крене одатле и сме да мења возила. Помозите Марску да се пресели на Марс тако што ћете решити овај проблем уместо њега.

## Описи функција
Потребно је да имплементирате функцију

* $\text{Resi}(N, A[\dots], M, U[\dots], V[\dots], W[\dots], R[\dots])$

где је:

* $N$ број градова.
* $A$ низ целих бројева где $i$-ти број представља заштиту возила које се налази у граду $i$.
* $M$ број путева.
* $U$, $V$ и $W$ низови дужине $M$ који описују путеве: $i$-ти пут повезује градове $U_i$ и $V_i$, док је количина зрачења коју пропушта заштита овог пута $W_i$.
* $R$ низ у који треба да упишете решење за сваки град.

**Сви низови су индексирани од 1.**

## Ограничења
* $1 \leq N, M \leq 2 \times 10^5$
* $1 \leq A_i, W_i \leq 10^9$
* $1 \leq U_i, V_i \leq N$
* $U_i \neq V_i$
* Постоји највише један пут који директно повезује неки пар градова.

## Подзадаци
* **[7 поена]:** Све вредности у низу $A$ су једнаке.
* **[7 поена]:** Све вредности у низу $W$ су једнаке.
* **[12 поена]:** $N, M \leq 250$.
* **[33 поена]:** $N, M \leq 2500$.
* **[41 поена]:** Без додатних ограничења.

## Детаљи имплементације
Потребно је да пошаљете тачно један фајл `marsko.cpp` који имплементира поменуту функцију. Осим тражене функције, ваш фајл може садржати и додатне глобалне променљиве, помоћне функције и додатне библиотеке.

Ваша функција мора бити следећег облика:

`void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R);`

**Вашим програмима је дозвољено да мењају садржај низова, али не смеју да приступају ван њихових граница**

Уз задатак, обезбеђен вам је "template" фајл `code.cpp` који можете користити и мењати по потреби. Такође вам је обезбеђен програм `grader.cpp` који служи да лакше тестирате кодове. Овај програм учитава са стандардног улаза следеће податке:

* У првом реду бројеве $N$ и $M$.
* У наредном реду низ $A$.
* У наредних $M$ редова по три броја. У $i$-том реду налазе се бројеви $U_i$, $V_i$ и $W_i$.

Затим овај програм позива вашу функцију и штампа низ $R$ који је функција попунила, у једном реду.

## Примери
### Пример 1
#### Улаз
```
5 7
7 7 7 7 7
1 2 3
1 3 8
2 5 7
4 5 10
1 5 6
2 3 9
3 5 8
```

#### Излаз
```
3 3 1 1 3
```

#### Објашњење
Возилом са заштитом $7$ могуће је безбедно се возити по првом, трећем и петом путу. Из првог, другог и петог града могуће је безбедно стићи у први, други и пети град. Из трећег и четвртог града није могуће безбедно стићи у неки други град.

### Пример 2
#### Улаз
```
5 4
1 7 8 5 3
1 3 7
1 5 7
3 5 7
2 4 7
```

#### Излаз
```
1 2 3 1 1
```

#### Објашњење
Из првог, четвртог и петог града није могуће безбедно стићи у неки други град. Из другог града могуће је безбедно стићи у други и четврти град. Из трећег града могуће је безбедно стићи у први, трећи и пети град.

### Пример 3
#### Улаз
```
5 5
5 9 6 1 3
1 5 7
1 2 4
2 5 9
4 3 2
3 5 6
```

#### Излаз
```
5 5 3 1 1
```

#### Објашњење
Из првог града могуће је безбедно стићи у други град. Када у другом граду заменимо возило можемо безбедно да стигнемо до свих градова.