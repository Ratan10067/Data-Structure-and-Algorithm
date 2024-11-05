#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
//>>> Time Complexity is O(n*m + q) >>>>///
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (i and j)
            {
                v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << v[x2][y2] - v[x2][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1]<<endl;
    }
    return 0;
}