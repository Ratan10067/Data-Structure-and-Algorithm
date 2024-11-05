#include <bits/stdc++.h>
using namespace std;

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            vector<int> set_bit;
            for (auto &v : arr)
            {
                if (v & (1 << i))
                {
                    set_bit.push_back(v);
                }
            }
            if (set_bit.size() >= x)
            {
                ans += (1 << i);
                arr = set_bit;
            }
        }
        cout << ans << endl;
    }
    return 0;
}