#include <bits/stdc++.h>
using namespace std;
vector<int> a[300007];
int cnt,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m;
vector<bool> bad[300007];
inline bool valid(int x,int y) {return x>=0 && x<n && y>=0 && y<m;}
inline void check(int x,int y)
{
    if(!valid(x,y)) return;
    if(bad[x][y]) cnt--;
    bad[x][y]=false;
    bool dobar = false;
    for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]<a[x][y]) dobar = true;
    if(!dobar) {bad[x][y]=true; cnt++;}
}
int main()
{
    int q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int t;
        scanf("%d",&t);
        a[i].push_back(t);
        bad[i].push_back(false);
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) check(i,j);
    if(cnt==1) printf("DA\n");
    else printf("NE\n");
    while(q--)
    {
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        xa--; xb--; ya--; yb--;
        swap(a[xa][ya],a[xb][yb]);
        check(xa,ya); check(xb,yb);
        for(int i=0;i<4;i++) check(xa+dx[i],ya+dy[i]);
        for(int i=0;i<4;i++) check(xb+dx[i],yb+dy[i]);
        if(cnt==1) printf("DA\n");
        else printf("NE\n");
    }
}
