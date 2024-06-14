#include <bits/stdc++.h>
using namespace std;
int n;
int rec(int level)
{
    if (level > n)
    {
        return 0;
    }
    if (level == n)
    {
        return 1;
    }
    int ans = 0;
    for (int step = 1; step <= 3; step++)
    {
        if (step + level <= n)
        {
            int ways = rec(level + step);
            ans += ways;
        }
    } 
    return ans;
}
void solve()
{
    cin>>n;
    int ans = rec(1);
} 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}