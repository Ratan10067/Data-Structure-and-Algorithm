#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int l, r;
    cin >> l >> r;

    int n = sqrt(r);
    vector<int> v(n + 1, 1); // Sieve for primes up to sqrt(r)

    // Simple sieve to find all primes up to sqrt(r)
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

    vector<int> num(r - l + 1, 1); // Mark primes in the range [l, r]

    // Mark multiples of primes in range [l, r]
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 1)
        {
            int currMul = max(i * i, (l + i - 1) / i * i); // Start from max(i^2, first multiple of i >= l)
            while (currMul <= r)
            {
                num[currMul - l] = 0; // Mark as non-prime
                currMul += i;
            }
        }
    }

    if (l == 1)
        num[0] = 0; // Special case: 1 is not prime

    // Output results
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i])
        {
            cnt++;
            ans.push_back(i + l); // Actual number is i + l
        }
    }

    cout << cnt << endl;
    for (auto &v : ans)
        cout << v << " ";
    cout << endl;

    return 0;
}