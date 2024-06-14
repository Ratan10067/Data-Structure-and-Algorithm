#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
#define MP make_pair
pair<int, int> get_fraction(int a, int b)
{
    if (a == 0 and b == 0)
        return make_pair(0, 0);
    if (a == 0)
        return make_pair(0, 1);
    if (b == 0)
        return make_pair(1, 0);
    int x = gcd(a, b);
    return make_pair(a / x, b / x);
}
signed main()
{
    int n;
    cin >> n;
    int arr[n];
    int ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans += mp[get_fraction(arr[i], i)];
        mp[get_fraction(arr[i], i)]++;
    }
    cout << ans << endl;
    return 0;
}