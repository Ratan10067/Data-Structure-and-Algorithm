/*
Problem Statement :
Description
Given a string S consisting of the lowercase character of length N. Score of a string is the number of unique characters present in the string( characters which are only present once in the string). Like score of "character" is 3 {h,t,e}.

Find the sum of the score of all substring of S.

Input Format
The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.

Output Format
For each test case print the sum of the score of all substring of S in a newline.


This question is solved by using contribution technique method
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ;
    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        int n;
        cin >> n;
        string s = "";
        cin >> s;
        int ans = 0;
        vector<int> occur[26];
        for (int i = 0; i < 26; i++)
        {
            occur[i].push_back(-1);
        }
        for (int i = 0; i < n; i++)
        {
            occur[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++)
        {
            occur[i].push_back(n);
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j < occur[i].size() - 1; j++)
            {
                ans += (occur[i][j] - occur[i][j - 1]) * (occur[i][j + 1] - occur[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}