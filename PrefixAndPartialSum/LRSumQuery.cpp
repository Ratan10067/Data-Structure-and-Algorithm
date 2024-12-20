/*
Problem Statement :
Description
Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7.


Input Format
The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.

Output Format
For each query print the value of (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7 in a new line.


*/

#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007
signed main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int prefixSum[n];
    prefixSum[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        if (prefixSum[i] < 0)
            prefixSum[i] += mod;
        if (prefixSum[i] >= mod)
            prefixSum[i] -= mod;
    }
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        if (L == 0)
        {
            int ans = prefixSum[R];
            ans = (ans + mod) % mod;
            cout << ans << endl;
        }
        else
        {
            int ans = prefixSum[R] - prefixSum[L - 1];
            ans = (ans + mod) % mod;
            cout << ans << endl;
        }
    }
    return 0;
}