#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
class MinStack
{
public:
    stack<long long> st;
    long long minValue;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minValue = val;
        }
        else
        {
            if (val >= minValue)
            {
                st.push(val);
            }
            else
            {
                st.push(1LL * 2 * val - minValue);
                minValue = val;
            }
        }
    }

    void pop()
    {
        int y = st.top();
        if (y < minValue)
        {
            minValue = 1LL * 2 * minValue - y;
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < minValue)
            return minValue;
        else
            return st.top();
    }

    int getMin()
    {
        return minValue;
    }
};
signed main()
{
    return 0;
}