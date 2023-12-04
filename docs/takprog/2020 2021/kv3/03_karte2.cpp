#include <cstdio>

const int N = 100005;
int a[N];

void single_test() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int j = 1, first = 0, second = 0;
    bool can_win = false;

    for(int i = 0; i < n; i++) {
        first += a[i];
        if(first > k) break;

        if(i > 0) second -= a[i];
        while(j < n && second <= first) {
            second += a[j++];
        }

        if(!(second > first && second <= k)) {
            can_win = true;
            break;
        }
    }

    printf("%s\n", can_win ? "da" : "ne");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) single_test();
    return 0;
}
