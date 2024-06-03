#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
#define INF 1e9
vector<vector<char>> arr;
using state = pair<int, int>;
vector<vector<int>> vis;
vector<vector<int>> dis;
vector<vector<int>> num_path;
bool is_valid(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m and arr[x][y] != '#')
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
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if (is_valid(x, y))
        {
            neighs.push_back({x, y});
        }
    }
    return neighs;
}
vector<vector<state>> par;
void bfs(state st_node)
{
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e9));
    vector<vector<int>> num_path(n,vector<int>(m,INF));
    queue<state> q;
    dis[st_node.F][st_node.S] = 0;
    vis[st_node.F][st_node.S] = 1;
    num_path[st_node.F][st_node.S] = 1;
    q.push(st_node);
    while (!q.empty())
    {
        state node = q.front();
        q.pop();
        for (state v : neighbours(node))
        {
            if (!vis[v.F][v.S])
            {
                vis[v.F][v.S] = 1;
                num_path[v.F][v.S] = num_path[st_node.F][st_node.S];
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                q.push(v);
            }
            else if (dis[v.F][v.S] == dis[node.F][node.S] + 1)
            {
                num_path[v.F][v.S] += num_path[st_node.F][st_node.S];
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    arr.resize(n);
    state st, en;
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
    bfs(st);
    if (!vis[en.F][en.S])
    {
        cout << "Finish is not reacheable" << endl;
    }
    else
    {
        cout << dis[en.F][en.S] << endl;
    }
    return 0;
}