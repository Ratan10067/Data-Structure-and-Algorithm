#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
int n;
int queen[20]; // queen[i] is the position of  queen in ith row;
bool check(int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        int prow = i;
        int pcol = queen[i];
        if(pcol==col or abs(pcol-col)== abs(prow - row))
        {
            return 0;
        }
    }
    return 1;
}
int rec(int level)
{
    if(level==n)
    {
        return 1;
    }
    int ans = 0;
    for(int col = 0;col<n;col++)
    {
        if(check(level,col))
        {
            queen[level] = col;
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }
    return ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        IOS;
        cin.tie(0);
        cout.tie(0);
    }
    return 0;
}