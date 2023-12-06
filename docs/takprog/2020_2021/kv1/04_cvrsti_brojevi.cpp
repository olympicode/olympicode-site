#include <bits/stdc++.h>
using namespace std;
int dp[10][1024],mx[1024];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<1024;i++) {mx[i]=-1000000000; for(int j=0;j<10;j++) dp[j][i]=-1000000000;}
	mx[0]=0;
	for(int i=0;i<s.size();i++)
	{
		int c=s[i]-'0';
		for(int j=0;j<1024;j++) if((1<<c)&j)
		{
			dp[c][j]=max(dp[c][j],mx[j^(1<<c)])+1;
			mx[j]=max(mx[j],dp[c][j]);
		}
	}
	int x=0; for(int i=0;i<1024;i++) x=max(x,mx[i]);
	cout<<s.size()-x;
}
