## Први потпроблем

Овај потпроблем нас пита да нађемо збир збирова сваког подниза низа $A$, што можемо урадити итерирањем по сваком поднизу, рачунајући збир користећи низ префиксних сума. Сложеност овог алгоритма је $\mathcal{O}(N^2)$, што је довољно добро.

## Други потпроблем

Чистом симулацијом израчунавања функције $f$, на начин описан у тексту задатка, можемо у експоненцијалном времену урадити овај потпроблем.

## Остали потпроблеми

Можемо лако уочити да ће вредност функције $f(A, k)$ бити једнако изразу $\sum_{i=1}^{n} c_i \cdot A_i$ за неки низ коефицијената $c$ -- хајде да видимо колики су ти коефицијенти. Коефицијент уз $A_i$ ће бити једнак броју финалних поднизова у којима се појављује тај елемент. 

Скуп свих подниза чији ће се збирови сабирати у фазама када је $k = 0$ у којима се садржи елемент $A_i$ је у бијекцији са скупом парова низова $l$ и $r$ од $k$ елемената, за које важи $1 \leq l_1 \leq l_2 \leq \dots \leq l_k \leq i \leq r_k \leq r_{k-1} \leq \dots \leq r_1 \leq n$. Ово лако можемо проверити тако што посматрамо да је тај подниз у првој фази био подниз низа $A[1..n] = A$, у другој подниз низа $A[l_1 .. r_1]$, итд. Такође, приметимо да су низови $l$ и $r$ на неки начин независни, број оваквих парова низова $(l, r)$ је једнак производу броја адекватних $l$ и $r$ низова.

Треба да израчунамо колико оваквих поднизова постоји (симетрично рачунамо за $l$ и $r$ низове). Рачунајући за $l$ низове прво, увођењем $d_i = l_i - l_{i-1}$ (уз $l_0 = 1$), можемо видети да низова $l$ има колико и решења једначине $d_1 + d_2 + \cdots + d_k = i - 1$ (где $d_i \geq 0$), чији је број решења ${k + i - 1 \choose k}$. 

Користећи сличну анализу за број низова $r$, добијамо да је $c_i = {k + i - 1 \choose k} \cdot {k + n - i \choose k}$. Све што нам остаје је да израчунамо ове биномне коефицијенте.

### Подзадаци 3 и 4

Све биномне коефицијенте можемо израчунати користећи Паскалов троугао, и укупна временска сложеност је $O(N^2)$.

### Подзадатак 5

Овде морамо користити бржи начин израчунавања биномних коефицијената, користећи сегментно стабло над простим чиниоцима. Алтернативно, можемо прекалкулисати факторијеле и рачунати биномне коефицијенте дељењем, користећи модуларни инверз.