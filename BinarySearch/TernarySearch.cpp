/*
Question Link : atcoder.jp/contests/abc279/tasks/abc279_d
Ternary Search uses in the convex upward function or convex downward function and it uses two mid points which is calculated using section formula (mx2 + nx1)/(m+n)
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using ld = long double;
int a, b;
ld func(int op)
{
    ld ans = (op)*b + (ld)a / sqrt(op + 1);
    return ans;
}
signed main()
{
    cin >> a >> b;
    int lo = 0, hi = a / b;
    while (hi - lo >= 3)
    {
        int mid1 = (2 * lo + hi) / 3;
        int mid2 = (2 * hi + lo) / 3;
        if (func(mid1) > func(mid2))
        {
            lo = mid1;
        }
        else
        {
            hi = mid2;
        }
    }
    ld ans = a;
    for (int i = 0; i <= hi; i++)
    {
        ans = min(ans, func(i));
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
/*
Binary Search Solution
signed main()
{

    cin >> a >> b;
    int lo = 0, hi = a / b;
    while (hi - lo >= 3)
    {
        int mid = (lo + hi)/2;
        if (func(mid)< func(mid+1))
        {
            ans = mid;
            hi = mid -1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
*/