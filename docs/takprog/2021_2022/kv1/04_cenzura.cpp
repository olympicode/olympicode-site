#include <bits/stdc++.h>
using namespace std;
int dp[200007][15];
pair<int,int> prv[200007][15];
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        dp[i+1][j]=dp[i][j]+((a[i]==b[j])?1:0); prv[i+1][j]={i,j};
        if(a[i]==b[j] && j && dp[i+1][j]>dp[i][j-1]) {dp[i+1][j]=dp[i][j-1]; prv[i+1][j]={i,j-1};}
        if(j && dp[i+1][j-1]<dp[i+1][j]) {dp[i+1][j]=dp[i+1][j-1]; prv[i+1][j]={i+1,j-1};}
    }
    int sol=n,nd=0;
    for(int i=0;i<m;i++) if(dp[n][i]<sol) {sol=dp[n][i]; nd=i;}
    pair<int,int> p=make_pair(n,nd);
    while(true)
    {
        if(p.first==0) break;
        pair<int,int> pr=prv[p.first][p.second];
        if(pr.second==p.second && a[pr.first]==b[p.second]) a[pr.first]='*';
        p=pr;
    }
    cout<<sol<<endl<<a;
}
