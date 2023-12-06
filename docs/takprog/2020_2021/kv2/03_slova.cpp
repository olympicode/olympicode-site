#include <cstdio>

const int N = 1000005;
const int MOD = 1000000007;

int ways[26];
char s[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", &s);

    for(int i = 0; i < 26; i++)
        ways[i] = 0;

    for(int i = 0; i < n; i++) {
        int j = s[i] - 'A';
        ways[j] += (j > 0) ? ways[j - 1] : 1;
        if(ways[j] >= MOD) ways[j] -= MOD;
    }

    printf("%d\n", ways['Z' - 'A']);
    return 0;
}
