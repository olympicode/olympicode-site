#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
    int n;
    double money;
    scanf("%d %lf", &n, &money);

    double prev = 1e10;
    while(n--)
    {
	double curr;
	scanf("%lf", &curr);
	if(curr > prev)
	    money *= curr / prev;
	prev = curr;
    }

    printf("%.6f\n", money);
    return 0;
}
