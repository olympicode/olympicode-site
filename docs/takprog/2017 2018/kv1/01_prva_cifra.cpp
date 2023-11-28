#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,x1,y1;

    cin>>x>>y;

    x1=x;
    y1=y;

    while(x1>=10) x1/=10;
    while(y1>=10) y1/=10;

    if (x1>y1 || ((x1==y1) && (x>y))) cout<<x<<"\n"; else
        cout<<y<<"\n";

   return 0;
}
