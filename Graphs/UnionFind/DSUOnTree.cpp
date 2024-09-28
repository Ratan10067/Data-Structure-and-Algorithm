#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n;
int val[MAXN];
vector<int> g[MAXN];
set<int> cols[MAXN];
int ans[MAXN];

int merge(int a, int b)
{
    if (cols[a].size() < cols[b].size())
        swap(a, b);
    for (auto v : cols[b])
    {
        cols[a].insert(v);
    }
    cols[b].clear();
    return a;
}

int dfs(int node, int par)
{
    int cur_set = val[node];
    for (auto &v : g[node])
    {
        if (v != par)
        {
            cur_set = merge(cur_set, dfs(v, node));
        }
    }
    ans[node] = cols[cur_set].size();
    return cur_set;
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        cols[i].insert(val[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n"; 
    return 0;
}