#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[1001][1001];
int dp1(int l, int r)
{
    if (l >= r)
        return 1;
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int ans = 0;
    if (s[l - 1] == s[r - 1] and dp1(l + 1, r - 2))
    {
        ans = 1;
    }
    return dp[l][r] = ans;
}
int dp3[1010];
int dp2(int i)
{
    if (i == 0)
        return -1;
    if (dp3[i] != -1)
        return dp3[i];
    int ans = 1e9;
    for (int j = i - 1; j >= 0; j--)
    {
        if (dp1(j + 1, i))
        {
            ans = min(ans, dp2(j) + 1);
        }
    }
    return dp3[i] = ans;
}
void solve()
{
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    memset(dp3, -1, sizeof(dp3));
    cout << dp2(n) << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}