#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = n - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] >= arr[mid])
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << arr[ans] << endl;
    return 0;
}