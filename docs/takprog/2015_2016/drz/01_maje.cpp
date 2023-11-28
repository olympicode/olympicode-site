#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 1000005;

int n;
char a[MAX_N][10];

int get_num(char str[10], int sep) {
    int ret = 0;
    int cnt = strlen(str);
    for (int i = sep; i < cnt; ++i)
        ret = ret * 10 + (str[i] - '0');
    for (int i = 0; i < sep; ++i)
        ret = ret * 10 + (str[i] - '0');
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &a[i]);
    }

    bool ok = true;
    int cnt = strlen(a[0]);
    int lastNum = get_num(a[0], 0);
    for (int i = 1; i < cnt; ++i)
        lastNum = min(lastNum, get_num(a[0], i));

    for (int i = 1; i < n; ++i) {
        cnt = strlen(a[i]);
        int minNum = -1;
        for (int j = 0; j < cnt; ++j) {
            int tmp = get_num(a[i], j);
            if (tmp >= lastNum) {
                if (minNum == -1 || minNum > tmp)
                    minNum = tmp;
            }
        }
        if (minNum < lastNum) {
            ok = false;
        }
        lastNum = minNum;
    }

    if (ok) printf("DA\n");
    else printf("NE\n");

    return 0;
}
