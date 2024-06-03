#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
vector<int> visited;
void dfs(int node, int num_component)
{
    visited[node] = num_component;
    for (auto i : g[node])
    {
        if (!visited[i])
        {
            dfs(i, num_component);
        }
    }
}
signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    visited.assign(n + 1, 0);
    int num_component = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            num_component++;
            dfs(i, num_component);
        }
    }
    // for(auto i:visited)cout<<i<<" ";cout<<endl;
    map<int, int> mp;
    for (int i = 0; i < visited.size(); i++)
    {
        mp[visited[i]]++;
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            cout << mp[visited[y]] << endl;
        }
        else if (x == 2)
        {
            int a, b;
            cin >> a >> b;
            if (visited[a] == visited[b])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}