#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

const int N = 205;
int a[N];

struct fraction { long long up, down; } ;

inline bool operator<(fraction a, fraction b)
{
    return a.up * b.down < b.up * a.down;
}

fraction means[N][N*N]; // means[i] = sve srednje vrednosti duzine najvise i
int n_means[N];

// broj elemenata a vecih ili jednakih x
int num_larger(int mm, fraction x)
{
	if(n_means[mm] == 0) return 0;
    if(means[mm][n_means[mm] - 1] < x) return 0;
    int left = 0, right = n_means[mm] - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(means[mm][mid] < x) left = mid + 1;
        else right = mid;
    }
    return n_means[mm] - right;
}

int main()
{
    int n, q;
	scanf("%d", &n);
    for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
    {
        long long sum = 0;
        for(int len = 1; i + len - 1 < n; len++)
        {
            sum += a[i + len - 1];
            for(int j = 0; j <= len; j++)
				means[j][n_means[j]++] = {sum,len};
        }
    }

    for(int i = 0; i <= n; i++)
        sort(means[i], means[i] + n_means[i]);

	
	scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int low, high, t;
		scanf("%d %d %d", &low, &high, &t);

		printf("%d\n", num_larger(low, {t, 1}) - num_larger(high + 1, {t, 1}));
    }

    return 0;
}
