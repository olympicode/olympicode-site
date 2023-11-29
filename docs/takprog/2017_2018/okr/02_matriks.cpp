#include<bits/stdc++.h>


using namespace std;

int n,m,q;

int calc(int x)
{
    if (x%4==0) return x;
    if (x%4==1) return 1;
    if (x%4==2) return x+1;
    return 0;
}

int main()
{

    cin>>n>>m>>q;

    while(q--)
    {
        int xl,yl,xr,yr;

        scanf("%d%d%d%d",&xl,&yl,&xr,&yr);

        int ans=0;

        if ((xr&1)==(xl&1))
            ans=calc(yr)^calc(yl-1);

        if ((yr&1)==(yl&1))
            ans^=calc(xr)^calc(xl-1);

        printf("%d\n",ans);
    }

  return 0;
}
