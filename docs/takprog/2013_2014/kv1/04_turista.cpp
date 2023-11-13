#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string>
using namespace std;

int cnt[27*27*27*27*27][2];

int main() {

    int n,l,k,i,j,t1,t2,bb,resbr;
    string ps,res;
    char s[15];

    res = "";
    resbr = 0;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%s", &s);
        l=strlen(s);
        k=(l+1)/2;
        t2=l&1;
        t1=0;
        bb=1;
        for(j=0; j<k; j++) {
            t1 = t1*27 + (tolower(s[j]) - 'a' + 1);
            s[j] = tolower(s[j]);
            s[l-1-j] = tolower(s[l-1-j]);
            if (s[j] != s[l-1-j]) bb=0;
        }

        if (bb) {
            if( ++cnt[t1][t2] > resbr ) {
                resbr = cnt[t1][t2];
                res = string(s);
            } else if (cnt[t1][t2] == resbr) {
                ps = string(s);
                if (ps < res) {
                    res = ps;
                }
            }
        }
    }

    printf("%s\n", res.c_str());

    return 0;
}
