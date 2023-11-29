/* kod koji prolazi sve test primere */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin >> n >> a;
    if (n/3<a || (a==2 && n%2))
    {
        printf("-1\n");
        return 0;
    }

    int x1,y1,x2,y2,x3,y3;

    x1 = x2 = a;

    y1 = y2 = 0;

    n -= 2*a;

    if (n<=a+a-2)
    {
        x3 = a;
        y3 = n-a;
    }
    else
    {
        if (n%2==1)
            y2++;
        x3 = n/2 + 1;
        y3 = n/2 - 1;
    }

    printf("%d %d\n%d %d\n%d %d\n",x1,y1,x2,y2,x3,y3);

    return 0;
}
