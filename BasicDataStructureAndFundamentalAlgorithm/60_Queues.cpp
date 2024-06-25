#include<iostream>
#include<queue>
using namespace std;

int main(){
queue<int> q;
q.push(12);
cout<<q.front()<<endl;
q.push(20);
cout << q.front() << endl;
q.push(202);
q.pop();
cout<<q.front()<<endl;
if (q.empty())
{
    cout<<"Queue is Empty : "<<endl;
}else{
    cout<<"Queue is not Empty : "<<endl;
}

return 0;
}