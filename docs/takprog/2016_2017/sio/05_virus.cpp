/* kod koji prolazi sve test primere */

#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200010

int N;

vector<int> graph[MAXN];

int leavesBelow[MAXN];
int maxLeaves[MAXN];

int countLeavesBelow(int node, int par)
{
    if (graph[node].size() == 1)
    {
        leavesBelow[node] =  1;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        int target = graph[node][i];

        if (target != par)
        {
            leavesBelow[node] += countLeavesBelow(target, node);
        }
    }

    return leavesBelow[node];
}


int countMaxLeaves(int node, int par, int leavesAbove)
{
    maxLeaves[node] = leavesAbove;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int target = graph[node][i];

        if (target == par) continue;

        // Update max at current node
        maxLeaves[node] = max(maxLeaves[node], leavesBelow[target]);

        countMaxLeaves(target, node, leavesAbove + leavesBelow[node] - leavesBelow[target]);
    }
}

int getCentroid()
{
    int centroid = 1;

    for (int i = 2; i <= N; i++)
    {
        if (graph[i].size() > 1 && maxLeaves[i] <= maxLeaves[centroid])
            centroid = i;
    }

    return centroid;
}

vector<int> leaves;

void getLeavesBelow(int node, int par)
{
    if (graph[node].size() == 1)
        leaves.push_back(node);

    for (int i = 0; i < graph[node].size(); i++)
    {
        int target = graph[node][i];

        if (target != par)
            getLeavesBelow(target, node);
    }
}


vector<pair<int,int>> solution;

int main() {
   
    //freopen("./input/case17.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Special case
    if (N <=  2)
    {
        cout << 1 << endl;
        cout << min(1,N) << ' ' << max(1, N) << endl;
        return 0;
    }


    countLeavesBelow(1, -1);
    countMaxLeaves(1, -1, 0);

    /*
    for (int i = 1; i <= N; i++)
    {
        cout << leavesBelow[i] << ' ' << maxLeaves[i] << endl;
    }
    */

    int centroid = getCentroid();

    // cout << centroid << endl;

    for (int i = 0; i < graph[centroid].size(); i++)
    {
        int target = graph[centroid][i];
        
        getLeavesBelow(target, centroid);
    }

    int totalLeaves = leaves.size();

    if (totalLeaves % 2)
    {
        leaves.push_back(centroid);
    }

    // Output solution
    cout << leaves.size() / 2 << endl;


    for (int i = 0; i < leaves.size() / 2; i++)
    {
        cout << leaves[i] << ' ' << leaves[i + leaves.size() / 2] << endl;
    }

    return 0;
}