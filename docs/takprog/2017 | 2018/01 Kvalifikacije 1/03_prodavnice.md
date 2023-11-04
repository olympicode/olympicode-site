## Анализа

Јасно је да је за сваки упит $(A, B)$ потребно израчунати вредност израза $\sum_{i=1}^n \min(|x_i - A|, |x_i - B|)$ тј. суму растојања до најближе продавнице. Директно рачунање ове суме за сваки упит даје решење сложености $O(nm)$ што је довољно само за 20 поена.

Посматрајмо случај када увек важи $A_i = B_i$ тј. када је потребно израчунати $\sum_{i=1}^n |x_i - A|$. За почетак, природан корак је сортирање низа $x$ -- надаље претпостављамо да је $x_1 \leq x_2 \leq \ldots \leq x_n$. За дату вредност $A$ можемо бинарном претрагом у сложености $O(\log n)$ одредити највећу вредност $ind$ за коју важи $x_{ind} < A$ (или установити да таква вредност не постоји ако је $A \leq x_1$). Сада важи
$$\sum_{i=1}^n |x_i - A| = \sum_{i = 1}^{ind} (A - x_i) + \sum_{i=ind+1}^n (x_i - A) = ind \cdot A - s_{ind} + (s_n - s_{ind}) - (n - ind)\cdot A$$
где је $s$ низ *префиксних сума* низа $x$, тј. $s_i = x_1 + x_2 + \ldots + x_i$. Према томе, уколико на почетку (пре свих упита) сортирамо низ $x$ и израчунамо низ префиксних сума, можемо за сваки упит одрадити бинарну претрагу и вратити резултат из претходне једначине (без сумирања). Сложеност овог приступа је $O(n \log n + m \log n)$.

Претходни алгоритам се једноставно модификује и у случају када је $A_i \neq B_i$. У том случају, за упит $(A, B)$ (нпр. нека је $A < B$) бинарном претрагом пронађемо највећу вредност $mid$ за коју важи $x_{mid} < \frac{A+B}{2}$; то значи да ће сви становници са координатама $x_1, x_2, \ldots, x_{mid}$ ићи у продавницу $A$ а становници са координатама $x_{mid+1}, x_{mid+2}, \ldots, x_n$ у продавницу $B$. Затим два пута применимо претходни алгоритам, једном за подниз $x[1, mid]$ и вредност $A$, а други пут за подниз $x[mid+1, n]$ и вредност $B$.

За додатне подзадатке је такође предвиђен овај алгоритам али је за њих довољна потенцијално лакша имеплементација и мања анализа специјалних случајева о којима треба водити рачуна приликом имплементације решења за $100$ поена -- нпр. када су вредности $A$ или $B$ или $\frac{A+B}{2}$ лево или десно од низа $x$ (нпр. када сви иду у само једну продавницу). Ово се у потпуности може заобићи паметно дизајнираном функцијом за поменуту бинарну претрагу.