#include<bits/stdc++.h>

using namespace std;

const int maxi=1e6+2;
vector<int> v[maxi];
int ans,n,m;
int p[maxi];

void ocisti()
{
    for (int i=1; i<=m;i++)
        v[i].clear();
    ans=0;
}
void dfs(int x, int pred)
{
    int sz=0;
    int last=0;
    ans++;
    for (int i:v[x])
        if (i!=pred)
        {
            sz++;
            last=i;
        }

    if (sz==1) dfs(last,x);
    return;
}

void solve()
{
    scanf("%d",&n);

    for (int i=1; i<=n; i++)
        scanf("%d",&p[i]);

    scanf("%d",&m);
    ocisti();
    
    for (int i=1; i,i<m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int poz=0;
    for (int i=1; i<=n; i++)
        if (p[i]!=i) poz=i;

    dfs(1,0);
    ans=m-ans;
    if (ans>=poz) printf("DA\n");
    else
        printf("NE\n");

    return;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
