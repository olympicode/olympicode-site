#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxN = 125;
const int maxE = 1e8;

int n;
int a[maxN];
int b[maxN];
string expr[maxN];
vector<int> base, mult;

void ispis()
{
    cout<<12<<endl;

    for (int i=0; i<12; i++)
        cout<<b[i]<<" ";

    cout<<endl;

    for (int i=1; i<=n; i++)
        cout<<expr[i]<<endl;

    fclose(stdout);
}

void mult_add(int idx)
{
    for (auto i = 0 ; i< mult.size(); i++)
    {
        if (mult[i]>0 && i)
            expr[idx]+='+';
        expr[idx] = expr[idx] + to_string(mult[i]);
    }
}

void solve(int x, int idx)
{
    int curId = 0;

    for (int i = 0 ; i < 10; i++)
        base[i] = 0;

    while(x>0)
    {
        if (x%7>3)
        {
            base[curId] = x%7 - 7;
            x+=7;
        }
        else
            base[curId] = x%7;
        x/=7;
        curId++;
    }

    int nasao = 0;
    expr[idx] = "";

    for (int i = 9 ; i>=0; i--)
        if (base[i])
        {
            mult.clear();

            for (int j = i ; j>=0; j--)
                if (abs(base[i]) == abs(base[j]))
                {
                    if (base[i]*base[j] < 0)
                        mult.pb(-(b[j]));
                    else
                        mult.pb(b[j]);
                    if (i>j)
                        base[j] = 0;
                }

            if (base[i]<0 && nasao)
                expr[idx]+='-';
            if (base[i]>0 && nasao)
                expr[idx]+='+';

            if (abs(base[i])>1)
            {
                expr[idx] = expr[idx] + to_string(abs(base[i]));
                expr[idx]+='*';
            }

            expr[idx]+='(';
            mult_add(idx);
            expr[idx]+=')';
            nasao = 1;
        }
}
void prepare_base()
{
    b[0] = 1;

    for(int i = 1; i<=9; i++)
        b[i] = b[i-1]*7;

    b[10] = 2;
    b[11] = 3;

    base.resize(10);
}
int main()
{
    cin>>n;

    assert(n>0 && n<maxN);

    for (int i = 1; i<=n; i++)
    {
        cin>>a[i];
        assert(a[i]>0 && a[i]<=maxE);
    }

    prepare_base();

    for (int i = 1; i<=n; i++)
        solve(a[i], i);

    ispis();
}
