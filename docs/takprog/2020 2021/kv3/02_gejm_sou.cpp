#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
long long a[MAXN],b[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&a[i],&b[i]);
	long long sol=0;
	for(int i=1;i<n;i++) sol+=min(max(abs(a[i]-a[i-1]),abs(b[i]-b[i-1])),max(abs(a[i]-b[i-1]),abs(b[i]-a[i-1])));
	printf("%lld",sol);
}
