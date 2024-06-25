#include <iostream>
using namespace std;

int main()
{
    int num = 6;
    int *ptr =&num;
    cout<<num<<endl;
    cout<<*ptr<<endl;
    cout<<sizeof(num)<<endl;
    cout<<sizeof(ptr)<<endl;
        return 0;
}