﻿
## Анализа

Најједноставније решење је за сваке три тачке проверити да ли формирају троокругао полупречника $R$ - све што нам треба су координате центра описане кружнице. Ако су координате темена троугла $(x_1, y_1)$, $(x_2, y_2)$ и $(x_3, y_3)$ а координате центра $(x_c, y_c)$, тада изједначавањем растојања добијамо:
$(x_1-x_c)^2 + (y_1 - y_c)^2 = (x_2-x_c)^2 + (y_2 - y_c)^2$
$(x_1-x_c)^2 + (y_1 - y_c)^2 = (x_3-x_c)^2 + (y_3 - y_c)^2$
Након сређивања се губе квадрати уз $x_c$ и $y_c$ па добијамо само две линеарне једначине са две непознате. Уколико су решења целобројна и полупречник је $R$, повећамо решење за $1$. Сложеност алгоритма је $O(N^3)$ и решава **подзадатак 1**.

Скуп $C$ свих могућих центара описаних кружница тражених троокруглова можемо добити тако што за сваке две тачке $A$ и $B$ одредимо (највише) 2 друге тачке које су и од $A$ и од $B$ удаљене тачно $R$ и, уколико су целобројне, убацимо их у поменути скуп. Рачун за координте те две тачке је аналоган као у решењу подзадатка 1 (користмо и $R$ овог пута) а могу се одредити и бинарном претрагом по симетрали дужи $AB$. Уколико се у скупу $C$ нека тачка $T$ јавља $a$ пута, то значи да је на кружници полупречника $R$ описаној око $T$ тачно $b$ тачака, где је $a = \frac{b(b-1)}{2}$ јер смо сваки пар бројали тачно једном. Сваке 3 од тих $b$ тачака формирају тражени троокругао па решењу треба додати $\binom{b}{3}$ за сваку тачку $T$ из $C$. Бројање појављивања сваке тачке је најлакше урадити сортирањем скупа $S$; како он садржи $O(N^2)$ могућих центара, сложеност алгоритма је $O(N^2 \log N)$ и решава **подзадатке 1 и 2**.

Ако је $R = 1$, задатак се своди на "колико једнакокрако-правоуглих троуглова са хипотенузом дужине $2$ има међу датим тачкама?". Ово се може решити провером за сваку од $N$ тачака да ли је теме правог угла таквог троугла - нпр. ако проверавамо да ли постоји такав троугао чије је теме правог угла "надоле" и у тачки $(x, y)$, треба испитати да ли се тачке $(x-1, y+1)$ и $(x+1, y+1)$ налазе међу датих $N$ тачака. Уколико на почетку соритрамо тачке, ово испитивање можемо одрадити у $O(\log N)$ преко бинарне претраге (може и преко неких других структура, нпр. C++ мапа). Сложеност овог приступа је $O(N \log N)$ и решава **подзадатак 3**.

Означимо са $minVal$ и $maxVal$ најмање и највеће координате датих тачака. Центар описане кружнице траженог троокругла може бити само у делу координатне равни ограничен са $[minVal - R, maxVal + R] \times [minVal - R, maxVal + R]$. За сваку тачку из ове области можемо израчунати колико се датих тачака налази на растојању $R$ од ње (ако их има $a$, тада има $\binom{a}{3}$ троокруглова чији је центар описаног круга ова тачка) испитивањем свих $O(R)$ кандидата (провера у сложености $O(1)$ јер су координате мале и можемо маркирати тачке у матрици). Укупна сложеност овог алгоритма је $O((maxVal - minVal + 2R)^2 \cdot R)$ и решава **подзадатак 4**. 

Означимо са $f(R)$ број целобројних тачака које се налазе на кружници полупречника $R$ чији је центар у некој целобројној тачки. Нпр. $f(1) = f(2) = f(3) = f(4) = 4$, $f(5) = 12$, итд. (приметимо да није битно у којој целобројној тачки је центар). $f(R)$ је заправо број целобројних решења једначине $x^2 + y^2 =R^2$ и сва та решења можемо пронаћи у сложености $O(R)$ нпр. испробавањем свих могућности за $x$. Ово израчунамо на почетку и означимо скуп тих решења са $\{(x_i,y_i), (x_2, y_2), \ldots, (x_{f(R)}, y_{f(R)}\}$. 
Уколико око сваке од $N$ тачака опишемо кружницу полупречника $R$ и све целобројне тачке са те кружнице (за тачку $(x,y)$ тих $f(R)$ целобројних тачака су $(x+x_i, y+y_i)$, $i = \overline{1, f(R)}$) сместимо у један скуп (низ) $C$ (величине $N \cdot f(R)$), тада је $C$  скуп свих потенцијалних центара тражених троокруглова јер сваки такав центар мора бити на растојању $R$ од бар једне од $N$ тачака. Уколико се $C$ састоји од $M$ различитих тачака од којих се $i$-та појављује $a_i$ пута, укупно решење је $\binom{a_1}{3} + \binom{a_2}{3} + \ldots + \binom{a_M}{3}$. Број понављања сваке тачке можемо израчунати сортирањем низа $C$ и бројањем узастопних истих елемената. Зависно од тога да ли користимо QuickSort или CountingSort (прво по $x$ па по $y$), сложеност алгоритма је $O(N\cdot f(R) \cdot \log(N\cdot f(R)))$ или $O(N \cdot f(R))$.

Кључна ствар коју треба уочити је да су вредности $f(R)$ "довољно мале" за дата ограничења - испоставља се да је за  $f(R) \leq 324$ за свако $1\leq R\leq 10^5$. Ово је интуитивно (обично нема баш пуно целобројних тачака на описаним кружницама) а могло се и лако проверити за време такмичења: уколико такмичар (на локалној машини) израчуна $f(R)$ за свако $R$ до $10^5$ у укупној сложености $O(R^2)$, добиће тражени резултат за 2-3 минута. Дакле, последњи описани алгоритам заиста **решава цео задатак** у задатом временском ограничењу.