У далеком Јапану харају многобројне криминалне групe, познате као јакуза кланови. Њихови чланови, јакузе, леде крв у жилама свима који су те лоше среће да их сретну. У главном граду Јапана, Токију, се међу јакузама тренутно одвија битка за власт. Од разних страшних криминалаца, као најјачи и најопаснији се издваја Мома, који жели да освоји цео Токио.

Токио се може замислити као матрица димензија $M\times N$. Првог дана ће Мома заузети једно (било које) поље те матрице. У сваком наредном дану, он може заузети било које поље које је суседно неком пољу које је већ заузео. Два поља су суседна ако деле страну. Како је Мома најопаснији јакуза, он свако поље може освојити за дан, па ће после $MN$ дана цео Токио бити његов.

Међутим, иако га ниједна јакуза не може победити, постоји једна ствар која може - његово сујеверје. Он поседује своју мапу Токија, и на сваком пољу је написао један број од $1$ до $MN$, тако да је сваки број написан тачно једном. Он сматра да је једини начин да освоји цео Токио да **баш у $i$-том дану освоји поље на којем је написао број $i$.** Међутим, он је променљивог расположења, па ће $Q$ пута променити бројеве на својој мапи тако што замени бројеве у нека два поља. Ваш задатак је да за сваих $Q+1$ стања мапе (на почетку и после сваког упита) одредите да ли је могуће да Мома испуни свој циљ.

## Опис улаза
У првој линији стандардног улаза налази се три природна броја $N,M,Q$ - димензије Токија и број промена Момине мапе. У $i$-тој од наредних $N$ линија се налази по $M$ природних бројева, где $j$-ти представља вредност $A_{ij}$ - број који стоји на почетку у пољу $(i,j)$ на Моминој мапи. У $i$-тој од наредних $Q$ линија се налазе по $4$ цела броја $xa$, $ya$, $xb$, $yb$ који означавају да ће у $i$-тој промени заменити вредности на пољима $(xa,ya)$ и $(xb,yb)$.

## Опис излаза
На стандардни излаз испишите $Q+1$ линија: у $i$-тој линији треба да пише `DA` ако Мома може да освоји Токио у $i$-том стању мапе, а `NE` у супротном.

## Ограничења
-   $1 \leq N\cdot M\leq 300.000$
-   $1 \leq Q\leq 300.000$
-   $1 \leq A_{ij} \leq NM$
-   Свака вредност од $1$ до $NM$ се појављује тачно једном у низу $A_{ij}$.
- 
Додатно, за сваки од $Q$ упита важи:

-   $1 \leq x_a,x_b \leq N$
-   $1 \leq y_a,y_b \leq M$
-   $(x_a,y_a)\neq(x_b,y_b)$

## Подзадаци
1. (11 поена)  $N=1$, $Q\leq200$
2. (17 поена)  $Q\leq200$
3. (34 поена)  $N=1$
4. (38 поена)  Нема додатних ограничења

## Примери
### Пример 1
#### Улаз
```
3 3 1
1 2 3
4 5 6
7 8 9
1 2 2 2
```

#### Излаз
```
DA
NE
```

#### Објашњење
У почетном изгледу Токија Мома ће у првом дану освојити поље $(1,1)$. Наредних дана ће освајати поља $(1,2)$, $(1,3)$, $(2,1)$, $(2,2)$, $(2,3)$, $(3,1)$, $(3,2)$, $(3,3)$, која су редом суседна пољима $(1,1)$, $(1,2)$, $(1,1)$, $(1,2)$, $(1,3)$, $(2,1)$, $(2,2)$, $(2,3)$, која већ поседује у том тренутку. Међутим, након замене неће моћи после освајања поља означеног са $1$ да у следећем потезу освоји поље означено са $2$.