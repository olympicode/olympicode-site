﻿## Решење за $m = 1$:
Оно што треба приметити јесте да операцију којом пребацујемо све куглице једне групе на одређену позицију има смисла радити само на почетку и то максимално једном, јер било која операција која се одради пре такве операције не би имала утицај на крајњи резултат. Дакле, можемо да уопште не користимо ту операцију, или да све куглице пребацимо у неку од десет група, па онда оне које не треба да буду ту, пребацимо у одговарајуће групе помоћу друге операције. Као решење треба изабрати најјефтинију опцију. Временска сложеност: $O(N \cdot maxC)$, где је $maxC$ број цифара, меморијска сложеност: $O(N)$.

## Решење када сваку од група чини блок узастопних куглица:
С тим да куглице из различитих група не можемо померати у истој операцији, треба сваку групу посебно решити, па ће коначно решење бити сума решења за сваку од група. У овом подзадатку можемо једноставно издвојити групе с тим да су то узастопне куглице и након тога за сваку групу применити идеју из првог подзадатка. Временска  сложеност: $O(N \cdot maxC)$, меморијска сложеност: $O(N)$.  

## Главно решење:
Разлика у односу на претходни подзадатак је у томе што овде прво треба одвојити куглице по групама. Можемо да за сваку групу изградимо низ куглица које се налазе у њој и након тога треба применити идеју из претходног подзадатка. Временска сложеност: $O(N \cdot maxC)$, меморијска сложеност: $O(N)$