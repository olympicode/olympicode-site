#include <cstdio>
#include <algorithm>

const int N = 100005;
int x[N], y[N], z[N];
int cnt[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    for(int i = 0; i < n; i++) scanf("%d", &y[i]);
    for(int i = 0; i < n; i++) scanf("%d", &z[i]);

    long long res = 0;
    for(int i = 0; i < n; i++) cnt[x[i]]++;
    for(int i = 0; i < n; i++) res += cnt[y[z[i] - 1]];

    printf("%lld\n", res);
    return 0;
}
