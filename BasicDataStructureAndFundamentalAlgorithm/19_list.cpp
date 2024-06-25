#include<iostream>
#include<list>
using namespace std;

int main(){
list<int> l;
cout<<l.size()<<endl;
l.push_back(6);
l.push_back(9);
l.push_front(2);
cout<<l.size()<<endl;
return 0;
}