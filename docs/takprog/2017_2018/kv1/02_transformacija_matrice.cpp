#include<bits/stdc++.h>

using namespace std;

const int maxN=1005;

int a[maxN][maxN],b[maxN][maxN];
int n;

int calc(int a[][maxN],int b[][maxN], int n) //funkcija koja racuna broj polja koja se razlikuju u matricama a i b
{
   int diff=0;

   for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        if (a[i][j]-b[i][j]) diff++;

    return diff;
}

void rotate(int a[][maxN], int n)
{
    int c[maxN][maxN];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        c[j][n-i+1]=a[i][j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        a[i][j]=c[i][j];
}

int main()
{
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        scanf("%d",&a[i][j]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        scanf("%d",&b[i][j]);

     int ans=calc(a,b,n);

     rotate(a,n);

     ans=min(ans,calc(a,b,n)+1);

     rotate(a,n);

     ans=min(ans,calc(a,b,n)+2);

     rotate(a,n);

     ans=min(ans,calc(a,b,n)+3);

     printf("%d\n",ans);

    return 0;
}
