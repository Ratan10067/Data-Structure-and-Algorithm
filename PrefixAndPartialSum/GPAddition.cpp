/*
Problem Statement
Description
Given an array of N integers and Q queries and an integer K. Initially, all the elements of the array have value 0.

In each query 3 integers A, L, R is given, which means perform GP addition

Arr[L]+=A

Arr[L+1]+=A*K

Arr[L+2]+=A*K*K

Arr[L+3]+=A*K*K*K

.

.

.

.

Arr[R]+=A*(K^(R-L))



After performing all the operations. Print the final array % 10^9+7.

Input Format
The first line contains three space-separated integers N, Q, K where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next Q lines contain three space-separated integers A, L, R where 0<=A<=10^4, 1<=L<=R<=N.

Output Format
Print the N space-separated integer representing the final array %10^9+7.


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % mod;
            b -= 1;
        }
        else
        {
            a = (a * a) % mod;
            b = b >> 1;
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, k;
    cin >> n >> q >> k;
    int arr[n + 2];
    memset(arr, 0, sizeof(arr));
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        int product = binpow(k, l);
        arr[l] += (a * binpow(product, mod - 2)) % mod;
        arr[r + 1] -= (a * binpow(product, mod - 2)) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = (arr[i] + arr[i - 1]) % mod;
        cout << ((arr[i] * binpow(k, i)) % mod + mod) % mod << " ";
    }
    cout << endl;
    return 0;
}