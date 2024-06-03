#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if (data==-1)
    {
        return NULL;
    }
    cout<<"Enter data for inserting in left portion of : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right portion of : "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOfTraversal(Node* root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
int main(){
    Node * root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 7 -1 -1 -1
    levelOfTraversal(root);
    cout<<"Inorder manner"<<endl;
    inorder(root);
    cout<<"Preorder manner"<<endl;
    preorder(root);
    cout<<"Postorder manner"<<endl;
    postorder(root);
return 0;
}