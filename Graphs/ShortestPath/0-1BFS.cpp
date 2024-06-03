#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> g;
int n, m;
int dis[100100];
void BFS01(int sc)
{
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
    }
    dis[sc] = 0;
    dq.push_back(sc);
    while (!dq.empty())     
    {
        int x = dq.front();
        dq.pop_front();
        for(auto v:g[x])
        {
            int neigh = v.first;
            int weigh = v.second;
            if(dis[neigh]>dis[x]+ weigh)
            {
                dis[neigh] = dis[x] + weigh;
                if(weigh==0)
                {
                    dq.push_front(neigh);
                }
                else
                {
                    dq.push_back(neigh);
                }
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    g.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int sc;
    cin>>sc;
    BFS01(sc);
    return 0;
}