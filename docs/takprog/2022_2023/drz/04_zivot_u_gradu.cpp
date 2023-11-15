#include <bits\stdc++.h>
#define MAXN 3007
using namespace std;
const string folder="testcases\\";
int a[MAXN][MAXN],dp[2][MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,z;
    for(int i=0;i<MAXN;i++) dp[0][0][i]=dp[0][i][0]=1000000000;
    cin>>t>>z;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
        }
        dp[0][1][1]=dp[1][1][1]=a[1][1];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            if(i==1 && j==1) continue;
            dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
            dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1])+a[i][j];
        }
        if(k<dp[0][n][m] || k>dp[1][n][m]) {cout<<"NE"<<endl; continue;}
        cout<<"DA\n";
        if(!z) continue;
        int x=n,y=m,cur=k;
        string res="";
        while(x!=1 || y!=1)
        {
            assert(cur>=dp[0][x][y] && cur<=dp[1][x][y]);
            cur-=a[x][y];
            if(cur>=dp[0][x-1][y] && cur<=dp[1][x-1][y]) {x--; res+='S';}
            else {y--; res+='D';}
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
}
