## Решења за мале примере

Ако је дужина стринга $26$, потребно је једноставно проверити да је задати стринг заиста сачињен од свих слова 'A' до 'Z' у растућем поретку. Када је дужина $27$, исти услов треба да је испуњен када се избаци једно слово.

## Квадратно решење

Проблем можемо посматрати као пребројавање (не нужно узастопних) поднизова задатог натписа који чине растући низ слова од А до Z. Могући приступ јесте посматрати једноставнији потпроблем који се састоји од пребројавања краћих растућих поднизова који се завршавају неким словом. Нека $dp_{i, j}$ представља број растућих поднизова који се завршавају на позицији $i$ и који су дужине $j$.

Број поднизова који се завршавају на позицији $i$ и имају дужину $1$ је $1$ ако је слово на тој позицији у натпису A и $0$ у супротном. Ако претпоставимо да знамо решење за све позиције пре тренутне, лако можемо израчунати $dp$ вредности за тренутну позицију. Наиме, $dp_{i, j}$ је $0$ за свако $j$ сем за редни број слова који је на $i$-том месту у натпису. За ово $j$ потребно је пребројати све натписе дужине $j-1$ који се завршавају пре позиције $i$. Другим речима $dp_{i, j} = \sum_{1\le k <i}dp_{k, j-1}$. Коначно решење је сума свих секвенци које су дужине 26, односно $\sum_{1\le i \le n}dp_{i, 26}$.

## Решење у линеарном времену

Претходно решење можемо оптимизовати чувањем сумe свих претходних вредности. Вредности у табели биле би одређене на следећи начин.

$$
dp_{i, j} =  
\begin{cases}
dp_{i-1, j} + dp_{i-1, j-1}, & \text{ако је на $i$-тој позицији $j$-то слово алфабета}\\
dp_{i-1, j}, & \text{у супротном само преписујемо претходну вредност}
\end{cases}
$$

Оваква табела може се одржавати у линеарном времену. Приметимо на крају да пошто увек испитујемо само претходно поље, меморију можемо смањити коришћењем само једног низа дужине 26.