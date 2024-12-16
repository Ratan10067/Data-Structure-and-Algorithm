#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
vector<int> arr;
int check(int s)
{
    int last = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(last>=arr[i])
        {
            last-=arr[i];
        }
        else
        {
            cnt++;
            last = s-arr[i];
        }
        if(cnt>k)return 0;
    }
    if(cnt>k)return 0;
    return 1;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    cin>>_t;
    while(_t--)
    {
        cin>>n>>k;
        arr.resize(n);
        int lo = 0;
        int hi = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            lo = max(lo,arr[i]);
            hi+=arr[i];
        }
        int ans = 0;
        while(lo<=hi)
        {
            int mid = lo + (hi - lo)/2;
            if(check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}