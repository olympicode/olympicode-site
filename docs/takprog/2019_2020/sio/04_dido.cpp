#include<bits/stdc++.h>
using namespace std;
int Dido(int W,int L){
	int M = L/sqrtl(2);
	auto goodState=[&](int dist,int a,int b){
		if(dist<0||dist>=L||a>L||b>M)
			return false;
		if(L-a-dist<0)
			return false;
		if(2*b*b>(L-a-dist)*(L-a-dist))
			return false;
		return true;
	};
	vector<vector<vector<int>>> dp(L,vector<vector<int>>(L+1,vector<int>(M+1)));
	for(int a=L;a>=0;a--)
		for(int b=M;b>=0;b--)
			for(int dist=0;dist<L;dist++){
				if(!goodState(dist,a,b))
					continue;
				dp[dist][a][b]=0;
				
				if(goodState(dist+1,a+1,b))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist+1][a+1][b]);
					
				if(goodState(dist+2,a,b+2))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist+2][a][b+2]+dist+dist+2);
					
				if(goodState(dist+1,a+1,b+1))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist+1][a+1][b+1]+dist+dist+1);
					
				if(goodState(dist,a+2,b))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist][a+2][b]+dist+dist);
				
				if(goodState(dist-1,a+1,b+1))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist-1][a+1][b+1]+dist+dist-1);
				
				if(goodState(dist-2,a,b+2))
					dp[dist][a][b]=max(dp[dist][a][b],dp[dist-2][a][b+2]+dist+dist-2);
			}
	return dp[W][0][0];
}