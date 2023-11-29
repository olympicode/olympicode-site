#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

const int N = 500005;
int set[N], rank[N], n_dsu;

int n, m, n_pts;

int push() { set[n_dsu] = n_dsu; rank[n_dsu] = 0; return n_dsu++; }
int find(int x) { return set[x] == x ? x : find(set[x]); }
void join(int x, int y)
{
    x = find(x); y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y])
        set[x] = y;
    else
    {
        set[y] = x;
        rank[x] += rank[x] == rank[y];
    }
}

struct block { int start, end, colour; } ;

void join_all(std::vector<block> &a)
{
    for(int i = 0; i < a.size() - 1; i++)
    {
        join(a[i].colour, a[i + 1].colour);
    }
}

void join_all(std::vector<block> &a, std::vector<block> &b)
{
    for(int i = 0; i < a.size() - 1; i++)
        join(a[i].colour, a[i + 1].colour);
    for(int i = 0; i < b.size() - 1; i++)
        join(b[i].colour, b[i + 1].colour);
    if(a.size() && b.size())
        join(a[0].colour, b[0].colour);
}


void join_pairs(std::vector<block> &a, std::vector<block> &b)
{
    int j = 0;
    for(int i = 0; i < b.size(); i++)
    {
        while(j < a.size() && a[j].end < b[i].start) j++;
        while(j < a.size() && a[j].start <= b[i].end)
        {
            join(a[j].colour, b[i].colour);
            j++;
        }
        if(j) j--;
    }
}

void try_add_empty(std::map<int, std::vector<block>> &blocks, int x, std::vector<int> &existing_rows)
{
    if(x < 0 || x >= n) return;
    if(blocks.find(x) == blocks.end())
    {
        blocks[x].push_back({0, m - 1, push()});
        existing_rows.push_back(x);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &n_pts);

    std::map<int, std::vector<int>> points;
    for(int i = 0; i < n_pts; i++)
    {
        int ii, jj;
        scanf("%d %d", &ii, &jj);
        ii--; jj--;
        points[ii].push_back(jj);
    }

    std::map<int, std::vector<block>> blocks;
    std::vector<int> existing_rows;
    for(auto &row : points)
    {
        row.second.push_back(m);
        sort(row.second.begin(), row.second.end());

        int prev_j = -1;
        for(int point : row.second)
        {
            block curr = {prev_j + 1, point - 1, -1};
            if(curr.start <= curr.end)
            {
                curr.colour = push();
                blocks[row.first].push_back(curr);
            }
            prev_j = point;
        }

        if(blocks.find(row.first) != blocks.end())
            existing_rows.push_back(row.first);
    }

    // ugly hack
    for(auto &row : points)
    {
        try_add_empty(blocks, row.first - 1, existing_rows);
        try_add_empty(blocks, row.first + 1, existing_rows);
    }
    std::sort(existing_rows.begin(), existing_rows.end());

    for(int i = 0; i < existing_rows.size(); i++)
    {
        int prev = i ? existing_rows[i - 1] : -1;
        int curr = existing_rows[i];
        int next = i < existing_rows.size() - 1 ? existing_rows[i + 1] : n;

        // prev or next row empty
        if(prev != curr - 1 || next != curr + 1)
            join_all(blocks[curr]);

        // adjacent rows
        if(i && prev == curr - 1)
            join_pairs(blocks[prev], blocks[curr]);

        // empty between
        if(i && prev != curr - 1)
            join_all(blocks[prev], blocks[curr]);
    }
    
    std::set<int> colours;
    for(int i = 0; i < n_dsu; i++)
        colours.insert(find(set[i]));

    printf("%d\n", colours.size());
    
    return 0;
}

