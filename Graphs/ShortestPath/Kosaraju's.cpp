// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     void dfs(int node, vector<int> &vis, vector<int> adj[],
//              stack<int> &st)
//     {
//         vis[node] = 1;
//         for (auto it : adj[node])
//         {
//             if (!vis[it])
//             {
//                 dfs(it, vis, adj, st);
//             }
//         }
//         st.push(node);
//     }
// private:
//     void dfs3(int node, vector<int> &vis, vector<int> adjT[])
//     {
//         vis[node] = 1;
//         for (auto it : adjT[node])
//         {
//             if (!vis[it])
//             {
//                 dfs3(it, vis, adjT);
//             }
//         }
//     }

// public:
//     // Function to find number of strongly connected components in the graph.
//     int kosaraju(int V, vector<int> adj[])
//     {
//         vector<int> vis(V, 0);
//         stack<int> st;
//         for (int i = 0; i < V; i++)
//         {
//             if (!vis[i])
//             {
//                 dfs(i, vis, adj, st);
//             }
//         }

//         vector<int> adjT[V];
//         for (int i = 0; i < V; i++)
//         {
//             vis[i] = 0;
//             for (auto it : adj[i])
//             {
//                 adjT[it].push_back(i);
//             }
//         }
//         int scc = 0;
//         while (!st.empty())
//         {
//             int node = st.top();
//             st.pop();
//             if (!vis[node])
//             {
//                 scc++;
//                 dfs3(node, vis, adjT);
//             }
//         }
//         return scc;
//     }
// };

// int main()
// {

//     int n = 5;
//     int edges[5][2] = {
//         {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
//     vector<int> adj[n];
//     for (int i = 0; i < n; i++)
//     {
//         adj[edges[i][0]].push_back(edges[i][1]);
//     }
//     Solution obj;
//     int ans = obj.kosaraju(n, adj);
//     cout << "The number of strongly connected components is: " << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100];
vector<int> grev[100];
vector<int> vis(100, 0);
vector<int> tout_order;
vector<vector<int>> codensed_graph;
void dfs1(int node)
{
    vis[node] = 1;
    for (auto &v : g[node])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    tout_order.push_back(node);
}
int curr_scc = 0;
int src_num[100];
void dfs2(int node)
{
    src_num[node] = curr_scc;
    vis[node] = 1;
    for (auto &v : grev[node])
    {
        if (!vis[v])
        {
            dfs2(v);
        }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    reverse(tout_order.begin(), tout_order.end());
    vis.assign(n + 1, 0);
    for (auto x : tout_order)
    {
        if (!vis[x])
        {
            curr_scc++;
            dfs2(x);
        }
    }

    codensed_graph.resize(curr_scc + 1);
    for (auto i : src_num)
        cout << i << " ";
    cout << endl;
    int indeg[100] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (auto v : g[i])
        {
            if (src_num[i] != src_num[v])
            {
                indeg[src_num[v]]++;
                codensed_graph[src_num[i]].push_back(src_num[v]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (indeg[i] == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
