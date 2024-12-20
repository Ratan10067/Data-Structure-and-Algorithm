/*
Problem Statement :
Description
You have been given an array A of N integers and M ranges. ith range is defined by the two integers li and ri, li≤ri.

Initially, array S is empty. For range i, add elements A[li],A[li+1]…..A[ri] in the array S. After adding all the elements in each of the range, sort the elements of S in ascending order.

You need to answer Q queries. Each query consists of a number K > 0. You have to find the Kth smallest element in S, i.e., the element at Kth position in sorted S.

It may be possible that the same element presents multiple times in S.

Input Format
The first line of the input contains a single integer T - the number of test cases(1 ≤ T ≤ 10). Then T test cases follow.

The first line of each test case contains three integers N, M, and Q, (1 ≤ N, M, Q ≤ 10^5).

The second line contains N space-separated integers A1, A2,….,AN, the elements of the array A, (1≤Ai≤10^9).

Next M lines contain two space-separated integers li and ri - ith range, (1 ≤ li ≤ ri ≤ N).

The last line of a test case contains Q space-separated integers K1, K2,….,KQ, where Ki denotes the ith query. (1 ≤ Ki ≤1 0^18).

Output Format
For each test case, print Q space-separated integers, where ith number denotes the answer of ith query. If the Kth value doesn't exist for a particular query, print -1.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define endl "\n";

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back({x, 0});
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        (s[l].second)++;
        if (r < n - 1)
            (s[r + 1].second)--;
    }

    for (int i = 1; i < s.size(); i++)
    {
        (s[i].second) += (s[i - 1].second);
    }
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++)
    {
        (s[i].second) += (s[i - 1].second);
    }

    while (q--)
    {
        int k;
        cin >> k;
        int low = 0, high = n - 1, ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (s[mid].second >= k)
            {
                ans = s[mid].first;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << " ";
    }
}

signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}