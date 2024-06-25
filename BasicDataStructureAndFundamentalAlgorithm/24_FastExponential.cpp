#include<iostream>
using namespace std;

int main(){
int x,y;
cin>>x>>y;
int res=1;
while (y>0)
{
    if(y&1)
    res=(res*x);
    x=x*x;
    y>>1;
}

return 0;
}