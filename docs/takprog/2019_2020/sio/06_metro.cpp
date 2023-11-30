#include <bits/stdc++.h>
#define maxn 51000
using namespace std;

vector<pair<int,int> > a[maxn];
vector<pair<int,int> > b[maxn];

int cntu[maxn];
int cntv[maxn];

int bs;

int si[maxn];
int pos[maxn];

bool posu[maxn];
bool posv[maxn];

bool sp[maxn];
int lb[maxn];
int rb[maxn];

int paru[maxn];
long long valu[maxn];
int parv[maxn];
long long valv[maxn];

int arr[maxn];
int parr1[maxn];
int parr2[maxn];
int ppermo1[maxn];
int ppermo2[maxn];
pair<int,int> marr[maxn];
int permo[maxn];
int ad[maxn];

int ch[maxn];

int t=0;
int bc=0;

vector<int> spec;

void dfsu(int u) {
    if(cntu[u]>1 || posu[u]) return;
    posu[u]=true;
    for(auto v:a[u]) dfsu(v.first);
}

void dfsv(int u) {
    if(cntv[u]>1 || posv[u]) return;
    posv[u]=true;
    for(auto v:b[u]) dfsv(v.first);
}

void dfsfu(int u) {
    if(sp[u]) {
        si[u]=++t;
        pos[t]=u;
        lb[u]=rb[u]=si[u];
        return;
    }
    lb[u]=maxn;
    rb[u]=0;
    for(auto v:a[u]) {
        paru[v.first]=u;
        valu[v.first]=valu[u]+v.second;
        ch[u]++;
        dfsfu(v.first);
        lb[u]=min(lb[u],lb[v.first]);
        rb[u]=max(rb[u],rb[v.first]);
    }
}

void dfsfv(int u) {
    if(sp[u]) {
        lb[u]=rb[u]=si[u];
        return;
    }
    lb[u]=maxn;
    rb[u]=0;
    for(auto v:b[u]) {
        parv[v.first]=u;
        valv[v.first]=valv[u]+v.second;
        ch[u]++;
        dfsfv(v.first);
        lb[u]=min(lb[u],lb[v.first]);
        rb[u]=max(rb[u],rb[v.first]);
    }
}
int lg[maxn],rg[maxn];
void process_block(int b,int l,int r,int diff) {
    if(ad[b]) {
        for(int j=lg[b];j<=rg[b];j++) arr[j]+=ad[b];
        ad[b]=0;
    }
    int t1=0,t2=0;
    for(int j=lg[b];j<=rg[b];j++) {
        int rj=permo[j];
        if(l<=rj && rj<=r) {
            parr1[t1]=arr[j]+diff;
            ppermo1[t1]=rj;
            t1++;
        }
        else {
            parr2[t2]=arr[j];
            ppermo2[t2]=rj;
            t2++;
        }
    }
    int i1=0,i2=0;
    int tr=0;
    while(i1<t1 && i2<t2) {
        if(parr1[i1]<parr2[i2]) {
            arr[lg[b]+tr]=parr1[i1];
            permo[lg[b]+tr]=ppermo1[i1];
            i1++;
        }
        else {
            arr[lg[b]+tr]=parr2[i2];
            permo[lg[b]+tr]=ppermo2[i2];
            i2++;
        }
        tr++;
    }
    while(i1<t1) {
        arr[lg[b]+tr]=parr1[i1];
        permo[lg[b]+tr]=ppermo1[i1];
        i1++;
        tr++;
    }
    while(i2<t2) {
        arr[lg[b]+tr]=parr2[i2];
        permo[lg[b]+tr]=ppermo2[i2];
        i2++;
        tr++;
    }
}
void Resi(int N, int M, int *U, int *V, int *C, int Q, int *A, int *B, long long *R) {
    for(int i=1;i<=M;i++) {
        cntu[V[i]]++;
        cntv[U[i]]++;
        a[U[i]].push_back({V[i],C[i]});
        b[V[i]].push_back({U[i],C[i]});
    }
    for(int i=1;i<=N;i++) sort(a[i].begin(),a[i].end()),sort(b[i].begin(),b[i].end());
    dfsu(1);
    dfsv(2);
    for(int i=3;i<=N;i++) if(posu[i] && posv[i] && !posu[a[i][0].first]) sp[i]=true,spec.push_back(i);
    dfsfu(1);
    dfsfv(2);
    for(int i=1;i<=t;i++) marr[i]={valu[pos[i]]+valv[pos[i]],i};
    bs=(sqrt(t)*log(t)/log(2)+1);
    bool ok=false;
    for(int i=0;i*bs<t;i++) {
        bc++;
        lg[i]=i*bs+1;
        rg[i]=min((i+1)*bs,t);
        sort(marr+lg[i],marr+rg[i]+1);
        for(int j=lg[i];j<=rg[i];j++) {
            arr[j]=marr[j].first;
            permo[j]=marr[j].second;
        }
    }
    for(int i=1;i<=Q;i++) {
        if(A[i]==-1) {
            int l=0;
            int r=5e8;
            int k=B[i];
            while(l<r) {
                int m=(l+r)>>1;
                int cnt=0;
                for(int j=0;j<bc;j++) {
                    int lb=lg[j];
                    int rb=rg[j];
                    while(lb<rb) {
                        int mb=(lb+rb+1)>>1;
                        if(arr[mb]+ad[j]<=m) lb=mb;
                        else rb=mb-1;
                    }
                    while(lb>=lg[j] && arr[lb]+ad[j]>m) lb--;
                    cnt+=(lb-lg[j]+1);
                }
                if(cnt>=k) r=m;
                else l=m+1;
            }
            R[i]=l;
        }
        else {
            int u=U[A[i]];
            int v=V[A[i]];
            int diff=B[i]-C[A[i]];
            C[A[i]]=B[i];
            int l,r;
            if(u==paru[v] || u==parv[v]) l=lb[v],r=rb[v];
            else l=lb[u],r=rb[u];
            int b1=(l-1)/bs;
            int b2=(r-1)/bs;
            for(int j=b1+1;j<b2;j++) ad[j]+=diff;
            process_block(b1,l,r,diff);
            if(b1!=b2) process_block(b2,l,r,diff);
        }
    }
}
