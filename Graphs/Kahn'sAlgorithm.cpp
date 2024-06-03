#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n,m;
// if you have want to get lowest lexicographically take priroty queue instead of queue
void kahn()
{
    queue<int> q;
    for (int i = 1; i <= n;i++)
    {
        if(indeg[i]==0)q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr])
        {
            indeg[v]--;
            if(indeg[v]==0)
            {
                q.push(v);
            }
        }
    }
    
}
signed main()
{
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();
    if(topo.size()!=n)
    {
        cout<<"their is cycle present"<<endl;
    }
    else
    {
        for(auto i:topo)cout<<i<<" ";cout<<endl;
    }
    return 0;
}