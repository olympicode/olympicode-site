## Анализа

Једна од кључних ставки у задатку јесте гаранција да без избацивања, односно уништења неког узастопног подниза није могуће поделити задати низ тако да су му подзбирови неког префикса и остатка низа једнаки. Такође, поставка задатка условљава да су сви чланови улазног низа строго позитивни, што уз пажљиво решавање поједностављује комплексност коришћеног алгоритма претраге.

Најпре, нека је збир свих чланова задатог низа $z$, а збир чланова неког његовог префикса (односно суфикса) $p$. Неопходно је одредити неки непразан подниз улазног низа који не обухвата префикс (односно суфикс), такав да ако збир његових чланова означимо са $s$, мора бити задовољен услов $z = p + s + p = 2p + s$. Другим речима, збир чланова подниза који се уништава $0<s<z$, мора бити једнак укупној суми свих чланова изворног низа умањеној за двоструку вредност префикса, $s=z-2p$.

Сада је потребно извршити претрагу по свим префиксима (односно суфиксима) и свим узастопним поднизовима улазног низа и проверити да ли је могуће задовољити малопређашњу једнакост. Уколико би та претрага наивно била извршена кроз три независне петље (прва по префиксима низа, а друга и трећа по левој и десној граници подниза за уништење), добила би се кубна временска сложеност $\mathcal{O}(N^3)$ по дужини низа. Међутим, уз нешто вештију претрагу по левој и десној граници узастопног подниза ту сложеност могуће је и умањити.

## Смернице за алгоритам

Наиме, на почетку итерације по префиксима (односно суфиксима) иницијализовати леву и десну границу на први суседни члан префикса (односно суфикса). У свакој итерацији неопходно је испитати да ли је вредност израза $z - 2p - s$ већа, мања или једнака нули, те ако је већа, померати десну границу, а уколико је мања, померати леву. Претрага се завршава или када израз поприми вредност нула након чега следи испис утврђених граница подниза, или када лева и десна граница дођу до краја изворног низа, када се прелази на следећи префикс (односно суфикс). Пошто приликом напредовања граница мора бити задовољен и услов да индекс леве границе није виши од индекса десне, то је укупна сложеност ове унутрашње петље линеарна $\mathcal{O}(N)$ по дужини низа. Како је неопходно претрагу урадити за све префиксе и суфиксе изворног низа (због асиметрије претраге), то је укупна сложеност овог алгоритма квадратна $\mathcal{O}(N^2)$, што се и захтевало за максималан број поена у овом задатку.