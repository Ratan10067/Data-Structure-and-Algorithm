#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform Depth-Limited Search (DLS)
bool DLS(int src, int target, int limit, vector<vector<int>> &adj, vector<bool> &visited)
{
    stack<pair<int, int>> s;
    s.push({src, 0});

    while (!s.empty())
    {
        int node = s.top().first;
        int depth = s.top().second;
        s.pop();

        if (node == target)
            return true;

        if (depth < limit)
        {
            visited[node] = true;
            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    s.push({neighbor, depth + 1});
                }
            }
        }
    }
    return false;
}

// Function to perform IDDFS
bool IDDFS(int src, int target, int maxDepth, vector<vector<int>> &adj)
{
    for (int limit = 0; limit <= maxDepth; ++limit)
    {
        vector<bool> visited(adj.size(), false);
        if (DLS(src, target, limit, adj, visited))
            return true;
    }
    return false;
}

int main()
{
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges to the adjacency list
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4, 5};
    adj[3] = {1};
    adj[4] = {2};
    adj[5] = {2};

    int src = 0;      // Starting node
    int target = 5;   // Target node
    int maxDepth = 3; // Maximum depth limit

    if (IDDFS(src, target, maxDepth, adj))
        cout << "Target node found!" << endl;
    else
        cout << "Target node not found within depth limit." << endl;

    return 0;
}
