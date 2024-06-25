#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int n, k;
int arr[1001];
int dp[1001][1001];
int rec(int i, int x)
{
    if (x == 0)
        return 0;
    if (i == -1)
    {
        if (x == 0)
        {
            return 0;
        }
        else
        {
            return 1e9;
        }
    }
    if (dp[i][x] != -1)
        return dp[i][x];
    int ans = 1e9;
    int min_seen = arr[i];
    for (int j = i - 1; j >= -1; j--)
    {
        ans = min(ans, rec(j, x - 1)) + min_seen;
        min_seen = min(min_seen, arr[j]);
    }
    return dp[i][x] = ans;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(n - 1, k) << endl;
}
signed main()
{
    solve();
    return 0;
}