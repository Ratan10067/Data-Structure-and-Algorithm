#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, 0));
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = -it.first;
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto v : adj[node])
            {
                int temp = v[0];
                int edW = v[1];
                if (!vis[temp])
                {
                    pq.push({-edW, temp});
                }
            }
        }
        return sum;
    }
};
signed main()
{
    // Driver code sttandard input output for graph problems///
    return 0;
}