#include<bits/stdc++.h>

using namespace std;

const int maxi=5e5+5;

priority_queue<pair<int,int>> pq;
int l[maxi],r[maxi],k[maxi],a[maxi];
int n,m;
vector<int> v[maxi];

void clear()
{
    for (int i=1;i<=n+1;i++)
        v[i].clear();

    while(!pq.empty())
        pq.pop();
}
void solve()
{
  scanf("%d%d",&n,&m);
  clear();

  for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);

  for (int i=1;i<=m;i++)
  {
      scanf("%d",&l[i]);
      v[l[i]].push_back(i);
  }
  for (int i=1;i<=m;i++)
      scanf("%d",&r[i]);

  for (int i=1;i<=m;i++)
      scanf("%d",&k[i]);

  for (int i=1;i<=n;i++)
  {
      for (int j:v[i])
      pq.push({-r[j],j});

      while(a[i]>0 && !pq.empty())
      {
          pair<int,int> value=pq.top();
          int idx= value.second;
          pq.pop();
          if (r[idx]>=i)
          {
              int sub=min(k[idx],a[i]);
              k[idx]-=sub;
              a[i]-=sub;
              if (k[idx]>0) pq.push({-r[idx],idx});
          }
      }

      if (a[i]>0)
      {
          printf("NE\n");
          return;
      }
  }

  printf("DA\n");
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
