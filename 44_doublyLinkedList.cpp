#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->prev  =NULL;
        this->next  =NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};
void insertAtHead(Node* &Head,int data){
    Node* temp = new Node(data);
    temp->next = Head;
    Head->prev = temp;
    Head=temp;

}
void insertAtTail(Node* &tail,int data){
    Node *temp = new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}
void insertAtPosition(Node *&tail, Node *&Head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(Head, d);
    }
    else
    {
        Node *temp = Head;
        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            insertAtTail(tail, d);
            return;
        }
        // Create a node for d
        Node *nodeToInsert = new Node(d);
        temp->next->prev = nodeToInsert;
        nodeToInsert->next = temp->next;
        nodeToInsert->prev = temp;

        temp->next = nodeToInsert;
    }
}
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}
void print(Node* &Head){
    Node* temp = Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
Node* node1  = new Node(12);
Node* Head = node1;
Node* tail = node1;
insertAtHead(Head,87);
print(Head);
insertAtTail(tail, 77);
insertAtTail(tail, 87);
insertAtTail(tail, 37);
print(Head);
insertAtPosition(tail,Head,2,07);
print(Head);
return 0;
}