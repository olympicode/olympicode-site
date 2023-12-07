#include <cstdio>
#include <cassert>

struct entry { int min, count; } ;
const entry ZERO = {1<<30, 0};
bool operator==(const entry a, const entry b) { return a.min == b.min && a.count == b.count; }
entry operator+(const entry a, const entry b)
{
    if(a.min < b.min) return a;
    else if(a.min > b.min) return b;
    else return {a.min, a.count + b.count};
}
entry operator-(const entry a, const entry b)
{
    // only called if a has double-counted entries in b, so this
    // should hold
    assert(a.min != b.min || (a == ZERO && b == ZERO) || a.count > b.count);
    return {a.min, a.min == b.min ? (a.count - b.count) : a.count};
}
const int N = 1000;
int city[N][N];
entry sum_up[N][N], sum_down[N][N];
int n, m;

inline entry get_up(int i, int j)
{
    assert(i < n && j < m);
    return i >= 0 && j >= 0 ? sum_up[i][j] : ZERO;
}
inline entry get_down(int i, int j)
{
    assert(i >= 0 && j >= 0);
    return i < n && j < m ? sum_down[i][j] : ZERO;
}

int main()
{
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &city[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            sum_up[i][j] = (entry){city[i][j], 1} + get_up(i-1, j) + get_up(i, j-1) - get_up(i-1, j-1);

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
            sum_down[i][j] = (entry){city[i][j], 1} + get_down(i+1, j) + get_down(i, j+1) - get_down(i+1, j+1);

    while(q--)
    {
        int i, j, h, w;
        scanf("%d %d %d %d", &i, &j, &h, &w);
        i--; j--;  // 0-indexing
        int ii = i + h - 1, jj = j + w - 1;  // bottom-right
        entry topleft = get_up(n-1, j-1) + get_up(i-1, m-1) - get_up(i-1, j-1);
        entry botright = get_down(i, jj+1) + get_down(ii+1, j) - get_down(ii+1, jj+1);
        entry res = topleft + botright;
        printf("%d\n", res.count);
    }

    return 0;
}
