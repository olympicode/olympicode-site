#include <bits/stdc++.h>

using namespace std;
void fix(int &x, int c){
    if(x < 0){
        x += c;
    }
}//A - x
//B - y
//C - x+y
//D - x-y
int x[200100], y[200010];
int A[100],B[100],C[100],D[100],AB[100][100],AC[100][100],AD[100][100],BC[100][100],BD[100][100],CD[100][100],ABC[100][100][100],ABD[100][100][100],ACD[100][100][100],BCD[100][100][100],ABCD[100][100][100][100];

int main(){
        int n, c;
        cin >> n >> c;
        for(int j = 0; j < n; ++j){
            cin >> x[j] >> y[j];
            int xMod = x[j]%c, yMod = y[j]%c, xmyMod = (x[j]-y[j])%c, xpyMod = (x[j]+y[j])%c;
            fix(xMod,c);
            fix(yMod,c);
            fix(xmyMod,c);
            fix(xpyMod, c);
            A[xMod]++;
            B[yMod]++;
            C[xpyMod]++;
            D[xmyMod]++;
            AB[xMod][yMod]++;
            AC[xMod][xpyMod]++;
            AD[xMod][xmyMod]++;
            BC[yMod][xpyMod]++;
            BD[yMod][xmyMod]++;
            CD[xpyMod][xmyMod]++;
            ABC[xMod][yMod][xpyMod]++;
            ABD[xMod][yMod][xmyMod]++;
            ACD[xMod][xpyMod][xmyMod]++;
            BCD[yMod][xpyMod][xmyMod]++;
            ABCD[xMod][yMod][xpyMod][xmyMod]++;
        }
        int ans = 1;
        for(int j = 0; j < n; ++j){
            int xMod = x[j]%c, yMod = y[j]%c, xmyMod = (x[j]-y[j])%c,xpyMod = (x[j]+y[j])%c;
            fix(xMod,c);
            fix(yMod,c);
            fix(xmyMod,c);
            fix(xpyMod, c);
            ans = max(ans, A[xMod] + B[yMod]+ C[xpyMod] + D[xmyMod] -
                      AB[xMod][yMod] - AC[xMod][xpyMod] - AD[xMod][xmyMod] - BC[yMod][xpyMod] - BD[yMod][xmyMod] - CD[xpyMod][xmyMod] +
                      ABC[xMod][yMod][xpyMod] + ABD[xMod][yMod][xmyMod] + ACD[xMod][xpyMod][xmyMod] + BCD[yMod][xpyMod][xmyMod] -
                      ABCD[xMod][yMod][xpyMod][xmyMod] );
        }
        cout << ans << '\n';
        return 0;
    }
