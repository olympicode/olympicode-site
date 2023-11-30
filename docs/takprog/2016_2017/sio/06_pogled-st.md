Чланови Комисије су у периодима доколице дошли на занимљиву идеју да на зградама једног места направе видиковце. Зграде су поређане на некој замишљеној линији. На свакој од њих могу бити постављена највише два уређаја за посматрање од којих је један усмерен према почетку тог низа зграда (на леву страну), а други према крају низа зграда (на десну страну).  Међутим, постављање уређаја који је окренут према почетку се може извести само ако између зграде на који се уређај поставља и почетка низа не постоји зграда веће висине. Слично постављање уређаја који је окренут према крају се може извести само ако између те зграде и краја низа не постоји зграда веће висине. Дозвољено је срушити неке зграде, ако се тиме добија могућност постављања уређаја за посматрање на неким зградама. За сваку зграду је позната цена рушења. Постављање сваког уређаја доноси одређену зараду и за сваку зграду су познате зарада ако је постављен уређај који је окренут на лево и зарада од уређаја који је окренут на десно. Укупна зарада од постављених уређаја је једнака разлици збира зарада од постављених уређаја и трошкова рушења зграда које треба срушити. Због заузетости неким другим активностима, они не могу да одвоје време и да одреде које зграде треба срушити и где поставити уређаје тако да зарада буде што већа. Помозите им да израчунају највећу могућу зараду која се може достићи постављањем уређаја (уз неопходна рушења).

## Опис улаза 
У првом реду се налази један природан број: \$n\$ - број зграда.
У наредних \$n\$ редова се налази по \$4\$ броја и они представљају податке за одговарајућу зграду: висина зграде, цена рушења зграде, зарада ако на њој постоји уређај окренут улево (при чему лево нема нити једна зграда веће висине, тј. све зграде које су биле веће висине су срушене) и зарада ако је на згради постављен уређај који је окренут удесно (при чему су зграде веће висине десно од те зграде срушене). Висине зграда су различити бројеви, тј. не постоје две зграде исте висине.

## Опис излаза
У првом реду излаза исписати максималну могућу зараду која представља разлику збира свих зарада од уређаја распоређених на зградама и збира трошкова рушења зграда које су морале да буду срушене.

## Пример 1
### Улаз
```
10
1041 18 23 27
1169 29 16 29
1962 14 23 23
1281 27 29 28
1995 21 29 26
1391 14 22 13
1815 19 26 29
1718 18 20 13
1771 25 29 18
1837 15 14 26
```
### Излаз
```
149
```

## Објашњење примера
Ако се распореде уређаји на зградама 1, 2, 3 и 5 (зграде су нумерисане бројевима од 1 до \$n\$, слева надесно) тако да су окренути лево, збир зарада ће бити \$23+16+23+29 = 91\$. Ако се на зградама 5, 7, 9 распореде уређаји тако да гледају десно, мора се срушити зграда број 10. Збир зарада од постављених уређаја је \$26+29+18 = 73\$. Рушење зграде 10 кошта 15. Тако је укупна зарада \$91 + 73 - 15 = 149\$. 

## Пример 2
### Улаз
```
8
1771 25 14 13
1270 21 24 16
1018 19 23 24
1729 26 25 16
1817 18 26 22
1861 26 13 18
1541 19 20 23
1645 25 14 17

```
### Излаз
```
98
```

## Ограничења и подзадаци
* Укупан број зграда није већи од \$100.000\$ (\$n\leq 100.000\$).
* Висине зграда су цели бројеви између \$1\$ и \$1.000.000.000\$.
* Цене рушења зграда су цели бројеви између \$0\$ и \$2.000.000\$.
* Зараде од уређаја су цели бројеви између  \$1\$ и \$20.000\$.

Постоје \$4\$ подзадатка у којима додатно важи:

* Подзадатак 1 [\$16\$ поена]: \$n \leq 1000\$. 
* Подзадатак 2 [\$12\$ поена]: цене рушења зграда су између \$1.000.000\$ и \$2.000.000\$, а зараде од постављања уређаја за посматрање између \$5\$ и \$10\$.
* Подзадатак 3 [\$25\$ поена]: цене рушења зграда су једнаке нули (за сваку од зграда). 
* Подзадатак 4 [\$47\$ поена]: нема додатних ограничења.