#include <bits/stdc++.h>

using namespace std;

const int N=500,M=N*N*5,L=5,oo=INT_MAX/N;
int n,m,tr=N*N*L;
vector<string> mat(N);
vector<int> dx={0,0,1,-1,1,1,-1,-1,2,2,-2,-2,1,1,-1,-1},dy={1,-1,0,0,1,-1,1,-1,1,-1,1,-1,2,-2,2,-2},l={0,4,0,8,0},r={7,7,3,15,7},d={1,N,N,1,N};
/*
    Indeksi 0: Kralj
            1: Lovac
            2: Top
            3: Konj
            4: Kraljica
    dx,dy: indeksi 0-3: Smerovi za top
           indeksi 4-7: Smerovi za lovca
           indeksi 8-15: Smerovi za konja
           (Ovo je obelezeno u nizovima l i r)
    d: koliko polja figura sme da se pomeru u tom pravcu
*/
bool inside(int x,int y){
    return x>=0 && x<n && y>=0 && y<m && mat[x][y]=='.';
}
int getNum(int x,int y,int z){ //Iz koordinata polja u broj
    return z + y*L + x*N*L;
}
tuple<int,int,int> getField(int i){ //Iz broja u koordinate polja
    return make_tuple(i/N/L, (i%(N*L))/L, i%L);
}
vector<int> dist(M,oo);
queue<int> q[6]; //Dial's algorithm
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    q[0].push(0);
    dist[0]=0;
    for(int t=0;t<M;t++)
        while(q[t%6].size())
        {
            int tr=q[t%6].front(),x,y,z;
            q[t%6].pop();
            tie(x,y,z)=getField(tr);
            if(x==n-1&&y==m-1)
            {
                printf("%i\n",dist[tr]);
                return 0;
            }
            for(int i=0;i<5;i++) //Menjanje figure
            {
                int br=getNum(x,y,i);
                if(dist[br]>dist[tr]+i+1)
                    dist[br]=dist[tr]+i+1,q[dist[br]%6].push(br);
            }
            for(int k=l[z];k<=r[z];k++) //Pomeranje figure
                for(int i=1;i<=d[z];i++)
                {
                    int xx=x+dx[k]*i,yy=y+dy[k]*i,br=getNum(xx,yy,z);
                    if(!inside(xx,yy))
                        break;
                    if(dist[br]<=dist[tr]) //Veoma bitan uslov za optimizaciju programa
                        break;
                    if(dist[br]>dist[tr]+1)
                        dist[br]=dist[tr]+1,q[dist[br]%6].push(br);
                }
        }
    printf("-1\n");
    return 0;
}
