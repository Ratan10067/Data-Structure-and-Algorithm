#include <bits/stdc++.h>
using namespace std;
int a, b;

int solve(int x, int y)
{
    int ans = 1;
    if (y == 1)
        return x;
    if (y & 1)
    {
        ans *= (x + 2 * (x * (y / 2)));
    }
    else
    {
        ans *= (2 * (x * (y / 2)));
    }
    return ans;
}

int main()
{
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}