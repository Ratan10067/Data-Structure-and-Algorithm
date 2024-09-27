/*
First Question is that to find the number of solution for different a and b value for which the relation is satisfy
Relation is 1/a + 1/b = 1/n and n is given 
Solution : In this question we arrange the terms and we get (n-a)*(n-b) = n*n and after this by checking the divisors of n*n we can get the values of a and b.

Second Question is that to find the summation of the series floor((N/1)^3) + floor((N/2)^3) +floor((N/3)^3) + floor((N/4)^3) + ..... + floor((N/N)^3) where N is Given.
Solution : In this question First thing is to analyse that the number of Distinct Values that floor(n/x) where x lies between 1 to x is bounded by 2*sqrt(n) so the thing is that there are many values which is same so first to find a largest x such that floor(n/i) = floor(n/x) and we find that x = floor(n/(floor(n/i)) )
*/

/* Solution of Second Problem */
#include <bits/stdc++.h>
using namespace std;
int cube(int x) { return x * x * x; };
signed main()
{
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1, la; i <= n; i = la + 1)
    {
        la = n / (n / i);
        ans += (cube(n / i)) * (la - i + 1);
    }
    cout << ans << endl;
    return 0;
}

/*
Solution of First Problem
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
const int mod = 1000007;
signed main()
{
    while (1)
    {
        int n, d;
        cin >> n >> d;
        if (n == 0 and d == 0)
            break;
        map<int, int> mp;
        for (int i = 2; i * i <= n; i++)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt)
                mp[i] = 2 * cnt;
        }
        if (n > 1)
            mp[n] = 2;
        mp[2] += 2 * d;
        mp[5] += 2 * d;
        int ans = 1;
        bool f = true;
        for (auto i : mp)
        {
            ans *= (i.second + 1);
            ans %= mod;
            if (ans < 0)
            {
                ans += mod;
            }
            if (i.second % 2)
                f = false;
        }
        ans *= 2;
        ans %= mod;
        if (ans < 0)
            ans += mod;
        if (f)
        {
            ans = (ans - 1 + mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}