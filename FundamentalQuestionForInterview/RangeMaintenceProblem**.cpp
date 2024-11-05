#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
using ii = pair<int, int>;
struct RangeMaintence
{
    set<ii> st;
    void fill_range(int l, int r)
    {
        auto it = st.lower_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= l)
            {
                l = it->first;
                r = max(r, it->second);
                st.erase(it);
            }
        }
        it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            --it;
            if (it->second >= r)
            {
                r = it->second;
                l = min(l, it->first);
                st.erase(it);
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it == st.end() or (it->first > r))
                break;
            else
            {
                st.erase(it);
            }
        }

        st.insert({l, r});
    }
    void clear_range(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo1 = it->first;
                int hi1 = l;

                int lo2 = r;
                int hi2 = it->second;

                st.erase(it);
                st.insert({lo1, hi1});
                st.insert({lo2, hi2});
                return;

                if (it->second >= l)
                {
                    int lo = it->first;
                    int hi = l;
                    st.erase(it);
                    st.insert({lo, hi});
                }
            }
        }

        it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo = r;
                int hi = it->second;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it == st.end() or (it->first >= r))
            {
                break;
            }
            else
            {
                st.erase(it);
            }
        }
    }
    bool check_point(int x)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    bool check_range_any(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.end())
        {
            if (it->first <= r)
            {
                return 1;
            }
        }
        return check_point(l);
    }
    bool check_range_all(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= r)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    void print_status()
    {
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            cout << "(" << it->first << "," << it->second << ")" << endl;
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    RangeMaintence rm;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r;
            cin >> l >> r;
            rm.fill_range(l, r);
        }
        else if (x == 2)
        {
            int l, r;
            cin >> l >> r;
            rm.clear_range(l, r);
        }
        else if (x == 3)
        {
            int val;
            cin >> val;
            cout << rm.check_point(val) << endl;
        }
        else if (x == 4)
        {
            int l, r;
            cin >> l >> r;
            rm.check_range_all(l, r);
        }
        rm.print_status();
    }
    return 0;
}