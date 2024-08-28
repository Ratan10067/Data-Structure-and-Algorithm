#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> tin, low;
int timer = 1;
vector<int> extra;
int total_compo = 0;
void dfs(int node, int par = -1)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    vector<int> childNodes;
    for (auto &to : g[node])
    {
        if (to == par)
        {
            continue;
        }
        if (vis[to])
        {
            low[node] = min(low[node], tin[to]);
        }
        else
        {
            childNodes.push_back(to);
            dfs(to, node);
            low[node] = min(low[node], low[to]);
            child++;
        }
    }
    if (par == -1)
    {
        extra[node] = child - 1;
    }
    else
    {
        for (auto v : childNodes)
        {
            if (low[v] >= tin[node])
            {
                extra[node]++;
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    extra.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            total_compo++;
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << total_compo + extra[i] << endl;
    }
    return 0;
}