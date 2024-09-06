#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
int n;
int par[100100][32];
int depth[100100];
int partial[100100];
vector<vector<int>> g;

// Binary Lifting Code ###### O(log(n)) #######
void dfs(int node, int parent, int dep)
{
    depth[node] = dep;
    par[node][0] = parent;
    for (int i = 1; i <= 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, dep + 1);
        }
    }
}

// Lowest Common Ancestor in O(logn)
int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = 20; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

// Partial Sum
void add(int u, int v, int x)
{
    partial[u] += x;
    partial[v] += x;
    int lcaofuandv = lca(u, v);
    partial[lcaofuandv] -= x;
    if (par[lcaofuandv][0] != 0) // Avoid accessing par[0][0] which can be invalid
    {
        partial[par[lcaofuandv][0]] -= x;
    }
}

// Push operation to propagate the values
void pushAll(int node, int pp)
{
    for (auto v : g[node])
    {
        if (v != pp)
        {
            pushAll(v, node);
        }
    }
    partial[par[node][0]] += partial[node];
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        g.clear();
        g.resize(n + 1);
        fill(depth, depth + n + 1, 0);
        fill(partial, partial + n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            fill(par[i], par[i] + 21, 0);
        }

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(1, 0, 0);

        int q;
        cin >> q;
        while (q--)
        {
            int u, v, x;
            cin >> u >> v >> x;
            add(u, v, x);
        }

        pushAll(1, 0);

        for (int i = 1; i <= n; i++)
            cout << partial[i] << " ";
        cout << endl;
    }

    return 0;
}