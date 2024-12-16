#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll ncr_precise(ll n, ll r)
{
    if (r < 0 or r > n)
        return 0;
    ll ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
int ncr_array[4004][4004];
void ncr_any_modulo(int m)
{
    ncr_array[0][0] = 1 % m;
    for (int n = 1; n <= 4000; n++)
    {
        for (int r = 0; r <= n; r++)
        {
            if (r == 0 or r == n)
            {
                ncr_array[0][0] = 1 % m;
            }
            else
            {
                ncr_array[n][r] = (ncr_array[n - 1][r] % m + ncr_array[n - 1][r - 1] % m) % m;
            }
        }
    }
}

ll fact[400400];
void precompute()
{
    fact[0] = 1;
    for (int i = 0; i < 4000; i++)
    {
        fact[i] = i * fact[i - 1];
    }
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 0)
        {
            a = (a * a) % mod;
            b = b >> 1;
        }
        else
        {
            ans = (ans * a) % mod;
            b = b - 1;
        }
    }
    return ans;
}

ll ncr(ll n, ll r)
{
    if (r < 0 or r > n)
        return 0;
    ll den = (fact[n - r] * fact[r]) % mod;
    return (fact[n] * binpow(den, mod - 2)) % mod;
}
signed main()
{
    return 0;
}