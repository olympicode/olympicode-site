﻿## Општа опажања
Рецимо да нам је позната вредност $S$ i желимо да израчунамо $C$. Касније ћемо решити и обрнут проблем.

Прво што треба да схватимо је да никада неће два кабла ићи један преко другог. То можемо да докажемо преко контрадикције. Претпоставимо супротно, да је оптимално да на неком месту имамо два кабла који иду један преко другог. Нека су њихови почеци и крајеви редом ($a_1$,$b_1$) и ($a_2$,$b_2$). Цена одржавања тих каблова сигурно није мања од цена одржавања кабла ($min(a_1,a_2)$, $max(b_1,b_2)$), а тај кабл прекрива све куће које прекрива барем један од ова два кабла.

Такође је важно уочити да никада није оптимално имати кабл који не прелази преко ни једне куће, пошто његово склањање смањује цену, а услов је још увек испуњен. 

Нека група бандера представља подниз узастопних бандера тако да између њих нема кућа, а директно лево и директно десно од ње је кућа, или уопште нема ни кућа ни бандера. Потребани и довољни услови за покривање свих кућа кабловима су: 

 - Не постоје два кабла чији се интервали пресецају.
 - У свакој групи бандера нити почиње, нити се завршава неки кабл, или почиње и завршава се тачно један кабл.
 - Прва и последња група су изузетак од претходног правила, у њима почиње, односно завршава тачно један кабл.

Након што смо поделили бандере у групе, нас је баш брига где се налазе куће. Сада желимо да израчунамо вредност $dp[i]$ што је минимална цена да се услов испуни за префикс бандера дужине $i$.

Прво ћемо схватити да $dp[i]$ не може да буде већи од било ког $dp[j]$ где је $j \le i$ и бандере са индексима $i$ и $j$ су у истој групи, пошто ми можемо само кабл да спојимо са бандером $j$ и бандере после ње да игноришемо. 

Сада ћемо претпоставити да је оптимално да бандеру $i$ спајамо са неком бандером $j$. Важно је да те две бандере нису у истој групи, да $j$ нема кућу директно са леве стране и да $i$ нема кућу директно са десне стране, као и да бандере $i$ и $j$ нису на већој удаљеноти од $D$. Уколико то важи, онда је $dp[i]= a_i \cdot S + c_i + dp[j-1] + c_j - a_j\cdot S$.

Користећу формулу горе можемо да израчунамо $dp[i]$ за све вредности $i$, уз специјалан случај да је $dp$ у првој групи једнако 0.

Сада смо нашли за $S$ вредност $C$, како обрунуто? Важно је схватити да важи $S \le C$ пошто постоји барем једна кућа. То значи да ми можемо да тражимо вредност $S$ такву да је вредност оптималног постављања једнака $C$.

Предлажемо да се решења за подзадатке читају редом пошто је у питању само оптимизација горе описаног решења.

## Решење за $n,m,C \le 100$
У овом подзадатку је довољно да имплементирамо метод описан горе. Разпоређивање у групе можемо да прекалкулишемо грубом силом, након тога можемо радити линеарну претрагу по $S$ и користити $n^2$ dp. Временска сложеност овог решења је $O(MN + CN^2)$.

## Решење за $n\le 1000$
У овом подзатаку уместо да радимо грубу силу како бисмо распоредили бандере у групе, можемо да користимо технику два показивача.

Такође, приметимо да је функција $C(S)$ растућа, тако да ми можемо бинарно претраживати вредност $S$.

Једини спор део овог приступа је само динамичко програмирање чија је сложеност $O(n^2)$. 

Укупна временска сложеност је $O(m+n+n^2 log C)$.

## Решење за $D=10^9$
Нека низ $a_i$ означава позицију $i$-те бандере на $x$ оси.

У овом подзатаку не морамо да се бринемо око тога колико је дугачак кабл. Дефинисаћемо $b[i]=dp[i-1] + c_i - a_i\cdot S$. Сада је формула за спајање бандере $i$ са бандером $j$: $$a_i\cdot S +c_i + b_j$$
Сада само за свако $i$ морамо да памтимо најбољи претходни $b_j$ (наравно, такав да важе претходно помену ти услови). Пошто је дужина кабла неограничена, то можемо да чувамо у једној променљивој максимума. 

Што се тиче најбоље вредности $dp$ у групи, то исто можемо да радимо преко променљиве. Временска сложеност је $O(M+N+Nlog C).$

## Главно решење

Најмање $j$ које можемо узети можемо да чувамо преко једног показивача који ћемо да померамо како идемо кроз $i$. Сада на неки начин морамо да динамички убацујемо и избацујемо елементе од којих тражимо минимум. За то можемо користити структуру података "set". Временска сложеност је $О(N+M + N \cdot log N \cdot log C).$

Решење које уместо сета користи коренску декомпозицију је покривено подзадатком где је $N\le 50.000$. 