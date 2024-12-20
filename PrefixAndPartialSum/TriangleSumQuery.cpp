/*
Problem Statement :
Description
Given a 2d-array of dimension N*M and Q queries. In each query three integers x1, y1, L are given, you have to find the sum of the triangle ( check the image ) %10^9+7.

Assume that the value of cell outside the grid has value 0.


Input Format
The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

Next N lines contains M space-separated integers (-1e9<=Aij<=1e9).

Next Q lines contains three space separated integers x1, y1, L where 1<=x1<=N, 1<=y1<=M, 1<=L<=1000.

Output Format
For each query print the sum of the triangle.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int arr[n + 1][m + 1];
    int brr[n + 1][m + 1];
    int p[n + 1][m + 1];
    memset(arr, 0, sizeof(arr));
    memset(brr, 0, sizeof(brr));
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            brr[i][j] = arr[i][j] + brr[i - 1][j] + brr[i][j - 1] - brr[i - 1][j - 1];
            p[i][j] = (p[i - 1][j - 1] + brr[i][j] - brr[i][j - 1]);
        }
    }
    while (q--)
    {
        int x1, y1, l;
        cin >> x1 >> y1 >> l;
        int x = max(0 * 1LL, x1 - l);
        int y = max(0 * 1LL, y1 - l);
        int ans = (p[x1][y1] - p[x][y] - brr[x][y1] + brr[x][y]);
        ans %= mod;
        if (ans < 0)
            ans += mod;
        cout << ans << endl;
    }
    return 0;
}