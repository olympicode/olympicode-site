#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long

const int SVE=10,PUTA=20; //Moze se igrati sa ovim konstantama da se dobije dobro resenje

int n;
ll p,q,bestAns;
struct resenje{
    int cntResenje;
    string resenje;
}trResenje, best;
struct matrica{
    vector<vector<int> > mat;
    vector<int> rowid, colid;
    void ucitaj(){
        mat.resize(n, vector<int>(n));
        rowid.resize(n);
        iota(rowid.begin(), rowid.end(), 0);
        colid.resize(n);
        iota(colid.begin(), colid.end(), 0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> mat[i][j];
    }
    void swap_row(int i,int j){
        trResenje.cntResenje++;
        trResenje.resenje+="R " + to_string(i+1) + " " + to_string(j+1) + "\n";
        swap(rowid[i],rowid[j]);
    }
    void swap_col(int i,int j){
        trResenje.cntResenje++;
        trResenje.resenje+="C " + to_string(i+1) + " " + to_string(j+1) + "\n";
        swap(colid[i],colid[j]);
    }
    void izmesaj(){
        for(int i=0;i<n;i++){
            int j = rng()%n, k = rng()%n;
            swap_row(i,j);
            swap_col(i,k);
        }
    }
    int get(int i,int j){
        return mat[rowid[i]][colid[j]];
    }
}A,B,Backup;
ll getSum(){
    ll sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sum+=(ll)A.get(i,j)*B.get(i,j);
    return sum;
}
int main(){
    freopen("1.in","r",stdin);  //Ovo se menja za razlicite inputa
    freopen("1.out","w",stdout);
    cin >> n >> p >> q;
    A.ucitaj();
    Backup.ucitaj();
    for(int oo=0;oo<SVE;oo++){
        trResenje.cntResenje=0;
        trResenje.resenje.clear();
        B=Backup;
        B.izmesaj();
        for(int o=0;o<PUTA;o++){
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++){
                    ll diffRow=0;
                    for(int k=0;k<n;k++)
                        diffRow+=(ll)A.get(i,k)*B.get(j,k)-(ll)A.get(i,k)*B.get(i,k)+(ll)A.get(j,k)*B.get(i,k)-(ll)A.get(j,k)*B.get(j,k);
                    if(diffRow>0)
                        B.swap_row(i,j);
                    ll diffCol=0;
                    for(int k=0;k<n;k++)
                        diffCol+=(ll)A.get(k,i)*B.get(k,j)-(ll)A.get(k,i)*B.get(k,i)+(ll)A.get(k,j)*B.get(k,i)-(ll)A.get(k,j)*B.get(k,j);
                    if(diffCol>0)
                        B.swap_col(i,j);
                }
        }
        for(int o=0;o<n*n*PUTA;o++){
            int a=rng()%n, b=rng()%n, c=rng()%n, d=rng()%n;
            ll diffRow=0;
            for(int k=0;k<n;k++)
                diffRow+=(ll)A.get(c,k)*B.get(d,k)-(ll)A.get(c,k)*B.get(c,k)+(ll)A.get(d,k)*B.get(c,k)-(ll)A.get(d,k)*B.get(d,k);
            if(diffRow>0)
                B.swap_row(c,d);
            ll diffCol=0;
            for(int k=0;k<n;k++)
                diffCol+=(ll)A.get(k,a)*B.get(k,b)-(ll)A.get(k,a)*B.get(k,a)+(ll)A.get(k,b)*B.get(k,a)-(ll)A.get(k,b)*B.get(k,b);
            if(diffCol>0)
                B.swap_col(a,b);
        }
        if(getSum()>bestAns)
            bestAns=getSum(),best=trResenje;
    }
    cerr << bestAns;
    cout << best.cntResenje << endl << best.resenje << endl;
}
