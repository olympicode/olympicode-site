#include <bits/stdc++.h>
#define maxN 50005

using namespace std;

int n,m,a[maxN],b[maxN],c[maxN],d[maxN],cnt[maxN],i,j;
bool transposed = false;
long long s1=0,s2=0,sl=0;

vector<pair<pair<int,int>,int>> ans;

int main() {
	std::ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
		s1+=b[i];
	}
	
	for(i=0;i<m;i++){
		cin>>c[i]>>d[i];
		s2+=d[i];
	}
	
	if(s2<s1){
		transposed=true;
		swap(s1,s2);
		swap(n,m);
		for(i=0;i<max(n,m);i++){
			swap(a[i],c[i]);
			swap(b[i],d[i]);
		}
	}
	
	cout<<s1<<endl;
	
	for(i=0;i<m;i++) sl+=c[i];
	
	long long dif = s1-sl;
	
	for(i=0;i<m;i++){
		cnt[i]=min((long long)d[i],c[i]+dif);
		dif-=cnt[i]-c[i];
	}
	
	i=j=0;
	
	while(i<n && j<m){
		if(b[i]==0){
			i++;
			continue;
		}
		if(cnt[j]==0){
			j++;
			continue;
		}
		int tmp = min(b[i],cnt[j]);
		ans.push_back({{i+1,j+1},tmp});
		b[i]-=tmp;
		cnt[j]-=tmp;
	}
	
	cout<<ans.size()<<endl;
	
	for(i=0;i<ans.size();i++){
		if(transposed) {
			swap(ans[i].first.first,ans[i].first.second);
		}
		cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
	}
	return 0;
}