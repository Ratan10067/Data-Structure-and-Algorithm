#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int lo = 0;
    int hi = n - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}