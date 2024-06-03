#include <bits/stdc++.h>
using namespace std;
int n,m;
class Solution
{
public:
    vector<int> bellman_ford(int n, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(n, 1e8);
        dis[S] = 0;
        int m = edges.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if (dis[u] != 1e8 and (dis[u] + wt < dis[v]))
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        bool flag = 0;
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dis[u] != 1e8 and (dis[u] + wt < dis[v]))
            {
                flag = 1;
            }
        }
        if (flag == 0)
            return dis;

        return {-1};
    }
};
int main()
{
    cin>>n>>m;
    vector<vector<int>> g;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    int st;
    cin>>st;
    Solution s;
    s.bellman_ford(n,g,st);
    return 0;
}