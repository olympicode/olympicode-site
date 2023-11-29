#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int K=101,N=1003;
const ll mod=1LL<<61;
bool prebacio;
ll add(ll a,ll b){a+=b;if(a>=mod)a-=mod,prebacio=1;return a;}
ll sub(ll a,ll b){a-=b;if(a<0)a+=mod;return a;}
ll dp[N][K][2],vals[N][2][K]; ///val,k
int kada[N+K][K],degree[N*K],resetin[N*K];
int znam[N*K],jedan[N*K],zn,jed;
bool visited[N*K];
vector<vector<int> > graf(N*K*2);
int getInd(int i,int val,int k){return i*N*K+val*K+k;}
pair<int,int> getState(int val){
    pair<int,int> p;
    if(val>=N*K)
        val-=N*K;
    p.f=val/K;
    p.s=val-p.f*K;
    return p;
}
vector<vector<pair<pair<int,int>,pair<int,ll> > > > events(N);
void init()
{
    for(int i=0;i<N+K;i++)for(int j=0;j<K;j++)kada[i][j]=N;
    for(int i=0;i<K;i++)for(int k=0;k<=i;k++)dp[k][i][0]=1;
    for(int val=0;val<N;val++)
    {
        for(int k=0;k<K;k++)
        {
            if(val<N-1){
                graf[getInd(1,val,k)].pb(getInd(0,val+1,k));
                graf[getInd(0,val+1,k)].pb(getInd(1,val,k));
                degree[getInd(0,val,k)]++;
            }
            if(val!=0)
                graf[getInd(1,val,k)].pb(getInd(0,val-1,k)),graf[getInd(0,val-1,k)].pb(getInd(1,val,k)),degree[getInd(0,val,k)]++;
            else if(k)
                graf[getInd(0,val,k-1)].pb(getInd(1,val,k)),graf[getInd(1,val,k)].pb(getInd(0,val,k-1)),degree[getInd(0,val,k)]++;
        }
    }
    for(int val=0;val<2;val++)
        for(int k=0;k<K;k++)
            vals[0][val][k]=dp[val][k][0];
    for(int i=0;i<N*K;i++)
        resetin[i]=degree[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    cin >> t;
    vector<string> ans(t);
    vector<pair<pair<int,int>,pair<int,ll> > > qu(t); ///n,i,k,s;
    for(int i=0;i<t;i++)
        cin >> qu[i].f.f >> qu[i].s.f >> qu[i].s.s,qu[i].f.s=i;
    sort(all(qu));
    int j=0;
    for(int i=1;i<N;i++) ///Izracunaj DP na gore, popuni vals i kada, odgovori na querije koji su "Ne postoji"
    {
        for(int val=0;val<N;val++)
            for(int k=0;k<K;k++)
            {
                int pos=i+k-val;
                if(pos<0)
                    continue;
                if(val<N-1)
                    dp[val][k][i&1]=dp[val+1][k][i&1^1];
                else
                    dp[val][k][i&1]=0;
                if(pos>1)
                    kada[pos][k]=min(kada[pos][k],kada[pos-2][k]);
                prebacio=0;
                if(val!=0)
                    dp[val][k][i&1]=add(dp[val][k][i&1],dp[val-1][k][i&1^1]);
                else if(k){
                    dp[val][k][i&1]=add(dp[val][k][i&1],dp[val][k-1][i&1^1]);
                    if(pos>1)
                        kada[pos][k]=min(kada[pos][k],kada[pos-2][k-1]);
                }
                if(prebacio&&kada[pos][k]==N)
                    kada[pos][k]=i;
                if(val<2)
                    vals[i][val][k]=dp[val][k][i&1];
            }
        while(j<t&&qu[j].f.f==i)
        {
            int pos=i+qu[j].s.f;
            if(kada[pos][qu[j].s.f]==N&&dp[0][qu[j].s.f][i&1]<qu[j].s.s)
                ans[qu[j].f.s]="Ne postoji";
            else
                events[qu[j].f.f].pb({{0,qu[j].s.f},{qu[j].f.s,qu[j].s.s}});
            j++;
        }
    }
    for(int i=N-3;i>=0;i--) ///Izracunaj DP na dole, odgovori na ostale upite
    {
        for(int j=0;j<N*K;j++)
            degree[j]=resetin[j];
        memset(visited,0,sizeof(visited));
        for(int val=0;val<2;val++)
            for(int k=0;k<K;k++)
            {
                int pos=i+k-val;
                if(pos<0)
                    continue;
                dp[val][k][i&1]=vals[i][val][k];
                znam[zn++]=getInd(0,val,k);
            }
        while(zn||jed)
        {
            while(zn)
            {
                int val,k,tr=znam[--zn];
                visited[tr]=1;
                auto p=getState(tr);
                val=p.f;
                k=p.s;
                for(auto p:graf[tr])
                {
                    degree[p-N*K]--;
                    auto d=getState(p);
                    dp[d.f][d.s][i&1^1]=sub(dp[d.f][d.s][i&1^1],dp[val][k][i&1]);
                    if(degree[p-N*K]==1)
                        jedan[jed++]=p;
                }
            }
            while(jed)
            {
                int val,k,tr=jedan[--jed];
                auto p=getState(tr);
                val=p.f;
                k=p.s;
                for(auto p:graf[tr])
                    if(!visited[p])
                    {
                        auto d=getState(p);
                        dp[d.f][d.s][i&1]=dp[val][k][i&1^1];
                        znam[zn++]=p;
                    }
            }
        }
        for(auto p:events[i+1])
        {
            int val=p.f.f,k=p.f.s,in=p.s.f;
            ll s=p.s.s;
            val++;
            int pos=i+k-val;
            if(pos>=0&&(kada[pos][k]<=i||dp[val][k][i&1]>=s))
            {
                events[i].pb({{val,k},{in,s}});
                ans[in]+='(';
                continue;
            }
            s-=dp[val][k][i&1];
            ans[in]+=')';
            val--;
            if(val==0)
                k--;
            else
                val--;
            events[i].pb({{val,k},{in,s}});
        }
    }
    for(int i=0;i<t;i++)
        cout << ans[i] << endl;
    return 0;
}
