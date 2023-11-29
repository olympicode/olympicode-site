#include<bits/stdc++.h>

using namespace std;


//ranac po sahovnicama, onda greedy ograditi one koje ima najmanje da se ograde
// officijalno resenje komisije(tj mene :P)

const int ma=2e3+3;

#define pb push_back

int n,m,k;
int a[ma][ma],ob[ma][ma];
string s;
int comp;
int b[ma][ma];
int total,neparne;
vector<pair<pair<int,int>, int > >v;
pair<int,int> dp[1000002],pre[1000002];
map<pair<int,int>, pair<int,int> > mp;
int k1;
int koji[1000002];
set<pair<int,int> > st[10];
int cnt[ma][ma];
int broj[1000002];

int in_range(int x, int y)
{
    if (x>n || x<=0 || y>m || y<=0) return 0;
    return 1;
}
void dfs(int x, int y)
{
    if (a[x][y]) return;
    ob[x][y]=comp;
    broj[comp]++;
    total++;
    if ((x+y)%2) neparne++;
    if (in_range(x-1,y) && !ob[x-1][y]) dfs(x-1,y);
    if (in_range(x+1,y) && !ob[x+1][y]) dfs(x+1,y);
    if (in_range(x,y-1) && !ob[x][y-1]) dfs(x,y-1);
    if (in_range(x,y+1) && !ob[x][y+1]) dfs(x,y+1);
    return ;
}
void ocisti()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            a[i][j]=b[i][j];
            ob[i][j]=0;
        }

    comp=0;
    k=k1;
}

void ispisi()
{
    freopen("imanje-04.out","w",stdout);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]==2) printf("o");
            else if (a[i][j]==1) printf("x");
            else
                printf(".");
        printf("\n");

    }

    fclose(stdout);
}

int okolo(int x, int y)
{
    if (x>1 && !a[x-1][y]) return 1;
    if (x<n && !a[x+1][y]) return 1;
    if (y>1 && !a[x][y-1]) return 1;
    if (y<m && !a[x][y+1]) return 1;
    return 0;
}
void update(int x, int y)
{
    st[cnt[x][y]].erase( {x,y});
    cnt[x][y]++;
    st[cnt[x][y]].insert( {x,y});
    return;
}
void ogradi(int xi, int yi)
{
    if (cnt[xi][yi]==3) return;
    a[xi][yi]=2;
    k--;

    st[cnt[xi][yi]].erase( {xi,yi});

    if (!a[xi][yi-1]) update(xi,yi-1);
    if (!a[xi][yi+1]) update(xi,yi+1);
    if (!a[xi-1][yi]) update(xi-1,yi);
    if (!a[xi+1][yi]) update(xi+1,yi);

    return;
}

int main()
{

    freopen("imanje-04.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    k1=k;


       for (int i=1; i<=n; i++)
    {
        cin>>s;
        for (int j=1; j<=m; j++)
            if (s[j-1]=='.') b[i][j]=0;
            else
                b[i][j]=1;
    }

    fclose(stdin);

    ocisti();

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (ob[i][j]==0 && !a[i][j])
            {
                comp++;
                total=0;
                neparne=0;
                dfs(i,j);
                if (neparne>0 && total-neparne>0)
                {
                    if (total-neparne>neparne)
                    {
                        v.pb( {{total-neparne,neparne},comp});
                        koji[comp]=1;
                    }
                    else
                    {
                        v.pb( {{neparne,total-neparne},comp});
                    }
                }
            }


    for (auto j:v)
    {
        for (int i=k; i>0; i--)
        {

            int cmp = j.second;
            int prepreke = j.first.second;
            int dodaje  = j.first.first;
            if (prepreke >0 && prepreke<=i && dp[i].first<dp[i-prepreke].first+dodaje)
            {
                dp[i]= {dp[i-prepreke].first+dodaje,cmp};
                mp[dp[i]]=dp[i-prepreke];
            }
        }
    }


    int x=k;
    int count=0;

    while(dp[x].second!=0)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (dp[x].second== ob[i][j] && a[i][j]==0 && (i+j)%2==koji[dp[x].second])
                {
                    a[i][j]=2;
                    broj[ob[i][j]]--;
                    count++;
                }

        dp[x]=mp[dp[x]];

    }

    k-=count;

    for (int i=1; i<=n; i++)
    {
        a[i][0]=1;
        a[i][m+1]=1;
    }

    for (int i=1; i<=m; i++)
    {
        a[0][i]=1;
        a[n+1][i]=1;
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            broj[ob[i][j]]=0;
            ob[i][j]=0;

        }

    comp=0;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (!ob[i][j] && a[i][j]==0)
            {
                comp++;
                dfs(i,j);
            }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]==2 && min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1])>=2)
            {
                a[i][j]=0;
                broj[ob[i][j]]++;
                k++;
            }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (!a[i][j] && broj[ob[i][j]]>2)
            {
                st[min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1])].insert( {i,j});
                cnt[i][j]=min(1,a[i-1][j])+min(1,a[i+1][j])+min(1,a[i][j-1])+min(1,a[i][j+1]);
            }

    while(k>0)
    {
        int p=0;
        if (st[3].size()) p=3;
        else if (st[2].size()) p=2;
        else if (st[1].size()) p=1;

        if (p==1 && k<=2) break;
        if (p==2 && k==1) break;
        if (p)
        {
            pair<int,int> node = *st[p].begin();
            st[p].erase(st[p].begin());
            int xi=node.first;
            int yi=node.second;

            if (p==3)
            {
                if (!a[xi][yi-1] && cnt[xi][yi-1]==3) continue;
                if (!a[xi][yi+1] && cnt[xi][yi+1]==3) continue;
                if (!a[xi-1][yi] && cnt[xi-1][yi]==3) continue;
                if (!a[xi+1][yi] && cnt[xi+1][yi]==3) continue;
            }

            if (!a[xi][yi-1]) ogradi(xi,yi-1);
            if (!a[xi][yi+1]) ogradi(xi,yi+1);
            if (!a[xi-1][yi]) ogradi(xi-1,yi);
            if (!a[xi+1][yi]) ogradi(xi+1,yi);
        } else
            k--;
    }

    ispisi();

    return 0;
}
