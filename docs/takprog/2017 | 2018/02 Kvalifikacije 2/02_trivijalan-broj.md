
## Анализа

Свакако најлакши начин да се реши овај задатак јесте да се одреди тривијалност сваког од бројева између $2$ и $N$ ($N$ је број за који се тражи одговор) и након тога одреди број који има најмању тривијалност. При одређивању збира делилаца користимо чињеницу да у пару са сваким делиоцем $d_1 < \sqrt{N}$ иде и делилац $d_2 = \frac{N}{d_1}$. Због тога је довољно само за бројеве између $1$ и $\sqrt{N}$ проверавати да ли деле број $N$ и за сваки број $d<\sqrt{N}$ који дели број $n$ додати збиру делилаца вредност $d + \frac{N}{d}$, ако је $\sqrt{N}$ цео број онда је и $\sqrt{N}$ такође делилац броја $N$ и треба га додати збиру (али са њим у пару не иде други делилац). Према томе, одређивање збира свих делилаца за све бројеве између $2$ и $N$ има сложеност $O(N\sqrt{N})$. Ако то треба да поновимо $T$ пута (за $T$ различитих улазних вредности), онда је укупна сложеност $$O(TN\sqrt{N})$$.

Горње решење можемо профинити тако што би само једном рачунали збир делилаца за бројеве између $2$ и највећег од бројева $A_i$, након тога за сваки појединачни $A_i$, одређујемо број са најмањом тривијалношћу, рачунајући количнике збира делилаца и бројева за одговарајуће бројеве.

Одређивање збира делилаца можемо убрзати користећи чињеницу да су сви бројеви $d, 2d, 3d, 4d, \ldots$ дељиви бројем $d$ и због тога збиру делилаца за те бројеве треба додати број $d$. Према томе за сваку вредност $d=1, 2, 3, \ldots, N$ треба збиру делилаца бројева $d, 2d, 3d, \ldots, kd$ (где је $k$ број са особином да је $kd \leq n < (k+1)d$) додати број тј. делилац $d$. Лако закључујемо да за конкретно $d$ треба ажурирати (увећати) збир делилаца за $\frac{N}{d}$ бројева, па је сложеност одређивања збира делилаца за бројеве између $2$ и $N$ једнака $O(N + \frac{N}{2} + \frac{N}{3} + \ldots + \frac{N}{N}) = O(N\log N)$.

Приметимо да је збир делилаца за просте бројеве $p$ једнак $p+1$ и тривијалност простог броја је једнака $1 + \frac{1}{p}$. С друге стране сваки сложен број $N$ има особину да је збир делилаца већи од $N + \sqrt{N}$, па је тривијалност вeћа од $1 + \frac{1}{\sqrt{N}}$. Намеће се да ће најмању тривијалност у интервалу од $2$ до $N$ имати највећи прост број који није већи од $N$.  Одређивање тог највећег простог броја можемо извести тако што за бројеве $N, N-1, N-2, \ldots$ проверавамо да ли су прости и поступак прекидамо када одредимо први број који јесте прост. Поступак можемо профинити тако што би тестирали (проверавали) само бројеве облика $6k+1$ и $6k+5$ (наравно, изузетак су $2$ и $3$).

Проверу да ли је број прост $N$ изводимо проверававајући да ли има делиоце међу бројевима између $2$ и $\sqrt{N}$. Ако међу њима има бар један делилац онда број $N$ није прост, у супротном јесте.

Поступак провере да ли је број прост можемо убрзати тако што би проверавали да ли број $N$ има делиоце само међу простим бројевима између $2$ и $\sqrt{N}$. Због тога би за почетак требало да одредимо само просте бројеве између $2$ и $\sqrt{N}$ (користећи на пример Ератостеново сито), а затим да тестирамо да ли је неки број прост тако што проверавамо да ли је дељив неким простим бројем које смо претходно издвојили.


