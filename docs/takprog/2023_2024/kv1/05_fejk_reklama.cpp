#include <bits/stdc++.h>
#define maxn 44
#define maxl 2100000
#define maxk 530000
using namespace std;
long long t;
long long n,s;
long long m;
long long mult[maxn];
long long add[maxn];
long long l[maxn];
long long r[maxn];
long long npot[2][maxl];
long long add_pot[maxl];
long long mult_pot[maxl];
long long add_potn;
long long mult_potn;
long long npotn[maxn];
inline void construct_pot(long long i,long long g) {
    if(i>m) return;
    add_potn=mult_potn=0;
    for(long long j=0;j<npotn[g];j++) {
        long long v=npot[g][j];
        long long add_v = 1ll * v + add[i];
        if(l[i]<=add_v && add_v<=r[i]) add_pot[add_potn++]=add_v;
        long long mult_v = 1ll * v * mult[i];
        if(l[i]<=mult_v && mult_v<=r[i]) mult_pot[mult_potn++]=mult_v;
    }
    if(mult[i]<0) {
        reverse(mult_pot,mult_pot+mult_potn);
    }
    long long p=0;
    long long q=0;
    npotn[g^1]=0;
    while(p<add_potn && q<mult_potn) {
        if(add_pot[p]<mult_pot[q]) {
            npot[g^1][npotn[g^1]++]=add_pot[p];
            p++;
        }
        else {
            if(add_pot[p]>mult_pot[q]) {
                npot[g^1][npotn[g^1]++]=mult_pot[q];
                q++;
            }
            else {
                npot[g^1][npotn[g^1]++]=add_pot[p];
                p++;
                q++;
            }
        }
    }
    while(p<add_potn) {
        npot[g^1][npotn[g^1]++]=add_pot[p];
        p++;
    }
    while(q<mult_potn) {
        npot[g^1][npotn[g^1]++]=mult_pot[q];
        q++;
    }
    construct_pot(i+1,g^1);
}
struct func {
    long long k,n;
    long long l,r;
};
inline bool l_cmp(func a,func b) {
    return a.l>b.l;
}
inline bool r_cmp(func a,func b) {
    return a.r<b.r;
}
inline bool (*(cmp[2]))(func x, func y) = {l_cmp,r_cmp};
func fnc[2][2][maxk];
long long fncn[2][2];
func add_fnc[maxk];
func mult_fnc[maxk];
long long add_fncn;
long long mult_fncn;
inline void construct_linear(long long i,long long g) {
    if(i<=m) {
        for(long long id=0;id<2;id++) {
            for(long long j=0;j<fncn[id][g];j++) {
                if(fnc[id][g][j].l==fnc[id][g][j].r) {
                    fnc[id][g][j].n=fnc[id][g][j].k*fnc[id][g][j].l+fnc[id][g][j].n;
                    fnc[id][g][j].k=0;
                }
            }
        }
        return;
    }
    for(long long id=0;id<2;id++) fncn[id][g^1]=0;
    for(long long id=0;id<2;id++) {
        add_fncn=mult_fncn=0;

        for(long long j=0;j<fncn[id][g];j++) {
            func f=fnc[id][g][j];
            if(f.l==f.r) {
                f.n=f.k*f.l+f.n;
                f.k=0;
            }
            long long nl = f.l-add[i];
            long long nr = f.r-add[i];
            long long ml = max(l[i-1],nl);
            long long mr = min(r[i-1],nr);
            if(ml<=mr) {
                func add_f = {f.k,f.k*add[i]+f.n,ml,mr};
                add_fnc[add_fncn++]=add_f;
            }
        }
        if(mult[i]>=0) {
            for(long long j=0;j<fncn[id][g];j++) {
                func f=fnc[id][g][j];
                if(f.l==f.r) {
                    f.n=f.k*f.l+f.n;
                    f.k=0;
                }
                long long nl,nr;
                if(mult[i]>0) {
                    nl = f.l/mult[i];
                    while(nl*mult[i]<f.l) nl++;
                    while((nl-1)*mult[i]>=f.l) nl--;
                    nr = f.r/mult[i];
                    while(nr*mult[i]>f.r) nr--;
                    while((nr+1)*mult[i]<=f.r) nr++;
                }
                else {
                    if(f.l<=0 && 0<=f.r) {
                        nl = -1e9;
                        nr = 1e9;
                    }
                    else {
                        nl = 1e9;
                        nr = -1e9;
                    }
                }
                long long ml = max(l[i-1],nl);
                long long mr = min(r[i-1],nr);
                if(ml<=mr) {
                    func mult_f = {f.k*mult[i],f.n,ml,mr};
                    mult_fnc[mult_fncn++]=mult_f;
                }
            }
        }
        else {
            mult[i]*=-1;
            for(long long j=0;j<fncn[1-id][g];j++) {
                func f=fnc[1-id][g][j];
                if(f.l==f.r) {
                    f.n=f.k*f.l+f.n;
                    f.k=0;
                }
                long long nl = f.l/mult[i];
                while(nl*mult[i]<f.l) nl++;
                while((nl-1)*mult[i]>=f.l) nl--;
                long long nr = f.r/mult[i];
                while(nr*mult[i]>f.r) nr--;
                while((nr+1)*mult[i]<=f.r) nr++;
                nl*=-1;
                nr*=-1;
                swap(nl,nr);
                long long ml = max(l[i-1],nl);
                long long mr = min(r[i-1],nr);
                if(ml<=mr) {
                    func mult_f = {-f.k*mult[i],f.n,ml,mr};
                    mult_fnc[mult_fncn++]=mult_f;
                }
            }
            mult[i]*=-1;
        }
        long long p=0;
        long long q=0;
        while(p<add_fncn && q<mult_fncn) {
            if(cmp[id](add_fnc[p],mult_fnc[q])) {
                fnc[id][g^1][fncn[id][g^1]++]=add_fnc[p];
                p++;
            }
            else {
                fnc[id][g^1][fncn[id][g^1]++]=mult_fnc[q];
                q++;
            }
        }
        while(p<add_fncn) {
            fnc[id][g^1][fncn[id][g^1]++]=add_fnc[p];
            p++;
        }
        while(q<mult_fncn) {
            fnc[id][g^1][fncn[id][g^1]++]=mult_fnc[q];
            q++;
        }
    }
    construct_linear(i-1,g^1);
}
int main() {
    scanf("%lld",&t);
    assert(1<=t && t<=10);
    while(t--) {
        scanf("%lld %lld",&n,&s);
        assert(1<=n && n<=40);
        assert(abs(s)<=1000000000);
        for(long long i=0;i<2;i++) {
            npotn[i]=0;
            fncn[0][i]=fncn[1][i]=0;
        }
        for(long long i=0;i<n;i++) {
            scanf("%lld",&mult[i]);
            assert(abs(mult[i])<=1000000000);
        }
        for(long long i=0;i<n;i++) {
            scanf("%lld",&add[i]);
            assert(abs(add[i])<=1000000000);
        }
        for(long long i=0;i<n;i++) {
            scanf("%lld",&l[i]);
            assert(abs(l[i])<=1000000000);
        }
        for(long long i=0;i<n;i++) {
            scanf("%lld",&r[i]);
            assert(abs(r[i])<=1000000000);
        }
        m=n/2;
        npot[0][0]=s;
        npotn[0]=1;
        construct_pot(0,0);
        fnc[0][(n-1)&1][fncn[0][(n-1)&1]++]={1,0,l[n-1],r[n-1]};
        fnc[1][(n-1)&1][fncn[1][(n-1)&1]++]={1,0,l[n-1],r[n-1]};
        construct_linear(n-1,(n-1)&1);
        bool hans=false;
        long long mans=0;
        long long p=0;
        if(npotn[(m+1)&1]>0) {
            p=0;
            for(long long i=0;i<fncn[1][m&1];i++) {
                func f=fnc[1][m&1][i];
                while(p+1<npotn[(m+1)&1] && npot[(m+1)&1][p+1]<=f.r) p++;
                long long x = npot[(m+1)&1][p];
                if(f.l<=x && x<=f.r) {
                    if(!hans || f.k*x+f.n>mans) {
                        hans=true;
                        mans=f.k*x+f.n;
                    }
                }
            }
            reverse(npot[(m+1)&1],npot[(m+1)&1]+npotn[(m+1)&1]);
            p=0;
            for(long long i=0;i<fncn[0][m&1];i++) {
                func f=fnc[0][m&1][i];
                while(p+1<npotn[(m+1)&1] && npot[(m+1)&1][p+1]>=f.l) p++;
                long long x = npot[(m+1)&1][p];
                if(f.l<=x && x<=f.r) {
                    if(!hans || f.k*x+f.n>mans) {
                        hans=true;
                        mans=f.k*x+f.n;
                    }
                }
            }
        }
        if(!hans) printf("nemoguce\n");
        else printf("%lld\n",mans);
    }
    return 0;
}
