// This is a Lowest Common Ancestor Problem based on Tree Algorithm

#include <bits/stdc++.h>
using namespace std;
int par[100100][100100];
int depth[100100];
vector<vector<int>> g;
// >>>> This code is basically gives me a binary lifting <<<<
// Code Starts
void dfs(int node, int prev, int dep)
{
    par[node][0] = prev;
    depth[node] = dep;
    for (int i = 1; i < 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto v : g[node])
    {
        if (v != prev)
        {
            dfs(v, node, dep + 1);
        }
    }
}
// Code End

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--)
    {
        if (depth[u] - depth[v] & (1 << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

signed main()
{
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int x, y;
    cin >> x >> y;
    cout << lca(x, y) << endl;
    return 0;
}