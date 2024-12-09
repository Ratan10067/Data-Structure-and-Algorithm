/*
    Question: You have to find the longest palindromic string in given String.
    Solution :
        Intuition: We can solve this question in 3 ways that come at first glance:
        Use Brute Force : Check for every corresponding element in string the longest palindrome possible and do it till the end.
        DP: Since we are essentially looping over every element in Brute Force, maybe we can somehow use the result from our previous iteration to simplify the current one? This gives us a nudge to look for a pattern and hence we go for DP.
        Expand through the center for even and odd length palindromes.
        Manacher Algorithm.
        Analysis: Let's see all the approaches one by one !!!

        Brute Force: Instead of directly going to code and finding a problem later, lets stop and think about the concept we intend to use here
        Concept: We will go through all possible elements in string and find the longest palindrome amongst them. Review: To calculate all the possible substrings in a string of length n, the number of combinations generated are: 1+2+3+4+..........n=n(n-1)/2. To check all the substrings for Palindrome, we will have to go through all the n characters. Total Combinations: n*n(n-1)/2= O(n^3) Conclusion: Since the time complexity is O(n^3), hence we will not discuss this approach, and our energy would be better spent looking at the DP solution.

        DP : if we know string "aba" is palindrome then "cabac" must be palindrome as left and right are equal. State : P(i,j) - True if substring(i,j) is a palindrome Transition: P(i, j) == P(i+1, j-1) && s[i] == s[j]; Base cases : P(i, i) = true; //One character P(i, i+1) = s[i] == s[i+1]; //Two character Time Complexity - O(N^2), Space Complexity - O(N^2) (caching all substring)

        Expand Around Center : Time: O(n^2), Space: O(1) Loop through the input string with i then inner loop through a section of that string with j You now have two pointers left and right (i, j) respectively Since we start with 2 letters, for them to be a palindrome they have to be the same, so while that is the case, we'll keep expanding our window till they're no longer a palindrome Max will be the longest palindrome so if the current palindrome length is greater than our previous palindrome length we'll update the max We'll do this till we're done looping through the string for both odd and even length palindromes, then return max.


Here i give a Solution using Manacher Algorithm which time complexity of O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        int n = s.length();
        p.assign(n, 1);
        int l = 0;
        int r = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < r)
            {
                p[i] = min(r - i, p[2 * l - i]);
            }
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i;
                r = i + p[i] - 1;
            }
        }
    }

    void build(string s)
    {
        string t = "";
        for (auto &v : s)
        {
            t += string("#") + v;
        }
        run_manacher(t + '#');
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        string s;
        cin >> s;
        manacher m;
        m.build(s);

        int cen = 0;
        int max_length = 0;
        int size = m.p.size();

        for (int i = 0; i < size; i++)
        {
            if (m.p[i] > max_length)
            {
                max_length = m.p[i];
                cen = i;
            }
        }

        int start = (cen - max_length + 1) / 2;
        cout << s.substr(start, max_length - 1) << endl;
    }
    return 0;
}
