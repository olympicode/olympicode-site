#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
int n;
vector<int> a[maxn];
int d[2][maxn];
stack<pair<int,int> > st;
void dfs(int u,int id) {
    st.push({u,-1});
    d[id][u]=0;
    while(st.size()>0) {
        u=st.top().first;
        int par=st.top().second;
        st.pop();
        for(auto v:a[u]) {
            if(v!=par) {
                d[id][v]=d[id][u]+1;
                st.push({v,u});
            }
        }
    }
}
int main() {
    int u,v;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    int x=1;
    for(int i=1;i<=n;i++) {
        if(d[0][i]>d[0][x]) x=i;
    }
    for(int i=1;i<=n;i++) d[0][i]=0;
    dfs(x,0);
    int y=1;
    for(int i=1;i<=n;i++) {
        if(d[0][i]>d[0][y]) y=i;
    }
    dfs(y,1);
    int diam = d[0][y];
    int p=0,q=0,r=0,p1=0,q1=0,r1=0;
    for(int i=1;i<=n;i++) {
        if(d[0][i]==diam && d[1][i]==diam) r++;
        else {
            if(d[0][i]==diam) p++;
            if(d[1][i]==diam) q++;
        }
        if(d[0][i]==diam-1 && d[1][i]==diam-1) r1++;
        else {
            if(d[0][i]==diam-1) p1++;
            if(d[1][i]==diam-1) q1++;
        }
    }
    if(n==2) {
        printf("0");
        return 0;
    }
    if(p>1 || q>1 || r>0) {
        if((p>=2 && q>=2) || (p+r>=2 && q>=2) || (p>=2 && q+r>=2) || r>=2) printf("%d",diam);
        else {
            if(n%2==0) printf("%d",diam-1);
            else printf("%d",diam);
        }
    }
    else {
        if((p1>=2 && q1>=2) || (p1+r1>=2 && q1>=2) || (p1>=2 && q1+r1>=2) || r1>=2) printf("%d",diam-1);
        else {
            if(n%2==0) printf("%d",diam-2);
            else printf("%d",diam-1);
        }
    }
    return 0;
}
