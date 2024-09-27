/*
In number theory, Euler's totient function counts the positive integers up to a given integer n that are relatively prime to n. It is written using the Greek letter phi as
φ(n) or ϕ(n), and may also be called Euler's phi function. In other words, it is the number of integers k in the range 1 ≤ k ≤ n for which the greatest common divisor gcd(n, k) is equal to 1.The integers k of this form are sometimes referred to as totatives of n.

Some Properties of Totient Function :

1. ϕ(p) = p-1 (Where is p is any Prime Number)
2. ϕ(p^k) = p^k - p^(k-1)
3. ϕ(a.b) = ϕ(a).ϕ(b)    (When gcd(a,b)==1)
*/

#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int phi[n + 1];
    vector<int> isPrime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return 0;
}