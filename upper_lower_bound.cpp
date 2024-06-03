#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
            // auto it = upper_bound(arr, arr + n, arr[i]) - lower_bound(arr, arr + n, arr[i]);
//             auto it = lower_bound(arr, arr + n, arr[i]);
//             cout << *it << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout<<pow(2,3)<<endl;
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int cnt = 0;
        cnt = upper_bound(arr, arr + n, m) - arr;
        cout << cnt << endl;
        
    }
    return 0;
}