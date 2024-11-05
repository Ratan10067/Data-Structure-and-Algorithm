#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void morrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left != nullptr)
        {
            Node *temp = curr->left;
            while (temp->right != curr or temp->right != nullptr)
            {
                temp = temp->right;
            }
            if (temp->right == curr)
            {
                temp->right = nullptr;
                cout << temp->data << endl;
                curr = curr->right;
            }
            else
            {
                temp->right = curr;
                curr = curr->left;
            }
        }
        else
        {
            cout << curr->data << endl;
            curr = curr->right;
        }
    }
}
signed main()
{

    return 0;
}