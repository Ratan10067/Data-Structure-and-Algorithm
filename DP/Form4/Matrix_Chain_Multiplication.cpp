#include <bits/stdc++.h>
using namespace std;
int n;
int x[101], y[101];
int dp[101][101];
int back[101][101];
int rec(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    int ans = 1e9;
    for (int i = l; i < r; i++)
    {
        if (rec(l, i) + rec(r + 1, i) + x[l] * y[i] * y[r] < ans)
        {
            ans = rec(l, i) + rec(r + 1, i) + x[l] * y[i] * y[r];
            back[l][r] = i;
        }
    }
    return dp[l][r] = ans;
}
int opb[1001], clb[1001];
void generate(int l, int r)
{
    if (l == r)
        return;
    opb[l]++;
    clb[r]++;
    int mid = back[l][r];
    generate(l, mid);
    generate(mid + 1, r);
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, n) << endl;
    generate(1, n);
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < opb[i]; x++)
        {
            cout << "(";
        }
        cout << " " << i << " ";
        for (int x = 0; x < clb[i]; x++)
        {
            cout << ")";
        }
    }

    return 0;
}