#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
void solve()
{
    int n;
    cin >> n;
    string s = "";
    cin >> s;
    int prefix[n + 1];
    int last[26];
    int dp[n + 1];
    memset(dp, -1, sizeof(last));
    dp[0] = 1;
    prefix[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = prefix[i - 1];
        if (last[s[i - 1] - 'a'] != -1)
        {
            int idx = last[s[i - 1] - 'a'];
            dp[i] -= prefix[idx];
        }
        last[s[i - 1] - 'a'] = i - 1;
        prefix[i] = prefix[i - 1] + dp[i];
    }
    cout << prefix[n] - 1 << endl;
}
signed main()
{
    solve();
    return 0;
}