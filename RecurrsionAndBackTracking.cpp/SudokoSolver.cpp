#include <bits/stdc++.h>
using namespace std;
const int boardSize = 4;
const int cellSize = 2;
int board[boardSize][boardSize];
/*
0 1 0 0
0 0 4 0
0 4 0 0
0 0 3 0
*/
bool check(int ch, int row, int col)
{
    // check in row
    for (int c = 0; c < boardSize; c++)
    {
        if (c != col and board[row][c] == ch)
        {
            return false;
        }
    }
    // check in col
    for (int r = 0; r < boardSize; r++)
    {
        if (r != row and board[r][col] == ch)
        {
            return false;
        }
    }
    // check in square
    int str = (row / cellSize) * cellSize;
    int stc = (col / cellSize) * cellSize;
    for (int dx = 0; dx < cellSize; dx++)
    {
        for (int dy = 0; dy < cellSize; dy++)
        {
            if (str + dx == row and stc + dy == col)
                continue;
            if (board[str + dx][stc + dy] == ch)
                return false;
        }
    }
    return true;
}
int ans = 0;
void rec(int row, int col)
{
    if (col == boardSize)
    {
        rec(row + 1, 0);
        return;
    }
    // base case
    if (row == boardSize)
    {
        ans++;
        cout << "Answer : " << ans << endl;
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    if (board[row][col] == 0)
    {
        for (int ch = 1; ch <= boardSize; ch++)
        {
            if (check(ch, row, col))
            {
                board[row][col] = ch;
                rec(row, col + 1);
                board[row][col] = 0;
            }
        }
    }
    else
    {
        if (check(board[row][col], row, col))
        {
            rec(row, col + 1);
        }
    }
}
signed main()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cin >> board[i][j];
        }
    }
    rec(0, 0);
    return 0;
}