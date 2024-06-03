#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;
vector<int> any_cycle;
vector<int> parent;
bool is_cycle = 0;
void dfs(int node,int par)
{
    col[node] = 2;
    parent[node] = par;
    for(auto v:g[node])
    {
        if(col[v]==1)
        {
            dfs(v,node);
        }
        else if(col[v]==2)
        {
            if(is_cycle)
            {
                int temp = node;
                while (temp!=v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
            }
            is_cycle = 1;
        }
    }
    col[node] = 3;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n+1,1);
    parent.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if(col[i]==1)
        {
            dfs(i,0);
        }
    }
    return 0;
}