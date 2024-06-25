#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subTreeSize[100100];
int numChild[100100];
void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    numChild[node] = 0;
    subTreeSize[node] = 1;
    for(auto &v:g[node])
    {
        if(v!=parent)
        {
            numChild[node]++;
            dfs(v,node,depth+1);
            subTreeSize[node]+=subTreeSize[v];
        }
    }
    if(numChild[node]==0)
    {
        isLeaf[node] = 1;
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

    return 0;
}