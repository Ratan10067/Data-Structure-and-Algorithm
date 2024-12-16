/*
Problem Statement :
Description
Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.

Input Format
The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.

Output Format
For each test case print the Kth smallest element in the array C.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> arr, brr;
int n, m, k;
int check(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upper_bound(brr.begin(), brr.end(), x - arr[i]) - brr.begin();
    }
    return cnt >= k;
}
signed main()
{
    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        cin >> n >> m >> k;
        arr.resize(n);
        brr.resize(m);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
        }
        if (n > m)
        {
            swap(n, m);
            swap(arr, brr);
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        int lo = arr[0] + brr[0];
        int hi = arr[n - 1] + brr[m - 1];
        int ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}