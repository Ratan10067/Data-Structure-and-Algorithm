#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans;
int board[100][100];
int fact(int n)
{
    if (n <= 1)
        return n;
    return n * fact(n - 1);
}
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool check(int i, int j)
{
    if (board[i][j] == 1)
        return 0;
    for (int i = 0; i < 8; i++)
    {
        int x = i + dx[i];
        int y = j + dy[i];
        if (x >= 0 and x < n and y >= 0 and y < n and board[x][y] == 1)
            return 0;
    }
    return 1;
}
void rec(int level)
{
    if (level == k)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j))
            {
                board[i][j] = 1;
                rec(level + 1);
                board[i][j] = 0;
            }
        }
    }
}
signed main()
{
    // This is direct formula for n>=4 >>> a(n) = (n - 2)*(n + 5)*(n^4 - 3*n^3 - 8*n^2 + 66*n - 108)/6, for n >= 4<<<<<<
    cin >> n >> k;
    memset(board, -1, sizeof(board));
    rec(0);
    cout << ans / fact(n) << endl;
    return 0;
}