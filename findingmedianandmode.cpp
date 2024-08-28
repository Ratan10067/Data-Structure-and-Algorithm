#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
struct data_dashboard
{
    int sum = 0;
    int cnt = 0;
    int sum_square = 0;
    // mode
    map<int, int> freq;
    multiset<pair<int, int> > freq_order;
    // median
    multiset<int> low, high;
    void balance()
    {
        if (low.size()<high.size())
        {
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        if(low.size()>high.size()+1)
        {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        } 
    }
    void insert(int x)
    {
        cnt++;
        sum+=x;
        sum_square += x * x;
        // mode
        if (freq_order.find(make_pair(freq[x],x))!=freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        freq[x]++;
        freq_order.insert(make_pair(freq[x],x));

        // median 
        if(low.empty())low.insert(x);
        else if(x<=*low.rbegin())
        {
            low.insert(x);
        }
        else
        {
            high.insert(x);
        }
        balance();
    }
    void remove(int x)
    {
        cnt--;
        sum -= x;
        sum_square -=x*x;
        if (freq_order.find(make_pair(freq[x], x)) != freq_order.end())
        {
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        freq[x]--;
        freq_order.insert(make_pair(freq[x], x));
        if(high.find(x)!=high.end())
        {
            high.erase(high.find(x));
        }
        else if(low.find(x)!=low.end())
        {
            low.erase(low.find(x));
        }
        balance();
    }
    double mean()
    {
        return sum / cnt*(1.0);
    }
    double variance()
    {
        return sum_square / cnt*(1.0) - mean() * mean();
    }
    double mode()
    {
        return freq_order.rbegin()->second;
    }
    double median()
    {
        if (cnt & 1)
        {
            return *low.rbegin();
        }
        else
        {
            return (*low.rbegin() + *high.rbegin()) / 2.0;
        }
    }
};
signed main()
{

    return 0;
}