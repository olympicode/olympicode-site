#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long numComponents;

struct Node
{
    int parent;
    int rank;
};
Node DSU[10000001];

inline void MakeSet(int x)
{
    DSU[x].parent = x;
    DSU[x].rank = 0;
    numComponents++;
}

inline int Find(int x)
{
    if (DSU[x].parent == x) return x;
    DSU[x].parent = Find(DSU[x].parent);
    return DSU[x].parent;
}

inline void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    numComponents--;
    if (DSU[xRoot].rank < DSU[yRoot].rank)
    {
        DSU[xRoot].parent = yRoot;
    }
    else if (DSU[xRoot].rank > DSU[yRoot].rank)
    {
        DSU[yRoot].parent = xRoot;
    }
    else
    {
        DSU[yRoot].parent = xRoot;
        DSU[xRoot].rank++;
    }
}

int n, m, r;
int c, p, b;

vector<string> board;
bool mark[1001][1001];
int poz[1001][1001];

int placetest(int x, int y, int nid, bool doit)
{
    if (doit) MakeSet(nid);

    int total = 0;

    int ly = -1;
    int ry = m;

    for (int dx=0;dx>=-r;dx--)
    {
        int xt = x + dx;
        if (xt < 0) break;
        if (board[xt][y] != '.') break;

        // top-left
        for (int dy=0;dy>=-r;dy--)
        {
            int yt = y + dy;
            if (yt <= ly) break;
            if (board[xt][yt] != '.')
            {
                ly = max(ly, yt);
                break; // no need to go on
            }

            // If field is unoccupied, occupy it
            if (!mark[xt][yt])
            {
                if (doit) mark[xt][yt] = true;
                total++;
            }
            // If there is someone else here, union it
            if (doit && poz[xt][yt])
            {
                Union(nid, poz[xt][yt]);
            }
        }

        // top-right
        for (int dy=0;dy<=r;dy++)
        {
            int yt = y + dy;
            if (yt >= ry) break;
            if (board[xt][yt] != '.')
            {
                ry = min(ry, yt);
                break;
            }

            // If field is unoccupied, occupy it
            if (!mark[xt][yt])
            {
                if (doit) mark[xt][yt] = true;
                total++;
            }
            // If there is someone else here, union it
            if (doit && poz[xt][yt])
            {
                Union(nid, poz[xt][yt]);
            }
        }
    }

    ly = -1;
    ry = m;

    // now expand down
    for (int dx=0;dx<=r;dx++)
    {
        int xt = x + dx;
        if (xt > n - 1) break;
        if (board[xt][y] != '.') break;

        // bottom-left
        for (int dy=0;dy>=-r;dy--)
        {
            int yt = y + dy;
            if (yt <= ly) break;
            if (board[xt][yt] != '.')
            {
                ly = max(ly, yt);
                break; // no need to go on
            }

            // If field is unoccupied, occupy it
            if (!mark[xt][yt])
            {
                if (doit) mark[xt][yt] = true;
                total++;
            }
            // If there is someone else here, union it
            if (doit && poz[xt][yt])
            {
                Union(nid, poz[xt][yt]);
            }
        }

        // top-right
        for (int dy=0;dy<=r;dy++)
        {
            int yt = y + dy;
            if (yt >= ry) break;
            if (board[xt][yt] != '.')
            {
                ry = min(ry, yt);
                break;
            }

            // If field is unoccupied, occupy it
            if (!mark[xt][yt])
            {
                if (doit) mark[xt][yt] = true;
                total++;
            }
            // If there is someone else here, union it
            if (doit && poz[xt][yt])
            {
                Union(nid, poz[xt][yt]);
            }
        }
    }

    return total;
}

int cntflds()
{
    int ret = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mark[i][j]) ret++;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m >> r;
    cin >> c >> p >> b;

    board.resize(n);
    for (int i=0;i<n;i++) cin >> board[i];

    int numRs = 0;

    // Overly conservative because why not
    while ((numRs + 1) * c + (numComponents + 1) * p <= b)
    {
        int best = -1;
        int bx = -1, by = -1;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (!poz[i][j] && board[i][j] == '.' && ((1 +numRs) % 3 != 0 || mark[i][j]))
                {
                    int cur = placetest(i, j, numRs + 1, false);
                    if (cur > best)
                    {
                        best = cur;
                        bx = i, by = j;
                    }
                }
            }
        }

        // No need to update stuff if done
        if (best == 0) break;

        placetest(bx, by, ++numRs, true);
        poz[bx][by] = numRs;
        cout << bx + 1 << " " << by + 1 << endl;
		cerr << "Fields covered: " << cntflds() << endl;
    }

    cerr << "Fields covered: " << cntflds() << endl;
    cerr << "Cost spent: " << (numRs * c + numComponents * p) << endl;

    return 0;
}
