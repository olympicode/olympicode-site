﻿
Можемо поделити град на три дела: део који игноришемо (у примеру доле
обележен са `?`), горњи леви (`A`) и доњи десни "троугао" (`b`):

~~~
AAAAAAAA
AA???bbb
AA???bbb
AAbbbbbb
AAbbbbbb
~~~

За оба троугла ћемо израчунати пар $(m, n)$, где је $m$ број случајева
у најздравијем пољу, а $n$ број таквих поља. Ако смо добили $(m_a,
n_a)$ за горњи леви, а $(m_b, n_b)$ за доњи десни, укупно решење
можемо одредити као:

* $(m_a, n_a)$, ако $m_a < m_b$
* $(m_b, n_b)$, ако $m_a > m_b$
* $(m_a, n_a + n_b)$, ако $m_a = m_b$

Горњи леви троугао можемо посматрати као два преклопљена правоугаоника
са једним теменом у горњем левом углу табле -- на слици, `A` и `a`
(преклапање обележено са `@`):

~~~
@@aaaaaa
AA???...
AA???...
AA......
AA......
~~~

Као и раније, можемо одредити број случајева у најздравијем пољу и
број таквих поља у троуглу "сабирањем" ових решења за два
правоугаоника. У добијеном резултату ће поља обележена са `@` бити
урачуната два пута и морамо елиминсати једно од појављивања -- нека је
$(m,n)$ "збир" правоугаоника $A$ и $a$, а $(m', n')$ обухвата само
`@`. Тада је укупно решење за троугао:

* $(m, n-n')$, ако $m = m'$ (нека од најздравијих поља јесу у `@`)
* $(m, n)$, ако $m \neq m'$ (ниједно од тих поља није у `@`, тако да
  ништа нисмо бројали два пута).

Сада је само потребно да пре упита одредимо ове парове за сваки
правоугаоник са теменом у горњем левом углу матрице. Ово можемо
урадити у $\mathcal{O}(N^2)$: сваки правоугаоник можемо посматрати као
унију доњег десног поља и "троугла", вредност за троугао одредити као
што је горе описано (из претходно израчунатих вредности за мање
правоугаонике) и додати јој доње десно поље.

Исти поступак ћемо користити за доњи десни "троугао", где унапред
одређујемо решења за правоугаонике са теменом у доњем десном углу.
Укупна сложеност је $\mathcal{O}(N^2)$ за израчунавање ових вредности,
и $\mathcal{O}(1)$ по упиту, односно $\mathcal{O}(N^2 + Q)$ за цео
задатак.