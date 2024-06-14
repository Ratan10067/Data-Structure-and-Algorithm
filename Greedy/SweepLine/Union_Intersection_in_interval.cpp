// Question Is to find union and intersection of interval.
// To find intersection of all interval we just to find min of all initial point and max of all final point and if final point is less than initial point then answer will be -1.

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
    IOS;
    cin.tie(0);
    cout.tie(0);
    vector<pair<int, int>> events;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    int inter = 0;
    int uni = 0;
    int cnt = 0;
    for (int i = 0; i < events.size() - 1; i++)
    {
        cnt += events[i].second;
        if (cnt > 0)
        {
            uni += events[i + 1].first - events[i].first;
        }
        if (cnt == n)
        {
            inter += events[i + 1].first - events[i].first;
        }
    }
    cout << uni << " " << inter << endl;
    return 0;
}