#include <bits/stdc++.h>
using namespace std;
int n;
int x[1001];
int dp[1001][1001];
int rec(int l, int r)
{
    if (l + 1 == r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MAX;
    for (int i = l + 1; i <= r - 1; i++)
    {
        ans = min(ans, x[r] - x[l] + rec(l, i) + rec(i, r));
    }
    return dp[l][r] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    x[0] = 0;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n) << endl;
}
signed main()
{
    solve();
    return 0;
}