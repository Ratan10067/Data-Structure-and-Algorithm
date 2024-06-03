#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m,k;
#define INF 1e9
vector<vector<char>> arr;
using state = pair<pair<int, int>,int>;
vector<vector<int>> vis;
vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(k + 1, 1e9)));
vector<vector<int>> num_path;
bool is_valid(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m)
    {
        return true;
    }
    return false;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<state> neighbours(state node)
{
    vector<state> neighs;
    for (int i = 0; i < 4; i++)
    {
        int x = node.F.F + dx[i];
        int y = node.F.S + dy[i];
        if (is_valid(x, y))
        {
            int z = node.S;
            if(arr[x][y]=='#')z+=1;
            if(z>k)continue;
            neighs.push_back({{x, y},z});
        }
    }
    return neighs;
}
vector<vector<state>> par;
void bfs(state st_node)
{
    vis.assign(n, vector<int>(m, 0));
    vector<vector<int>> num_path(n, vector<int>(m, INF));
    queue<state> q;
    dis[st_node.F.F][st_node.F.S][st_node.S] = 0;
    vis[st_node.F.F][st_node.F.S] = 1;
    num_path[st_node.F.F][st_node.F.S] = 1;
    q.push(st_node);
    while (!q.empty())
    {
        state node = q.front();
        q.pop();
        for (state v : neighbours(node))
        {
            if (dis[v.F.F][v.F.S][v.S]==1e9)
            {
                dis[v.F.F][v.F.S][v.S] = dis[node.F.F][node.F.S][node.S] + 1;
                q.push(v);
            }
        }
    }
}
signed main()
{
    cin >> n >> m>>k;
    arr.resize(n);
    pair<int,int> st, en;
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'F')
            {
                en = {i, j};
            }
        }
    }
    bfs({st,0});
    int ans = INT_MAX;
    for(int bomb = 0;bomb<=k;bomb++)
    {
        ans = min(ans,dis[en.F][en.S][bomb]);
    }
    cout<<ans<<endl;
    return 0;
}