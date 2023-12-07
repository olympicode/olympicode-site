#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 600000
using namespace std;
struct Segment {
    int cnt;
    int child_left;
    int child_right;
};
int reser[maxn];
Segment arr[182*maxn];
Segment emp;
int al=0;
int segs[30];
inline void erase_reservation(int o,int p,int N,int M) {
    int len=0;
    while(o<=N) {
        segs[len++]=o;
        o+=(o&(-o));
    }
    int l=1,r=M;
    while(l<r) {
        int m=(l+r)>>1;
        if(p<=m) {
            for(int i=0;i<len;i++) {
                arr[segs[i]].cnt--;
                segs[i]=arr[segs[i]].child_left;
            }
            r=m;
        }
        else {
            for(int i=0;i<len;i++) {
                arr[segs[i]].cnt--;
                segs[i]=arr[segs[i]].child_right;
            }
            l=m+1;
        }
    }
    for(int i=0;i<len;i++) arr[segs[i]].cnt--;
}
inline void add_reservation(int o,int p,int N,int M) {
    int len=0;
    while(o<=N) {
        segs[len++]=o;
        o+=(o&(-o));
    }
    int l=1,r=M;
    while(l<r) {
        int m=(l+r)>>1;
        if(p<=m) {
            for(int i=0;i<len;i++) {
                arr[segs[i]].cnt++;
                if(arr[segs[i]].child_left==0) arr[segs[i]].child_left=al++;
                segs[i]=arr[segs[i]].child_left;
            }
            r=m;
        }
        else {
            for(int i=0;i<len;i++) {
                arr[segs[i]].cnt++;
                if(arr[segs[i]].child_right==0) arr[segs[i]].child_right=al++;
                segs[i]=arr[segs[i]].child_right;
            }
            l=m+1;
        }
    }
    for(int i=0;i<len;i++) arr[segs[i]].cnt++;
}
inline int traverse(int o,int x,int M,int c) {
    int len=0;
    while(o>0) {
        segs[len++]=o;
        o-=(o&(-o));
    }
    int l=1,r=M;
    while(l<r) {
        if(l>=c) return l;
        int m=(l+r)>>1;
        int cfree=m-l+1;
        for(int i=0;i<len;i++) cfree-=arr[arr[segs[i]].child_left].cnt;
        if(x<=cfree) {
            r=m;
            if(l==r) return l;
            for(int i=0;i<len;i++) segs[i]=arr[segs[i]].child_left;
        }
        else {
            l=m+1;
            if(l==r) return l;
            x-=cfree;
            for(int i=0;i<len;i++) segs[i]=arr[segs[i]].child_right;
        }
    }
    return l;
}
void Smestaj(int N,int M,int Q,int *T,int *U,int *X,int *Ans) {
    al=N+1;
    int l=1;
    for(int i=1;i<=Q;i++) {
        if(T[i]==1) {
            int o=N+1-U[i];
            if(reser[o]!=0) erase_reservation(o,reser[o],N,M);
            reser[o]=X[i];
            if(reser[o]!=0) add_reservation(o,reser[o],N,M);
        }
        else {
            int o=N-U[i];
            int vx=reser[o+1];
            if(vx==0) vx=M+1;
            Ans[l]=traverse(o,U[i],M,vx);
            Ans[l]=min(Ans[l],vx);
            l++;
        }
    }
}
