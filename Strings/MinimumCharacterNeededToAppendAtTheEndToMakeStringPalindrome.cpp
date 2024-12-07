/*
    Question : Find the minimum character require to append at the end of the string to make whole string Palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false)
vector<int> kmp;

void buildKMP(string &str, int n)
{
    int i = 0;
    int j = -1;
    kmp[0] = -1;
    while (i < n)
    {
        while (j != -1 and str[i] != str[j])
        {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }
}

signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    string s = str;
    reverse(str.begin(), str.end());
    string s1 = str + '#' + s;
    int n = s1.length();
    kmp.resize(n + 1);
    buildKMP(s1, n);
    /*
        Print KMP Array
        for (auto i : kmp)
            cout << i << " ";
        cout << endl;
    */
    cout << str.length() - kmp[n] << endl;
    return 0;
}