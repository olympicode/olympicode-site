﻿##  Решење за $n = 1$
Прво треба приметити да уколико се блок са наградом налази испод нивоа праћке, да се неће уопште померити. Посматрајмо сада случај када је изнад или на њеној висини. У коначном распореду блокова имаћемо серију кула висине $k-1$ и евентуално још једну кулу мање висине. Сада једноставном аритметиком треба одредити тачно у којој кули ће се блок са наградом наћи и на којој висини. Временска сложеност: $O(1)$. Меморијска сложеност: $O(n)$. 

## Решење када су све куле исте висине
Поново, ако је блок са наградом испод висине праћке, остаће ту. Уколико није, можемо посматрати куле са десна на лево и са сваке скинути блокове који су на висини барем $k$, а потом их редом паковати у нове куле које ћемо поставити скроз десно. Временска сложеност: $O(n)$. Меморијска сложеност: $O(n)$.

## Решење за $1 \le n, h_i \le 100$
Када је блок са наградом испод нивоа праћке, неће се померати. Посматрајмо други случај. У овом подзадатку можемо поново ићи са десна на лево и сада за сваку кулу посматрати блокове одоздо на горе, а потом за сваки блок можемо наћи прву кулу на десно на коју може да стане. Временска сложеност: $O(maxh_i \cdot n^3)$. Меморијска сложеност: $О(n^2)$.

## Glavno rešenje
Слично, као у претходним подзадацима, обилазићемо куле са десна на лево. Можемо приметити да када се неки блокови померају на десно, они попуњавају најближа упражњена места на десној страни. Дакле, при обиласку кула, уколико је нека кула низа од праћке(има празних места), можемо је поставити као прву позицију коју ће куле лево попуњавати ако имају вишак блокова. Док, уколико посматрана кула има вишак блокова, можемо попуњавати празна места, све док не искористимо све куле које су вишак. Структура коју можемо користити за ово је *std::stack* у *C++*. Временска сложеност: $O(n)$. Меморијска сложеност: $O(n)$.