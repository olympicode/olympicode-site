#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;
int a[N], orig_wait[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);

    int orig_max = 0;
    for(int i = 0; i < n; i++)
    {
	orig_max = max(a[i], orig_max);
	orig_wait[i] = orig_max - a[i];
    }

    for(int i = n - 1; i >= 0; i--)
	orig_wait[i] = max(orig_wait[i], orig_wait[i + 1]);
    
    int top_min = 1 << 30, top_wait = 0;
    int res = orig_wait[0];
    for(int i = 0; i < n; i++)
    {
	top_min = min(a[i], top_min);
	top_wait = max(a[i] - top_min, top_wait);

	res = min(res, max(top_wait, orig_wait[i + 1]));
    }

    printf("%d\n", res);
    
    return 0;
}
