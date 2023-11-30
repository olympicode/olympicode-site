Ако оптимално тргујемо струјом, сигурно ћемо сваког дана или "чекати" (без куповине и продаје), или потрошити сав новац на струју, или продати сву струју коју имамо. Ово тврђење неће бити формално доказано овде, али идеја иза њега је да ако "раздвојимо" новац (или струју) и потрошимо само део, потрошен и сачуван део се могу посматрати независно. Ако потрошен део новца доноси бољу зараду од непотрошеног, боље је да потрошимо све (и обрнуто).

Сада је потребно само одабрати дане када ћемо куповати и продавати струју. Оптималан избор је да купујемо у локалним минимумима цене, односно данима када је струја јефтинија него што је била јуче и него што ће бити сутра, и да продајемо у локалним максимумима (кад је скупља од суседних дана). Да бисмо доказали да је ово оптимално, посматрајмо било који други избор дана. Тада сигурно можемо "померити" ону куповину (или продају) која није локални минимум (максимум) на "суседни" дан када је цена повољнија и зарадити више.

Локалне минимуме и максимуме можемо наћи у $\mathcal{O}(N)$ (за сваки дан гледамо само два суседа), тако да се цео задатак може решити у $\mathcal{O}(N)$. Обратите пажњу на први и последњи дан -- пошто имају само једног суседа, можемо их или посматрати као специјалне случајеве, или додати "вештачке" елементе за дане $0$ и $N+1$, са ценама $\infty$ и $-\infty$.

Нешто једноставније решење за имплементацију је следеће: за сваки дан можемо одлучити да ли ћемо тог дана купити струју и одмах је продати следећег дана. У овом случају дозвољавамо да исти дан продамо струју и опет је купимо по истој цени (што је исто као да не урадимо ништа). Јасно је да ћемо у овом случају куповати оних дана када је цена мања него следећег, тако да можемо избећи "памћење" минимума и максимума.