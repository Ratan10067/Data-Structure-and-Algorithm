#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty " << endl;
        }
        return 0;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Stack st(5);
    st.push(22);
    // cout << st.peek() << endl;
    st.push(43);
    // cout << st.peek() << endl;
    st.push(44);
    // cout << st.peek() << endl;
    st.push(44);
    // cout << st.peek() << endl;
    st.push(49);
    // cout << st.peek() << endl;
    st.push(41);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
     st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty()){
        cout<<"Stack is Empty chutiye"<<endl;
    }else{
        cout<<"Stack abhi bhara hai"<<endl;
    }

    return 0;
}