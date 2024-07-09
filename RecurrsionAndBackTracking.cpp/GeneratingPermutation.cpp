#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v;
vector<vector<int>> all_solution;
vector<int> curr_per;
int n;
void rec(int level)
{
    if (level == n)
    {
        all_solution.push_back(curr_per);
        return;
    }
    for (auto i : mp)
    {
        if (i.second != 0)
        {
            mp[i.first]--;
            curr_per.push_back(i.first);
            rec(level + 1);
            curr_per.pop_back();
            mp[i.first]++;
        }
    }
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    rec(0);
    return 0;
}