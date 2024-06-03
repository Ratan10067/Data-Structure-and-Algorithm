#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
int n, m;
vector<vector<int>> g;
vector<int> vis;
bool is_bipartite = true;
void dfs(int node,int color)
{
    vis[node] = color;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v,3-color);
        }
        else if(vis[v]==vis[node])
        {
            is_bipartite = false;
        }
    }
}
// >>>>> biPartite me bs yahi check krna hai ki even cycle hai ki nhi ek compnent me <<<<< //
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
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            num_component++;
            dfs(i,1);
        }
    }
    cout << num_component << endl;
    cout<<"isBipartite : "<<is_bipartite<<endl;
    // no of ways to color such that it is biPartite is 2 ki power no. of Components.
    return 0;
}