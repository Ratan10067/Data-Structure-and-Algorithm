#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int n;
int arr[10010];
int dp[10010];
int rec(int level)
{
    if(level<0)
    {
        return 0;
    }
    if(dp[level]!=-1)return dp[level];
    int ans = 1;
    for (int i = 0; i < level; i++)
    {
        if(arr[i]<arr[level])
        {
            ans = max(ans,1 + rec(i));
        }
    }
    return dp[level] = ans;
}
void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        best = max(best,rec(i));
    }
    cout<<best<<endl;
}
signed main()
{
    solve();
    return 0;
}