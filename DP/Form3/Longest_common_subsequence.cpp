#include <bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
int dp[1001][1001];
string str;
int rec(int i, int j)
{
    // pruning
    // base case
    if (i >= n or j >= m)
    {
        return 0;
    }
    // Caching
    if (dp[i][j] != -1)
        return dp[i][j];
    // transition
    int ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    if (a[i] == b[j])
    {
        ans = max(ans, 1 + rec(i + 1, j + 1));
        str.push_back(a[i]);
    }
    return dp[i][j] = ans;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> a >> b;
    cout << rec(0, 0) << endl;
    cout << str << endl;
    return 0;
}