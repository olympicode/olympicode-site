У овом задатку се од такмичара захтевало да у листи речи пронађе од свих палиндрома који се највише појављују у листи од свих речи онај који је лексикографски најмањи. Задатак се показао као један од тежих из овог сета и само је деветоро такмичара освојило максималан број поена.

Прва ствар коју треба урадити у сваком решењу овог задатка је издвојити палиндроме у посебну листу јер нам речи које нису палиндроми не утичу на решење и само нам повећавају временску сложеност. 

Тест примери су били подељени у три дисјунктне групе.

У првој групи се налазило $20\%$ тест примера и за тест примере из прве групе је важило да је број речи у улазној листи $N \leq 1.000$. За решавање овог подзадатка је било довољно проверити са две петље за фиксиран индекс $1 \leq i \leq N_{pal}$ колико постоји индекса $i \leq j \leq N_{pal}$ таквих да је $Pal[i]=Pal[j]$, где је $Pal$ листа палиндромских речи.  Сложеност овог решења је $O(N_{pal}^2 \cdot L)$, где је $L$ дужина речи са улаза. $L$ по условима задатка није веће од $10$.

У другој се налазило $60\%$ тест примера и за те тест примере је важило $N \leq 50.000$. За решавање ове групе тест примера је било потребно да се закључи да се улазне речи могу сортирати и да ће се онда једнаке речи појављивати једна за другом у листи. Након сортирања речи решење се може пронаћи једним пролазом кроз низ тако што се све речи у узастопном блоку једнаких речи обрађују одједном. Уколико се користи ефикасан алгоритам за сортирање, решење има сложеност $O(N_{pal}\cdot \log(N_{pal}) \cdot L)$.

У последњој групи тест примера се налазило $20\%$ тест примера и за решавање ове групе тест примера је било потребно применити технику хеширања. Можемо приметити да је у претходним решењима у сложености фигурисала дужина речи $L$. Иако је та дужина мала можемо је изоставити тако што ћемо улазне речи хеширати, односно претворити у бројеве. Хеширање речи у бројеве је инјективно пресликавање скупа речи у скуп интегера. Пошто су улазне речи кратке можемо избећи колизију (појаву да две различите речи имају исту хеш вредност, која се дешава при хеширању великих стрингова јер се хеширање мора радити по неком модулу) тако што ћемо користити следећу хеш функцију:
$$
h(s)=(s_0-'a'+1)\cdot 27^{l-1}+(s_1-'a'+1)\cdot 27^{l-2}+\ldots+(s_{n-1}-'a'+1)\cdot 27^0. 
$$
Приметимо да је довољно да хеширамо само половину стринга односно првих $(l+1)/2$ карактера и податак о томе да ли је палиндром парне или непарне дужине пошто су палиндроми симетрични. Након хеширања довољно је да користимо матрицу од $275$ редова и $2$ колоне како би смо пребројали све палиндроме и пронашли решење.

## Generalizacija
Уколико не би постојало ограничење за дужину улазних речи али би постојало ограничење за њихову суму $1 \leq L_i \leq 10^6$ задатак би се могао решити користећи структуру *Trie* која је веома корисна у задацима са стринговима. Више о структури *Trie* можете прочитати на [линку.](http://www.dms.rs/agogeit/data/tekstovi/Trie.pdf)