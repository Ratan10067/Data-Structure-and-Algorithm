
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {};
};

map<Node *, Node *> mp;

Node *ParentCreation(Node *root, int tar)
{
    if (root == nullptr)
        return nullptr;
    queue<Node *> q;
    q.push(root);
    Node *ans = nullptr;
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode->data == tar)
        {
            ans = frontNode;
        }
        if (frontNode->left)
        {
            mp[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        if (frontNode->right)
        {
            mp[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return ans;
}

vector<int> KDistanceNodes(Node *root, int k, int tar)
{
    vector<int> ans;
    queue<Node *> q;
    Node *targetNode = ParentCreation(root, tar);
    q.push(targetNode);
    map<Node *, int> vis;
    map<Node *, int> dis;
    vis[targetNode] = 1;
    dis[targetNode] = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (dis[frontNode] == k)
                ans.push_back(frontNode->data);
            if (frontNode->left and !vis[frontNode->left])
            {
                vis[frontNode->left] = 1;
                dis[frontNode->left] = dis[frontNode] + 1;
                q.push(frontNode->left);
            }
            if (frontNode->right and !vis[frontNode->right])
            {
                vis[frontNode->right] = 1;
                dis[frontNode->right] = dis[frontNode] + 1;
                q.push(frontNode->right);
            }
            if (mp[frontNode] and !vis[mp[frontNode]])
            {
                vis[mp[frontNode]] = 1;
                dis[mp[frontNode]] = dis[frontNode] + 1;
                q.push(mp[frontNode]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

Node *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    // cout << data << endl;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<Node *> q;
    auto root = new Node(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new Node(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new Node(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}
void solve()
{
    int n, k, tar;
    cin >> n >> k >> tar;
    string s;
    cin >> s;
    auto root = deserialize(s);
    auto ans = KDistanceNodes(root, k, tar);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
