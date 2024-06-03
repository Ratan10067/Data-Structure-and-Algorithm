#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
vector<int> vis;
bool is_circular = false;
// cycle ke liye parent maintain krna hai this is important because if we not maintain the parent the result is always be wrong, every two nodes which connect to each other is cycle if we do not maintain cycle.
void dfs(int node, int par)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, node);
        }
        else
        {
            if (v != par)
            {
                is_circular = true;
                return;
            } 
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    cin.tie(0);
    cout.tie(0);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0);
        }
    }
    if (is_circular)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}