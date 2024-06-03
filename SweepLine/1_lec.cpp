#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
signed main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;
        if (i + 1 < n and cnt >= k)
        {
            ans += v[i + 1].first - v[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}