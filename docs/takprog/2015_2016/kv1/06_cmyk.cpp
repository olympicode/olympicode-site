// RandomUsername (Nikola Jovanovic)
// Quals 2016
// CMYK cyk tiles

#include <bits/stdc++.h>
using namespace std;

// symbols: 'A'..'Z'
const int MAX_STRING_LEN = 105, MAX_SYMBOLS = 30, MAX_GRAMMAR_SZ = 105, MAX_RULE_LEN = 10;

struct productionRule
{
    int L, R1, R2;
};

// vars
int testCases, stringLen, grammarSz, symbolNo;
char str[MAX_STRING_LEN];
bool DP[MAX_STRING_LEN][MAX_STRING_LEN][MAX_SYMBOLS]; // DP[length][index][symbol]
productionRule grammar[MAX_STRING_LEN];

// input vars
char temp[MAX_RULE_LEN];
char L, R1, R2;

// parts of the string that can be formed from a single 'W'
vector< pair<int, int> > blocks;
// parts of the string that can be tiled using 'W' chars
bool tiled[MAX_STRING_LEN];

// sort by the endpoints
bool compair(pair<int, int> a, pair<int, int> b)
{
    return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}

void solveCYK()
{
    // init
    for(int l = 1; l <= stringLen; l++)
    {
        for(int i = 1; i <= stringLen; i++)
        {
            for(int symb = 0; symb <= symbolNo; symb++)
            {
                if(l == 1)
                {
                    DP[l][i][symb] = (symb == (str[i] - 'A'));
                }
                else
                {
                    DP[l][i][symb] = false;
                }
            }
            if(DP[l][i]['W' - 'A'])
            {
                blocks.push_back({i, i});
            }
        }
    }

    // actual DP
    for(int l = 2; l <= stringLen; l++)
    {
        for(int i = 1; i <= stringLen - l + 1; i++)
        {
            for(int k = 1; k <= l - 1; k++)
            {
                for(int idx = 1; idx <= grammarSz; idx++)
                {
                    // s[i..i+l-1] (L) -> s[i..i+k-1] (R1) + s[i+k..stringLen] (R2)
                    DP[l][i][ grammar[idx].L ] |= DP[k][i][ grammar[idx].R1 ] & DP[l-k][i+k][ grammar[idx].R2 ];
                }
            }
            if(DP[l][i]['W' - 'A'])
            {
                blocks.push_back({i, i + l - 1});
            }
        }
    }
}

void SolveTiling()
{
    tiled[0] = true;
    for(int i = 1; i <= stringLen; i++)
    {
        tiled[i] = false;
    }
    sort(blocks.begin(), blocks.end());
    for(int i = 0; i < blocks.size(); i++)
    {
        tiled[ blocks[i].second ] |= tiled[ blocks[i].first - 1 ];
    }
}

int main()
{
    double start = clock();
    // input
    symbolNo = 25;
    scanf("%d", &grammarSz);
    for(int i = 1; i <= grammarSz; i++)
    {
        scanf("\n%c%c -> %c", &R1, &R2, &L);
        grammar[i] = { (L - 'A'), (R1 - 'A'), (R2 - 'A') };
    }
    scanf("%d", &testCases);
    for(int tc = 1; tc <= testCases; tc++)
    {
        blocks.clear();
        scanf("%d", &stringLen);
        scanf("%s", str+1);
        // CYK
        solveCYK();
        // we have to tile the string using blocks
        SolveTiling();
        printf("%s\n", tiled[stringLen] ? "YES" : "NO" );
    }
    double stop = clock();
    fprintf(stderr, "Time: %.2f\n", (stop - start) / CLOCKS_PER_SEC);
    return 0;
}
