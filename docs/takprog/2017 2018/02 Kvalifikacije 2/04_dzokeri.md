## Анализа

Приметимо најпре да је задатак за случај $x = y = 0$ једнак проблему Најдужи Заједничи Подниз (енгл. Longest Common Subsequence; скр. LCS). Уз врло једноставну измену, алгоритам за LCS може такође решити варијанту овог задатка за случај $x = 0$. Дакле, права тежина задатка лежи у случају када $x \neq 0$. У наставку ћемо се најпре укратко подсетити алгоритма за LCS и показати како се једноставном изменом може искористити да реши овај задатак за случај $x = 0$. Потом ћемо описати како се тај алгоритам може проширити тако да реши овај задатак у општем случају, тј. чак и када $x \neq 0$.

Стандардни LCS алгоритам дефинише низ $dp[i][j]$ који представља LCS за стрингове $A^i$ и $B^j$, где $A^i$ ($B^j$) означава суфикс стринга $A$ ($B$) од позиције $i$ ($j$). Тада, $dp[i][j]$ дефинишемо као: $dp[i][j] = \max\{dp[i + 1][j], dp[i][j + 1], eq_{i, j}\}$, где у случају да $А[i] = B[j]$ имамо $eq_{i, j} = dp[i + 1][j + 1] + 1$, а иначе $eq_{i, j} = -\infty$.

Да бисмо решили овај задатак у случају када $x = 0$, довољно је да дефинишемо $dp[i][j]$ на само мало другачији начин, наиме $dp[i][j] = \max\{dp[i + 1][j] - y, dp[i][j + 1] - y, eq_{i, j}\}$, где је $eq_{i, j}$ дефинисано као и пре.

Посматрајмо сада случај $x \neq 0$. Прво, у дефиницији $dp[i][j]$ имамо, између осталог, вредност $dp[i + 1][j] - y$ која се може интепретирати на следећи начин: убацимо џокер испод карактера $А[i]$, што има цену $y$, и пронађимо LCS за $A^{i + 1}$ и $B^j$. Када $x \neq 0$, треба ли цена и даље да буде само $y$ или ипак треба да буде $x + y$? То зависи од тога да ли је и испод $A[i - 1]$ био џокер или није. Ако је испод био џокер, онда је цена само $y$ (јер не почињемо нову операцију), а ако није био џокер онда је цена $x + y$ (јер почињемо нову операцију). Сада је јасно како проширити алгоритам за LCS да реши овај задатак -- поред индекса $i$ и $j$, требало би памтити још два индикатора (тј. две променњиве где свака има вредност $0$ или $1$) које означавају да ли је испод $A[i - 1]$, тј. изнад $B[j - 1]$, био уметнут џокер или није.

## Смернице за алгоритам
Рецимо да желимо да израчунамо $dp[i][j][ind1][ind2]$, где су $ind1$ и $ind2$ као што је описано изнад. У смерницама датим испод, претпостављамо да су стрингови $A$ и $B$ индексирани од $0$. Ради једноставности, нека $ret$ представља вредност коју желимо да израчунамо. Тада имамо

<pre>
Ако ако $i == length(A)$ и $j == length(B)$:
  $ret = 0$
Иначе, ако је $i == length(A)$:
  $ret = -x * (1 - ind2) - y * (length(B) - j)$
Иначе, ако је $j == length(B)$:
  $ret = -x * (1 - ind1) - y * (length(A) - i)$
Иначе:
  Ако је $A[i] == B[j]$:
    $ret = \max\{dp[i][j + 1][0][1] - x * (1 - ind2) - y, dp[i + 1][j][1][0] - x * (1 - ind1) - y, dp[i + 1][j + 1][0][0] + 1\}$
  Иначе:
    $ret = \max\{dp[i][j + 1][0][1] - x * (1 - ind2) - y, dp[i + 1][j][1][0] - x * (1 - ind1) - y\}$
</pre>