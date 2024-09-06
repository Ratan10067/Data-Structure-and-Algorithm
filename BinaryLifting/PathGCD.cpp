#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const long long int infl = 1e18;
const int MOD = 1e9 + 7;

#define endl '\n'

vector<vector<long long int>> adj;
vector<vector<pair<long long int, long long int>>> par;
vector<long long int> v(100100);
vector<long long int> depth;
void dfs(long long int node, long long int prev, long long int dep)
{
    par[node][0] = {prev, __gcd(v[node], v[prev])};
    depth[node] = dep;
    for (long long int i = 1; i < 20; i++)
    {
        long long int a = par[node][i - 1].first;
        long long int b = par[node][i - 1].second;
        long long int x = __gcd(par[a][i - 1].second, b);
        par[node][i] = {par[a][i - 1].first, x};
    }
    for (auto u : adj[node])
    {
        if (u != prev)
        {
            dfs(u, node, dep + 1);
        }
    }
}

long long int find_lca(long long int a, long long int b)
{
    long long int hcf = __gcd(v[a], v[b]);

    if (depth[a] > depth[b])
        swap(a, b);
    for (long long int i = 19; i >= 0; i--)
    {
        if ((depth[b] - depth[a]) & (1 << i))
        {

            hcf = __gcd(par[b][i].second, hcf);
            b = par[b][i].first;
        }
    }

    if (a == b)
        return hcf;
    else
    {
        for (long long int i = 19; i >= 0; i--)
        {
            if (par[a][i].first != par[b][i].first)
            {
                hcf = __gcd(par[b][i].second, hcf);
                hcf = __gcd(par[a][i].second, hcf);
                b = par[b][i].first;
                a = par[a][i].first;
            }
        }
        hcf = __gcd(hcf, par[a][0].second);
        return hcf;
    }
}
void solve()
{
    long long int a, b, c, d, x, y, n, m, k, l, i, j, Max = INT_MIN, Min = INT_MAX, ctr = 0, cnt = 0, ans = 0, lo, hi, mid, q;
    char ch;
    cin >> n;
    adj.clear();

    adj.resize(n + 1);
    pair<long long int, long long int> p = {0, 0};
    par = vector<vector<pair<long long int, long long int>>>(n + 1, vector<pair<long long int, long long int>>(21, p));
    depth = vector<long long int>(n + 1, 0);
    v[0] = 1;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0, 0);
    cin >> q;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        cout << find_lca(a, b) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
