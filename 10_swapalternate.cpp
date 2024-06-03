#include <iostream>
using namespace std;
void swapalternate(int a[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = a[2*i+1];
        a[2*i+1] = a[size-(2*i+1)-1];
        a[size-(2*i+1)-1] = temp;
    }
}
int main()
{
    int arr[] = {12, 26, 1, 14, 56, 23, 64, 4};
    swapalternate(arr,8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}