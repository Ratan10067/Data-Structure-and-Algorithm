#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int count = 0;
        int lastEnd = INT_MIN;

        for (const auto &interval : intervals)
        {
            if (interval[0] < lastEnd)
            {
                count++;
            }
            else
            {
                lastEnd = interval[1];
            }
        }

        return count;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    Solution s;
    cout << s.minRemoval(intervals) << endl;
    return 0;
}