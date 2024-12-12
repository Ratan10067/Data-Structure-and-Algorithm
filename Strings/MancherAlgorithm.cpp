#include "bits/stdc++.h"
using namespace std;
#define IOS ios_base ::sync_with_stdio(false)

struct manacher
{
    vector<int> p;
    void run_manacher(string s)
    {
        int n = s.length();
        p.assign(n, 1);
        int l = 1;
        int r = 1;
        for (int i = 0; i < n; i++)
        {
            p[i] = max(0, min(r - i, p[l + r - i]));
            while (i + p[i] < n and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }

        for (auto &v : p)
            cout << v << " ";
        cout << endl;
    }
    void build(string s)
    {
        string t = "";
        for (auto &v : s)
        {
            t += string("#") + v; //  Dont's Use t = t + '#' + v this leads to increase time complexity by n to n^2
            // Importatnt thing is that whenever concatenation is required you must write string("#") because when you write '#' + v then it goes arithematic addition of characters
        }
        run_manacher(t + '#');
    }

    int getLongest(int cen, bool odd)
    {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalindrome(int l, int r)
    {
        if (r - l + 1 <= getLongest((l + r) / 2, l % 2 == r % 2))
        {
            return true;
        }
        return false;
    }
} m;
signed main()
{
    IOS;
    string s;
    cin >> s; //(Example Test Case s = "babbabbabc")
    m.build(s);
    return 0;
}