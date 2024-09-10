// Time Complexity of this code is O(1e6log(log(1e6)) + qlog(x))

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
    int n, q;
    cin >> n >> q;
    vector<int> sp(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        sp[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (sp[i] == i)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (sp[j] == j)
                {
                    sp[j] = i;
                }
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> ans;
        while (x > 1)
        {
            ans.push_back(sp[x]);
            x /= sp[x];
        }
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}