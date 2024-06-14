#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
struct ques
{
    int s, d, t;
};
bool cmp(ques a, ques b)
{
    return a.t * b.d < b.t * a.d;
}
signed main()
{
    int n;
    cin>>n;
    vector<ques> arr;
    for(int i=0;i<n;i++)
    {
        int s,d,t;
        cin>>s>>d>>t;
        arr.push_back({s,d,t});
    }
    sort(arr.begin(),arr.end(),cmp);
    int total = 0;
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        timer+=arr[i].t;
        total+=arr[i].s - timer*arr[i].d;
    }
    cout<<total<<endl;
    return 0;
}