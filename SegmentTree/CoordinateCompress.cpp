#include <bits/stdc++.h>
using namespace std;
struct Coordinate_Compress
{
    map<int, int> mp;
    int cnt;
    vector<int> rev;
    void add(int x)
    {
        mp[x];
    }
    void build()
    {
        cnt = 0;
        for (auto &v : mp)
        {
            rev.emplace_back(v.first);
            v.second = cnt++;
        }
    }
    inline int getComp(int x)
    {
        return mp[x];
    }
    inline int getOriginal(int x)
    {
        return rev[x];
    }
    int getPrev(int x)
    {
        auto it = mp.upper_bound(x);
        it--;
        return it->second;
    }

    int getNext(int x)
    {
        auto it = mp.lower_bound(x);
        return it->second;
    }
};
signed main()
{

    return 0;
}