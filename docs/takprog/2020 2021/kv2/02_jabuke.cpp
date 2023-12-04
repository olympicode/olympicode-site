#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 10;

int id[maxN], a[maxN];
double p[maxN];

bool cmp(int x, int y)
{
    return p[x] > p[y];
}

int main()
{
    int n;

    scanf("%d",&n);

    for (int i = 1;i<=n;i++){
        scanf("%d%lf",&a[i], &p[i]);
        id[i] = i;
    }

   sort(id + 1, id + n + 1, cmp);

   long long sum = 0;
   double ans = 0;

   for (int i = 1;i<=n;i++)
   {
       sum+=a[id[i]];
       ans = max(ans, p[id[i]] * sum);
   }

   printf("%.3lf", ans/100.00);
}
