/*
Problem Statement
Description
You have to find the largest rectangular area possible in a given histogram where the largest rectangle can be made of contiguous bars. Assume that all bars have the same width and the width is 1 unit.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array.
The second line of each test case contains N space-separated integers, where Hi denotes the height of the ith bar.

Output Format
For each test case, print the largest area of the rectangle in the histogram.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> solveLeft(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() and v[st.top()] >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> solveRight(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!st.empty() and v[st.top()] >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = (st.top());
        }
        st.push(i);
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> leftSmallest = solveLeft(v);
        vector<int> rightSmallest = solveRight(v);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = v[i];
            if (rightSmallest[i] == -1)
            {
                rightSmallest[i] = n;
            }
            int b = rightSmallest[i] - leftSmallest[i] - 1;
            ans = max(ans, l * b);
        }
        cout << ans << endl;
    }
    return 0;
}