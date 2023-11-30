﻿## Решење
Користећи $N-1$ позив функцији нађимо растојање од тачке $0$ до свих осталих тачака. Тачка која је најближа тачки $0$ мора јој бити суседна, без умањења општости, рећи ћемо да је то тачка $1$. Користећи још $N-2$ позива функцији нађимо растојање свих тачака (сем $0$ и $1$) од тачке $1$. 

Сада круг можемо поделити у две групе: на оне тачке које су ближе тачки $0$ и оне које су ближе тачки $1$. Те тачке сада можемо сортирати по растојању од своје одговарајуће тачке, и самим тим, наћи редослед тачака на кругу. Такође, знамо растојање сваке две суседне тачке, сем за један пар: тачку из прве групе која је најдаља од тачке $1$ (назовимо ову тачку $A$ за даље потребе) и тачку из друге групе која је најдаља од тачке $1$ (назовимо ову тачку $B$ за даље потребе). За тај пар ћемо искористити још један позив функцији, тако да смо укупно искористили $2N-2$ позива. 

Најмање растојање ће сигурно бити једно од растојања суседних тачака, тако да то већ можемо да израчунамо. За највеће растојање нам је потребно још обзервација. Потребно је да нађемо обим круга. 

Уколико се тачке не налазе све на истом полукругу, обим је једнак $Rastojanje(0, 1)$+$Rastojanje(0, A)$+$Rastojanje(1, A)$+$Rastojanje(A, B)$ (за ово не морамо позивати функцију, сва ова растојања већ имамо). Уколико се налазе, можемо претпоставити да је $Rastojanje(A, B)$ полуобим, чиме не кваримо ниједно растојање (ово није неопходно, остатак решења можемо посматрати кроз два случаја, али је овако лакше за имплементацију).  

Сада када имамо обим, можемо да нађемо растојање између било које две тачке без да позивамо нашу функцију. За сваку тачку из прве групе можемо бинарном или тернарном претрагом наћи најдаљу тачку у сложености $O(logN)$,  и за крај узмемо најдаљи пар. 
