#include <bits/stdc++.h>
using namespace std;
int n, target;
vector<int> v;
bool is4SumPossible(vector<int> v, int n, int target)
{
    map<int, int> pos;
    for (int b = n - 2; b >= 1; b--)
    {
        for (int a = b - 1; a >= 0; a--)
        {
            if (pos[target - v[a] - v[b]])
            {
                return 1;
            }
        }
        int c = b;
        for (int d = c + 1; d < n; d++)
        {
            pos[v[c] + v[d]] = 1;
        }
    }
    return 0;
}
signed main()
{
    cin >> n >> target;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << is4SumPossible(v, n, target) << endl;
    return 0;
}