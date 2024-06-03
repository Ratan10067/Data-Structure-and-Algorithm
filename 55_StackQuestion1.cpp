#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string name = "Ratan";
    stack<char> s;
    for (int i = 0; i < name.length(); i++)
    {
        // char ch = name[i];
        s.push(name[i]);
    }
    string ans="";
    for (int i = 0; i < name.length(); i++)
    {
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"Reverse of the name is : "<<ans<<endl;
    return 0;
}