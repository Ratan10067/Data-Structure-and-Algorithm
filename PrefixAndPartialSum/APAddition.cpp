/*
Problem Statement :
Description
Given an array of N integers and Q queries. Initially, all the elements of the array have value 0.

In each query 4 integers A, D, L, R is given, which means perform AP addition

Arr[L]+=A

Arr[L+1]+=A+D

Arr[L+2]+=A+2*D

Arr[L+3]+=A+3*D

.

.

.

.

Arr[R]+=A+(R-L)*D.

After performing all the operations. Print the final array % 10^9+7.

Input Format
The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next Q lines contain four space-separated integers A, D, L, R where 0<=A,D<=10^4, 1<=L<=R<=N.

Output Format
Print the N space-separated integer representing the final array %10^9+7.


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
int mul(int a, int b)
{
    int ans = (1LL * a * b) % M;
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int v1[1000001] = {0};
    int v2[1000001] = {0};
    while (q--)
    {
        int a, d, l, r;
        cin >> a >> d >> l >> r;
        v1[l] += (a - mul(l, d));
        v1[r + 1] -= (a - mul(l, d));
        v2[l] += d;
        v2[r + 1] -= d;
    }
    int pf[1000001] = {0}, pf2[1000001] = {0};
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v1[i];
        ;
        pf2[i] = pf2[i - 1] + v2[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (((pf[i] + mul(pf2[i], i)) % M) + M) % M << " ";
    }
    return 0;
}