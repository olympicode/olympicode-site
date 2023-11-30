##Подзадатак $1$
Јасно да сваки листић можемо посматрати као $K$-точлани подскуп скупа $\{1, 2, 3, …., M\}$, те тако имамо укупно $N$  подскупова са по $K$ елемената ($K$-точланих). Означимо те подскупове са $S_1, S_2, …, S_N$. За свако појединачно извлачење и сваки број $j$ између 1 и $K$ потребно је одредити колико има скупова у низу $S_1, S_2, …, S_N$ који садрже као поскуп скуп састављен од првих $j$ бројева извучених у том извлачењу.

Наивна варијанта се састоји баш од бројања колико има листића (тј. скупова) којима је  скуп састављен од првих $j$ извучених бројева подскуп (тј. колико има скупова-листића који садрже свих $j$ првих извучених бројева). Зависно од имплементације, сложеност овог решења може бити $O(QNK)$ или $O(QNK^2)$.

Свака од напреднијих варијанти подразумева препроцесирање листића тако да се за свако $j\in \{1, 2, ..., К\}$ формирају сви подскупови са тачно $j$ од $К$ извучених бројева. Затим се подскупови исте кардиналности (са истим бројем елемената) смештају у колекцију која ће омогућити ефикасно одређивање колико се пута неки подскуп (са истим бројем елемената) појављује у датој колекцији. Приметимо да је број подскупова са $j$ елемената скупа који има $К$ елемената једнак $\binom{K}{j}$. Тако ће укупан број поскупова са $j$ елемената скупова $S_1, S_2, …, S_N$ бити $N\times\binom{K}{j}$. Укупан број свих подскупова (за све вредности $j$) ће бити $N\times (2^K-1)$.

##Подзадатак $2$
Елементи скупова (тј. извучени бројеви) су бројеви мањи од 100. Подскупови које издвајамо имају највише 3 елемента и елементи сваког подскупа се могу сортирати, а затим посматрати као цифре неког броја у систему са основом 100 (будући да су елементи мањи од 100). Тако ће сваки подскуп бити представљен као највише троцифрен број у систему са основом 100, односно сваки скуп може бити представљен помоћу броја који је мањи од милион. Захваљујући томе могу се избројати појављивања сваког подскупа и запамитити у низу дужине 1000000 (тј. са милион елемената).

##Подзадатак $3$
У подзадатку три се скупови опет могу представити помоћу бројева у систему са основом 100 али како у подзадатку 3 број $К$ може имати вредност 5, то ће бити највише потоцифрени бројеви и њихова вредност је ограничена са 10 милијарди. Овај пут не можемо применити обично бројање, већ формирамо низове са бројевима који представљају скупове. Низове можемо сортирати и на крају једним пролазом избројати број појављивања сваке вредности (тј. сваког подскупа). При одговарању на упите подскуп који се састоји од $j$ првих извучених бројева представимо као број (на исти начин као и подскупове оформљене од листића) и бинарном претрагом проналазимо у низу бројева који представљају подскупове листића. 

##Подзадатак $4$
У подзадатку четири максимални број извучених бројева, као и максимална вредност извучених бројева су такви да се подскупови са више елемената не могу репрезентовати помоћу целобројних типова подржаних у језицима који се користе за такмичење. Због тога је потребно подскупове представити на неки други начин. Један од начина је структура која садржи број елемената у подскупу и елементе подскупа смештене у низ који је сортиран. Над тако репрезентованим подскуповима можемо дефинисати поређење (уобичајено лексикографско поређење). Користећи то поређење можемо сорирати низове који садрже све подскупове са истим бројем елемената. Након тога бројање колико пута се неки подскуп $P$ појављује у низу обављамо варијацијом бинарне претраге у којој прво одређујемо део низа са подскуповима у коме се први елемент поклапа са првим елементом подскупа $P$, затим у тако издвојеном поднизу (одређен је почетним и крајњим елементом подниза) део у коме се други елемент поклапа са другим елементом подскупа $P$, итд. Поступак прекидамо када исцрпимо све елементе подскупа $P$, након чега је број подскупова једнак дужини издвојеног подниза, или када подниз у коме се елементи могу поклапати са подскупом $P$ постане празан (тада је одговор нула).

##главно решење
Последњи подзадатак може бити решен и тако што се подскупови смештају у хеш табелу, при чему у току додавања истовремено бројимо колико се пута појављују подскупови. Након тога одговарање на упите се своди на проналажење одговарајућих скупова у хеш табели и издвајању информације колико пута се тај подскуп налази у хеш табели.

Показало се да максимум поена може бити освојен и тако што се сваким извученим бројем у једном конкретном извлачењу издвоје само листићи који садрже све до тог тренутка извучене бројеве. Број издвојених листића је одговор за конкретно извлачење и конкретан број извучених бројева. Када се након тога обрађује следећи извучени број, анализирају се само листићи који су издвојени и од њих издвајају само они који садрже извучени број. Уз пажљиву имплементацију добија се решење које се извршава у предвиђеном времену.