#include<iostream>
using namespace std;
void update(int a[] , int size){
    a[0]=33;
    a[1]=45;
    cout<<"printng the values of array in update function";
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main(){
int arr[7]={1,2,3,45,7,8,2};
cout<<"Printing the values of array in main function";
for (int i = 0; i < 7; i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
update(arr,7);
cout<<endl;
for (int i = 0; i < 7; i++)
{
    cout << arr[i] << " ";
}
return 0;
}