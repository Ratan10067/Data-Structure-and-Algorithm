#include <bits/stdc++.h>
using namespace std;
#define int long long
class TrieNode
{
public:
    int freq;
    TrieNode *left;
    TrieNode *right;
    TrieNode()
    {
        freq = 0;
        left = nullptr;
        right = nullptr;
    }
};
void insert(int n, TrieNode *head)
{
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit)
        {
            if (!curr->right)
            {
                curr->right = new TrieNode();
            }
            curr = curr->right;
            curr->freq++;
        }
        else
        {
            if (!curr->left)
            {
                curr->left = new TrieNode();
            }
            curr = curr->left;
            curr->freq++;
        }
    }
}
void erase(int n, TrieNode *head)
{
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit)
        {
            curr->right->freq--;
            curr = curr->right;
        }
        else
        {
            curr->left->freq--;
            curr = curr->left;
        }
    }
}
int maximumXOR(int n, TrieNode *head)
{
    TrieNode *curr = head;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit)
        {
            if (curr->left and curr->left->freq > 0)
            {
                ans += (1 << i);
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        else
        {
            if (curr->right && curr->right->freq > 0)
            {
                ans += (1 << i);
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    TrieNode *head = new TrieNode();
    insert(0, head);
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            insert(x, head);
        }
        else if (c == '-')
        {
            erase(x, head);
        }
        else
        {
            cout << maximumXOR(x, head) << "\n";
        }
    }
    return 0;
}