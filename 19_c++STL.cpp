#include <iostream>
#include<array>
using namespace std;

int main()
{
    array<int,6> a={1,2,3,4,5,12};
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Element at 2nd Index "<<a.at(2)<<endl;
    cout<<"Empty or not "<<a.empty()<<endl;
    cout<<"First Element "<<a.front()<<endl;
    cout<<"Last Element "<<a.back()<<endl;
    return 0;
}