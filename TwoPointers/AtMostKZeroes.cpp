#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tail = 0;
    int head = -1;
    int ans = 0, cntZero = 0;
    while (tail < n)
    {
        while (head + 1 < n and (cntZero < k or arr[head + 1] == 1))
        {
            head++;
            if (arr[head] == 0)
                cntZero++;
        }
        // Update the answer for current start
        ans = max(ans, head - tail + 1);
        // move start one step forward
        if (tail > head)
        {
            // when we have zero element in window.
            tail++;
            head = tail - 1;
        }
        else
        {
            if (arr[tail] == 0)
                cntZero--;
            tail++;
        }
    }
    return 0;
}