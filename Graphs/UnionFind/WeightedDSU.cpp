/*
Problem Statement : In the Given Question there are also given weight that if a is directed to b then Xa - Xb = C where C is Some value, a and b are the nodes of the graph.
*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
using ii = pair<int, int>;
#define F first
#define S second

vector<pair<int, ii>> edge;

struct UnionFind
{
    int n, set_size, *parent, *rank, *value;
    vector<vector<int>> graph;
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        value = new int[n + 1];
        graph.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            value[i] = 0;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }

    void dfs(int cur, int par, int diff)
    {
        value[cur] += diff;

        for (int u : graph[cur])
        {
            if (u == par)
                continue;
            dfs(u, cur, diff);
        }
    }

    void merge(int x, int y, int val)
    {
        int xroot = find(x), yroot = find(y);
        set_size -= 1; // No. of connected components decreases by 1.

        if (xroot != yroot)
        {
            // Merge the smaller DSU to the bigger DSU
            // Update values of smaller DSU w.r.t root of bigger DSU.
            if (rank[xroot] >= rank[yroot])
            {
                int diff = value[x] - value[y];
                diff -= val;
                dfs(yroot, -1, diff);
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                int diff = value[y] - value[x];
                diff += val;
                dfs(xroot, -1, diff);
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    int value1(int x, int y)
    {
        if (find(x) != find(y))
            return 1e9;
        return value[x] - value[y];
    }
};

signed main()
{
    IOS int q;
    int n;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({c, {a, b}});
            uf.merge(a, b, c);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int x = uf.value1(a, b);
            if (x == 1e9)
                cout << "?" << "\n";
            else
                cout << x << "\n";
        }
    }
    return 0;
}
