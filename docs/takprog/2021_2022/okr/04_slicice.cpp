#include<bits/stdc++.h>
#define maxn 10000000
using namespace std;
bool nopr[maxn+5];
int cnt[maxn+5];
int main() {
	for(long long i=2;i<=maxn;i++) {
		cnt[i]=cnt[i-1];
		if(!nopr[i]) {
			cnt[i]+=1;
			for(long long j=i*i;j<=maxn;j+=i) {
				nopr[j]=true;
			}
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		int n;
		scanf("%d",&n);
		printf("%d\n",n-1-cnt[n]+cnt[n/2]);
	}
	return 0;
}