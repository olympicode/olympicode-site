#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[1000005];
int has[1000005][10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i];
        while (x > 0) {
            has[i][x % 10] = true;
            x /= 10;
        }
    }

    int res = 1;
    for (int dig = 0; dig < 10; ++dig) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (has[i][dig]) ++cur;
            else {
                res = max(res, cur);
                cur = 0;
            }
        }
        res = max(res, cur);
    }
    
    printf("%d\n", res);
    return 0;
}
