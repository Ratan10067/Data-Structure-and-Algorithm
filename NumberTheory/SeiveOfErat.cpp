#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
// >>>>> time complexity is O(nlog(log(n))) <<<<<<
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            cout << "Prime Number" << endl;
        }
    }
    return 0;
}