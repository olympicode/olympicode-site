#include <cstdio>
#include <algorithm>

const int N = 500005;
const long long MOD = 1000000007;

struct wall {
    int x, hp;
} ;

wall left[N], right[N];

long long totalside(wall *walls, int n, long long todo, bool exit) {
    long long res = 0;

    for(int i = 0; i < n; i++) {
        int take = std::min(todo, (long long)walls[i].hp);
        walls[i].hp -= take; todo -= take;
        
        long long mult = (todo == 0 && take > 0 && exit) ? (2*take - 1) : 2*take;
        res += mult * walls[i].x;
        res %= MOD;
    }

    return res;
}

int main() {
    int n, nleft = 0, nright = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, hp;
        scanf("%d %d", &x, &hp);
        if(x < 0) {
            left[nleft++] = {x, hp};
        } else {
            right[nright++] = {x, hp};
        }
    }

    std::sort(left, left + nleft, [](wall a, wall b) { return a.x > b.x; });
    std::sort(right, right + nright, [](wall a, wall b) { return a.x < b.x; });

    long long l = 0, r = 0;
    for(int i = 0; i < nleft; i++) l += left[i].hp;
    for(int i = 0; i < nright; i++) r += right[i].hp;

    bool exitright = r <= l;
    if(r > l) r = l + 1;
    else if(r < l) l = r;

    long long res = totalside(right, nright, r, !exitright) - totalside(left, nleft, l, exitright);
    res = (res + MOD) % MOD;
    printf("%lld\n", res);

    return 0;
}
