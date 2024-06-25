#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->next = tail;
    tail = temp;
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

        nodeToInsert->next = temp->next;

        temp->next = nodeToInsert;
    }
}
void deleteNode(int position, Node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    // cout<<node1->next<<endl;
    Node *head = node1;
    Node *tail = node2;
    cout << node1->data << endl;
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtHead(head, 19);
    insertAtTail(tail, 25);
    insertAtTail(tail, 29);
    print(tail);
    cout << endl;
    insertAtPosition(tail, head, 3, 22);
    print(head);
    cout << endl;

    return 0;
}