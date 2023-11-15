#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    long long ans = 0;
    long long maxX = -2e6, minX = 2e6, maxY = -2e6, minY = 2e6, xS=0, yS = 0, pS = 0;

    for(int i = 0; i < m; ++i){
        long long xT, yT;
        cin >> xT >> yT;
        minY = min(minY, yT);
        maxY = max(yT, maxY);
        maxX = max(xT, maxX);
        minX = min(minX, xT);
        xS += xT;
        pS += xT*yT;
        yS += yT;
        ans = max(ans, pS - minX*yS - minY*xS + (i+1)*minX*minY);
        ans = max(ans, -1*pS + minX*yS + maxY*xS - (i+1)*minX*maxY);
        ans = max(ans, -1*pS + maxX*yS + minY*xS - (i+1)*maxX*minY);
        ans = max(ans, pS - maxX*yS - maxY*xS + (i+1)*maxX*maxY);

        cout << ans%mod << "\n";
    }
}
