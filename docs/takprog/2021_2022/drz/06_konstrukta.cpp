#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int maxN = 2e5 + 10;

int N, furthestNode, maxDist, dist[maxN];
vector<int> v[maxN], diametarPath;
map<pii, int> edges;


void bfs(int startNode) {
    dist[startNode] = 0;
    queue<int> q;
    q.push(startNode);

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int node: v[currentNode]) {
            if (dist[node] == -1) {
                dist[node] = dist[currentNode] + 1;
                q.push(node);
            }
        }
    }
}

int findBiggestDistanceFromNode(int startNode, int newLineEndpointA, int newLineEndpointB) {
    v[newLineEndpointA].push_back(newLineEndpointB);
    v[newLineEndpointB].push_back(newLineEndpointA);

    for (int i = 1; i <= N ;i++) {
        dist[i] = -1;
    }

    bfs(startNode);
    
    int biggestDistance = 0;
    for (int i = 1; i <= N; i++) {
        biggestDistance = max(biggestDistance, dist[i]);
    }
    
    v[newLineEndpointA].pop_back();
    v[newLineEndpointB].pop_back();

    return biggestDistance;
}

void findDiameterEnd(int node, int dist, int parent) {
    if (dist > maxDist) {
        maxDist = dist;
        furthestNode = node;
    }

    for (int i: v[node]) {
        if (i != parent) {
            findDiameterEnd(i, dist + 1, node);
        }
    }
}

void getDiameterPath(int currentNode, int targetNode, int par, vector<int> &currentPath) {
    currentPath.push_back(currentNode);

    if (currentNode == targetNode) {
        diametarPath = currentPath;
    }

    for (int i: v[currentNode]) {
        if (i != par) {
            getDiameterPath(i, targetNode, currentNode, currentPath);
        }
    }

    currentPath.pop_back();
}

pii findPairOfNonConnectedNodes() {
    for (int node = 1; node <= N; node++) {
        int nextNode = node == N ? 1 : node + 1;
        if (edges.find({node, nextNode}) == edges.end()) {
            return {node, nextNode};
        }
    }
    
    return {-1, 1};
}

int main() {
    
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[{x, y}] = true;
        edges[{y, x}] = true;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    maxDist = -1;
    findDiameterEnd(1, 0, 0);
    int firstDiameterEndpoint = furthestNode;
    
    maxDist = -1;
    findDiameterEnd(firstDiameterEndpoint, 0, 0);
    int secondDiameterEndpoint = furthestNode;
    
    vector<int> path;    
    getDiameterPath(firstDiameterEndpoint, secondDiameterEndpoint, 0, path);

    int diamLen = diametarPath.size();
    int lo = 0;
    int ro = diamLen/2;

    while (lo < ro - 1) {
        int mid = lo + ro >> 1;
        maxDist = findBiggestDistanceFromNode(diametarPath[mid], diametarPath[mid], diametarPath[diamLen - mid]);
        maxDist = min(maxDist, findBiggestDistanceFromNode(diametarPath[diamLen - mid - 1], diametarPath[mid - 1], diametarPath[diamLen - mid - 1]));

        if (maxDist <= mid) {
            ro = mid;
        } else {
            lo = mid;
        }
    }

    int eurosongFinalNode, newLineEndpointA, newLineEndpointB;
    
    if (findBiggestDistanceFromNode(diametarPath[ro], diametarPath[ro], diametarPath[diamLen - ro]) <
                                    findBiggestDistanceFromNode(diametarPath[diamLen - ro - 1], diametarPath[ro - 1], diametarPath[diamLen - ro - 1])) {
        eurosongFinalNode = diametarPath[ro];
        newLineEndpointA = diametarPath[ro];
        newLineEndpointB = diametarPath[diamLen - ro];
    } else {
        eurosongFinalNode = diametarPath[diamLen - ro - 1];
        newLineEndpointA = diametarPath[diamLen - ro  - 1];
        newLineEndpointB = diametarPath[ro - 1];
    }
        
    if (newLineEndpointA == newLineEndpointB || edges.find({newLineEndpointA, newLineEndpointB}) != edges.end()) { // new path is irrelevant
        pii nonConnectedNodes = findPairOfNonConnectedNodes();
        newLineEndpointA = nonConnectedNodes.first;
        newLineEndpointB = nonConnectedNodes.second; 
    } 
    
    printf("%d %d\n", newLineEndpointA, newLineEndpointB);
    printf("%d\n", eurosongFinalNode);

    return 0;
}
