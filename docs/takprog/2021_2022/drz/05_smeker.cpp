#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";
priority_queue<pair<int,int>> pql[2];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqu[2];
void addtoheaps(int i,int k,int val)
{
    pair<int,int> t={val,k};
    if(k==1) {pql[i].push(t); return;}
    if(k&1)
    {
        if(t<pqu[i].top()) pql[i].push(t);
        else
        {
            pair<int,int> r=pqu[i].top();
            pqu[i].pop(); pqu[i].push(t);
            pql[i].push(r);
        }
        return;
    }
    if(t>pql[i].top()) pqu[i].push(t);
    else
    {
        pair<int,int> r=pql[i].top();
        pql[i].pop(); pql[i].push(t);
        pqu[i].push(r);
    }
}
int getmedian(int i)
{
    if(pql[i].size()!=pqu[i].size()) return pql[i].top().second;
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addtoheaps(0,i,x);
        addtoheaps(1,i,y);
        int a=getmedian(0);
        int b=getmedian(1);
        printf("%d\n",((a==b)?a:-1));
    }
}
