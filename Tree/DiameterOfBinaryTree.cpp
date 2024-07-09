#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int dfs(Node *curr, int &ans)
{
    if (curr == nullptr)
        return 0;

    int lc = dfs(curr->left, ans);
    int rc = dfs(curr->right, ans);
    ans = max(ans, lc + rc + 1);
    return max(lc, rc) + 1;
}
signed main()
{
    
    return 0;
}