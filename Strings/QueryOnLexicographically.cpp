/*
Question: You given a q query and in each query you given three integers i,j and length and you have to find that which string is lexicographically small among substr(i,i + length-1) and substr(j,j + length - 1)
*/

#include "bits/stdc++.h"
using namespace std;
#define ios_base ::sync_with_stdio(false);
struct hasher
{
    int n, _k, _p;
    vector<int> powk, base, rev;

    void init(string s, int k, int p)
    {
        _k = k, _p = p;
        n = s.length();
        powk.resize(n + 1);
        base.resize(n + 1);
        // precompute

        base[0] = 0;
        powk[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int num = (s[i] - 'a' + 1) % p;
            base[i + 1] = (1LL * base[i] * k + num) % p;
            powk[i + 1] = (1LL * k * powk[i]) % p;
        }

        // Reverse
        rev.resize(n + 1);
        rev[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int num = (s[i] - 'a' + 1) % _p;
            rev[i] = (1LL * rev[i + 1] * k + num) % p;
        }
    }
    int gethash(int l, int r)
    { // 0 index
        int ans = (base[r + 1] - 1LL * base[l] * powk[(r - l + 1)]) % _p;
        return (ans + _p) % _p;
    }

    int getrevhash(int l, int r)
    {
        int ans = (rev[l] - 1LL * rev[r + 1] * powk[(r - l + 1)]) % _p;
        return (ans + _p) % _p;
    }
};

struct double_hash
{
    hasher a, b;
    string temp;
    void init(string s)
    {
        a.init(s, 37, 1000000021);
        b.init(s, 39, 1000000009);
        temp = s;
    }

    pair<int, int> gethash(int l, int r)
    {
        return {a.gethash(l, r), b.gethash(l, r)};
    }
    pair<int, int> getrevhash(int l, int r)
    {
        return {a.getrevhash(l, r), b.getrevhash(l, r)};
    }
    bool isPalindrome(int l, int r)
    {
        return gethash(l, r) == getrevhash(l, r);
    }
    int lex_order(int i, int j, int len)
    {
        int ans = 0;
        int lo = 0;
        int hi = len;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (gethash(i, i + mid - 1) == gethash(j, j + mid - 1))
            {
                lo = mid + 1;
                ans = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        if (ans == len)
        {
            return 0;
        }
        if (temp[i + ans] < temp[j + ans])
        {
            return -1;
        }
        return 1;
    }
};
signed main()
{
    string str;
    cin >> str;
    double_hash ha;
    ha.init(str);

    int q;
    cin >> q;
    while (q--)
    {
        int i, j, x;
        cin >> i >> j >> x;
        cout << ha.lex_order(i, j, x) << endl;
    }

    return 0;
}