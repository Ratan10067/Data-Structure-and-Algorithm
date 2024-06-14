#include <bits/stdc++.h>
using namespace std;

int n;
int w[3003];
int v[3003];
int W;
int dp[3003][3003];
vector<int> solution; // this will print the order of weight that gives you maximum value
int rec(int i, int x)
{
    // pruning
    // basecase
    if (i == n)
    {
        return 0;
    }
    cout << "i : " << i << " x : " << x << endl;
    // cache check
    if (dp[i][x] != -1)
    {
        cout << "i1 : " << i << " x1 : " << x << endl;
        return dp[i][x];
    }
    // transition
    int ans = rec(i + 1, x);
    if (w[i] <= x)
    {
        // if we write ans = max(ans, rec(i, x - w[i]) + v[i]); then this problem is converted to 0-infinite probelm means an elemnet can take as many of times
        cout << "i2 : " << i << " x2 : " << x << endl;
        ans = max(ans, rec(i + 1, x - w[i]) + v[i]);
    }
    // save and return
    cout << "i3 : " << i << " x3 : " << x << endl;
    cout << "ans : " << ans << endl;
    return dp[i][x] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> W;
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, W);
}
void generate(int i, int x)
{
    if (i == n)
        return;
    else
    {
        int dontake = rec(i + 1, x);
        if (w[i] <= x)
        {
            int take = rec(i + 1, x - w[i]) + v[i];
            if (dontake > take)
            {
                generate(i + 1, x);
            }
            else
            {
                solution.push_back(i);
                generate(i + 1, x - w[i]);
            }
        }
        else
        {
            generate(i + 1, x);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    solve();
    // for(int i=0;i<15;i++)
    // {
    //     for(int j=0;j<15;j++)cout<<dp[i][j]<<" ";cout<<endl;
    // }
    return 0;
}