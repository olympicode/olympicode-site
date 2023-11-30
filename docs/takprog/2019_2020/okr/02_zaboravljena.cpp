#include <cstdio>
#include <algorithm>

#define IMPOSSIBLE "nemoguce\n"

const int N = 105;
char board[N][N];
int n, k, t;

char other_player(char p) { return p == 'X' ? 'O' : 'X'; }

void replace(char a, char b)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == a)
                board[i][j] = b;
}

void swap_xo()
{
    replace('X', '?');
    replace('O', 'X');
    replace('?', 'O');
}

void delete_until(char c, int cnt)
{
    int total = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == c)
                total++;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == c && total > cnt)
            {
                board[i][j] = '.';
                total--;
            }
}

int main()
{
    scanf("%d %d %d", &n, &k, &t);

    if(t < 2*k - 1)
    {
        printf(IMPOSSIBLE);
        return 0;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = '.';
    int last_i, last_j;
    
    if(k == 2)
    {
        int max_draw = n * ((n+1)/2);
        if(t > max_draw + 1)
        {
            printf(IMPOSSIBLE);
            return 0;
        }

        char last = (t % 2) ? 'X' : 'O';  // we'll modify t, save this now
        
        char curr = 'X';
        for(int i = 0; i < n; i += 2)
            for(int j = 0; j < n; j++)
                if(t > 1)
                {
                    board[i][j] = curr;
                    t--;
                    curr = other_player(curr);
                }

        board[1][0] = last;
        last_i = 1; last_j = 0;
    }
    else if(k == 3)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = (i/2 + j) % 2 ? 'O' : 'X';
        std::swap(board[0][0], board[1][1]);
        for(int i = 0; i < 3; i++)
            board[1][i] = '*';
        last_i = last_j = 1;
    }
    else
    {
        for(int i = 0; i < n - n%2; i++)
        {
            char curr = i % 2 ? 'O' : 'X';
            for(int j = 0; j < n; j++)
                board[i][j] = (j % k != k - 1) ? curr : other_player(curr);
        }
        if(n % 2)
            for(int j = 0; j < n; j++)
                board[n - 1][j] = j % 2 ? 'O' : 'X';

        if(n == k)
        {
            std::swap(board[0][n - 1], board[2][0]);
            last_i = 0; last_j = n - 1;
            for(int i = 0; i < n; i++)
                board[0][i] = '*';
        }
        else
        {
            std::swap(board[0][k - 1], board[0][k]);
            last_i = 0; last_j = k - 1;
            for(int i = 0; i < k; i++)
                board[0][i] = '*';
        }
    }

    if(k > 2)
    {
        if(t % 2 == 0) swap_xo();
        int want_x = (t + 1) / 2;
        int want_o = t - want_x;

        // '*' that get replaced
        if(t % 2 == 0) want_o -= k;
        else want_x -= k;
        
        delete_until('X', want_x);
        delete_until('O', want_o);
        replace('*', t % 2 == 0 ? 'O' : 'X');
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n+1; j++)
            printf("%c", j == n ? '\n' : board[i][j]);
    printf("%d %d\n", last_i + 1, last_j + 1);
    return 0;
}
