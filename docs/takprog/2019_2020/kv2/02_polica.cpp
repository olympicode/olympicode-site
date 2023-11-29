#include <cstdio>
#include <iostream>

const int N = 1000005;
int a[N], n;
int last[10];

void print_sol(int x, int y)
{
    std::swap(a[x], a[y]);
    for(int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < 10; i++)
        last[i] = -1;
    for(int i = 0; i < n; i++)
        last[a[i]] = i;

    // Povecan broj
    for(int i = 0; i < n; i++)
        for(int d = 9; d > a[i]; d--)
            if(last[d] > i)
            {
                print_sol(i, last[d]);
                return 0;
            }

    // Ostaje isti
    for(int i = 0; i < n; i++)
        if(last[a[i]] > i)
        {
            print_sol(i, last[a[i]]);
            return 0;
        }

    // Moramo da smanjimo
    print_sol(n - 1, n - 2);
    return 0;
}
