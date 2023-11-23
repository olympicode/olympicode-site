// O(N) - sve subtaskove
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int x[2000000];

int cnt1[7];
int cnt2[7];

int calcRes() {
    int ret = 0;
    int sum1 = 0;
    int sum2 = 0;
    int last = 0;
    for (int i = 1; i <= 6; ++i) {
        sum1 += cnt1[i];
        sum2 += cnt2[i];
        if (sum1 < sum2) {
            ret += sum2 - max(sum1, last);
            last = sum2;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", &x[i]);
    }

    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    int res = 0;
    for (int k = 0; k < n; ++k) {
        cnt1[x[k]]++;
        cnt2[x[k]]--;
        cnt2[x[2 * k]]++;
        cnt2[x[2 * k + 1]]++;
        res = max(res, calcRes());
    }

    printf("%d\n", res);
    return 0;
}
