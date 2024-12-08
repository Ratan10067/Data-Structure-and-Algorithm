#include "bits/stdc++.h"
using namespace std;
struct hasher
{
    int sz;
    int mod;
    int p;
    vector<int> fHash;
    vector<int> pk;
    void init(string s, int _p, int _mod)
    {
        mod = _mod;
        p = _p;
        sz = s.length();
        fHash.resize(sz);
        pk.resize(sz);
        fHash[0] = (s[0] - 'a' + 1);
        pk[0] = 1;
        for (int i = 1; i < s.length(); i++)
        {
            fHash[i] = (fHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int getfHash(int l, int r)
    {
        if (l == 0)
            return fHash[r];
        return (fHash[r] - fHash[l - 1] * pk[r - l + 1] % mod + mod) % mod;
    }
};
int n;
hasher shash;
string str;
bool cmp(int i, int j)
{
    int lo = 1;
    int hi = n;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (shash.getfHash(i, i + mid - 1) == shash.getfHash(j, j + mid - 1))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return str[i + ans] < str[j + ans];
}

signed main()
{
    cin >> str;
    n = str.length();
    str += str;
    shash.init(str, 37, 999999937);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp); // O(nlogn*logn) Time Complexity is O(n*log(n)^2)

    return 0;
}