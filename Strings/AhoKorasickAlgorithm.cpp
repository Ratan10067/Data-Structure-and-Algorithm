#include "bits/stdc++.h"
using namespace std;

class TrieNode
{
public:
    TrieNode *links[26];
    TrieNode *failureLink;
    TrieNode *outputLink;
    int index = -1;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        failureLink = nullptr;
        outputLink = nullptr;
    }

    bool isContainKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
};

class AhoLorasick
{
public:
    TrieNode *root = new TrieNode();
    vector<vector<int>> res;
    void insert(string s, int idx)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!curr->isContainKey(s[i]))
            {
                curr->links[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->links[s[i] - 'a'];
        }
        curr->index = idx;
    }

    void connectFailureAndOutputLinks()
    {
        queue<TrieNode *> q;
        TrieNode *curr = root;

        for (int i = 0; i < 26; i++)
        {
            if (curr->links[i])
            {
                q.push(curr->links[i]);
                curr->links[i]->failureLink = curr;
            }
        }

        while (!q.empty())
        {
            TrieNode *node = q.front();
            q.pop();

            for (int i = 0; i < 26; i++)
            {
                if (node->links[i])
                {
                    TrieNode *child = node->links[i];
                    TrieNode *temp = node->failureLink;

                    while (!temp->links[i] and temp != root)
                    {
                        temp = temp->failureLink;
                    }
                    if (temp->links[i])
                    {
                        child->failureLink = temp->links[i];
                    }
                    else
                    {
                        child->failureLink = root;
                    }

                    q.push(child);
                }
            }
            if (node->failureLink->index >= 0)
            {
                node->outputLink = node->failureLink;
            }
            else
            {
                node->outputLink = node->failureLink->outputLink;
            }
        }
    }

    void search(string text)
    {
        TrieNode *curr = root;
        for (int i = 0; i < text.size(); i++)
        {
            if (curr->isContainKey(text[i]))
            {
                curr = curr->links[text[i] - 'a'];
                if (curr->index >= 0)
                    res[curr->index].push_back(i);
                TrieNode *myOutput = curr->outputLink;
                while (myOutput != nullptr)
                {
                    res[myOutput->index].push_back(i);
                    myOutput = myOutput->outputLink;
                }
            }
            else
            {
                while (curr != root and !curr->isContainKey(text[i]))
                {
                    curr = curr->failureLink;
                }
                if (curr->isContainKey(text[i]))
                    i--;
            }
        }
    }
};

signed main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    AhoLorasick al;
    vector<string> pattern;
    al.res.resize(k);
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        pattern.push_back(s);
        al.insert(s, i);
    }
    al.connectFailureAndOutputLinks();
    al.search(str);
    for (int i = 0; i < k; i++)
    {
        if (al.res[i].size() == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}