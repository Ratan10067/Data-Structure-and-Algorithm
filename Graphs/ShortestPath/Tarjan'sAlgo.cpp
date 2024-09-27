// Question is to find Bridges in Graph
// Critical Connection Problem on LeetCode

#include <bits/stdc++.h>
using namespace std;
int timer = 1;
vector<vector<int>> ans;
void dfs(int node, int par, vector<int> &vis, vector<vector<int>> &adj, int *tin, int *low)
{
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for (auto v : adj[node])
    {
        if (v == par)
            continue;
        if (!vis[v])
        {
            dfs(v, node, vis, adj, tin, low);
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node])
            {
                ans.push_back({v, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[v]);
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    dfs(0, -1, vis, adj, tin, low);
    return 0;
}