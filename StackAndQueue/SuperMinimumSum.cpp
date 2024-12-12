/*
Problem Statement :
Description
You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a contiguous block of the original array's elements

Input Format
The first line contains T, the number of test cases.
The first line of each test case contains N, the number of integers in an array A.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.

Output Format
For each test case, print a single number representing the sum of the minimum of all subarrays of A.


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
        // for(auto i:leftSmallest)cout<<i<<" ";cout<<endl;
        // for(auto i:rightSmallest)cout<<i<<" ";cout<<endl;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - leftSmallest[i], right;
            if (rightSmallest[i] == -1)
            {
                right = n - i;
            }
            else
            {
                right = rightSmallest[i] - i;
            }
            // cout<<"left : "<<left<<" right : "<<right<<endl;
            ans += left * right * v[i];
        }
        cout << ans << endl;
    }
    return 0;
}