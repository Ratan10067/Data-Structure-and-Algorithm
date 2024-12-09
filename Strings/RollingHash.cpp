#include <bits/stdc++.h>
using namespace std;

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
    void init(string s)
    {
        a.init(s, 37, 1000000021);
        b.init(s, 39, 1000000009);
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
};

void solve()
{
    string s;
    cin >> s;
    hasher hasha, hashb;
    hasha.init(s, 37, 1000000021);
    hashb.init(s, 39, 1000000009);

    set<pair<int, int>> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            st.insert({hasha.gethash(i, j), hashb.gethash(i, j)});
        }
    }
}

int main()
{
    solve();
    return 0;
}