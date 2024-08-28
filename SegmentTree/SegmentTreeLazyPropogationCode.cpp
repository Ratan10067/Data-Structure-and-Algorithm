#include <bits/stdc++.h>
using namespace std;
#define MAXN 100100
struct node
{
    int sum, maxr, lazy;
    node() : sum(0), maxr(0), lazy(0) {}
};
node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.maxr = max(a.maxr, b.maxr);
    return temp;
}
node t[4 * MAXN];
void push(int id, int l, int r)
{
    if (t[id].lazy)
    {
        t[id].sum = t[id].lazy * (r - l + 1);
        t[id].maxr = t[id].lazy;
        if (l != r)
        {
            t[id >> 1].lazy = t[id].lazy;
            t[id >> 1 | 1].lazy = t[id].lazy;
        }
        t[id].lazy = 0;
    }
}
void update(int id, int s, int e, int l, int r, int v)
{
    push(id, s, e);
    if (s >= r and e <= l)
        return;
    if (s >= l and e <= r)
    {
        t[id].lazy = v;
        push(id, s, e);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, s, mid, l, r, v);
    update(id << 1 | 1, s, mid, l, r, v);
    t[id] = merge(t[id << 1], t[id << 1 | 1]);
}
node query(int id, int s, int e, int l, int r)
{
    push(id, l, r);
    if (s >= r and e <= l)
        return node();
    if (s >= l and e <= r)
    {
        return t[id];
    }
    int mid = (l + r) >> 1;
    return merge(query(id << 1, s, mid, l, r), query(id << 1 | 1, mid + 1, e, l, r));
}
void solve()
{
    update(1, 0, 9, 0, 5, 3);
    update(1, 0, 9, 6, 9, 4);
    node x = query(1, 0, 9, 3, 6);
    cout << x.sum << " " << x.maxr << endl;
}
signed main()
{
    solve();
    return 0;
}