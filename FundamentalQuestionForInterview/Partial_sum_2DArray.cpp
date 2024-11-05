#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    int q;
    cin>>q;
    while (q--)
    {
        int l,r,u,d,x;
        cin>>l>>r>>u>>d>>x;
        v[u][l]+=x;
        v[u][r+1]-=x;
        v[d+1][l]-=x;
        v[d+1][r+1]+=x;
    }
    return 0;
}