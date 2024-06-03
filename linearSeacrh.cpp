#include <iostream>
using namespace std;
bool linearsearch(int a[], int size,int num)
{
    for (int i = 0; i < size; i++)
    {
        if(a[i]==num){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int num;
    cout<<"Enter the number that you want to go for search : ";
    cin>>num;
    int arr[]={11,23,1,5,4};
    bool found = linearsearch(arr,5,num);
    if(found)
    cout<<"Number that you are enter is present"<<"\n";
    else
    cout<<"Numbar that you are enter is not present"<<"\n";
     return 0;
}