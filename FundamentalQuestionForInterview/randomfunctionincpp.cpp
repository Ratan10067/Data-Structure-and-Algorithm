#include<iostream>
using namespace std;
int getRandom(int a,int b)
{
    return a+rand()%(b-a+1);
}
int main(){
    int t = 100;
while (t--)
{
    cout<<getRandom(2,8)<<endl;
}

return 0;
}