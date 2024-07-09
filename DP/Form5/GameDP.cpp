#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int rec(int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (dp[x] != -1)
        return dp[x];
    int ans = 0;
    for (int m = 0; m < (1 << x); m++)
    {
        if (rec(x - (1 << m)) == 0)
        {
            ans = 1;
            break;
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 10; i++)
    {
        cout<<rec(i)<<endl;
    }
    return 0;
}