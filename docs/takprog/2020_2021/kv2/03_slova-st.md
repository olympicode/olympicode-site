Шетајући градом, наишли сте на натпис сачињен од $N$ слова енглеског алфабета. Из неког разлога, запитали сте се **на колико је начина могуће обрисати сва слова осим 26, тако да су преостала слова сва различита и поређана редом**?

Пошто овај број може бити веома велик, потребно је исписати само његов остатак при дељењу са $10^9 + 7$.

## Опис улаза
У првом реду налази се број слова у натпису $N$.

У другом реду налази се $N$ великих слова која (редом) чине натпис.

## Опис излаза
Исписати број начина да се из натписа обришу сва слова осим 26, тако да су преостала слова поређана редом (тј. тако да остане `ABCDEFGHIJKLMNOPQRSTUVWXYZ`) по модулу $10^9 + 7$.

## Ограничења
* $1 \leq N \leq 10^6$

Тест примери су подељени у четири дисјунктне групе:

* У тест примерима вредним 10 поена: $N \leq 26$
* У тест примерима вредним 20 поена: $N \leq 27$
* У тест примерима вредним 30 поена: $N \leq 3000$
* У тест примерима вредним 40 поена нема додатних ограничења.

## Примери
### Пример 1
#### Улаз
```
29
AABACDEFGHIJKLMNOPQRSTUVWXYZZ
```

#### Излаз
```
4
```

#### Објашњење
Могући начини су:

* Обрисати прво и треће `A` и прво `Z`.
* Обрисати прво и треће `A` и друго `Z`.
* Обрисати друго и треће `A` и прво `Z`.
* Обрисати друго и треће `A` и друго `Z`.

### Пример 2
#### Улаз
```
78
AAABBBCCCDDDEEEFFFGGGHHHIIIJJJKKKLLLMMMNNNOOOPPPQQQRRRSSSTTTUUUVVVWWWXXXYYYZZZ
```

#### Излаз
```
865810542
```