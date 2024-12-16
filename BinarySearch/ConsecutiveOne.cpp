/*
Problem Statement :
    Description
Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only one.

Find the maximum score possible if you can change at most K elements of the array.

Input Format
The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated integer N, K where 
The next line contains N space-separated integers which are either 0 or 1.

Output Format
For each test case print the maximum score possible if you can change at most K elements of the array in a new line.

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> arr;
int n, k;
int prefix[200001];
int check(int l, int r)
{
    int cntZero = (r - l + 1) - (prefix[r] - (l == 0 ? 0 : prefix[l - 1]));
    return cntZero <= k;
}
signed main()
{
    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        cin >> n >> k;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            prefix[i] = arr[i];
            if (i)
            {
                prefix[i] += prefix[i - 1];
            }
        }
        int maxLength = 0;
        for (int i = 0; i < n; i++)
        {
            int lo = 0;
            int hi = n - 1;
            int ans = i - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (check(i, mid))
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            // cout<<"ans : "<<ans<<endl;
            maxLength = max(maxLength, ans - (i - 1));
        }
        cout << maxLength << endl;
    }
    return 0;
}