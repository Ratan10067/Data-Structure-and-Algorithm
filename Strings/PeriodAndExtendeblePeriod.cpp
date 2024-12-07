/*
Question: You have to find the period of string and also find the extendeble period of string so in both case your answer is length of string - last index value of kmp array.
Code given below
*/

#include "bits/stdc++.h"

using namespace std;

signed main()
{
    string str = "";
    cin >> str;
    int n = str.length();
    vector<int> kmp(n + 1);
    kmp[0] = -1;
    int i = 0;
    int j = -1;
    while (i < n)
    {
        while (j != -1 and str[i] != str[j])
        {
            j = kmp[j];
        }
        i++;
        j++;
        kmp[i] = j;
    }

    // Extendeble Period is len(s) - kmp(len(s))
    cout << n - kmp[n] << endl;
    if (n % (n - kmp[n]) == 0)
    {
        // Then we said period of string
        cout << n - kmp[n] << endl;
    }
    else
    {
        cout << n << endl;
    }
    return 0;
}