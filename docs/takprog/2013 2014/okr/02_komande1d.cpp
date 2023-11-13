#include <stdio.h>

char s[500555];

int main() {

    int n,x,k,i,R,L,P,oL,oR,tt;

    for(tt=0; tt<3; tt++) {
        scanf("%d%d%d", &n, &x, &k);
        scanf("%s", &s);

        R = 0; L = 0;
        for(i=0; i<n; i++) {
            if (s[i] == 'R') R++;
            else L++;
        }

        P = R - L;
        oL = 0; oR = 0;
        if (P < x) {
            oL = x - P;
            k -= oL;
        } else {
            oR = P - x;
            k -= oR;
        }

        if (k < 0 || k%2 == 1) {
            printf("-1\n");
            continue;
        }

        oL += k/2;
        oR += k/2;

        if (oL > L || oR > R) {
            printf("-1\n");
            continue;
        }

        for(i=0; i<n; i++) {
            if (s[i] == 'R' && oR > 0) {
                printf("%d ", i+1);
                oR--;
            }

            if (s[i] == 'L' && oL > 0) {
                printf("%d ", i+1);
                oL--;
            }
        }
    }

    return 0;
}
