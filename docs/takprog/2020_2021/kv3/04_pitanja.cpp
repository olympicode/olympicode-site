#include <bits/stdc++.h>
#define maxN 200005
#define maxQ 200005

using namespace std;

struct upit{
long long x,y,k,id;
};

upit u[maxQ],tmp;
long long n,q,i,a[maxN],x,y,k,s[maxN],ans[maxQ];
vector<int> v;

bool poredi(upit a,upit b){
return a.k<b.k;
}

void resetuj(){
for(int i=0;i<v.size();i++) s[v[i]]=-1;
v.clear();
}

long long resi(int x,int k){
if(s[x]!=-1) return s[x];
v.push_back(x);
if(x<k) s[x]=a[x];
else s[x]=a[x]+resi(x-k,k);
return s[x];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    //ifstream fin("27.in.txt");
    //ofstream fout("27.out.txt");
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cin>>q;
    for(i=0;i<q;i++){
        cin>>x>>y>>k;
        tmp.x=x-1;
        tmp.y=y-1;
        tmp.k=k;
        tmp.id=i;
        u[i]=tmp;
    }
    for(i=0;i<n;i++) s[i]=-1;
    sort(u,u+q,poredi);
    for(i=0;i<q;i++){
        if(i!=0 && u[i].k!=u[i-1].k) resetuj();
        ans[u[i].id]=resi(u[i].y,u[i].k)-resi(u[i].x,u[i].k)+a[u[i].x];
    }
    for(i=0;i<q-1;i++) cout<<ans[i]<<"\n";
    cout<<ans[q-1];
    return 0;
}
