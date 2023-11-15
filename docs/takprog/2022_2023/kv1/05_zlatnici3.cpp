#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXQ 200005
#define MAXLOGN 20

int n,q;
vector<int> graph[MAXN];
bool visited[MAXN];
int dfsInd1[MAXN], dfsInd2[MAXN], parent[MAXN];
long long totalSum;

long long bitArr[MAXN];
long long nodeCoins[MAXN];

long long bitGetSum(int idx){
    long long sum=0;
    for(int i=idx;i>0;i-=(i&-i)){
        sum+=bitArr[i];
    }
    return sum;
}

void bitUpdate(int idx, int val){
    for(int i=idx;i<=MAXN;i+=(i&-i)){
        bitArr[i]+=val;
    }
}

long long getSubtrSum(int node){
    return bitGetSum(dfsInd2[node]-1) - bitGetSum(dfsInd1[node]-1);
}
void updateNode(int node, int val){
    bitUpdate(dfsInd1[node], val);
    nodeCoins[node]+=val;
    totalSum+=val;
}

int lg[2*MAXN];
pair<int,int> sparseTable[MAXLOGN][2*MAXN];
int first[MAXN];
vector<int> euler;
vector<pair<int,int>> heights;
int height[MAXN];
int par[MAXLOGN][MAXN];

int findLCA(int a, int b){
    int l=first[a], r=first[b];
    if(r<l){
        swap(l,r);
    }
    int i = lg[r - l + 1];
    pair<int,int> minimum = min(sparseTable[i][l], sparseTable[i][r - (1 << i) + 1]);
    return euler[minimum.first];
}

int dfsCnt;
void dfs(int cur, int hg, int parent){
    par[0][cur] = parent;
    height[cur]=hg;
    euler.push_back(cur);
    heights.push_back({hg, euler.size()-1});
    first[cur]=euler.size()-1;
    dfsInd1[cur]=dfsCnt++;
    visited[cur]=true;
    for(auto i:graph[cur]){
        if(!visited[i]){
            dfs(i, hg+1, cur);
            euler.push_back(cur);
            heights.push_back({hg, euler.size()-1});
        }
    }
    dfsInd2[cur]=dfsCnt;
}

int findCentroid(int cur, int last){
    long long curSum = getSubtrSum(cur);
    long long curVal = nodeCoins[cur];
    int maxNode=-1;
    long long maxVal = 0;
    for(auto i:graph[cur]){
        if(i==last){
            continue;
        }
        long long potentialVal = getSubtrSum(i);
        if(maxNode==-1 || maxVal<potentialVal){
            maxVal = potentialVal;
            maxNode = i;
        }
    }
    if(maxVal<=totalSum/2){
        if(totalSum%2==0 && maxVal==totalSum/2){
            return min(cur, maxNode);
        }
        return cur;
    }
    return findCentroid(maxNode, cur);
}

int bsNode;

bool bsCondition(int curCentroid, int changedNode, int lca, int leftPathLen, int rightPathLen, int m){
    if(m==0){
        return true;
    }
    long long vertexVal, potNode;
    if(m<=leftPathLen){
        m--;
        potNode = curCentroid;
        while(m>0){
            potNode = par[lg[m]][potNode];
            m-=(1<<lg[m]);
        }
        vertexVal = totalSum - 2*getSubtrSum(potNode);
        if(vertexVal==0 && par[0][potNode]<potNode){
            vertexVal++;
        }
        potNode = par[0][potNode];
    }
    else{
        m -= leftPathLen;
        m = rightPathLen - m;
        potNode = changedNode;
        while(m>0){
            potNode = par[lg[m]][potNode];
            m-=(1<<lg[m]);
        }
        vertexVal = 2*getSubtrSum(potNode)-totalSum;
        if(vertexVal==0 && par[0][potNode]>potNode){
            vertexVal++;
        }
    }
    if(vertexVal>0){
        bsNode = potNode;
    }
    return (vertexVal>0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int in1,in2;
        cin>>in1>>in2;
        graph[in1].push_back(in2);
        graph[in2].push_back(in1);
    }

    dfsCnt=1;
    dfs(1,0,1);

    for (int i = 2; i < 2*MAXN; i++){
        lg[i] = lg[i/2] + 1;
    }
    for (int j = 0; j < heights.size(); j++){
        sparseTable[0][j]=heights[j];
    }
    for (int i = 1; i < MAXLOGN; i++){
        for (int j = 0; j + (1 << i) < heights.size(); j++){
            sparseTable[i][j] = min(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
        }
    }
    for(int i=1;i<MAXLOGN;i++){
        for(int j=1;j<=n;j++){
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }

    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        updateNode(i,in);
    }

    totalSum = getSubtrSum(1);
    int curCentroid = findCentroid(1,0);
    cout<<findCentroid(1,0)<<"\n";

    cin>>q;
    for(int i=0;i<q;i++){
        int in1, in2;
        cin>>in2>>in1;
        updateNode(in1,in2);
        int changedNode = in1;
        int lca = findLCA(curCentroid, changedNode);
        int pathLen = height[curCentroid] + height[changedNode] - 2*height[lca];
        int leftPathLen = height[curCentroid] - height[lca];
        int rightPathLen = height[changedNode] - height[lca];
        bsNode = curCentroid;
        int l=-1, r = pathLen+1;
        while(r - l > 1){
             int m = (l + r) / 2;
             if(bsCondition(curCentroid, changedNode, lca, leftPathLen, rightPathLen, m)){
                l = m;
             }
             else{
                r = m;
             }
        }
        curCentroid = bsNode;
        cout<<curCentroid<<"\n";
    }
}
