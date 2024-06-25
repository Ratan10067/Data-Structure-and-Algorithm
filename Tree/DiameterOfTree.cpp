#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int dep[100100];
int par[100100];

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    for (auto &v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int maxi = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxi])
        {
            maxi = j;
        }
    }
    dfs(maxi, 0, 0);
    maxi = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxi])
        {
            maxi = j;
        }
    }
    cout << dep[maxi] << endl;
    return 0;
}