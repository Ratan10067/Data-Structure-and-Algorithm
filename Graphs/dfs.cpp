#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
int n, m;
vector<vector<int> > g;
vector<int> vis;
// >>>>> this is depth first search method in graph which helps every nuber visited once.<<<<<<//
void dfs(int node,int num_component)
{
    vis[node] = num_component;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            // dfs(v);
        }
    }
}
signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n + 1, 0);
    int num_component = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num_component++;
            dfs(i,num_component);
        }
    }
    cout << num_component << endl;
    return 0;
}