/*
    Question:
    You have to find the index of first occurence of 1 in array consisting of zeros and ones, zero are continous and then after it is 1
*/

#include "bits/stdc++.h"
using namespace std;
int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int lo = 0;
    int hi = n - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] == 1)
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