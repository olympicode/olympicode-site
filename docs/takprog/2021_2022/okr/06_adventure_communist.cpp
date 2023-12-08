#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 1000005;
const int mod = 1000000007;
 
int n, t;
long long a[maxN], k[maxN], c, powC[maxN];
 
long long modPow(long long a, long long p) {
	if (p == 0) return 1;
 
	long long ans, tmp = modPow(a, p / 2);
	ans = tmp * tmp;
	ans %= mod;
 
	if (p % 2) {
		ans *= a;
		ans %= mod;
	}
 
	return ans%mod;
}
 
long long solve() {
	long long p = 1, ans = (a[0] * modPow(c,t))%mod;
 
	powC[0]=modPow(c,t-n+1);
 
	for(int i=1;i<n;i++){
		powC[i]=powC[i-1]*c;
		powC[i]%=mod;
	}
 
	ans = (a[0] * powC[n-1])%mod;
 
	for (int i = 1; i < n; i++) {
		p *= k[i];
		p %= mod;
		p *= (t - i + 1);
		p %= mod;
 
		long long tmp = a[i] * p;
		tmp %= mod;
 
		tmp *= powC[n-1-i];
		tmp %= mod;
 
		ans += tmp;
		ans %= mod;
	}
 
	if (ans < 0) ans += mod;
	return ans;
}
 
long long solveBrute() {
 
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long tmp = a[j + 1] * k[j + 1];
			tmp %= mod;
			tmp *= (j + 1);
			tmp %= mod;
			tmp += c * a[j];
			tmp %= mod;
			a[j] = tmp;
		}
		a[n - 1] *= c;
		a[n - 1] %= mod;
	}
 
	if (a[0] < 0) a[0] += mod;
	return a[0];
}
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>n>>t>>c;
 
    for(int i=0;i<n;i++) cin>>a[i];
 
    for(int i=0;i<n;i++) cin>>k[i];
 
    cout<<solve()<<endl;
    return 0;
}