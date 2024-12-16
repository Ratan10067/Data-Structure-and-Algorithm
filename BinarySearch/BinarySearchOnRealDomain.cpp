/*
In this context we discuss to apply the binary search on real domain not discrete
*/
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define EPS 1e-9
int check(int x)
{
}
signed main()
{
    int n;
    cin >> n;
    long double lo = 0;
    long double hi = n;
    while (abs(lo - hi) >= EPS)
    {
        long double mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    /*
    Alternative Approach
    for(int i=0;i<40;i++)
    {
        int mid = (lo + hi)/2;
        if(check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    */
    long double ans = (lo + hi) / 2;
    return 0;
}