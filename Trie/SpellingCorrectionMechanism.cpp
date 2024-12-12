#include "bits/stdc++.h"
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
class TrieNode
{
public:
    TrieNode *links[26];
    bool isLeaf = false;
    multiset<string> wend;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
    }
    bool isContainKey(char ch) { return links[ch - 'a'] != nullptr; }
};
int k;
string s;
vector<string> result;
void insert(TrieNode *&root, string s)
{
    TrieNode *cur = root;
    for (auto c : s)
    {
        if (cur->links[c - 'a'] == NULL)
            cur->links[c - 'a'] = new TrieNode();
        cur = cur->links[c - 'a'];
        cur->wend.insert(s);
    }
}
void seachMatch(TrieNode *curr, int pos, int misMatch)
{
    if (misMatch > k)
        return;
    if (pos == s.length())
    {
        for (auto v : curr->wend)
            result.push_back(v);
    }
    for (int i = 0; i < 26; i++)
    {
        if (curr->links[i])
        {
            seachMatch(curr->links[i], pos + 1, misMatch + (i != s[pos] - 'a'));
        }
    }
}
signed main()
{

    return 0;
}