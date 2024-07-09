#include <bits/stdc++.h>
using namespace std;
vector<int> generate(vector<int> arr)
{
    int n = arr.size();
    vector<int> subVal;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                sum += (arr[j]);
        }
        subVal.push_back(sum);
    }
    sort(subVal.begin(), subVal.end());
    return subVal;
}
long long count(vector<int> arr, int x)
{
    long long ans = 0;
    vector<int> newarr[2];
    for (int i = 0; i < arr.size(); i++)
    {
        newarr[i & 1].push_back(arr[i]);
    }
    vector<int> sub0 = generate(newarr[0]);
    vector<int> sub1 = generate(newarr[1]);
    for (auto v : sub0)
    {
        ans += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }
    return ans;
}
// >>>> Important thing is that you must focus this method works for n<=40 and its time complexity is O(n*(2^n))<<<<<<<
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << count(v, x) << endl;
    return 0;
}