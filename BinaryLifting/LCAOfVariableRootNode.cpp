#include <bits/stdc++.h>
using namespace std;
#define int long long

// Depth-First Search (DFS) to calculate depth and parent table (Binary Lifting)
void dfs(int node, int parent, vector<vector<int>> &g, vector<int> &depth, vector<vector<int>> &par, int dep)
{
    depth[node] = dep;
    par[node][0] = parent;
    for (int i = 1; i < 21; i++) // Precompute the 2^i-th ancestor of node
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, g, depth, par, dep + 1);
        }
    }
}

// Lowest Common Ancestor (LCA) query
int lca(int u, int v, vector<int> &depth, vector<vector<int>> &par)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }

    // Bring u and v to the same depth
    for (int i = 20; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            u = par[u][i];
        }
    }

    if (u == v)
        return u; // If already the same, return u

    // Binary lifting to find the lowest common ancestor
    for (int i = 20; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0]; // Return the parent of u or v
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t_;
    cin >> t_;
    while (t_--)
    {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1); // Graph adjacency list
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> depth(n + 1, 0);                        // Depth array
        vector<vector<int>> par(n + 1, vector<int>(21, 0)); // Binary lifting table

        // Precompute depth and parent table starting from node 1
        dfs(1, 0, g, depth, par, 0);

        int q;
        cin >> q;
        while (q--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            int l = lca(x, y, depth, par);
            int a = lca(x, z, depth, par);
            int b = lca(y, z, depth, par);
            if (a == l)
            {
                cout << b << endl;
            }
            else if (b == l)
            {
                cout << a << endl;
            }
            else
            {
                cout << l << endl;
            }
        }
    }

    return 0;
}
