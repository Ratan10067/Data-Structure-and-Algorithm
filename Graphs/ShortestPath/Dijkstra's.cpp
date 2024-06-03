#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ii = pair<int, int>;
#define F first
#define S second
#define MP make_pair
vector<vector<ii>> g;
int n, m;
lli dis[100100];
int vis[100100];
void dijkstra(int sc)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        vis[i] = 0;
    }
    dis[sc] = 0;
    priority_queue<ii> pq;
    pq.push(MP(-0, sc));
    while (!pq.empty())
    {
        ii fs = pq.top();
        pq.pop();
        if (vis[fs.S])
            continue;
        vis[fs.S] = 1;
        for (auto v : g[fs.S])
        {
            int neigh = v.S;
            int weigh = v.F;
            if (dis[neigh] > dis[fs.S] + weigh)
            {
                dis[neigh] = dis[fs.S] + weigh;
                pq.push(MP(-dis[weigh],neigh));
            }
        }
    }
}
signed main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijkstra(1);
    return 0;
}