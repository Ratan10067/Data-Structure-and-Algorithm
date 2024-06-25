#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int n;
int t;
int x[101];
int dp[105][10100];
int rec(int level, int left)
{
    // pruning
    if (left < 0)
    {
        return 0;
    }
    // basecase
    if (level == n + 1)
    {
        if (left == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    // cache check
    if (dp[level][left] != -1)
    {
        return dp[level][left];
    }
    // compute
    int ans = 0;
    if (rec(level + 1, left) == 1)
    {
        ans = 1;
    }
    else if (rec(level + 1, left - x[level]) == 1)
    {
        ans = 1;
    }
    return dp[level][level] = ans;
}
void printset(int level, int left)
{
    if (level == n + 1)
    {
        return;
    }
    if (rec(level + 1, left) == 1)
    {
        printset(level + 1, left);
    }
    else if (rec(level + 1, left - x[level]))
    {
        cout << x[level] << " ";
        printset(level + 1, left - x[level]);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    memset(dp, -1, sizeof(dp));
    int q;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (rec(1, t))
        {
            printset(1, t);
            cout << endl;
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}