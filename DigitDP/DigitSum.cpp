// the number of odd numbers in range L to R is ceil(r/2) - ceil((l-1)/2)
#include <bits/stdc++.h>
using namespace std;
int len;
const int mod = 1e9 + 7;
string l, r;
int dp[10010][2][2][100];
int d;
int rec(int level, int tlo, int thi, int sumD)
{
    if (level == len)
    {
        if (sumD == 0)
            return 1;
        else
            return 0;
    }
    if (dp[level][tlo][thi][sumD] != -1)
        return dp[level][tlo][thi][sumD];
    int ans = 0;
    int lo = 0;
    if (tlo == 1)
    {
        lo = l[level] - '0';
    }
    int hi = 9;
    if (thi == 1)
    {
        hi = r[level] - '0';
    }
    for (int i = lo; i <= hi; i++)
    {
        int ntlo = tlo;
        if (i != l[level] - '0')
            ntlo = 0;
        int nthi = thi;
        if (i != r[level] - '0')
            nthi = 0;
        ans += rec(level + 1, ntlo, nthi, (sumD + i) % d);
        ans = ans % mod;
    }
    return dp[level][tlo][thi][sumD] = ans;
}
signed main()
{
    cin >> l >> r >> d;
    int cnt = r.length() - l.length();
    string temp = "";
    while (cnt--)
    {
        temp.push_back('0');
    }
    l = temp + l;
    len = r.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0)<<endl;;
    return 0;
}