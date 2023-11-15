#include <bits/stdc++.h>
#define MAXN 307
using namespace std;
long long ev[2*MAXN*MAXN],d[2*MAXN],dist[2*MAXN],l[MAXN][MAXN],u[MAXN][MAXN];
int ep[2*MAXN*MAXN],ek[2*MAXN*MAXN],br,a;
void bellman_ford_iter() {for(int i=0;i<br;i++) d[ek[i]]=min(d[ek[i]],d[ep[i]]+ev[i]);}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m; br=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            scanf("%d",&a);
            l[i][j]=a;
            ep[br]=i;
            ek[br]=n+j;
            ev[br++]=-a;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            scanf("%d",&a);
            ep[br]=n+j;
            ek[br]=i;
            ev[br++]=a;
        }
        d[0]=0;
        for(int i=1;i<n+m;i++) d[i]=1000000000000000000LL;
        for(int i=0;i<n+m;i++) bellman_ford_iter();
        for(int i=0;i<n+m;i++) dist[i]=d[i];
        bellman_ford_iter();
        bool fail=false;
        for(int i=0;i<n+m;i++) if(d[i]!=dist[i]) fail=true;
        if(fail) {printf("NE\n"); continue;}
        printf("DA\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) printf("%lld ",d[i]-d[n+j]);
            printf("\n");
        }
    }
}
