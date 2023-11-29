#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2000005;

// (x,y) -- donji levi, (xx, yy) -- gornji desni
int x[N], y[N], xx[N], yy[N];
int pref_min[N], suff_min[N], pref_max[N], suff_max[N];
int n, k;

int solve(int left[], int right[])
{
    for(int i = 0; i < n; i++)
	pref_min[i] = (i % k == 0) ? left[i] : min(pref_min[i - 1], left[i]);
    for(int i = n - 1; i >= 0; i--)
	suff_min[i] = (i % k == k - 1) ? left[i] : min(suff_min[i + 1], left[i]);
    
    for(int i = 0; i < n; i++)
	pref_max[i] = (i % k == 0) ? right[i] : max(pref_max[i - 1], right[i]);
    for(int i = n - 1; i >= 0; i--)
	suff_max[i] = (i % k == k - 1) ? right[i] : max(suff_max[i + 1], right[i]);

    int res = 0;
    for(int i = 0; i < n; i++)
    {
	int low = min(pref_min[i], suff_min[max(i - k + 1, 0)]);
	int high = max(pref_max[i], suff_max[max(i - k + 1, 0)]);

	res = max(res, high - low);
    }

    return res;
}

long long m, a, b, s;
int rand(long long s) { return s = (a * s + b) % m; }

int main()
{

    cin >> n >> k >> m >> a >> b >> s;
    for(int i = 0; i < n; i++)
    {
	x[i] = rand(i ? yy[i - 1] : s);
	y[i] = rand(x[i]);
	xx[i] = rand(y[i]);
	yy[i] = rand(xx[i]);

	if(x[i] == xx[i]) xx[i]++;
	if(x[i] > xx[i]) swap(x[i], xx[i]);

	if(y[i] == yy[i]) yy[i]++;
	if(y[i] > yy[i]) swap(y[i], yy[i]);

	// cout << x[i] << " " << y[i] << " " << xx[i] << " " << yy[i] << endl;
    }
    
    printf("%d ", solve(x, xx));
    printf("%d\n", solve(y, yy));
    
    return 0;
}
