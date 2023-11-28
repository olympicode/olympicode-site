#include<bits/stdc++.h>

using namespace std;

const long long mo=1e9+7;

int n,m;
long long mod;
int q;

long long gcd(long long x, long long y)
{
    if (x<0) x*=-1;
    if (y<0) y*=-1;
    if (x==0 || y==0) return max(x,y);
    if (x%y==0) return y;
    return gcd(y,x%y);
}

pair<long long,pair<int,int> > calc(int x, int y)
{
    long long tot=0;

    //kratim po y
    tot=x*(y/mod);
    tot%=mo;
    y%=mod;

    // kratim po x
    tot+=y*(x/mod);
    tot%=mo;
    x%=mod;// sada x<mod && y<mod
    return {tot,{x,y}};
}

long long mul(long long n, long long x, long long k)
{
    long long first=k*n;
    first%=mo;
    first*=x;
    first%=mo;

   return first;
}

long long sumDOWN(long long n, long long x, long long k)//sum (n+i) *(x-i) (i=0...k-1) po modulu 10^9+7
{
    long long ans=0;
    long long first=mul(n,x,k);

    long long p=6;

    long long second=(k-1)/gcd(k-1,p);
    p/=gcd(k-1,p);

    long long third=k/gcd(k,p);
    p/=gcd(k,p);

    long long fourth=(3*n-3*x+2*k-1);
    long long fifth=fourth;
    fourth=fifth/gcd(fifth,p);
    p/=gcd(fifth,p);//sada je p sigurno 1

    long long sixth=mul(second,third,fourth);

    ans=(first-sixth+mo)%mo;

    return ans;
}

long long sumUP(long long n, long long x, long long k) //sum (n+i)*(x+i) (i=0...k-1)  po modulu 10^9+7
{
    long long ans=0;

    long long first= mul(n,x,k);

    long long p=6;

    long long second=(k-1)/gcd(k-1,p);
    p/=gcd(k-1,p);

    long long third=k/gcd(k,p);
    p/=gcd(k,p);

    long long fourth=(3*n+3*x+2*k-1);
    long long fifth=fourth;
    fourth=fifth/gcd(fifth,p);
    p/=gcd(fifth,p);//sada je p sigurno 1

    long long sixth=mul(second,third,fourth);

    ans=(first+sixth)%mo;

  return ans;
}

long long sumLine(long long n, long long x, long long k) // sum (n+i)*x  i=0...k-1 po modulu 10^9+7
{
  long long ans=0;

  long long first=mul(n,x,k);

  long long second=k-1;
  long long third=k;

  if (second%2==0) second/=2; else third/=2;

  long long fourth=mul(second,third,x);

  ans=(fourth+first)%mo;

  return ans;
}
long long finish(int xl, int yl,int xr, int yr)
{
    if (xl>xr || yl>yr) return 0;
    long long ans=0;

    long long dx=(xr-xl)+1;
    long long dy=(yr-yl)+1;
    long long dz=min(dx,dy)-1;

    long long currentTop=(xl+yl)%mod;
    long long rest=mod-currentTop;

    if (rest>=dz)
         ans=sumUP(currentTop,1,dz);
     else
     {
        ans=sumUP(currentTop,1,rest);
        ans+=sumUP(0,rest+1, dz-rest);
     }

    currentTop+=dz;
    currentTop%=mod;
    ans%=mo;

    long long dp=max(dx,dy)-dz;
    rest=mod-currentTop;

    if (rest>=dp)
            ans+=sumLine(currentTop,min(dx,dy),dp);
    else
    {
       ans+=sumLine(currentTop,min(dx,dy),rest);
       ans+=sumLine(0,min(dx,dy),dp-rest);
    }

    currentTop+=dp;
    currentTop%=mod;
    ans%=mo;

    rest=mod-currentTop;

    if (rest>=dz)
         ans+=sumDOWN(currentTop,dz,dz);
     else
     {
        ans+=sumDOWN(currentTop,dz,rest);
        ans+=sumDOWN(0,dz-rest, dz-rest);
     }

    ans%=mo;

    return ans;
}
int main()
{
    scanf("%d%d%lld",&n,&m,&mod);
    scanf("%d",&q);

    long long val=(1ll*(mod-1)*mod)/2;
    val%=mo;
  
    while(q--)
    {
        int xl,yl,xr,yr;
        scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
        long long ans=0;
        pair<long long,pair<int,int> > rest = calc(xr-xl+1,yr-yl+1);
        ans=(val*rest.first)%mo;
        ans+=finish(xr-rest.second.first+1,yr-rest.second.second+1, xr, yr);
        ans%=mo;
        printf("%lld\n",ans);
    }

  return 0;
}
