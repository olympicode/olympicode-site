﻿

## Анализа
Приметимо да ако смо изградили ограду чије је горње лево поље $(x,y)$, а доње десно је $(z,t)$ мора да важи $x\leq a\leq z$ и $y\leq b\leq t$ да би садржало поље које садржи кућу. Такође видимо да је у том случају обим подматрице управо $2\cdot(z+t-x-y)+4$. Сада видимо да треба да максмизирамо вредност $C_{xy}+C_{zt}+2\cdot(z+t-x-y)+4$, за $x\leq a\leq z$ и $y\leq b\leq t$. Простом провером по свим четворкама даје лако $O((NM)^2)$.
Да би се ово даље оптимизовало, извршићемо замену редоследа сабирака: треба да максимизизирамо израз $(C_{xy}-2\cdot x-2\cdot y)+(C_{zt}+2\cdot z+2\cdot t)+4$. Означимо $G_{xy}=C_{xy}-2\cdot x-2\cdot y$ и $H_{zt}=C_{zt}+2\cdot z+2\cdot t$. Сада видимо да тражимо максимум $G_{xy}+H_{zt}+4$, при чему важи $x\leq a\leq z$, $y\leq b \leq t$ и сабирци $G_{xy}$ и $H_{zt}$ су потпуно независни. Стога можемо да нађемо максимум $G_{xy}$ под условом $x\leq a, y\leq b$ (нека је овај максимум $M_1$) и максимум $H_{zt}$ по условом $z\geq a, t\geq b$ (нека је овај максимум $M_2$), и затим испишемо решење $M_1+M_2+4$. Рачунање матрица $G$ и $H$, као и тражење $M_1$ и $M_2$ се раде лаком претрагом у $O(NM)$.
