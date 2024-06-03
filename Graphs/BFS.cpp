#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> visited;
vector<int> dis;
void bfs(int src_node)
{
    visited[src_node] = 1;
    queue<int> q;
    q.push(src_node);
    dis[src_node] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto v:g[node])
        {
            if(!visited[v])
            {
                visited[v] = 1;
                dis[v] = dis[node] + 1;
                q.push(v);
            }
        }
    } 
}
signed main(){
int n,m;
cin>>n>>m;
g.resize(n+1);
for (int i = 0; i < m; i++)
{
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
visited.assign(n+1,0);
dis.assign(n+1,1e9);
bfs(1);
for (int i = 0; i < n+1; i++)
{
    cout<<visited[i]<<endl;
}
return 0;
}