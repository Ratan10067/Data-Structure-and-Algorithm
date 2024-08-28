#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
// using event = pair<pair<int, int>, pair<int, int>>;
signed main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> events;
    for (int i = 0; i < n; i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({l,{0,x}});
        events.push_back({r,{2,x}});
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int y;
        cin>>y;
        events.push_back({y,{1,i}});
    }
    sort(events.begin(),events.end());
    multiset<int> mt;
    int ans[q];
    for (int i = 0; i < events.size(); i++)
    {
        if(events[i].S.F==0)
        {
            mt.insert(events[i].S.S);
        }
        else if(events[i].S.F==2)
        {
            mt.erase(mt.find(events[i].S.S));
        }
        else
        {
            if(mt.empty())
            {
                ans[events[i].S.S] = -1;
            }
            else
            {
                ans[events[i].S.S] = *mt.rbegin();
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}