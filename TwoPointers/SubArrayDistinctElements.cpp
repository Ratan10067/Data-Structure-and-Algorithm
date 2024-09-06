#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tail = 0;
    int head = -1;
    int ans = 0, distictCnt = 0;
    map<int, int> mp;
    while (tail < n)
    {
        while (head + 1 < n and (distictCnt < k or mp[arr[head + 1]] >= 1))
        {
            head++;
            if (mp[arr[head]] == 0)
            {
                distictCnt++;
            }
            mp[arr[head]]++;
        }
        // Update the answer for current start
        ans += (head - tail + 1);
        // move start one step forward
        if (tail > head)
        {
            // when we have zero element in window.
            tail++;
            head = tail - 1;
        }
        else
        {
            mp[arr[tail]]--;
            if (mp[arr[tail]] == 0)
            {
                distictCnt--;
            }
            tail++;
        }
    }
    cout << ans << endl;
    return 0;
}